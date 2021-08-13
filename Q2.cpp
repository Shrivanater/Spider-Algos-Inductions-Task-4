#include <iostream>
#include<climits>
 
const int V = 100;

using namespace std;
 
int minDist(int dist[], bool mstSet[]){
    int min = INT_MAX, min_index;
 
    for(int v = 0; v < V; v++){
        if (mstSet[v] == false && dist[v] < min){
            min = dist[v];
			min_index = v;
		}
	}
	
    return min_index;
}
 
void addEdge(int graph[V][V], int u, int v, int w){
	graph[u-1][v-1] = w;
	graph[v-1][u-1] = w;
} 
 
int primMST(int graph[V][V], int &count, int N){
    int parent[V];
    int dist[V];
    bool mstSet[V];
    int i, j, u;
 
    for(i = 0; i < V; i++){
        dist[i] = INT_MAX;
		mstSet[i] = false;
	}
        
    dist[0] = 0;
    parent[0] = -1; 
 
    for(i = 0; i < V - 1; i++){
        u = minDist(dist, mstSet);
        mstSet[u] = true;

        for(j = 0; j < V; j++){
			if (graph[u][j] && mstSet[j] == false && graph[u][j] < dist[j]){
				parent[j] = u;
				dist[j] = graph[u][j];
			}	           
		}           
    }
    
    for(i = 1; i < N; i++){
        if(graph[i][parent[i]] != 0){
        	count++;
		}
	}
	
	return count;
}

int main(){
	int N, M, u, v, w, i, count = 0, graph[V][V] = {{0}};
	
	cin >> N >> M;
	
	for(i = 0; i < M; i++){
		cin >> u >> v >> w;
		addEdge(graph, u, v, w);
	}

	for(i = 0; i < N; i++){
		cout << endl;
		for(int j = 0; j < N; j++)
		cout << graph[i][j] << "\t";
	}
	cout << endl;
    cout << M - primMST(graph, count, N);
}
