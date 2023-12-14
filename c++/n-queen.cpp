#include <bits/stdc++.h>
using namespace std;

int N;
void printSolution(vector<vector<int>> &board){
	
    cout << endl << "Solution Matrix is : " << endl;
    for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
		if(board[i][j])
			cout << "Q ";
		else cout<<"* ";
		printf("\n");
	}
    cout<<"{ "; 
      for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
		if(board[i][j])
			cout <<j<< " ";
	}
    cout<<"} "<<endl;
}


bool isSafe(vector<vector<int>> &board, int row, int col){

	int i, j;

	for (i = 0; i < col; i++)
		if (board[row][i])
			return false;

	for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
		if (board[i][j])
			return false;

	for (i = row, j = col; j >= 0 && i < N; i++, j--)
		if (board[i][j])
			return false;

	return true;
}

bool solveNQUtil(vector<vector<int>> &board, int col)
{
	
	if (col >= N){
		return true;
	}

	for (int i = 0; i < N; i++) {
		
		
		if (isSafe(board, i, col)) {
			
			board[i][col] = 1;
            // cout << "Placing Queen in " << i << "th row and " << col << "th column." << endl;

            if (solveNQUtil(board, col + 1)){
				printSolution(board);
			}
				

			board[i][col] = 0;
            // cout << "Placing Queen in " << i << "th row and " << col << "th column doesn't work so removing queen from this place." << endl;
            // back
		}
	}
    // cout << "Cannot place queen in the " << col<< "th column." << endl;
    return false;
}


bool solveNQ()
{
    cout << "Enter n: ";
    cin >> N;

    vector<vector<int>> board(N, vector<int>(N, 0));

    if (solveNQUtil(board, 0) == false)
    {
        cout << "Solution does not exist";
        return false;
    }

	return true;
}

int main()
{
	solveNQ();
	return 0;
}
