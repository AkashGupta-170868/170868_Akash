#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "/home/akash/Take_Away_File_Encryption_System/include/header.h"

#define FIXED_XOR_KEY 43981

void auth_menu(void);
void user_menu(const char *username);

int main(void)
{
	auth_menu();
	return 0;
}

/* Authentication Menu */
void auth_menu(void)
{
	int choice;
	int result;
	char username[50];
	char password[50];

	while(1)
	{
		printf("\n===== SECURE FILE ENCRYPTION SYSTEM =====\n");
		printf("1. Register\n");
		printf("2. Login\n");
		printf("3. Exit\n");
		printf("Enter choice: ");
		scanf("%d", &choice);
		getchar();

		switch(choice)
		{
			case 1:
				printf("Enter Username: ");
				scanf("%49s", username);

				printf("Enter Password: ");
				scanf("%49s", password);
				getchar();

				result = register_user(username, password);

				if(result == 0)
					printf("Registration Successful\n");
				else if(result == 1)
					printf("Username Already Exists\n");
				else
					printf("Registration Failed\n");
				break;

			case 2:
				printf("Enter Username: ");
				scanf("%49s", username);

				printf("Enter Password: ");
				scanf("%49s", password);
				getchar();

				result = login_user(username, password);

				if(result == 0)
				{
					printf("Login Successful\n");
					user_menu(username);
				}
				else
				{
					printf("Invalid Credentials\n");
				}
				break;

			case 3:
				printf("Exiting System...\n");
				exit(0);

			default:
				printf("Invalid Choice\n");
		}
	}
}

/* User Dashboard */
void user_menu(const char *username)
{
	int choice;
	int result;
	char filename[100];
	char text[500];
	char input[500];
	char permissions[10];
	char delete_user[50];
	char key_input[20];
	uint16_t key;
	char *data;
	char *result_text;

	while(1)
	{
		printf("\n===== USER MENU =====\n");
		printf("1. XOR Encrypt Text\n");
		printf("2. XOR Decrypt Text\n");
		printf("3. Create Encrypted File\n");
		printf("4. Read Encrypted File\n");
		printf("5. Append to File\n");
		printf("6. Set File Permission\n");
		printf("7. Secure Delete File\n");
		printf("8. Logout\n");
		printf("Enter choice: ");
		scanf("%d", &choice);
		getchar();

		switch(choice)
		{
			case 1:
				printf("Enter text to encrypt: ");
				fgets(input, sizeof(input), stdin);
				input[strcspn(input, "\n")] = '\0';

				printf("Enter key (Press Enter for default): ");
				fgets(key_input, sizeof(key_input), stdin);

				if(key_input[0] == '\n')
					key = FIXED_XOR_KEY;
				else
					key = (uint16_t)atoi(key_input);

				result_text = xor_encrypt(input, key);

				if(result_text != NULL)
				{
					printf("Encrypted Text: %s\n", result_text);
					free(result_text);
				}
				else
				{
					printf("Encryption Failed\n");
				}
				break;

			case 2:
				printf("Enter encrypted text: ");
				fgets(input, sizeof(input), stdin);
				input[strcspn(input, "\n")] = '\0';

				printf("Enter key (Press Enter for default): ");
				fgets(key_input, sizeof(key_input), stdin);

				if(key_input[0] == '\n')
					key = FIXED_XOR_KEY;
				else
					key = (uint16_t)atoi(key_input);

				result_text = xor_decrypt(input, key);

				if(result_text != NULL)
				{
					printf("Decrypted Text: %s\n", result_text);
					free(result_text);
				}
				else
				{
					printf("Decryption Failed\n");
				}
				break;

			case 3:
				printf("Enter filename: ");
				scanf("%99s", filename);
				getchar();

				printf("Enter text: ");
				fgets(text, sizeof(text), stdin);
				text[strcspn(text, "\n")] = '\0';

				result = create_encrypted_file(filename, text, FIXED_XOR_KEY);

				if(result == 0)
				{
					printf("File Created Successfully\n");
					set_file_permission(filename, username, "rwd");
					log_operation(username, "CREATE", filename);
				}
				else
				{
					printf("File Creation Failed\n");
				}
				break;

			case 4:
				printf("Enter filename: ");
				scanf("%99s", filename);
				getchar();

				data = read_encrypted_file(filename, FIXED_XOR_KEY);

				if(data != NULL)
				{
					printf("File Content: %s\n", data);
					log_operation(username, "READ", filename);
					free(data);
				}
				else
				{
					printf("Read Failed\n");
				}
				break;

			case 5:
				printf("Enter filename: ");
				scanf("%99s", filename);
				getchar();

				printf("Enter data to append: ");
				fgets(text, sizeof(text), stdin);
				text[strcspn(text, "\n")] = '\0';

				result = append_to_encrypted_file(filename,
						FIXED_XOR_KEY,
						text);

				if(result == 0)
				{
					printf("Append Successful\n");
					log_operation(username, "APPEND", filename);
				}
				else
				{
					printf("Append Failed\n");
				}
				break;

			case 6:
				printf("Enter filename: ");
				scanf("%99s", filename);

				printf("Enter permissions (r/w/d): ");
				scanf("%9s", permissions);
				getchar();

				set_file_permission(filename,
						username,
						permissions);

				printf("Permissions Updated\n");
				log_operation(username,
						"PERMISSION",
						filename);
				break;

			case 7:
				printf("Enter filename: ");
				scanf("%99s", filename);

				printf("Enter username for verification: ");
				scanf("%49s", delete_user);
				getchar();

				if(strcmp(username, delete_user) != 0)
				{
					printf("Username Mismatch. Delete Denied\n");
					break;
				}

				result = secure_delete(filename, delete_user);

				if(result == 0)
				{
					printf("File Deleted Securely\n");
					log_operation(username,
							"DELETE",
							filename);
				}
				else if(result == 1)
				{
					printf("File Does Not Exist\n");
				}
				else if(result == 2)
				{
					printf("Unauthorized Delete Attempt\n");
				}
				else
				{
					printf("Delete Failed\n");
				}
				break;

			case 8:
				printf("Logged Out Successfully\n");
				return;

			default:
				printf("Invalid Choice\n");
		}
	}
}
