#include <iostream>
using namespace std;

class Graphe {

public:

	(int var);

	bool Case::canAdd(const Case &box) const;

	int Case::getStatus() const;

	void Case::setStatus(int var);
	
	void Case::setSelected();
	
	String Case::toString() const;
	
	void Case::saisir();

private:
	int status = 0;
	bool selected = true;
	//int trapped;
};
