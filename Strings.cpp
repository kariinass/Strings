#include <iostream>
#include <cstdlib>
#include <ctime>  
#include <string>
using namespace std;

int countUpper(string s) {
	int prop = 0;
	for (auto c : s) {
		if (c >= 'A' && c <= 'Z') {
			prop++;
		}
	}
	cout << "Uppercase letters: " << prop << endl;
	return 0;
}

int countLower(string s) {
	int stroch = 0;
	for (auto c : s) {
		if (c >= 'a' && c <= 'z') {
			stroch++;
		}
	}
	cout << "Lowercase letters: " << stroch << endl;
	countUpper(s);
	return 0;
}

int countWords(string s) {
	int count = 0;
	int flag = 1;
	for (auto c : s) {
		if (c != ' ' && flag == 1) {
			count++;
			flag = 0;
		}
		else if (flag != 1 && c == ' ') {
			flag = 1;
		}
	}
	cout << "Words in line: " << count << endl;
	return 0;
}

int generateWord(string s) {
	string w;
	int ls, lw;
	ls = s.size();
	int j;
	int let = 0;
	srand(time(NULL));
	for (int i = 0; i < 5; i++) {
		w = "";
		j = 0;
		lw = rand() % 6 + 2; //random word length from 2 to 7
		while (j < lw) {
			let = rand() % ls; //random index of a letter from the entered string
			if (s[let] != ' ') {
				w += s[let];
			}
			j++;
		}
		cout << w << endl;
	}
	return 0;
}

int removeDuplicates(const string& s4) {
	string w2;
	for (char c : s4) {
		if (c != ' ' && w2.find(c) == string::npos) {
			w2 += c;
		}
	}
	cout << w2 << endl;
	return 0;
}

int maximumLength(int n) {

	int flag = 1;
	char** strings = nullptr;
	int maxLength = 0;
	int count = 0;
	// Reading strings and writing to a dynamic array strings
	for (int i = 0; i <= n; i++) {
		string s5;
		getline(cin, s5);
		char* newString = new char[s5.length() + 1]; 
		strcpy_s(newString = new char[s5.length() + 1], s5.length() + 1, s5.c_str()); // the string s5 is copied to the array
		if (s5.length() > maxLength) {
			maxLength = s5.length();
		}
		++count;

		char** temp = new char* [count];
		copy(strings, strings + count - 1, temp);  // writing the string to the temp 
		temp[count - 1] = newString;
		delete[] strings;
		strings = temp;
	}
	// Search for and output the longest strings
	cout << "The longest string(s) is(are) at index:";
	for (int i = 0; i < count; i++) {
		if (strlen(strings[i]) == maxLength) {
			cout << " " << i - 1;
		}
	}
	cout << endl;
	// Freeing up allocated memory
	for (int i = 0; i < count; ++i) {
		delete[] strings[i];
	}
	delete[] strings;
	return 0;
}

string deleteSpaces(string f){
	int i = 0;
	while (i < f.length()) {
		if (f[i] == ' ') {
			f.erase(i, 1);
		}
		else {
			i++;
		}
	}
	cout << f << endl;
	return f;
}

int isPalindrom(string f) {
	int count = 0;
	for (int i = 0; i < f.length() / 2; i++) {
		if (f[i] == f[f.length()-i-1]) {
			count++;
		}
	}
	if (count * 2 == f.length()) {
		cout << "This string is a palindrome" << endl; 
	}
	else {
		cout << "This string is not a palindrome" << endl;
	}
	return 0;
}

string stringReplacer(const string& inputStr, const string& src, const string& dst)
{
	string result(inputStr);      // result string initialized with the inputStr value
	size_t pos = result.find(src);// initialized by the index of the first element of the src substring in the result 
	while (pos != string::npos) { // it will be executed as long as the entries of the src substring in the result string are found
		result.replace(pos, src.size(), dst); // replaces the src substring in the result string, starting from the pos position, with dst  (size()=length())
		pos = result.find(src, pos); // returns the next entry of the substring, starting with pos
	}
	return result;
}

int longestWord(const string& inpStr) {

	int maxWordLength = 0;
	int maxWordStartIndex = 0;
	int currentWordLength = 0;
	int currentWordStartIndex = 0;

	for (int i = 0; i < inpStr.length(); i++) {
		if (inpStr[i] != ' ') {
			currentWordLength++;
		}
		else {
			if (currentWordLength > maxWordLength) {
				maxWordLength = currentWordLength;
				maxWordStartIndex = currentWordStartIndex;
			}
			currentWordLength = 0;
			currentWordStartIndex = i + 1;
		}
	}

	if (currentWordLength > maxWordLength) {
		maxWordLength = currentWordLength;
		maxWordStartIndex = currentWordStartIndex;
	}
	cout << inpStr.substr(maxWordStartIndex, maxWordLength) << endl;
	return 0;
}

int main() {

	/*Task 1*/
	cout << "Task 1 " << endl;
	string s1;
	cout << "Input line: ";
	getline(cin, s1);
	countLower(s1);

	/*Task 2*/
	cout << "Task 2 " << endl;
	string s2;
	cout << "Input line: ";
	getline(cin, s2);
	countWords(s2);


	/*Task 3*/
	cout << "Task 3 " << endl;
	string s;
	cout << "Input line: ";
	getline(cin, s);
	generateWord(s);
	

	/*Task 4*/
	cout << "Task 4 " << endl;
	string s4;
	cout << "Input line: ";
	getline(cin, s4);
	removeDuplicates(s4);
	

	/*Task 5*/
	cout << "Task 5" << endl;
	int n;
	cout << "Input the number of lines" << endl;
	cin >> n;
	maximumLength(n);	

	/*Task 6*/
	cout << "Task 6" << endl;
	string f;
	cout << "Input the line" << endl;
	getline(cin, f);
	isPalindrom(deleteSpaces(f));


	/*Task 7*/
	cout << "Task 7" << endl;
	string inputStr, src, dst;
	cout << "Input 3 lines" << endl;
	getline(cin, inputStr);
	getline(cin, src);
	getline(cin, dst);
	cout << stringReplacer(inputStr, src, dst) << endl;


	/*Task 8*/
	cout << "Task 8" << endl;
	string inpStr;
	cout << "Input the line" << endl;
	getline(cin, inpStr);
	longestWord(inpStr);

	return 0;
}