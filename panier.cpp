/**************************************************
* Titre: Travail pratique #1 - panier.cpp
* Date: 20 janvier 2018
* Auteur: Loic LeBlanc et Daniel Nahum
**************************************************/

#include "panier.h"

/**
* Constructeur de Panier, prend sa capacite en parametre.
*/
Panier::Panier(int capacite) 
	: capaciteContenu_(capacite), nombreContenu_(0), totalAPayer_(0.0), contenuPanier_(new Produit*[capacite]){

}

/**
* Destructeur de Panier. Desalloue le tableau de pointeurs.
*/
Panier::~Panier() {
	delete[] contenuPanier_;
}

/**
* Destructeur de Panier. Desalloue le tableau de pointeurs.
*/
Produit** Panier::obtenirContenuPanier() const {
	return contenuPanier_;
}

/**
* Accesseur de nombreContenu_
*/
int Panier::obtenirNombreContenu() const {
	return nombreContenu_;
}

/**
* Accesseur de totalAPayer_
*/
double Panier::obtenirTotalApayer() const {
	return totalAPayer_;
}

/**
* Cette methode ajoute un pointeur a un produit a la liste contenuPanier_. Elle fait aussi la gestion de memoire de contenuPanier_. 
*/
void Panier::ajouter(Produit* nouveauProduit) {

	if (nombreContenu_ < capaciteContenu_) {
		contenuPanier_[nombreContenu_++] = nouveauProduit;
	}
	else {
		//Allocation d'une nouvelle liste de produit ayant le double de la capacite anterieure
		Produit** nouvelleListe = new Produit*[capaciteContenu_ * 2];

		//Inscription de tous les anciens produits de l'ancienne liste a la nouvelle liste
		for (int i = 0; i < capaciteContenu_; i++) {
			nouvelleListe[i] = contenuPanier_[i];
		}

		//Deallocation de l'ancienne liste
		delete[] contenuPanier_;

		//La nouvelle liste deviens la liste
		contenuPanier_ = nouvelleListe;

		//Mise a jour de la propriete capacite_
		capaciteContenu_ *= 2;

		//Ajout du produit a la nouvelle liste
		contenuPanier_[nombreContenu_++] = nouveauProduit;

	}
	
	totalAPayer_ += nouveauProduit->obtenirPrix();

}

/**
* Cette methode affiche le contenu du panier de facon ergonomique et jolie.
*/
void Panier::afficher() const {
	cout << "Votre panier contient " << nombreContenu_ << " produits: " << endl << endl;

	for (int i = 0; i < nombreContenu_; i++) {
		contenuPanier_[i]->afficher();
		cout << endl;
	}
}

/**
* Cette methode simule la livraison du panier en desallouant le contenuPanier_ et en ramenant le totalAPayer_ et le nombreContenu_ a 0.
*/
void Panier::livrer() {

	delete[] contenuPanier_;
	contenuPanier_ = new Produit*[capaciteContenu_];

	nombreContenu_ = 0;
	totalAPayer_ = 0.0;

}