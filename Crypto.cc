#include <iostream>
#include <string>

using namespace std;

class Cipher {
public:
	string encrypt(string text);

	Cipher(string text);

	string decrypt(string text);
	
	string text;
};

Cipher::Cipher(string n_text) {

	this->text = n_text;
}

string Cipher::encrypt(string text) {
	return this->text;
}

string Cipher::decrypt(string text) {
	return this->text;
}


class Rot13 : public Cipher {
public:
	Rot13(string text);

	string decrypt_with(Cipher *cipher, string text) {

		for (int i = 0; i < text.size(); ++i) {

			if (isalpha(text[i])) {

				if ((tolower(text[i]) - 'a') < 13)
					cipher->text.append(1, text[i] + 13);

				else
					cipher->text.append(1, text[i] - 13);
			}
			else {
				cipher->text.append(1, text[i]);
			}
		}
		return cipher->text;
	}

	string encrypt_with(Cipher *cipher, string text) {

		for (int i = 0; i < text.size(); ++i) {

			if (isalpha(text[i])) {

				if ((tolower(text[i]) - 'a') < 13)
					cipher->text.append(1, text[i] + 13);

				else
					cipher->text.append(1, text[i] - 13);
			}
			else {
				cipher->text.append(1, text[i]);
			}
		}
		return cipher->text;
	}
};

Rot13::Rot13(string text) : Cipher(text) {}

int main() {
	string source;

	Rot13 *r13 = new Rot13(source);
	Cipher cipher = Cipher(source);

	source = "The quick brown fox jumped over the lazy dog";
	//cout << "What message would you like to encrypt?" << endl;
	//getline(cin, source);

	string encrypted = r13->encrypt_with(&cipher, source);
	string decrypted = r13->decrypt_with(&cipher, encrypted);

	cout << "encrypted: " << encrypted << endl;;
	cout << "decrypted: " << decrypted << endl;

	delete r13;
	return 0;
}
