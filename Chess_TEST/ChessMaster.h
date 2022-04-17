#pragma once
#include <string>
#include <vector>
#include "ChessBoard.h"
#include "ChessFigure.h"

class ChessMaster
{
private:
	bool move;

	//��������� �� �����, �� ������� ���������� ����
	ChessBoard *Board;

	//������ ����
	Space S;

	//�����
	Pawn pawnBlack;
	Pawn pawnWhite;

	//�����
	Bishop bishopBlack;
	Bishop bishopWhite;

	//����
	Knight knightBlack;
	Knight knightWhite;

	//�����
	Queen queenBlack;
	Queen queenWhite;

	//�����
	Rook rookBlack;
	Rook rookWhite;

	//������
	King kingBlack;
	King kingWhite;

	/*������ ���� ����� �� �����
	std::vector <ChessFigure> figures;*/

public:
	void standardInitialization();

	//��������� ����
	std::vector <std::string> getPossibleMoves(std::string);

	//������� ��� �� ���������
	void makeAMove(std::string, std::string);

	//��� �� ������
	ChessColors isCheck();

	ChessMaster(ChessBoard&);

	ChessColors isCheckAfterMove(std::string firstPos, std::string secondPos);

	std::vector <std::string> getRealPossibleMoves(std::string);

	~ChessMaster();
};