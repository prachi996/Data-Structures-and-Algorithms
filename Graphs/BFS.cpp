#include<iostream>
#include <list>
 
using namespace std;

class Graph
{
    int V;    // No. of vertices
 
    list<int> *adj;  
    public:
        Graph(int V) {
        this->V = V;
        adj = new list<int>[V];
        }
 
        void add_edge(int u, int v) {
            //Add edge from vertex u to vertex v
            adj[u].push_back(v);
        }
    
        
        void BFS(int s) {
        bool *visited = new bool[V];

        //Mark false to all the nodes
        for(int i = 0; i < V; i++)
            visited[i] = false;
    
        list<int> queue; // Create a queue for BFS
    
        visited[s] = true;
        queue.push_back(s);
    
        list<int>::iterator i;
    
        while(!queue.empty()) {
            s = queue.front(); //Dequeue vertex and print it
            cout<<s<<" ";
            queue.pop_front();

            //Get all adjacent vertices of the dequeued vertex s
            for (i = adj[s].begin(); i != adj[s].end(); ++i) {
                // check if vertex is visited or not
                if (!visited[*i]) {
                    visited[*i] = true;
                    queue.push_back(*i);
                }
            }
        }
    } 
};
 

int main()
{

    Graph g(4);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 2);
    g.add_edge(2, 0);
    g.add_edge(2, 3);
    g.add_edge(3, 3);
 
    cout << "Breadth First Traversal of Graph is given as: \n";
    g.BFS(2);
 
    return 0;
}