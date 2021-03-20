//Best case: O(n), when the array is already sorted, this is for optimized bubble sort (when we use flag to keep track of swapping)
//Best case: O(n^2), for raw bubble sort
//Worst case: O(n^2), when the array is reverse sorted
//Average case: O(n^2)
//Space: O(1), as it's an in place algorithm

#include <bits/stdc++.h>

using namespace std;

int main(){
    int arr[] = {64, 34, 25, 12, 22, 11, 90};  
    int n = sizeof(arr) / sizeof(arr[0]);
    
    bool flag;
    
    for(int i = 0; i < n-1; i++){
        flag = false;
        for(int j = 0; j < n-i-1; j++){
	//at every pass the largest element placed correctly at the last.
        //so we don't have to loop for that element. That's why we subtract i
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                flag = true;
            }
        }
        
        if(!flag) break; // if no swap occurs, the array is sorted
    }
    
    for(int i : arr) cout<<i<<" ";
}
