#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "AdjacencyList.h"

using namespace std;

int main() {

    
    int no_of_lines, power_iterations;
    string from, to;
    cin >> no_of_lines;
    cin >> power_iterations;

    AdjacencyList graph;

    
    for(int i = 0; i < no_of_lines; i++) {
        // this takes input about 2 websites. "to" and "from" and checks if the websites are unique
        // if they are unique, then add them to a vector of unique websites.

        cin >> from;
        graph.addWebsite(from);

        cin >> to;
        graph.addWebsite(to);
        
        // Do Something

        graph.addEdge(from, to);

    }
    
    graph.PageRank(power_iterations);

}