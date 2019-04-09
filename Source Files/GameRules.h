#pragma once

#include <vector>
#include <tuple>
#include <stack>

namespace chess {
	enum Color { Black, White };
	enum Type { King, Queen, Rook, Bishop, Knight, Pawn };

	class GameManager {
		class Piece {
		protected:
			Type piece_type;
			Color piece_color;
			std::vector<std::tuple<int, int>> possible_directions;
		public:
			Piece(Type piece_type, Color piece_color);
			Type getType();
			Color getColor();
			virtual bool can_jump_blocks() = 0;
			virtual std::vector<std::tuple<int, int>> getMoveDirections() = 0;
		};
		class King : public Piece {
		public:
			King(Color piece_color);
			bool can_jump_blocks();
			std::vector<std::tuple<int, int>> getMoveDirections();
		};
		class Queen : public Piece {
		public:
			Queen(Color piece_color);
			bool can_jump_blocks();
			std::vector<std::tuple<int, int>> getMoveDirections();
		};
		class Rook : public Piece {
		public:
			Rook(Color piece_color);
			bool can_jump_blocks();
			std::vector<std::tuple<int, int>> getMoveDirections();
		};
		class Bishop : public Piece {
		public:
			Bishop(Color piece_color);
			bool can_jump_blocks();
			std::vector<std::tuple<int, int>> getMoveDirections();
		};
		class Knight : public Piece {
		public:
			Knight(Color piece_color);
			bool can_jump_blocks();
			std::vector<std::tuple<int, int>> getMoveDirections();
		};
		class Pawn : public Piece {
		public:
			Pawn(Color piece_color);
			bool can_jump_blocks();
			std::vector<std::tuple<int, int>> getMoveDirections();
		};
		class Move {
			std::tuple <int, int> src, des;
			Piece *moving_piece, *captured_piece;
		public:
			Move();
			Move(std::tuple<int, int> src, std::tuple<int, int> des, Piece *moving_piece, Piece *captured_piece);
			bool isInvalid();
			std::tuple<int, int> getSrc();
			std::tuple<int, int> getDes();
			Piece* getMovingPiece();
			Piece* getCapturedPiece();
		};
		class Board {
		private:
			std::vector<Piece*> all_pieces;
			class Square {
			private:
				Piece* piece_placed;
				friend class Board;
			};
			Square squares[8][8];
			std::vector<std::tuple<int, int>> getValidMoves(std::tuple<int, int> block);
		public:
			Board();
			Move move(std::tuple<int, int> src, std::tuple<int, int> des);
			void display();

			friend class GameManager;
		};

		Board board;
		Color turn;
		std::stack<Move> previous_moves;

	public:
		GameManager();
		void display();
		void getMoves(std::tuple<int, int> block);
		void move(std::tuple<int, int> src, std::tuple<int, int> des);
	};
}
