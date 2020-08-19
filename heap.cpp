#include<iostream>
#include<list>
#include<iterator>
#include<random>
#include<queue>
#include<climits>
#include<algorithm>
#include<math.h>
#include<time.h>

using namespace std;

// Class to store nodes
class Vertex {
    public:
    double min;
    int nametag;
    double distance;
    bool explored;
    vector<double> coordinates;

};

// Function to print edges of the MST
void printMSTedges(vector <double> input, int nodes){
    //print MST edges
    for (int i = 0; i<nodes; i++){
        cout << input[i];
        cout << endl;
    }
}


//generates edge weights
vector <double> generateWeights(vector <vector <double>> coords, int sourceindex, int dimensions, int nodes){
    
    //checks dimension before deciding what to do
    if (dimensions == 0){

        //initializes vector
        vector <double> weights(nodes);

        //creates random function
        random_device rnd_device;
        mt19937 mersenne_engine {rnd_device()}; 
        uniform_real_distribution<double> dist {0, 1};
        auto gen = [&dist, &mersenne_engine](){
            return dist(mersenne_engine);
        };

        //populates weights vector with random double values
        generate(begin(weights), end(weights), gen);
        return weights;
    }
    //takes euclidean distance
    else{

        //initializes vector
        vector <double> weights;

        //gets the coordinates of the source index
        vector <double> sourcecoords = coords[sourceindex];

        //finds the distance to every node
        for (int i = 0; i<nodes; i++){
            if (i == sourceindex){
                weights.push_back(7.0);
            }
            else{
                vector <double> destcoords = coords[i];
                double sum = 0.0;
                for (int j = 0; j<dimensions; j++){
                    double temp = (sourcecoords[j] - destcoords[j]);
                    sum += pow(temp,2);
                }
                weights.push_back(sqrt(sum));
            }
        }

        //return vector of weights
        return weights;
    }
    
}



//performs prims algorithm
double primsMSPAN(vector <Vertex> graphinp, int nodes, int dimension) {

    //initialize graph as new vector
    vector <Vertex> graph;
    graph = graphinp;

    //initialize static coordinates array
    vector <vector <double> > coordinatesBank;
    if (dimension != 0){
        for (int i = 0; i < nodes; i++){
            coordinatesBank.push_back(graph[i].coordinates);
        }
    }

    //set initial graph values
    graph[0].explored = true;
    graph[0].min = 0.0;

    //initialize vector of generated edge weights
    vector <double> weights(nodes);

    //do prims to choose n-1 edges for our MST
    for (int i = 1; i < nodes; i++){
        weights = generateWeights(coordinatesBank, (i-1), dimension, nodes);
        int minindex = 0;
        double min = 100;
        for (int j = 0; j<nodes; j++){
            if (weights[j] < graph[j].min && graph[j].explored == false){
                graph[j].min = weights[j];
            }
            if (weights[j] < min){
                min = weights[j];
                minindex = j;
            }
        }
        graph[minindex].explored = true;
    }


    //print the edges of the MST
    vector <double> minedges;
    for(int i=0; i <= nodes; i++){
        minedges.push_back(graph[i].min);
    }
    minedges[0] = 0.0;
    //printMSTedges(minedges,nodes);
    double sum = accumulate(minedges.begin(), minedges.end(), 0.0); 
    return sum;
}



// initializes graph as vector of verticies
vector <Vertex> makeGraph(int nodes, int dim) {

    //randomizer for coordinates
    std::random_device rd;  
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dis(0, 1);

    //initializes values for verticies in graph
    vector <Vertex> graph;
    for (int i = 0; i < nodes; i++){
        Vertex newvert;
        newvert.nametag = i;
        newvert.min = 4.0;
        newvert.explored = false;
        vector <double> temp;
        for (int j = 0; j<dim; j++){
            temp.push_back(dis(gen));
        };
        newvert.coordinates = temp;
        graph.push_back(newvert);
    }
    return(graph);
}


//main method
int main(int argc, char* argv[]) {
    // Ensure proper command line input
    assert(atoi(argv[1]) == 0);
    assert(argc == 5);
    
    int n = atoi(argv[2]);
    int trials = atoi(argv[3]);
    int dimension = atoi(argv[4]);

    double sum_weight;

    // Used for testing
    /*
    time_t my_time = time(NULL); 
    cout << "Start time: " << ctime(&my_time) << endl;
    */

    //makes the magic happen
    for (int i = 0; i < trials; i++)
    {
        vector <Vertex> graph = makeGraph(n, dimension);
        
        cout << primsMSPAN(graph,n,dimension) << endl;
    }
    
    //cout << (sum_weight / trials) << " " << n << " " << trials << " " << dimension << endl;

    // Used for testing
    /*
    time_t your_time = time(NULL); 
    cout << endl << "End time: " << ctime(&your_time) << endl;
    */

    return 0;
}