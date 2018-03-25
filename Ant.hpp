/*********************************************************************
 * ** Program name: Ant.hpp
 * ** Author: Alexandra Carper
 * ** Date: 01/21/2018
 * ** Description: This is the class declaration file for the Ant class.
 * 					In this file we create an enumerated data type called
 * 					Orientation that helps keep track of the ant's
 * 					orientation.
 * *********************************************************************/
#include <iostream>
#ifndef ANT_HPP
#define ANT_HPP

//Create enumerated type for orientation
enum Orientation{UP, DOWN, LEFT, RIGHT};

class Ant
{
	private:
		char boardColor;
		int tRow;
		int tColumn;
		Orientation ori;

	public:
		Ant(int row, int column);
		void setBoardColor(char color);
		char getBoardColor();
		void setTRow(int trow);
		int getTRow();
		void setTColumn(int tcolumn);
		int getTColumn();
		void setAntOrientation(Orientation o);
		Orientation getAntOrientation();
};

#endif


