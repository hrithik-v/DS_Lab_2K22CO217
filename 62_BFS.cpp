// 62. Breadth First Search (BFS) Traversal

#include <iostream>
#include <vector>
#include <queue>
using namespace std;


// -------Utility Fn(s)----------
vector <vector <int>> createGraph();
void printAdjList(vector <vector <int>>);
// ------------------------------

void bfsOfGraph(vector<vector<int>> adj) {
    queue <int> q;    
    vector <int> visited(adj.size(),0);
    
    q.push(0);  // starting from Node 0
    visited[0] = 1;
    
    while(!q.empty()){
        int f = q.front();
        cout<<f<<" ";
        
        for (auto i:adj[f]){
            if (!visited[i]){
                visited[i] = 1;
                q.push(i);
            }
        }
        
        q.pop();
    }
    
    return;
}


int main(){
    vector <vector <int>> adj = createGraph();
    cout<<"\nAdjacency List: \n";
    printAdjList(adj);  

    cout<<endl<<"BFS Traversal: \n";

    bfsOfGraph(adj);
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