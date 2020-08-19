#include<iostream>
#include<list>
#include<iterator>
#include<random>
#include<queue>
#include<climits>
#include<algorithm>
#include<math.h>

using namespace std;

class edge {
public:
	double v_one, v_two, length;

	edge (double v1, double v2, double l)
	{
		v_one = v1, v_two = v2, length = l;
	}
};

double calculateDistance(vector<double> v1, vector<double> v2, int dimension)
{
	// cout << "Calculating distance between (" << v1[0] << ", " << v1[1] << ", " << v1[2] << ") and (" << v2[0] << ", " << v2[1] << ", " << v2[2] << ")" << endl;
	double sum;
	for(int i = 0; i < dimension; i++)
	{
		sum += pow((v1[i] - v2[i]),2.0);
	}
	return sqrt(sum);
}

double primMST(vector<vector<double> > graph, int n, int dimension)
{
	vector<edge> edges;
	double min_distance = 10;
	// Add n-1 edges, each with null nodes and 10 (INF) distance
	for(int i = 0; i < n - 1; i++)
	{
		edges.push_back(edge(0,0,10));
	}

	// Initialize first vertex as done (-1), distance = 0
	edges[0] = edge(-1,0,0);

	// start/current node
	int current_node_index = 0;
	int next_node_index;

	// Start at a, check distance to all other 
	for(int j = 0; j < n - 1; j++)
	{
		edges[current_node_index].v_one = -1;
		min_distance = 10;

		for(int k = 0; k < n - 1; k++)
		{
			if (edges[k].v_one >= 0)
			{
				double distance = calculateDistance(graph[current_node_index], graph[k], dimension);
				if (edges[j].length > distance)
				{
					if (distance < min_distance)
					{
						min_distance = distance;
						edges[k].v_one = j;
						next_node_index = k;
					}
					edges[k].length = distance;
				}
			}
		}
		current_node_index = next_node_index;
	}

	double sum = 0;
	for(int i = 0; i < n-1; i++)
	{
		sum += edges[i].length;
	}
	return(sum);
}

void printGraph(vector<vector<double> > graph, int n, int d)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Coordinate " << i << ": ";
		for (int j = 0; j < d; j++)
		{
			cout << graph[i][j] << ",";
		}
		cout << endl;
	}
}


// initializes graph as vector of verticies
vector<vector<double> > makeGraph(int v, int dimension) {
	vector<vector<double> > graph;
	
	std::default_random_engine gen;
    std::uniform_real_distribution<double> distribution(0.0,1.0);

	for (int i = 0; i < v; i++){
		vector<double> coordinate;
		
		for (int j = 0; j < dimension; j++)
		{
			double temp = distribution(gen);
			coordinate.push_back(distribution(gen));
		}

		graph.push_back(coordinate);
	}
	return(graph);
}


//main method
int main(int argc, char* argv[]) 
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine gen (seed);
    std::uniform_real_distribution<double> distribution(0.0,1.0);

	int n;
	cout << "n: ";
	cin >> n;

	int dimension;
	cout << "Dimension: ";
	cin >> dimension;
	
	vector<vector<double> > graph = makeGraph(n, dimension);

	// Tester code to make sure Edge class worked
	/*
	vector<edge> edges;

	for(int i = 0; i < n; i++)
	{
		edge current = edge(distribution(gen),distribution(gen),distribution(gen));
		edges.push_back(current);
	}
	for (int j = 0; j < n; j++)
	{
		cout << edges[j].v_one << ", " << edges[j].v_two << ", " << edges[j].length << endl;
	}
	*/

	//printGraph(graph, n, dimension);
	/*
	vector<Edge> edges(n);
	for (int i = 0; i < n; i++)
	{
		Edge here(0.5,0.1,0.4);
		edges.push_back(here);
	}

	for (int j = 0; j < n; j++)
	{
		cout << edges[j].v_one << ", " << edges[j].v_two << ", " << edges[j].length << endl;
	}
	*/

	cout << primMST(graph, n, dimension) << endl;

	return 0;
}