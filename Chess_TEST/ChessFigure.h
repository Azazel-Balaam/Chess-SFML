#pragma once
#include <string>

enum ChessColors
{
	WHITE,
	BLACK,
	SPACE,
};

//Класс Фигуры
class ChessFigure
{
protected:
	std::string name;
	ChessColors сolor;

public:
	ChessFigure();
	~ChessFigure();
	//Получить имя фигуры
	std::string getName();

	//Получить цвет фигуры
	ChessColors getColor();
	
	//Переопределение оператора сравнения
	friend bool operator== (const ChessFigure&, const ChessFigure&);
};

//Класс Пустое поле
class Space : public ChessFigure {
	using ChessFigure::name;
	using ChessFigure::сolor;

public:
	Space();
};

//Класс Ладья
class Rook : public ChessFigure {
	using ChessFigure::name;
	using ChessFigure::сolor;

public:
	Rook(ChessColors);
};

//Класс Пешка
class Pawn : public ChessFigure {
	using ChessFigure::name;
	using ChessFigure::сolor;

public:
	Pawn(ChessColors);
};

//Класс Коня
class Knight : public ChessFigure {
	using ChessFigure::name;
	using ChessFigure::сolor;

public:
	Knight(ChessColors);
};

//Класс Слон
class Bishop : public ChessFigure {
	using ChessFigure::name;
	using ChessFigure::сolor;

public:
	Bishop(ChessColors);
};

//Класс Ферзь
class Queen : public ChessFigure {
	using ChessFigure::name;
	using ChessFigure::сolor;

public:
	Queen(ChessColors);
};

//Класс Король
class King : public ChessFigure {
	using ChessFigure::name;
	using ChessFigure::сolor;

public:
	King(ChessColors);
};