/*
 * SpaceInvader.h
 *
 *  Created on: 17 oct. 2008
 *      Author: Aur�lien
 */

#ifndef INVADERSMUSTDIE_H_
#define INVADERSMUSTDIE_H_

#include <drivers/EcranV.h>
#include <drivers/ClavierV.h>
#include <sextant/Activite/Threads.h>
#include "MapInvaders.h"
#include "GererEnnemiInvaders.h"
#include "GererMissileInvaders.h"
#include "TirEnnemi.h"

class InvadersMustDie : public Threads {
private:
	EcranV *ecran;
	ClavierV *clavier;
	MapInvaders *map; //pour gérer le contenu des cases
	GererEnnemiInvaders *gererEnnemiInvaders; //Thread gérant les ennemis
	GererMissileInvaders *gererMissileInvaders;  // Thread gérant les missiles
	TirEnnemi *tirEnnemi; // Thread gérant les tirs ennemis (de façon aléatoire)

public:
	InvadersMustDie(EcranV *ec, ClavierV *c);

	virtual ~InvadersMustDie();

	void run();
	void stop();

	static int score;
};

#endif /* InvadersMustDie_H_ */
