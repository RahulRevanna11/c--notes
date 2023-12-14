// #include <bits/stdc++.h> 
// using namespace std;


// void knapSack(int W, int wt[], int val[], int n) {

// 	vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));	

// 	for (int i = 0; i <= n; i++)
// 		dp[i][0] = 0;
// 	for (int i = 0; i <= W ; i++)
// 		dp[0][i] = 0;

// 	for (int i = 1; i <= n; i++){
// 		for (int j = 1; j <= W ; j++){
			
// 			if(wt[i-1] <= j){
// 				dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
// 			}
// 			else
// 				dp[i][j] = dp[i - 1][j];
// 		}
// 	}
// 	cout << "Maximum capacity: " << dp[n][W] << endl;

// 	cout << "Items to be included are: " << endl;
// 	for (int i = n  ; i > 0; i--){

// 		if(dp[i-1][W] == dp[i][W])
// 			continue;
// 		else{
// 			cout << "{"<<wt[i - 1] << ", "<< val[i - 1] << "}" << endl;
// 			W -= wt[i - 1];
// 		}
		
// 	}
// } 


// int main() { 

// 	int profit[] = { 3,4,5,6 }; 
// 	int weight[] = { 2,3,4,5}; 

// 	int W = 5; 
// 	int n = sizeof(profit) / sizeof(profit[0]);

// 	knapSack(W, weight, profit, n);

// 	return 0; 
// }

#include <iostream>
#include <vector>

using namespace std;

int knapsackRecursion(vector<int>& weights, vector<int>& values, int capacity, int n, vector<int>& includedItems) {
    if (n == 0 || capacity == 0) {
        return 0;
    }
      cout<<weights[n-1]<<endl;
    if (weights[n - 1] > capacity) {
        return knapsackRecursion(weights, values, capacity, n - 1, includedItems);
    }

    int include = values[n - 1] + knapsackRecursion(weights, values, capacity - weights[n - 1], n - 1, includedItems);
    int exclude = knapsackRecursion(weights, values, capacity, n - 1, includedItems);
cout<<max(include,exclude);
    if (include > exclude) {
        includedItems.push_back(n - 1); // Index of the included item
		
        return include;
    } else {
        return exclude;
    }
}

int main() {
    vector<int> weights = {2, 3, 4, 5};
    vector<int> values = {3, 4, 5, 6};
    int capacity = 9;
    int n = weights.size();

    vector<int> includedItems;
    int maxValue = knapsackRecursion(weights, values, capacity, n, includedItems);

    cout << "Maximum value that can be obtained: " << maxValue << endl;

    cout << "Items included in the knapsack: ";
    for (int i = includedItems.size() - 1; i >=0; --i) {
        cout << includedItems[i] << " ";
    }
    cout << endl;

    return 0;
   
}
