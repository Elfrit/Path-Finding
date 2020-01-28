#include "Labyrinthe.h"
#include <iostream>

class Labyrinthe {
	
	Labyrinthe::Labyrinthe() : x(6), y(6), labyrinthe(6, 6);
	Labyrinthe::Labyrinthe(int x, int y) : x(x), y(y), labyrinthe(x, y);

	Labyrinthe::toString() const {
		for (int i(0); i < this->x; ++i) {
			String affiche = "";
			for (int j(0); i < this->y; ++j) {
				affiche+=""
			}
		}
	}
};