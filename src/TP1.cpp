#include <map>

#include "AnalyseurCommandes.h"
#include "Element.h"

using namespace std;

void testAnalyseurCommandes() {
	AnalyseurCommandes analyseur;
	cout << analyseur.ajouter("Scolopacidae.") << endl;
	cout << analyseur.ajouter("Scolopacidae rep Actitis.") << endl;
	cout << analyseur.ajouter("Actitis rep Hypoleucos,") << endl;
	cout << analyseur.ajouter("			Macularia.") << endl;
	cout << analyseur.ajouter("rep Macularia ?") << endl;
	cout << analyseur.ajouter("Calidris.") << endl;
	cout << analyseur.ajouter("Calidris rep Alba.") << endl;
	cout << analyseur.ajouter("Hypoleucos ce Macularia ?") << endl;
	cout << analyseur.ajouter("Hypoleucos ce Alba ?") << endl;
	cout << analyseur.ajouter("rep Hypoleucos, Macularia ?") << endl;
	cout << analyseur.ajouter("Scolopacidae rep Calidris,") << endl;
	cout << analyseur.ajouter("Arenaria.") << endl;
	cout << analyseur.ajouter("Hypoleucos ce Alba ?") << endl;
	cout << analyseur.ajouter("Alpina.") << endl;
	cout << analyseur.ajouter("Alba ce Alpina ?") << endl;
	cout << analyseur.ajouter("Alba ce Alpina.") << endl;
	cout << analyseur.ajouter("Alba ce Alpina ?") << endl;
}

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
		if (commande == "id." ) {
			// Construire element
			string identificateur = entreeTexte.substr(0, entreeTexte.size() - 1);
			Element element(identificateur);
			// Ajouter dans le map
			mapElements[identificateur] = element;
		}
		else if (commande == "rep id1, ... , idn." ){
			//
		}
		else if (commande == "id0 rep id1, ... , idn." ){
			//
		}
		else if (commande == "id0 ce id1." ){
			//
		}
		else if (commande == "id0 ce id1?" ){
			//
		}
		else if (commande == "rep id1?" ){
			//
		}
		else if (commande == "rep id1, id2 ?" ){
			//
		}
	    cout << commande << ", " << entreeTexte << endl;
	}
	return EXIT_SUCCESS;
}
