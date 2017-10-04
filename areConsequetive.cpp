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

int getSum(int *arr, int n) {
	int sum = 0;
	for(int i = 0; i < n; i++) {
		sum += arr[i];
	}
	return sum;
}

bool areConse(int *a, int n) {
	int sum = 0;
	int min = a[0];
	
	for(int i = 0; i < n; i++) {
		if(min > a[i]) {
			min = a[i];
		}

		sum += a[i];
	}

	int sum_progression = (n * min) + (n * (n-1)/2);

	return sum == sum_progression;
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

	bool res = areConse(arr, n);

	if(res) {
		cout << "The numbers are consequetive" << endl;
	}
	else {
		cout << "The numbers are NOT consequetive" << endl;
	}
}
