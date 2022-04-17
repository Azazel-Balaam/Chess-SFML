#include "ChessFigure.h"
#include <string>

ChessFigure::ChessFigure()
{
}

ChessFigure::~ChessFigure()
{
}

//���������� ���
std::string ChessFigure::getName()
{
	return name;
}

ChessColors ChessFigure::getColor()
{
	return �olor;
}

//������ ����
Space::Space()
{
	name = "Space";
	�olor = SPACE;
}

//�����
Rook::Rook(ChessColors _�olor)
{	
	name = "Rook";
	�olor = _�olor;
}

//�����
Pawn::Pawn(ChessColors _�olor)
{
	name = "Pawn";
	�olor = _�olor;
};

//����
Knight::Knight(ChessColors _color)
{
	name = "Knight";
	�olor = _color;
};

//����
Bishop::Bishop(ChessColors _color)
{
	name = "Bishop";
	�olor = _color;
};

//�����
Queen::Queen(ChessColors _color)
{
	name = "Queen";
	�olor = _color;
}

//������
King::King(ChessColors  _color)
{
	name = "King";
	�olor = _color;
}

bool operator==(const ChessFigure &A, const ChessFigure &B)
{
	return (A.name == B.name and A.�olor == B.�olor);
}
