#include <iostream>
#include <unordered_map>
#include <sstream>  //getline()
using namespace std;

unordered_map<char, char> key;

string checkValid(string cypher) {
	for (int i = 0; i < cypher.length(); i++) {	
		if (key.find(cypher[i]) != key.end()) { // finds repeat value
			cout << "Repeated value found." << endl;
			cout << "Clearing the key." << endl;
			key.clear();
			return "Key must not contain repeated values.";
		}

		else if (key.find(cypher[i]) == key.end()) { // not a repeat
				if (isalpha(cypher[i]) == false) { // checks if a letter
					cout << "Key must contain only letters" << endl;
					return "invalid";
				}
				else {
					key[(char)toupper(cypher[i])] = (char)65+i; //ascii code
					cout << "Cypher for " << (char)(65 + i)  << " = " << (char)toupper(cypher[i]) << endl;

					key[(char)tolower(cypher[i])] = (char)97 + i;
					cout << "Cypher for " << (char)(97 + i) << " = " << (char)tolower(cypher[i]) << endl;
				}
			}
		
	}

	if (key.size() == 26 * 2) {
		cout << "Valid key" << endl;
		return "valid";
	}
	else if (key.size() != 26 * 2) {
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

	cout << "Cypher: " << endl;  // checking cypher
	for (itr = key.begin(); itr != key.end(); itr++) {
		cout << itr->first << " " << itr->second << endl;
	}




	key.clear();

	return 0;
}