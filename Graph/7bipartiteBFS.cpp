/* 
A Bipartite Graph is a graph whose vertices can be divided into two independent sets, U and V such that every edge (u, v) either connects a vertex from U to V or a vertex from V to U. In other words, for every edge (u, v), either u belongs to U and v to V, or u belongs to V and v to U. We can also say that there is no edge that connects vertices of same set.

A bipartite graph is possible if the graph coloring is possible using two colors such that vertices in a set are colored with the same color. Note that it is possible to color a cycle graph with even cycle using two colors. It is not possible to color a cycle graph with odd cycle using two colors. 

Striver told : if odd length cycle is there it's not bipartite for sure...rest it is bipartite graph

Algorithm :
    -> Start with root...mark it as color "0"
    -> visit children of queue's top and 
    -> if(children is not colored)...mark it visited, push it to queue, mark it as opposite color from the parent
    -> if(children is colored)...& if their adjacent node(s) have same color then its not bipartite...return false.
*/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isBipartite(int root, vector<int> color, vector<int> adj[]){
        
        color[root] = 0;
        queue<int> q;
        q.push(root);

        while(!q.empty()){
            
            int v = q.front();
            q.pop();

            for(auto it : adj[v]){
                if(color[it] == -1){
                    color[it] = 1-color[v];
                    q.push(it);
                } else if(color[it]==color[v])
                    return false;
            }
        }
        return true;
    }

    bool isBipartiteBFS(int v, vector<int> adj[]){
        vector<int> colored(v,-1);
        for(int i=1;i<=v;i++){
            if(colored[i]==-1){
                if(!isBipartite(i,colored,adj))
                    return false;
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
    vector < int > adj[v];

    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        addEdge(adj, a, b);
    }

    Solution obj;
    bool ans = obj.isBipartiteBFS(v, adj);
    if(ans)
        cout<<"Yes bipartite.";
    else
        cout<<"Not bipartite.";

    return 0;
}