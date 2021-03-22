#include <bits/stdc++.h>

using namespace std;

const int numOfNode = 9;
int adjMat[numOfNode][numOfNode];
vector<bool> visited(numOfNode, false);

void init(){
    for(int i = 0; i < numOfNode; i++){
        for(int j = 0; j < numOfNode; j++){
            adjMat[i][j] = 0;
        }
    }
}

void addEdge(int s, int d){
    adjMat[s][d] = 1;
    adjMat[d][s] = 1;
}

void dfs(int start){
    visited[start] = true;
    
    stack<int> st;
    
    st.push(start);
    
    while(!st.empty()){
        int s = st.top();
        
        st.pop();
        
        cout<<s<<" ";
        
        for(int i = 0; i < numOfNode; i++){
            if(adjMat[s][i] && !visited[i]){
                st.push(i);
                visited[i] = true;
            }
        }
    }
}

int main(){
    int start = 0;
    
    init();
    
    addEdge(0,1);
    addEdge(0,2);
    addEdge(1,3);
    addEdge(1,4);
    addEdge(6,8);
    addEdge(2,5);
    addEdge(2,6);
    addEdge(3,7);
    
    dfs(start);
}