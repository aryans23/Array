#include <iostream> 
using namespace std;

void init(int *arr, int n) {
	while(n--) {
		cin >> *arr;
		arr++;
	}
}

void printArr(int *arr, int n) {
	cout << "Array: ";
	for(int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

inline int max(int a, int b) {
	return (a>b) ? a:b;
}

int getMaxSumNoAdj(int *arr, int n) {
	int inc = arr[0],	// Inclusive of curr element 
		exc = 0,		// Exclusive of curr element
		temp;

	for(int i = 1; i < n; i++) {
		temp = max(inc, exc);
		inc = arr[i] + exc;
		exc = temp;
	}

	return max(inc, exc);
}
	
int main() {
	cout << "Enter number of elements in the array" << endl;
	int n;
	cin >> n;
	int *arr = new int(n);

	cout << "Enter the elements of the array" << endl;	
	init(arr, n);
	printArr(arr, n);

	cout << "Max Sum: " << getMaxSumNoAdj(arr, n) << endl;

	return 0;
}
