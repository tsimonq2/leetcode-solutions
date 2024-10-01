#include <bitset>
#include <vector>

class Solution {
public:
    // Solve the Sudoku puzzle
    void solveSudoku(std::vector<std::vector<char>>& board) {
        // Step 1: Initialize bitsets to track rows, columns, and 3x3 grids
        std::bitset<9> row[9], col[9], grid[9];

        // Step 2: Preprocess the board to set initial values in the bitsets
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '1';  // Convert '1'-'9' to 0-8
                    row[i].set(num);
                    col[j].set(num);
                    grid[getGridIndex(i, j)].set(num);
                }
            }
        }

        // Step 3: Start backtracking from the top-left corner
        backtrack(board, row, col, grid, 0, 0);
    }

private:
    // Function to calculate the 3x3 grid index for a given cell (i, j)
    int getGridIndex(int i, int j) {
        return (i / 3) * 3 + (j / 3);
    }

    // Recursive backtracking function
    bool backtrack(std::vector<std::vector<char>>& board, std::bitset<9> row[], 
                   std::bitset<9> col[], std::bitset<9> grid[], int i, int j) {
        // If we've filled all rows, the Sudoku is solved
        if (i == 9) return true;
        
        // Move to the next row if we're at the end of the current one
        if (j == 9) return backtrack(board, row, col, grid, i + 1, 0);

        // If the cell is already filled, skip to the next column
        if (board[i][j] != '.') return backtrack(board, row, col, grid, i, j + 1);

        // Try placing numbers 1-9 in the empty cell
        for (int num = 0; num < 9; ++num) {
            if (!row[i].test(num) && !col[j].test(num) && !grid[getGridIndex(i, j)].test(num)) {
                // Place the number
                board[i][j] = num + '1';  // Convert 0-8 back to '1'-'9'
                row[i].set(num);
                col[j].set(num);
                grid[getGridIndex(i, j)].set(num);

                // Recur to place the next number
                if (backtrack(board, row, col, grid, i, j + 1)) return true;

                // Undo the placement (backtrack)
                board[i][j] = '.';
                row[i].reset(num);
                col[j].reset(num);
                grid[getGridIndex(i, j)].reset(num);
            }
        }

        // If no number can be placed, backtrack
        return false;
    }
};
