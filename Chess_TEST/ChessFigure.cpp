#include "ChessFigure.h"
#include <string>

ChessFigure::ChessFigure()
{
}

ChessFigure::~ChessFigure()
{
}

//Возвращает имя
std::string ChessFigure::getName()
{
	return name;
}

ChessColors ChessFigure::getColor()
{
	return сolor;
}

//Пустое поле
Space::Space()
{
	name = "Space";
	сolor = SPACE;
}

//Ладья
Rook::Rook(ChessColors _сolor)
{	
	name = "Rook";
	сolor = _сolor;
}

//Пешка
Pawn::Pawn(ChessColors _сolor)
{
	name = "Pawn";
	сolor = _сolor;
};

//Конь
Knight::Knight(ChessColors _color)
{
	name = "Knight";
	сolor = _color;
};

//Слон
Bishop::Bishop(ChessColors _color)
{
	name = "Bishop";
	сolor = _color;
};

//Ферзь
Queen::Queen(ChessColors _color)
{
	name = "Queen";
	сolor = _color;
}

//Король
King::King(ChessColors  _color)
{
	name = "King";
	сolor = _color;
}

bool operator==(const ChessFigure &A, const ChessFigure &B)
{
	return (A.name == B.name and A.сolor == B.сolor);
}
