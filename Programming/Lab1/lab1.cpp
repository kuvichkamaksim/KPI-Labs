#include <iostream>
#include <string>
using namespace std;

string encrypt (string message, string key, char matrix[91][91]) {
  int i;
  string cryptedMessage;
  for (i= 0; i < message.length(); i++) {
    int keyIndex = key.at(i % key.length()) - 32;
    cryptedMessage += matrix[message.at(i) - 32][keyIndex];
  };
  cout << cryptedMessage;
  cout << endl;
  return (cryptedMessage);
};

void decrypt (string message, string key, char matrix[91][91]) {
  int i, j;
  for (i= 0; i < message.length(); i++) {
    int keyIndex = key.at(i % key.length()) - 32;
    for (j= 0; j < 91; j++) {
      if ( matrix[keyIndex][j] == message[i]) break;
    };
    cout << matrix[0][j];
  };
  cout << endl;
};

int main() {
  string message="message", key="key";
  cout << "Enter your message: " << endl;
  cin >> message;

  char matrix [91][91];
  int i, j;

  for (i= 0; i <= 90; i++) {
    for (j= 0; j < 90; j++) {
      int count = (i + j) % 90;
      matrix[i][j]= char(count + 32);
      // cout << matrix[i][j];
    };
    // cout << endl;
  };
  string cryptedMessage = encrypt(message, key, matrix);

  decrypt(cryptedMessage, key, matrix);
  return (0);
};
