/* ***************** NOT COMPLETE (BUG) ******************** */
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

int findMissing(int *a, int n) {
	int start = 0;
	int end = n-1;
	int mid = n/2;

	while(start <= end) {	
		if(a[start] != start) {
			return start;
		}

		if(a[mid] < mid) {
			cout << "Some error in input" << endl;
			return -1; 
		}

		else if(a[mid] == mid) {
			start = mid;
			continue;
		}

		else {
			end = mid;
			continue;
		}
	}		
	cout << "No missing element in the range 0 to " << n << endl;
	return -1;
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

	int res = findMissing(arr, n);

	if(res == -1) {
		cout << "" << endl;
	}
	else {
		cout << "Missing element: " << res << endl;
	}
}
