/*
 * EnnemiInvaders.h
 *
 *  Created on: 25 oct. 2013
 *      Author: Benjamin
 */

#ifndef ENNEMIINVADERS_H_
#define ENNEMIINVADERS_H_

#include "ConfigInvaders.h"

/**
 * @file EnnemiInvaders.h
 * @class EnnemiInvaders
 * @brief EnnemiInvaders
*/

class EnnemiInvaders {
	int ligne,colonne;
public :
	void init(int x, int y);
	int getLigne();
	int getColonne();

	//Methodes de déplacement de l'ennemi
	void gauche();
	void droite();
	void descendre();
};

#endif /* EnnemiInvaders_H_ */
