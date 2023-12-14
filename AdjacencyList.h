#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <list>
#include <set>
using namespace std;

/*
For adjacency list in stepik, i used  map<int, list<pair<int, int>>> adjacencyGraph. 
I would change it to map<string, list<pair<string, float>>> or something like this
*/


class AdjacencyList {
    private:
    
    // Total number of pages 
    int numVertices;

    // This vector keeps track of unique websites.
    set<string> Websites;

    // Maybe do a map with each vertice, and the value is a list of "to" websites
    //map<string, list<string>> graph

    // stores the out degree of each website categorized by name. pageweight / int for each page
    map<string, int> outDegree;

    // stores the in degree of each website categorized by name
    map<string, vector<string>> inDegree;

    // stores the rank of each categorized by name
    map<string, float> pageRanking;

    public:

    AdjacencyList();    // constructor

    void addWebsite(string site);       // this adds website to vectors to keep track of unique websites

    void addEdge(string fromPage, string toPage);   // adds an edge to 'from' site to 'to' site

    void printPageRank();   // prints page and rank by format designated in assingment document

    // prints the pagerank of all pages after p powerIterations in ascending alphabetical order of webpages and rounding to two places
    void PageRank(int n);      

    // return number of unique websites
    int getNumSites();

    


};
