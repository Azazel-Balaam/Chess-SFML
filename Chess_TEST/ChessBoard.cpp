#include "ChessBoard.h"
#include <string>

void ChessBoard::coordinateTranslation(std::string coord, int &iOut, int &jOut)
{
	if (coord.size() != 2)
	{
		throw "Bad Coord";
	}

	std::string letterStr = "abcdefgh";
	for (int i = 0; i < 8; i++) {
		if (coord[0] == letterStr[i]) {
			iOut = i;
		}
	}

	std::string numStr = "87654321";
	for (int j = 0; j < 8; j++) {
		if (coord[1] == numStr[j]) {
			jOut = j;
		}
	}
}

ChessFigure ChessBoard::getField(std::string str)
{	
	int iOut = 0;
	int jOut = 0;

	coordinateTranslation(str, iOut, jOut);

	return *Board[iOut][jOut];
}

ChessFigure* ChessBoard::getFieldPointer(std::string str)
{
	int iOut = 0;
	int jOut = 0;

	coordinateTranslation(str, iOut, jOut);

	return Board[iOut][jOut];
}

void ChessBoard::setFigure(ChessFigure &_chess, std::string str)
{
	int iOut = 0;
	int jOut = 0;

	coordinateTranslation(str, iOut, jOut);

	Board[iOut][jOut] = &_chess;
}

bool ChessBoard::fieldIsEmpty(std::string Pos)
{
	if (this->getField(Pos) == this->S) {
		return true;
	}
	else {
		return false;
	}
}

ChessBoard & ChessBoard::operator=(const ChessBoard & A)
{
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			int iOut, jOut;
			this->Board[i][j] = A.Board[i][j];
		}
	}

	return *this;
}

ChessBoard::ChessBoard()
{
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			Board[i][j] = &S;
		}
	}
}

ChessBoard::~ChessBoard()
{
}
