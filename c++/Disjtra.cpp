
// #include <bits/stdc++.h>
// using namespace std;
// #define INF 9999

// typedef pair<int, int> iPair;

// class Graph {
// 	int V; 
// 	list<pair<int, int> >* adj;

// public:
// 	Graph(int V); 

// 	void addEdge(int u, int v, int w);

	
// 	void shortestPath(int s);
// };


// Graph::Graph(int V)
// {
// 	this->V = V;
// 	adj = new list<iPair>[V];
// }

// void Graph::addEdge(int u, int v, int w)
// {
// 	adj[u].push_back(make_pair(v, w));
// 	adj[v].push_back(make_pair(u, w));
// }

// // Prints shortest paths from src to all other vertices
// void Graph::shortestPath(int src)
// {
// 	priority_queue<iPair, vector<iPair>, greater<iPair> >
// 		pq;

// 	vector<int> dist(V, INF);


// 	pq.push(make_pair(0, src));
// 	dist[src] = 0;

// 	while (!pq.empty()) {
	
//                   cout<<"Node Selected : "<<pq.top().second<<"  Weight :"<<pq.top().first<<endl;


// 		int u = pq.top().second;
// 		pq.pop();
	
//         cout<<"distance array before updation : \n";
//         for(int i=0;i<V;i++) cout<<i<<":"<<dist[i]<<"\n";
       

// 		list<pair<int, int> >::iterator i;
// 		for (i = adj[u].begin(); i != adj[u].end(); ++i) {
		
// 			int v = (*i).first;
// 			int weight = (*i).second;

// 			if (dist[v] > dist[u] + weight) {

// 				dist[v] = dist[u] + weight;
// 				pq.push(make_pair(dist[v], v));

// 			}
            
// 		}
//          cout<<"distance after  updation : \n";

//         for(int i=0;i<V;i++) cout<<i<<":"<<dist[i]<<"\n";
 
//         cout<<endl<<endl; 
// 	}

	
// 	printf("Vertex Distance from Source\n");
// 	for (int i = 0; i < V; ++i)
// 		printf("%d \t\t %d\n", i, dist[i]);
// }

// int main()
// {

// 	int V = 9;
// 	Graph g(V);

// 	g.addEdge(0, 1, 4);
// 	g.addEdge(0, 7, 8);
// 	g.addEdge(1, 2, 8);
// 	g.addEdge(1, 7, 11);
// 	g.addEdge(2, 3, 7);
// 	g.addEdge(2, 8, 2);
// 	g.addEdge(2, 5, 4);
// 	g.addEdge(3, 4, 9);
// 	g.addEdge(3, 5, 14);
// 	g.addEdge(4, 5, 10);
// 	g.addEdge(5, 6, 2);
// 	g.addEdge(6, 7, 1);
// 	g.addEdge(6, 8, 6);
// 	g.addEdge(7, 8, 7);


// 	g.shortestPath(0);

// 	return 0;
// }
#include <bits/stdc++.h>
using namespace std;
#define size 7

int minimumDistance(int distance[], bool visited[]) {
  int min = INT_MAX;
  int min_index = INT_MAX;
  for (int i = 0; i < size; i++) {
    if (!visited[i] && distance[i] <= min) {
      min = distance[i];
      min_index = i;
    }
  }
  return min_index;
}

void printParentPath(int parent[], int i) {
  if (parent[i] == -1) {
    return;
  }
  printParentPath(parent, parent[i]);
  cout << i + 1 << " ";
}

void dijkstra(int graph[size][size], int source, int target) {
  int distance[size];
  bool visited[size];
  int parent[size];
  
  for (int i = 0; i < size; i++) {
    parent[i] = -1;
    distance[i] = INT_MAX;
    visited[i] = false;
  }

  distance[source] = 0;
  for (int step = 0; step < size - 1; step++) {
   
    int U = minimumDistance(distance, visited);
    visited[U] = true;
    cout << "Step " << step + 1 << ": Visit vertex " << U + 1 << endl;
    for (int j = 0; j < size; j++) {
      if (!visited[j] && graph[U][j]) {
        
        int curr_distance = distance[U] + graph[U][j];
        if (curr_distance < distance[j]) {
          parent[j] = U;
          distance[j] = curr_distance;
        }
      }
    }
   
    cout << "Distance Array: ";
    for (int i = 0; i < size; i++) {
      if (distance[i] == INT_MAX) {
        cout << "INF ";
      } else {
        cout << distance[i] << " ";
      }
    }
    cout << endl;
    cout << "Visited Array: ";
    for (int i = 0; i < size; i++) {
      cout << visited[i] << " ";
    }
    cout << endl<<endl;
  }

  cout << "Vertex\t\tDistance\tPath" << endl;
  cout << source + 1 << " to " << target + 1 << ":\n";
  cout << "Shortest Distance: " << distance[target] << endl;
  cout << "Path: " << source + 1 << " ";
  printParentPath(parent, target);
  cout << endl;
}

int main() {
  int graph[size][size] = 
  {{0, 2, 1, 4, 0, 0, 0}, 
  {2, 0, 2, 0, 3, 3, 0},
  {1, 2, 0, 2, 5, 7, 0}, 
  {4, 0, 2, 0, 2, 4, 0},
  {0, 3, 5, 0, 0, 0, 1},
  {0, 0, 7, 4, 0, 0, 3},
  {0, 0, 0, 0, 1, 3, 0}};
  
 int source=1,target=7; 
  
  dijkstra(graph, source-1, target-1);
}
