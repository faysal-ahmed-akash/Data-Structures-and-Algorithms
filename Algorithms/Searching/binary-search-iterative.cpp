#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int left, int right, int key){
    
    while(left <= right){
        int mid = left + ((right - left) / 2);
        
        if(arr[mid] == key) return mid;
        else if(arr[mid] < key) left = mid + 1;
        else right = mid - 1;
    }
    
    return -1;
}

int main(){
    int arr[] = { 1, 5, 6, 7, 10, 11, 12, 13, 20, 25, 33, 40 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 40;
    
    int found = binarySearch(arr, 0, n - 1, key);
    
    if(found != -1) cout<<"Found at index "<<found<<endl;
    else cout<<"Not found"<<endl;
}
