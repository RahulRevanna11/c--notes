#include <bits/stdc++.h>
using namespace std;
#define V 4

void printSolution(int dist[][V]);

void fw(int dist[][V]){
 for (int k = 0; k < V; k++) {

cout << "Using " << k << " as intermediate node" << endl;
 for (int i = 0; i < V; i++) {

 for (int j = 0; j < V; j++) {

if ((dist[k][j] != 9999 && dist[i][k] != 9999) && (dist[i][j] > (dist[i][k] + dist[k][j]))){
 dist[i][j] = dist[i][k] + dist[k][j];
 }
}
 }
 printSolution(dist);
 cout << endl ;
 }

 printSolution(dist);
}

void printSolution(int dist[][V]){

cout << "The solution matrix is : " << endl;

for (int i = 0; i < V; i++) {
 for (int j = 0; j < V; j++) {
if (dist[i][j] == 9999)
 cout << "INF" << "\t";
 else
cout << dist[i][j] << "\t";
}
cout << endl;
}
}

int main(){

int graph[V][V] = { { 0, 3, 9999, 7},
{ 8, 0, 2, 9999 },
{ 4, 9999, 0, 1 },
 {2, 9999, 9999, 0} };

fw(graph);
return 0;
}
