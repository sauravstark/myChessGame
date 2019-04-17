#include "Pieces.h"

chess::Piece::Piece(Type piece_type, Color piece_color) {
	this->piece_type = piece_type;
	this->piece_color = piece_color;
}

chess::Type chess::Piece::getType() {
	return piece_type;
}

chess::Color chess::Piece::getColor() {
	return piece_color;
}

chess::King::King(Color piece_color) : Piece(Type::king, piece_color) {
	possible_directions.push_back(std::make_tuple(1, 0));
	possible_directions.push_back(std::make_tuple(-1, 0));
	possible_directions.push_back(std::make_tuple(0, 1));
	possible_directions.push_back(std::make_tuple(0, -1));
	possible_directions.push_back(std::make_tuple(1, 1));
	possible_directions.push_back(std::make_tuple(1, -1));
	possible_directions.push_back(std::make_tuple(-1, 1));
	possible_directions.push_back(std::make_tuple(-1, -1));
}

bool chess::King::canMoveOneBlock() {
	return true;
}

std::vector<std::tuple<int, int>> chess::King::getMoveDirections() {
	return possible_directions;
}

chess::Queen::Queen(Color piece_color) : Piece(Type::queen, piece_color) {
	possible_directions.push_back(std::make_tuple(1, 0));
	possible_directions.push_back(std::make_tuple(-1, 0));
	possible_directions.push_back(std::make_tuple(0, 1));
	possible_directions.push_back(std::make_tuple(0, -1));
	possible_directions.push_back(std::make_tuple(1, 1));
	possible_directions.push_back(std::make_tuple(1, -1));
	possible_directions.push_back(std::make_tuple(-1, 1));
	possible_directions.push_back(std::make_tuple(-1, -1));
}

bool chess::Queen::canMoveOneBlock() {
	return false;
}

std::vector<std::tuple<int, int>> chess::Queen::getMoveDirections() {
	return possible_directions;
}

chess::Rook::Rook(Color piece_color) : Piece(Type::rook, piece_color) {
	possible_directions.push_back(std::make_tuple(1, 0));
	possible_directions.push_back(std::make_tuple(-1, 0));
	possible_directions.push_back(std::make_tuple(0, 1));
	possible_directions.push_back(std::make_tuple(0, -1));
}

bool chess::Rook::canMoveOneBlock() {
	return false;
}

std::vector<std::tuple<int, int>> chess::Rook::getMoveDirections() {
	return possible_directions;
}

chess::Bishop::Bishop(Color piece_color) : Piece(Type::bishop, piece_color) {
	possible_directions.push_back(std::make_tuple(1, 1));
	possible_directions.push_back(std::make_tuple(1, -1));
	possible_directions.push_back(std::make_tuple(-1, 1));
	possible_directions.push_back(std::make_tuple(-1, -1));
}

bool chess::Bishop::canMoveOneBlock() {
	return false;
}

std::vector<std::tuple<int, int>> chess::Bishop::getMoveDirections() {
	return possible_directions;
}

chess::Knight::Knight(Color piece_color) : Piece(Type::knight, piece_color) {
	possible_directions.push_back(std::make_tuple(2, 1));
	possible_directions.push_back(std::make_tuple(2, -1));
	possible_directions.push_back(std::make_tuple(-2, 1));
	possible_directions.push_back(std::make_tuple(-2, -1));
	possible_directions.push_back(std::make_tuple(1, 2));
	possible_directions.push_back(std::make_tuple(1, -2));
	possible_directions.push_back(std::make_tuple(-1, 2));
	possible_directions.push_back(std::make_tuple(-1, -2));
}

bool chess::Knight::canMoveOneBlock() {
	return true;
}

std::vector<std::tuple<int, int>> chess::Knight::getMoveDirections() {
	return possible_directions;
}

chess::Pawn::Pawn(Color piece_color) : Piece(Type::pawn, piece_color) {
	if (piece_color == Color::white)
		possible_directions.push_back(std::make_tuple(1, 0));
	else
		possible_directions.push_back(std::make_tuple(-1, 0));
}

bool chess::Pawn::canMoveOneBlock() {
	return true;
}

std::vector<std::tuple<int, int>> chess::Pawn::getMoveDirections() {
	return possible_directions;
}
