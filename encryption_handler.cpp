#include "encryption_handler.h"
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <random>

using std::string;
using std::ifstream;
using std::ofstream;
using std::runtime_error;

unsigned char EncryptionHandler::readKeyFromFile(const string& keyFile) {
    // Read from file in binary mode rather than text
    ifstream inFile(keyFile, std::ios_base::binary);
    if (!inFile) {
        throw runtime_error("Unable to open key file: " + keyFile);
    }
    // Read key from file
    char key;
    if (!inFile.get(key)) {
        throw runtime_error("Unable to read key from file: " + keyFile);
    }

    inFile.close();
    return key;
}

char EncryptionHandler::encryptChar(char c, unsigned char key) {
    // XOR operation
    return c ^ key;
}

char EncryptionHandler::decryptChar(char c, unsigned char key) {
    // XOR operation
    return c ^ key;
}

void EncryptionHandler::generateKey(const string& keyFile) {
    std::random_device rd;
    // Initializes a Mersenne Twister pseudo-random number generator with a random seed from rd
    std::mt19937 gen(rd());
    // Distribution that produces random integers uniformly in the range [0, 255]
    std::uniform_int_distribution<> distrib(0, 255);

    // Generate a new random key
    char newKey = static_cast<char>(distrib(gen));

    // Write key to file in binary mode
    ofstream outFile(keyFile, std::ios_base::binary);
    if (!outFile) {
        throw runtime_error("Unable to create key file: " + keyFile);
    }

    outFile.put(newKey);
    outFile.close();
}

void EncryptionHandler::processFile(const string& inputFile, const string& outputFile, const string& keyFile, bool isEncrypt) {
    // Read key from file
    unsigned char key = readKeyFromFile(keyFile);

    // Open input and output files
    ifstream inFile(inputFile);
    if (!inFile) {
        throw runtime_error("Unable to open input file: " + inputFile);
    }

    ofstream outFile(outputFile);
    if (!outFile) {
        throw runtime_error("Unable to create output file: " + outputFile);
    }

    // Encrypt/decrypt each character in the input file and write to output file
    char c;
    while (inFile.get(c)) {
        char processedChar = isEncrypt ? encryptChar(c, key) : decryptChar(c, key);
        outFile.put(processedChar);
    }

    inFile.close();
    outFile.close();
}