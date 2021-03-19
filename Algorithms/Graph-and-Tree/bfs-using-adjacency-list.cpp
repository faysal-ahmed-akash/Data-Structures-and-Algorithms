#include <bits/stdc++.h>

using namespace std;

const int numOfNodes = 6;
unordered_map<int, vector<int>> adjList;

//for bfs of a tree we don't need this bool vector
//but for bfs of a graph we need this vector as unlike tree graph may contain cycles
//so we may end up looping infinitely
vector<bool> visited(numOfNodes, false);

void addEdge(int s, int d){
    adjList[s].push_back(d);
    adjList[d].push_back(s); //for directed graph remove this line
}

void bfs(int start){
    //print adjacency list
    for(auto i : adjList){
        cout<<"parent: "<<i.first<<" child: ";
        for(int j : i.second) cout<<j<<" ";
        cout<<endl;
    }
    
    cout<<"bfs: ";
    visited[start] = true;
    
    queue<int> q;
    
    q.push(start);
    
    while(!q.empty()){
        int s = q.front();
        
        q.pop();
        
        cout<<s<<" ";
        
        for(auto i : adjList[s]){
            if(!visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int main(){
    int start = 3;
    
    addEdge(0, 1);
    addEdge(1, 4);
    addEdge(0, 2);
    addEdge(2, 3);
    addEdge(1, 5);
   
    bfs(start);
}