/*
 * GererEnnemiInvaders.cpp
 *
 *  Created on: 28 oct. 2013
 *      Author: Clément
 */
#include "ConfigInvaders.h"
#include "GererEnnemiInvaders.h"
// Constantes
int GererEnnemiInvaders::direction = DROITE;
GererEnnemiInvaders::GererEnnemiInvaders(MapInvaders* mapInvaders, bool* jouer) {
	map = mapInvaders; //pour gérer le contenu des cases
	vivant = jouer; // Gere le game over
	nbEnnemi = NBENNEMI; // nombre d'ennemis en vie
}

GererEnnemiInvaders::~GererEnnemiInvaders() {
}

//Méthode de thread des ennemis
void GererEnnemiInvaders::run() {
	while (*vivant) {
		//Boucle pour gérer la vitesse de déplacement
		for (int i = 0; i < VITESSE_ENNEMI; i++);
		//Les ennemis se déplacent tant que ce n'est pas gameover
		deplacerEnnemi(GererEnnemiInvaders::direction);
	}
}

//Initialisation du thread de déplacement des ennemis
void GererEnnemiInvaders::init() {
	// Initialisation des ennemis
	int ennemiTraite = 0;
	//int ennemiParLigne = NBENNEMI / NB_LIGNE_ENNEMI;
	//Creation du tableau d'ennemis
	for (int i = 1; i < NB_LIGNE_ENNEMI + 1; i++) {
		// Nombre d'ennemis
		for (int j = 5; j < LARGEUR - 5; j++) {
			// Decalage des ennemis d'une ligne sur l'autre
			if (j == 5 && i % 2 == 0) {
				j = 6;
			}
			if (ennemiTraite < NBENNEMI) {
				tableauEnnemi[ennemiTraite].init(i, j);
				ennemiTraite++;
			} else {
				break;
			}
			j = j + 1; // (LARGEUR/ennemiParLigne) ; // gestion de multi lignes
		}
	}
	//Affichage des ennemis
	for (int i = 0; i < NBENNEMI; i++) {
		map->getCase(tableauEnnemi[i].getLigne(), tableauEnnemi[i].getColonne())->setCaseEnnemi();
		map->getCase(tableauEnnemi[i].getLigne(), tableauEnnemi[i].getColonne())->paint();
	}
}

//Deplacement des ennemis
void GererEnnemiInvaders::deplacerEnnemi(int direction) {
	//déplacement de chaque ennemi
	for (int i = 0; i < nbEnnemi; i++) {
		//Mise en place vecteur direction
		int dx = 0;
		//Déplacement latéral droite ou gauche
		if (GererEnnemiInvaders::direction == DROITE) {
			//direction
			dx = 1;
			//Si on arrive au bord droit on descend tous les ennemis
			if (tableauEnnemi[i].getColonne() >= LARGEUR - 1) {
				GererEnnemiInvaders::direction = GAUCHE;
				dx = -1;
				descendreEnnemi();
				break;
			}
			//Gestion des collisions (sauf missile gerer dans gererMissileInvaders)
			switch (map->getCase(tableauEnnemi[i].getLigne(), tableauEnnemi[i].getColonne() + dx)->getEtat()) {
			case BUNKER: //l'ennemi meure et le bunker est détruit
				map->getCase(tableauEnnemi[i].getLigne(), tableauEnnemi[i].getColonne() + dx)->setCaseVide();
				map->getCase(tableauEnnemi[i].getLigne(), tableauEnnemi[i].getColonne())->setCaseVide();
				supprimerEnnemi(tableauEnnemi[i].getLigne(), tableauEnnemi[i].getColonne());
				break;
			case VAISSEAU:
				*vivant = false; // Game over
				break;
			case VIDE://l'ennemi avance
				map->getCase(tableauEnnemi[i].getLigne(), tableauEnnemi[i].getColonne())->setCaseVide();
				tableauEnnemi[i].droite();
				map->getCase(tableauEnnemi[i].getLigne(), tableauEnnemi[i].getColonne())->setCaseEnnemi();
				break;
			default:
				break;
			}
		} else {
			//direction
			dx = -1;
			//Si on arrive au bord gauche on descend tous les ennemis
			if (tableauEnnemi[i].getColonne() <= 1) {
				GererEnnemiInvaders::direction = DROITE;
				dx = 1;
				descendreEnnemi();
				break;
			}
			switch (map->getCase(tableauEnnemi[i].getLigne(), tableauEnnemi[i].getColonne() + dx)->Etat()) {
			case BUNKER://l'ennemi meure et le bunker est détruit
				map->getCase(tableauEnnemi[i].getLigne(), tableauEnnemi[i].getColonne() + dx)->setCaseVide();
				map->getCase(tableauEnnemi[i].getLigne(), tableauEnnemi[i].getColonne())->setCaseVide();
				supprimerEnnemi(tableauEnnemi[i].getLigne(), tableauEnnemi[i].getColonne());
				break;
			case VAISSEAU:
				*vivant = false; // Game over
				break;
			case VIDE://l'ennemi avance
				map->getCase(tableauEnnemi[i].getLigne(), tableauEnnemi[i].getColonne())->setCaseVide();
				tableauEnnemi[i].gauche();
				map->getCase(tableauEnnemi[i].getLigne(), tableauEnnemi[i].getColonne())->setCaseEnnemi();
			}

		}

	} // fin déplacement de chaque ennemi

	//Raffraichissement de l'écran
	map->afficher();
}

