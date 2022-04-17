#pragma once
#include "ChessFigure.h"
#include <string>

class ChessMaster;

class ChessBoard
{
	//��������� ������������� ����� ������������
	friend class ChessMaster;

private:
	//�����
	ChessFigure *Board[8][8];

	//��������� ������ ������ ���� ��� ������������� ������
	Space S;

	//��������� ������ �� ����
	void setFigure(ChessFigure&, std::string);

	ChessFigure *getFieldPointer(std::string str);

public:
	//������� ��������� ��������� � "���������"
	void coordinateTranslation(std::string, int&, int&);

	//������� ������� ������� ����� �� ����
	ChessFigure getField(std::string);

	//���� ������?
	bool fieldIsEmpty(std::string);

	//��������������� ��������� ���������
	ChessBoard& operator = (const ChessBoard&);

	ChessBoard();
	~ChessBoard();
};