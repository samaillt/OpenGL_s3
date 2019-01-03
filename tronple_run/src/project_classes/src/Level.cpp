#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>
#include "project_classes/Level.hpp"

Level::Level(){}
Level::Level(std::string sourceFile){
	_sourceFile = "../src/assets/levels/"+sourceFile;
}

Level::~Level()
{
    /*for(int i = 0; i < _cells.size(); ++i)
        for (int j = 0; j < _cells[i].size(); ++j)
            delete (_cells[i][j]);*/
}

int Level::getSizeX() const {
	return _sizeX;
}
int Level::getSizeY() const {
	return _sizeY;
}
int Level::getSizeZ() const {
	return _sizeZ;
}
Player Level::getPlayer() const {
	return _mainCharacter;
}
std::vector<Cell*> Level::getCells() const {
	return _cells;
}
std::vector<Coin*> Level::getCoins() const {
	return _coins;
}
std::vector<Block*> Level::getBlocks() const {
	return _blocks;
}
std::vector<Arch*> Level::getArches() const {
	return _arches;
}
std::vector<Arrival*> Level::getArrivals() const {
	return _arrivals;
}
std::vector<Hole*> Level::getHoles() const {
	return _holes;
}
std::string Level::getSourceFile() const {
	return _sourceFile;
}

void Level::setSizeX(const int n) {
	_sizeX = n;
}
void Level::setSizeY(const int n) {
	_sizeY = n;
}
void Level::setSizeZ(const int n) {
	_sizeZ = n;
}
void Level::setPlayer(Player &player) {
	_mainCharacter = player;
}
void Level::setCells(std::vector<Cell*> &cells) {
	_cells = cells;
}
void Level::setCoins(std::vector<Coin*> &coins) {
	_coins = coins;
}
void Level::setBlocks(std::vector<Block*> &blocks) {
	_blocks = blocks;
}
void Level::setArches(std::vector<Arch*> &arches) {
	_arches = arches;
}
void Level::setArrivals(std::vector<Arrival*> &arrivals) {
	_arrivals = arrivals;
}
void Level::setHoles(std::vector<Hole*> &holes) {
	_holes = holes;
}
void Level::setSourceFile(std::string &sourceFile) {
	_sourceFile = "../src/assets/levels/"+sourceFile;
}