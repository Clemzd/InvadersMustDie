/*
 * GererMissileInvaders.h
 *
 *  Created on: 28 oct. 2013
 *      Author: Guillaume
 */

#ifndef GERERMISSILEINVADERS_H_
#define GERERMISSILEINVADERS_H_
#include <sextant/Activite/Threads.h>
#include "ConfigInvaders.h"
#include "MissileInvaders.h"
#include "MapInvaders.h"


class GererMissileInvaders: public Threads {
	MapInvaders* map;
	MissileInvaders tableauMissile[100];
	int nbMissile;
	bool* vivant;
public:
	GererMissileInvaders(MapInvaders* mapInvaders, bool* jouer);
	virtual ~GererMissileInvaders();
	void run();
	MissileInvaders* getTableauMissile();
	void ajouterMissile(MissileInvaders missile);// dans le tableau de missiles
	void supprimerMissile(int indice); // du tableau de missiles
	void setNbMissile(int nb); // nombre total de missiles
	void exit();
};

#endif /* GERERMISSILEINVADERS_H_ */
