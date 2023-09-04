// Problem statement: Given two sorted arrays arr1[] and arr2[] of sizes n and m in non-decreasing order. 
// Merge them in sorted order. 
// Modify arr1 so that it contains the first N elements and modify arr2 so that it contains the last M elements.

#include<bits/stdc++.h>

using namespace std;

// ------------------------------ M1: Using Insertion Sort ---------------------------
void merge1(int arr1[], int arr2[], int n, int m) {
  // code here

  for (int i = 0; i < n; i++) {
    // take first element from arr1 
    // compare it with first element of second array
    // if condition match, then swap
    if (arr1[i] > arr2[0]) {
      int temp = arr1[i];
      arr1[i] = arr2[0];
      arr2[0] = temp;
    }

    // then sort the second array
    // put the element in its correct position
    // so that next cycle can swap elements correctly
    // insertion sort is used here
    int first = arr2[0];
    int k;
    for(k=1; k<m; k++){
      if(arr2[k]<first){
        arr2[k-1] = arr2[k];
      }
      else{
        break;
      }
    }
    // int k=1;
    // while(k<m && arr2[k]<first){
    //   arr2[k-1]=arr2[k];
    //   k++;
    // }
    arr2[k - 1] = first;
  }
}


// ------------------------ M2: Using Gap Method(Shell Sort) -----------------------------------

void merge2(int ar1[], int ar2[], int n, int m) {

  int len = n+m;
  int gap = ceil((float)(len) / 2); 
  // ceil can be also calculated as (len/2 + len%2) hence, no need to add float for decimal value of (n+m)/2
  while (gap > 0) {
    int i = 0;
    int j = gap;  
    while (j < len) {
      if (j < n && ar1[i] > ar1[j]) {
        // Both i and j lie in arr1
        swap(ar1[i], ar1[j]);
      } 
      else if (j >= n && i < n && ar1[i] > ar2[j - n]) {
        // i lies in arr1 and j lies in arr2
        swap(ar1[i], ar2[j - n]);
      } 
      else if (j >= n && i >= n && ar2[i - n] > ar2[j - n]) {
        // Both i and j lie in arr2
        swap(ar2[i - n], ar2[j - n]);
      }
      i++;
      j++;
    }
    if (gap == 1) {
        break;
    } 
    else {
      gap = ceil((float) gap / 2);
    }
  }
}


int main() {
  int arr1[] = {1,4,7,8,10};
  int arr2[] = {2,3,9};
  cout << "Before merge:" << endl;
  for (int i = 0; i < 5; i++) {
    cout << arr1[i] << " ";
  }
  cout << endl;
  for (int i = 0; i < 3; i++) {
    cout << arr2[i] << " ";
  }
  cout << endl;
  merge1(arr1, arr2, 5, 3);
  cout << "After merge:" << endl;
  for (int i = 0; i < 5; i++) {
    cout << arr1[i] << " ";
  }
  cout << endl;
  for (int i = 0; i < 3; i++) {
    cout << arr2[i] << " ";
  }

}