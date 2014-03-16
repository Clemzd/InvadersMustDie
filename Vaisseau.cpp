#include "Vaisseau.h"

char const Vaisseau::dessin[] = {'|','-','-','O','-','-','|'}; // forme de vaisseau taille multiple
int const Vaisseau::dessin_size = 8; // taille dessin vaisseau

Vaisseau::Vaisseau() {
	//Données pour vaisseau taille multiple
	colonneG = LARGEUR/2;
	colonneD = colonneG + dessin_size;
	//Donnée pour vaisseau un caractère ( actuellement utilisé)
	colonne = LARGEUR/2;
}

/**
 * Déplacement à gauche
 */
void Vaisseau::gauche() {
	colonneG--;
	colonneD--;
	colonne--;
}

/**
 * Déplacement à droite
 */
void Vaisseau::droite() {
	colonneG++;
	colonneD++;
	colonne++;
}
/**
 * Retourne position vaisseau , partie gauche (taille multiple)
 */
int Vaisseau::getGauche() {
	return colonneG;
}
/**
 * Retourne position vaisseau , partie droite (taille multiple)
 */
int Vaisseau::getDroite() {
	return colonneD;
}

/**
 * Retourne position vaisseau du joueur ( un caractère)
 */
int Vaisseau::getColonne() {
	return colonne;
}
