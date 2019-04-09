#include "GameRules.h"

#include <iostream>

bool onBoard(int rank, int file) {
	if ((rank < 0) || (rank > 7) || (file < 0) || (file > 7))
		return false;
	return true;
}

chess::GameManager::Piece::Piece(Type piece_type, Color piece_color) {
	this->piece_type = piece_type;
	this->piece_color = piece_color;
}

chess::Type chess::GameManager::Piece::getType() {
	return piece_type;
}

chess::Color chess::GameManager::Piece::getColor()
{
	return piece_color;
}

chess::GameManager::King::King(Color piece_color) : Piece(Type::King, piece_color) {
	possible_directions.push_back(std::make_tuple( 1, 0));
	possible_directions.push_back(std::make_tuple(-1, 0));
	possible_directions.push_back(std::make_tuple( 0, 1));
	possible_directions.push_back(std::make_tuple( 0,-1));
	possible_directions.push_back(std::make_tuple( 1, 1));
	possible_directions.push_back(std::make_tuple( 1,-1));
	possible_directions.push_back(std::make_tuple(-1, 1));
	possible_directions.push_back(std::make_tuple(-1,-1));
}

bool chess::GameManager::King::can_jump_blocks() {
	return true;
}

std::vector<std::tuple<int, int>> chess::GameManager::King::getMoveDirections() {
	return possible_directions;
}

chess::GameManager::Queen::Queen(Color piece_color) : Piece(Type::Queen, piece_color) {
	possible_directions.push_back(std::make_tuple( 1, 0));
	possible_directions.push_back(std::make_tuple(-1, 0));
	possible_directions.push_back(std::make_tuple( 0, 1));
	possible_directions.push_back(std::make_tuple( 0,-1));
	possible_directions.push_back(std::make_tuple( 1, 1));
	possible_directions.push_back(std::make_tuple( 1,-1));
	possible_directions.push_back(std::make_tuple(-1, 1));
	possible_directions.push_back(std::make_tuple(-1,-1));
}

bool chess::GameManager::Queen::can_jump_blocks() {
	return false;
}

std::vector<std::tuple<int, int>> chess::GameManager::Queen::getMoveDirections() {
	return possible_directions;
}

chess::GameManager::Rook::Rook(Color piece_color) : Piece(Type::Rook, piece_color) {
	possible_directions.push_back(std::make_tuple( 1, 0));
	possible_directions.push_back(std::make_tuple(-1, 0));
	possible_directions.push_back(std::make_tuple( 0, 1));
	possible_directions.push_back(std::make_tuple( 0,-1));
}

bool chess::GameManager::Rook::can_jump_blocks() {
	return false;
}

std::vector<std::tuple<int, int>> chess::GameManager::Rook::getMoveDirections() {
	return possible_directions;
}

chess::GameManager::Bishop::Bishop(Color piece_color) : Piece(Type::Bishop, piece_color) {
	possible_directions.push_back(std::make_tuple( 1, 1));
	possible_directions.push_back(std::make_tuple( 1,-1));
	possible_directions.push_back(std::make_tuple(-1, 1));
	possible_directions.push_back(std::make_tuple(-1,-1));
}

bool chess::GameManager::Bishop::can_jump_blocks() {
	return false;
}

std::vector<std::tuple<int, int>> chess::GameManager::Bishop::getMoveDirections() {
	return possible_directions;
}

chess::GameManager::Knight::Knight(Color piece_color) : Piece(Type::Knight, piece_color) {
	possible_directions.push_back(std::make_tuple( 2, 1));
	possible_directions.push_back(std::make_tuple( 2,-1));
	possible_directions.push_back(std::make_tuple(-2, 1));
	possible_directions.push_back(std::make_tuple(-2,-1));
	possible_directions.push_back(std::make_tuple( 1, 2));
	possible_directions.push_back(std::make_tuple( 1,-2));
	possible_directions.push_back(std::make_tuple(-1, 2));
	possible_directions.push_back(std::make_tuple(-1,-2));
}

bool chess::GameManager::Knight::can_jump_blocks() {
	return true;
}

std::vector<std::tuple<int, int>> chess::GameManager::Knight::getMoveDirections() {
	return possible_directions;
}

chess::GameManager::Pawn::Pawn(Color piece_color) : Piece(Type::Pawn, piece_color) {
	if (piece_color == Color::White)
		possible_directions.push_back(std::make_tuple(1, 0));
	else
		possible_directions.push_back(std::make_tuple(-1, 0));
}

bool chess::GameManager::Pawn::can_jump_blocks() {
	return true;
}

