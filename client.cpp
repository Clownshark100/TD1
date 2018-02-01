/**************************************************
* Titre: Travail pratique #1 - panier.cpp
* Date: 20 janvier 2018
* Auteur: Loic LeBlanc et Daniel Nahum
**************************************************/


#include "client.h"

/**
* Constructeur par parametres de Client
*/
Client::Client(string nom, string prenom, int identifiant, string codePostal, long date) 
	: nom_(nom), prenom_(prenom), identifiant_(identifiant), codePostal_(codePostal), dateNaissance_(date), monPanier_(nullptr)
{}

/**
* Destructeur de Client, desalloue le panier.
*/
Client::~Client(){
	delete monPanier_;
}

/**
* Accesseur de nom_
*/
string Client::obtenirNom() const {
	return nom_;
}

/**
* Accesseur de prenom_
*/
string Client::obtenirPrenom() const {
	return prenom_;
}

/**
* Accesseur de identifiant_
*/
int Client::obtenirIdentifiant() const {
	return identifiant_;
}

/**
* Accesseur de codePostal_
*/
string Client::obtenirCodePostal() const{
	return codePostal_;
}

/**
* Accesseur de dateNaissance_
*/
long Client::obtenirDateNaissance() const {
	return dateNaissance_;
}
/**
* Modifie la valeur de nom_ par la valeur passee en parametre
*/
void Client::modifierNom(const string nom) {
	nom_ = nom;
}
/**
* Modifie la valeur de prenom_ par la valeur passee en parametre
*/
void Client::modifierPrenom(const string prenom) {
	prenom_ = prenom;
}
/**
* Modifie la valeur de identifiant_ par la valeur passee en parametre
*/
void Client::modifierIdentifiant(const int identifiant) {
	identifiant_ = identifiant;
}
/**
* Modifie la valeur de codePostal_ par la valeur passee en parametre
*/
void Client::modifierCodePostal(const string codePostal) {
	codePostal_ = codePostal;
}

/**
* Modifie la valeur de dateNaissance_ par la valeur passee en parametre
*/
void Client::modifierDateNaissance(const long date) {
	dateNaissance_ = date;
}
/**
* Cette methode ajoute un produit au Panier de ce client. Il alloue un Panier s'il y a lieu.
*/
void Client::acheter(Produit* produit) {
	//Si le panier existe
	if (monPanier_) {
		monPanier_->ajouter(produit);
	}
	else {
		monPanier_ = new Panier(4);
		monPanier_->ajouter(produit);
	}
}
/**
* Cette methode affiche les produits dans le panier du client de facon ergonomique et jolie.
*/
void Client::afficherPanier() const {
	
	monPanier_->afficher();
}

/**
* Cette methode simule la livraison du panier du client en le vidant.
*/
void Client::livrerPanier() {
	monPanier_->livrer();
}
