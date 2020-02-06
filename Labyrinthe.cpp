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

	void Labyrinthe::noeud(int debutX, int debutY){ //Ici, c'est peut �tre une Case pas un Labyrinthe
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

	//bool Labyrinthe::parcourir(int debutX, int debutY) { //Trouve les cases concern�es et les parcourent
	//	if moveOk(debutX, debutY) {
	//		int statCase = this->labyrinthe[debutX][debutY].getStatus();
	//	}
	//	else {
	//		return false;
	//	}
	//	for (int i(0); i < this->x; ++i) {
	//		for (int j(0); i < this->y; ++j) {
	//			if (this->labyrinthe[i][j].getStatus() == statCase and this->labyrinthe[i][j].getSelected() == true;) {
	//				this->labyrinthe[i][j].noeud(debutX, debutY) //A voir, cette fonction est tr�s suspecte
	//				this->labyrinthe[i][j].setSelected(); //Le met directement sur false;
	//			}
	//		}
	//	}
	//	return true;
	//}

	int Labyrinthe::parcourir(int numCase) { //Trouve les cases concern�es et les parcourent, si il ne peut pas parcourir return -1, si il est � la fin, retourne 0, sinon retourne 1
		bool canChange = false; //Permet de savoir si on peut parcourir ou si nous n'avons plus aucune option
		bool end = false;
		for (int i(0); i < this->x; ++i) {
			for (int j(0); i < this->y; ++j) {
				if (labyrinthe[i][j].getStatus() == -2) {
					end = true;
				}
				else if (this->labyrinthe[i][j].getStatus() == numCase and this->labyrinthe[i][j].getSelected() == true;) {
					this->labyrinthe[i][j].noeud(i,j) //A voir, cette fonction est tr�s suspecte
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

	void Labyrinthe::search() { //Methode o� Dijkstra est utilis� 1 fois
		int i = 0;
		bool passeSuivant = true; //Il y a un chemin possible entre le debut et la fin
		while (passeSuivant) {
			switch (this->parcourir(i)) {
				case -1:
					printf("Il n'existe aucun chemin pour arriver � la fin.");
					passeSuivant = false;
					break;
				case 0:
					printf('Le labyrinthe est complet !');
					passeSuivant = false;
					break;
				default :
					printf('Actuellement nous en somme � la %d itt�ration', i);
					break;
			}
			i++;
		}	
	}

	int Labyrinthe::*findPath(int iDepart, int jDepart) { //Dijkstra once
		int tabTemp = [this->x][this->y]; //Va contenir les diff�rentes colonnes 
		for (int i(0); i < this->x; ++i) {
			for (int j(0); j < this->y; ++j) {
				tabTemp[i][j] = -1;
			}
		}
		vector<int>path; //Va contenir le noeud associ� � la ligne/colonne

		path.push_back(this->labyrinthe[iDepart][jDepart]);
		for (int i(1); i < this->x; ++i) {
			for (int j(0); this->y; ++j) { //Boucle pour inscrire � la ligne voulue
				if (this->graphe[i][j] != 0) {
					tabTemp[i][j] = graphe[path[i]][j]; //La ligne du graphe o� le noeud a �t� le plus petit est ajout� 
				}
			}
			path.push_back(tabMin[tabTemp[i]]); //Ajoute le plus petit noeud � path
			if (path[path.size()] == -2) { //Si l'algorithme atteint la fin, la boucle est quitt�
				i = this->x;
			}

			for (int j(0); j < this->y; ++j) { //Verifie si l'ancienne ligne contient des valeurs inf�rieurs (!= -1) au nouveau
				if (tabTemp[i][j] > tab[i - 1][j]{
					tabTemp[i][j] = tab[i - 1][j];
				}
			}
		}

		vector<int> fastPath;
		fastPath.pushBack(-2);

		//� partir d'ici l'objectif est de remplir fastPath avec le chemin le plus rapide. Pour cela il faut parcourir path et tabTemp

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