// 61. Create a graph 

#include <iostream>
#include <vector>
using namespace std;


// This Fn shall return Adjacency List of Undirected Graph
vector <vector <int>> createGraph(){
    int V,E;
    cout<<"No. of Edges: ";
    cin>>E;
    cout<<"No. of Vertices: ";
    cin>>V;

    vector <vector <int>> adj(V);

    for (int i=0;i<E; i++){
        int v1, v2;
        cin>>v1>>v2;

        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }

    return adj;
}


int main(){

    vector <vector <int>> adj = createGraph();

    cout<<"\nAdjacency List: \n";

    for (int i = 0 ;i< adj.size();i++){
        cout<<i<<"-> ";
        for (auto j: adj[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }

    
}