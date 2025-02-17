#include "encryption_handler.h"
#include <iostream>
#include <string>
#include <exception>

using std::cout;
using std::cerr;
using std::cin;
using std::string;
using std::exception;

void printUsage() {
    cout << "1. Generate a new encryption key\n";
    cout << "2. Encrypt a file with XOR\n";
    cout << "3. Decrypt a file with XOR\n";
    cout << "4. Encrypt a file with Shift\n";
    cout << "5. Decrypt a file with Shift\n";
    cout << "Enter your choice (1-5): ";
}

int main() {
    try {
        int choice;
        printUsage();
        cin >> choice;

        if (choice == 1) {
            string keyFile;
            cout << "Enter key file name: ";
            cin >> keyFile;
            EncryptionHandler::generateKey(keyFile);
            cout << "Key generated successfully and saved to: " << keyFile << "\n";
        } 
        else if (choice == 2 || choice == 3) {
            string inputFile, outputFile, keyFile;
            cout << "Enter input file name: ";
            cin >> inputFile;
            cout << "Enter output file name: ";
            cin >> outputFile;
            cout << "Enter key file name: ";
            cin >> keyFile;

            bool isEncrypt = (choice == 2);
            EncryptionHandler::processFileXOR(inputFile, outputFile, keyFile, isEncrypt);
            cout << (isEncrypt ? "Encryption" : "Decryption") << " completed successfully.\n";
        } 
        else if (choice == 4 || choice == 5) {
            string inputFile, outputFile, keyFile;
            cout << "Enter input file name: ";
            cin >> inputFile;
            cout << "Enter output file name: ";
            cin >> outputFile;
            cout << "Enter key file name: ";
            cin >> keyFile;

            bool isEncrypt = (choice == 4);
            EncryptionHandler::processFileShift(inputFile, outputFile, keyFile, isEncrypt);
            cout << (isEncrypt ? "Encryption" : "Decryption") << " completed successfully.\n";
        } 
        else {
            cerr << "Invalid choice. Please restart the program and enter a valid option.\n";
            return 1;
        }

        return 0;
    } 
    catch (const exception& e) {
        cerr << "Error: " << e.what() << "\n";
        return 1;
    }
}
