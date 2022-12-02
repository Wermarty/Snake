#ifndef FRUIT_H
#define FRUIT_H

class Fruit {
private:
	int m_x;		//These are the fruit's coord
	int m_y;

public:
	Fruit();
	
	//Change fruit's coord randomly
	void newFruit();		
	int getRandomInt(int min, int max); //Used in newFruit()

	//Return the coord for :	 1) axis x			2) axis y
	int getCol() const;
	int getRow() const;
};





#endif