#pragma once
#include <string>
#include <vector>
#include "ChessBoard.h"
#include "ChessFigure.h"

class ChessMaster
{
private:
	bool move;

	//указатель на доску, на которой происходит игра
	ChessBoard *Board;

	//Пустое поле
	Space S;

	//Пешки
	Pawn pawnBlack;
	Pawn pawnWhite;

	//Слоны
	Bishop bishopBlack;
	Bishop bishopWhite;

	//Кони
	Knight knightBlack;
	Knight knightWhite;

	//Ферзи
	Queen queenBlack;
	Queen queenWhite;

	//Ладьи
	Rook rookBlack;
	Rook rookWhite;

	//Короли
	King kingBlack;
	King kingWhite;

	/*Вектор всех фигур на доске
	std::vector <ChessFigure> figures;*/

public:
	void standardInitialization();

	//возможные ходы
	std::vector <std::string> getPossibleMoves(std::string);

	//сделать ход из возможных
	void makeAMove(std::string, std::string);

	//шах ли чёрным
	ChessColors isCheck();

	ChessMaster(ChessBoard&);

	ChessColors isCheckAfterMove(std::string firstPos, std::string secondPos);

	std::vector <std::string> getRealPossibleMoves(std::string);

	~ChessMaster();
};