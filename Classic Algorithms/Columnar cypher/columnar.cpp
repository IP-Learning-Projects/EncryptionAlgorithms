#include <bits/stdc++.h>

std::map<int, int> keyMap;

void orderColumns(const std::string &key) {
  for (unsigned int i = 0; i < key.length(); i++) {
    keyMap[key[i]] = i;
  }
}

std::string encrypt(std::string text, const std::string &key) {
  unsigned int row, column;
  std::string cipher;
  column = key.length();
  row = text.length() / column;
  if (text.length() % column) {
    row += 1;
  }
  char matrix[row][column];

  for (unsigned int i = 0, k = 0; i < row; i++) {
    for (unsigned int j = 0; j < column;) {
      if (text[k] == '\0') {
        matrix[i][j] = '_';
        j++;
      }
      if (isalpha(text[k]) || text[k] == ' ') {
        matrix[i][j] = text[k];
        j++;
      }
      k++;
    }
  }
  unsigned int j = 0;
  for (auto &iterator : keyMap) {
    j = iterator.second;
    for (unsigned int i = 0; i < row; i++) {
      if (isalpha(matrix[i][j]) || matrix[i][j] == ' ' || matrix[i][j] == '_')
        cipher += matrix[i][j];
    }
  }
  return cipher;
}

std::string decrypt(std::string encryptedText, const std::string &key) {
  unsigned int column = key.length();

  unsigned int row = encryptedText.length() / column;
  char cipherMatrix[row][column];
  for (unsigned int j = 0, k = 0; j < column; j++) {
    for (unsigned int i = 0; i < row; i++) {
      cipherMatrix[i][j] = encryptedText[k++];
    }
  }
  int index = 0;
  for (auto &iterator : keyMap) {
    iterator.second = index++;
  }

  char decryptedText[row][column];
  auto ii = keyMap.begin();
  int k = 0;
  for (int l = 0, j; key[l] != '\0'; k++) {
    j = keyMap[key[l++]];
    for (unsigned int i = 0; i < row; i++) {
      decryptedText[i][k] = cipherMatrix[i][j];
    }
  }
  std::string decrypted;
  for (unsigned int i = 0; i < row; i++) {
    for (unsigned int j = 0; j < column; j++) {
      if (decryptedText[i][j] != '_') decrypted += decryptedText[i][j];
    }
  }
  return decrypted;
}

int main() {
  int choice;
  std::string text;
  std::string key;

  std::cout << "1)Encrypt" << std::endl << "2)Decrypt";
  std::cin >> choice;

  std::cout << "Insert plaintext";
  std::cin >> text;
  std::cout << "Plain text: " << text << std::endl;

  std::cout << "Insert key";
  std::cin >> key;
  std::cout << "key: " << key << std::endl;
  orderColumns(key);

  if (choice == 1) {
    std::string cipher = encrypt(text, key);
    std::cout << "Encrypted Message: " << cipher << std::endl;
  } else {
    std::string decryptedText = decrypt(text, key);
    std::cout << "Decrypted Message: " << decryptedText << std::endl;
  }

  return 0;
}