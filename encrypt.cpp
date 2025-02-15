#include "encryption_handler.h"
#include <iostream>
#include <string>
#include <exception>

using std::cout;
using std::cerr;
using std::string;
using std::exception;

void printUsage() {
    cout << "Usage: ./encrypt [-e|-d] <input_file> <output_file> <key_file>\n";
    cout << "       ./encrypt -g <key_file>\n";
    cout << "  -e: encrypt mode\n";
    cout << "  -d: decrypt mode\n";
    cout << "  -g: generate a new encryption key\n";
}

int main(int argc, char* argv[]) {
    try {
        // Not enough arguments
        if (argc < 2) {
            printUsage();
            return 1;
        }

        string mode = argv[1];

        // Generate a new encryption key
        if (mode == "-g") {
            if (argc != 3) {
                cerr << "Error: Key generation requires a key file path.\n";
                printUsage();
                return 1;
            }
            string keyFile = argv[2];
            EncryptionHandler::generateKey(keyFile);
            cout << "Key generated successfully and saved to: " << keyFile << "\n";
            return 0;
        }

        if (argc != 5) {
            printUsage();
            return 1;
        }

        string inputFile = argv[2];
        string outputFile = argv[3];
        string keyFile = argv[4];

        if (mode != "-e" && mode != "-d") {
            std::cerr << "Error: Invalid mode. Use -e for encryption or -d for decryption.\n";
            printUsage();
            return 1;
        }

        // Encrypt or decrypt mode
        bool isEncrypt = (mode == "-e");
        EncryptionHandler::processFile(inputFile, outputFile, keyFile, isEncrypt);

        // Print success message
        std::cout << (isEncrypt ? "Encryption" : "Decryption") << " completed successfully.\n";
        return 0;

    } catch (const exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }
}