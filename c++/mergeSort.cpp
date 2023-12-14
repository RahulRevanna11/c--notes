#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void merge( vector<int> arr, int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int first[n1];
    int second[n2];
    for (int i = 0; i < n1; i++)
    {

        first[i] = arr[l + i];
    }
    for (int i = 0; i <= n2; i++)
    {
        second[i] = arr[m + i + 1];
    }
    int i = 0, j = 0, k = 0;
    int res[n1 + n2];
    while (i < n1 && j < n2)
    {
        if (arr[l + i] <= arr[m + j + 1])
        {
            res[k++] = arr[l + i];
            i++;
        }
        else
        {
            res[k++] = arr[m + j + 1];
            j++;
        }
    }
    while (i < n1)
    {
        res[k++] = arr[l + i];
        i++;
    }
    while (j < n2)
    {
        res[k++] = arr[m + i];
        j++;
    }
    k = 0;
    for (int p = l; p <= r; p++)
    {
        arr[p] = res[k++];
    }
}
void mergeSort( vector<int> arr, int i, int j)
{
    if (i < j)
    {
        int mid = i + (j - i) / 2;
        cout<<"subList before sorting: ";

        for (int p = i; p <= mid; p++)
        {
            cout << arr[p]<<" ";
        }
        cout << " ";
        for (int p = mid+1; p <= j; p++)
        {
            cout << arr[p]<< " ";
        }
        cout << endl<<endl;
        mergeSort(arr, i, mid);
        mergeSort(arr, mid + 1, j);

        merge(arr, i, mid, j);
        cout<<"subList after sorting : ";
        for (int p = i; p <= mid; p++)
        {
            cout << arr[p]<< " ";
        }
        cout << " ";
        for (int p = mid+1; p <= j; p++)
        {
            cout << arr[p]<< " ";
        }
        cout << endl<<endl;
    }
}
int main()
{
    int n=200;
   
      map<int,int>m;
    vector<int> arr; 
     for(int i=0;arr.size()<6;i++)
 {
    int a=rand()%200;
   
  if(m.find(a)==m.end())
    arr.push_back(a);
    m[a]++;
 }
      

    mergeSort(arr, 0, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }
}
