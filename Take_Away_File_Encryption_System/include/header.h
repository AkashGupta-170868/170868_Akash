#ifndef HEADER_H
#define HEADER_H

#include <stdint.h>

int32_t register_user(const char *username, const char *password);
int32_t login_user(const char *username, const char *password);
char* xor_encrypt(const char *input_string, uint16_t key);
char* xor_decrypt(const char *encrypted_string, uint16_t key);
 int16_t create_encrypted_file(const char *filename, const char *text, uint16_t key);
char* read_encrypted_file(const char *filename, uint16_t key);
int append_to_encrypted_file(const char *filename, uint16_t key, const char *new_data);
int32_t log_operation(const char *username, const char *operation, const char *filename);
int16_t secure_delete(const char *filename, const char *username);
#endif
