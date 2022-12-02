#include "snake.h"
#include <conio.h>
#include <chrono>
#include "constants.h"

Snake::Snake() :
	m_lengh{ g_initialLengh },
	m_alive{ true },
	m_body{ {2, 3}, {3, 3}, {4, 3} },
	m_currentDirection{ Direction::down },
	m_nextDirection{ m_currentDirection },
	m_head{ m_body[m_lengh-1]},
	m_tail{ m_body[0]}
	{
	}

int Snake::getLengh() const{
	return m_lengh;
}
Snake::body_type Snake::getBody() const{
	return m_body;
}
Snake::Coord Snake::getTail() const{
	return m_tail;
}
Snake::Coord Snake::getHead() const{
	return m_head;
}
Snake::Direction Snake::getCurrentDirection() const {
	return m_currentDirection;
}
Snake::Direction Snake::getNextDirection() const {
	return m_nextDirection;
}
bool Snake::isAlive() const{
	return m_alive;
}

void Snake::changeCoordTail(Snake::Coord newCoord) {
	m_tail.x = newCoord.x;
	m_tail.y = newCoord.y;
}
void Snake::changeCoordHead(Snake::Coord newCoord) {
	m_head.x = newCoord.x;
	m_head.y = newCoord.y;
}
void Snake::changeCurrentDirection(Snake::Direction nextDirection) {
	m_currentDirection = nextDirection;
}
void Snake::changeNextDirection(Snake::Direction nextDirection) {
	m_nextDirection = nextDirection;
}

void Snake::die() {
	m_alive = false;
}

void Snake::go() {
	switch (m_nextDirection) {
	case Direction::up:
		partialGo();
		m_body[m_lengh - 1].x -= 1;				
		break;									
	case Direction::down:
		partialGo();
		m_body[m_lengh - 1].x += 1;
		break;
	case Direction::left:
		partialGo();
		m_body[m_lengh - 1].y -= 1;
		break;
	case Direction::right:
		partialGo();
		m_body[m_lengh - 1].y += 1;
		m_head = m_body[m_lengh - 1];
		
		break;
	default:
		break;
	}
}
void Snake::partialGo() {							
	for (int i{ 0 }; i < m_lengh - 1; i++) {		
		m_body[i].x = m_body[i + 1].x;				
		m_body[i].y = m_body[i + 1].y;				
	}
}

void Snake::getNewDirection(char c) {
	switch (c) {
	case('z'): m_nextDirection = Snake::Direction::up; break;
	case('q'): m_nextDirection = Snake::Direction::left; break;
	case('s'): m_nextDirection = Snake::Direction::down; break;
	case('d'): m_nextDirection = Snake::Direction::right; break;
	default:
		m_nextDirection = m_currentDirection;
		break;
	}
}
char Snake::getUserInput() const {
	return static_cast<char>(_getch());
}

void Snake::extend() {
	Snake::Coord extended{ m_tail };
	m_body.insert(m_body.begin(), extended);
	m_lengh++;
}
