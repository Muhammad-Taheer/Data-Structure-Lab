#include <iostream>
#include <string>
using namespace std;

bool palindrome(string str, int left, int right) {
	if (left >= right) {
		return true;
	}
	if (str[left] != str[right]) {
		return false;
	}
	return palindrome(str, left + 1, right - 1);
}

int main() {
	string str;

	cout << "Enter a string " << endl;
	cin >> str;

	if (palindrome(str, 0, str.length() - 1)){

		cout << str << " is palindrome" << endl;
	}
	else {
		cout << str << " is not palindrome" << endl;
	}
}