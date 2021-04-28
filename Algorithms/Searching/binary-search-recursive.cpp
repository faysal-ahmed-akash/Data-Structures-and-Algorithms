#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int left, int right, int key){
    
    if(left > right) return -1;
    
    int mid = left + ((right - left) / 2);
    //cout<<left<<" "<<mid<<" "<<right<<endl;
    
    if(arr[mid] == key) return mid;
    else if(arr[mid] < key) return binarySearch(arr, mid + 1, right, key);
    else return binarySearch(arr, left, mid - 1, key);
}

int main(){
    int arr[] = { 1, 5, 6, 7, 10, 11, 12, 13, 20, 25, 33, 40 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 7;
    
    int found = binarySearch(arr, 0, n - 1, key);
    
    if(found != -1) cout<<"Found at index "<<found<<endl;
    else cout<<"Not found"<<endl;
}
