#include "panier.h"

Panier::Panier(int capacite) 
	: capaciteContenu_(capacite), nombreContenu_(0), totalAPayer_(0.0), contenuPanier_(new Produit*[capacite]){

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
		delete contenuPanier_;

		//La nouvelle liste deviens la liste
		contenuPanier_ = nouvelleListe;

		//Mise a jour de la propriete capacite_
		capaciteContenu_ *= 2;

		//Ajout du produit a la nouvelle liste
		contenuPanier_[nombreContenu_++] = nouveauProduit;

	}
	
	totalAPayer_ += nouveauProduit->obtenirPrix();

}