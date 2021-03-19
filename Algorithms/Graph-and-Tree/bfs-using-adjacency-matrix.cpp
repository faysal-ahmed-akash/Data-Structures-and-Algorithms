#include <bits/stdc++.h>

using namespace std;

const int numOfNode = 9;
int adjMat[numOfNode][numOfNode];

void init(){
    for(int i = 0; i < numOfNode; i++){
        for(int j = 0; j < numOfNode; j++){
            adjMat[i][j]=0;
        }
    }
}

void addEdge(int s, int d){
    adjMat[s][d]=1;
    adjMat[d][s]=1;
}

void bfs(int root){
    queue<int> q;
    vector<bool> visited(numOfNode, false);
    visited[root] = true;
    
    q.push(root);
    
    while(!q.empty()){
        int s = q.front();
        q.pop();
        cout<<s<<endl;
        for(int i = 0; i < numOfNode; i++){
            if(!visited[i] && adjMat[s][i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int main(){
    int root = 0;
    
    init();
    
    addEdge(0,1);
    addEdge(0,2);
    addEdge(1,3);
    addEdge(1,4);
    addEdge(6,8);
    addEdge(2,5);
    addEdge(2,6);
    addEdge(3,7);
    
    bfs(root);
}