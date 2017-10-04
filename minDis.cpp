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

int findDis(int *a, int n, int x, int y) {
	int prev, i, min_dis = INT_MAX;

	for(i = 0; i < n; i++) {
		if(a[i] == x || a[i] == y) {
			prev = i;
			break;
		}
	}

	if(i == n) {
		return -1;
	}

	for(i = i+1; i < n; i++) {
		if(a[i] == x || a[i] == y) {
		   if(a[i] != a[prev]) {
		      if(min_dis > i - prev) {
	   		     min_dis = i - prev;
   			  }
		   }
		   prev = i;
		}
	}
	return min_dis;	
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
	
	cout << "Enter x: ";
	cin >> x;
	cout << "Enter y: ";
	cin >> y;

	int res = findDis(arr, n, x, y);

	if(res == -1) {
		cout << "Numbers don't exist" << endl;
	}
	else {
		cout << "Minimum distance: " << res << endl;
	}
}
