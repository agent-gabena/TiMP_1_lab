#include "modAlphaCipher.h"

std::string modAlphaCipher::encrypt(const std::string& user_str) 
{
    std::string new_str = user_str;
    int length, line_count, position, i; 
    length = user_str.size(); 
    line_count = (length - 1) / newkey + 1; 
    i = 0;
    for (int colum_number = newkey; colum_number > 0; colum_number--) { 
        for (int line_number = 0; line_number < line_count; line_number++) { 
            position = newkey*line_number+colum_number; 
            new_str[position-1] = user_str[i];
            i++;
            
        }
    }
    return new_str;
}
std::string modAlphaCipher::decrypt(const std::string& user_str) 
{
    std::string new_str = user_str;
    int length, line_count, position, i; 
    length = user_str.size(); 
    line_count = (length - 1) / newkey + 1; 
    i = 0;
    for (int colum_number = newkey; colum_number > 0; colum_number--) { 
        for (int line_number = 0; line_number < line_count; line_number++) { 
            position = colum_number+newkey*line_number;
            new_str[i] = user_str[position-1];
            i++;
            
        }
    }
    return new_str;
}