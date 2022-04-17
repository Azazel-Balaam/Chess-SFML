#include "ChessMaster.h"
#include "ChessBoard.h"
#include "ChessFigure.h"
#include <iostream>


ChessMaster::ChessMaster(ChessBoard& _Board) :
//Пешки
pawnBlack(ChessColors::BLACK),
pawnWhite(ChessColors::WHITE),

//Слоны
bishopBlack(ChessColors::BLACK),
bishopWhite(ChessColors::WHITE),

//Кони
knightBlack(ChessColors::BLACK),
knightWhite(ChessColors::WHITE),

//Ферзи
queenBlack(ChessColors::BLACK),
queenWhite(ChessColors::WHITE),

//Ладьи
rookBlack(ChessColors::BLACK),
rookWhite(ChessColors::WHITE),

//Короли
kingBlack(ChessColors::BLACK),
kingWhite(ChessColors::WHITE)
{
	Board = &_Board;
}

ChessMaster::~ChessMaster()
{
}

void ChessMaster::standardInitialization()
{
	//Белые пешки
	Board->setFigure(pawnWhite, "a2");
	Board->setFigure(pawnWhite, "b2");
	Board->setFigure(pawnWhite, "c2");
	Board->setFigure(pawnWhite, "d2");
	Board->setFigure(pawnWhite, "e2");
	Board->setFigure(pawnWhite, "f2");
	Board->setFigure(pawnWhite, "g2");
	Board->setFigure(pawnWhite, "h2");
	//Белые фигуры
	Board->setFigure(rookWhite, "a1");
	Board->setFigure(rookWhite, "h1");
	Board->setFigure(knightWhite, "b1");
	Board->setFigure(knightWhite, "g1");
	Board->setFigure(bishopWhite, "c1");
	Board->setFigure(bishopWhite, "f1");
	Board->setFigure(queenWhite, "d1");
	Board->setFigure(kingWhite, "e1");

	//Чёрные пешки
	Board->setFigure(pawnBlack, "a7");
	Board->setFigure(pawnBlack, "b7");
	Board->setFigure(pawnBlack, "c7");
	Board->setFigure(pawnBlack, "d7");
	Board->setFigure(pawnBlack, "e7");
	Board->setFigure(pawnBlack, "f7");
	Board->setFigure(pawnBlack, "g7");
	Board->setFigure(pawnBlack, "h7");

	//Чёрные фигуры
	Board->setFigure(rookBlack, "a8");
	Board->setFigure(rookBlack, "h8");
	Board->setFigure(knightBlack, "b8");
	Board->setFigure(knightBlack, "g8");
	Board->setFigure(bishopBlack, "c8");
	Board->setFigure(bishopBlack, "f8");
	Board->setFigure(queenBlack, "d8");
	Board->setFigure(kingBlack, "e8");
}

