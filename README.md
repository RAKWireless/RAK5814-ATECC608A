| <center><img src="./assets/rakstar.jpg" alt="RAKstar" width=25%></center>  | ![RAKWireless](./assets/RAK-Whirls.png) | [![Build Status](https://github.com/RAKWireless/RAK13005-TLE7259-Library/workflows/RAK%20Library%20Build%20CI/badge.svg)](https://github.com/RAKWireless/RAK13005-TLE7259-Library/actions) |
| -- | -- | -- |

# <RAK5814>

RAK5814-ATECC608A is modified from ArduinoECCX08 Version 1.3.6. Added support for RAK11200 based on the original library.
To access certain features of the ATECC608A, users will need to contact Microchip and sign an NDA contract to obtain the complete datasheet. Due to the required NDA - technical support, an Arduino library, and hookup guide are not provided for users on this product.

The ATECC608A chip is capable of many cryptographic processes, including, but not limited to:

- Creating and securely storing unique asymmetric key pairs based on Elliptic Curve Cryptography (FIPS186-3).

- AES-128: Encrypt/Decrypt, Galois Field Multiply for GCM
- Creating and verifying 64-byte digital signatures (from 32-bytes of message data).
- Creating a shared secret key on a public channel via Elliptic Curve Diffie-Hellman Algorithm.
- SHA-256 & HMAC Hash including off-chip context save/restore
- Internal high quality FIPS random number generator.

Embedded in the chip is a 10Kb EEPROM array that can be used for storing keys, certificates, data, consumption logging, and security configurations. 

[*RAKWireless <RAK#> <function>*](https://store.RAKWireless.com/products/Encrypt-rak5814)

# Documentation

* **[Product Repository](https://github.com/RAKWireless/RAK5814-ATECC608A)** - Product repository for the RAKWireless RAK5814 Encrypt module.
* **[Documentation](https://docs.RAKWireless.com/Product-Categories/WisBlock/RAK5814/Overview/)** - Documentation and Quick Start Guide for the RAK5814 Encrypt module.

# Installation

In Arduino IDE open Sketch->Include Library->Manage Libraries then search for RAK5814 .

In PlatformIO open PlatformIO Home, switch to libraries and search for RAK5814 .
Or install the library project dependencies by adding

```log
lib_deps =
  RAKWireless/RAKWireless ATECC608A Encrypt library
```

into **`platformio.ini`**

For manual installation download the archive, unzip it and place the RAK5814-ATECC608A folder into the library directory.
In Arduino IDE this is usually <arduinosketchfolder>/libraries/
In PlatformIO this is usually <user/.platformio/lib>

# Usage

The library provides RAK_ATECC608A class, which allows communication with ATECC608A via IIC. These examples show how to use RAK5814.

- [RAK5814_CSR_Encrypt_ATECC608A](./examples/RAK5814_CSR_Encrypt_ATECC608A)This sketch can be used to generate a CSR for a private key generated in an ATECC608A crypto chip slot. If the ECC608 is not configured and locked it prompts the user to configure and lock the chip with a default TLS configuration.The user is prompted for the following information that is contained in the generated CSR:
  - country
  - state or province
  - locality
  - organization
  - organizational unit
  - common name
- [RAK5814_Hash_Encrypt_ATECC608A](./examples/RAK5814_Hash_Encrypt_ATECC608A) This example shows how to create a hash on larger amounts of data. If you have only 32 bytes of data, then you can simply sign the data, But if you have more than that, then you mush send your data into an SHA256 algorithm,And this will create a 32-byte hash of the data.  It's kind of like a signature, but it's created with a standard algorithm, and so anyone can make it. The ATECC608A will make it for us easily in an embedded system.
- [RAK5814_Random_Encrypt_ATECC608A](./examples/RAK5814_Random_Encrypt_ATECC608A) This example shows how to use the Random Number Generator on the ATECC608A. It will print random numbers once a second on the serial terminal at 115200.
- [RAK5814_Sign_Encrypt_ATECC608A](./examples/RAK5814_Sign_Encrypt_ATECC608A) This example shows how to create a digital signature on 32 bytes of data.
- [RAK5814_Verify_Encrypt_ATECC608A](./examples/RAK5814_Verify_Encrypt_ATECC608A) This example shows how to verify a digital signature of a message using an external public key.

## This class provides the following methods:

**int ECCX08Class::begin(uint8_t i2cAddress)**

Initialize ECC608.

#### Parameters:

| Direction | Name       | Function                                              |
| --------- | ---------- | ----------------------------------------------------- |
| in        | i2cAddress | Device address should be 0x60.                        |
| return    |            | If the device init successful return 1 else return 0. |

**void ECCX08Class::end()  **

Close communication with ECC608.

#### Parameters:

| Direction | Name | Function |
| --------- | ---- | -------- |
| return    |      | none     |

**int ECCX08Class::serialNumber(byte sn[]) **

Get the Serial number of ECC608.

#### Parameters:

| Direction | Name | Function                                      |
| --------- | ---- | --------------------------------------------- |
| in        | sn   | Serial number array pointer.                  |
| return    |      | If the get successful return 1 else return 0. |

**String ECCX08Class::serialNumber() **

Get the Serial number of ECC608.

#### Parameters:

| Direction | Name | Function              |
| --------- | ---- | --------------------- |
| return    |      | Serial number string. |

**long ECCX08Class::random(long max)  **

Get a random number in the range from 0 to max.

#### Parameters:

| Direction | Name | Function                    |
| --------- | ---- | --------------------------- |
| in        | max  | Maximum random number.      |
| return    |      | The obtained random number. |

**long ECCX08Class::random(long min, long max)  **

Get random numbers in a specified range.

#### Parameters:

| Direction | Name | Function                    |
| --------- | ---- | --------------------------- |
| in        | min  | Minimum random number.      |
| in        | max  | Maximum random number.      |
| return    |      | The obtained random number. |

**int ECCX08Class::random(byte data[], size_t length)**

Get a random number of specified length bytes.

#### Parameters:

| Direction | Name   | Function                                      |
| --------- | ------ | --------------------------------------------- |
| in        | data   | Random number data pointer.                   |
| in        | length | Data length.                                  |
| return    |        | If the get successful return 1 else return 0. |

**int ECCX08Class::ecdsaVerify(const byte message[], const byte signature[], const byte pubkey[])**

Verify signature data.

#### Parameters:

| Direction | Name      | Function                                      |
| --------- | --------- | --------------------------------------------- |
| in        | message   | Signed data pointer.                          |
| in        | signature | Signature data pointer.                       |
| in        | pubkey    | Public key.                                   |
| return    |           | If the get successful return 1 else return 0. |

**int ECCX08Class::ecSign(int slot, const byte message[], byte signature[])**

Sign the specified data.

#### Parameters:

| Direction | Name      | Function                                      |
| --------- | --------- | --------------------------------------------- |
| in        | message   | Data pointer that needs to be signed.         |
| in        | signature | Signature data pointer.                       |
| in        | slot      | Slot used.                                    |
| return    |           | If the get successful return 1 else return 0. |