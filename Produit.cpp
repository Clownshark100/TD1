#include "Produit.h"
#include <stdio.h>

Produit::Produit() : nom_("outil"), reference_(0), prix_(0.0) {
}

Produit::Produit(string nom, int reference, double prix) 
	: nom_(nom), reference_(reference), prix_(prix){
}

string Produit::obtenirNom() {
	return nom_;
}

int Produit::obtenirReference() {
	return reference_;
}

double Produit::obtenirPrix() {
	return prix_;
}

void Produit::modifierNom(string nouveauNom) {
	nom_ = nouveauNom;
}

void Produit::modifierReference(int nouvelleReference) {
	reference_ = nouvelleReference;
}

void Produit::modifierPrix(double nouveauPrix) {
	prix_ = nouveauPrix;
}

void Produit::afficher() {

	cout << "Details pour:" << nom_ << ":" << endl << 
		"reference: " << reference_ << endl << 
		"prix:" << prix_ << endl;
}