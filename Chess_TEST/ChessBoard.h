#pragma once
#include "ChessFigure.h"
#include <string>

class ChessMaster;

class ChessBoard
{
	//Объявляем дружественный класс МастерШахмат
	friend class ChessMaster;

private:
	//Доска
	ChessFigure *Board[8][8];

	//Экземпляр класса Пустое поле для инициализации достки
	Space S;

	//поставить фигуру на поле
	void setFigure(ChessFigure&, std::string);

	ChessFigure *getFieldPointer(std::string str);

public:
	//Перевод шахматных координат в "Массивные"
	void coordinateTranslation(std::string, int&, int&);

	//Вернуть фигруру которая стоит на поле
	ChessFigure getField(std::string);

	//Поле пустое?
	bool fieldIsEmpty(std::string);

	//Переопределение оператора сравнения
	ChessBoard& operator = (const ChessBoard&);

	ChessBoard();
	~ChessBoard();
};