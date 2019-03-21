#pragma once

#include<vector>

class ChessBoard {
	enum PieceColor {black, white};

	enum PieceType {king, queen, rook, knight, bishop, pawn};

	struct Cord {
		int row, col;
	};

	class Square {
	private:
		bool isOccupied;
		PieceColor color;
	public:
		void place_piece();
		void remove_piece();
	};

	class Piece {
		PieceColor color;
		bool isCaptured;
		Cord pos;
		PieceType type;
		virtual std::vector<Cord> getMoves() = 0;
		virtual void move(Cord dest);
		bool getCheckStatus(Cord dest);
	};

	class King : public Piece {
		std::vector<Cord> getMoves();
	};

	class Queen : public Piece {
		std::vector<Cord> getMoves();
	};

	class Rook : public Piece {
		std::vector<Cord> getMoves();
	};

	class Knight : public Piece {
		std::vector<Cord> getMoves();
	};

	class Bishop : public Piece {
		std::vector<Cord> getMoves();
	};

	class Pawn : public Piece {
		std::vector<Cord> getMoves();
	};

	class PieceSet {
		PieceColor color;
		King king;
		Queen queen;
		Rook rooks[2];
		Knight knights[2];
		Bishop bishops[2];
		Pawn pawns[8];
	};

	Square board_squares[8][8];
	PieceSet player_black, player_white;
};
