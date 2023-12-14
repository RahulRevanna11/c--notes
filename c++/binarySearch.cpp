#include<iostream>
#include<vector>
#include<algorithm>
#include <bits/stdc++.h>
using namespace std;

int main()
{
  map<int,int>m;
    vector<int> arr; 
     for(int i=0;arr.size()<=20;i++)
 {
    int a=rand()%200;
   
  if(m.find(a)==m.end())
    arr.push_back(a);
    m[a]++;
 }
 sort(arr.begin(),arr.end());
 int i=0,j=arr.size()-1;
 int key=arr[0];
 int counter=0;
 while(i<j)
 {counter++;

    int mid=i+(j-i)/2;
     for(int k=i;k<=j;k++)
    {
        if(k==mid)
        cout<<"-"<<arr[mid]<<"- ";
        else cout<<arr[k]<<" ";
    }
    cout<<endl;
    if(arr[mid]==key)
    {
        cout<<key<<" found at index "<<mid;
     break;
    }
    else if(arr[mid]>key)
    j=mid-1;
    else i=mid+1;
    // cout<<mid;
    if(i>=j)
    cout<<"key element not found"<<endl;
    
   
 }
 cout<<"size of list space "<< arr.size()<<endl<<"no of comparison "<<counter;

 
return 0;
}