// Sudoku Solver
#include <bits/stdc++.h>
using namespace std;
// N is used for size of Sudoku grid. Size will be NxN
int N; 
int SQN;

// This function finds an entry in grid that is still unassigned
bool FindUnassignedLocation(vector<vector<int> >&grid, int &row, int &col);

// Checks whether it will be legal to assign num to the given row,col
bool isSafe(vector<vector<int> >&grid, int row, int col, int num);

/* Takes a partially filled-in grid and attempts to assign values to
  all unassigned locations in such a way to meet the requirements
  for Sudoku solution (non-duplication across rows, columns, and boxes) */
bool SolveSudoku(vector<vector<int> >&grid)
{
    int row, col;

    // If there is no unassigned location, we are done
    if (!FindUnassignedLocation(grid, row, col))
       return true; // success!

    // consider digits 1 to N
    for (int num = 1; num <= N; num++)
    {
        if (isSafe(grid, row, col, num))
        {
            // make tentative assignment
            grid[row][col] = num;

            // return, if ans found
            if (SolveSudoku(grid))
                return true;

            // if ans not found, then back track
            grid[row][col] = 0;
        }
    }
    return false; // this triggers backtracking
}

/* Searches the grid to find an entry that is still unassigned. */
bool FindUnassignedLocation(vector<vector<int> >&grid, int &row, int &col)
{
    for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (grid[row][col] == 0)
                return true;
    return false;
}

bool UsedInRow(vector<vector<int> >&grid, int row, int num)
{
    for (int col = 0; col < N; col++)
        if (grid[row][col] == num)
            return true;
    return false;
}

bool UsedInCol(vector<vector<int> >&grid, int col, int num)
{
    for (int row = 0; row < N; row++)
        if (grid[row][col] == num)
            return true;
    return false;
}

bool UsedInBox(vector<vector<int> >&grid, int boxStartRow, int boxStartCol, int num)
{
    for (int row = 0; row < SQN; row++)
        for (int col = 0; col < SQN; col++)
            if (grid[row+boxStartRow][col+boxStartCol] == num)
                return true;
    return false;
}

bool isSafe(vector<vector<int> >&grid, int row, int col, int num)
{
    /* Check if 'num' is not already placed in current row,
       current column and current SQNxSQN box */
    return !UsedInRow(grid, row, num) &&
           !UsedInCol(grid, col, num) &&
           !UsedInBox(grid, row - row%SQN , col - col%SQN, num);
}

void printGrid(vector<vector<int> >&grid)
{
    for (int row = 0; row < N; row++)
    {
       for (int col = 0; col < N; col++)
             cout<<grid[row][col];
        cout<<"\n";
    }
}
int main()
{
 cout<<"Enter N: "<<endl;
   cin>>N;
   SQN=sqrt(N);
   cout<<"Enter sudoku "<<endl;
   vector<vector<int> >grid(N,vector<int>(N));
    // 0 means cell is unassigned
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>grid[i][j];
        }
    }
    if (SolveSudoku(grid) == true)
          printGrid(grid);
    else
         cout<<("No solution exists");

    return 0;
}