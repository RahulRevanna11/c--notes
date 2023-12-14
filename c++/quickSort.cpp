#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;


int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];  
    int i = (low - 1);  

    for (int j = low; j <= high - 1; j++) {
       
        if (arr[j] <= pivot) {
            i++;  
            swap(arr[i], arr[j]); 
        }
    }

    swap(arr[i + 1], arr[high]);  
    return (i + 1);  
}


void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
      
        int pivotIdx = partition(arr, low, high);

 cout<<"before sorting "<<endl;
        for(int i=low;i<pivotIdx;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<"-";
        cout<<arr[pivotIdx];
        cout<<"-";
        for(int i=pivotIdx+1;i<=high;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        quickSort(arr, low, pivotIdx - 1);
        quickSort(arr, pivotIdx + 1, high);

        cout<<"after sorting "<<endl;
         for(int i=low;i<pivotIdx;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<"-";
        cout<<arr[pivotIdx];
        cout<<"-";
        for(int i=pivotIdx+1;i<=high;i++)
        {
            cout<<arr[i]<<" ";
        }
         cout<<endl<<arr[pivotIdx];
        cout<<endl;
    }
}

int main() {
    int n;
    map<int,int>m;
    vector<int> arr; 
     for(int i=0;arr.size()<=100;i++)
 {
    int a=rand()%200;
   
  if(m.find(a)==m.end())
    arr.push_back(a);
    m[a]++;
 }
     n=arr.size();
    

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
