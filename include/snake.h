#ifndef SNAKE_H
#define SNAKE_H

#include <iostream>
#include <string>
#include <array>
#include <vector>
#include "constants.h"



class Snake {
public:
	struct Coord {			//A struct to create the type Coord which is the coord
		int x{};			//for one point
		int y{};
	}; 
	using body_type = std::vector< Coord >;		//Vector wich contains coord for 
												//every part of snake's body
	
	enum class Direction {		//Represent every direction possible
		up,							
		down,
		left,
		right,
		nowhere,

		max_direction,
	};

private:
	int m_lengh{};			//Size of the snake
	bool m_alive{};			//Booleen for snake's life
	body_type m_body{};		//Contains every coord from each part of the body
	Direction m_currentDirection{};	//Direction followed by the snake
	Direction m_nextDirection{};	//Next direction that the snake will follow
	Coord m_tail{};			//Coord from the snake's tail
	Coord m_head{};			//Coord from the snake's head
	
public:
	Snake();

	//Function which return what they mean ;)
	int getLengh() const;
	body_type getBody() const;
	Coord getTail() const; 
	Coord getHead() const;
	Direction getCurrentDirection() const;
	Direction getNextDirection() const;
	bool isAlive() const;

	//Function which change what they mean with the parameter
	void changeCoordTail(Coord newCoord);
	void changeCoordHead(Coord newCoord);
	void changeCurrentDirection(Direction nextDirection);
	void changeNextDirection(Direction nextDirection);
	
	//Change the life status to false
	void die();
	
	//Change the coords of m_body
	void go();
	void partialGo(); //Used in go()

	//Change the nextDirection variable thanks of the parameter
	void getNewDirection(char c);
	char getUserInput() const; //Used in getNewDirection()

	//Increase the lengh by one and add a new coord inside the body
	void extend();
};



#endif