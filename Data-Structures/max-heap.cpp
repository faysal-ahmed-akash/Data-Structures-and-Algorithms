#include <bits/stdc++.h>
using namespace std;

class MaxHeap{
    public:
        int heap_size;
        int *heap;
        int capacity;
    
        MaxHeap(int x); 
        int parent(int i) {return (i - 1) / 2;}
        int left(int i) {return 2 * i + 1;}
        int right(int i) {return 2 * i + 2;}
        void insertKey(int x);
        void deleteKey(int i);
        void increaseKey(int i, int new_val);
        void decreaseKey(int i, int new_val);
        void maxHeapify(int i);
        int extractMax();
};

void swap(int *x, int *y){ 
    int temp = *x; 
    *x = *y; 
    *y = temp; 
}

MaxHeap::MaxHeap(int x){ 
    heap_size = 0; 
    capacity = x; 
    heap = new int[x]; 
} 

void MaxHeap::insertKey(int x){
    if(heap_size == capacity) cout<<"Overflow!"<<endl;
    else{
        heap[heap_size] = x;
        int i = heap_size;
        heap_size++;
        
        while(i != 0 && heap[parent(i)] < heap[i]){
            swap(&heap[parent(i)], &heap[i]); //passing as pointer so that original array gets changed
            i = parent(i);
        }
    }
}

void MaxHeap::decreaseKey(int i, int new_val){
    heap[i] = new_val;
    maxHeapify(i); //traverse down
}

void MaxHeap::increaseKey(int i, int new_val){
    heap[i] = new_val;
    while (i != 0 && heap[parent(i)] < heap[i]){ //traverse up
       swap(&heap[i], &heap[parent(i)]);
       i = parent(i);
    }
}

void MaxHeap::deleteKey(int i){ 
    increaseKey(i, INT_MAX); //this value will be root
    extractMax(); //extract the root
}

void MaxHeap::maxHeapify(int i){
    int l = left(i);
    int r = right(i);
    int largest = i;
    
    //we need to check if i is a leaf node or not
    //if i is leaf node then l and r will be greater than heap size
    if(l < heap_size && heap[l] > heap[i])
        largest = l; //l is the largest
    if(r < heap_size && heap[r] > heap[largest])
        largest = r; //r is the largest
        
    if(largest != i){ //if i is not the largest then replace i with the largest else i is the largest no need to heapify
        swap(&heap[i], &heap[largest]);
        maxHeapify(largest); //traversing down to check for largest value
    }
}

int MaxHeap::extractMax(){
    if(heap_size <= 0) return INT_MIN;
    else if(heap_size == 1){
        heap_size--;
        return heap[0];
    }
    
    int root = heap[0];
    heap[0] = heap[heap_size - 1];
    heap_size--;
    maxHeapify(0);
    
    return root;
}

int main(){
    MaxHeap h(10);
    
    h.insertKey(3); 
    h.insertKey(2);
    h.insertKey(15); 
    h.insertKey(5); 
    h.insertKey(10);
    h.insertKey(20);
    h.insertKey(1);
    h.extractMax();
    
    //print the heap
    for(int i = 0; i < h.heap_size; i++) cout<<h.heap[i]<<" ";
    cout<<endl;
}