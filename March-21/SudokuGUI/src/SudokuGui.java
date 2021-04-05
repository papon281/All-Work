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

import java.util.Arrays;

public class SudokuGui{

	static int N = 9;

	private JFrame frame = new JFrame ("Sudoku Solver");

	private JTextField textfield[][] = new JTextField[N][N];

	private GridPanel gridPanel = new GridPanel ( new GridLayout ( 9 , 9 , 1 , 1 ) );
	
	int[][] sudoku = new int[N][N];

	public SudokuGui() {

		for(int x = 0 ; x < N ; x++) {

			for ( int y = 0 ; y < N ; y++) {

				textfield[x][y] = new JTextField();

				textfield[x][y].setForeground(Color.RED);

				gridPanel.add(textfield[x][y]);

			}

		}

	}
	
	public boolean getDigit() {

		for(int x = 0 ; x < N ; x++) {

			for(int y = 0 ; y < N ; y++) {

				if(!textfield[x][y].getText().equals("")){
					
					if(textfield[x][y].getText().equals("1") || textfield[x][y].getText().equals("2") || textfield[x][y].getText().equals("3") || textfield[x][y].getText().equals("4") || textfield[x][y].getText().equals("5") || textfield[x][y].getText().equals("6") || textfield[x][y].getText().equals("7")|| textfield[x][y].getText().equals("8") || textfield[x][y].getText().equals("9")) {
						sudoku[x][y]=(Integer.parseInt(textfield[x][y].getText()));

					}
					else {
						JOptionPane.showMessageDialog(frame,"Please enter valid inpu. The valid input is between 1-9","Error",JOptionPane.ERROR_MESSAGE);
						return false;
					}
				}
				
				else {
					
					sudoku[x][y] = 0;
					
				}

			}

		}
		return true;

	}
	
	public void SudokutoGUI() {
		
		for(int i=0;i<N;i++) {
			for(int j=0;j<N;j++) {
				textfield[i][j].setText(String.valueOf(sudoku[i][j]));
			}
		}
	}
	
	public void clearGrid(){
        for (int y = 0; y < 9; y++){
            for (int x = 0; x < 9; x++){
                textfield[x][y].setText("");
                textfield[x][y].setForeground(Color.RED);
            }
        }
    }
	
	
	public void createGui() {

		JPanel mainPanel = new JPanel(new GridBagLayout());

		GridBagConstraints gridBagConstraints = new GridBagConstraints();

		gridBagConstraints.weighty = 1;

		gridBagConstraints.weightx = 1;

		gridBagConstraints.anchor = GridBagConstraints.NORTH;
		
		JLabel topLabel = new JLabel("Sudoku Solver",JLabel.CENTER);

		topLabel.setOpaque(true);

		topLabel.setBackground(Color.BLACK);

		topLabel.setForeground(Color.WHITE);

		topLabel.setFont(new Font("Helvetica",Font.PLAIN,20));
		
		gridBagConstraints.gridx = 0;

		gridBagConstraints.gridy = 0;

		gridBagConstraints.gridwidth = 2;

		gridBagConstraints.weighty = 0.05;

		gridBagConstraints.fill = GridBagConstraints.BOTH;

		mainPanel.add(topLabel,gridBagConstraints);
		
		gridBagConstraints.gridx = 0;

		gridBagConstraints.gridy = 0;

		gridBagConstraints.gridwidth = 2;

		gridBagConstraints.weighty = 1;

		gridBagConstraints.fill = GridBagConstraints.BOTH;

		gridBagConstraints.anchor = GridBagConstraints.NORTH;

		mainPanel.add(gridPanel,gridBagConstraints);
		
		gridBagConstraints.anchor = GridBagConstraints.SOUTH;

		gridBagConstraints.weighty = 0.1;
			
		JButton solveButton = new JButton("Solve");

		gridBagConstraints.gridx = 0;

		gridBagConstraints.gridy = 3;

		gridBagConstraints.gridwidth = 2;

		gridBagConstraints.ipadx = 0;

		mainPanel.add(solveButton,gridBagConstraints);
		
		JButton clearButton = new JButton("Clear Table");
        gridBagConstraints.gridx = 1;
        gridBagConstraints.gridy = 2;
        gridBagConstraints.gridwidth = 1;
        gridBagConstraints.ipadx = 0;
        mainPanel.add(clearButton, gridBagConstraints);
        clearButton.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                clearGrid();
            }
        });
        
        JButton exitButton = new JButton("Exit");
        gridBagConstraints.gridx = 0;
        gridBagConstraints.gridy = 2;
        gridBagConstraints.gridwidth = 1;
        gridBagConstraints.ipadx = 0;
        mainPanel.add(exitButton, gridBagConstraints);
        exitButton.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                System.exit(0);
            }
        });

		solveButton.addActionListener(new ActionListener() {

				public void actionPerformed(ActionEvent e) {
					
					if(!getDigit()) {
						clearGrid();
					}
					else {
					
						if( !SolveSudoku.solveSudoku( sudoku , 0 , 0 , N ) ) {
	
							JOptionPane.showMessageDialog(frame,"This puzzle cannot be solved","Error",JOptionPane.ERROR_MESSAGE);
	
						}
	
						else {
	
							SudokutoGUI();
	
						}
					}
				}

			});
		
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		frame.setSize(300,300);

		frame.getContentPane().add(mainPanel);

		frame.setLocationRelativeTo(null);

		frame.setMinimumSize(new Dimension(300,300));

		frame.setVisible(true);

	}
	
	public class GridPanel extends JPanel {

		GridPanel(GridLayout layout) {

			super(layout);

		}
		
		public void paintComponent(Graphics g) {

			g.fillRect(getWidth()/3-1, 0, 3, getHeight());

			g.fillRect(2*getWidth()/3-1, 0, 3, getHeight());

			g.fillRect(0, getHeight()/3-1, getWidth(), 3);

			g.fillRect(0, 2*getHeight()/3-1, getWidth(), 3);

		}

	}
	
}
