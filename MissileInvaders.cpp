/*
 * MissileInvaders.cpp
 *
 */
#include "MapInvaders.h"
#include "MissileInvaders.h"
void MissileInvaders::init(int dir, int lign, int col, Couleur c, MapInvaders* mapInvaders, GererEnnemiInvaders* gererEnnemiInvaders, bool* jouer) {
	direction = dir; //Direction du missile : HAUT ou BAS
	ligne = lign; //Coordonnée verticale du missile
	colonne = col; //Coordonnée verticale du missile
	couleur = c; //Couleur non utilisée
	map = mapInvaders; //pour gérer le contenu des cases
	vivant = jouer; // Gere le game over
	// Occuper la case :
	map->getCase(lign, col)->occupeMissile();
	this->gererEnnemiInvaders = gererEnnemiInvaders; // thread de gestion des ennemis
}
;

bool MissileInvaders::avance() { //Retourne false si le missile est perdu
	//Mise en place du vecteur direction
	int dx = 0;
	if (direction == BAS){
		dx = 1;
	}else{
		dx = -1;
	}
	//booleen témoignant de la présence du missile dans l'écran
	bool nonTermine = false;
	//Collision :
	switch (map->getCase(ligne + dx, colonne)->getEtat()) {
	case ENNEMI: // Destruction de l'ennemi
		map->getCase(ligne + dx, colonne)->setCaseVide();
		gererEnnemiInvaders->supprimerEnnemi(ligne + dx, colonne);
		break;
	case BUNKER: // Destruction du bunker
		map->getCase(ligne + dx, colonne)->setCaseVide();
		break;
	case VIDE: // Pas d'obstacle
		map->getCase(ligne + dx, colonne)->setCaseMissile();
		nonTermine = true; // le missile n'est pas encore détruit
		break;
	case VAISSEAU://Quand le joueur est touché
		//Game over
		*vivant = false;
		break;
	case TROU: //Missile perdu
		break;
	case MISSILE:
		// Si l'utilisateur tire trop rapidement, deux missiles peuvent rentrer en collision
		// Ou bien si l'ennemi tire en même temps que l'utilisateur
		map->getCase(ligne + dx, colonne)->setCaseVide();
		break;
	default:
		break;
	}
	//On libère la case précédente
	map->getCase(ligne, colonne)->setCaseVide();
	//Mise à jour de la position actuelle du missile
	ligne = ligne + dx;
	return nonTermine;
}

/**
 * Destructeur
 */
MissileInvaders::~MissileInvaders() {

}

//position verticale du missile
int MissileInvaders::getLigne() {
	return ligne;
}

//position horizontale du missile
int MissileInvaders::getColonne() {
	return colonne;
}
