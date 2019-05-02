#pragma once

#include "Pieces.h"

#include <vector>

namespace chess {
	class Board {
	private:
		class Square {
		private:
			Piece* piece_placed;
		public:
			Piece* getPiece();
			void placePiece(Piece *piece);
			void removePiece();
		};
		Square squares[8][8];
	public:
		Board();
		Piece* getPiece(int rank, int file);
		void placePiece(Piece *piece, int rank, int file);
		void removePiece(int rank, int file);
		void display();
	};
}
