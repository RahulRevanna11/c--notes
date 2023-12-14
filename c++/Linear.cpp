#include <bits/stdc++.h>
using namespace std;
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
      cout << "Comparing with element at index " << i << ": " << arr[i] << std::endl;

        if (arr[i] == key) {
            return i;
        }
    }
    return -1; 
}

int main() {
   
    set<int> st;

    srand(time(0));
    while(st.size() != 100){
        st.insert(rand() % 1000 + 1);
    }

    set<int>::iterator it;
    int k=0;
    int n=100;
    int arr[100];
    for (it = st.begin(); it != st.end(); it++){
        arr[k++]=*it;
    }

    int key=10;

    int result = linearSearch(arr, n, key);

    if (result != -1) {
       cout << "Element found at index " << result << std::endl;
    } else {
      cout << "Element not found in the array." << std::endl;
    }

    return 0;
}
