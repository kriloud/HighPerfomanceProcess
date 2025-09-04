//
//  xor_cipher.h
//  HighPerfomanceProcess
//
//  Created by Ilya on 04.09.2025.
//
#ifndef XOR_CIPHER_H
#define XOR_CIPHER_H

#ifdef __cplusplus
extern "C" {
#endif

void xor_cipher(std::string input, std::string output, std::string key, int length) {
    int key_length = 0;
    while (key[key_length] != '\0') key_length++;
    
    for (int i = 0; i < length; i++) {
        output[i] = input[i] ^ key[i % key_length];
    }
}

#ifdef __cplusplus
}
#endif

#endif // XOR_CIPHER_H