std::vector<std::string> ChessMaster::getPossibleMoves(std::string field)
{
	std::vector<std::string> ans;

	std::string namedField[8][8] = {
			"a8", "a7", "a6", "a5", "a4", "a3", "a2", "a1",
			"b8", "b7", "b6", "b5", "b4", "b3", "b2", "b1",
			"c8", "c7", "c6", "c5", "c4", "c3", "c2", "c1",
			"d8", "d7", "d6", "d5", "d4", "d3", "d2", "d1",
			"e8", "e7", "e6", "e5", "e4", "e3", "e2", "e1",
			"f8", "f7", "f6", "f5", "f4", "f3", "f2", "f1",
			"g8", "g7", "g6", "g5", "g4", "g3", "g2", "g1",
			"h8", "h7", "h6", "h5", "h4", "h3", "h2", "h1"
	};

	int iOut, jOut;
	//Пешка?
	if (Board->getField(field).getName() == "Pawn") {
		//Пешка белая?
		Board->coordinateTranslation(field, iOut, jOut);
		if (Board->getField(field).getColor() == ChessColors::WHITE) {
			
			if (jOut - 1 < 8 and jOut - 1 >= 0) {
				//1 ход вперёд
				if (Board->fieldIsEmpty(namedField[iOut][jOut - 1])) {
					ans.push_back(namedField[iOut][jOut - 1]);

					//2 хода вперёд
					if (jOut == 6 and Board->fieldIsEmpty(namedField[iOut][jOut - 2])) {
						ans.push_back(namedField[iOut][jOut - 2]);
					}
				}
			}

			//бьёт влево
			if (iOut - 1 >= 0 and iOut - 1 < 8 and jOut - 1 >= 0 and jOut - 1 < 8) {
				if (Board->getField(namedField[iOut - 1][jOut - 1]).getColor() == ChessColors::BLACK) {
					ans.push_back(namedField[iOut - 1][jOut - 1]);
				}
			}
			//бьёт вправо
			if (iOut + 1 >= 0 and iOut + 1 < 8 and jOut - 1 >= 0 and jOut - 1 < 8) {
				if (Board->getField(namedField[iOut + 1][jOut - 1]).getColor() == ChessColors::BLACK) {
					ans.push_back(namedField[iOut + 1][jOut - 1]);
				}
			}
		}
		//Пешка не белая => Чёрная
		else
		{
			Board->coordinateTranslation(field, iOut, jOut);
			if (jOut + 1 < 8 and jOut + 1 >= 0) {
				//1 ход вперёд
				if (Board->fieldIsEmpty(namedField[iOut][jOut + 1])) {
					ans.push_back(namedField[iOut][jOut + 1]);

					//2 хода вперёд
					if (jOut == 1 and Board->fieldIsEmpty(namedField[iOut][jOut + 2])) {
						ans.push_back(namedField[iOut][jOut + 2]);
					}
				}
			}

			//бьёт вправо
			if (iOut + 1 >= 0 and iOut + 1 < 8 and jOut + 1 >= 0 and jOut + 1 < 8) {
				if (Board->getField(namedField[iOut + 1][jOut + 1]).getColor() == ChessColors::WHITE) {
					ans.push_back(namedField[iOut + 1][jOut + 1]);
				}
			}
			//бьёт влево
			if (iOut - 1 >= 0 and iOut - 1 < 8 and jOut + 1 >= 0 and jOut + 1 < 8) {
				if (Board->getField(namedField[iOut - 1][jOut + 1]).getColor() == ChessColors::WHITE) {
					ans.push_back(namedField[iOut - 1][jOut + 1]);
				}
			}
		}
	}

	//Конь
	if (Board->getField(field).getName() == "Knight")
	{	
		Board->coordinateTranslation(field, iOut, jOut);
		if (iOut + 2 < 8 and iOut + 2 >= 0 and jOut + 1 < 8 and jOut + 1 >= 0 
				and Board->getField(namedField[iOut][jOut]).getColor() != Board->getField(namedField[iOut + 2][jOut + 1]).getColor()) {
			ans.push_back(namedField[iOut + 2][jOut + 1]);
		}
		if (iOut + 2 < 8 and iOut + 2 >= 0 and jOut - 1 < 8 and jOut - 1 >= 0
				and Board->getField(namedField[iOut][jOut]).getColor() != Board->getField(namedField[iOut + 2][jOut - 1]).getColor()) {
			ans.push_back(namedField[iOut + 2][jOut - 1]);
		}

		if (iOut - 2 < 8 and iOut - 2 >= 0 and jOut + 1 < 8 and jOut + 1 >= 0
				and Board->getField(namedField[iOut][jOut]).getColor() != Board->getField(namedField[iOut - 2][jOut + 1]).getColor()) {
			ans.push_back(namedField[iOut - 2][jOut + 1]);
		}
		if (iOut - 2 < 8 and iOut - 2 >= 0 and jOut - 1 < 8 and jOut - 1 >= 0
				and Board->getField(namedField[iOut][jOut]).getColor() != Board->getField(namedField[iOut - 2][jOut - 1]).getColor()) {
			ans.push_back(namedField[iOut - 2][jOut - 1]);
		}
		//-------------------------------------------------------------------------------------------------------------------------------
		if (iOut + 1 < 8 and iOut + 1 >= 0 and jOut + 2 < 8 and jOut + 2 >= 0
				and Board->getField(namedField[iOut][jOut]).getColor() != Board->getField(namedField[iOut + 1][jOut + 2]).getColor()) {
			ans.push_back(namedField[iOut + 1][jOut + 2]);
		}
		if (iOut + 1 < 8 and iOut + 1 >= 0 and jOut - 2 < 8 and jOut - 2 >= 0
				and Board->getField(namedField[iOut][jOut]).getColor() != Board->getField(namedField[iOut + 1][jOut - 2]).getColor()) {
			ans.push_back(namedField[iOut + 1][jOut - 2]);
		}

		if (iOut - 1 < 8 and iOut - 1 >= 0 and jOut + 2 < 8 and jOut + 2 >= 0
				and Board->getField(namedField[iOut][jOut]).getColor() != Board->getField(namedField[iOut - 1][jOut + 2]).getColor()) {
			ans.push_back(namedField[iOut - 1][jOut + 2]);
		}
		if (iOut - 1 < 8 and iOut - 1 >= 0 and jOut - 2 < 8 and jOut - 2 >= 0
				and Board->getField(namedField[iOut][jOut]).getColor() != Board->getField(namedField[iOut - 1][jOut - 2]).getColor()) {
			ans.push_back(namedField[iOut - 1][jOut - 2]);
		}
	}

	//Ладья
	if (Board->getField(field).getName() == "Rook")
	{
		Board->coordinateTranslation(field, iOut, jOut);
		int i = 1;

		while ((iOut + i) >= 0 and (iOut + i) < 8) 
		{
			if (Board->getField(namedField[iOut + i][jOut]).getColor() == ChessColors::SPACE) {
				ans.push_back(namedField[iOut + i][jOut]);
			}
			else {
				if (Board->getField(namedField[iOut + i][jOut]).getColor() != Board->getField(namedField[iOut][jOut]).getColor()) {
					ans.push_back(namedField[iOut + i][jOut]);
					break;
				}
				else {
					break;
				}
			}
			i++;
		}

		i = 1;
		while (iOut - i >= 0 and iOut - i < 8) 
		{
			if (Board->getField(namedField[iOut - i][jOut]).getColor() == ChessColors::SPACE) {
				ans.push_back(namedField[iOut - i][jOut]);
			}
			else {
				if (Board->getField(namedField[iOut - i][jOut]).getColor() != Board->getField(namedField[iOut][jOut]).getColor()) {
					ans.push_back(namedField[iOut - i][jOut]);
					break;
				}
				else {
					break;
				}
			}
			i++;
		}

		i = 1;
		while (jOut - i >= 0 and jOut - i < 8) 
		{
			if (Board->getField(namedField[iOut][jOut - i]).getColor() == ChessColors::SPACE) {
				ans.push_back(namedField[iOut][jOut - i]);
			}
			else {
				if (Board->getField(namedField[iOut][jOut - i]).getColor() != Board->getField(namedField[iOut][jOut]).getColor()) {
					ans.push_back(namedField[iOut][jOut - i]);
					break;
				}
				else {
					break;
				}
			}
			i++;
		}


		i = 1;
		while (jOut + i >= 0 and jOut + i < 8) 
		{
			if (Board->getField(namedField[iOut][jOut + i]).getColor() == ChessColors::SPACE) {
				ans.push_back(namedField[iOut][jOut + i]);
			}
			else {
				if (Board->getField(namedField[iOut][jOut + i]).getColor() != Board->getField(namedField[iOut][jOut]).getColor()) {
					ans.push_back(namedField[iOut][jOut + i]);
					break;
				}
				else {
					break;
				}
			}
			i++;
		}
	}
	
	//Слон
	if (Board->getField(field).getName() == "Bishop")
	{
		Board->coordinateTranslation(field, iOut, jOut);
		int i = 1;

		//++
		while (iOut + i >= 0 and iOut + i < 8 and jOut + i >= 0 and jOut + i < 8)
		{
			if (Board->getField(namedField[iOut + i][jOut + i]).getColor() == ChessColors::SPACE) {
				ans.push_back(namedField[iOut + i][jOut + i]);
			}
			else {
				if (Board->getField(namedField[iOut + i][jOut + i]).getColor() != Board->getField(namedField[iOut][jOut]).getColor()) {
					ans.push_back(namedField[iOut + i][jOut + i]);
					break;
				}
				else {
					break;
				}
			}
			i++;
		}

		//--
		i = 1;
		while (iOut - i >= 0 and iOut - i < 8 and jOut - i >= 0 and jOut - i < 8)
		{
			if (Board->getField(namedField[iOut - i][jOut - i]).getColor() == ChessColors::SPACE) {
				ans.push_back(namedField[iOut - i][jOut - i]);
			}
			else {
				if (Board->getField(namedField[iOut - i][jOut - i]).getColor() != Board->getField(namedField[iOut][jOut]).getColor()) {
					ans.push_back(namedField[iOut - i][jOut - i]);
					break;
				}
				else {
					break;
				}
			}
			i++;
		}

		//+-
		i = 1;
		while (iOut + i >= 0 and iOut + i < 8 and jOut - i >= 0 and jOut - i < 8)
		{
			if (Board->getField(namedField[iOut + i][jOut - i]).getColor() == ChessColors::SPACE) {
				ans.push_back(namedField[iOut + i][jOut - i]);
			}
			else {
				if (Board->getField(namedField[iOut + i][jOut - i]).getColor() != Board->getField(namedField[iOut][jOut]).getColor()) {
					ans.push_back(namedField[iOut + i][jOut - i]);
					break;
				}
				else {
					break;
				}
			}
			i++;
		}

		//-+
		i = 1;
		while (iOut - i >= 0 and iOut - i < 8 and jOut + i >= 0 and jOut + i < 8)
		{
			if (Board->getField(namedField[iOut - i][jOut + i]).getColor() == ChessColors::SPACE) {
				ans.push_back(namedField[iOut - i][jOut + i]);
			}
			else {
				if (Board->getField(namedField[iOut - i][jOut + i]).getColor() != Board->getField(namedField[iOut][jOut]).getColor()) {
					ans.push_back(namedField[iOut - i][jOut + i]);
					break;
				}
				else {
					break;
				}
			}
			i++;
		}
	}

	//Ферзь
	if (Board->getField(field).getName() == "Queen")
	{
		Board->coordinateTranslation(field, iOut, jOut);

		//++
		int i = 1;
		while (iOut + i >= 0 and iOut + i < 8 and jOut + i >= 0 and jOut + i < 8)
		{
			if (Board->getField(namedField[iOut + i][jOut + i]).getColor() == ChessColors::SPACE) {
				ans.push_back(namedField[iOut + i][jOut + i]);
			}
			else {
				if (Board->getField(namedField[iOut + i][jOut + i]).getColor() != Board->getField(namedField[iOut][jOut]).getColor()) {
					ans.push_back(namedField[iOut + i][jOut + i]);
					break;
				}
				else {
					break;
				}
			}
			i++;
		}

		//--
		i = 1;
		while (iOut - i >= 0 and iOut - i < 8 and jOut - i >= 0 and jOut - i < 8)
		{
			if (Board->getField(namedField[iOut - i][jOut - i]).getColor() == ChessColors::SPACE) {
				ans.push_back(namedField[iOut - i][jOut - i]);
			}
			else {
				if (Board->getField(namedField[iOut - i][jOut - i]).getColor() != Board->getField(namedField[iOut][jOut]).getColor()) {
					ans.push_back(namedField[iOut - i][jOut - i]);
					break;
				}
				else {
					break;
				}
			}
			i++;
		}

		//+-
		i = 1;
		while (iOut + i >= 0 and iOut + i < 8 and jOut - i >= 0 and jOut - i < 8)
		{
			if (Board->getField(namedField[iOut + i][jOut - i]).getColor() == ChessColors::SPACE) {
				ans.push_back(namedField[iOut + i][jOut - i]);
			}
			else {
				if (Board->getField(namedField[iOut + i][jOut - i]).getColor() != Board->getField(namedField[iOut][jOut]).getColor()) {
					ans.push_back(namedField[iOut + i][jOut - i]);
					break;
				}
				else {
					break;
				}
			}
			i++;
		}

		//-+
		i = 1;
		while (iOut - i >= 0 and iOut - i < 8 and jOut + i >= 0 and jOut + i < 8)
		{
			if (Board->getField(namedField[iOut - i][jOut + i]).getColor() == ChessColors::SPACE) {
				ans.push_back(namedField[iOut - i][jOut + i]);
			}
			else {
				if (Board->getField(namedField[iOut - i][jOut + i]).getColor() != Board->getField(namedField[iOut][jOut]).getColor()) {
					ans.push_back(namedField[iOut - i][jOut + i]);
					break;
				}
				else {
					break;
				}
			}
			i++;
		}

		i = 1;
		while ((iOut + i) >= 0 and (iOut + i) < 8)
		{
			if (Board->getField(namedField[iOut + i][jOut]).getColor() == ChessColors::SPACE) {
				ans.push_back(namedField[iOut + i][jOut]);
			}
			else {
				if (Board->getField(namedField[iOut + i][jOut]).getColor() != Board->getField(namedField[iOut][jOut]).getColor()) {
					ans.push_back(namedField[iOut + i][jOut]);
					break;
				}
				else {
					break;
				}
			}
			i++;
		}

		i = 1;
		while (iOut - i >= 0 and iOut - i < 8)
		{
			if (Board->getField(namedField[iOut - i][jOut]).getColor() == ChessColors::SPACE) {
				ans.push_back(namedField[iOut - i][jOut]);
			}
			else {
				if (Board->getField(namedField[iOut - i][jOut]).getColor() != Board->getField(namedField[iOut][jOut]).getColor()) {
					ans.push_back(namedField[iOut - i][jOut]);
					break;
				}
				else {
					break;
				}
			}
			i++;
		}

		i = 1;
		while (jOut - i >= 0 and jOut - i < 8)
		{
			if (Board->getField(namedField[iOut][jOut - i]).getColor() == ChessColors::SPACE) {
				ans.push_back(namedField[iOut][jOut - i]);
			}
			else {
				if (Board->getField(namedField[iOut][jOut - i]).getColor() != Board->getField(namedField[iOut][jOut]).getColor()) {
					ans.push_back(namedField[iOut][jOut - i]);
					break;
				}
				else {
					break;
				}
			}
			i++;
		}


		i = 1;
		while (jOut + i >= 0 and jOut + i < 8)
		{
			if (Board->getField(namedField[iOut][jOut + i]).getColor() == ChessColors::SPACE) {
				ans.push_back(namedField[iOut][jOut + i]);
			}
			else {
				if (Board->getField(namedField[iOut][jOut + i]).getColor() != Board->getField(namedField[iOut][jOut]).getColor()) {
					ans.push_back(namedField[iOut][jOut + i]);
					break;
				}
				else {
					break;
				}
			}
			i++;
		}
	}

	//Король
	if (Board->getField(field).getName() == "King")
	{
		Board->coordinateTranslation(field, iOut, jOut);
		
		//+0
		if (iOut + 1 >= 0 and iOut + 1 < 8 
				and (Board->getField(namedField[iOut + 1][jOut]).getColor() == ChessColors::SPACE 
					or Board->getField(namedField[iOut + 1][jOut]).getColor() != Board->getField(namedField[iOut][jOut]).getColor())) {
			ans.push_back(namedField[iOut + 1][jOut]);
		}
		//0+
		if (jOut + 1 >= 0 and jOut + 1 < 8
			and (Board->getField(namedField[iOut][jOut+1]).getColor() == ChessColors::SPACE
				or Board->getField(namedField[iOut][jOut+1]).getColor() != Board->getField(namedField[iOut][jOut]).getColor())) {
			ans.push_back(namedField[iOut][jOut+1]);
		}
		//-0
		if (iOut - 1 >= 0 and iOut - 1 < 8
			and (Board->getField(namedField[iOut - 1][jOut]).getColor() == ChessColors::SPACE
				or Board->getField(namedField[iOut - 1][jOut]).getColor() != Board->getField(namedField[iOut][jOut]).getColor())) {
			ans.push_back(namedField[iOut - 1][jOut]);
		}
		//0-
		if (jOut - 1 >= 0 and jOut - 1 < 8
			and (Board->getField(namedField[iOut][jOut - 1]).getColor() == ChessColors::SPACE
				or Board->getField(namedField[iOut][jOut - 1]).getColor() != Board->getField(namedField[iOut][jOut]).getColor())) {
			ans.push_back(namedField[iOut][jOut - 1]);
		}
		//++
		if (iOut + 1 >= 0 and iOut + 1 < 8 and jOut + 1 >= 0 and jOut + 1 < 8
			and (Board->getField(namedField[iOut + 1][jOut + 1]).getColor() == ChessColors::SPACE
				or Board->getField(namedField[iOut + 1][jOut + 1]).getColor() != Board->getField(namedField[iOut][jOut]).getColor())) {
			ans.push_back(namedField[iOut + 1][jOut + 1]);
		}
		//--
		if (iOut - 1 >= 0 and iOut - 1 < 8 and jOut - 1 >= 0 and jOut - 1 < 8
			and (Board->getField(namedField[iOut - 1][jOut - 1]).getColor() == ChessColors::SPACE
				or Board->getField(namedField[iOut - 1][jOut - 1]).getColor() != Board->getField(namedField[iOut][jOut]).getColor())) {
			ans.push_back(namedField[iOut - 1][jOut - 1]);
		}
		//+-
		if (iOut + 1 >= 0 and iOut + 1 < 8 and jOut - 1 >= 0 and jOut - 1 < 8
			and (Board->getField(namedField[iOut + 1][jOut - 1]).getColor() == ChessColors::SPACE
				or Board->getField(namedField[iOut + 1][jOut - 1]).getColor() != Board->getField(namedField[iOut][jOut]).getColor())) {
			ans.push_back(namedField[iOut + 1][jOut - 1]);
		}
		//-+
		if (iOut - 1 >= 0 and iOut - 1 < 8 and jOut + 1 >= 0 and jOut + 1 < 8
			and (Board->getField(namedField[iOut - 1][jOut + 1]).getColor() == ChessColors::SPACE
				or Board->getField(namedField[iOut - 1][jOut + 1]).getColor() != Board->getField(namedField[iOut][jOut]).getColor())) {
			ans.push_back(namedField[iOut - 1][jOut + 1]);
		}
	}

	return ans;
}

