//Best case: O(n), when the array is sorted or nearly sorted
//Worst case: O(n^2)
//Average case: O(n^2)
//Space: O(1)

//Sorting In Place: Yes
//Insertion sort is used when number of elements is small.
//It can also be useful when input array is almost sorted, only few elements are misplaced in complete big array.

#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {64, 34, 25, 12, 22, 11, 90};  
    int n = sizeof(arr)/sizeof(arr[0]);
    int current, i, j;
    
    for(i = 1; i < n; i++){
        current = arr[i];
        for(j = i-1; j >= 0; j--)
            if(arr[j] > current) arr[j+1] = arr[j]; //shift the greater elements to the right till a value less than current is found
            else break;
            
        arr[j+1] = current;
	//when the inner loop breaks j is decremented one extra time by one, hence we take j plus 1 here
	//placing the current value correctly
    }
    
    for(int i : arr) cout<<i<<" ";
}
