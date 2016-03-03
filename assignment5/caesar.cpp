//
//  CaesarCipher.cpp
//  assignment5
//
//  Created by Jacob Dickinson on 2/6/15.
//
//
#include <string>

#include "cipher.hpp"
#include "caesar.hpp"

CaesarCipher::CaesarCipher() : Cipher(), rotN(1) {
}

CaesarCipher::CaesarCipher(int shift) : Cipher(), rotN(shift) {

}
CaesarCipher::~CaesarCipher(){

}

// Overloaded encrypt method
// Encrypt the text argument and return the encrypted text

std::string
CaesarCipher::encrypt( std::string &inputText){
    int charLoc;
    std::string text = inputText;
    std::string::size_type len = text.length();
    for(int i = 0; i < len; ++i){
        // keep new lines
        if(text[i] == '\n'){
            //kep same
            text[i] = text[i];
        }
        //if not new line
        else{
            //if punc
            if(ispunct(text[i])){
                //keep same
                text[i] = text[i];
            }
            //not punc
            else{
                charLoc = 0;
                while(text[i] != alpha[charLoc]){
                    ++charLoc;
                }
                text[i] = alpha[((charLoc + rotN) %53)];
            }
        }
    }

    return text;
    
}
    
// Decrypt the text argument and return the decrypted text

std::string
CaesarCipher::decrypt( std::string &inputText){
    int charLoc;
    std::string text = inputText;
    std::string::size_type len = text.length();
    for(int i = 0; i < len; ++i){
        // keep new lines
        if(text[i] == '\n'){
            text[i] = text[i];
        }
        else{
            if(ispunct(text[i])){
                text[i] = text[i];
            }
            else{
                charLoc = 0;
                while(text[i] != alpha[charLoc]){
                    ++charLoc;
                }
                if((charLoc - rotN) < 0){
                    text[i] = alpha[((53 + (charLoc - rotN)) % 53)];
                }
                else{
                    text[i] = alpha[((charLoc - rotN) %53)];
                }
            }
        }
    }
    
    return text;
    
}
