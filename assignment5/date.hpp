//
//  DateCipher.hpp
//  assignment5
//
//  Created by Jacob Dickinson on 2/9/15.
//
//

#ifndef DATE_CIPHRT_HPP_
#define DATE_CIPHRT_HPP_

#include "cipher.hpp"

class DateCipher : public Cipher {
public:
    DateCipher();
    DateCipher(std::string date);
    virtual ~DateCipher();
    virtual std::string encrypt( std::string &text);
    virtual std::string decrypt( std::string &text);
private:
    int rotN[6];
    char alpha[53] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', ' '};
};

#endif
