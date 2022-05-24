/*
Cycle detection in Graph using BFS:

Algorithm :
    -> take root node assign it parent as -1 and mark it as visited & push it to queue along with the parent
    -> visit the children of queue's top element (node, parent)
    -> if(child is not visited)...mark it as visited and push it into the queue with parent as node.
    -> if(child is visited)
        -> if(child is same as parent)...move on---as the child had came from the parent
        -> if(child is not same as parent)...then it had been marked by some other parent by some other route---so there is a cycle

*/

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool checkForCycle(int root, int V, vector<int> adj[], vector<int> &visited)
    {
        // Create a queue for BFS
        queue<pair<int, int>> q;
        visited[root] = true;
        q.push({root, -1});
        while (!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
 
            for (auto child : adj[node])
            {
                if (!visited[child])
                {
                    visited[child] = true;
                    q.push({child, node});
                }
                else if (parent != child)
                    return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[])
    {
        vector<int> vis(V - 1, 0);
        for (int i = 1; i <= V; i++)
        {
            if (!vis[i])
            {
                if (checkForCycle(i, V, adj, vis))
                    return true;
            }
        }
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
    bool ans = obj.isCycle(v, adj);
    if(ans)
        cout<<"Cycle is there.";
    else
        cout<<"Cycle is not there.";

    return 0;
}