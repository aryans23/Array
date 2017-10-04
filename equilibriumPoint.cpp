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

int findEqui(int *arr, int n) {
	int sum = getSum(arr, n);
	int left = 0;
	int right = 0;

	for (int i = 0; i < n; ++i)
	{
		right = sum - left - arr[i];
		if (left + right == 0)
		{
			return arr[i];
		}
		left += arr[i];
	}
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

	int res = findEqui(arr, n);

	if(res != -1) {
		cout << "Equilibrium Point: " << res << endl;
	}
	else {
		cout << "No Equilibrium Point" << endl;
	}
}
