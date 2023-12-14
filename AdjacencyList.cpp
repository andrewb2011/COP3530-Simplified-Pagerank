#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <iomanip>
#include "AdjacencyList.h"


/* ===================== CONSTRUCTOR ===================== */
AdjacencyList::AdjacencyList() {}

/* ===================== ADDER ===================== */
void AdjacencyList::addWebsite(string site) {
    // this adds unique website to a set. for testing purposes
    
    Websites.insert(site);

}

void AdjacencyList::addEdge(string from, string to) {

    // both of these add a new entry to respective maps if website is not in there.

    outDegree[from]++; // incrememnts the number of websites going outwards to calculate pagerank;
    inDegree[to].push_back(from); // adds "from" to a vector of "from" sites for each vertice

    // next we need to add "to" to outdegree and "from" to indegree maps if they are not in there already

    outDegree[to];
    inDegree[from];

}
/* ===================== PRINTER FUNCTION ===================== */
void AdjacencyList::printPageRank() {

    // goes through pageRanking map and prints the site in order and the rank of each site.
    //for (auto site : pageRanking)
    //    cout << setprecision(2) << fixed << site.first << " " << site.second << endl;
    
    for (auto site : Websites) 
        cout << setprecision(2) << fixed << site << " " << pageRanking[site] << endl;


}

void AdjacencyList::PageRank(int n) {

    // This is step 2 in the documentation. Every site starts as 1/|V|, |V| = number of unique sites
    for (auto vertice : inDegree) 
        pageRanking[vertice.first] = 1.0f / (float)getNumSites();
    
    //This is used for testing purposes to see if all websites are in taken correctly
    /*cout << "----------------" << endl;
    for (string site : Websites) {
        cout << site << endl;
    }*/

    // this prints rank in n = 1. just prints 1 / (# of pages) for each page.
    if (n == 1) {
        for (auto rank : pageRanking) {
            cout << setprecision(2) << fixed << rank.first << " " << rank.second << endl;
        }

    }
    else{   // if n > 1, then this runs.

        // This is used to store previous iterations before it goes through power iters.
        map<string, float> tempMap;

        // if n > 1, then this runs
        for (int i = 1; i < n; ++i) {
            tempMap = pageRanking;

            //for (auto webpage : inDegree) {
            for (auto iter = inDegree.begin(); iter != inDegree.end(); ++iter) {

                float rank = 0.0f;
                for (auto IncomingLink : iter->second) {
                    rank += (1.0f / (float)outDegree[IncomingLink]) * pageRanking[IncomingLink];
                }
                tempMap[iter->first] = rank;

            }
            // update the pageranking for next iteration
            pageRanking = tempMap;

        }
        // prints unique sites and ranking based on format in assignment instructions
        printPageRank();
    }
}



int AdjacencyList::getNumSites() {

    return Websites.size();

}