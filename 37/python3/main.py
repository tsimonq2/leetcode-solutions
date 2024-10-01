#!/usr/bin/env python3

class Solution:
    def solveSudoku(self, board):
        # Step 1: Initialize bitsets for rows, columns, and 3x3 grids
        row = [0] * 9
        col = [0] * 9
        grid = [0] * 9
        
        # Step 2: Preprocess the board to set initial values in the bitsets
        for i in range(9):
            for j in range(9):
                if board[i][j] != '.':
                    num = int(board[i][j]) - 1  # Convert '1'-'9' to 0-8
                    bit = 1 << num  # Create bitmask for the number
                    row[i] |= bit
                    col[j] |= bit
                    grid[self.get_grid_index(i, j)] |= bit

        # Step 3: Start backtracking from the top-left corner
        self.backtrack(board, row, col, grid, 0, 0)

    def get_grid_index(self, i, j):
        """Calculate the 3x3 grid index for a given cell (i, j)."""
        return (i // 3) * 3 + (j // 3)

    def backtrack(self, board, row, col, grid, i, j):
        """Recursive backtracking function."""
        # If we've filled all rows, the Sudoku is solved
        if i == 9:
            return True
        
        # Move to the next row if we're at the end of the current one
        if j == 9:
            return self.backtrack(board, row, col, grid, i + 1, 0)

        # If the cell is already filled, skip to the next column
        if board[i][j] != '.':
            return self.backtrack(board, row, col, grid, i, j + 1)

        # Try placing numbers 1-9 in the empty cell
        grid_idx = self.get_grid_index(i, j)
        for num in range(9):
            bit = 1 << num
            if not (row[i] & bit or col[j] & bit or grid[grid_idx] & bit):
                # Place the number
                board[i][j] = str(num + 1)
                row[i] |= bit
                col[j] |= bit
                grid[grid_idx] |= bit

                # Recur to place the next number
                if self.backtrack(board, row, col, grid, i, j + 1):
                    return True

                # Undo the placement (backtrack)
                board[i][j] = '.'
                row[i] &= ~bit
                col[j] &= ~bit
                grid[grid_idx] &= ~bit

        # If no number can be placed, backtrack
        return False
