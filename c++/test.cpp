#include<iostream>
#define NODE 5
using namespace std;
int path[NODE];
int graph[NODE][NODE] = {
   {0, 1, 0, 1, 0},
   {1, 0, 1, 1, 1},
   {0, 1, 0, 0, 1},
   {1, 1, 0, 0, 1},
   {0, 1, 1, 1, 0},
};
void displayCycle() {
   cout<<"Cycle: ";

   for (int i = 0; i < NODE; i++)
      cout << path[i] << " ";
   cout << path[0] << endl;      
}

bool isValid(int v,int k)
{
  if(graph[path[k-1]][v]==0)
  return false;
  for (int i = 0; i < k; i++)   
      if (path[i] == v)
         return false;
   return true;
}
bool cycleFound(int k)
{
if(k==NODE)
{
  if (graph[path[k-1]][ path[0] ] == 1 )
         return true;
      else
         return false; 
}
for(int i=0;i<NODE;i++)
{
path[k]=i;
if(isValid(i,k))
{if(cycleFound(k+1)==true)
return true;
path[k]=-1;
}
}
return false;
}

bool hamiltonianCycle()
{
  for(int i=0;i<NODE;i++)
  {
    path[i]=-1;
    path[0]=0;
  }
  if(cycleFound(1)==false)
  return false;
  displayCycle();
  return true;
}

int main() {
   hamiltonianCycle();
}