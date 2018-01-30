#include "Produit.h"
#include <stdio.h>

Produit::Produit() : nom_("outil"), reference_(0), prix_(0.0) {
}

Produit::Produit(string nom, int reference, double prix) 
	: nom_(nom), reference_(reference), prix_(prix){
}

string Produit::obtenirNom() const {
	return nom_;
}

int Produit::obtenirReference() const {
	return reference_;
}

double Produit::obtenirPrix() const{
	return prix_;
}

void Produit::modifierNom(const string nouveauNom) {
	nom_ = nouveauNom;
}

void Produit::modifierReference(const int nouvelleReference) {
	reference_ = nouvelleReference;
}

void Produit::modifierPrix(const double nouveauPrix) {
	prix_ = nouveauPrix;
}

void Produit::afficher() const {

	cout << "Details pour: " << nom_ << endl << 
		"reference: " << reference_ << endl << 
		"prix:" << prix_ << "$" << endl;
}
