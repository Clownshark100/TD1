#include "client.h"

Client::Client(string nom, string prenom, int identifiant, string codePostal, long date) 
	: nom_(nom), prenom_(prenom), identifiant_(identifiant), codePostal_(codePostal), dateNaissance_(date), monPanier_(nullptr)
{
}

string Client::obtenirNom() const {
	return nom_;
}

string Client::obtenirPrenom() const {
	return prenom_;
}

int Client::obtenirIdentifiant() const {
	return identifiant_;
}

string Client::obtenirCodePostal() const{
	return codePostal_;
}

long Client::obtenirDateNaissance() const {
	return dateNaissance_;
}

void Client::modifierNom(const string nom) {
	nom_ = nom;
}

void Client::modifierPrenom(const string prenom) {
	prenom_ = prenom;
}

void Client::modifierIdentifiant(const int identifiant) {
	identifiant_ = identifiant;
}

void Client::modifierCodePostal(const string codePostal) {
	codePostal_ = codePostal;
}

void Client::modifierDateNaissance(const long date) {
	dateNaissance_ = date;
}

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

void Client::afficherPanier() const {
	
	monPanier_->afficher();
}

void Client::livrerPanier() {
	monPanier_->livrer();
}
