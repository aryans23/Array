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

void findSubArr(int *a, int n, int &left, int &right) {
	int _sum = 0;
	for(int i = 0; i < n; i++) {
		if(a[i] == 1) {
			_sum++;
		}
		else {
			_sum--;
		}
	}

	if(_sum == 0) {
		return;
	}

	while(left < right) {
		if(_sum > 0) {		// need to remove 1s
			if(a[left] == 1 && a[right] == 1) {
				left++;
				right--;
				_sum -= 2;
				if(_sum == 0) {
					return;
				}
			}
			else if(a[left] == 1) {
				left++;
				_sum--;
				if(_sum == 0) {
					return;
				}
			}
			else {
				right--;
				_sum--;
				if(_sum == 0) {
					return;
				}
			}
		}
		if(_sum < 0) {		// need to remove 0s
			if(a[left] == 0 && a[right] == 0) {
				left++;
				right--;
				_sum += 2;
				if(_sum == 0) {
					return;
				}
			}
			else if(a[left] == 0) {
				left++;
				_sum++;
				if(_sum == 0) {
					return;
				}
			}
			else {
				right--;
				_sum++;
				if(_sum == 0) {
					return;
				}
			}
		}
	}
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

	int left = 0;
	int right = n-1;

	findSubArr(arr, n, left, right);

	if(left < right) {
		cout << "Subarray is from " << left << " to " << right << endl;
	}
	else {
		cout << "No subarray" << endl;
	}
}
