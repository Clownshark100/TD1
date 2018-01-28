#include "Rayon.h"

Rayon::Rayon() : categorie_("inconnu"), tousProduits_(nullptr), capaciteProduits_(0), nombreProduits_(0) {}

Rayon :: Rayon(string cat) : categorie_(cat), tousProduits_(nullptr), capaciteProduits_(0), nombreProduits_(0){}

Rayon ::~Rayon() {
	delete[] tousProduits_;
}

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
		Produit** nouvelleListe = new Produit*[capaciteProduits_ + 5]; // cr�e une nouvelle liste avec une capacit� augment�e de 5

		for (int i = 0; i < capaciteProduits_; i++) 
			nouvelleListe[i] = tousProduits_[i]; // transf�re les pointeurs aux produits de la liste initiale � la nouvelle liste
		
		delete[] tousProduits_; // d�salloue la liste initiale

		tousProduits_ = nouvelleListe; // la nouvelle liste devient la liste initiale

		capaciteProduits_ += 5; // incr�mente l'attribut capaciteProduits par 5

		tousProduits_[nombreProduits_++] = produit; // ajoute le produit dans la nouvelle liste
	}	
}

void Rayon::afficher() 
{
	cout << "Categorie : " << categorie_ << endl << "Nombre de produits : " 
		<< nombreProduits_ << endl << " Capacite : " << capaciteProduits_ << endl;
	
	for (int i = 0; i < nombreProduits_; i++)
	{
		tousProduits_[i]->afficher();
	}
}





