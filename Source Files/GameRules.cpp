#include "GameRules.h"

void ChessBoard::Square::place_piece() {

}

void ChessBoard::Square::remove_piece() {

}

std::vector<ChessBoard::Cord> ChessBoard::King::getMoves() {
	return std::vector<Cord>();
}

void ChessBoard::Piece::move(Cord dest) {

}

std::vector<ChessBoard::Cord> ChessBoard::Queen::getMoves() {
	return std::vector<Cord>();
}

std::vector<ChessBoard::Cord> ChessBoard::Rook::getMoves() {
	return std::vector<Cord>();
}

std::vector<ChessBoard::Cord> ChessBoard::Knight::getMoves() {
	return std::vector<Cord>();
}

std::vector<ChessBoard::Cord> ChessBoard::Bishop::getMoves() {
	return std::vector<Cord>();
}

std::vector<ChessBoard::Cord> ChessBoard::Pawn::getMoves() {
	return std::vector<Cord>();
}

bool ChessBoard::Piece::getCheckStatus(Cord dest) {
	return false;
}
