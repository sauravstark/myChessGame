#include "GameRules.h"

#include <iostream>

static bool onBoard(int rank, int file) {
	return ((rank >= 0) && (rank < 8) && (file >= 0) && (file < 8));
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

chess::Piece * chess::GameManager::Move::getMovingPiece() {
	return moving_piece;
}

chess::Piece * chess::GameManager::Move::getCapturedPiece() {
	return captured_piece;
}

void chess::GameManager::MakeMove(std::tuple<int, int> src, std::tuple<int, int> des) {
	int src_rank = std::get<0>(src), src_file = std::get<1>(src), des_rank = std::get<0>(des), des_file = std::get<1>(des);
	if ((!onBoard(src_rank, src_file)) || (!onBoard(des_rank, des_file)))
		return;
	Piece* moving_piece = board.getPiece(src_rank, src_file);
	if ((moving_piece != nullptr) && (moving_piece->getColor() == turn)) {
		std::vector<std::tuple<int, int>> valid_moves = moving_piece->getValidMoves();
		if (std::find(valid_moves.begin(), valid_moves.end(), des) != valid_moves.end()) {
			Player& oppenent = ((turn == chess::Color::white) ? team_white : team_black);
			Piece* captured_piece = board.getPiece(des_rank, des_file);
			oppenent.capture(captured_piece);
			board.removePiece(src_rank, src_file);
			board.placePiece(moving_piece, des_rank, des_file);
			turn = ((turn == chess::Color::white) ? chess::Color::black : chess::Color::white);
			previous_moves.push(Move(src, des, moving_piece, captured_piece));
			if (oppenent.updateValidMoves(board)) {
				game_over = true;
			}
		}
	}
}

chess::GameManager::GameManager(): board(),team_white(board, Color::white), team_black(board, Color::black){
	turn = chess::Color::white;
	game_over = false;
}

void chess::GameManager::start() {
	while (!game_over) {
		system("CLS");
		team_white.displayInfo();
		team_black.displayInfo();
		board.display();
		std::cout << "Turn: " << ((turn == chess::Color::white) ? "White" : "Black") << std::endl;
		/*if (turn == chess::Color::white)
			team_white.displayValidMoves();
		else
			team_black.displayValidMoves();*/
		int src_rank, src_file, des_rank, des_file;
		std::cin >> src_rank >> src_file >> des_rank >> des_file;
		this->MakeMove(std::make_tuple(src_rank, src_file), std::make_tuple(des_rank, des_file));
	}
}
