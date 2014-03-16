#ifndef RANDOMINVADERS_H
#define RANDOMINVADERS_H

/**
 * @file RandomInvaders.h
 * @class RandomInvaders
 * @brief Classe permettant de choisir un entier aléatoirement.
 */

class RandomInvaders {
	unsigned long int random(void);

public:
	int nextInt(int);
	bool nextBool(void);
};
#endif

