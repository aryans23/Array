#include <iostream> 
using namespace std;

void init(int *arr, int n) {
	int val;
	while(n--) {
		cin >> val;
		if(val != 0 && val != 1) {
			cout << "Enter ONLY 0 or 1" << endl;
			n++;
			continue;
		}
		*arr = val;
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

int *seg(int *arr, int n) {
	int *start = arr;
	int *end = &arr[n-1];

	while(start < end) {
		if(*start == 0) {
			start++;
			continue;
		}

		else {	// start = 1
			*start++ = 0;
			while(*end == 1) {
				end--;
			}
			*end = 1;
		}
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

	arr = seg(arr, n);
	printArr(arr, n);

	return 0;
}
