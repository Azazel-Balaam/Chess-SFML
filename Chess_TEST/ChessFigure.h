#pragma once
#include <string>

enum ChessColors
{
	WHITE,
	BLACK,
	SPACE,
};

//����� ������
class ChessFigure
{
protected:
	std::string name;
	ChessColors �olor;

public:
	ChessFigure();
	~ChessFigure();
	//�������� ��� ������
	std::string getName();

	//�������� ���� ������
	ChessColors getColor();
	
	//��������������� ��������� ���������
	friend bool operator== (const ChessFigure&, const ChessFigure&);
};

//����� ������ ����
class Space : public ChessFigure {
	using ChessFigure::name;
	using ChessFigure::�olor;

public:
	Space();
};

//����� �����
class Rook : public ChessFigure {
	using ChessFigure::name;
	using ChessFigure::�olor;

public:
	Rook(ChessColors);
};

//����� �����
class Pawn : public ChessFigure {
	using ChessFigure::name;
	using ChessFigure::�olor;

public:
	Pawn(ChessColors);
};

//����� ����
class Knight : public ChessFigure {
	using ChessFigure::name;
	using ChessFigure::�olor;

public:
	Knight(ChessColors);
};

//����� ����
class Bishop : public ChessFigure {
	using ChessFigure::name;
	using ChessFigure::�olor;

public:
	Bishop(ChessColors);
};

//����� �����
class Queen : public ChessFigure {
	using ChessFigure::name;
	using ChessFigure::�olor;

public:
	Queen(ChessColors);
};

//����� ������
class King : public ChessFigure {
	using ChessFigure::name;
	using ChessFigure::�olor;

public:
	King(ChessColors);
};