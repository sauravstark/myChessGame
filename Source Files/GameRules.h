#pragma once

#include <stack>
#include "Players.h"

namespace chess {

	class GameManager {
		
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
		Board board;
		Color turn;
		Player team_white, team_black;
		std::stack<Move> previous_moves;
		void MakeMove(std::tuple<int, int> src, std::tuple<int, int> des);
		bool game_over;
	public:
		GameManager();
		void start();
	};
}
