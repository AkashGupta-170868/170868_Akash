#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>
#include <stdint.h>
#include "../include/header.h"
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

#define DB_FILE "/home/akash/Take_Away_File_Encryption_System/database/users.db"

#define PERMISSION "/home/akash/Take_Away_File_Encryption_System/database/permissions.db"
#define FIXED_XOR_KEY 43981

/*Function name: register_user
Descripton: Registers a new user by validating input, checking for duplicate usernames, hashing the password using SHA-256, and storing the credentials securely in the database file
Author : Akash Gupta
Created At: 06-05-2026
 */ 
int32_t register_user(const char *username, const char *password)
{
	FILE *fp;
	char stored_username[50];
	unsigned char hash[SHA256_DIGEST_LENGTH];
	char hash_string[65];
	int32_t i;

	if (username == NULL || password == NULL ||
			strlen(username) == 0 || strlen(password) == 0)
	{
		return 2;
	}

	for (i = 0; username[i] != '\0'; i++)
	{
		if (username[i] == ' ')
		{
			return 2;
		}
	}

	fp = fopen(DB_FILE, "r");

	if (fp != NULL)
	{
		while (fscanf(fp, " %49[^:]:%*s", stored_username) == 1)
		{
			if (strcmp(username, stored_username) == 0)
			{
				fclose(fp);
				return 1;
			}
		}

		fclose(fp);
	}

	fp = fopen(DB_FILE, "a");

	if (fp == NULL)
	{
		return 3;
	}

	SHA256((unsigned char *)password, strlen(password), hash);

	for (i = 0; i < SHA256_DIGEST_LENGTH; i++)
	{
		sprintf(&hash_string[i * 2], "%02x", hash[i]);
	}

	hash_string[64] = '\0';

	fprintf(fp, "%s:%s\n", username, hash_string);

	fclose(fp);

	return 0;
}

/*Function name: register_user
Descripton: Authenticates a user by validating input, hashing the entered password using SHA-256, and comparing it with the stored credentials in the database file.
Author : Akash Gupta
Created At: 06-05-2026
 */
int32_t login_user(const char *username, const char *password)
{
	FILE *fp;
	char stored_username[50];
	char stored_password[65];
	unsigned char hash[SHA256_DIGEST_LENGTH];
	char hash_string[65];
	int32_t i;

	if (username == NULL || password == NULL ||
			strlen(username) == 0 || strlen(password) == 0)
	{
		return 2;
	}

	fp = fopen(DB_FILE, "r");

	if (fp == NULL)
	{
		return 3;
	}

	SHA256((unsigned char *)password, strlen(password), hash);

	for (i = 0; i < SHA256_DIGEST_LENGTH; i++)
	{
		sprintf(&hash_string[i * 2], "%02x", hash[i]);
	}

	hash_string[64] = '\0';

	while (fscanf(fp, " %49[^:]:%64s", stored_username, stored_password) == 2)
	{
		if (strcmp(username, stored_username) == 0)
		{
			fclose(fp);

			if (strcmp(hash_string, stored_password) == 0)
				return 0;
			else
				return 1;
		}
	}

	fclose(fp);

	return 3;
}


/*Function name: xor_encrypt
Descripton: Encrypts the input string using XOR encryption with the given key and returns the encrypted data as a hexadecimal string.
Author : Akash Gupta
Created At: 06-05-2026
 */
char* xor_encrypt(const char *input_string, uint16_t key)
{
	int index;
	int input_length;
	unsigned char xor_key;
	unsigned char encrypted_byte;
	char *encrypted_result;

	if(input_string == NULL || input_string[0] == '\0')
		return NULL;

	input_length = strlen(input_string);

	encrypted_result = (char *)malloc((input_length * 2) + 1);

	if(encrypted_result == NULL)
		return NULL;

	xor_key = (unsigned char)(key & 0xFF);

	for(index = 0; index < input_length; index++)
	{
		encrypted_byte = ((unsigned char)input_string[index]) ^ xor_key;

		sprintf(encrypted_result + (index * 2), "%02X", encrypted_byte);
	}

	encrypted_result[input_length * 2] = '\0';

	return encrypted_result;
}

/*Function name: xor_decrypt
Descripton: decrypt the string.
Author : Akash Gupta
Created At: 06-05-2026
 */
