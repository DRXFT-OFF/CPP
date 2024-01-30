#include <iostream>
using namespace std;

const int key = 188;

char* Cipher(char input[50]);
char* Decipher(char* encrypted_input);
void Print_Encrypted(char* encrypted_pointer);
void Print_Decrypted(char* decrypted_pointer);

int main()
{
	cout << "Enter your string: ";
	char ch[50];
	cin.getline(ch, sizeof(ch));
	char *encrypted, *decrypted;

	encrypted = Cipher(ch);
	decrypted = Decipher(encrypted);

	Print_Encrypted(encrypted);
	Print_Decrypted(decrypted);
	return 0;
}

char* Cipher(char input[50])
{
	char encrypted[50];
	for (int i = 0; input[i] != '\0'; i++)
	{
		encrypted[i] = input[i] ^ key;
	}
	return encrypted;
}

char* Decipher(char* encrypted_input)
{
	char decrypted[50];
	for (int i = 0; encrypted_input[i] != '\0'; i++)
	{
		decrypted[i] = encrypted_input[i] ^ key;
	}
	return decrypted;
}

void Print_Encrypted(char* encrypted_pointer)
{
	cout << "Encrypted: " << encrypted_pointer << "\n";
}

void Print_Decrypted(char* decrypted_pointer)
{
	cout << "Decrypted: " << decrypted_pointer << "\n";
}
