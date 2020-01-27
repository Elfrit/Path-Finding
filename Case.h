#include <iostream>
using namespace std;

class Case {

public:

	Case(int var);

	bool Case::canAdd(const Case &box) const;

	int getStatus() const;

	void setStatus(int var);
	
	String toString() const;
	
	void Case::saisir();

private:
	int status;
};
