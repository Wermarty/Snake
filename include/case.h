#ifndef CASE_H
#define CASE_H

#include <iostream>


class Case {
public:
	enum struct Type {		//Different type of element possible for one case
		wallUp,				
		wallRight,
		wallLeft,
		wallDown,
		snake,
		fruit,
		empty,

		max_types,
	};

private:
	Type m_type{};

public:
	Case() = default;
	Case(Type type);

	//Print the case depending on which type it is
	void printCase() const;

	//Return a bool if the case is "nameOfFunction"
	bool isEmpty() const;
	bool isFruit() const;
	bool isSnake() const;
	bool isWall() const;
};

#endif