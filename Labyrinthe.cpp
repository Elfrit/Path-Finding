#include "Labyrinthe.h"
#include <iostream>

class Labyrinthe {
	
	Labyrinthe::Labyrinthe() : x(6), y(6), labyrinthe(6, 6);
	Labyrinthe::Labyrinthe(int x, int y) : x(x), y(y), labyrinthe(x, y);

	moveOk(int x, int y) const{
		if (x > 0 and y > 0 and x < this->x and y < this->y) {
			return true;
		}
		return false;
	}

	void Labyrinthe::noeud(int debutX, int debutY){ //Ici, c'est peut être une Case pas un Labyrinthe
		if (moveOk(debutX, debutY)) {
			if (moveOk(debutX + 1, debutY) && this->labyrinthe[debutX + 1][debutY].canAdd()) {
				this->labyrinthe[debutX + 1][debutY].setStatus(labyrinthe[debutX][debutY].getStatus() + 1);
			}
			if (moveOk(debutX, debutY + 1) && this->labyrinthe[debutX][debutY + 1].canAdd()) {
				this->labyrinthe[debutX][debutY + 1].setStatus(labyrinthe[debutX][debutY].getStatus() + 1);
			}
			if (moveOk(debutX -1, debutY) && this->labyrinthe[debutX - 1][debutY].canAdd()) {
				this->labyrinthe[debutX - 1][debutY].setStatus(labyrinthe[debutX][debutY].getStatus() + 1);
			}
			if (moveOk(debutX, debutY - 1) && this->labyrinthe[debutX][debutY - 1].canAdd()) {
				this->labyrinthe[debutX][debutY - 1].setStatus(labyrinthe[debutX][debutY].getStatus() + 1);
			}
		}
		else {
			printf("Erreur, votre X et Y est trop grand/petit");
		}
	}

	bool Labyrinthe::parcourir(int debutX, int debutY) {
		if moveOk(debutX, debutY) {
			int statCase = this->labyrinthe[debutX][debutY].getStatus();
		}
		else {
			return false;
		}
		for (int i(0); i < this->x; ++i) {
			for (int j(0); i < this->y; ++j) {
				if (this->labyrinthe[i][j].getStatus() == statCase) {
					this->labyrinthe[i][j].noeud(debutX, debutY) //A voir, cette fonction est très suspecte
				}
			}
		}
		return true;
	}

	String Labyrinthe::toString() const {
		String affiche = "";
		for (int i(0); i < this->x; ++i) {
			for (int j(0); i < this->y; ++j) {
				affiche += this->labyrinthe[i][j].getStatus(); +' | ';
			}
			affiche+='\n'
		}
		return affiche;
	}
};