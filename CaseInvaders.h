#ifndef CASEINVADERS_H
#define CASEINVADERS_H

/**
 * @file Case.h
 * @class Case
 * @brief Une case de la grille de jeu.
 */


#include <drivers/EcranV.h>
#include "ConfigInvaders.h"

class CaseInvaders {
	/**
	 * écran pour l'affichage de la case
	 */
	EcranV* ecran;
	/**
	 * coordonnées de la case dans la grille.
	 */
    int x, y ;
    /**
     * Etat de la case. Permet de savoir si la case est un trou, un mur, une raquette ou une balle.
     */
    int etat;
    int etatold;
    /**
     * Couleur du premier plan de la case.
     */
    Couleur couleurPr();
    /**
     * Couleur de l'arrière plan de la case.
     */
    Couleur couleurAr();
    /**
     * Caractère de la case.
     */
    char Caractere();

public:
	//Modifieurs
	void setEcran(EcranV* e);
	void setCaseEnnemi();
	void setCaseBunker();
	void setCaseTrou();
	void setCaseVaisseau();
    void setCaseVide();
    void setCaseMissile();

    //Accesseurs
    EcranV* getEcran();
    int getEtat();
    /**
     * définit la case x,y comme une case vide.
     */
    void init(int x, int y);

    /**
     * Affiche la case.
     */
    void paint();

    /**
     * Pour qu'un missile occupe une case
     */
    void occupeMissile();
    /**
     * Pour libérer une case
     */
    void libere();
    /**
     * Retourne l'état de la case
     */
    int Etat();
    /**
     * Retourne l'état précédent de la case
     */
    int EtatOld();

};
#endif
