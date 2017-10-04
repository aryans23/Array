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

void subArr(int *a, int n, int& left, int& right, int subSum) {
	 int sum = 0;
	 for(int i = 0; i < n; i++) {
		 sum += a[i];
	 }

	 if(sum == subSum) {
		 return;
	 }
	
	 while(left < right) {
		 if(sum - a[left] - a[right] >= subSum) {
			 sum -= a[left] + a[right];
			 left++;
			 right--;
			 if(sum == subSum) {
				 return;
			 }
			 continue;
		 }

		 else if(sum-a[left] >= subSum) {
			 sum -= a[left];
			 left++;
			 if(sum == subSum) {
			 	return;
			 }
			 continue;
		 }

		 else if(sum-a[right] >= subSum) {
			 sum -= a[right];
			 right--;
			 if(sum == subSum) {
			 	return;
			 }
			 continue;
		 }	 

		 left = right+1;	// to break the loop
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
	int subSum = 0;

	cout << "Enter Subarray sum: ";
	cin >> subSum;

	subArr(arr, n, left, right, subSum);

	if(left <= right) {
		cout << "Subarray is from " << left << " to " << right << endl;
	}
	else {
		cout << "No subarray" << endl;
	}
}
