#include <iostream>
using namespace std;

const int MAX = 10;

// Function to input a matrix
void inputMatrix(int matrix[][MAX], int rows, int cols)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            cin >> matrix[i][j];
        }
    }
}

// Function to display a matrix
void displayMatrix(int matrix[][MAX], int rows, int cols)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

// Matrix Addition
void addMatrix(int A[][MAX], int B[][MAX], int rows, int cols)
{
    int C[MAX][MAX];

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    cout << "\nResult of Addition:\n";
    displayMatrix(C, rows, cols);
}

// Matrix Multiplication
void multiplyMatrix(int A[][MAX], int B[][MAX],
                    int r1, int c1, int r2, int c2)
{
    if(c1 != r2)
    {
        cout << "\nMatrix multiplication is not possible!\n";
        return;
    }

    int C[MAX][MAX] = {0};

    for(int i = 0; i < r1; i++)
    {
        for(int j = 0; j < c2; j++)
        {
            for(int k = 0; k < c1; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    cout << "\nResult of Multiplication:\n";
    displayMatrix(C, r1, c2);
}

// Matrix Transpose
void transposeMatrix(int A[][MAX], int rows, int cols)
{
    int T[MAX][MAX];

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            T[j][i] = A[i][j];
        }
    }

    cout << "\nTranspose Matrix:\n";
    displayMatrix(T, cols, rows);
}

int main()
{
    int choice;
    int A[MAX][MAX], B[MAX][MAX];
    int r1, c1, r2, c2;

    do
    {
        cout << "\n===== MATRIX OPERATIONS =====\n";
        cout << "1. Matrix Addition\n";
        cout << "2. Matrix Multiplication\n";
        cout << "3. Matrix Transpose\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "Enter rows and columns of matrices: ";
                cin >> r1 >> c1;

                cout << "Enter Matrix A:\n";
                inputMatrix(A, r1, c1);

                cout << "Enter Matrix B:\n";
                inputMatrix(B, r1, c1);

                addMatrix(A, B, r1, c1);
                break;

            case 2:
                cout << "Enter rows and columns of Matrix A: ";
                cin >> r1 >> c1;

                cout << "Enter rows and columns of Matrix B: ";
                cin >> r2 >> c2;

                cout << "Enter Matrix A:\n";
                inputMatrix(A, r1, c1);

                cout << "Enter Matrix B:\n";
                inputMatrix(B, r2, c2);

                multiplyMatrix(A, B, r1, c1, r2, c2);
                break;

            case 3:
                cout << "Enter rows and columns of Matrix: ";
                cin >> r1 >> c1;

                cout << "Enter Matrix:\n";
                inputMatrix(A, r1, c1);

                transposeMatrix(A, r1, c1);
                break;

            case 4:
                cout << "Exiting Program...\n";
                break;

            default:
                cout << "Invalid Choice!\n";
        }

    } while(choice != 4);

    return 0;
}