void ChessMaster::makeAMove(std::string firstPos, std::string secondPos)
{
	//Создание вектора возможных ходов фигуры
	std::vector<std::string> posible;
	posible = this->getPossibleMoves(firstPos);

	//проверка разрешения на ход
	for (std::vector <std::string>::iterator it = posible.begin(); it != posible.end(); it++) {
		if (secondPos == *it) {

			int iOut, jOut;
			Board->coordinateTranslation(secondPos, iOut, jOut);

			Board->Board[iOut][jOut] = Board->getFieldPointer(firstPos);
			Board->setFigure(S, firstPos);
		}
	}
}

ChessColors ChessMaster::isCheck()
{
	std::string namedField[8][8] = {
		"a8", "a7", "a6", "a5", "a4", "a3", "a2", "a1",
		"b8", "b7", "b6", "b5", "b4", "b3", "b2", "b1",
		"c8", "c7", "c6", "c5", "c4", "c3", "c2", "c1",
		"d8", "d7", "d6", "d5", "d4", "d3", "d2", "d1",
		"e8", "e7", "e6", "e5", "e4", "e3", "e2", "e1",
		"f8", "f7", "f6", "f5", "f4", "f3", "f2", "f1",
		"g8", "g7", "g6", "g5", "g4", "g3", "g2", "g1",
		"h8", "h7", "h6", "h5", "h4", "h3", "h2", "h1"
	};

	std::vector <std::string> goodFields;

	std::string blackKingField;
	std::string whiteKingField;


	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (Board->getField(namedField[i][j]).getColor() == ChessColors::BLACK and 
				Board->getField(namedField[i][j]).getName() == "King") {
				blackKingField = namedField[i][j];
				break;
			}
		}
	}
	
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (Board->getField(namedField[i][j]).getColor() == ChessColors::WHITE and
				Board->getField(namedField[i][j]).getName() == "King") {
				whiteKingField = namedField[i][j];
				break;
			}
		}
	}

	std::vector<std::string> ans;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {

			ans = this->getPossibleMoves(namedField[i][j]);
			
			if (this->Board->getField(namedField[i][j]).getColor() == ChessColors::BLACK) {
				for (std::vector<std::string>::iterator it = ans.begin(); it != ans.end(); it++) {
					if (*it == whiteKingField)
					{
						return ChessColors::WHITE;
					}
				}
			}
			if (this->Board->getField(namedField[i][j]).getColor() == ChessColors::WHITE) {
				for (std::vector<std::string>::iterator it = ans.begin(); it != ans.end(); it++) {
					if (*it == blackKingField)
					{
						return ChessColors::BLACK;
					}
				}
			}
		}
	}

	return ChessColors::SPACE;
}

ChessColors ChessMaster::isCheckAfterMove(std::string firstPos, std::string secondPos) {

	ChessBoard B1 = *Board;
	ChessMaster Master(B1);

	Master.makeAMove(firstPos, secondPos);
	return Master.isCheck();
}

std::vector<std::string> ChessMaster::getRealPossibleMoves(std::string pos)
{
	std::vector <std::string> ans = this->getPossibleMoves(pos);
	
	for (auto it = ans.begin(); it != ans.end(); it++) {
		if ((isCheckAfterMove(pos, *it) == Board->getField(pos).getColor()) and !ans.empty()) {
			ans.erase(it);
		}
	}

	return ans;
}