import java.awt.Color;

import java.awt.Dimension;

import java.awt.Font;

import java.awt.Graphics;

import java.awt.GridBagConstraints;

import java.awt.GridBagLayout;

import java.awt.GridLayout;

import java.awt.event.*;

import javax.swing.JButton;

import javax.swing.JFrame;

import javax.swing.JLabel;

import javax.swing.JOptionPane;

import javax.swing.JPanel;

import javax.swing.JTextField;


public class SolveSudoku {
	
	public static boolean solveSudoku (int[][] sudoku , int row , int column,int N) {
		
		if(!ValidSudoku.isValidSudoku(sudoku, N)) {
			return false;
		}

		// If we reached the 8th row and 9th column, we are returning true 
		
		if (row == N-1 && column == N) {

			return true;

		}

		// Check if column value is 9, if then we move to next row and column start from 0
		if (column == N) {

			row++;

			column=0;

		}

		/*Check if the current position of the suduku already contains
			value>0, we iterate for next column*/
		if (sudoku[row][column] != 0) {

			return solveSudoku (sudoku , row , column+1,N);

		}

		for (int num = 1 ; num <= 9 ; num++) {

			/*Check if it is safe to place the num(1-9) in the given
				row,column else we move to next column*/
			if (isSafe (sudoku , row , column , num,N) ) {

				/* Assigning the num in the current position(row,column)
				   assuming our assigned num in the position nis correct*/
				sudoku[row][column]=num;

				// Checking for next column
				if (solveSudoku (sudoku , row , column+1,N) ) {

					return true;

				}

			}

			/* Removing the assigned num, since our assumption was wrong
				and we go for the next assumption with difference num value*/
			sudoku[row][column] = 0;

		}

		return false;

	}

	// Check whether it is valid for assigned the num in given row,column
	public static boolean isSafe (int[][] sudoku , int row , int column , int num,int N) {

		// If we find the same num in the similar row, return false
		for (int i =0 ; i < N ; i++) {

			if (sudoku[row][i] == num) {

				return false;

			}

		}

		// If we find the same num in similar column,return false
		for (int i = 0 ; i < N ; i++) {

			if (sudoku[i][column] == num) {

				return false;

			}

		}

		int startRow = row - row % 3;

		int startColumn = column - column % 3;

		// If we find the same num in the particular 3*3 matrix, return false
		for (int i = 0 ; i < 3; i++) {

			for (int j = 0 ; j < 3 ; j++) {

				if (sudoku[i+startRow][j+startColumn] == num) {

					return false;

				}

			}

		}

		return true;

	}

}
