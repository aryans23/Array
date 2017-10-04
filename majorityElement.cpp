#include <iostream> 
using namespace std;

void init(int *arr, int n) {
	while(n--) {
		cin >> *arr;
		arr++;
	}
}

void printArr(int *arr, int n) {
	for(int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void findMajorityEle(int *arr, int n) {
	int major = arr[0];
	int count = 1;

	for(int i = 1; i < n; i++) {
		if(arr[i] == major) {
			count ++;
		}

		else {
			count--;
		}

		if(count == 0) {
			major = arr[i];
			count = 1;
		}
	}

	count = 0;

	for(int i = 0; i < n; i++) {
		if(arr[i] == major) {
			count++;
		}
	}

	if(count > n/2) {
		cout << "Majority Element: " << major << endl;
	}

	else {
		cout << "No Major Element present" << endl;
	}
}

int main() {
	cout << "Enter number of elements in the array" << endl;
	int n;
	cin >> n;
	int *arr = new int(n);

	cout << "Enter the elements of the array" << endl;	
	init(arr, n);
	cout << "Array: ";
	printArr(arr, n);

	findMajorityEle(arr, n);
}
