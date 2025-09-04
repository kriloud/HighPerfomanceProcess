//
//  xor.hpp
//  HighPerfomanceProcess
//
//  Created by Ilya on 04.09.2025.
//

#include <string>

inline std::string xor_cipher(const std::string& input, const std::string& key) {
    std::string output = input;
    for (size_t i = 0; i < input.size(); i++) {
        output[i] = input[i] ^ key[i % key.size()];
    }
    return output;
}
