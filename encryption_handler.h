#ifndef ENCRYPTION_HANDLER_H
#define ENCRYPTION_HANDLER_H

#include <string>

using std::string;

class EncryptionHandler {
private:
    static unsigned char readKeyFromFile(const string& keyFile);
    static char encryptChar(char c, unsigned char key);
    static char decryptChar(char c, unsigned char key);

public:
    static void processFile(const string& inputFile, const string& outputFile, const string& keyFile, bool isEncrypt);
    static void generateKey(const string& keyFile);
};

#endif // ENCRYPTION_HANDLER_H