//Arriver au bout d'une ligne, tous les ennemis descendent d'une ligne
void GererEnnemiInvaders::descendreEnnemi() {
	for (int i = 0; i < nbEnnemi; i++) {
		map->getCase(tableauEnnemi[i].getLigne(), tableauEnnemi[i].getColonne())->setCaseVide();
		tableauEnnemi[i].descendre();
		switch (map->getCase(tableauEnnemi[i].getLigne(), tableauEnnemi[i].getColonne())->getEtat()) {
		case BUNKER:// suppression du bunker et mort de l'ennemi
			supprimerEnnemi(tableauEnnemi[i].getLigne(), tableauEnnemi[i].getColonne());
			map->getCase(tableauEnnemi[i].getLigne(), tableauEnnemi[i].getColonne())->setCaseVide();
			break;
		case VAISSEAU:
			*vivant = false; // Game over
			break;
		case TROU: // L'ennemi meure car sort de la zone
			supprimerEnnemi(tableauEnnemi[i].getLigne(), tableauEnnemi[i].getColonne());
			break;
		case VIDE: // l'ennemi avance
			map->getCase(tableauEnnemi[i].getLigne(), tableauEnnemi[i].getColonne())->setCaseEnnemi();
			break;
		default:
			break;
		}
	}
}

//Getter du tableau d'ennemis présents
EnnemiInvaders* GererEnnemiInvaders::getTableauEnnemi() {
	return tableauEnnemi;
}
;

//non utilisé , destruction du thread
void GererEnnemiInvaders::exit() {
	Exit();
}

//Supprime un ennemi dans la table d'ennemis
void GererEnnemiInvaders::supprimerEnnemi(int ligne, int colonne) {
	bool decale = false;
	for (int i = 0; i < nbEnnemi; i++) {
		// On ne touche pas au tableau tant que l'on est pas rendu à celui que l'on désire supprimé
		if (!decale && tableauEnnemi[i].getLigne() == ligne && tableauEnnemi[i].getColonne() == colonne) {
			decale = true;
		} else if (decale) { //Ensuite on décale tous les suivant d'un rang, écrasant l'ennemi à suppprimé
			tableauEnnemi[i - 1] = tableauEnnemi[i];
		}
	}
	nbEnnemi--; // ennemi supprimé donc un ennemi en moins
}
;

//Getter du nombre d'ennemis
int GererEnnemiInvaders::getNbEnnemi() {
	return nbEnnemi;
}
;

