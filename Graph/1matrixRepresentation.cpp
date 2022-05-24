// Adjacency matrix representaion of the graph

#include <iostream>
using namespace std;

int main()
{
	// V is the number of vertices {1,2,3...}
	// e is the number of edges
	int V, e;
	cin >> V >> e ;
	
    // Adjacency matrix
    int adjMat[V + 1][e + 1];
    // initialize the matrix
    for(int i = 0; i <= V; i++)
    {
        for(int j = 0; j <= e; j++)
        {
            adjMat[i][j] = 0;
        }
    }
	for(int i = 0; i < e; i++){
		int u , v ;
		cin >> u >> v ;
		adjMat[u][v] = 1 ;
		adjMat[v][u] = 1 ;
	}	

    // Print the adjacency matrix
    for(int i = 1; i <= V; i++){
        for(int j = 1; j <= e; j++){
            cout << adjMat[i][j] << " ";
        }
        cout << endl;
    }
	
	return 0;
}
