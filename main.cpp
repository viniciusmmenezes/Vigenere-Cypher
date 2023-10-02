#include <iostream>
#include <string>

using namespace std;

class Vig {
public:
  string k;
  Vig(string k) {
    for (int i = 0; i < k.size(); ++i) {
      if (k[i] >= 'A' && k[i] <= 'Z')
        this->k += k[i];
      else if (k[i] >= 'a' && k[i] <= 'z')
        this->k += k[i] + 'A' - 'a';
    }
  }
  string encryption(string t) {
    string output;
    for (int i = 0, j = 0; i < t.length(); ++i) {
      char c = t[i];
      if (c >= 'a' && c <= 'z')
        c += 'A' - 'a';
      else if (c < 'A' || c > 'Z')
        continue;
      output += (c + k[j] - 2 * 'A') % 26 + 'A';
      j = (j + 1) % k.length();
    }
    return output;
  }
  string decryption(string t) {
    string output;
    for (int i = 0, j = 0; i < t.length(); ++i) {
      char c = t[i];
      if (c >= 'a' && c <= 'z')
        c += 'A' - 'a';
      else if (c < 'A' || c > 'Z')
        continue;
      output += (c - k[j] + 26) % 26 + 'A';
      j = (j + 1) % k.length();
    }
    return output;
  }
};

int main() {
  string plainText;
  string encryptionKey;

  cout << "Digite o texto a ser cifrado: ";
  getline(cin, plainText);

  cout << "Digite a chave: ";
  cin >> encryptionKey;

  Vig v(encryptionKey);
  string ori = plainText;
  string encrypt = v.encryption(ori);
  string decrypt = v.decryption(encrypt);

  cout << "Mensagem Original: " << ori << endl;
  cout << "Mensagem Cifrada: " << encrypt << endl;
  cout << "Mensagem Decifrada: " << decrypt << endl;
}
