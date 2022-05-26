/* 
Striver told : if odd length cycle is there it's not bipartite for sure...rest it is bipartite graph

Algorithm :
    -> Start with root...mark it as color "0"
    -> visit children of queue's top and 
    -> if(children is not colored)...mark it visited, push it to queue, mark it as opposite color from the parent
    -> if(children is colored)...& if their adjacent node(s) have same color then its not bipartite...return false.
*/

#include<bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool bipartiteDfs(int node, vector<int> adj[], int color[]) {
        for(auto it : adj[node]) {
            if(color[it] == -1) {
                color[it] = 1 - color[node];
                if(!bipartiteDfs(it, adj, color)) {
                    return false; 
                }
            } else if(color[it] == color[node]) return false; 
        }
        return true; 
    }
    bool checkBipartite(vector<int> adj[], int n) {
        int color[n];
        memset(color, -1, sizeof color); 
        for(int i = 0;i<n;i++) {
            if(color[i] == -1) {
                color[i] = 1;
                if(!bipartiteDfs(i, adj, color)) {
                    return false;
                }
            } 
        }
        return true; 
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
    vector<int> adj[v];

    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        addEdge(adj, a, b);
    }

    Solution obj;
    bool ans = obj.checkBipartite(adj,v);
    if(ans)
        cout<<"Yes bipartite.";
    else
        cout<<"Not bipartite.";

    return 0;
}