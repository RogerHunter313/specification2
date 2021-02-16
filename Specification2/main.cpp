#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <sstream>  //getline()
using namespace std;

unordered_map<char, char> key;
unordered_set<char> uniqueValues;

string checkValid(string cypher) {
	for (int i = 0; i < cypher.length(); i++) {	
		if (uniqueValues.find((char)toupper(cypher[i])) != uniqueValues.end()) { // finds repeat value
			cout << "Repeated value found." << endl;
			cout << "Clearing the key." << endl;
			key.clear();
			return "Key must not contain repeated values.";
		}

		else if (uniqueValues.find((char)toupper(cypher[i])) == uniqueValues.end()) { 
				if (isalpha(cypher[i]) == false) { // checks if a letter
					cout << "Key must contain only letters" << endl;
					return "invalid";
				}
				else {
					key[(char)(65 + i)] = toupper(cypher[i]); //ascii code
					cout << "Cypher for " << (char)(65 + i)  << " = " << (char)toupper(cypher[i]) << endl;

					key[(char)(97 + i)] = (char)tolower(cypher[i]);
					cout << "Cypher for " << (char)(97 + i) << " = " << (char)tolower(cypher[i]) << endl;

					uniqueValues.insert(toupper(cypher[i]));  //add unique
					cout << "insert " << char(toupper(cypher[i])) << " as unique." << endl;
				}
			}
		
	}

	if (uniqueValues.size() == 26) {
		cout << "Valid key" << endl;
		return "valid";
	}
	else if (uniqueValues.size() != 26) {
		cout << "Key must contain 26 unique letters." << endl;
		key.clear();
	}
	return "invalid";
}

int main() {
	string cypher;
	// cout << "Enter a substitution cypher: >" << flush;
	// getline(cin, cypher);
	cypher = "VCHPRZGJNTLSKFBDQWAXEUYMOI";  //command line argurments demonstrated in class notes

	while (checkValid(cypher) != "valid") {
		cout << "Key invalid." << endl;
		cout << "Enter a valid substitiion cypher: >" << flush;
		getline(cin, cypher);
	}

	auto itr = key.begin(); // creates iterator

	cout << "Cypher: " << endl;  // checking cypher, order through iteration changes, but key stays true
	for (itr = key.begin(); itr != key.end(); itr++) {
		cout << itr->first << " " << itr->second << endl;
	}

	string  pText;
	cout << "plaintext:  " << flush;
	getline(cin, pText);

	cout << endl;
	cout << "ciphertext: ";

	for (int i = 0; i < pText.length(); i++) {
		if (key.find(pText[i]) != key.end()) { //check if in key
			cout << key[(char)pText[i]];
		}

		else {
			cout << pText[i];
		}
	}

	key.clear();

	return 0;
}