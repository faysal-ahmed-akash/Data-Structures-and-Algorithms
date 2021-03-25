//https://www.youtube.com/watch?v=cAv-4ltj1go&list=PLIY8eNdw5tW_zX3OCzX7NJ8bL1p6pWfgG&index=32
//https://www.youtube.com/watch?v=alJswNJ4P3U
//time: O(nlogn)
//space: O(n)

#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int m, int r, int size){
    int i = l;
    int j = m + 1;
    int k = l;
 
    int b[size];
 
    while(i <= m && j <= r){
        if (arr[i] <= arr[j]){
            b[k] = arr[i];
            i++;
        }else{
            b[k] = arr[j];
            j++;
        }
        k++;
    }
    
    while(i <= m){
        b[k] = arr[i];
        i++;
        k++;
    }
    
    while(j <= r){
        b[k] = arr[j];
        j++;
        k++;
    }
 
    for(int x = l; x <= r; x++){
        arr[x] = b[x];
    }
}
 
void mergeSort(int arr[], int l, int r, int size){
    if(l < r) {
        int m = (l + r) / 2;

        mergeSort(arr, l, m, size);
        mergeSort(arr, m + 1, r, size);
        merge(arr, l, m, r, size);
    }
}
 
int main(){
    int inputArr[] = {10, 5, 0, 8, 1, 6};
    int size = sizeof(inputArr) / sizeof(inputArr[0]);
    
    mergeSort(inputArr, 0, size - 1, size);
    //arrays are passed by address (https://stackoverflow.com/questions/24057085/is-c-array-passed-by-reference-or-by-pointer)
    //hence passing the input array to the function as arr, changing arr will effect inputArr as array cannot be passed by value
 
    for(int i : inputArr) cout<<i<<" ";
    
    return 0;
}