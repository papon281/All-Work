import java.util.*;
import java.io.*;
import java.util.Arrays;

//Driver code

public class SudokuMain{

	static int N = 9;

	static int[][] sudoku = new int[N][N];

	SudokuMain() {

		for(int i = 0 ; i < N ; i++) {

			for(int j = 0 ; j < N ; j++) {

				sudoku[i][j] = 0;

			}

		}

	}
	
	public static void main (String args[]) {

		Scanner input = new Scanner(System.in);

		while(true) {

			System.out.println("1. Check the sudoku is valid or invalid.");

			System.out.println("2. Solution of the Sudoku Puzzle.");
			
			System.out.println("3. Exit.");

			int option = input.nextInt();

			if(option == 1) {

				SudokuMain sudo = new SudokuMain();
				System.out.println("Enter a sudoku for check valid or invalid.");


				for(int i = 0 ; i < N ;i++) {

					for(int j = 0 ; j < N ;j++) {

						sudoku[i][j] = input.nextInt();

					}

				}

				if(ValidSudoku.isValidSudoku(sudoku,N)) {

					System.out.println("The sudoku you enter was valid.");

				}

				else {

					System.out.println("The sudoku you enter was invalid.");

				}

			}

			 if(option == 2) {

				 SudokuMain sudo = new SudokuMain();

				System.out.println("Enter a sudoku for solve.");

				for(int i = 0 ; i < N ; i++) {

					for(int j = 0 ; j < N ;j++) {

						sudoku[i][j] = input.nextInt();

					}

				}

				if (SolveSudoku.solveSudoku(sudoku , 0 , 0, N)) {

					SolveSudoku.printSudoku (sudoku , N);

				}

				else {

					System.out.println("No solution exist."); 

				}

			}

			else if(option == 3) {

				System.exit(0);
			}

			else if(option <= 0 || option > 3){

				System.out.println("Please, enter number between 1-3.");

			}

		}

	}
	
}

	
