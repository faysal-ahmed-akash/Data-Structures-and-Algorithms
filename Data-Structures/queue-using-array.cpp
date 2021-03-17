#include <bits/stdc++.h>
using namespace std;

#define N 5

class Queue{
    public:
        int queue[N];
        int i = 0;
        int j = 0;
        int sz = 0;
        
        void push(int x){
            if(!full()){
                queue[j] = x;
                j++;
                sz++;
                if(j == N) j = 0;
            }else cout<<"Queue is full, can't push!"<<endl;
        }
        
        void pop(){
            if(!empty()){
                i++;
                sz--;
                if(i == N) i = 0;
            }else cout<<"Queue is empty, can't pop!"<<endl;
        }
        
        int front(){
            if(size() == 0) return -100000;
            return queue[i];
        }
        
        int size(){return sz;}
        
        bool full(){
            if(size() == N) return true;
            return false;
        }
        
        bool empty(){
            if(size() == 0) return true;
            return false;
        }
        
        void printQueue(){
            if(!empty()){
                int k = i;
                int x = size();
                while(x--){
                    if(k == N) k = 0;
                    cout<<queue[k]<<endl;
                    k++;
                }
            }else cout<<"Queue is empty, nothing to print!"<<endl;
        }
};

int main() {
    Queue q;
    
    q.push(10);
    q.push(20);
    q.push(30);
    q.pop();
    q.push(40);
    q.push(50);
    q.push(60);
    q.pop();
    q.push(70);
    // q.pop();
    
    cout<<"Front: "<<q.front()<<endl;
    cout<<"Size: "<<q.size()<<endl;
    cout<<"Full: "<<q.full()<<endl;
    cout<<"Empty: "<<q.empty()<<endl;
    
    q.printQueue();
    
    return 0;
}
