#ifndef ARENA_H
#define ARENA_H

#include "case.h"
#include "snake.h"
#include "fruit.h"
#include "constants.h"
#include <array>




class Arena {

public:
	//type for the arena made from a matrice of case
	using map_type = std::array<std::array<Case, g_numCol>, g_numRow>;

private:
	map_type m_arena{};		//Arena
	Snake m_snake{};		//Snake
	Fruit m_fruit{};		//Fruit



public:
	Arena();

	//Print the arena on screen
	void printArena() const;

	//Erase the snake's tail from his movement
	void eraseTail();

	//Return true if the snake's head is on a fruit case
	bool isEating();

	//Print the fruit on the arena
	void printFruit();

	//Check if the next movement will kill the snake
	bool nextMovementAvailable();	
	


	//Play the game
	void play();

	//Use each frame in play()
	void update();

	//Use every time update() is called
	void movingSnake();				//Move the snake
	void managingFruit();			//Check if a fruit has been eaten and needs to be re-create
	void printingArena();			//Print the new arena
	void gettingNewDirection();		//Get the new direction and do all the checking

	
	
};


#endif