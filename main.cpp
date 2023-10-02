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
  string encryptedText;
  string encryptionKey;

  cout << "-----------------------------\n";
  cout << "Digite o texto a ser cifrado: \n";
  getline(cin, plainText);
  cout << "\n";

  cout << "Digite a chave: ";
  cin >> encryptionKey;
  cout << "\n";

  Vig v(encryptionKey);
  string encrypt = v.encryption(plainText);

  cout << "Mensagem Cifrada: \n" << encrypt << endl;
  cout << "\n";

  cout << "-------------------------------\n";
  cout << "Digite o texto a ser decifrado: ";
  cout << "\n";
  cin.ignore();
  getline(cin, encryptedText);
  cout << "\n";

  cout << "Digite a chave: ";
  cin >> encryptionKey;
  cout << "\n";

  Vig w(encryptionKey);
  string decrypt = w.decryption(encryptedText);

  cout << "Mensagem Decifrada: \n" << decrypt << endl;

  return 0;
}
