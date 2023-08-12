// Floor of an element x is the largest element <= x
// Ceil of an element x is the smallest element >= x

#include<bits/stdc++.h>
using namespace std;

// ---------------------------- Method 1(My logic) ---------------------------
int findFloor(int arr[], int n, int x){
	if(x<arr[0]){
		return -1;
	}
	int s=0, e=n-1;
	while(s<=e){
		int mid = s+(e-s)/2;
		if(arr[mid]==x){
			return arr[mid];
		}
		else if(arr[mid]<x){
			s = mid+1;
		}
		else{
			e = mid-1;
		}
	}

	return arr[e];
}


int findCeil(int arr[], int n, int x){
	if(x>arr[n-1]){
		return -1;
	}
	int s=0, e=n-1;
	while(s<=e){
		int mid = s+(e-s)/2;
		if(arr[mid]==x){
			return arr[mid];
		}
		else if(arr[mid]<x){
			s = mid+1;
		}
		else{
			e = mid-1;
		}
	}

	return arr[s];
}

// -------------------------------- Method 2(Striver's method) ---------------------------

int findFloor(int arr[], int n, int x){
	int ans = -1;
	int s=0, e=n-1;
	while(s<=e){
		int mid = s+(e-s)/2;
		if(arr[mid]<=x){
			ans = arr[mid]; // potential ans
            s = mid+1; // look for some larger element<=x on the right
		}
		else{
			e = mid-1;
		}
	}

	return ans;
}

int findCeil(int arr[], int n, int x){
	int ans = -1;
	int s=0, e=n-1;
	while(s<=e){
		int mid = s+(e-s)/2;
		if(arr[mid]>=x){
			ans = arr[mid]; // potential ans
            e = mid-1; // look for some smaller element<=x on the left
		}
		else{
			s = mid+1;
		}
	}

	return ans;
}

pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
	sort(arr, arr+n);
	int floor = findFloor(arr, n, x);
	int ceil = findCeil(arr, n, x);
	return {floor, ceil};
}

int main()
{
    return 0;
}
