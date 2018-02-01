/********************************************
* Titre: Travail pratique #1 - client.h
* Date: 20 janvier 2018
* Auteur: Loic Leblanc et Daniel Nahum
*
* La classe Client permet de ranger les informations des clients et lui 
* attribue un panier pour qu'il faire ses achats
*******************************************/

#ifndef CLIENT_H
#define CLIENT_H
#include <string>
#include "panier.h"
using namespace std;
class Client
{
public:
    Client (string  nom,  string prenom, int identifiant, string codePostal,  long date);
    ~Client();
    // methodes d'acces
    
    string obtenirNom() const;
    string obtenirPrenom() const;
    int obtenirIdentifiant() const;
    string obtenirCodePostal() const;
    long obtenirDateNaissance() const;
    
    // methodes de modification
    void modifierNom(string nom) ;
    void modifierPrenom(string prenom) ;
    void modifierIdentifiant(int identifiant) ;
    void modifierCodePostal(string codePostal);
    void modifierDateNaissance(long date);
    
    // autres méthodes
    void acheter (Produit * prod);
    void afficherPanier() const;
    void livrerPanier();
    
    
private:
    
    string nom_;
    string prenom_;
    int identifiant_;
    string codePostal_;
    long dateNaissance_;
    Panier *  monPanier_;
};
#endif /* client_h */
