#include <iostream>
using namespace std;

class Crypt
{
	const int key = 25;
	char encrypt_char[50], decrypt_char[50];
	char *encrypted, *decrypted;
	public:
		Crypt()
		{
			encrypted = encrypt_char;
			decrypted = decrypt_char;
		}
		char* Encrypt(char* string);
		char* Decrypt(char* string);
		void Print_encrypt()
		{
			if (encrypt_char[0]) cout << encrypted;
			else cout << "Error! String is empty!";
		}
		void Print_decrypt()
		{
			if (decrypt_char[0]) cout << decrypted;
			else cout << "Error! String is empty!";
		}
};

char* Crypt::Encrypt(char* string)
{
	for (int i = 0; string[i]; i++)
	{
		encrypted[i] = string[i] ^ key;
	}
	return encrypted;
}

char* Crypt::Decrypt(char* string)
{
	for (int i = 0; string[i]; i++)
	{
		decrypted[i] = string[i] ^ key;
	}
	return decrypted;
}

int main()
{
	Crypt crypt;
	char input[50];
	char choose;
	while (true)
	{
		cout << "Choose: \n" << "1.Encrypt \n" << "2.Decrypt \n" << "3.Print last saved encrypt \n" << "4.Print last saved decrypt \n" << "5.Close programm \n";
		cin >> choose;
		cin.ignore();
		switch (choose)
		{
		case '1':
			cout << "Enter string to encrypt: ";
			cin.getline(input, sizeof(input));
			crypt.Encrypt(input);
			cout << "Encrypted: ";
			crypt.Print_encrypt();
			cout << "\n";
			break;
		case '2':
			cout << "Enter string to decrypt: ";
			cin.getline(input, sizeof(input));
			crypt.Decrypt(input);
			cout << "Decrypted: ";
			crypt.Print_decrypt();
			cout << "\n";
			break;
		case '3':
			cout << "Last saved encrypt: ";
			crypt.Print_encrypt();
			cout << "\n";
			break;
		case '4':
			cout << "Last saved decrypt: ";
			crypt.Print_decrypt();
			cout << "\n";
			break;
		case '5':
			exit(0);
			break;
		default:
			cout << "Error! Wrong input!";
			break;
		}
		cout << "\n";
	}
	
	return 0;
}
