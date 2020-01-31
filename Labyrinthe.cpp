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

	//bool Labyrinthe::parcourir(int debutX, int debutY) { //Trouve les cases concernées et les parcourent
	//	if moveOk(debutX, debutY) {
	//		int statCase = this->labyrinthe[debutX][debutY].getStatus();
	//	}
	//	else {
	//		return false;
	//	}
	//	for (int i(0); i < this->x; ++i) {
	//		for (int j(0); i < this->y; ++j) {
	//			if (this->labyrinthe[i][j].getStatus() == statCase and this->labyrinthe[i][j].getSelected() == true;) {
	//				this->labyrinthe[i][j].noeud(debutX, debutY) //A voir, cette fonction est très suspecte
	//				this->labyrinthe[i][j].setSelected(); //Le met directement sur false;
	//			}
	//		}
	//	}
	//	return true;
	//}

	int Labyrinthe::parcourir(int numCase) { //Trouve les cases concernées et les parcourent, si il ne peut pas parcourir return -1, si il est à la fin, retourne 0, sinon retourne 1
		bool canChange = false; //Permet de savoir si on peut parcourir ou si nous n'avons plus aucune option
		bool end = false;
		for (int i(0); i < this->x; ++i) {
			for (int j(0); i < this->y; ++j) {
				if (labyrinthe[i][j].getStatus() == -2) {
					end = true;
				}
				else if (this->labyrinthe[i][j].getStatus() == numCase and this->labyrinthe[i][j].getSelected() == true;) {
					this->labyrinthe[i][j].noeud(i,j) //A voir, cette fonction est très suspecte
					this->labyrinthe[i][j].setSelected(); //Le met directement sur false;
					canChange = true;
				}
			}
		}
		if (end)
			return 0;
		else if (canChange)
			return 1;
		return -1;
	}

	void Labyrinthe::search() { //Methode où Dijkstra est utilisé 1 fois
		int i = 0;
		bool passeSuivant = true; //Il y a un chemin possible entre le debut et la fin
		while (passeSuivant) {
			switch (this->parcourir(i)) {
				case -1:
					printf("Il n'existe aucun chemin pour arriver à la fin.");
					passeSuivant = false;
					break;
				case 0:
					printf('Le labyrinthe est complet !');
					passeSuivant = false;
					break;
				default :
					printf('Actuellement nous en somme à la %d ittération', i);
					break;
			}
			i++;
		}	
	}

	int Labyrinthe::*findPath() { //Dijkstra
		vector<int> path;






		return path;
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