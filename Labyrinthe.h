#include "Case.h"
#include <iostream>

class Labyrinthe : public Case {
public:
	Labyrinthe::Labyrinthe();
	Labyrinthe::Labyrinthe(int x, int y);
	/**
	Check if the move can fit the array.

	@param 2 int to check.
	@return a bool var.
	*/
	moveOk(int x, int y) const;
	
	/**
	If it can, modify the "Case" around the one we choose.

	@param 2 int (One Case).
	@return void.
	*/
	bool Labyrinthe::noeud(int debutX, int debutY);
	
	/**
	Search in the array if it can create new "noeud".

	@param 2 int (one Case) to search.
	@return a bool var.
	*/
	bool Labyrinthe::parcourir(int debutX, int debutY);
	
	/**
	Print the entire array.

	@param no param.
	@return String.
	*/
	String Labyrinthe::toString() const;

private:
	int x, y;
	vector<Case> labyrinthe;
};
