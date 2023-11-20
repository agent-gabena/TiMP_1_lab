#include <iostream>
#include <cctype>

#include "modAlphaCipher.h"



// проверка, чтобы строка состояла только из прописных букв
bool isValid(const std::wstring& s) {
    for(auto c:s)
        if (!iswalpha(c) || !iswupper(c))
            return false;
    return true;
}

int main(int argc, char **argv) {
    std::locale loc("ru_RU.UTF-8");
    std::locale::global(loc);
    std::wstring key;
    std::wstring text;
    unsigned op;
    std::wcout<<"Cipher ready. Input key: ";
    std::wcin>>key;
    if (!isValid(key)) {
        std::wcerr<<"key not valid\n";
        return 1;
    }
    std::wcout<<"Key loaded\n";
    modAlphaCipher cipher(key);
    do {
        std::wcout<<"Cipher ready. Input operation (0-exit, 1-encrypt, 2-decrypt): ";
        std::wcin>>op;
        if (op > 2) {
            std::wcout<<"Illegal operation\n";
        } else if (op >0) {
            std::wcout<<"Cipher ready. Input text: ";
            std::wcin>>text;
            if (isValid(text)) {
                if (op==1) {
                    std::wcout<<"Encrypted text: "<<cipher.encrypt(text)<<std::endl;
                } else {
                    std::wcout<<"Decrypted text: "<<cipher.decrypt(text)<<std::endl;
                }
            } else {
                std::wcout<<"Operation aborted: invalid text\n";
            }
        }
    } while (op!=0);
    return 0;
}