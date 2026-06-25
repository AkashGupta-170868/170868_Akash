#include "simplefs-ops.h"

extern struct filehandle_t file_handle_array[MAX_OPEN_FILES]; // Array for storing opened files
struct filehandle_t filehandle;

int simplefs_create(char *filename){
	/*
	   Create file with name `filename` from disk
	 */
	struct inode_t *inode = (struct inode_t *)malloc(sizeof(struct inode_t));
	int inode_number = simplefs_allocInode();
	if (inode_number == -1){
		return -1;
		free(inode);
	}
	strcpy(inode->name , filename);
	inode->status = INODE_IN_USE;
	inode->file_size = 0;

	for(int i = 0; i < MAX_FILE_SIZE; i++){
		inode->direct_blocks[i] = -1;
	}
	simplefs_writeInode(inode_number, inode);
	free(inode);
	return inode_number;
}


void simplefs_delete(char *filename){
	/*
	   delete file with name `filename` from disk
	 */
	struct inode_t *inode = (struct inode_t *)malloc(sizeof(struct inode_t));
	int inode_number = -1;
	for(int i = 0; i < NUM_INODES; i++){
		simplefs_readInode(i , inode);
		if ( inode->status == INODE_IN_USE && strcmp(inode->name ,filename) == 0){
			inode_number = i;
			break;
		}
	}
	if ( inode_number == -1){
		free(inode);
		return;
	}
	for ( int i = 0; i < MAX_FILE_SIZE; i++){
		if (inode->direct_blocks[i] != -1){
			simplefs_freeDataBlock(inode->direct_blocks[i]);
		}
	} 
	simplefs_freeInode(inode_number);
	free(inode);
}

int simplefs_open(char *filename){
	/*
	   open file with name `filename`
	 */
	struct inode_t *inode = (struct inode_t *)malloc(sizeof(struct inode_t));
	int inode_number = -1;
	for(int i = 0; i < NUM_INODES; i++){
		simplefs_readInode(i , inode);
		if ( inode->status == INODE_IN_USE && strcmp(inode->name ,filename) == 0){
			inode_number = i;
			break;
		}
	}
	if(inode_number == -1){
		free(inode);
		return -1;
	}
	for ( int i =0; i < MAX_OPEN_FILES; i++){
		if (file_handle_array[i].inode_number == -1){
			file_handle_array[i].inode_number = inode_number;
			file_handle_array[i].offset = 0;
			free(inode);
			return i;
		}
	}
	free(inode);
	return -1;
}

void simplefs_close(int file_handle){
	/*
	   close file pointed by `file_handle`
	 */

	if(file_handle < 0 || file_handle >= MAX_OPEN_FILES){
		return;
	}
	if(file_handle_array[file_handle].inode_number == -1){
		return;
	}
	file_handle_array[file_handle].inode_number = -1;
	file_handle_array[file_handle].offset = 0;

}
int32_t simplefs_read(int32_t file_handle, char *buf, int32_t nbytes)
{
        if (file_handle < 0 || file_handle >= MAX_OPEN_FILES)
                return -1;

        if (file_handle_array[file_handle].inode_number == -1)
                return -1;

        int32_t inodenum = file_handle_array[file_handle].inode_number;

        struct inode_t inode;
        simplefs_readInode(inodenum, &inode);

        int32_t offset = file_handle_array[file_handle].offset;

        if (offset + nbytes > inode.file_size)
                return -1;

        int32_t byte_read = 0;

        while (byte_read < nbytes)
        {
                int32_t block_index = offset / BLOCKSIZE;
                int32_t block_offset = offset % BLOCKSIZE;

                if (block_index >= MAX_FILE_SIZE)
                        return -1;

                if (inode.direct_blocks[block_index] == -1)
                        return -1;

                char temp[BLOCKSIZE];
                simplefs_readDataBlock(inode.direct_blocks[block_index], temp);

                int32_t to_read = BLOCKSIZE - block_offset;

                if (to_read > (nbytes - byte_read))
                        to_read = nbytes - byte_read;

                memcpy(buf + byte_read, temp + block_offset, to_read);

                byte_read += to_read;
                offset += to_read;
        }
        buf[nbytes] = '\0';
        return 0;
}
int32_t simplefs_write(int32_t file_handle, char *buf, int32_t nbytes)
{
        if (file_handle < 0 || file_handle >= MAX_OPEN_FILES)
                return -1;

        if (file_handle_array[file_handle].inode_number == -1)
                return -1;

        int32_t inodenum = file_handle_array[file_handle].inode_number;

        struct inode_t inode;
        simplefs_readInode(inodenum, &inode);

        int32_t offset = file_handle_array[file_handle].offset;
        int32_t byte_write = 0;

        if (offset + nbytes > MAX_FILE_SIZE * BLOCKSIZE)
                return -1;
        int32_t temp_offset = offset;
        int32_t remaining = nbytes;

        while (remaining > 0)
        {
                int32_t block_index = temp_offset / BLOCKSIZE;

                if (block_index >= MAX_FILE_SIZE)
                        return -1;

                if (inode.direct_blocks[block_index] == -1)
                {
                        int32_t blk = simplefs_allocDataBlock();
                        if (blk == -1)
                                return -1;

                        simplefs_freeDataBlock(blk);
                }

                int32_t block_offset = temp_offset % BLOCKSIZE;
                int32_t space = BLOCKSIZE - block_offset;

                if (space > remaining)
                        space = remaining;

                remaining -= space;
                temp_offset += space;
        }
        while (byte_write < nbytes)
        {
                int32_t block_index = offset / BLOCKSIZE;
                int32_t block_offset = offset % BLOCKSIZE;

                if (block_index >= MAX_FILE_SIZE)
                        return -1;

                char temp[BLOCKSIZE];

                if (inode.direct_blocks[block_index] == -1)
                {
                        int32_t blocknum = simplefs_allocDataBlock();
                        if (blocknum == -1)
                                return -1;

                        inode.direct_blocks[block_index] = blocknum;

                        memset(temp, 0, BLOCKSIZE);
                }
                else
                {
                        simplefs_readDataBlock(inode.direct_blocks[block_index], temp);
                }

                int32_t to_write = BLOCKSIZE - block_offset;

                if (to_write > (nbytes - byte_write))
                        to_write = nbytes - byte_write;

                memcpy(temp + block_offset, buf + byte_write, to_write);

                simplefs_writeDataBlock(inode.direct_blocks[block_index], temp);

                byte_write += to_write;
                offset += to_write;
        }

        if (offset > inode.file_size)
                inode.file_size = offset;


        simplefs_writeInode(inodenum, &inode);

        return 0;
}
int simplefs_seek(int file_handle, int nseek){
	/*
	   increase `file_handle` offset by `nseek`
	 */
	if(file_handle < 0 || file_handle >= MAX_OPEN_FILES){
		return -1;
	}
	if(file_handle_array[file_handle].inode_number == -1){
		return -1;
	}
	file_handle_array[file_handle].offset += nseek;
	return 0;
}
