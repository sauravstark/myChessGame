#pragma once
#include <vector>
#include <tuple>

namespace chess {

	enum Color { black, white };
	enum Type { king, queen, rook, bishop, knight, pawn };

	class Piece {
		friend class Player;
		friend class Board;
	protected:
		Type piece_type;
		Color piece_color;
		std::vector<std::tuple<int, int>> possible_directions;
		std::tuple<int, int> current_block;
		std::vector<std::tuple<int, int>> valid_moves;
	public:
		Piece(Type piece_type, Color piece_color);
		virtual Type getType();
		Color getColor();
		std::vector<std::tuple<int, int>> getValidMoves();
		virtual bool canMoveOneBlock() = 0;
		std::vector<std::tuple<int, int>> getMoveDirections();
	};
	class King : public Piece {
	public:
		King(Color piece_color);
		bool canMoveOneBlock();
	};
	class Queen : public Piece {
	public:
		Queen(Color piece_color);
		bool canMoveOneBlock();
	};
	class Rook : public Piece {
	public:
		Rook(Color piece_color);
		bool canMoveOneBlock();
	};
	class Bishop : public Piece {
	public:
		Bishop(Color piece_color);
		bool canMoveOneBlock();
	};
	class Knight : public Piece {
	public:
		Knight(Color piece_color);
		bool canMoveOneBlock();
	};
	class Pawn : public Piece {
		bool promoted;
		Type promoted_to;
	public:
		Pawn(Color piece_color);
		bool canMoveOneBlock();
	};
}
