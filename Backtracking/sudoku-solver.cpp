#include <iostream>
#include <string>
#include <vector>

using namespace std;

void PrintGrid(int (*grid)[9], int n)
{
  for (size_t i = 0; i < n; i++)
  {
    for (size_t j = 0; j < n; j++)
    {
      cout << grid[i][j] << " ";
    }
    cout << endl;
  }
}

bool IsSafe(int (*grid)[9], int i, int j, int n, int value)
{
  // check whether this number is present in the row or column
  for (size_t k = 0; k < n; k++)
  {
    if (grid[k][j] == value || grid[i][k] == value)
    {
      // it exist in column or row
      return false;
    }
  }

  // check for subgrid 3 by 3
  // get the starting point of the subgrid assuming n is 9
  int startX = (i / 3) * 3;
  int startY = (j / 3) * 3;

  for (size_t x = startX; x < startX + 3; x++)
  {
    for (size_t y = startY; y < startY + 3; y++)
    {
      if (grid[x][y] == value)
      {
        return false;
      }
    }
  }

  return true;
}

/**
 * @brief
 *
 * @param grid sudoku grid
 * @param i row index
 * @param j column index
 * @param n size of the grid
 * @return true
 * @return false
 */
bool SolveSudoku(int (*grid)[9], int i, int j, int n)
{
  // base case
  if (i == n)
  {
    PrintGrid(grid, n);
    return true;
  }

  // recursive case
  // we are at the end of the row
  if (j == n)
  {
    // shift to the next row, first column
    return SolveSudoku(grid, i + 1, 0, n);
  }

  // if the cell is already filled skip it
  if (grid[i][j] != 0)
  {
    return SolveSudoku(grid, i, j + 1, n);
  }

  // we are on the cell to be filled - try all possibilities
  for (int val = 0; val <= n; val++)
  {
    // check whether it is safe to place
    if (IsSafe(grid, i, j, n, val))
    {
      grid[i][j] = val;

      auto subproblemSolution = SolveSudoku(grid, i, j + 1, n);
      if (subproblemSolution)
      {
        return true;
      }
    }
  }

  // we are here if the current cell cannot be filled
  // empty the current cell and move to the previous cell
  grid[i][j] = 0;
  return false;
}

int main()
{
  int n = 9;
  int grid[9][9] =
      {{5, 3, 0, 0, 7, 0, 0, 0, 0},
       {6, 0, 0, 1, 9, 5, 0, 0, 0},
       {0, 9, 8, 0, 0, 0, 0, 6, 0},
       {8, 0, 0, 0, 6, 0, 0, 0, 3},
       {4, 0, 0, 8, 0, 3, 0, 0, 1},
       {7, 0, 0, 0, 2, 0, 0, 0, 6},
       {0, 6, 0, 0, 0, 0, 2, 8, 0},
       {0, 0, 0, 4, 1, 9, 0, 0, 5},
       {0, 0, 0, 0, 8, 0, 0, 7, 9}};

  SolveSudoku(grid, 0, 0, 9);

  return 0;
}