#include <map>
#include <regex>
#include <sstream>

#include "AnalyseurCommandes.h"
#include "Element.h"

using namespace std;

int main() {
	string ligneTexteUsager;
	AnalyseurCommandes analyseur;
	map<string, Element> mapElements;
	// CTRL + D va arreter l'execution
	while (getline(cin, ligneTexteUsager))
	{
		string * reponse;
		reponse = analyseur.ajouter(ligneTexteUsager);
		string commande, entreeTexte;
		entreeTexte = *reponse;
		commande = *(reponse + 1);
		string identificateur, repActuelTexte, id0Id;
		regex expReg(".* rep "), expReg2(".rep*.*");
		map<string, Element>::iterator id0, id1;
		// Cette commande indique que l’identificateur id est une CE
		if (commande == "id." ) {
			identificateur = entreeTexte.substr(0, entreeTexte.size() - 1);
	    	// Construire element et ajouter dans le map
			Element element(identificateur);
			mapElements[identificateur] = element;
		}
		// Cette commande indique que les identificateurs id1 , ... , idn sont représentés par la CE de l’identificateur id0
		// Un seul identificateur
		else if (commande == "id0 rep id1, ... , idn.") {
			identificateur = entreeTexte.substr(0, entreeTexte.size() - 1);
			identificateur = regex_replace(identificateur, expReg, "");
			// Construire element
			identificateur = entreeTexte.substr(0, entreeTexte.size() - 1);
			Element element(identificateur);
			// Ajouter dans le map
			mapElements[identificateur] = element;
			// Trouver l’instance d’Element qui représente l’identificateur id1 et
			// faire pointer son champ representant vers l’Element représentant l’identificateur id0
			id0Id = regex_replace(repActuelTexte, expReg2, "");
			id0 = mapElements.find(id0Id);
			id1 = mapElements.find(identificateur);
		}
		// Deux identificateurs ou plus
		else if (commande == "id0 rep id1, ... , idn." && entreeTexte.find(",") != string::npos) {
			identificateur = entreeTexte.substr(0, entreeTexte.size() - 1);
			identificateur = regex_replace(identificateur, expReg, "");
		    stringstream stream(identificateur);
		    while( getline(stream, identificateur, ',') ) {
		    	// Construire element et ajouter dans le map
				Element element(identificateur);
				mapElements[identificateur] = element;
		    }
		}
		else if (commande == "id0 ce id1.") {
			//
		}
		else if (commande == "id0 ce id1?") {
			//
		}
		else if (commande == "rep id1?") {
			//
		}
		else if (commande == "rep id1, id2 ?") {
			//
		}
	}
	return EXIT_SUCCESS;
}
