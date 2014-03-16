/*
 * TirEnnemi.cpp
 *
 *  Created on: 29 oct. 2013
 *      Author: Guillaume
 */

#include "TirEnnemi.h"
#include  "MapInvaders.h"
#include "MissileInvaders.h"
#include "GererMissileInvaders.h"
#include "GererEnnemiInvaders.h"
#include "ConfigInvaders.h"
//extern bool jouer;

TirEnnemi::TirEnnemi(GererEnnemiInvaders* gererEnnemiInvaders,GererMissileInvaders* gererMissileInvaders, MapInvaders* map, bool* jouer) {
	this->gererEnnemiInvaders = gererEnnemiInvaders; // Thread de gestion des ennemis
	this->gererMissileInvaders = gererMissileInvaders;
	this->map = map;
	vivant = jouer; // Gere le game over
}
;

TirEnnemi::~TirEnnemi() {
}
;

void TirEnnemi::run() {
	while (*vivant) {
		//Boucle pour l'attente (réglage vitesse)
		for (int i = 0; i < VITESSE_MISSILE_ENNEMI; i++);

		//Un ennemi au hasard de la ligne du bas tire un missile
		EnnemiInvaders* tableauEnnemi = gererEnnemiInvaders->getTableauEnnemi();
		int nbTotalEnnemis = gererEnnemiInvaders->getNbEnnemi();
		int nbEnnemiParLigne = NBENNEMI / NB_LIGNE_ENNEMI; //il faudrait prendre en charge lorsque division ne rend pas un entier
		int indiceDerniereLigne = ((nbTotalEnnemis/nbEnnemiParLigne) - 1) * nbTotalEnnemis;
		int choixEnnemi = indiceDerniereLigne + (random.nextInt(nbTotalEnnemis-indiceDerniereLigne));
		EnnemiInvaders ennemi = tableauEnnemi[choixEnnemi];
		MissileInvaders* missile = new MissileInvaders();
		missile->init(BAS, ennemi.getLigne()+1, ennemi.getColonne(), VERT, map, gererEnnemiInvaders, vivant);
		gererMissileInvaders->ajouterMissile(*missile);
	}

}
;

void TirEnnemi::exit() {
	Exit();
}



