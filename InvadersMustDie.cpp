/*
 * InvadersMustDie.cpp
 *
 *  Created on: 17 oct. 2008
 *      Author: Clement
 */

#include "InvadersMustDie.h"
#include "MissileInvaders.h"

int InvadersMustDie::score = 0;
// boolean a true tant que le joueur est vivant
bool jouer = true;

InvadersMustDie::InvadersMustDie(EcranV *ec, ClavierV *c) {
	ecran = ec;
	clavier = c;
	map = new MapInvaders(ecran); //pour gérer le contenu des cases
	gererEnnemiInvaders = new GererEnnemiInvaders(map, &jouer); //Thread gérant les ennemis
	gererMissileInvaders = new GererMissileInvaders(map, &jouer); // Thread gérant les missiles
	gererMissileInvaders->setNbMissile(0); // Création tableau de missiles à 0
	tirEnnemi = new TirEnnemi(gererEnnemiInvaders,gererMissileInvaders,map, &jouer); // Thread gérant les tirs ennemis (de façon aléatoire)
}

InvadersMustDie::~InvadersMustDie() {

}

void InvadersMustDie::run() {	//Fonction principale
	ecran->effacerEcranV(NOIR); // écran noir
	map->init(); // Initialisation de la map : cases vides, trous en haut et en bas, vaisseau en bas
	gererEnnemiInvaders->init(); // Initialisation des ennemis : cases ennemis + tableau ennemis
	gererEnnemiInvaders->start("Gerer Ennemi"); // Démarrage du thread des ennemis
	gererMissileInvaders->start("Gerer Missile"); // Démarrage du thread des missiles
	tirEnnemi->start("Tir Ennemi"); // Démarrage du thread des tirs d'ennemis aléatoires
	//Tant que le joueur n'est pas mort on joue
	while (jouer) {
		//Attente de l'appui du joueur sur une touche
		char c = clavier->getChar();
		switch (c) {
		case 's': // déplacement du vaisseau gauche
			map->deplacer(GAUCHE);
			break;
		case 'd': // déplacement du vaisseau droit
			map->deplacer(DROITE);
			break;
		case ' ': { // Tir du vaisseau
			MissileInvaders* missile = new MissileInvaders(); //Creation missile
			missile->init(HAUT, HAUTEUR - 2, map->getVaisseau()->getColonne(), VERT, map, gererEnnemiInvaders, &jouer);
			gererMissileInvaders->ajouterMissile(*missile); // Ajout dans tableau des missiles
			break;
		}
		case 'q': // Provoque un game over
			jouer = false;
		}
	}
	//GAME OVER
	ecran->effacerEcranV(NOIR);
	ecran->afficherMot(20,40,"GAME OVER",ROUGE);
}
