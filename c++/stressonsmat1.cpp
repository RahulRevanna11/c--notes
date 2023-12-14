#include <bits/stdc++.h>
using namespace std;

#define ROW_1 4
#define COL_1 4

#define ROW_2 4
#define COL_2 4

void print(string display, vector<vector<int>> matrix,
           int start_row, int start_column, int end_row,
           int end_column)
{
    cout << endl
         << display << " =>" << endl;
    for (int i = start_row; i <= end_row; i++)
    {
        for (int j = start_column; j <= end_column; j++)
        {
            cout << setw(10);
            cout << matrix[i][j];
        }
        cout << endl;
    }
    cout << endl;
    return;
}

vector<vector<int>>
add_matrix(vector<vector<int>> matrix_A,
           vector<vector<int>> matrix_B, int split_index,
           int multiplier = 1)
{
    for (auto i = 0; i < split_index; i++)
        for (auto j = 0; j < split_index; j++)
            matrix_A[i][j] = matrix_A[i][j] + (multiplier * matrix_B[i][j]);
    return matrix_A;
}
// void add_matrix(vector<vector<int>> matrix_A,
//                 vector<vector<int>> matrix_B,
//                 vector<vector<int>> &matrix_C,
//                 int split_index)
// {
//     for (auto i = 0; i < split_index; i++)
//         for (auto j = 0; j < split_index; j++)
//             matrix_C[i][j] = matrix_A[i][j] + matrix_B[i][j];
// }

