#ifndef CONFIG_H
#define CONFIG_H

/***
 * @file ConfigInvaders.h
 * @brief Fichier de configuration du jeu. 
 * N.B. : Les zones doivent être entourées par un espace vide.
 * Les zones doivent être inclues les unes dans les autres
 ***/

/*** Type des cases ***/
#define VIDE 		0
#define BUNKER 		10
#define ENNEMI 		20
#define VAISSEAU	21
#define COMPTEUR 	30
#define BALLE 		40
#define ZONE 		50
#define MISSILE		60
#define TROU		70
/*** Taille du jeu ***/
#define LARGEUR 	80
#define HAUTEUR 	25
/*** Nombre de donnee dans le jeu ***/
#define NB_BUNKER		8
#define TAILLE_BUNKER_LARGEUR 	4
#define TAILLE_BUNKER_HAUTEUR 	4
//Attention à mettre des données cohérentes
#define NB_LIGNE_ENNEMI 1
#define NBENNEMI 20
/*** Vitesse ***/
#define VITESSE_ENNEMI 	10000000
#define VITESSE_MISSILE 100000
#define VITESSE_MISSILE_ENNEMI 10000000
/*** Choix de la raquette ***/
#define GAUCHE 		1
#define DROITE 		2
#define HAUT		3
#define BAS 		4


#endif
