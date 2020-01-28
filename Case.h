#include <iostream>
using namespace std;

class Case {

public:

	Case(int var);

	bool Case::canAdd(const Case &box) const;

	int Case::getStatus() const;

	void Case::setStatus(int var);
	
	void Case::setSelected();
	
	String Case::toString() const;
	
	void Case::saisir();

private:
	int status;
	bool selected = true;
	//int trapped;
};
