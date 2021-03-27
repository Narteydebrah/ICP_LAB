#include "Labwork_8.h"
#include <iostream>

using namespace std;

int i, j;

void lowertriangular(int matrix[3][3], int row, int col){


    for (i = 0; i < row; i++   )
    {
        for (j = 0; j < col; j++)
        {
            if (i < j)
            {
                cout << "0" << " ";
            }
            else
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}


int main(){
    int B[8];
    int matrix[3][3] = {{4,0,0},
                         {0,4,0},
                         {0,0,4}};
    int row =3, col =3;
    cout<<"lower triangular matrix:\n";
    lowertriangular(matrix, row, col);


}


