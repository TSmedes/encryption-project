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
    unsigned char key;
    if (!inFile.get(reinterpret_cast<char&>(key))) {
        throw runtime_error("Unable to read key from file: " + keyFile);
    }

    inFile.close();
    return key;
}

void EncryptionHandler::generateKey(const string& keyFile) {
    std::random_device rd;
    // Initializes a Mersenne Twister pseudo-random number generator with a random seed from rd
    std::mt19937 gen(rd());
    // Distribution that produces random integers uniformly in the range [0, 255]
    std::uniform_int_distribution<> distrib(0, 255);

    // Generate a new random key
    unsigned char newKey = static_cast<unsigned char>(distrib(gen));

    // Write key to file in binary mode
    ofstream outFile(keyFile, std::ios_base::binary);
    if (!outFile) {
        throw runtime_error("Unable to create key file: " + keyFile);
    }

    outFile.put(newKey);
    outFile.close();
}

char EncryptionHandler::encryptCharXOR(char c, unsigned char key) {
    // XOR operation
    return c ^ key;
}

char EncryptionHandler::decryptCharXOR(char c, unsigned char key) {
    // XOR operation
    return c ^ key;
}


char EncryptionHandler::encryptCharShift(char c, char key) {
    // Encrypt a character using Vigenère cipher (single character key)
    if (!isalpha(c)) {
        return c; 
    }

    char base = islower(c) ? 'a' : 'A'; // Determine if the character is uppercase or lowercase
    char keyChar = key;  // Use the key character (since it's now a single character)
    int shift = (keyChar - base) % 26;
    char encryptedChar = (c - base + shift) % 26 + base;

    return encryptedChar;
}

char EncryptionHandler::decryptCharShift(char c, char key) {
    // Decrypt a character using Vigenère cipher (single character key)
    if (!isalpha(c)) {
        return c; 
    }

    char base = islower(c) ? 'a' : 'A'; // Determine if the character is uppercase or lowercase
    char keyChar = key;  // Use the key character (since it's now a single character)
    int shift = (keyChar - base) % 26;
    char decryptedChar = (c - base - shift + 26) % 26 + base;

    return decryptedChar;
}




void EncryptionHandler::processFileXOR(const string& inputFile, const string& outputFile, const string& keyFile, bool isEncrypt) {
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
        char processedChar = isEncrypt ? encryptCharXOR(c, key) : decryptCharXOR(c, key);
        outFile.put(processedChar);
    }

    inFile.close();
    outFile.close();
}


void EncryptionHandler::processFileShift(const string& inputFile, const string& outputFile, const string& keyFile, bool isEncrypt) {
    // Read key from file (now returns a single char)
    char key = readKeyFromFile(keyFile); // Read the single key character

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
        char processedChar = isEncrypt ? encryptCharShift(c, key) : decryptCharShift(c, key);
        outFile.put(processedChar);
    }

    inFile.close();
    outFile.close();
}
