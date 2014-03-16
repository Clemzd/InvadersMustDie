#include "CaseInvaders.h"

/**
 * @file Case.cpp
 * Implémentation des méthodes de la classes Case.
 */

void CaseInvaders::init(int xx, int yy) {
	x = xx;
	y = yy;
	setCaseVide();
}
;

/**
 * Etat de la case
 */
int CaseInvaders::getEtat() {
	return etat;
}
;

void CaseInvaders::setEcran(EcranV* e) {
	ecran = e;
}

EcranV* CaseInvaders::getEcran() {
	return ecran;
}

/**
 * Une case standard de l'écran
 */
void CaseInvaders::setCaseVide() {
	etat = VIDE;
}
;

/**
 * Une case contenant un ennemi
 */
void CaseInvaders::setCaseEnnemi() {
	etat = ENNEMI;
}
;

/**
 * Une case contenant un bunker
 */
void CaseInvaders::setCaseBunker() {
	etat = BUNKER;
}
;

/**
 * Ces cases se situent sur les lignes supérieures et inférieures de la map (limites de la carte)
 */
void CaseInvaders::setCaseTrou() {
	etat = TROU;
}
;

/**
 * Case contenant le vaisseau du joueur
 */
void CaseInvaders::setCaseVaisseau() {
	etat = VAISSEAU;
}
;

/**
 * Case contenant un missile
 */
void CaseInvaders::setCaseMissile() {
	etat = MISSILE;
}
;

/**
 * Affiche à l'écran le contenu de la case aux coordonées x et y
 */
void CaseInvaders::paint() {
	ecran->afficherCaractere(x, y, couleurPr(), couleurAr(), Caractere());
}
;

/**
 * Fixe les couleurs des différents états
 */
Couleur CaseInvaders::couleurPr() {
	switch (etat) {
	case VIDE:
		return NOIR;
	case BUNKER:
		return JAUNE;
	case ENNEMI:
		return ROUGE;
	case MISSILE:
		return ROUGE_LEGER;
	case VAISSEAU:
		return VERT;
	default:
		return BLEU_LEGER;
	}
}

/**
 * Fixe la couleur de fond
 */
Couleur CaseInvaders::couleurAr() {
	return NOIR;
}

/**
 * Fixe le caractère correspondant à un état de case
 */
char CaseInvaders::Caractere() {
	switch (etat) {
	case VIDE:
		return ' ';
	case BALLE:
		return '0';
	case ENNEMI:
		return 'V';
	case VAISSEAU:
		return 'U';
	case MISSILE:
		return '|';
	case BUNKER:
		return 'X';
	default:
		return ' ';
	}
}

/**
 * Pour qu'un missile occupe une case
 */
void CaseInvaders::occupeMissile() {
	etatold = etat;
	etat = MISSILE;
	paint();
}
;

/**
 * Pour libérer une case
 */
void CaseInvaders::libere() {
	etat = etatold;
	paint();
}
;

/**
 * Retourne le précédent Etat de la case
 */
int CaseInvaders::EtatOld() {
	return etatold;
}
;

/**
 * Retourne l'état de la case
 */
int CaseInvaders::Etat() {
	return etat;
}
;

