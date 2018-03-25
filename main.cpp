/*********************************************************************
 * ** Program name: main.cpp
 * ** Author: Alexandra Carper
 * ** Date: 01/21/2018
 * ** Description: This main function asks the user to create the board
 * 					by inputting board rows and board columns. Then, it
 * 					asks the user to choose the number of steps the ant
 * 					takes. Next, it asks the user if he or she wants to
 * 					start at a random location. If the user chooses yes,
 * 					the program generates a random coordinate. If the
 * 					user chooses no, the program asks for the coordinates
 * 					of the location the user wants the ant to start at.
 * 					Once the ant has a starting location, the  program
 * 					dynamically allocates a 2d array for the board and
 * 					places the ant on the board in its specified
 * 					location. The program prints the board and then
 * 					proceeds with each step by following the rules of
 * 					Langton's ant. If the ant is on a white space,
 * 					it turns right 90 degrees and changes the space to
 * 					black. If the ant is on a black space, it turns 90
 * 					degrees and changes the space to white. For each move
 * 					it prints out the board, and when it finishes, it
 * 					deallocates the memory to prevent memory leaks.
 * *********************************************************************/
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <string>
#include "Ant.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::srand;
using std::time;

int main()
{
	int boardRows,
	    boardColumns,
	    steps,
	    row, 
	    column;

	bool validDataBoard = false;
	bool validDataAnt = false;
	char randomStart;

	//Menu
	char choice;

	cout << "Welcome! Would you like to start the Langton's Ant simulation"
	     << " or quit?\n";
	cout << "A. Start Langton's Ant simulation.\n";
	cout << "B. Quit\n";
	
	//Input choice
	cin >> choice;
	
	//If wrong input type
	if(cin.fail())
	{
		cout << "Error! Please enter 'A' or 'B'." << endl;
		//Clear stream
		cin.clear();
		//Skip newline character				
		cin.ignore();
		//Prompt again				
		cin >> choice;
	}
	//If input is wrong character
	else if(choice != 'a' && choice != 'A' && choice != 'b' && choice != 'B')
	{
		cout << "Error! Please enter 'A' or 'B'." << endl;
		//Clear stream
		cin.clear();
		//Skip newline character
		cin.ignore();
		//Prompt again
		cin >> choice;				
	}
	//If user chooses B
	else if(choice == 'b' || choice == 'B')
	{
		//Quit
		cout << "Goodbye!" << endl;
	}
	//While user chooses A
	while(choice == 'a' || choice == 'A')
	{						
		validDataBoard = false;
		validDataAnt = false;
		//Get rows on board
		cout << "Please enter the amount of rows on the board." << endl;
		//Force through loop
		while(!validDataBoard)
		{
			//User inputs board rows
			cin >> boardRows;
			
			//If valid input
			if(boardRows > 0)
			{
				//Don't return through loop
				validDataBoard = true;
			}
			//If invalid input
			else if(boardRows < 0 || cin.fail())
			{
				cout << "Error! The number of rows must"
				     << " be an integer greater than 0!" << endl;
				//Clear stream
				cin.clear();
				//Skip newline character
				cin.ignore();
			}
		}
		
		//Set input validator back to false
		validDataBoard = false;
		
		//Get columns on board
		cout << "Please enter the amount of columns on the board."
		     << endl;

		//Force through loop
		while(!validDataBoard)
		{
			//User inputs boardColumns
			cin >> boardColumns;
			
			//If valid input
			if(boardColumns > 0)		
			{
				//Don't return through loop
				validDataBoard = true;	
			}
			//If input not valid
			else if(boardColumns < 0 || cin.fail())
			{
				cout << "Error! The number of columns must"
				     << " be an integer greater than 0!" << endl;
				//Clear stream
				cin.clear();
				//Skip newline character
				cin.ignore();
			}
		}

		//Get the steps the ant takes
		cout << "Enter the number of steps for the ant to execute."
		     << endl;
		//Set input validator back to false
		validDataAnt = false;
		//Force through loop
		while(!validDataAnt)
		{	
			//User inputs steps
			cin >> steps;
			//If valid input
			if(steps > 0)
			{
				//Don't return through loop
				validDataAnt = true;
			}
			//If invalid input
			else if(cin.fail() || steps < 0)
			{
				cout << "Error! Please enter an integer greater"
				     << " than 0!" << endl;
				//Clear stream
				cin.clear();
				//Skip newline character
				cin.ignore();
			}
		}
	
		//Get starting location of ant
		cout << "Do you want the ant to start at a" 
		     << " random location?" << endl;
		cout << "Enter 'Y' for 'Yes' and 'N' for 'No'." << endl;
		//Set input validator
		validDataAnt = false;
		

		//Force through loop
		while(!validDataAnt)
		{
			//User inputs choice
			cin >> randomStart;

			//If user chooses yes
			if(randomStart == 'y' || randomStart == 'Y')
			{
				//Seed with time
				srand(time(0));
				//boardRows = max value
				row = (rand() % boardRows);
				//boardColumns = max value	
				column = (rand() % boardColumns);
				//Don't return through loop
				validDataAnt = true;
			}
			
			//If user wants to pick starting location
			else if(randomStart == 'n' || randomStart == 'N')
			{
				//Get rows
				while(!validDataAnt)
				{
					cout << "Enter the row number at which"
					     << " you would like the ant to"
					     << " start." << endl;
					cout << "(Must be > 1 and within board)" 
					     << endl;
					//User inputs row
					cin >> row;
					
					//If valid input
					if(row <= boardRows && row > 0)	
					{	
						//Account for array format
						row -= 1;
						//Don't return through loop
						validDataAnt = true;
					}
					//If invalid input
					else if(cin.fail() || row > boardRows ||
						row < 0)
					{
						cout << "The ant must start at"
						     << " a position inside the"
						     << " specified number of"
						     << " rows!" << endl;
						//Clear stream
						cin.clear();
						//Skip newline character
						cin.ignore();
					}
				}

				//Get columns
				validDataAnt = false;
				
				//Force through loop
				while(!validDataAnt)
				{
					cout << "Enter the column number at"
					     << " which you would like the ant"
					     << " the ant to start." << endl;
					//User inputs columns
					cin >> column;

					//If valid input
					if(column <= boardColumns && column > 0)
					{
						//Account for array
						column -= 1;
						//Don't return through loop
						validDataAnt = true;
					}
					//If invalid input
					else if(cin.fail() || 
						column > boardColumns ||
						column < 0)
					{
						cout << "The ant must start at"
						     << " at a position inside"
						     << " the specified number"
						     << " of columns!" << endl;
						//Clear stream
						cin.clear();
						//Skip newline character
						cin.ignore();
					}
				}
			}
			//If not correct character
			else
			{
				cout << "Error! Please enter 'Y' for 'Yes' or "
				     << "'N' for 'No'." << endl;
				//Clear stream
				cin.clear();
				//Skip newline character
				cin.ignore();
			}
		}

		//Create ant object
		Ant littleAnt(row, column);		
		
		//Clear screen					
		cout << "\033[2J\033[1;1H";		
		cout << "Press enter to continue..." << endl;
		string tempString;
		getline(cin, tempString);

		//Create the board
		char **board = new char*[boardRows];	
		//Loop through rows				
		for(int i = 0; i < boardRows; i++)
		{
			//Create columns
			board[i] = new char[boardColumns]; 
		}

		//Initialize board to space characters
		//Loop through rows
		for(int i = 0; i < boardRows; i++)
		{	
			//Loop through columns
			for(int j = 0; j < boardColumns; j++)
			{	//Call set function
				board[i][j] = ' ';
			}
		}

		//Create "ant" (ant = *) and place in starting coordinates
		board[row][column] = '*';
	
		//Print starting board and show ant location
		//Loop through rows
		for(int i = 0; i < boardRows; i++)
		{
			//Loop through columns
			for(int j = 0; j < boardColumns; j++)
			{
				//Print board
				cout << board[i][j];
			}
			//Skip line
			cout << endl;
		}

		//Start simulation
		//Count down steps till 0
		for(int i = steps; i > 0; i--)	
		{		

			//If board color white
			if(littleAnt.getBoardColor() == ' ')
			{	
				//Change space to black
				board[littleAnt.getTRow()][littleAnt.getTColumn()] = '#';		
		
				//If pointing up
				if(littleAnt.getAntOrientation() == UP)
				{	//Turn 90 degrees right
					littleAnt.setAntOrientation(RIGHT);
					//Retrieve column position 
					column = littleAnt.getTColumn();
					//Store column as 1 to right
					column += 1;

					//If out of range of board
					if(column >= boardColumns)
					{
						//Wrap board
						column = 0;
					}
					
					//Set column of ant's move
					littleAnt.setTColumn(column);

					//Set Board Color
					if(board[littleAnt.getTRow()][littleAnt.getTColumn()] == ' ')
					{
						littleAnt.setBoardColor(' ');
					}
					else
					{
						littleAnt.setBoardColor('#');
					}
					
					//Place ant on board
					board[row][column] = '*';
				}
				//If ant points right
				else if(littleAnt.getAntOrientation() == RIGHT)
				{
					//Turn 90 degrees right
					littleAnt.setAntOrientation(DOWN);
					//Retrieve row position
					row = littleAnt.getTRow();
					//Store row as next 1 down
					row += 1;
					
					//If out of range of board
					if(row >= boardRows)
					{
						//Wrap board
						row = 0; 
					}
					
					//Set row for ant's move
					littleAnt.setTRow(row);
					
					//Set Board Color
					if(board[littleAnt.getTRow()][littleAnt.getTColumn()] == ' ')
					{
						littleAnt.setBoardColor(' ');
					}
					else
					{
						littleAnt.setBoardColor('#');
					}				
	
					//Place ant on board
					board[row][column] = '*';

				}
				//If ant points down
				else if(littleAnt.getAntOrientation() == DOWN)
				{
					//Turn 90 degrees right
					littleAnt.setAntOrientation(LEFT);
					//Retrieve column position
					column = littleAnt.getTColumn();
					//Store column as column to left
					column -= 1;
				
					//If out of range of board
					if(column < 0)
					{	
						//Wrap board
						column = boardColumns - 1;
					}
					
					//Set column for ant's move
					littleAnt.setTColumn(column);

					//Set Board Color
					if(board[littleAnt.getTRow()][littleAnt.getTColumn()] == ' ')
					{
						littleAnt.setBoardColor(' ');
					}
					else
					{
						littleAnt.setBoardColor('#');
					}

					//Place ant on board
					board[row][column] = '*';
				}
				//If ant is pointing left
				else if(littleAnt.getAntOrientation() == LEFT)
				{
					//Turn 90 degrees right
					littleAnt.setAntOrientation(UP);
					//Retrieve row position
					row = littleAnt.getTRow();
					//Store row as 1 row up
					row -= 1;
					
					//If out of range of board
					if(row < 0)
					{
						row = boardRows - 1;
					}
			
					//Set row to ant's move
					littleAnt.setTRow(row);
	
					//Set Board Color
					if(board[littleAnt.getTRow()][littleAnt.getTColumn()] == ' ')
					{
						littleAnt.setBoardColor(' ');
					}
					else
					{
						littleAnt.setBoardColor('#');
					}
				
					//Place ant on board
					board[row][column] = '*';
				}
			}
			//If board space is black
			else if(littleAnt.getBoardColor() == '#')
			{
				//Change to white
				board[littleAnt.getTRow()][littleAnt.getTColumn()] = ' ';
				//If pointing up
				if(littleAnt.getAntOrientation() == UP)
				{
					//Turn 90 degrees left
					littleAnt.setAntOrientation(LEFT);
					//Retrieve column position
					column = littleAnt.getTColumn();
					//Set column to 1 left
					column -= 1;

					//If out of range of board
					if(column < 0)
					{
						//Wrap board
						column = boardColumns - 1;
					}

					//Set column for ant's move
					littleAnt.setTColumn(column);

					//Set Board Color
					if(board[littleAnt.getTRow()][littleAnt.getTColumn()] == ' ')
					{
						littleAnt.setBoardColor(' ');
					}
					else
					{
						littleAnt.setBoardColor('#');
					}


					//Place ant on board
					board[row][column] = '*';

				}
				//If pointing right
				else if(littleAnt.getAntOrientation() == RIGHT)
				{
					//Turn 90 degrees left
					littleAnt.setAntOrientation(UP);
					//Retrieve row position
					row = littleAnt.getTRow();
					//Set row to 1 up
					row -= 1;
				
					//If out of range of board
					if(row < 0)
					{
						//Wrap board
						row = boardRows - 1;
					}
			
					//Set row for ant's move
					littleAnt.setTRow(row);

					//Set Board Color
					if(board[littleAnt.getTRow()][littleAnt.getTColumn()] == ' ')
					{
						littleAnt.setBoardColor(' ');
					}
					else
					{
						littleAnt.setBoardColor('#');
					}

					//Place ant on board
					board[row][column] = '*';
				}
				//If pointing down
				else if(littleAnt.getAntOrientation() == DOWN)
				{
					//Turn 90 degrees left
					littleAnt.setAntOrientation(RIGHT);
					//Retrieve column position
					column = littleAnt.getTColumn();
					//Set column to 1 column right
					column += 1;

					//If out of range of board
					if(column >= boardColumns)
					{
						//Wrap board
						column = 0;
					}
					
					//Set column for ant's move
					littleAnt.setTColumn(column);

					//Set Board Color
					if(board[littleAnt.getTRow()][littleAnt.getTColumn()] == ' ')
					{
						littleAnt.setBoardColor(' ');
					}
					else
					{
						littleAnt.setBoardColor('#');
					}

					//Place ant on board
					board[row][column] = '*';
				}
				//If pointing left
				else if(littleAnt.getAntOrientation() == LEFT)
				{
					//Turn 90 degrees left
					littleAnt.setAntOrientation(DOWN);
					//Retrieve row position
					row = littleAnt.getTRow();
					//Set row to 1 row down
					row += 1;
	
					//If out of range of board
					if(row >= boardColumns)
					{
						row = 0;
					}
			
					//Set row for ant's move
					littleAnt.setTRow(row);

					//Set Board Color
					if(board[littleAnt.getTRow()][littleAnt.getTColumn()] == ' ')
					{
						littleAnt.setBoardColor(' ');
					}
					else
					{
						littleAnt.setBoardColor('#');
					}

					//Place ant on board
					board[row][column] = '*';
				}
			}
		
			//Print board
			for(int i = 0; i < boardRows; i++)
			{
				for(int j = 0; j < boardColumns; j++)
				{
					cout << board[i][j];
				}
				//Skip to next line
				cout << endl;
				cout << endl;
			}
		}	
			
		//End menu
		cout << "Would you like to play again?" << endl;
		cout << "A. Play again." << endl;
		cout << "B. Quit" << endl;
		//Input choice
		//If A, program should repeat
		//If B, program should quit
		cin >> choice;
			
		if(choice == 'b' || choice == 'B')
		{
			cout << "Goodbye!" << endl;
		}
		if(cin.fail() && choice != 'a' && choice != 'A' && choice != 'b' && choice != 'B')
		{
			cout << "Error! Please choose 'A' or 'B'!";
			cin >> choice;
		}
		
		//Delete allocated memory
		for(int i = 0; i < boardRows; i++)
		{	
		
			delete[] board[i];
		}
	
		delete[] board;
	}

	return 0;
}
