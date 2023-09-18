// PROBLEM:
// Given an array arr of integer numbers, where arr[i] represents the number of pages in the ‘i-th’ book. 
// There are ‘m’ number of students, and the task is to allocate all the books to the students.
// Allocate books in such a way that:
// 1. Each student gets at least one book.
// 2. Each book should be allocated to only one student.
// 3. Book allocation should be in a contiguous manner.
// You have to allocate the book to ‘m’ students such that the maximum number of pages assigned to a 
// student is minimum. If the allocation of books is not possible, return -1.

#include<bits/stdc++.h>
using namespace std;

int reqStudents(vector<int>& arr, int n, int mid){
    // here mid is the max permissible no. of pages that
    // can be assigned to a student
    int count=1;
    long long currPages=0;
    for(int i=0; i<n; i++){
        if(currPages+arr[i]>mid){
            count++;
            currPages=arr[i];
        }
        else{
            currPages+=arr[i];
        }
    }
    return count;
}

int findPages(vector<int>& arr, int n, int m) {
    // Write your code here.
    if(m>n){
        return -1;
    }

    int totalPages = accumulate(arr.begin(), arr.end(), 0);
    int maxi= *max_element(arr.begin(), arr.end());

    int s = maxi; 
    // min no. of pages reqd so that each book can be assigned
    // must be equal to the no. of pages in book with max pages
    int e = totalPages;

    while(s<=e){
        int mid = (s+e)/2; 

        // check if we can assign all books to exactly m students with 
        // max permissible no. of pages assigned to each student = mid
        int req = reqStudents(arr, n, mid);

        if(req>m){
            // it means we need more no. of students for curr value of mid
            // so, we need to increase the max permissible value of pages so 
            // that it can be alloted to exactly m students
            // at mid = totalPages, we have only 1 student
            // at mid = maxi, we have >m students
            // Hence, for maxi <mid < totalPages, we can get exactly m students
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }

    return s;
}

int main()
{
    return 0;
}