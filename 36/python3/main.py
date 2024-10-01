#!/usr/bin/env python3

class Solution:
    def isValidSudoku(self, board):
        for i in range(9):
            row_seen = set()
            col_seen = set()
            grid_seen = set()
            
            for j in range(9):
                # Check row duplicates
                if board[i][j] != '.':
                    if board[i][j] in row_seen:
                        return False
                    row_seen.add(board[i][j])

                # Check column duplicates
                if board[j][i] != '.':
                    if board[j][i] in col_seen:
                        return False
                    col_seen.add(board[j][i])

                # Check 3x3 grid duplicates
                grid_row = 3 * (i // 3) + j // 3
                grid_col = 3 * (i % 3) + j % 3
                if board[grid_row][grid_col] != '.':
                    if board[grid_row][grid_col] in grid_seen:
                        return False
                    grid_seen.add(board[grid_row][grid_col])
        
        return True
