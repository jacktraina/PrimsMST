#include<iostream>
#include<list>
#include<iterator>
#include<random>
#include<queue>
#include<climits>
#include<algorithm>

using namespace std;

//class to store nodes
class Vertex {
	public:

	vector<double> edges;
	double min;
	int nametag;
	double distance;
	// Need to add class for vector pair
	vector<double> coordinates;

	//find minimum edge weight
	int minindex() {
		return 0;
	};
};


vector <double> generateWeights(vector <double> coordsource, int dimensions, int nodes)
{
	
	if (dimensions == 0)
	{

		vector <double> weights(nodes);
		
		// Need to fix random generator
		/*
		random_device rnd_device;
		mt19937 mersenne_engine {rnd_device()};  
		uniform_real_distribution<double> dist {0, 1};

		auto gen = [&dist, &mersenne_engine](){
					return dist(mersenne_engine);
				};
		
		generate(begin(weights), end(weights), gen);
		*/

		for (int i = 0; i<nodes; i++)
		{
			weights[i] = (double) (rand() % 1000) / 1000;
			// weights[i] = dis(gen);
			// cout << weights.at(i);
			// cout << weights.at(0);
		}
		
		cout << weights.at(1);
		return weights;
	}
	else
	{
		cout << "yeet";
	
	}
	
}

//performs prims algorithm
void primsMSPAN(vector <Vertex>  & inpGraph, int nodes, int dimension) {

	cout << "hello";
	cout << endl;
	Vertex currentnode = inpGraph.at(0);

	int * minindex =  0;
	for (int i = nodes-1; i > 0; i--){
		vector<double> currentcoordinates = currentnode.coordinates;
		inpGraph.erase(inpGraph.begin()+ (* minindex));
		
		vector <double> edgeweights = generateWeights(currentcoordinates, dimension, i);
		
		
		cout << edgeweights.at(i-1);
		
		double min = * std::min_element(edgeweights.begin(), edgeweights.end());
		


		for (int j = i-1; j > 0; j--){
			double dist = inpGraph.at(j).distance;
			
			if (edgeweights.at(j) < dist){
				inpGraph.at(j).distance = edgeweights.at(j);
			}
			
			if (edgeweights.at(j) == min) {
				* minindex = j;
				cout << "yeet";
				cout << endl;

			}
			
		}
		currentnode = inpGraph.at(* minindex);
	}
} 



// initializes graph as vector of verticies
vector <Vertex> makeGraph(int nodes) {
	vector <Vertex> graph;
	for (int i = 0; i < nodes; i++){
		Vertex newvert;
		newvert.nametag = i;
		newvert.distance = INT_MAX;
		graph.push_back(newvert);
	}
	return(graph);
}


//main method
int main(int argc, char* argv[]) {
	int n;
	cout << "n: ";
	cin >> n;
	cout << endl;

	int dimension;
	cout << "dimension: ";
	cin >> dimension;
	cout << endl;
	
	vector <Vertex> graph = makeGraph(n);
	cout << "made graph";
	cout << endl;

	primsMSPAN(graph,n,dimension);

	return 0;
}