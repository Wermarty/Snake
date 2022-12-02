#include "case.h"

Case::Case(Type type) : m_type{ type } {
}

void Case::printCase() const{
	switch (m_type) {
	case Type::wallUp:		std::cout << '.'; break;
	case Type::wallRight:	std::cout << '|'; break;
	case Type::wallLeft:	std::cout << '|'; break;
	case Type::wallDown:	std::cout << '`'; break;
	case Type::snake:		std::cout << 'o'; break;
	case Type::fruit:		std::cout << '%'; break;
	case Type::empty:		std::cout << ' '; break;
	default:
		std::cout << '?';
	}
}

bool Case::isEmpty() const {
	return (m_type == Type::empty);
}
bool Case::isFruit() const {
	return (m_type == Type::fruit);
}
bool Case::isSnake() const {
	return (m_type == Type::snake);
}
bool Case::isWall() const {
	switch (m_type) {
	case Type::wallUp:		return true;
	case Type::wallRight:	return true;
	case Type::wallLeft:	return true;
	case Type::wallDown:	return true;
	default: 
		return false;
	}
}