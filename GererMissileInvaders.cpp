/*
 * GererMissileInvaders.cpp
 *
 *  Created on: 28 oct. 2013
 *      Author: Guillaume
 */

#include "GererMissileInvaders.h"
#include  "MapInvaders.h"
#include "MissileInvaders.h"
#include "ConfigInvaders.h"

GererMissileInvaders::GererMissileInvaders(MapInvaders* mapInvaders, bool* jouer) {
	map = mapInvaders; //pour gérer le contenu des cases
	nbMissile = 0; //Nombre de missile total sur le terrain
	vivant = jouer; // Gere le game over
}
;

//destructeur
GererMissileInvaders::~GererMissileInvaders() {
}
;

void GererMissileInvaders::run() {
	//Tant que le joueur n'a pas été percuté par un missile
	while (*vivant) {
		//Tous les missiles avancent tant qu'ils ne sont pas détruits
		for (int j = 0; j < nbMissile; j++) {
			if (!tableauMissile[j].avance()) {
				supprimerMissile(j); // suppression de missile perdu ou écrasé
			}
		}
		map->afficher(); // mise a jour affichage
	}
}
;

/**
 * suppresion d'un missile dans le tableau des missiles
 */
void GererMissileInvaders::supprimerMissile(int indice) {
	bool decale = false;
	// On ne touche pas au tableau tant que l'on est pas rendu à celui que l'on désire supprimé
	for (int i = 0; i < nbMissile; i++) {
		if (!decale && indice == i) {
			decale = true;
			nbMissile--;
		}
		else if(decale) { //Ensuite on décale tous les suivant d'un rang, écrasant le missile à suppprimer
			tableauMissile[i - 1] = tableauMissile[i];
		}
	}
}
;

/**
 * Non utilisé, destruction de thread
 */
void GererMissileInvaders::exit() {
	Exit();
}
/**
 * Ajout d'un missile dans le tableau des missiles
 */
void GererMissileInvaders::ajouterMissile(MissileInvaders missile) {
	tableauMissile[nbMissile] = missile;
	nbMissile++;
}
;
/**
 * Permet de fixer le nombre total de missiles.
 */
void GererMissileInvaders::setNbMissile(int nb) {
	nbMissile = nb;
}
;

