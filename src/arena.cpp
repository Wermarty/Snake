#include "arena.h"
#include "case.h"
#include "snake.h"
#include <chrono>
#include "constants.h"

Arena::Arena() {

	for (int row{ 0 }; row < g_numRow; row++) {
		for (int col{ 0 }; col < g_numCol; col++) {
			if (col == 0) {
				m_arena[row][col] = Case::Type::wallLeft;
			}
			else if (col == g_numCol - 1) {
				m_arena[row][col] = Case::Type::wallRight;
			}
			else if ((row == 0) && (col != 0) && (col != g_numCol - 1)) {
				m_arena[row][col] = Case::Type::wallUp;
			}
			else if (row == g_numRow - 1 && (col != 0) && (col != g_numCol - 1)) {
				m_arena[row][col] = Case::Type::wallDown;
			}

			else {
				m_arena[row][col] = Case::Type::empty;
			}
		}
	}
	for (const auto& coord : m_snake.getBody()) {
		m_arena[coord.x][coord.y] = Case::Type::snake;
	}
	m_arena[m_fruit.getRow()][m_fruit.getCol()] = Case::Type::fruit;
}

void Arena::printArena() const{
	std::cout << '\n'; 
	for (int row{ 0 }; row < g_numRow; row++) {
		for (int col{ 0 }; col < g_numCol; col++) {
			m_arena[row][col].printCase();
		}
		std::cout << '\n';
	}
}

void Arena::eraseTail() {
	Snake::Coord tail{ m_snake.getTail() };
	m_arena[tail.x][tail.y] = Case::Type::empty;
}

bool Arena::isEating() {
	return ((m_snake.getHead().x == m_fruit.getRow()) && (m_snake.getHead().y == m_fruit.getCol()));
}

void Arena::printFruit() {
	m_arena[m_fruit.getRow()][m_fruit.getCol()] = Case::Type::fruit;
}

bool Arena::nextMovementAvailable() {
	Snake::Coord nextPosition{ m_snake.getHead() };
	Snake::Direction nextDirection{ m_snake.getNextDirection() };

	switch (nextDirection) {
	
	case Snake::Direction::up:
		
		nextPosition.x -= 1;
		if (m_arena[nextPosition.x][nextPosition.y].isWall()
			|| m_arena[nextPosition.x][nextPosition.y].isSnake()) {
			return false;
		}
		
		return true;
	
	case Snake::Direction::down:
		nextPosition.x += 1;
		if (m_arena[nextPosition.x][nextPosition.y].isWall()
			|| m_arena[nextPosition.x][nextPosition.y].isSnake()) {
			return false;
		}
		return true;
	
	case Snake::Direction::left:
		nextPosition.y -= 1;
		if (m_arena[nextPosition.x][nextPosition.y].isWall()
			|| m_arena[nextPosition.x][nextPosition.y].isSnake()) {
			return false;
		}
		return true;
	
	case Snake::Direction::right:
		nextPosition.y += 1;
		if (m_arena[nextPosition.x][nextPosition.y].isWall()
			|| m_arena[nextPosition.x][nextPosition.y].isSnake()) {
			return false;
		}
		return true;
	
	default:
		return true;
	}
}

void Arena::play() {
	do {
		update();
	} while (m_snake.isAlive());
}
void Arena::update() {

	movingSnake();

	managingFruit();

	printingArena();

	gettingNewDirection();

}
void Arena::movingSnake() {
	eraseTail();
	m_snake.go();
	Snake::Coord newHead{ m_snake.getHead() };
	for (const auto& coord : m_snake.getBody()) {
		m_arena[coord.x][coord.y] = Case::Type::snake;
	}
	m_snake.changeCoordTail(m_snake.getBody()[0]);
	m_snake.changeCoordHead(m_snake.getBody()[m_snake.getLengh() - 1]);
}

void Arena::managingFruit() {
	if (isEating()) {
		do {
			m_fruit.newFruit();
		} while (!m_arena[m_fruit.getRow()][m_fruit.getCol()].isEmpty());

		printFruit();
		m_snake.extend();
	}
}
void Arena::printingArena() {
	system("cls");
	printArena();
}
void Arena::gettingNewDirection() {
	
	m_snake.getNewDirection(m_snake.getUserInput());
	
	if (!nextMovementAvailable()) {
		m_snake.die();
	}
	m_snake.changeCurrentDirection(m_snake.getNextDirection());
}



