#include "Rayon.h"

Rayon::Rayon() : categorie_("inconnu"), tousProduits_(nullptr), capaciteProduits_(0), nombreProduits_(0) {}

Rayon :: Rayon(string cat) : categorie_(cat), tousProduits_(nullptr), capaciteProduits_(0), nombreProduits_(0){}

string Rayon ::  obtenirCategorie()
{
	return categorie_;
}

Produit** Rayon :: obtenirTousProduits()
{
	return  tousProduits_;
}

int Rayon :: obtenirCapaciteProduits()
{
	return capaciteProduits_;
}

int Rayon :: obtenirNombreProduits()
{
	return nombreProduits_;
}

void Rayon::modifierCategorie(string cat)
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
		Produit** nouvelleListe = new Produit*[capaciteProduits_ + 5]; // creer une nouvelle liste avec une capacite augmentee de 5

		for (int i = 0; i < capaciteProduits_; i++) 
			nouvelleListe[i] = tousProduits_[i]; // transferre les produits de la liste initial a la nouvelle liste
		
		delete[] tousProduits_; // desaloue la liste initial

		tousProduits_ = nouvelleListe; // la nouvelle liste devient la liste initial

		capaciteProduits_ += 5; // incremente l'attribut capaciteProduits par 5

		tousProduits_[nombreProduits_++] = produit; // ajout du produit dans la nouvelle liste
	}	
}

void Rayon::afficher() 
{
	cout << "Categorie : " << categorie_ << endl << "Nombre de produits : " 
		<< nombreProduits_ << endl << " Capacite : " << capaciteProduits_ << endl;
	
	for (int i = 0; i < nombreProduits_; i++)
	{
		(*tousProduits_)[i].afficher();
	}
}





