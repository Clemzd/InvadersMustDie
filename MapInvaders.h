#ifndef MAPINVADERS_H
#define MAPINVADERS_H

#include "CaseInvaders.h"
#include "EnnemiInvaders.h"
#include "ConfigInvaders.h"
#include "Vaisseau.h"


/**
 * @file MapInvaders.h
 * @class MapInvaders
 * @brief La MapInvaders du jeu avec des murs, deux raquettes et des balles.
 */

class MapInvaders {

	/*
	 * Tableau des cases du jeu.
	 */
	CaseInvaders tab[LARGEUR][LARGEUR];

	Vaisseau* vaisseau;

public:
	/**
	 * Construit la MapInvaders avec les murs, les zones privées, le nombre de verrous associés, les raquettes et les trous.
	 */
	MapInvaders(EcranV* e);

	/**
	 * Associe un écran à la MapInvaders et affiche cette dernière.
	 */
	void affiche();
	Vaisseau* getVaisseau();
	CaseInvaders* getCase(int x, int y);
	void deplacer(int gd);
	void init();
	void afficher(); //Permet d'actualiser l'affichage de la map entière

};
#endif
