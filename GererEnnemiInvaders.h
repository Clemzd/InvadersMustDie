/*
 * GererEnnemiInvaders.h
 *
 *  Created on: 28 oct. 2013
 *      Author: Clément
 */

#ifndef GERERENNEMIINVADERS_H_
#define GERERENNEMIINVADERS_H_
#include <sextant/Activite/Threads.h>
#include "ConfigInvaders.h"
#include "MapInvaders.h"
#include "EnnemiInvaders.h"

class GererEnnemiInvaders: public Threads {
	MapInvaders* map;
	EnnemiInvaders tableauEnnemi[20]; //NBENNEMI
	int nbEnnemi;
	bool* vivant;
public:
	GererEnnemiInvaders(MapInvaders* mapInvaders, bool* jouer);
	virtual ~GererEnnemiInvaders();
	void deplacerEnnemi(int direction);
	void descendreEnnemi();
	void init();
	void run();
	EnnemiInvaders* getTableauEnnemi();
	int getNbEnnemi();
	void supprimerEnnemi(int ligne, int colonne);
	static int direction;
	void exit();
};

#endif /* GERERENNEMIINVADERS_H_ */
