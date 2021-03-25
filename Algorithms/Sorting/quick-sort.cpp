//https://www.youtube.com/watch?v=yEzFMbc7ltQ
//worst: O(n^2)
//best and avg: O(nlogn)
//space: O(nlogn)

#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int start, int end){
    int pivot = arr[end];
    int pivotIdx = start;
    int temp;
    
    for(int i = start; i < end; i++){
        if(arr[i] < pivot){
            temp = arr[pivotIdx];
            arr[pivotIdx] = arr[i];
            arr[i] = temp;
            pivotIdx++;
        }
    }
    
    temp = arr[pivotIdx];
    arr[pivotIdx] = arr[end];
    arr[end] = temp;
    
    return pivotIdx;
}

void quickSort(int arr[], int start, int end){
    
    if(start < end){
        int p = partition(arr, start, end);
        
        quickSort(arr, start, p - 1);
        quickSort(arr, p + 1, end);   
    }
}

int main(){
    int arr[] = {3, 10, 5, 1, 6, 2, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    quickSort(arr, 0, size - 1);
    
    for(int i : arr) cout<<i<<" ";
}