#include "Case.h"
#include <iostream>

class Labyrinthe : public Case {
public:
	Labyrinthe();
	Labyrinthe(int x, int y);

	Labyrinthe::toString() const;

private:
	int x, y;
	vector<Case> labyrinthe;
};
