//
//  DateCipher.cpp
//  assignment5
//
//  Created by Jacob Dickinson on 2/6/15.
//
//

#include <iostream>
#include <string>
#include "date.hpp"


DateCipher::DateCipher() : Cipher(){
    for(int x = 0; x < 6; x++){
        rotN[x] = 1;
    }
    
}


DateCipher::DateCipher(std::string date) : Cipher(){
    if(date.length() != 8){
        std::cout << "invalid date" << std::endl;
    }
    for(int x = 0; x < date.length(); x++){
        if(std::isdigit(date[x])){
            for(int i = 0; i < 6; i++){
                rotN[i] = (int)date[x];
            }
        }
    }
}

DateCipher::~DateCipher(){
}

std::string
DateCipher::encrypt( std::string &inputText){
    int charLoc;
    std::string text = inputText;
    std::string::size_type len = text.length();
    for(int i = 0; i < text.length(); i++){
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
                text[i] = alpha[((charLoc + rotN[i % 6]) %53)];
            }
        }
    }
           
    return text;
}
std::string
DateCipher::decrypt( std::string &inputText){
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
                if((charLoc - rotN[i % 6]) < 0){
                    text[i] = alpha[((53 + (charLoc - rotN[i % 6])) % 53)];
                }
                else{
                    text[i] = alpha[((charLoc - rotN[i % 6]) %53)];
                }
            }
        }
    }
                      
    return text;
}

