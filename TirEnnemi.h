/*
 * TirEnnemi.h
 *
 *  Created on: 29 oct. 2013
 *      Author: Guillaume
 */

#ifndef TIRENNEMI_H_
#define TIRENNEMI_H_
#include <sextant/Activite/Threads.h>
#include "ConfigInvaders.h"
#include "GererMissileInvaders.h"
#include "GererEnnemiInvaders.h"
#include "MissileInvaders.h"
#include "MapInvaders.h"
#include "RandomInvaders.h"


class TirEnnemi: public Threads {
private :
	GererEnnemiInvaders* gererEnnemiInvaders; //Thread de gestion des ennemis
	GererMissileInvaders* gererMissileInvaders; //Thread de gestion des missiles
	MapInvaders* map; //pour gérer le contenu des cases
	bool* vivant; // gere le game over
	/*
	 * Générateur d'entiers aléatoires.
	 */
		RandomInvaders random;
public:
	TirEnnemi(GererEnnemiInvaders* gererEnnemiInvaders,GererMissileInvaders* gererMissileInvaders, MapInvaders* map, bool* jouer);
	virtual ~TirEnnemi();
	void run(); // un ennemi aléatoire de la ligne du bas tire un missile
	void exit();
};

#endif /* TirEnnemi_H_ */
