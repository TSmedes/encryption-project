# Encryption Project

A simple command-line tool for encrypting and decrypting text files using a XOR cipher.

## Usage

### Building

Compile the program using g++:

```bash
g++ -o encrypt encrypt.cpp encryption_handler.cpp
```

### Running

The following commands are available:

```bash
./encrypt -g <key_file>

./encrypt [-e|-d] <input_file> <output_file> <key_file>
```

Options:

- `-g`: Generate a new key
- `-e`: Encrypt the input file
- `-d`: Decrypt the input file

### Examples

To generate a new key:

```bash
./encrypt -g key.txt
```

To encrypt a file:

```bash
./encrypt -e message.txt encrypted_message.txt
```

To decrypt a file:

```bash
./encrypt -d encrypted.txt decrypted_message.txt
```

Example messages to verify encryption and decryption are available in the `test_messages` folder.

## Implementation Details

### Encryption

The program uses an XOR cipher. Every bit of the message file is XORed with each bit in the key.

### Decryption

XOR is a symmetric operation, and can be performed again to decrypt.

### Key Generation

In cryptography, key choice is crucial and must be chosen truly randomly. C++'s <random_device> is commonly used for random number generation, however this generator uses a hardware module for random number generation. This is not consistent behavior, and on some machines may use poor algorithms for random number generation. Because of this, we have chosen to use a Mersenne Twister pseudo-random generator seeded with a number from <random_device>. This generates 32-bit random numbers and we use a distributor to evenly distribute these numbers accross the 8-bit range.

The key generated is an 8-bit key.
