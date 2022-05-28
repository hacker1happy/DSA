/*
Topological sort : 
    * linear ordering of vertices s.t if there is an edge u->v, u appears before v in that ordering.
    * There can be more than one topological sorting for a graph.
    * possible for DAG (Directed Acyclic Graph)

Algorithm:
    -> call dfs(root)
    -> mark it as visited
    -> recurr all its adjacent nodes
        -> if (child is not visited)...call dfs(child)
    -> at the end dfs call put the root in a global stack.
    -> topological sort will be elements in stack from top to bottom.

Intution behind this algo. : 
    whenever a dfs call is completed 
    it is put into the stack 
    making sure that for an edge u->v, 
    u appears before v. 
*/

#include<bits/stdc++.h>

using namespace std;

void topoSortDFS(int root,vector<int> adj[], stack<int> &s, int vis[]){
    vis[root]=1;
    for(auto ch : adj[root]){
        if(!vis[ch])
            topoSortDFS(ch,adj,s,vis);
    }
    s.push(root);
}

void printTopologicalSort(int v,vector<int> adj[]){
    stack<int> s;
    int vis[v]={0};
    for(int i=0;i<v;i++){
        if(!vis[i]){
            topoSortDFS(i,adj,s,vis);
        }
    }
    cout<<"Topological sort :\n";
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int v,e;
    cin>>v>>e;
    vector<int> adj[v];
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
    }
    printTopologicalSort(v,adj);
    return 0;
}