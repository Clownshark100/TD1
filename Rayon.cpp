/********************************************
* Titre: Travail pratique #1 -Rayon.cpp
* Date: 20 janvier 2018
* Auteur: Loic Leblanc et Daniel Nahum
*******************************************/
#include "Rayon.h"
/**
* Constructeur par default et parametre
*/
Rayon :: Rayon(string cat) : categorie_(cat), tousProduits_(nullptr), capaciteProduits_(0), nombreProduits_(0){}
/**
* Destructeur de Rayon, desalloue le tableau de pointeurs tousProduits_
*/
Rayon ::~Rayon() {
	delete[] tousProduits_;
}
/**
* Accesseur de categorie_
*/
string Rayon ::  obtenirCategorie() const
{
	return categorie_;
}
/**
* Accesseur du tableau de pointeurs tousProduits_
*/
Produit** Rayon :: obtenirTousProduits() const
{
	return  tousProduits_;
}
/**
* Accesseur de capaciteProduits_
*/
int Rayon :: obtenirCapaciteProduits() const
{
	return capaciteProduits_;
}
/**
* Accesseur de nombreProduits_
*/
int Rayon :: obtenirNombreProduits() const
{
	return nombreProduits_;
}
/**
* Modifie la valeur de categorie_ par la valeur cat passee en parametre
*/
void Rayon::modifierCategorie(const string cat)
{
	categorie_ = cat;
}
/**
* Ajoute un pointeur a un produit a la liste tousProduits_. Gere la memoire de de tousProduits_.
*/
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
/**
* Affiche la categorie, le nombre de produits, la capacite du rayon, et les produits
*/
void Rayon::afficher() const
{
	cout << "Categorie : " << categorie_ << endl << "Nombre de produits : " 
		<< nombreProduits_ << endl << " Capacite : " << capaciteProduits_ << endl;
	
	for (int i = 0; i < nombreProduits_; i++)
	{
		tousProduits_[i]->afficher();
	}
}





