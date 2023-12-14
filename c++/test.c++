#include<bits/stdc++.h>
using namespace std;
int processArray(int arr[],int n)

{

int i=0;
int sum=-1;
for(int j=0;j<n;j++)
{
   if(sum!=-1&&arr[j]<100)
  { sum+=arr[j];
  continue;}
  else if(sum!=-1)
  {
     arr[i]=sum;
 i++;
 sum=-1;
  }

  if(arr[j]>=100)
 { arr[i]=arr[j];
 i++;}
 else {
    sum=arr[j];

 }
  


}
return  i+1;
}
int main()
{
//     vector<int>arr;
//     int a;
//     cin>>a;
//     arr.push_back(a);
//     int ans=0;
//     if(a<100&&a!=-1)
//     ans=max(ans,a);
//     while(a>=0)
//     {
//         cin>>a;
//         arr.push_back(a);
//  if(a<100&&a!=-1)
//   ans=max(ans,a);
//     }

//     cout<<ans;


int arr[100];
int n=0;
int a=0;
while(a>=0)
{
    cin>>a;
    arr[n]=a;
    n++;

}
 n=processArray(arr,n);
 for(int i=0;i<n;i++)
 {
    cout<<arr[i]<<" ";
 }
 return 0;
}