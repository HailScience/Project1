/*********************************************************************
 * ** Program name: Ant.cpp
 * ** Author: Alexandra Carper
 * ** Date: 01/21/2018
 * ** Description: This class interface file constructs an Ant object,
 * 					sets and gets the boardColor, sets and gets the
 * 					current row, sets and gets the current column, and
 * 					sets and gets the orientation of the ant.
 * *********************************************************************/
#include <iostream>
#include "Ant.hpp"

/***********************************************************************
 * Description: Constructor takes row and column as parameters and sets
 * the boardColor to white spaces, sets the current row to the row
 * passed to it, sets the current column to the column passed to it,
 * and sets the ant orientation to down.
 * ********************************************************************/
Ant::Ant(int row, int column)
{
	setBoardColor(' ');
	setTRow(row);
	setTColumn(column);
	setAntOrientation(DOWN);
}

/***********************************************************************
 * Description: Takes color as a parameter and sets it to boardColor.
 **********************************************************************/
void Ant::setBoardColor(char color)
{
	boardColor = color;
}

/***********************************************************************
 * Description: Returns boardColor
 **********************************************************************/
char Ant::getBoardColor()
{
	return boardColor;
}

/***********************************************************************
 * Description: Takes current row that was passed to it and sets it
 * 				to tRow
 **********************************************************************/
void Ant::setTRow(int trow)
{
	tRow = trow;
}

/***********************************************************************
 * Description: Returns tRow
 **********************************************************************/
int Ant::getTRow()
{
	return tRow;
}

/***********************************************************************
 * Description: Takes current column that was passed to it and sets it
 * 				to tColumn
 **********************************************************************/
void Ant::setTColumn(int tcol)
{
	tColumn = tcol;
}

/***********************************************************************
 * Description: Returns tColumn
 **********************************************************************/
int Ant::getTColumn()
{
	return tColumn;
}

/***********************************************************************
 * Description: Takes the orientation that was passed to it and sets it
 * 				to ori
 **********************************************************************/
void Ant::setAntOrientation(Orientation o)
{
	ori = o;
}

/***********************************************************************
 * Description: Returns ori
 **********************************************************************/
Orientation Ant::getAntOrientation()
{
	return ori;
}