vector<vector<int>> multiply_matrix(vector<vector<int>> matrix_A,
                                    vector<vector<int>> matrix_B)
{
    int col_1 = matrix_A[0].size();
    int row_1 = matrix_A.size();
    int col_2 = matrix_B[0].size();
    int row_2 = matrix_B.size();

    if (col_1 != row_2)
    {
        cout << "vectors can not ne multiplied";
        return {};
    };

    vector<vector<int>> result_matrix(row_1, vector<int>(col_2, 0));

    if (col_1 == 1)
        result_matrix[0][0] = matrix_A[0][0] * matrix_B[0][0];

    else
    {
        int split_index = col_1 / 2;

        // vector<vector<int>>result_matrix_00(split_index
        // ,vector<int>(split_index
        // ,0));
        // vector<vector<int>>result_matrix_01(split_index
        // ,vector<int>(split_index
        // ,0));
        // vector<vector<int>>result_matrix_10(split_index
        // ,vector<int>(split_index
        // ,0));
        // vector<vector<int>>result_matrix_11(split_index
        // ,vector<int>(split_index
        // ,0));

        vector<vector<int>> a00(split_index, vector<int>(split_index, 0));
        vector<vector<int>> a01(split_index, vector<int>(split_index, 0));
        vector<vector<int>> a10(split_index, vector<int>(split_index, 0));
        vector<vector<int>> a11(split_index, vector<int>(split_index, 0));
        vector<vector<int>> b00(split_index, vector<int>(split_index, 0));
        vector<vector<int>> b01(split_index, vector<int>(split_index, 0));
        vector<vector<int>> b10(split_index, vector<int>(split_index, 0));
        vector<vector<int>> b11(split_index, vector<int>(split_index, 0));

                for (auto i = 0; i < split_index; i++)
            for (auto j = 0; j < split_index; j++) {
                a00[i][j] = matrix_A[i][j];
                a01[i][j] = matrix_A[i][j + split_index];
                a10[i][j] = matrix_A[split_index + i][j];
                a11[i][j] = matrix_A[i + split_index]
                                    [j + split_index];
                b00[i][j] = matrix_B[i][j];
                b01[i][j] = matrix_B[i][j + split_index];
                b10[i][j] = matrix_B[split_index + i][j];
                b11[i][j] = matrix_B[i + split_index]
                                    [j + split_index];
            }


        vector<vector<int>> p(multiply_matrix(
            a00, add_matrix(b01, b11, split_index, -1)));
            if(p.size()>1)
            print("p",p,0,0,p.size()-1,p[0].size()-1);

        vector<vector<int>> q(multiply_matrix(
            add_matrix(a00, a01, split_index), b11));if(q.size()>1)
 print("q",q,0,0,q.size()-1,q[0].size()-1);


        vector<vector<int>> r(multiply_matrix(
            add_matrix(a10, a11, split_index), b00));if(r.size()>1)
 print("r",r,0,0,r.size()-1,r[0].size()-1);
            
        vector<vector<int>> s(multiply_matrix(
            a11, add_matrix(b10, b00, split_index, -1))); if(s.size()>1)
 print("s",s,0,0,s.size()-1,s[0].size()-1);

        vector<vector<int>> t(multiply_matrix(
            add_matrix(a00, a11, split_index),
            add_matrix(b00, b11, split_index)));
if(t.size()>1)
             print("t",t,0,0,t.size()-1,t[0].size()-1);
        vector<vector<int>> u(multiply_matrix(
            add_matrix(a01, a11, split_index, -1),
            add_matrix(b10, b11, split_index)));if(u.size()>1) 
 print("u",u,0,0,u.size()-1,u[0].size()-1);

        vector<vector<int>> v(multiply_matrix(
            add_matrix(a00, a10, split_index, -1),
            add_matrix(b00, b01, split_index)));if(v.size()>1)
 print("v",v,0,0,v.size()-1,v[0].size()-1);


        vector<vector<int>> result_matrix_00(add_matrix(
            add_matrix(add_matrix(t, s, split_index), u,
                       split_index),
            q, split_index, -1));

          if(result_matrix_00.size()>1)   print("result_matrix_00",result_matrix_00,0,0,result_matrix_00.size()-1,result_matrix_00[0].size()-1);
        vector<vector<int>> result_matrix_01(
            add_matrix(p, q, split_index));
           if(result_matrix_01.size()>1)  print("result_matrix_01",result_matrix_01,0,0,result_matrix_01.size()-1,result_matrix_01[0].size()-1);
        vector<vector<int>> result_matrix_10(
            add_matrix(r, s, split_index));
           if(result_matrix_10.size()>1)   print("result_matrix_10",result_matrix_10,0,0,result_matrix_10.size()-1,result_matrix_10[0].size()-1);
        vector<vector<int>> result_matrix_11(add_matrix(
            add_matrix(add_matrix(t, p, split_index), r,
                       split_index, -1),
            v, split_index, -1));
           if(result_matrix_01.size()>1)   print("result_matrix_11",result_matrix_11,0,0,result_matrix_11.size()-1,result_matrix_11[0].size()-1);

        for (auto i = 0; i < split_index; i++)
            for (auto j = 0; j < split_index; j++)
            {
                result_matrix[i][j] = result_matrix_00[i][j];
                result_matrix[i][j + split_index] = result_matrix_01[i][j];
                result_matrix[split_index + i][j] = result_matrix_10[i][j];
                result_matrix[i + split_index]
                             [j + split_index] = result_matrix_11[i][j];
            }

        // for (int i = 0; i < split_index; i++)
        //     for (int_fast16_t j = 0; j < split_index; j++)
        //     {
        //         result_matrix[i][j] = result_matrix_00[i][j];
        //         result_matrix[i][j + split_index] = result_matrix_01[i][j];
        //         result_matrix[split_index + i][j] = result_matrix_10[i][j];
        //         result_matrix[i + split_index]
        //                      [j + split_index] = result_matrix_11[i][j];
        //     }
    }
    return result_matrix;
}

int main()
{
    vector<vector<int>> matrix_A = {{2, 3, 1, 5},
                                    {1, 4, 7, 6},
                                    {8, 2, 3, 9},
                                    {5, 2, 1, 7}};

    print("Array A", matrix_A, 0, 0, ROW_1 - 1, COL_1 - 1);

    vector<vector<int>> matrix_B = {{7, 6, 5, 4},
                                    {8, 1, 2, 3},
                                    {2, 9, 3,5},
                                    {3, 4, 7, 8}};

    print("Array B", matrix_B, 0, 0, ROW_2 - 1, COL_2 - 1);

    vector<vector<int>> result_matrix(
        multiply_matrix(matrix_A, matrix_B));

    print("Result Array", result_matrix, 0, 0, ROW_1 - 1,
          COL_2 - 1);
}
