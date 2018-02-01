/**************************************************
* Titre: Travail pratique #1 - panier.cpp
* Date: 20 janvier 2018
* Auteur: Loic LeBlanc et Daniel Nahum
**************************************************/

#include "Produit.h"
#include <stdio.h>

/**
* Constructeur par defaut de Produit
*/
Produit::Produit() : nom_("outil"), reference_(0), prix_(0.0) {
}

/**
* Constructeur par parametres de Produit
*/
Produit::Produit(string nom, int reference, double prix) 
	: nom_(nom), reference_(reference), prix_(prix){
}

/**
* Accesseur de nom_
*/
string Produit::obtenirNom() const {
	return nom_;
}
/**
* Accesseur de reference_
*/
int Produit::obtenirReference() const {
	return reference_;
}
/**
* Accesseur de prix_
*/
double Produit::obtenirPrix() const{
	return prix_;
}
/**
* Modifie la valeur de nom_ par la valeur passee en parametre
*/
void Produit::modifierNom(const string nouveauNom) {
	nom_ = nouveauNom;
}
/**
* Modifie la valeur de reference_ par la valeur passee en parametre
*/
void Produit::modifierReference(const int nouvelleReference) {
	reference_ = nouvelleReference;
}
/**
* Modifie la valeur de prix_ par la valeur passee en parametre
*/
void Produit::modifierPrix(const double nouveauPrix) {
	prix_ = nouveauPrix;
}
/**
* Cette methode affiche le les caracteristiques du produit de facon ergonomique et jolie.
*/
void Produit::afficher() const {

	cout << "Details pour: " << nom_ << endl << 
		"reference: " << reference_ << endl << 
		"prix:" << prix_ << "$" << endl;
}
