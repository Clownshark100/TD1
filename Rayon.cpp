#include "Rayon.h"

Rayon :: Rayon(string cat) : categorie_(cat), tousProduits_(nullptr), capaciteProduits_(0), nombreProduits_(0){}

Rayon ::~Rayon() {
	delete[] tousProduits_;
}

string Rayon ::  obtenirCategorie() const
{
	return categorie_;
}

Produit** Rayon :: obtenirTousProduits() const
{
	return  tousProduits_;
}

int Rayon :: obtenirCapaciteProduits() const
{
	return capaciteProduits_;
}

int Rayon :: obtenirNombreProduits() const
{
	return nombreProduits_;
}

void Rayon::modifierCategorie(const string cat)
{
	categorie_ = cat;
}

void Rayon :: ajouterProduit(Produit * produit)
{
	if (nombreProduits_ < capaciteProduits_){
		tousProduits_[nombreProduits_++] = produit;
	}
	else
	{
		Produit** nouvelleListe = new Produit*[capaciteProduits_ + 5]; // crée une nouvelle liste avec une capacité augmentée de 5

		for (int i = 0; i < capaciteProduits_; i++) 
			nouvelleListe[i] = tousProduits_[i]; // transfère les pointeurs aux produits de la liste initiale à la nouvelle liste
		
		delete[] tousProduits_; // désalloue la liste initiale

		tousProduits_ = nouvelleListe; // la nouvelle liste devient la liste initiale

		capaciteProduits_ += 5; // incrémente l'attribut capaciteProduits par 5

		tousProduits_[nombreProduits_++] = produit; // ajoute le produit dans la nouvelle liste
	}	
}

void Rayon::afficher() const
{
	cout << "Categorie : " << categorie_ << endl << "Nombre de produits : " 
		<< nombreProduits_ << endl << " Capacite : " << capaciteProduits_ << endl;
	
	for (int i = 0; i < nombreProduits_; i++)
	{
		tousProduits_[i]->afficher();
	}
}





