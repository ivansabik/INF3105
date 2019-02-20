#include "Element.h"


Element::Element() {
}

Element::Element(std::string identificateur) {
	Element::identificateur = identificateur;
	Element::rang = 0;
	Element::suivant = nullptr;
}

Element::~Element() {
}

