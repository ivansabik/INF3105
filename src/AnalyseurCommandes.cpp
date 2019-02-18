#include "AnalyseurCommandes.h"

using namespace std;

AnalyseurCommandes::AnalyseurCommandes() {
	actuelEstRep = false;
}

bool AnalyseurCommandes::finitPar (string const &fullString, string const &ending) {
    if (fullString.length() >= ending.length()) {
        return (0 == fullString.compare (fullString.length() - ending.length(), ending.length(), ending));
    } else {
        return false;
    }
}

string AnalyseurCommandes::validerEntree(string entreeTexte) {
	// id.
	cout << "Texte d'entree: " << entreeTexte << endl;
	if (finitPar(entreeTexte, ".") && entreeTexte.find("rep") == string::npos && entreeTexte.find("ce") == string::npos && AnalyseurCommandes::actuelEstRep == false && entreeTexte.rfind("rep", 0) != 0) {
		AnalyseurCommandes::actuelEstRep = false;
		return "id.";
    }
	// id0 rep id1, ... , idn.
	else if ((finitPar(entreeTexte, ".") || finitPar(entreeTexte, ",")) && entreeTexte.find("rep") != string::npos) {
		AnalyseurCommandes::actuelEstRep = true;
		return "rep id1, ... , idn.";
	}
	else if ((finitPar(entreeTexte, ".") || finitPar(entreeTexte, ",")) && AnalyseurCommandes::actuelEstRep == true) {
		AnalyseurCommandes::actuelEstRep = true;
		return "id0 rep id1, ... , idn.";
	}
	// id0 ce id1.
	else if (finitPar(entreeTexte, ".") && entreeTexte.find("ce") != string::npos) {
		AnalyseurCommandes::actuelEstRep = false;
		return "id0 ce id1.";
	}
	// id0 ce id1?
	else if (finitPar(entreeTexte, "?") && entreeTexte.find("ce") != string::npos && entreeTexte.rfind("ce", 0) != 0) {
		AnalyseurCommandes::actuelEstRep = false;
		return "id0 ce id1?";
	}
	// rep id1?
	else if (entreeTexte.rfind("rep", 0) == 0 && finitPar(entreeTexte, "?")) {
		AnalyseurCommandes::actuelEstRep = false;
		return "rep id1?";
	}
	// rep id1, id2 ?
	else if (finitPar(entreeTexte, "?") && entreeTexte.find("rep") != string::npos && entreeTexte.find(",") != string::npos) {
		AnalyseurCommandes::actuelEstRep = false;
		return "rep id1, id2 ?";
	}
	else if (entreeTexte.rfind("ce", 0) == 0){
		throw invalid_argument("Commande invalide!");
	}
	else {
		throw invalid_argument("Commande invalide!");
	}
}

string AnalyseurCommandes::ajouter(string entreeTexte) {
	return validerEntree(entreeTexte);
}
