

import java.util.Arrays;

public class ValidSudoku {
	public static boolean isinRange (int[][] sudoku,int N) {

		// Traverse sudoku[][] array

		for (int i = 0 ; i < N ; i++) {

			for (int j = 0; j < N ; j++) {

				// Check if Sudoku[i][j] lies in the range

				if(sudoku[i][j] < 0 || sudoku[i][j] > 9) {

					return false;

				}

			}

		}

		return true;

	}

	// Function to check if the solution of soduku puzzle is valid or invalid

	public static boolean isValidSudoku (int[][] sudoku,int N) {

		// Check if all elements of suduku[][] stores value in the range[1-9]

		if (isinRange(sudoku,N) == false) {

			return false;

		}

		// Stores Unique value from 1-N

		boolean[] valid = new boolean[N+1];

		// Traverse each row of the given array

		for (int i = 0 ; i < N ; i++) {

			// Initializaes the valid[] array to false

			Arrays.fill (valid , false);

			// Traverse each column of currebt row

			for (int j = 0 ; j < N ; j++) {

				// Stores the value of sudoku[i][j]

				int z = sudoku[i][j];

				// Check if current row stores the duplicate value

				if(z>0){
					if (valid[z]){

						return false;

					}
					valid[z]= true;
				}

			}

		}

		// Traverse each column of the given array

		for (int i = 0 ; i < N ; i++) {

			// Initilizes the valid[] array to false

			Arrays.fill(valid , false);

			// Traverse each row of the current column

			for (int j = 0 ; j < N ; j++) {

				// Stores the value of sudoku[j][i]

				int z = sudoku[j][i];

				// Check if current columns stores duplicate value

				if(z>0){

					if (valid[z]){

						return false;

					}

					valid[z]=true;
				}

			}

		}

		// Traverse each block of size 3*3 in sudoku[][] array

		for (int i = 0 ; i < N - 2 ; i = i + 3) {

			//j stores first column of each 3*3 block

			for (int j = 0 ; j < N - 2 ; j = j + 3) {

				// Initialize valid[] array to false

				Arrays.fill(valid , false);

				// Traverse current block

				for (int k = 0 ; k < 3 ; k++) {

					for (int l = 0 ; l < 3 ; l++) {

						// Stores row number of current block

						int x = i + k;

						// Stores column number of current block

						int y = j + l;

						// Stores the value of suduku[x][y]

						int z = sudoku[x][y];

						// Check if current block stores duplicate value

						if(z>0){

							if(valid[z]) {

								return false;

							}

							valid[z]=true;

						}

					}

				}

			}

		}

		// If all conditions satisfied
		
		return true;

	}
}
