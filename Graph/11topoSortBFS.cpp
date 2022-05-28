/*

// Kahn's Algorithm

Topological sort : 
    * linear ordering of vertices s.t if there is an edge u->v, u appears before v in that ordering.
    * There can be more than one topological sorting for a graph.
    * possible for DAG (Directed Acyclic Graph)

Algorithm:
    -> require two thing...inDegree array and queue Data structure
    -> fill the inDegree array
    -> fill queue by rule :
        -> insert all nodes with inDegree[node] as zero
        -> Now simple bfs algo follows
        -> take q.front() and print it(part of topological sort)...recurr its adjacent nodes
        -> while recurring reduce the inDegree of child by one and then insert if inDegree is zero

Time Complexity: O(N+E)
Space complexity: O(N)+O(N)

Intution behind this algo. :
    whenever a node "u" is inserted into the queue 
    it is guranteed that it has no in degree, 
    so its going to appear before a node "v",
    making sure that for an edge u->v, u appears before v.  
*/

#include<bits/stdc++.h>

using namespace std;

void printTopologicalSort(int N, vector<int> adj[]) {
        queue<int> q; 
	    vector<int> indegree(N, 0); 
	    for(int i = 0;i<N;i++) {
	        for(auto it: adj[i]) {
	            indegree[it]++; 
	        }
	    }
	    
	    for(int i = 0;i<N;i++) {
	        if(indegree[i] == 0) {
	            q.push(i); 
	        }
	    }

        cout<<"Topological Sort using BFS -> Kahn's Algo:\n";
	    while(!q.empty()) {
	        int node = q.front(); 
            cout<<node<<" ";
	        q.pop(); 
	        for(auto it : adj[node]) {
	            indegree[it]--;
	            if(indegree[it] == 0) {
	                q.push(it); 
	            }
	        }
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