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
