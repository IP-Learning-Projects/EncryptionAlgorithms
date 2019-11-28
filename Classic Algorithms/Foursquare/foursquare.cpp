#include <iostream>
#include <string>
#include <utility>
#include <vector>

std::string copyUnique(const std::string &text) {
  std::string result;
  for (char i : text) {
    int exists = result.find(i);
    if (exists < 0) {
      result += i;
    }
  }
  return result;
}

std::string square(const std::string &key, const std::string &alphabet) {
  std::string square = copyUnique(key);

  for (char i : alphabet) {
    int exists = square.find(i);
    if (exists < 0) {
      square += i;
    }
  }
  return square;
}

std::string encrypt(const std::string &plain, std::vector<std::string> keys,
                    const std::string &alphabet) {
  std::string cipher;

  std::string cipherAlphabet1 = square(keys[0], alphabet);
  std::string cipherAlphabet2 = square(keys[1], alphabet);

  for (unsigned int i = 0; i < plain.size() - 1; i += 2) {
    // first letter position in pair
    int position = alphabet.find(plain[i]);
    int r = position / 5 + 1;
    int c = position % 5 + 1;

    // second letter position in pair
    position = alphabet.find(plain[i + 1]);
    int rr = position / 5 + 1;
    int cc = position % 5 + 1;

    // encrypt using the cipher alphabet
    char l1 = cipherAlphabet1[5 * r + cc - 6];
    char l2 = cipherAlphabet2[5 * rr + c - 6];

    // append to cipher
    cipher += l1;
    cipher += l2;
  }
  return cipher;
}

std::string decrypt(const std::string &cipher, std::vector<std::string> keys,
                    const std::string &alphabet) {
  std::string plain;

  // construct the ciphered squares
  std::string cipherAlphabet1 = square(keys[0], alphabet);
  std::string cipherAlphabet2 = square(keys[1], alphabet);

  for (unsigned int i = 0; i < cipher.size() - 1; i += 2) {
    // first letter position in pair
    int position = cipherAlphabet1.find(cipher[i]);
    int r = position / 5 + 1;
    int c = position % 5 + 1;

    // second letter position in pair
    position = cipherAlphabet2.find(cipher[i + 1]);
    int rr = position / 5 + 1;
    int cc = position % 5 + 1;

    // encrypt using the cipher alphabet
    char l1 = alphabet[5 * r + cc - 6];
    char l2 = alphabet[5 * rr + c - 6];

    // append decrypted letters to result
    plain += l1;
    plain += l2;
  }
  return plain;
}

int main() {
  int choice;
  std::string text;
  std::vector<std::string> keys;
  std::string temp;
  std::string alphabet = "ABCDEFGHIKLMNOPQRSTUVWXYZ";

  std::cout << "1)Encrypt" << std::endl << "2)Decrypt";
  std::cin >> choice;

  std::cout << "Insert plaintext";
  std::cin >> text;
  std::cout << "Plain text: " << text << std::endl;

  std::cout << "Insert key 1";
  std::cin >> temp;
  keys.push_back(temp);
  std::cout << "key1 : " << temp << std::endl;

  std::cout << "Insert key 2";
  std::cin >> temp;
  keys.push_back(temp);
  std::cout << "key 2: " << temp << std::endl;
  if (choice == 1) {
    std::string encryptedMessage = encrypt(text, keys, alphabet);
    std::cout << "Encrypted text: " << encryptedMessage << std::endl;
  } else {
    std::string decrypted = decrypt(text, keys, alphabet);
    std::cout << "Decrypted text: " << decrypted << std::endl;
  }

  return 0;
}