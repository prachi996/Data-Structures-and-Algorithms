// Depth First Search Algorithm for connected graph using Adjacency Matrix

#include <iostream>
#include<map>
#include<list>
#include<iterator>

using namespace std;

class Graph {
    public:
        map<int, int> visited; //A set to store the visited nodes
        map<int, list<int>> adj;

        void add_edge(int u, int v) {
            //Add edge from vertex u to vertex v
            adj[u].push_back(v);
        }

        void DFS(int u) {
            // u is any starting vertex

            visited[u] = true;  
            cout<<u<<" ";

            list<int>::iterator i;
            for(i = adj[u].begin(); i != adj[u].end(); i++) {
                if(!visited[*i]) {
                    //If the node isn't visited perform DFS on that node
                    DFS(*i);
                }
            }
        }
};


int main() {
    Graph G;
    G.add_edge(10, 20);
    G.add_edge(10, 30);
    G.add_edge(20, 30);
    G.add_edge(30, 10);
    G.add_edge(30, 40);
    G.add_edge(40, 40);

    cout<<"Depth First Traversal of Graph is given as: \n";
    G.DFS(20);

    return 0;
}