/**************************************************
* Titre: Travail pratique #1 - Main.cpp
* Date: 20 janvier 2018
* Auteur: Mohammed Esseddik BENYAHIA
**************************************************/
/* 
Question 1 : Quel est le lien (agrégation ou composition) entre la classe Client et la classe Panier ?
C'est une composition parce que le panier fait partie intégrale du client et ne peut pas appartenir à un autre client. Cela est mis en évidence par la destruction du Panier dans le destructeur de Client.
Question 2 : Quel est le lien (agrégation ou composition) entre un Produit et un Rayon ? 
C'est une agrégaton puisque le produit peut exister sans le rayon. De ce faut, Rayon ne contient qu'un pointeur aux Produits et seul le tableau de pointeur est désalloué lors de la destruction de Rayon, pas les Produits eux-mêmes.

*/

#include "Produit.h"
#include "Rayon.h"
#include "client.h"
#include "panier.h"
#include <string>
#include <iostream>

using namespace std;

int main()
{
	//C'est à vous de voir si vous devez allouer dynamiquement ou non les élèments

	//1-  Creez 15 objets du classe produit
	Produit** produits = new Produit*[15];
	for (int i = 0; i < 15; i++)
		produits[i] = new Produit();
    
	//2-  Modifiez le nom, la référence, le prix de  troisieme objet Produit créé
	produits[2]->modifierNom("Casquette Sonex");
	produits[2]->modifierReference(3);
	produits[2]->modifierPrix(12.99);
	//   afficher les attributs de cet objet Produit
	produits[2]->afficher();
	
	//3-  Creez un objet du classe rayon à l'aide du constructeur par défaut
	Rayon rayon;
	//4-  Modifiez la catégorie  du rayon
	rayon.modifierCategorie("Accessoires");
	// 5- Ajouter 6 produits de  voret chaoix dans le rayon créé
    	for (int i =0; i < 6; i++)
	{
		rayon.ajouterProduit(produits[i]);
	}

	// 6- afficher le contenu du rayon
	rayon.afficher();
  
	//7-  Creez un objet de classe client à l'aide du constructeur
	Client* client = new Client("of Rivia", "Geralt", 1, "H92 D23", 1997);

	//8-  afficher l'etat des attributs du client
	cout << client->obtenirPrenom() << " " << client->obtenirNom() << endl
		<< client->obtenirIdentifiant() << endl
		<< client->obtenirCodePostal() << endl
		<< client->obtenirDateNaissance() << endl;

	//9-   Le client achete 9 produits
	for (int i = 0; i < 9; i++)
	{
		client->acheter(produits[i]);
	}

	//10- Afficher le contenu du panier du client
	client->afficherPanier();
	//11- livrer le panier du client
	client->livrerPanier();
    
	//12- afficher le contenu du panier du client
	client->afficherPanier();                 
	//13-  terminer le programme correctement
	delete client;
	client = nullptr;

	for (int i = 0; i < 15; i++) {
		delete produits[i];
	}
	delete[] produits;
	produits = nullptr;
	
	return 0;
}
