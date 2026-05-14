#include <iostream>
using namespace std;

int sum(int arr[], int size) {
	if (size == 0) {
		return 0;
	}
	return size - 1 + sum(arr, size - 1);
}
int main() {
	int arr[5] = { 1 ,2, 3, 4, 5 };

	int result = sum(arr, 5);
	cout << result << endl;
	return 0;
}