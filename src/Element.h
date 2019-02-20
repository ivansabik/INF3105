#ifndef ELEMENT_H_
#define ELEMENT_H_

#include <iostream>

class Element {
public:
	Element();
	Element(std::string idConstructeur);
	virtual ~Element();
protected:
	std::string identificateur;
	int rang;
	Element * suivant;
	Element * representant();
};

#endif
