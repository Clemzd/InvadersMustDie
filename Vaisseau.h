#ifndef VAISSEAU_H
#define VAISSEAU_H

#include "ConfigInvaders.h"

/**
 * @file Vaisseau.h
 * @class Vaisseau
 * @brief Une Vaisseau du jeu pouvant se déplacer verticalement.
*/

class Vaisseau {
	int colonneG,colonneD,colonne; //colonneD et colonneG de la Vaisseau
public :
	static const char dessin[];
	static const int dessin_size;
	//Constructeurs
	Vaisseau();

	//Données pour vaisseau taille multiple
	int getGauche();
	int getDroite();
	void gauche();
	void droite();
	//Données pour vaisseau un caractère (actuellement utilisé) : déplacement dans MapInvaders
	int getColonne();



};
#endif
