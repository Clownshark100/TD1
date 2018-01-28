#include "panier.h"

Panier::Panier(int capacite) 
	: capaciteContenu_(capacite), nombreContenu_(0), totalAPayer_(0.0), contenuPanier_(new Produit*[capacite]){

}

Panier::~Panier() {
	delete[] contenuPanier_; //Desalloue le tableau de pointeurs
}

Produit** Panier::obtenirContenuPanier() {
	return contenuPanier_;
}

int Panier::obtenirNombreContenu() {
	return nombreContenu_;
}

double Panier::obtenirTotalApayer() {
	return totalAPayer_;
}

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

void Panier::afficher() {
	cout << "Votre panier contient " << nombreContenu_ << " produits: " << endl << endl;

	for (int i = 0; i < nombreContenu_; i++) {
		contenuPanier_[i]->afficher();
		cout << endl;
	}
}


void Panier::livrer() {

	delete[] contenuPanier_;
	contenuPanier_ = new Produit*[capaciteContenu_];

	nombreContenu_ = 0;
	totalAPayer_ = 0.0;

}