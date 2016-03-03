//
//  CaesarCipher.hpp
//  assignment5
//
//  Created by Jacob Dickinson on 2/7/15.
//
//

#ifndef CAESAR_CIPHRT_HPP_
#define CAESAR_CIPHRT_HPP_

#include "cipher.hpp"

class CaesarCipher : public Cipher {
public:
    CaesarCipher();
    CaesarCipher(int shift);
    virtual ~CaesarCipher();
    virtual std::string encrypt( std::string &text);
    virtual std::string decrypt( std::string &text);
private:
    int rotN;
    char alpha[53] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', ' '};
};

#endif
