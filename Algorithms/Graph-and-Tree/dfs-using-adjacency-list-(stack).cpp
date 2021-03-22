#include <bits/stdc++.h>

using namespace std;

const int numOfNodes = 5;
unordered_map<int, vector<int>> adjList;
vector<bool> visited(numOfNodes, false);

void addEdge(int s, int d){
    adjList[s].push_back(d);
    adjList[d].push_back(s); //for directed graph remove this line
}

void printList(){
    //print adjacency list
    for(auto i : adjList){
        cout<<"parent: "<<i.first<<" child: ";
        for(int j : i.second) cout<<j<<" ";
        cout<<endl;
    }
    
    cout<<"dfs: ";
}

void dfs(int start){
    
    visited[start] = true;
    
    stack<int> st;
    
    st.push(start);
    
    while(!st.empty()){
        int s = st.top();
        
        st.pop();
        
        cout<<s<<" ";
        
        for(auto i : adjList[s]){
            if(!visited[i]){
                st.push(i);
                visited[i] = true;
            }
        }
    }
}

int main(){
    int start = 0;
    
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(2, 3);
    addEdge(1, 5);
    
    printList();
    
    dfs(start);
}