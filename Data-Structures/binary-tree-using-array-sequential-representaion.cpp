#include <bits/stdc++.h>
using namespace std;

char tree[10]; //all index has been initialized with '\0'

void root(char key){
    if(tree[0] != '\0') cout<<"Tree already has a root"<<endl;
    else tree[0] = key;
}

void setLeft(char key, int parent){
    if(tree[parent] == '\0') cout<<"Can't insert "<<key<<" at "<<2 * parent + 1<<", Parent doesn't exist at "<<parent<<"!"<<endl;
    else tree[2 * parent + 1] = key;
}

void setRight(char key, int parent){
    if(tree[parent] == '\0') cout<<"Can't insert "<<key<<" at "<<2 * parent + 2<<", Parent doesn't exist at "<<parent<<"!"<<endl;
    else tree[2 * parent + 2] = key;
}

void printTree(){
    for(int i = 0; i < 10; i++){
        if(tree[i] != '\0') cout<<tree[i];
        else cout<<"-";
    }    
}

int main() {
    root('A');
    setRight('B', 0);
    setLeft('C', 1);
    setRight('D', 1);
    setRight('E', 2);
    printTree();
    
    return 0;
}
