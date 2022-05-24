/*
Depth-first search is an algorithm for traversing or searching tree or graph data structures. The algorithm starts at the root node (selecting some arbitrary node as the root node in the case of a graph) and explores as far as possible along each branch before backtracking. So the basic idea is to start from the root or any arbitrary node and mark the node and move to the adjacent unmarked node and continue this loop until there is no unmarked adjacent node. Then backtrack and check for other unmarked nodes and traverse them. Finally, print the nodes in the path.

    -> uses stack
    -> we might traverse through more edges to reach a destination vertex from a source
    -> more suitable when there are solutions away from source.
    -> more suitable for game or puzzle problems. We make a decision, then explore all paths through this decision. And if this decision leads to win situation, we stop.
    -> children are visited before the siblings
    -> DFS algorithm is a recursive algorithm that uses the idea of backtracking
    -> requires less memory

Algorithm: 
Create a recursive function that takes the index of the node and a visited array.

   * Mark the current node as visited and print the node.
   * Traverse all the adjacent and unmarked nodes and call the recursive function with the index of the adjacent node.
*/

#include<bits/stdc++.h>

using namespace std;

map<int, list<int> > adjList;
map<int, bool> visited;

void dfsUtils(int v){
    // mark the current node as visited and print it.
    visited[v]=1;
    cout<<v<<" ";

    list<int>::iterator i;
    // check for the adjacent nodes of the current node....they are the child
    for (i = adjList[v].begin(); i != adjList[v].end(); ++i)
        // check if the child is visited or not.....if not then call dfs on child.
        if (!visited[*i])
            dfsUtils(*i);
}

void dfs(){
    // since the graph can have multiple components so we are using this function
    // else it would have been a single dfs call.
    cout<<"\nDFS of the above graph:\n";
    for(auto i : adjList){
        if(visited[i.first]!=1){
            dfsUtils(i.first);
        }
    }
}

void printGraph(){
    cout<<"Graph:\n";
    list<int>::iterator it;

    for(auto i : adjList){

        int v = i.first; 
        cout<<v<<" -> ";
        
        for(it=adjList[v].begin();it!=adjList[v].end();it++)
            cout<<*it<<" ";
        cout<<endl;

    }
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int e;
    cin>>e;

    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        adjList[a].push_back(b);
    }

    printGraph();
    dfs();   

    return 0;
}