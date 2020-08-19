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
    vector<double> coordinates;

    //find minimum edge weight
    int minindex() {
        return 0;
    };
};

/*

//generates edge weights
vector <double> generateWeights(vector <double> coordsource, int dimensions, int nodes){

    // seeds randomizer and creates a uniform distribution
	std::random_device rd;  //Will be used to obtain a seed for the random number engine
	std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	std::uniform_real_distribution<> dis(0.0, 1.0);

    vector <double> weights;
    if (dimensions == 0){
        for (int i = 0; i++; i<nodes){
            weights.push_back(dis(gen));
        }
    }
    else{
        cout << "yeet";
    }
    return weights;
}

//performs prims algorithm
void primsMSPAN(vector <Vertex> graph, int nodes, int dimension) {

    
    Vertex currentnode = graph.at(0);
    int minindex = 0;
    for (int i = nodes-1; i > 0; i--){
        vector<double> currentcoordinates = currentnode.coordinates;
        graph.erase(graph.begin()+minindex);
        vector <double> weights = generateWeights(currentcoordinates, dimension, i);
        double min = * std::min_element(weights.begin(), weights.end());
        minindex = i;
        for (int j = i; j > 0; j++){
            double dist = graph.at(j).distance;
            if (weights.at(j) < dist){
                graph.at(j).distance = weights.at(j);
            }
            if (weights.at(j) = min) {
                minindex = j;

            }
        }
        currentnode = graph.at(minindex);
    }
}
*/

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
    // primsMSPAN(graph,n,dimension);

    for (int i = 0)

    return 0;
}