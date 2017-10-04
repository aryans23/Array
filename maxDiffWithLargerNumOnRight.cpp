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

int maxDiff(int *a, int n) {
	if(n == 1 || n == 0) {
		return INT_MAX;
	}

	int min = a[0];
	int max_diff = a[1] - a[0];

	for(int i = 1; i < n; i++) {
		if(a[i] - min > max_diff) {
			max_diff = a[i] - min;
		}
		if(a[i] < min) {
			min = a[i];
		}
	}

	if(max_diff >= 0) {
		return max_diff;
	}
	else {
		return INT_MIN;
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
	
	int res = maxDiff(arr, n);
	if(res == INT_MAX) {
		cout << "Error: Too few Elements" << endl;
		return 1;
	}
	if(res == INT_MIN) {
		cout << "No larger element on the right of a smaller element" << endl;
		return 1;
	}
	cout << "Max Diff: " << maxDiff(arr,n) << endl;
	return 0;
}
