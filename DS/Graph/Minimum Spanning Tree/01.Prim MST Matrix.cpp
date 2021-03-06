/*

Prim��s algorithm is also a Greedy algorithm. It starts with an empty spanning tree. 
The idea is to maintain two sets of vertices. The first set contains the vertices 
already included in the MST, the other set contains the vertices not yet included.
 At every step, it considers all the edges that connect the two sets, and picks 
 the minimum weight edge from these edges. After picking the edge, it moves the 
 other endpoint of the edge to the set containing MST.
A group of edges that connects two set of vertices in a graph is called cut in 
graph theory. So, at every step of Prim��s algorithm, we find a cut (of two sets,
 one contains the vertices already included in MST and other contains rest of the verices),
  pick the minimum weight edge from the cut and include this vertex to MST Set 
  (the set that contains already included vertices).

How does Prim��s Algorithm Work? The idea behind Prim��s algorithm is simple, 
a spanning tree means all vertices must be connected. So the two disjoint subsets
 (discussed above) of vertices must be connected to make a Spanning Tree. And they 
 must be connected with the minimum weight edge to make it a Minimum Spanning Tree.

Algorithm
1) Create a set mstSet that keeps track of vertices already included in MST.
2) Assign a key value to all vertices in the input graph. Initialize all key v
alues as INFINITE. Assign key value as 0 for the first vertex so that it is picked first.
3) While mstSet doesn��t include all vertices
��.a) Pick a vertex u which is not there in mstSet and has minimum key value.
��.b) Include u to mstSet.
��.c) Update key value of all adjacent vertices of u. To update the key values, 
iterate through all adjacent vertices. For every adjacent vertex v, if weight of 
edge u-v is less than the previous key value of v, update the key value as weight of u-v

*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int V = 5;

int getMinKey(int key[], bool inMST[])
{
	int minVal = INT_MAX;
	int index;
	for (int i = 0; i < V; ++i) {
		if (inMST[i] == false && key[i] < minVal) {
			minVal = key[i];
			index = i;
		}
	}
	return index;
}

void primMST(int graph[V][V])
{
	int parent[V]; //array store constructed MST
    int key[V]; //key values to pick minmum weight edge
    bool inMST[V]; //reprent vetices in MST set
	for (int i = 0; i < V; ++i) {
		key[i] = INT_MAX;
		inMST[i] = false;
	}
	
	key[0] = 0;  // Make key 0 so that this vertex is picked as first vertex
	parent[0] = -1;// First node is always root of MST 
	for (int cnt = 0; cnt < V-1; ++cnt) {
		int u = getMinKey(key, inMST);
		inMST[u] = true;
		
		// Update key value and parent index of the adjacent vertices of
        // the picked vertex. Consider only those vertices which are not yet
        // included in MST
        for (int v = 0; v < V; ++v) {
        	if (graph[u][v] && inMST[v] == false && graph[u][v] < key[v]) {
        		parent[v] = u;
        		key[v] = graph[u][v];
			}
		}
	}
	
	 for (int i = 1; i < V; i++) {
        cout << parent[i] << " " << i << " " << graph[i][parent[i]] << endl;
     }
}
int main()
{
	   /* Let us create the following graph
          2    3
      (0)--(1)--(2)
       |   / \   |
      6| 8/   \5 |7
       | /     \ |
      (3)-------(4)
            9          */
   int graph[V][V] = {{0, 2, 0, 6, 0},
                      {2, 0, 3, 8, 5},
                      {0, 3, 0, 0, 7},
                      {6, 8, 0, 0, 9},
                      {0, 5, 7, 9, 0},
                     };
 
    // Print the solution
    primMST(graph);
    
    return 0;
}