char* xor_decrypt(const char *encrypted_string, uint16_t key)
{
	int index;
	int encrypted_length;
	unsigned char xor_key;
	unsigned int temp;
	char *decrypted_result;

	if(encrypted_string == NULL || encrypted_string[0] == '\0')
		return NULL;

	encrypted_length = strlen(encrypted_string);

	if(encrypted_length % 2 != 0)
		return NULL;

	decrypted_result = (char *)malloc((encrypted_length / 2) + 1);

	if(decrypted_result == NULL)
		return NULL;

	xor_key = (unsigned char)(key & 0xFF);

	for(index = 0; index < encrypted_length; index += 2)
	{
		sscanf(encrypted_string + index, "%2X", &temp);

		decrypted_result[index / 2] = ((unsigned char)temp) ^ xor_key;
	}

	decrypted_result[encrypted_length / 2] = '\0';

	return decrypted_result;
}

/*Function name: create_encrypted_file
Descripton: Creates a new file with strict permissions, encrypts the given text using XOR encryption with the provided key, and stores the encrypted content in the file.
Author : Akash Gupta
Created At: 06-05-2026
 */
int16_t create_encrypted_file(const char *filename, const char *text, uint16_t key){

	if (!filename || strlen(filename) == 0 || !text)
		return 2;

	int16_t fd = open(filename, O_CREAT | O_EXCL | O_WRONLY, 0600);

	if (fd < 0) {
		perror("open");
		return (errno == EEXIST) ? 1 : 3;
	}

	if (strlen(text) == 0) {
		close(fd);
		return 0;
	}

	char *enc = xor_encrypt(text, key);
	if (!enc) {
		close(fd);
		return 3;
	}
	if (write(fd, enc, strlen(enc)) < 0) {
		perror("write");
		close(fd);
		return 3;
	}

	close(fd);
	return 0;
}

/*Function name: read_encrypted_fle
Descripton: Reads the encrypted content from the specified file, decrypts it using XOR decryption with the given key, and returns the original plaintext data.
Author : Akash Gupta
Created At: 07-05-2026
 */
char* read_encrypted_file(const char *filename, uint16_t key)
{
	FILE *fp;
	long file_size;
	char *encrypted_data;
	char *decrypted_data;

	if(filename == NULL || filename[0] == '\0' || key == 0)
		return NULL;

	fp = fopen(filename, "r");

	if(fp == NULL)
	{
		perror("Error opening file");
		return NULL;
	}

	fseek(fp, 0, SEEK_END);
	file_size = ftell(fp);
	rewind(fp);

	if(file_size == 0)
	{
		fclose(fp);

		decrypted_data = (char *)malloc(1);

		if(decrypted_data == NULL)
			return NULL;

		decrypted_data[0] = '\0';

		return decrypted_data;
	}

	encrypted_data = (char *)malloc(file_size + 1);

	if(encrypted_data == NULL)
	{
		fclose(fp);
		return NULL;
	}

	fread(encrypted_data, 1, file_size, fp);
	encrypted_data[file_size] = '\0';

	fclose(fp);

	decrypted_data = xor_decrypt(encrypted_data, key);

	free(encrypted_data);

	return decrypted_data;
}


/*Function name: append_to_encrypted_file
Descripton: Appends new data to an existing encrypted file by decrypting its content, combining it with the new data, re-encrypting the result, and writing it back to the file.
Author : Akash Gupta
Created At: 07-05-2026
 */
int32_t append_to_encrypted_file(const char *filename, uint16_t key, const char *new_data)
{
	FILE *fp;
	char *old_content;
	char *combined_content;
	char *encrypted_content;
	size_t old_len, new_len;

	if(filename == NULL || filename[0] == '\0' || new_data == NULL || key == 0)
		return 2;
	if ( key != FIXED_XOR_KEY){
		return 4;
	} 
	fp = fopen(filename, "r");

	if(fp == NULL)
		return 1;

	fclose(fp);

	old_content = read_encrypted_file(filename, key);

	if(old_content == NULL)
		return 4;

	old_len = strlen(old_content);
	new_len = strlen(new_data);

	combined_content = (char *)malloc(old_len + new_len + 1);

	if(combined_content == NULL)
	{
		free(old_content);
		return 3;
	}

	strcpy(combined_content, old_content);
	strcat(combined_content, new_data);

	free(old_content);

	encrypted_content = xor_encrypt(combined_content, key);

	free(combined_content);

	if(encrypted_content == NULL)
		return 3;

	fp = fopen(filename, "w");

	if(fp == NULL)
	{
		free(encrypted_content);
		return 3;
	}

	if(fputs(encrypted_content, fp) == EOF)
	{
		fclose(fp);
		free(encrypted_content);
		return 3;
	}

	fclose(fp);
	free(encrypted_content);

	return 0;
}

