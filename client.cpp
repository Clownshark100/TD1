#include "client.h"

Client::Client(string nom, string prenom, int identifiant, string codePostal, long date) 
	: nom_(nom), prenom_(prenom), identifiant_(identifiant), codePostal_(codePostal), dateNaissance_(date), monPanier_(nullptr)
{
}

string Client::obtenirNom() {
	return nom_;
}

string Client::obtenirPrenom() {
	return prenom_;
}

int Client::obtenirIdentifiant() {
	return identifiant_;
}

string Client::obtenirCodePostal() {
	return codePostal_;
}

long Client::obtenirDateNaissance() {
	return dateNaissance_;
}

void Client::modifierNom(string nom) {
	nom_ = nom;
}

void Client::modifierPrenom(string prenom) {
	prenom_ = prenom;
}

void Client::modifierIdentifiant(int identifiant) {
	identifiant_ = identifiant;
}

void Client::modifierCodePostal(string codePostal) {
	codePostal_ = codePostal;
}

void Client::modifierDateNaissance(long date) {
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

void Client::afficherPanier() {
	
	cout << "Votre panier contient "<< monPanier_->obtenirNombreContenu() << " produits: " << endl << endl;

	for (int i = 0; i < monPanier_->obtenirNombreContenu(); i++) {
		monPanier_->obtenirContenuPanier()[i]->afficher();
		cout << endl;
	}
}

void Client::livrerPanier() {
	
	delete monPanier_;
	monPanier_ = nullptr;
}