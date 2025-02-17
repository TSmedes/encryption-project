# Encryption Project

A simple command-line tool for encrypting and decrypting text files using a XOR cipher and Vigenère cipher.

## Usage

### Building

Compile the program using g++:

```bash
g++ -o encrypt encrypt.cpp encryption_handler.cpp
```

### Running

The following commands are available:


Options:

1: Generate a new encryption key
2: Encrypt a file with XOR
3: Decrypt a file with XOR
4: Encrypt a file with Shift
5: Decrypt a file with Shift

### Examples

To generate a new key:

```bash
1
key.txt
```

To encrypt a file:

```bash
2 or 4
message.txt 
encrypted_message.txt
```

To decrypt a file:

```bash
3 or 5
encrypted_message.txt
decrypted_message.txt
```

Example messages to verify encryption and decryption are available in the `test_messages` folder.

## Implementation Details

### EncryptionXOR

The program uses an XOR cipher. Every bit of the message file is XORed with each bit in the key.

### DecryptionXOR

XOR is a symmetric operation, and can be performed again to decrypt.

### EncryptionShift

The program uses a Vigenere cipher, a polyalphabetic cipher made up of 26 distinct cipher alphabets in a Vigenère square.

### DecryptionShift

Vigenere is a symmetric operation and can be performed with the same key to decrypt.

### Key Generation

In cryptography, key choice is crucial and must be chosen truly randomly. C++'s <random_device> is commonly used for random number generation, however this generator uses a hardware module for random number generation. This is not consistent behavior, and on some machines may use poor algorithms for random number generation. Because of this, we have chosen to use a Mersenne Twister pseudo-random generator seeded with a number from <random_device>. This generates 32-bit random numbers and we use a distributor to evenly distribute these numbers accross the 8-bit range.

The key generated is an 8-bit key.
