#include<iostream>
#include<list>
#include<iterator>
#include<random>
using namespace std;

/*
void displayAdjList(list<int> adj_list[], int v) {
	for(int i = 0; i<v; i++) {
		cout << i << "--->";
		list<int> :: iterator it;
		for(it = adj_list[i].begin(); it != adj_list[i].end(); ++it) {
			cout << *it << " ";
		}
		cout << endl;
	}
}
void add_edge(list<int> adj_list[], int u, int v) {    //add v into the list u, and u into list v
	adj_list[u].push_back(v);
	// since it's undirected, we only need half the edges?
	//adj_list[v].push_back(u);
}


void create_graph(list<int> adj_list[], int n) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if (i != j) {
				add_edge(adj_list, i, j);
			}
		}
	}
}

// Obtained from https://en.cppreference.com/w/cpp/numeric/random/uniform_real_distribution
double rand_double() {
	std::random_device rd;  //Will be used to obtain a seed for the random number engine
	std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	std::uniform_real_distribution<> dis(0.0, 1.0);
	return dis(gen);
}

*/


// Obtained from https://en.cppreference.com/w/cpp/numeric/random/uniform_real_distribution

 
// A utility function to find the vertex with  
// minimum dist value, from the set of vertices  
// not yet included in MST  
double minDist(double dist[], bool mstSet[], int n)  
{  
	// Initialize min value  
	double min = (double) INT_MAX;
	int min_index;  
  
	for (int v = 0; v < n; v++)  
		if (mstSet[v] == false && dist[v] < min)  
			min = dist[v], min_index = v;  
  
	return min_index;  
}  
  
// A utility function to print the  
// constructed MST stored in prev[]  
void printMST(int prev[], vector< vector<double> > &graph, int n)  
{  
	cout<<"Edge \tWeight\n";  
	for (int i = 1; i < n; i++)  
		cout<<prev[i]<<" - "<<i<<" \t"<<graph[i][prev[i]]<<" \n";  
}  
  
// Function to construct and print MST for  
// a graph represented using adjacency  
// matrix representation  
void primMST(vector< vector<double> > &graph, int n)  
{  
	// Array to store constructed MST  
	int prev[n];  
	
	// Distance values used to pick minimum weight edge in cut  
	double dist[n];  
	
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
		int u = minDist(dist, mstSet, n);  
  
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
			if (graph[u][v] && mstSet[v] == false && graph[u][v] < dist[v])  
				prev[v] = u, dist[v] = graph[u][v];  
	}  
  
	// print the constructed MST  
	printMST(prev, graph, n);  
}  

void printMatrix(vector< vector<double> > &graph) {
    for(size_t x = 0;x < graph.size();++x){
        for(size_t y = 0;y < graph[x].size();++y){
            cout << graph[x][y] << " ";
        }
        cout << "\n";
    }
}

int main(int argc, char* argv[]) {
	
	std::random_device rd;  //Will be used to obtain a seed for the random number engine
	std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	std::uniform_real_distribution<> dis(0.0, 1.0);

	// prints hello world 
	int n;
	cout << "n: ";
	cin >> n;
	cout << endl;

	vector< vector<double> > graph(n, vector<double>(n));
	//int graph[V][V];

	for(size_t x = 0;x < graph.size();++x){
		for(size_t y = x;y < graph[x].size();++y){
			if (x == y) {
				graph[x][y] = 0;
			}
			else {
				graph[x][y] = dis(gen);
				graph[y][x] = graph[x][y];
			}
		}
	}

	// print graph
	printMatrix(graph);
	cout << endl;

	// primMST(create_graph(n))
	primMST(graph, n);
	return 0;
}