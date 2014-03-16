/*
 * MissileInvaders.h
 *
 */

#ifndef MISSILEINVADERS_H_
#define MISSILEINVADERS_H_
#include "MapInvaders.h"
#include "GererEnnemiInvaders.h"


class MissileInvaders {
	int direction, ligne, colonne;
	Couleur couleur; // non utilisé
	bool* vivant; // gère le GAME OVER
	MapInvaders* map; //pour gérer le contenu des cases
	GererEnnemiInvaders* gererEnnemiInvaders; // thread de gestion des ennemis

public:
	void init(int direction, int ligne, int col, Couleur couleur, MapInvaders* map,GererEnnemiInvaders* gererEnnemiInvaders, bool* jouer);
	virtual ~MissileInvaders();
	//méthode d'avancement du missile
	bool avance();
	//coordonnées
	int getLigne();
	int getColonne();
};

#endif /* MISSILEINVADERS_H_ */
