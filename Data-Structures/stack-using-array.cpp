#include <bits/stdc++.h>
using namespace std;

#define N 5

class Stack{
    public:
        int st[N];
        int cnt = 0;
        
        void push(int x){
            if(!full()){
                st[cnt] = x;
                cnt++;
            }else cout<<"Stack is full!"<<endl;
        }
        
        void pop(){
            if(!empty()){
                cnt--;
            }else cout<<"Stack is empty!"<<endl;
        }
        
        int top(){
            if(cnt == 0) return -100000;
            return st[cnt - 1];
        }
        
        int size(){
            return cnt;
        }
        
        bool full(){
            if(cnt < N) return false;
            return true;
        }
        
        bool empty(){
            if(cnt > 0) return false;
            return true;
        }
        
        void printStack(){
            for(int i = 0; i < cnt; i++) cout<<st[i]<<endl;
        }
};

int main() {
    Stack s;
    
    s.push(10);
    s.push(20);
    s.push(30);
    s.pop();
    s.push(40);
    s.push(50);
    s.push(60);
    s.pop();
    
    cout<<"Top: "<<s.top()<<endl;
    cout<<"Size: "<<s.size()<<endl;
    cout<<"Full: "<<s.full()<<endl;
    cout<<"Empty: "<<s.empty()<<endl;
    
    s.printStack();
    
    return 0;
}