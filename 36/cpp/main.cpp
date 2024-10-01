#include <bitset>
#include <iostream>
#include <ranges>
#include <vector>

class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        // Check rows, columns, and 3x3 subgrids
        for (int i = 0; i < 9; ++i) {
            std::bitset<9> rowSeen, colSeen, gridSeen;
            for (int j = 0; j < 9; ++j) {
                // Check row duplicates
                if (board[i][j] >= '1' && board[i][j] <= '9') {
                    int rowBit = board[i][j] - '1';
                    if (rowSeen[rowBit]) return false;
                    rowSeen.set(rowBit);
                }

                // Check column duplicates
                if (board[j][i] >= '1' && board[j][i] <= '9') {
                    int colBit = board[j][i] - '1';
                    if (colSeen[colBit]) return false;
                    colSeen.set(colBit);
                }

                // Check 3x3 grid duplicates
                int gridRow = 3 * (i / 3) + j / 3;
                int gridCol = 3 * (i % 3) + j % 3;
                if (board[gridRow][gridCol] >= '1' && board[gridRow][gridCol] <= '9') {
                    int gridBit = board[gridRow][gridCol] - '1';
                    if (gridSeen[gridBit]) return false;
                    gridSeen.set(gridBit);
                }
            }
        }

        // No duplicates found, Sudoku is valid
        return true;
    }
};
