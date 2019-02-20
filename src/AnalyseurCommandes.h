#ifndef ANALYSEUR_COMMANDES_H
#define ANALYSEUR_COMMANDES_H

#include <iostream>
#include <stdexcept>
#include <string>

class AnalyseurCommandes {
public:
	AnalyseurCommandes();
	std::string * ajouter(std::string entreeUtilisateur);
private:
	bool actuelEstRep;
	std::string repActuel;
	bool finitPar(std::string const &fullString, std::string const &ending);
	std::string * validerEntree(std::string entree);
};

#endif
