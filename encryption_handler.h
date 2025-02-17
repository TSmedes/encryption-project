#ifndef ENCRYPTION_HANDLER_H
#define ENCRYPTION_HANDLER_H

#include <string>

using std::string;

class EncryptionHandler {
private:
    static unsigned char readKeyFromFile(const string& keyFile);
    static char encryptCharXOR(char c, unsigned char key);
    static char decryptCharXOR(char c, unsigned char key);
    static char encryptCharShift(char c, char key);
    static char decryptCharShift(char c, char key);

public:
    static void processFileXOR(const string& inputFile, const string& outputFile, const string& keyFile, bool isEncrypt);
    static void processFileShift(const string& inputFile, const string& outputFile, const string& keyFile, bool isEncrypt);
    static void generateKey(const string& keyFile);
};

#endif // ENCRYPTION_HANDLER_H