std::vector<std::tuple<int, int>> chess::GameManager::Pawn::getMoveDirections() {
	return possible_directions;
}

chess::GameManager::Move::Move() {
	moving_piece = nullptr;
	captured_piece = nullptr;
}

chess::GameManager::Move::Move(std::tuple<int, int> src, std::tuple<int, int> des, Piece * moving_piece, Piece * captured_piece) {
	this->src = src;
	this->des = des;
	this->moving_piece = moving_piece;
	this->captured_piece = captured_piece;
}

bool chess::GameManager::Move::isInvalid() {
	return (moving_piece == nullptr);
}

std::tuple<int, int> chess::GameManager::Move::getSrc() {
	return src;
}

std::tuple<int, int> chess::GameManager::Move::getDes() {
	return des;
}

chess::GameManager::Piece * chess::GameManager::Move::getMovingPiece() {
	return moving_piece;
}

chess::GameManager::Piece * chess::GameManager::Move::getCapturedPiece() {
	return captured_piece;
}

chess::GameManager::Board::Board() {
	squares[0][0].piece_placed = new GameManager::Rook(Color::White);
	squares[0][1].piece_placed = new GameManager::Knight(Color::White);
	squares[0][2].piece_placed = new GameManager::Bishop(Color::White);
	squares[0][3].piece_placed = new GameManager::Queen(Color::White);
	squares[0][4].piece_placed = new GameManager::King(Color::White);
	squares[0][5].piece_placed = new GameManager::Bishop(Color::White);
	squares[0][6].piece_placed = new GameManager::Knight(Color::White);
	squares[0][7].piece_placed = new GameManager::Rook(Color::White);
	squares[1][0].piece_placed = new GameManager::Pawn(Color::White);
	squares[1][1].piece_placed = new GameManager::Pawn(Color::White);
	squares[1][2].piece_placed = new GameManager::Pawn(Color::White);
	squares[1][3].piece_placed = new GameManager::Pawn(Color::White);
	squares[1][4].piece_placed = new GameManager::Pawn(Color::White);
	squares[1][5].piece_placed = new GameManager::Pawn(Color::White);
	squares[1][6].piece_placed = new GameManager::Pawn(Color::White);
	squares[1][7].piece_placed = new GameManager::Pawn(Color::White);

	for (int i = 0; i < 8; i++) {
		for (int j = 2; j <= 5; j++) {
			squares[j][i].piece_placed = nullptr;
		}
	}

	squares[7][0].piece_placed = new GameManager::Rook(Color::Black);
	squares[7][1].piece_placed = new GameManager::Knight(Color::Black);
	squares[7][2].piece_placed = new GameManager::Bishop(Color::Black);
	squares[7][3].piece_placed = new GameManager::Queen(Color::Black);
	squares[7][4].piece_placed = new GameManager::King(Color::Black);
	squares[7][5].piece_placed = new GameManager::Bishop(Color::Black);
	squares[7][6].piece_placed = new GameManager::Knight(Color::Black);
	squares[7][7].piece_placed = new GameManager::Rook(Color::Black);
	squares[6][0].piece_placed = new GameManager::Pawn(Color::Black);
	squares[6][1].piece_placed = new GameManager::Pawn(Color::Black);
	squares[6][2].piece_placed = new GameManager::Pawn(Color::Black);
	squares[6][3].piece_placed = new GameManager::Pawn(Color::Black);
	squares[6][4].piece_placed = new GameManager::Pawn(Color::Black);
	squares[6][5].piece_placed = new GameManager::Pawn(Color::Black);
	squares[6][6].piece_placed = new GameManager::Pawn(Color::Black);
	squares[6][7].piece_placed = new GameManager::Pawn(Color::Black);

	for (int i = 0; i < 8; i++) {
		all_pieces.push_back(squares[0][i].piece_placed);
		all_pieces.push_back(squares[1][i].piece_placed);
		all_pieces.push_back(squares[6][i].piece_placed);
		all_pieces.push_back(squares[7][i].piece_placed);
	}
}

