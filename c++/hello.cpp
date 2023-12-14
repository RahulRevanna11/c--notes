#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;


void printmat(vector<vector<int>> &matrix, int m, int n ,int x=0)
{
  
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }
        
        cout << endl;
    }
}

void add(vector<vector<int>> &A, vector<vector<int>> &B, vector<vector<int>> &C, int size)
{
    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void sub(vector<vector<int>> &A, vector<vector<int>> &B, vector<vector<int>> &C, int size)
{
    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void Strassen_algorithmA(vector<vector<int>> &A, vector<vector<int>> &B, vector<vector<int>> &C, int size)
{
    
    if (size == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }
    else
    {
        int new_size = size / 2;
        vector<int> z(new_size, 0);
        vector<vector<int>> a11(new_size, z), a12(new_size, z), a21(new_size, z), a22(new_size, z),
            b11(new_size, z), b12(new_size, z), b21(new_size, z), b22(new_size, z),
            c11(new_size, z), c12(new_size, z), c21(new_size, z), c22(new_size, z),
            p1(new_size, z), p2(new_size, z), p3(new_size, z), p4(new_size, z),
            p5(new_size, z), p6(new_size, z), p7(new_size, z),
            aResult(new_size, z), bResult(new_size, z);

        int i, j;

      
        for (i = 0; i < new_size; i++)
        {
            for (j = 0; j < new_size; j++)
            {
                a11[i][j] = A[i][j];
                a12[i][j] = A[i][j + new_size];
                a21[i][j] = A[i + new_size][j];
                a22[i][j] = A[i + new_size][j + new_size];

                b11[i][j] = B[i][j];
                b12[i][j] = B[i][j + new_size];
                b21[i][j] = B[i + new_size][j];
                b22[i][j] = B[i + new_size][j + new_size];
            }
        }

      

        add(a11, a22, aResult, new_size); 
        add(b11, b22, bResult, new_size);
        Strassen_algorithmA(aResult, bResult, p1, new_size);
        cout << "p1:" ;
        printmat(p1, new_size, new_size,1);

        add(a21, a22, aResult, new_size); 
        Strassen_algorithmA(aResult, b11, p2, new_size);
        cout << "p2:" ;
        printmat(p2, new_size, new_size,1);

        sub(b12, b22, bResult, new_size); 
        Strassen_algorithmA(a11, bResult, p3, new_size);
        cout << "p3:";
        printmat(p3, new_size, new_size,1);

        sub(b21, b11, bResult, new_size); 
        Strassen_algorithmA(a22, bResult, p4, new_size);
        cout << "p4:" ;
        printmat(p4, new_size, new_size,1);

        add(a11, a12, aResult, new_size); // a11 + a12
        Strassen_algorithmA(aResult, b22, p5, new_size);
        cout << "p5:" ;
        printmat(p5, new_size, new_size,1);

        sub(a21, a11, aResult, new_size);
        add(b11, b12, bResult, new_size); 
        Strassen_algorithmA(aResult, bResult, p6, new_size);
        cout << "p6:" ;
        printmat(p6, new_size, new_size,1);

        sub(a12, a22, aResult, new_size); 
        add(b21, b22, bResult, new_size); 
        Strassen_algorithmA(aResult, bResult, p7, new_size);
        cout << "p7:";
        printmat(p7, new_size, new_size,1);

      

        add(p3, p5, c12, new_size); 
        cout << "c12:" ;
        printmat(c12, new_size, new_size);

        add(p2, p4, c21, new_size); 
        cout << "c21:" ;
        printmat(c21, new_size, new_size,1);

        add(p1, p4, aResult, new_size);      
        add(aResult, p7, bResult, new_size); 
        sub(bResult, p5, c11, new_size);     
        cout << "c11:" ;
        printmat(c11, new_size, new_size,1);

        add(p1, p3, aResult, new_size);      
        add(aResult, p6, bResult, new_size); 
        sub(bResult, p2, c22, new_size);   
        cout << "c22:" ;
        printmat(c22, new_size, new_size,1);

     
        for (i = 0; i < new_size; i++)
        {
            for (j = 0; j < new_size; j++)
            {
                C[i][j] = c11[i][j];
                C[i][j + new_size] = c12[i][j];
                C[i + new_size][j] = c21[i][j];
                C[i + new_size][j + new_size] = c22[i][j];
            }
        }
    }
}

void stresson(vector<vector<int>> &A, vector<vector<int>> &B, int m, int n, int a, int b)
{
    int k = max({m, n, a, b});
    int s = pow(2, int(ceil(log2(k))));;

    vector<int> z(s, 0);
    vector<vector<int>> Aa(s, z), Bb(s, z), Cc(s, z);

    for ( int i = 0; i < m; i++)
    {
        for ( int j = 0; j < n; j++)
        {
            Aa[i][j] = A[i][j];
        }
    }

    for ( int i = 0; i < a; i++)
    {
        for ( int j = 0; j < b; j++)
        {
            Bb[i][j] = B[i][j];
        }
    }

    Strassen_algorithmA(Aa, Bb, Cc, s);

    vector<int> temp1(b);
    vector<vector<int>> C(m, temp1);

    for ( int i = 0; i < m; i++)
    {
        for ( int j = 0; j < b; j++)
        {
            C[i][j] = Cc[i][j];
        }
    }

    cout << "final mat:" << endl;
    printmat(C, m, b);
}

int main()
{
    vector<vector<int>> A = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
    vector<vector<int>> B = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};

    cout << "A:" << endl;
    printmat(A, 3, 3);

    cout << " B:" << endl;
    printmat(B, 3, 3);

    stresson(A, B, 3, 3, 3, 3);

    return 0;
}