#include <iostream>
#include "Case.h"
using namespace std;

class Case {
	Case::Case(int var) : status(var){}
	
	bool Case::canAdd(const Case &box) const{
		if (box.getStatus() == -1) {
			return false;
		}
		else if (box.getStatus() == this->getStatus()) {
			return false;
		}

		else {
			return true;
		}
	}
	
	int Case::getStatus() const {
		return this->status;
	}
	
	void Case::setStatus(int var){
		this->status = var;
	}
	
	String toString() const{
		return this->status;
	}
	
	void Case::saisir(){
		cout<<"Mur(-1)/Obstacle(-2)/Ne rien mettre sur libre"; cin >>this->status;
	}
	
	

}
