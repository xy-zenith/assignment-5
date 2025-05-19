#include <iostream>
#include <string>
#include <vector>
//#include <ctime>
//#include <random>
#include "Graph.h"
#include "LinkedBagDS/LinkedBag.h"
#include "Product.h"

using namespace std;

int main()
{
	vector<Product> products; //create vector for products
	products.emplace_back("Monitor", "20-inch monitor", 3.3, 74); //create products
	products.emplace_back("Mouse", "Wireless mouse", 4.1, 123);
	products.emplace_back("Keyboard", "Wireless keyboard with blue switches", 4.7, 81);
	products.emplace_back("Headset", "USB headset", 3.9, 111);
	products.emplace_back("Laptop", "High performance laptop", 4.4, 101);
	products.emplace_back("Game controller", "Wired controller for PC", 3.5, 66);
	products.emplace_back("Webcam", "HD webcam", 3.6, 55);
	products.emplace_back("Batteries", "AA batteries 8-pack", 4.4, 202);
	products.emplace_back("Microphone", "USB microphone", 4.1, 64);
	products.emplace_back("Printer", "All-in-one printer", 4.5, 99);

	//srand(time(0)); //random seed

	/* undirected graph because the graph represents the products that had been purchased together
	*  if product A is purchase together with product B
	*  product B is also purchase with product A in the same transaction
	*  therefore the relationship should be represented by undirected graph
	*/
	Graph<int> productGraph(products.size(), 0); //create graph

	productGraph.addEdge(0, 1, 41); //create edges with weights
	productGraph.addEdge(0, 2, 20);
	productGraph.addEdge(0, 3, 12);
	productGraph.addEdge(0, 5, 7);
	productGraph.addEdge(0, 6, 11);
	productGraph.addEdge(0, 8, 19);
	productGraph.addEdge(0, 9, 9);
	productGraph.addEdge(1, 2, 35);
	productGraph.addEdge(1, 3, 24);
	productGraph.addEdge(1, 4, 66);
	productGraph.addEdge(1, 7, 81);
	productGraph.addEdge(2, 3, 4);
	productGraph.addEdge(2, 7, 50);
	productGraph.addEdge(3, 4, 49);
	productGraph.addEdge(4, 9, 10);
	productGraph.addEdge(6, 8, 21);

	// Print the adjacency list
	productGraph.printGraph();

	int start = 0;
	productGraph.DFT(start, products);// Call DFT 

	bool found = false;
	// Depth First search
	string prodName1 = "Laptop"; //replace with a product nanme that exists 
	found = productGraph.DFS(start, prodName1, products);
	if (found)
		cout << prodName1 << " has been found in the graph!" << endl;
	else
		cout << prodName1 << " has not been found in the graph!" << endl;

	string prodName2 = "Book"; //replace with a product nanme that DOES NOT exist 
	found = productGraph.DFS(start, prodName2, products);
	if (found)
		cout << prodName2 << " has been found in the graph!" << endl;
	else
		cout << prodName2 << " has not been found in the graph!" << endl;

	return 0;
}