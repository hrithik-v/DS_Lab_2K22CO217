// 63. Depth First Search (DFS) Traversal

#include <iostream>
#include <vector>
#include <queue>
using namespace std;


// -------Utility Fn(s)----------
vector <vector <int>> createGraph();
void printAdjList(vector <vector <int>>);
// ------------------------------


void DFSutil(int X, vector <int> &visited, vector <vector<int>> adj){
    cout<<X<<" ";
    visited[X] = 1;
    
    for (auto i : adj[X]){
        if (!visited[i]){
            DFSutil(i, visited, adj);
        }
    }
    return;
    
}

void dfsOfGraph(vector<vector<int>> adj) {
    
    vector <int> visited(adj.size(),0);
    DFSutil(0, visited, adj);
    
    return;
}

int main(){
    vector <vector <int>> adj = createGraph();
    cout<<"\nAdjacency List: \n";
    printAdjList(adj);  

    cout<<endl<<"DFS Traversal: \n";

    dfsOfGraph(adj);
}

// ---------------------------------------------------------------

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

void printAdjList(vector <vector <int>> adj){
    for (int i = 0 ;i< adj.size();i++){
        cout<<i<<"-> ";
        for (auto j: adj[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return;
}