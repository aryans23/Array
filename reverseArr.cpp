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

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int *reverse(int *arr, int n) {
	if(n==0 || n==1) {
		return arr;
	}

	int *start = &arr[0];
	int *end = &arr[n-1];

	while(start < end) {
		swap(start, end);
		start++;
		end--;
	}

	return arr;
}

int main() {
	cout << "Enter number of elements in the array" << endl;
	int n;
	cin >> n;
	int *arr = new int(n);

	cout << "Enter the elements of the array" << endl;	
	init(arr, n);
	printArr(arr, n);

	arr = reverse(arr, n);
	printArr(arr, n);

	return 0;
}
