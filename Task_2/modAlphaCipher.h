#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cctype>
#include <codecvt>


class modAlphaCipher
{
private:
    int newkey;
public:
    modAlphaCipher()=delete;
    modAlphaCipher(const int& key) :newkey(key) {};   
    std::string encrypt(const std::string& user_str);  
    std::string decrypt(const std::string& user_str); 
};