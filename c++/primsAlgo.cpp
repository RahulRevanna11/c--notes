
#include <bits/stdc++.h>
using namespace std;


#define V 5


int minKey(int key[], bool mstSet[])
{
	
	int min = INT_MAX, min_index;
cout<<"next possible set nodes: ";
	for (int v = 0; v < V; v++)
	{
		if(!mstSet[v])
			cout<<"( "<<v<<","<<key[v]<<")  ";
		if (mstSet[v] == false && key[v] < min)
	
		{	
			min = key[v], min_index = v;
          
          

        }}
        cout<<endl;
        cout<<"next taken node:"<<min_index<<endl;

	return min_index;
}


void printMST(int parent[], int graph[V][V])
{
	int totalcost=0;
	// cout << "Edge \tWeight\n";
	for (int i = 1; i < V; i++)
		{cout << parent[i] << " - " << i << " \t";
			// << graph[i][parent[i]] << " \n";
		totalcost+=graph[i][parent[i]];	}
			cout<<"total cost for mst:"<<totalcost;
}


void primMST(int graph[V][V])
{

	int parent[V];


	int key[V];

	
	bool mstSet[V];

	
	for (int i = 0; i < V; i++)
		key[i] = INT_MAX, mstSet[i] = false;

	
	key[0] = 0;

	
	parent[0] = -1;

   cout<<"parent array: "<<endl;
   for(int i=0;i<V;i++)
   {
    cout<<parent[i]<<" ";
   }
   cout<<endl;
    cout<<"cost array: "<<endl;
   for(int i=0;i<V;i++)
   {
    cout<<key[i]<<" ";
   }
   cout<<endl<<endl<<endl;
	
	for (int count = 0; count < V - 1; count++) {
		
		
		int u = minKey(key, mstSet);

		mstSet[u] = true;

		
		cout<<"adjacent nodes: ";
		for (int v = 0; v < V; v++)
{
		
          
			if (graph[u][v] && mstSet[v] == false
				&& graph[u][v] < key[v])
			{	
                parent[v] = u, key[v] = graph[u][v];
                 cout<<"( "<<v<<","<<key[v]<<")";

                }
                }
                cout<<endl;

                   cout<<"parent array: "<<endl;
   for(int i=0;i<V;i++)
   {
    cout<<parent[i]<<" ";
   }
   cout<<endl;
    cout<<"cost array: "<<endl;
   for(int i=0;i<V;i++)
   {
    cout<<key[i]<<" ";
   }
   cout<<endl<<endl<<endl;
	}
	printMST(parent, graph);
}

int main()
{
	int graph[V][V] = { { 0, 2, 0, 6, 0 },
						{ 2, 0, 3, 8, 5 },
						{ 0, 3, 0, 0, 7 },
						{ 6, 8, 0, 0, 9 },
						{ 0, 5, 7, 9, 0 } };

	primMST(graph);

	return 0;
}


