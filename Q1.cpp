#include<iostream>
#include<map>
#include<list>

using namespace std;

int n, i;

class Graph{
	public:
		map<int, bool> visited;
		map<int, list<int>> adj;
		int visit = 0;
		int route = 0;
		
		void addEdge(int a, int b);
		void DFS(int x);
};

void Graph :: addEdge(int a, int b){
	adj[a].push_back(b);
}

void Graph :: DFS(int x){
	visited[x] = true;
	visit++;	
	
	if(visit == n){
		route++;
	}	
	
	list<int> :: iterator j;			
	for(j = adj[x].begin(); j != adj[x].end(); j++){
		if(!visited[*j]){
			DFS(*j);
			visited[*j] = false;
		}
	}	
	
	visit--;		
}

int main(){
	int m, a, b;
	Graph cities;

	cin >> n >> m;
		
	for(i = 0; i < m; i++){
		cin >> a >> b;
		cities.addEdge(a, b);
		cities.addEdge(b, a);
	}
	
	cities.DFS(1);
	
	cout << cities.route;
}
