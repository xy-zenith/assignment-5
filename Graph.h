#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <list>
#include <utility>  // For std::pair
#include "LinkedBagDS/LinkedBag.h"
#include "Product.h"

using namespace std;

// Template class for a Graph
template <typename T>
class Graph
{
public:
    // Constructor
    Graph(int vertices, bool directed = false);

    // Add an edge
    void addEdge(int u, int v, T weight = T());

    // Get number of nodes
    int getNumVertices() const;

    // Print the adjacency list
    void printGraph() const;

    // Get neighbors of a vertex
    const LinkedBag<pair<int, T>>& getNeighbors(int vertex) const;

    // Depth First Traversal
    void DFT(int start, vector<Product>& products) const;
    void DFTRecursive(int v, vector<bool>& visited, vector<Product>& products) const;

    // Depth First Search (by product name)
    bool DFS(int start, string& productName, vector<Product>& products) const;
    bool DFSRecursive(int v, vector<bool>& visited, string& productName, vector<Product>& products) const;

private:
    int V; // Number of vertices
    bool directed; // Whether the graph is directed or undirected
    vector<LinkedBag<pair<int, T>>> adjList; // Adjacency list
};

// Include the implementation of template functions
#include "Graph.cpp"

//// Constructor
//template <typename T>
//Graph<T>::Graph(int vertices, bool directed)
//    : V(vertices), directed(directed)
//{
//    adjList.resize(V);
//}
//
//// Add an edge
//template <typename T>
//void Graph<T>::addEdge(int u, int v, T weight)
//{
//    if (u == v)
//        return;
//
//    adjList[u].add({ v, weight });
//
//    if (!directed)
//        adjList[v].add({ u, weight });
//}
//
//// Get number of nodes
//template <typename T>
//int Graph<T>::getNumVertices() const
//{
//    return V;
//}
//
//// Print the adjacency list
//template <typename T>
//void Graph<T>::printGraph() const
//{
//    for (int i = 0; i < V; ++i)
//    {
//        cout << "Vertex " << i << ": ";
//        vector<pair<int, T>> neighborVector = adjList[i].toVector(); //convert to vector for iteration
//        for (const auto& neighbor : neighborVector)
//        {
//            cout << "(" << neighbor.first << ", " << neighbor.second << ") ";
//        }
//        cout << endl;
//    }
//}
//
//// Get neighbors of a vertex
//template <typename T>
//const LinkedBag<pair<int, T>>& Graph<T>::getNeighbors(int vertex) const
//{
//    return adjList[vertex];
//}
//
//
//// DFS Traversal (Recursive approach)
//template <typename T>
//void Graph<T>::DFT(int start, vector<Product>& products) const
//{
//    vector<bool> visited(V, false); // To keep track of visited vertices
//    DFTRecursive(start, visited, products);
//    cout << endl;
//}
//
//// Utility function for DFS (Recursive)
//template <typename T>
//void Graph<T>::DFTRecursive(int v, vector<bool>& visited, vector<Product>& products) const
//{
//    visited[v] = true;
//    cout << products[v] << endl; //print the product information
//
//    // Recur for all the vertices adjacent to this vertex
//    vector<pair<int, T>> neighborVector = adjList[v].toVector(); //convert to vector for iteration
//    for (const auto& neighbor : neighborVector)
//    {
//        if (!visited[neighbor.first])
//            DFTRecursive(neighbor.first, visited, products);
//    }
//}
//
//// Depth First Search (by product name)
//template <typename T>
//bool Graph<T>::DFS(int start, string& productName, vector<Product>& products) const
//{
//    vector<bool> visited(V, false); // To keep track of visited vertices
//    if (DFSRecursive(start, visited, productName, products))
//        return true;
//    return false;
//}
//
//// Utility function for DFS by product name (Recursive)
//template <typename T>
//bool Graph<T>::DFSRecursive(int v, vector<bool>& visited, string& productName, vector<Product>& products) const
//{
//    visited[v] = true;
//    if (products[v].getName() == productName)
//        return true;
//
//    // Recur for all the vertices adjacent to this vertex
//    vector<pair<int, T>> neighborVector = adjList[v].toVector(); //convert to vector for iteration
//    for (const auto& neighbor : neighborVector)
//    {
//        if (!visited[neighbor.first])
//            if (DFSRecursive(neighbor.first, visited, productName, products))
//                return true;
//    }
//
//    return false;
//}

#endif // GRAPH_H