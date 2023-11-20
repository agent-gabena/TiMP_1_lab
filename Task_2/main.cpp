#include "modAlphaCipher.h"


bool isValid(const std::string& s)
{
    for(const auto &c:s) // цикл проходит по всему массиву и выдает сам объект этого массива
        if (!isalpha(c) )
            return false;
    return true;
    
}


int main(int argc, char **argv)
{
    int key;
    std::string text;
    unsigned op;
    std::cout<<"Cipher ready. Input key: ";
    std::cin>>key;
    if (!std::cin.good()) {
        std::clog<<"key not valid\n";
        return 1;
    }
    std::cout<<"Key loaded\n";
    modAlphaCipher cipher(key);
    do {
        std::cout<<"Cipher ready. Input operation (0-exit, 1-encrypt, 2-decrypt): ";
        std::cin>>op;
        if (op > 2) {
            std::cout<<"Illegal operation\n";
        } else if (op >0) {
            std::cout<<"Cipher ready. Input text: ";
            std::cin>>text;
            if (isValid(text)) {
                if (op==1) {
                    std::cout<<"Encrypted text: "<<cipher.encrypt(text)<<std::endl;
                } else {
                    std::cout<<"Decrypted text: "<<cipher.decrypt(text)<<std::endl;
                }
            } else {
                std::cout<<"Operation aborted: invalid text\n";
            }
        }
    } while (op!=0);

    return 0;
}