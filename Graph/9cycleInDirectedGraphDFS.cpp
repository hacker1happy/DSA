// Given a directed graph, check whether the graph contains a cycle or not. Your function should return true if the given graph contains at least one cycle, else return false.

/*
Algorithm :
    -> take two arrays as visited and dfsVisited
        -> visited for, if the node is visited atleast once in whole program
        -> dfsVisited for, if a node is visited in a particular dfs call
    -> call dfs(root) ... mark root as visited in both the arrays
    -> recurr all the adjacent nodes of the root
    -> if (child is not visited)...call dfs(child)
    -> else if (child is visited in both the arrays) return true...as this child has been found in this dfs call again
    -> on end of a dfs call...mark child as unvisited in the dfsVisited array...saying it's dfs call is over
*/

#include<bits/stdc++.h>

using namespace std;

class Solution {
  private:
    bool checkCycle(int root, vector < int > adj[], int vis[], int dfsVis[]) {
      vis[root] = 1;
      dfsVis[root] = 1;
      for (auto it: adj[root]) {
        if (!vis[it]) {
          if (checkCycle(it, adj, vis, dfsVis)) return true;
        } else if (dfsVis[it]) {
          return true;
        }
      }
      dfsVis[root] = 0;
      return false;
    }
  public:
    bool isCyclic(int N, vector < int > adj[]) {
      int vis[N], dfsVis[N];
      memset(vis, 0, sizeof vis);
      memset(dfsVis, 0, sizeof dfsVis);

      for (int i = 0; i < N; i++) {
        if (!vis[i]) {
          if (checkCycle(i, adj, vis, dfsVis)) {
            return true;
          }
        }
      }
      return false;
    }
};

void addEdge(vector < int > adj[], int u, int v) {
  adj[u].push_back(v);
  adj[v].push_back(u);
}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int v,e;
    cin>>v>>e;
    vector < int > adj[v];

    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        addEdge(adj, a, b);
    }

    Solution obj;
    if (obj.isCyclic(v, adj))
        cout << "Cycle Detected" << "\n";
    else
        cout << "No Cycle Detected";

    return 0;
}