std::vector<std::tuple<int, int>> chess::GameManager::Board::getValidMoves(std::tuple<int, int> block) {
	int rank = std::get<0>(block), file = std::get<1>(block);
	std::vector<std::tuple<int, int>> ret_vector;
	chess::GameManager::Piece *piece = squares[rank][file].piece_placed;
	
	if (piece == nullptr) {
		return ret_vector;
	}

	std::vector<std::tuple<int, int>> dir_vector = piece->getMoveDirections();

	for (auto itr = dir_vector.begin(); itr != dir_vector.end(); itr++) {
		int rank_disp = std::get<0>(*itr), file_disp = std::get<1>(*itr);
		
		if (piece->can_jump_blocks()) {
			int new_rank = rank + rank_disp, new_file = file + file_disp;

			if (!onBoard(new_rank, new_file))
				continue;
			
			if (squares[new_rank][new_file].piece_placed == nullptr) {
				ret_vector.push_back(std::make_tuple(new_rank, new_file));
			} else if (squares[new_rank][new_file].piece_placed->getColor() != piece->getColor()) {
				ret_vector.push_back(std::make_tuple(new_rank, new_file));
			}
		} else {
			for (int i = 1; i <= 7; i++) {
				int new_rank = rank + rank_disp * i, new_file = file + file_disp * i;
				
				if (!onBoard(new_rank, new_file))
					break;

				if (squares[new_rank][new_file].piece_placed == nullptr) {
					ret_vector.push_back(std::make_tuple(new_rank, new_file));
				} else if (squares[new_rank][new_file].piece_placed->getColor() != piece->getColor()) {
					ret_vector.push_back(std::make_tuple(new_rank, new_file));
					break;
				} else {
					break;
				}
			}
		}
	}

	if (piece->getType() == chess::Type::Pawn) {
		int new_rank = rank + ((piece->getColor() == chess::Color::White) ? (1) : (-1));
		int new_file = file + 1;
		
		if ((onBoard(new_rank, new_file)) && (squares[new_rank][new_file].piece_placed != nullptr) && (squares[new_rank][new_file].piece_placed->getColor() != piece->getColor()))
			ret_vector.push_back(std::make_tuple(new_rank, new_file));
		
		new_file = file - 1;

		if ((onBoard(new_rank, new_file)) && (squares[new_rank][new_file].piece_placed != nullptr) && (squares[new_rank][new_file].piece_placed->getColor() != piece->getColor()))
			ret_vector.push_back(std::make_tuple(new_rank, new_file));

	}

	return ret_vector;
}

chess::GameManager::Move chess::GameManager::Board::move(std::tuple<int, int> src, std::tuple<int, int> des) {
	int old_rank = std::get<0>(src), old_file = std::get<1>(src);
	int new_rank = std::get<0>(des), new_file = std::get<1>(des);

	if ((!onBoard(old_rank, old_file)) || (!onBoard(new_rank, new_file)))
		return Move();
	if (squares[old_rank][new_rank].piece_placed != nullptr)
		return Move();

	std::vector<std::tuple<int, int>> possible_moves = this->getValidMoves(src);
	if (std::find(possible_moves.begin(), possible_moves.end(), des) == possible_moves.end())
		return Move();

	Piece *moving_piece = squares[old_rank][old_file].piece_placed, *captured_piece = squares[new_rank][new_file].piece_placed;

	squares[new_rank][new_file].piece_placed = squares[old_rank][old_file].piece_placed;
	squares[old_rank][old_file].piece_placed = nullptr;

	return Move(src, des, moving_piece, captured_piece);
}

void chess::GameManager::Board::display() {
	chess::GameManager::Piece *piece;
	for (int i = 7; i >= 0; i--) {
		for (int j = 0; j < 8; j++) {
			piece = squares[i][j].piece_placed;
			if (piece == nullptr) {
				std::cout << " __ ";
			} else {
				std::cout << " ";
				switch (piece->getType())
				{
				case chess::Type::King:
					std::cout << "K";
					break;
				case chess::Type::Queen:
					std::cout << "Q";
					break;
				case chess::Type::Rook:
					std::cout << "R";
					break;
				case chess::Type::Bishop:
					std::cout << "B";
					break;
				case chess::Type::Knight:
					std::cout << "H";
					break;
				case chess::Type::Pawn:
					std::cout << "P";
					break;
				default:
					break;
				}
				switch (piece->getColor())
				{
				case chess::Color::White:
					std::cout << "1";
					break;
				case chess::Color::Black:
					std::cout << "2";
					break;
				default:
					break;
				}
				std::cout << " ";
			}
		}
		std::cout << std::endl;
	}
}

chess::GameManager::GameManager() {
	turn = chess::Color::White;
}

void chess::GameManager::display() {
	board.display();
}

void chess::GameManager::getMoves(std::tuple<int, int> block) {
	std::vector<std::tuple<int, int>> possible_moves = board.getValidMoves(block);
	for (auto itr = possible_moves.begin(); itr != possible_moves.end(); itr++) {
		std::cout << std::get<0>(*itr) << " " << std::get<1>(*itr) << std::endl;
	}
}

void chess::GameManager::move(std::tuple<int, int> src, std::tuple<int, int> des) {
	board.move(src, des);
}
