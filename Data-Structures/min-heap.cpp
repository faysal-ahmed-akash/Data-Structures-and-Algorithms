#include <bits/stdc++.h>
using namespace std;

class MinHeap{
    public:
        int heap_size;
        int *heap;
        int capacity;
    
        MinHeap(int x); 
        int parent(int i) {return (i - 1) / 2;}
        int left(int i) {return 2 * i + 1;}
        int right(int i) {return 2 * i + 2;}
        void insertKey(int x);
        void deleteKey(int i);
        void increaseKey(int i, int new_val);
        void decreaseKey(int i, int new_val);
        void minHeapify(int i);
        int extractMin();
};

void swap(int *x, int *y){ 
    int temp = *x; 
    *x = *y; 
    *y = temp; 
}

MinHeap::MinHeap(int x){ 
    heap_size = 0; 
    capacity = x; 
    heap = new int[x]; 
} 

void MinHeap::insertKey(int x){
    if(heap_size == capacity) cout<<"Overflow!"<<endl;
    else{
        heap[heap_size] = x;
        int i = heap_size;
        heap_size++;
        
        while(i != 0 && heap[parent(i)] > heap[i]){
            swap(&heap[parent(i)], &heap[i]); //passing as pointer so that original array gets changed
            i = parent(i);
        }
    }
}

void MinHeap::decreaseKey(int i, int new_val){
    heap[i] = new_val;
    while (i != 0 && heap[parent(i)] > heap[i]){ //traverse up
       swap(&heap[i], &heap[parent(i)]);
       i = parent(i);
    }
}

void MinHeap::increaseKey(int i, int new_val){
    heap[i] = new_val;
    minHeapify(i); //traverse down
}

void MinHeap::deleteKey(int i){ 
    decreaseKey(i, INT_MIN); //this value will be root
    extractMin(); //extract the root
}

void MinHeap::minHeapify(int i){
    int l = left(i);
    int r = right(i);
    int smallest = i;
    
    //we need to check if i is a leaf node or not
    //if i is leaf node then l and r will be greater than heap size
    if(l < heap_size && heap[l] < heap[i])
        smallest = l; //l is the smallest
    if(r < heap_size && heap[r] < heap[smallest])
        smallest = r; //r is the smallest
        
    if(smallest != i){ //if i is not the smallest then replace i with the smallest else i is the smallest no need to heapify
        swap(&heap[i], &heap[smallest]);
        minHeapify(smallest); //traversing down to check for smallest value
    }
}

int MinHeap::extractMin(){
    if(heap_size <= 0) return INT_MAX;
    else if(heap_size == 1){
        heap_size--;
        return heap[0];
    }
    
    int root = heap[0];
    heap[0] = heap[heap_size - 1];
    heap_size--;
    minHeapify(0);
    
    return root;
}

int main(){
    MinHeap h(10);
    
    h.insertKey(3); 
    h.insertKey(2);
    h.insertKey(15); 
    h.insertKey(5); 
    h.insertKey(10);
    h.insertKey(20);
    h.insertKey(1);
    
    //print the heap
    for(int i = 0; i < h.heap_size; i++) cout<<h.heap[i]<<" ";
}