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
		Type getType();
		Color getColor();
		virtual bool canMoveOneBlock() = 0;
		virtual std::vector<std::tuple<int, int>> getMoveDirections() = 0;
	};
	class King : public Piece {
	public:
		King(Color piece_color);
		bool canMoveOneBlock();
		std::vector<std::tuple<int, int>> getMoveDirections();
	};
	class Queen : public Piece {
	public:
		Queen(Color piece_color);
		bool canMoveOneBlock();
		std::vector<std::tuple<int, int>> getMoveDirections();
	};
	class Rook : public Piece {
	public:
		Rook(Color piece_color);
		bool canMoveOneBlock();
		std::vector<std::tuple<int, int>> getMoveDirections();
	};
	class Bishop : public Piece {
	public:
		Bishop(Color piece_color);
		bool canMoveOneBlock();
		std::vector<std::tuple<int, int>> getMoveDirections();
	};
	class Knight : public Piece {
	public:
		Knight(Color piece_color);
		bool canMoveOneBlock();
		std::vector<std::tuple<int, int>> getMoveDirections();
	};
	class Pawn : public Piece {
	public:
		Pawn(Color piece_color);
		bool canMoveOneBlock();
		std::vector<std::tuple<int, int>> getMoveDirections();
	};
}
