#include "EnnemiInvaders.h"
/*
 * EnnemiInvaders.cpp
 *
 *  Created on: 25 oct. 2013
 *      Author: Benjamin
 */

/*
 * Initialisation
 */
void EnnemiInvaders::init(int x, int y){
	ligne = x;
	colonne = y;
}

/**
 * déplacement à gauche d'un ennemi
 */
void EnnemiInvaders::gauche() {
	colonne--;
}

/**
 * déplacement à droite d'un ennemi
 */
void EnnemiInvaders::droite() {
	colonne++;
}

/**
 * déplacement en bas d'un ennemi
 */
void EnnemiInvaders::descendre() {
	ligne++;
}

/**
 * Retourne la position verticale d'un ennemi
 */
int EnnemiInvaders::getLigne() {
	return ligne;
}

/**
 * Retourne la position horizontale d'un ennemi
 */
int EnnemiInvaders::getColonne() {
	return colonne;
}
