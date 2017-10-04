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

int isBitonic(int *a, int n) {
	int start = 0;
	int count = 1;

	if(n == 0 || n == 1) {
		return n;
	}

	for(int i = 1; i < n; i++) {
		if(a[i] <= a[i-1]) {
			if(i + 1 == n) {
				count++;
			}
			else if(a[i+1] > a[i]) {
				count = 1;
				start = i;
			}
			else {
				count++;
			}
			continue;
		}
		else if(a[i] >= a[i-1]) {
			count++;
			continue;
		}
	}
	return count;
}

int main() {
	cout << "Enter number of elements in the array: ";
	int n,x,y;
	cin >> n;
	int *arr = new int(n);

	cout << "Enter the elements of the array" << endl;	
	init(arr, n);
	cout << "Array: ";
	printArr(arr, n);
	
	int res = isBitonic(arr, n);

	cout << "Length of max bitonic: " << res << endl;
}
