#include <iostream>
using namespace std;

int findmax(int arr[] , int size) {
	if (size == 1) {
		return arr[0];
	}
	int max = findmax(arr, size - 1);

	if (arr[size - 1] > max) {
		return arr[size - 1];
	}
	else {
		return max;
	}
}

int main() {
	int arr[5] = { 1, 2, 3, 4, 5 };

	int result = findmax(arr, 5);

	cout << result; 
}