/*Function name: log_operation                                                                                                         Descripton: Logs a file operation by recording the timestamp, username, operation type, and filename into an audit log file for tracking and security purposes.
Author : Akash Gupta
Created At: 06-05-2026
 */
int32_t log_operation(const char *username, const char *operation, const char *filename)
{
	FILE *fp;
	time_t now;
	struct tm *t;
	char timestamp[100];

	if(username == NULL || operation == NULL || filename == NULL)
		return 1;

	if(strlen(username) == 0 || strlen(operation) == 0 || strlen(filename) == 0)
		return 1;

	now = time(NULL);
	t = localtime(&now);

	if(t == NULL)
		return 2;

	strftime(timestamp, sizeof(timestamp), "%a %b %d %H:%M:%S %Y", t);

	fp = fopen("operations.log", "a");

	if(fp == NULL)
		return 2;

	if(fprintf(fp,"%s - USER: %s, OPERATION: %s, FILE: %s\n",timestamp, username, operation, filename) < 0)
	{
		fclose(fp);
		return 2;
	}

	fflush(fp);
	fclose(fp);

	return 0;

}
int16_t check_file_permission(const char *filename, const char *username, const char *operation)
{
        FILE *fp;
        char line[256];
        char storedFilename[128];
        char storedUsername[128];
        char storedPermissions[32];

        if(filename == NULL || username == NULL || operation == NULL)
                return 0;

        fp = fopen(PERMISSION, "r");

        if(fp == NULL)
                return 0;

        while(fgets(line, sizeof(line), fp) != NULL)
        {
                if(sscanf(line, "%127[^:]:%127[^:]:%31[^\n]",
                                storedFilename,
                                storedUsername,
                                storedPermissions) == 3)
                {
                        if(strcmp(filename, storedFilename) == 0 &&
                           strcmp(username, storedUsername) == 0)
                        {
                                fclose(fp);

                                if(strchr(storedPermissions, operation[0]) != NULL)
                                        return 1;
                                else
                                        return 0;
                        }
                }
        }

        fclose(fp);
        return 0;
}
/*
 * Function Name: secure_delete()
 * Function Description: This function validate the filename, username and permissions from permissions.db and delete the file if permissions is valid.
 * Author: Akash Gupta
 * Created: 8 May, 2026
 */

int16_t secure_delete(const char *filename, const char *username)
{
        if(filename == NULL || username == NULL){
                return 2;
        }

        if(strlen(filename) == 0 || strlen(username) == 0){
                return 2;
        }

        FILE *fp = fopen(filename, "r+");

        if(fp == NULL){
                return 1;
        }

        int8_t authorized = check_file_permission(filename, username, "d");

        if(!authorized){
                fclose(fp);
                return 2;
        }

        fseek(fp, 0, SEEK_END);
        long fileSize = ftell(fp);
        rewind(fp);

        for(long indx = 0; indx < fileSize; indx++){
                fputc('\0', fp);
        }

        fflush(fp);
        fsync(fileno(fp));
        fclose(fp);

        if(remove(filename) != 0){
                return 3;
        }

        return 0;
}

void set_file_permission(const char *filename,
                         const char *username,
                         const char *permissions)
{
        FILE *fp;
        FILE *temp;
        char line[256];
        char storedFile[128];
        char storedUser[128];
        char storedPerm[32];
        int8_t found = 0;

        if(filename == NULL || username == NULL || permissions == NULL)
                return;

        fp = fopen(PERMISSION, "r");
        temp = fopen("temp.db", "w");

        if(temp == NULL)
                return;

        if(fp != NULL)
        {
                while(fgets(line, sizeof(line), fp) != NULL)
                {
                        if(sscanf(line, "%127[^:]:%127[^:]:%31[^\n]",
                                        storedFile,
                                        storedUser,
                                        storedPerm) == 3)
                        {
                                if(strcmp(filename, storedFile) == 0 &&
                                   strcmp(username, storedUser) == 0)
                                {
                                        fprintf(temp, "%s:%s:%s\n",
                                                        filename,
                                                        username,
                                                        permissions);
                                        found = 1;
                                }
                                else
                                {
                                        fputs(line, temp);
                                }
                        }
                }

                fclose(fp);
        }

        if(!found)
        {
                fprintf(temp, "%s:%s:%s\n",
                                filename,
                                username,
                                permissions);
        }

        fclose(temp);

        remove(PERMISSION);
        rename("temp.db", PERMISSION);
}
