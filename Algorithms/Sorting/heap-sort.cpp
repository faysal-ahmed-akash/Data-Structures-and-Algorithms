#include <bits/stdc++.h>
using namespace std;

void heapify(int arr[], int heap_size, int i){
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest = i;

    if(l < heap_size && arr[l] > arr[i])
        largest = l;
    if(r < heap_size && arr[r] > arr[largest])
        largest = r;
        
    if(largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr, heap_size, largest);
    }
}

void heapSort(int arr[], int n){
    //Build heap
    for(int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);
    
    for(int i = n - 1; i > 0; i--){
        //move current root to the end
        swap(arr[0], arr[i]);
        
        heapify(arr, i, 0);
    }
}

int main(){
    int arr[] = { 12, 11, 13, 5, 6, 7, 1, 10 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    heapSort(arr, n);
    
    //print the heap
    for(int i = 0; i < n; i++) cout<<arr[i]<<" ";
}