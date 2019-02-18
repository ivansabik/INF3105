#include "AnalyseurCommandes.h"

using namespace std;

void testAnalyseurCommandes() {
	AnalyseurCommandes analyseur;
	cout << analyseur.ajouter("Scolopacidae.") << endl;
	cout << analyseur.ajouter("Scolopacidae rep Actitis.") << endl;
	cout << analyseur.ajouter("Actitis rep Hypoleucos,") << endl;
	cout << analyseur.ajouter("			Macularia.") << endl;
	cout << analyseur.ajouter("ce Macularia ?") << endl;
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
	testAnalyseurCommandes();
	return EXIT_SUCCESS;
}
