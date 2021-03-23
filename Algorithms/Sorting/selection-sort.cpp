//Best case: O(n^2)
//Worst case: O(n^2)
//Average case: O(n^2)
//Space: O(1)
//The good thing about selection sort is it never makes more than O(n) swaps and can be useful when memory write is a costly operation.
//because it is an in-place sorting algorithm, no additional temporary storage is required beyond what is needed to hold the original list.
//an in-place algorithm is an algorithm which transforms input using no auxiliary data structure.
//More broadly, in-place means that the algorithm does not use extra space for manipulating the input but 
//may require a small though nonconstant extra space for its operation.
//among the algorithms it makes the minimum number of swaps

#include <bits/stdc++.h>

using namespace std;

int main(){
    int arr[] = {64, 34, 25, 12, 22, 11, 90};  
    int n = sizeof(arr)/sizeof(arr[0]);
    int min_idx;
    
    for(int i = 0; i < n-1; i++){
        min_idx = i;
        for(int j = i+1; j < n; j++){
            if(arr[j] < arr[min_idx]){
                min_idx = j;
            }
        }
        
        swap(arr[i], arr[min_idx]);
    }
    
    for(int i : arr) cout<<i<<" ";
}
