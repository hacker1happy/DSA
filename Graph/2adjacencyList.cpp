// Adjacency list representation of the graph

#include<bits/stdc++.h>

using namespace std;

int main(){
    int v,e;
    cin>>v>>e;

    // Adjacency List
    vector<vector<int>> adjList(v+1);
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    // Print adjacency list
    for(int i=1;i<=v;i++){
        cout<<i<<" -> ";
        for(int j=0;j<adjList[i].size();j++){
            cout<<adjList[i][j]<<" ";
        }
        cout<<endl;
    } 

    return 0;
}