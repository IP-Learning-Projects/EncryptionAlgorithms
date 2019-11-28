#include <bits/stdc++.h>

std::string generateKey(const std::string text, const std::string key) {
  std::string result = key;
  for (char i : text) {
    result += i;
  }
  return result;
}

std::string encrypt(std::string text, std::string key) {
  std::string encryptedText;
  for (unsigned int i = 0; i < text.size(); i++) {
    int encryptedLetter = (text[i] + key[i]) % 26;
    encryptedLetter += 'A';
    encryptedText.push_back(encryptedLetter);
  }
  return encryptedText;
}

std::string decrypt(std::string encryptedText, std::string key) {
  std::string decryptedText;
  for (unsigned int i = 0; i < encryptedText.size(); i++) {
    int decryptedLetter = (encryptedText[i] - key[i] + 26) % 26;
    decryptedLetter += 'A';
    decryptedText.push_back(decryptedLetter);
  }
  return decryptedText;
}

int main() {
  int choice;
  std::string text;
  std::string keyword;

  std::cout << "1)Encrypt" << std::endl << "2)Decrypt";
  std::cin >> choice;

  std::cout << "Insert plaintext";
  std::cin >> text;
  std::cout << "Plain text: " << text << std::endl;

  std::cout << "Insert keyword";
  std::cin >> keyword;
  std::cout << "keyword: " << keyword << std::endl;

  std::string key = generateKey(text, keyword);
  std::cout << "Generated key: " << key << std::endl;

  if (choice == 1) {
    std::string encryptedText = encrypt(text, key);
    std::cout << "Encrypted : " << encryptedText << std::endl;
  } else {
    std::string decryptedText = decrypt(text, key);
    std::cout << "Decrypted Text : " << decryptedText << std::endl;
  }

  return 0;
}
