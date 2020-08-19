#include<iostream>
#include<list>
#include<iterator>
#include<random>
#include <queue>
#include<climits>

using namespace std;


 
// A utility function to find the vertex with  
// minimum dist value, from the set of vertices  
// not yet included in MST  
int minDist(vector<int> dist, bool mstSet[], int n)  
{  
	// Initialize min value  
	int min = INT_MAX, min_index;  
  
	for (int v = 0; v < n; v++)  
		if (mstSet[v] == false && dist.at(v) < min)  
			min = dist.at(v), min_index = v;  
  
	return min_index;  
}  
  
// A utility function to print the  
// constructed MST stored in prev[]  
void printMST(int prev[], vector< vector<int> > graph, int n)  
{  
	cout<<"Edge \tWeight\n";  
	for (int i = 1; i < n; i++)  
		cout<<prev[i]<<" - "<<i<<" \t"<<graph[i][prev[i]]<<" \n";  
}  
  
// Function to construct and print MST for  
// a graph represented using adjacency  
// matrix representation  
void primMST(int n)  
{  
	vector <vector<int> > graph;
	std::random_device rd;  //Will be used to obtain a seed for the random number engine
	std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	std::uniform_real_distribution<> dis(1, 10);
	// Array to store constructed MST  
	int prev[n];  
	  
	// Distance values used to pick minimum weight edge in cut  
	int dist[n];  
	  
	// To represent set of vertices not yet included in MST  
	bool mstSet[n];  
  
	// Initialize all dists as INFINITE  
	for (int i = 0; i < n; i++)  
		dist[i] = INT_MAX, mstSet[i] = false;  
  
	// Always include first 1st vertex in MST.  
	// Make dist 0 so that this vertex is picked as first vertex.  
	dist[0] = 0;  
	prev[0] = -1; // First node is always root of MST  
  
	// The MST will have n vertices  
	for (int count = 0; count < n - 1; count++) 
	{  
		// Pick the minimum dist vertex from the  
		// set of vertices not yet included in MST 

		
		vector<int> locdist;
		for (int i =0; i<n; i++){
			locdist.push_back(dis(gen));
		}
		int u = minDist(locdist, mstSet, n);  
		graph.push_back(locdist);
  
		// Add the picked vertex to the MST Set  
		mstSet[u] = true;  
  
		// Update dist value and prev index of  
		// the adjacent vertices of the picked vertex.  
		// Consider only those vertices which are not  
		// yet included in MST  
		for (int v = 0; v < n; v++)  
  
			// graph[u][v] is non zero only for adjacent vertices of m  
			// mstSet[v] is false for vertices not yet included in MST  
			// Update the dist only if graph[u][v] is smaller than dist[v]  
			if (graph[v][u] && mstSet[v] == false && graph[v][u] < dist[v])  
				prev[v] = u, dist[v] = graph[v][u];  
	}  
  
	// print the constructed MST  
	 printMST(prev, graph, n);  
}  

int main(int argc, char* argv[]) {

	int n;
	cout << "n: ";
	cin >> n;
	cout << endl;


	primMST(n);
	return 0;
}