// ************************* QUICK SORT **************************

// This sorting algorithm is based on Divide and Conquer Technique
// Each time, we choose a element in the array as pivot(first, last, middle, or any random element)
// and place it at its correct place(as in sorted array)
// i.e. Elements on the left of the pivot must be <= pivot element and elements on the right must be > pivot element
// Then we divide the array about the pivot and then again apply the same logic on the two parts of array 
// continue till whole array gets sorted.


#include<bits/stdc++.h>
using namespace std;

void quickSort(int arr[], int low, int high)
{
    if(low<high){
        int partitionIdx = partition(arr, low, high);
        quickSort(arr, low, partitionIdx-1);
        quickSort(arr, partitionIdx+1, high);
    }
}

int partition (int arr[], int low, int high)
{
    // this function places the pivot at its correct place and returns its correct position(index)
    int pivot = arr[low]; // choose the pivot
    int i=low, j=high;
    
    while(i<j){
        while(i<=high-1 && arr[i]<=pivot) i++; // find the first element>pivot from left end
        // NOTE: Here we have equality in the condition arr[i]<=pivot as we can place an element equal to pivot
        // either on the left side or on the right side of partition. Here we are placing everything <=pivot on LHS 
        // && >pivot on RHS
        while(j>=low+1 && arr[j]>pivot) j--; // find the first element <= pivot from right end
        
        if(i<j){
            swap(arr[i], arr[j]);
        }
    }
    
    // when j crosses i(j>i)
    swap(arr[low], arr[j]); // here j is the correct position of pivot in sorted array so bring it back to its jth index
    return j;
}

int main()
{
    return 0;
}