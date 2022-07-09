#include <iostream>
#include <string>
#include <vector>

using namespace std;

void PrintBoard(int n, int (*board)[20])
{
  for (size_t i = 0; i < n; i++)
  {
    for (size_t j = 0; j < n; j++)
    {
      cout << board[i][j] << " ";
    }
    cout << endl;
  }
}

/**
 * @brief whether we can place a queen on the cell x,y
 * in a given grid board
 *
 * @param board
 * @param n
 * @param x
 * @param y
 * @return true
 * @return false
 */
bool CanPlace(int (*board)[20], int n, int x, int y)
{
  // check for the column
  for (size_t k = 0; k < x; k++)
  {
    if (board[k][y] == 1)
    {
      return false;
    }
  }

  // left diagonal
  int i = x;
  int j = y;
  while (i >= 0 && j >= 0)
  {
    if (board[i][j] == 1)
      return false;

    i--;
    j--;
  }

  // right diagonal
  i = x;
  j = y;
  while (i >= 0 && j < n)
  {
    if (board[i][j] == 1)
      return false;

    i--;
    j++;
  }

  return true;
}

/**
 * @brief this method prints one of the ways to place
 * queens in each row that they cannot attack each other
 * Time Complexity O(n^n)
 *
 * @param n board size n by n
 * @param board whole board 2D int array memory
 * @param i start row index
 * @return true
 * @return false
 */
bool SolveNQueen(int n, int board[][20], int i)
{
  // base case
  if (i == n)
  {
    PrintBoard(n, board);
    return true;
  }

  // recursive case
  // try place a queen at every row - so we dont need to check for the row
  for (size_t j = 0; j < n; j++)
  {
    // check whether current cell i,j is safe to place or not
    if (CanPlace(board, n, i, j))
    {
      // place the queen on the board
      board[i][j] = 1;

      // now solve for the grid starting from the next row
      bool success = SolveNQueen(n, board, i + 1);

      if (success)
      {
        return true;
      }

      // if not successful - we will backtrack and increment the j
      // remove the queen
      board[i][j] = 0;
    }
  }

  // no position in the row that could satisfy the constraint
  // so the previous parent call requires updating
  return false;
}

/**
 * @brief counts all the possible ways to place queens on the board at each row
 * it also prints all possible
 * Time Complexity O(n^n)
 *
 * @param n
 * @param board
 * @param i
 * @return int
 */
int CountNQueenSolutions(int n, int board[][20], int i)
{
  // base case
  if (i == n)
  {
    PrintBoard(n, board); // print each board
    cout << "###########" << endl;
    // only 1 way to place a queen if its a 1x1 board
    return 1;
  }

  int numberOfWays = 0;

  // recursive case
  // try place a queen at every row - so we dont need to check for the row
  for (size_t j = 0; j < n; j++)
  {
    // check whether current cell i,j is safe to place or not
    if (CanPlace(board, n, i, j))
    {
      // place the queen on the board
      board[i][j] = 1;

      // now solve for the grid starting from the next row
      // CountNQueenSolution either returns 0 or more
      numberOfWays += CountNQueenSolutions(n, board, i + 1);

      // if not successful - we will backtrack and increment the j
      // remove the queen
      board[i][j] = 0;
    }
  }

  // no position in the row that could satisfy the constraint
  // so the previous parent call requires updating
  return numberOfWays;
}

int main()
{
  int board[20][20] = {0};

  int n;
  cin >> n;

  cout << CountNQueenSolutions(n, board, 0) << endl;

  return 0;
}