#include "MapInvaders.h"

MapInvaders::MapInvaders(EcranV* e) {
	//Initialisation de la MapInvaders
	for (int x = 0; x < HAUTEUR; x++) {
		for (int y = 0; y < LARGEUR; y++) {
			tab[x][y].init(x, y);
			tab[x][y].setEcran(e);
		}
	}
	//Vaisseau du joueur
	vaisseau = new Vaisseau();
}
;

Vaisseau* MapInvaders::getVaisseau(){
	return vaisseau;
}

void MapInvaders::init() {

// Gestion des bords
	for(int i=0;i< LARGEUR;i++){
		tab[0][i].setCaseTrou();
		tab[HAUTEUR][i].setCaseTrou();
	}
	
	// Initialisation du vaisseau
	tab[HAUTEUR - 1][LARGEUR / 2].setCaseVaisseau();
	tab[HAUTEUR - 1][LARGEUR / 2].paint();

	// Initialisation des bunkers
	int bord = 1;
	// on cree des bunkers tant qu'on peut
	while ((bord + TAILLE_BUNKER_LARGEUR) < LARGEUR) {
		// taille des bunkers en hauteur
		for (int y = 1; y < TAILLE_BUNKER_HAUTEUR; y++) {
			// taille des bunkers en largeur
			for (int i = 0; i < TAILLE_BUNKER_LARGEUR; i++) {
				tab[HAUTEUR - 3 - y][bord + i].setCaseBunker();
				tab[HAUTEUR - 3 - y][bord + i].paint();
			}
		}
		// espace entre bunker
		bord = bord + 7;
	}

}

void MapInvaders::deplacer(int gd) {
	int derniereLigne = HAUTEUR - 1;

	//	int size = Vaisseau::dessin_size;
	if (gd == GAUCHE) {
		if (vaisseau->getColonne() >= 1) {
			// Vider la case actuel
			tab[derniereLigne][vaisseau->getColonne()].setCaseVide();
			tab[derniereLigne][vaisseau->getColonne()].paint();
			vaisseau->gauche();
			tab[derniereLigne][vaisseau->getColonne()].setCaseVaisseau();
			tab[derniereLigne][vaisseau->getColonne()].paint();
		}
	} else {
		if (vaisseau->getColonne() <= LARGEUR - 2) {
			tab[derniereLigne][vaisseau->getColonne()].setCaseVide();
			tab[derniereLigne][vaisseau->getColonne()].paint();
			vaisseau->droite();
			tab[derniereLigne][vaisseau->getColonne()].setCaseVaisseau();
			tab[derniereLigne][vaisseau->getColonne()].paint();
		}
	}
}

CaseInvaders* MapInvaders::getCase(int x, int y) {
	return &tab[x][y];
}

/**
 * Permet d'actualiser l'affichage de la map entière
 */
void MapInvaders::afficher(){
	for (int x=0 ; x<HAUTEUR ; x++) {
		for (int y=0 ; y<LARGEUR ; y++) {
			tab[x][y].paint();
		}
	}
}
;
