#include "fruit.h"
#include "constants.h"
#include <cstdlib>

Fruit::Fruit() 
	: m_x{ getRandomInt(static_cast<int>(g_numRow / 2), g_numRow-1)}
	, m_y{ getRandomInt(static_cast<int>(g_numCol / 2), g_numCol-1) }{
}

void Fruit::newFruit() {
	m_x = getRandomInt(2, g_numRow - 2);
	m_y = getRandomInt(2, g_numCol - 2);
}
int Fruit::getRandomInt(int min, int max) {
	constexpr double fraction{ 1.0 / (RAND_MAX + 1.0) };
	return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
}

int Fruit::getRow() const {
	return m_x;
}
int Fruit::getCol() const {
	return m_y;
}