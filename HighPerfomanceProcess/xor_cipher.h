//
//  xor_cipher.h
//  HighPerfomanceProcess
//
//  Created by Ilya on 04.09.2025.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void xor_encrypt_decrypt(const char* input, char* output, const char* key, int length) {
    int key_len = strlen(key);
    for (int i = 0; i < length; i++) {
        output[i] = input[i] ^ key[i % key_len];
    }
}

char* xor_encrypt_string(const char* input, const char* key) {
    int length = strlen(input);
    char* encrypted = (char*)malloc(length + 1);
    if (encrypted == NULL) return NULL;
    
    xor_encrypt_decrypt(input, encrypted, key, length);
    encrypted[length] = '\0';
    return encrypted;
}

char* xor_decrypt_string(const char* input, const char* key) {
    return xor_encrypt_string(input, key);
}
