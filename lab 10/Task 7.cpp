#include <iostream>
using namespace std;

bool subsetsum(int arr[], int n, int index, int target) {
    if (target == 0)
        return true;

    if (index == n || target < 0)
        return false;

    if (subsetsum(arr, n, index + 1, target - arr[index]))
        return true;

    return subsetsum(arr, n, index + 1, target);
}

int findmax(int arr[], int n, int index, int best) {
    if (index == n)
        return best;

    if (arr[index] > best)
        best = arr[index];

    return findmax(arr, n, index + 1, best);
}

void removevalue(int arr[], int n, int value, int index, int newarr[], int& newn) {
    if (index == n)
        return;

    if (arr[index] != value) {
        newarr[newn] = arr[index];
        newn++;
    }

    removevalue(arr, n, value, index + 1, newarr, newn);
}

int magicnumber(int arr[], int n) {
    if (n == 0)
        return -1;

    int maxval = findmax(arr, n, 0, arr[0]);

    int temp[1000];
    int newn = 0;

    removevalue(arr, n, maxval, 0, temp, newn);

    if (subsetsum(temp, newn, 0, maxval))
        return maxval;

    return magicnumber(temp, newn);
}

int main() {
    int arr[] = { 2, 3, 5, 8, 13 };
    int n = 5;

    cout << magicnumber(arr, n) << endl;

    return 0;
}