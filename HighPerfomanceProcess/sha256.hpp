//
//  sha256.hpp
//  HighPerfomanceProcess
//
//  Created by Ilya on 04.09.2025.
//

#ifndef SHA256_HPP
#define SHA256_HPP

#include <cstdint>
#include <cstring>
#include <string>

// consts for SHA-256
static const uint32_t K[] = {
    0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
    0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
    0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
    0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
    0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
    0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
    0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
    0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};

inline uint32_t rotr(uint32_t x, uint32_t n) {
    return (x >> n) | (x << (32 - n));
}

inline uint32_t ch(uint32_t x, uint32_t y, uint32_t z) {
    return (x & y) ^ (~x & z);
}

inline uint32_t maj(uint32_t x, uint32_t y, uint32_t z) {
    return (x & y) ^ (x & z) ^ (y & z);
}

inline uint32_t sigma0(uint32_t x) {
    return rotr(x, 2) ^ rotr(x, 13) ^ rotr(x, 22);
}

inline uint32_t sigma1(uint32_t x) {
    return rotr(x, 6) ^ rotr(x, 11) ^ rotr(x, 25);
}

inline uint32_t gamma0(uint32_t x) {
    return rotr(x, 7) ^ rotr(x, 18) ^ (x >> 3);
}

inline uint32_t gamma1(uint32_t x) {
    return rotr(x, 17) ^ rotr(x, 19) ^ (x >> 10);
}

std::string sha256(const std::string& input) {
    uint32_t h0 = 0x6a09e667;
    uint32_t h1 = 0xbb67ae85;
    uint32_t h2 = 0x3c6ef372;
    uint32_t h3 = 0xa54ff53a;
    uint32_t h4 = 0x510e527f;
    uint32_t h5 = 0x9b05688c;
    uint32_t h6 = 0x1f83d9ab;
    uint32_t h7 = 0x5be0cd19;

    // prepare message
    size_t orig_len = input.size();
    size_t new_len = orig_len + 1;
    while (new_len % 64 != 56) new_len++;
    
    uint8_t* msg = new uint8_t[new_len + 8];
    memcpy(msg, input.c_str(), orig_len);
    msg[orig_len] = 0x80;
    for (size_t i = orig_len + 1; i < new_len; i++) msg[i] = 0;
    
    uint64_t bit_len = orig_len * 8;
    for (int i = 0; i < 8; i++) {
        msg[new_len + i] = (bit_len >> (56 - i * 8)) & 0xFF;
    }

    for (size_t i = 0; i < new_len + 8; i += 64) {
        uint32_t w[64];
        for (int j = 0; j < 16; j++) {
            w[j] = (msg[i + j*4] << 24) | (msg[i + j*4+1] << 16) |
                   (msg[i + j*4+2] << 8) | msg[i + j*4+3];
        }
        for (int j = 16; j < 64; j++) {
            w[j] = gamma1(w[j-2]) + w[j-7] + gamma0(w[j-15]) + w[j-16];
        }

        uint32_t a = h0, b = h1, c = h2, d = h3, e = h4, f = h5, g = h6, h = h7;

        for (int j = 0; j < 64; j++) {
            uint32_t t1 = h + sigma1(e) + ch(e, f, g) + K[j] + w[j];
            uint32_t t2 = sigma0(a) + maj(a, b, c);
            h = g;
            g = f;
            f = e;
            e = d + t1;
            d = c;
            c = b;
            b = a;
            a = t1 + t2;
        }

        h0 += a; h1 += b; h2 += c; h3 += d;
        h4 += e; h5 += f; h6 += g; h7 += h;
    }

    delete[] msg;

    // result
    char hash[65];
    sprintf(hash, "%08x%08x%08x%08x%08x%08x%08x%08x",
            h0, h1, h2, h3, h4, h5, h6, h7);
    hash[64] = 0;

    return std::string(hash);
}

#endif
