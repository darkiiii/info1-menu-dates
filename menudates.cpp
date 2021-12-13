#include <iostream>
#include "menudates.h"

using std::cout; using std::cin; using std::endl; using std::ostream; using std::istream;

const int MOIS[12] = { 31, 28, 31, 30, 31, 30, 31, 30, 31, 30, 31, 30 };

// Equivalent de la fonction Affichage : surcharge de cout
ostream& operator<< (ostream& os, const Date& d)
{
	os << d.j << ':' << d.m << ':' << d.a;
	return os;
}

// Equivalent de la fonction Saisie : surchage de cin
istream& operator>> (istream& is, Date& d)
{
	// Variable pour stocker l'entrée de l'utilisateur
	char in[11];
	// On lit la chaine entrée par l'utilisateur
	is >> in;
	// On initialise la variable d
	d = Date{ 0, 0, 0 };


	// ANALYSE DE LA CHAINE
	int status = 0;
	int i = 0;
	int j = 0;
	while( in[i] != '\0' && i < 11 ) {
		// Si le charactère est : on passe à l'entrée suivante entre jour/mois/année
		if (in[i] == ':') {
			j = 0;
			status++;
		}
		// Sinon on enregistre le charactère dans la bonne variable
		else {
			switch (status)
			{
			case 0:
				// Si on a déjà enregistré un nombre pour cette variable, on la multiplie par 10 car c'est le chiffre des 10aines ou plus
				if (j != 0) d.j *= 10;
				// Puis on ajoute le nouveau chiffre lu
				// le -48 c'est car le code ascii des chiffres c'est chiffre + 48
				d.j += in[i] - 48;
				break;
			case 1:
				// La même chose qu'au dessus
				if (j != 0) d.m *= 10;
				d.m += in[i] - 48;
				break;
			case 2:
				// Ici avec les années ça marche parreil mais on se retrouve à passer plusieurs fois (jusqu'à 4 normalement)
				if (j != 0) d.a *= 10;
				d.a += in[i] - 48;
				break;
			}
			j++;
		}
		i++;
	}

	return is;
}

// Equivalent de la fonction ajouter : surcharge de l'opérateur +
Date operator+(Date const& d1, Date const& d2) {
	// La date de sortie prend la valeur de la date 1
	Date ds = d1;

	// On ajoute les années et les jours
	ds.a += d2.a;
	ds.j += d2.j;

	// On ajoute le bon nombre d'années si le nombre de jours est supérieur à 365/366
	while (ds.j > (365 + (Bisextile(ds.a) ? 1 : 0))) {
		ds.j -= (365 + (Bisextile(ds.a) ? 1 : 0));
		ds.a += 1;
	}

	// On ajoute le bon nombre des mois si le nombre de jours ne rentre pas dans le mois
	while (ds.j > MOIS[ds.m - 1] + ((Bisextile(ds.a) && ds.m == 2) ? 1 : 0)) {
		ds.j -= MOIS[ds.m - 1] + ((Bisextile(ds.a) && ds.m == 2) ? 1 : 0);
		ds.m += 1;
	}

	// On ajoute le nombre de mois (effectivement c'est pas parfait mais c'était trop long sinon)
	ds.m += d2.m;

	ds.a += ds.m / 12;
	ds.m %= 12;
	ds.m += 1;

	return ds;
}

/*
* R : renvoie la puissance de 10 associée au nombre en paramètre
* E : un entier
* S : un entier
*/
int PuissanceDe10(int i) {
	int n = 1;
	for (int j = 0; j < i; j++) {
		n *= 10;
	}
	return n;
}

/*
* R : teste si une année est bisextile
* E : un nombre
* S : un booléen
*/
bool Bisextile(int a) {
	return ((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0 && a % 4000 != 0));
}

/*
* R: Permet d'afficher le menu
* E : vide
* S : vide
*/
void Menu(void) {
	cout << endl << endl << "Pour saisir une date, tapez 1" << endl;
	cout << "Pour afficher la date enregistree, tapez 2" << endl;
	cout << "Pour ajouter 2 dates, tapez 3" << endl;
	cout << "Sinon, tapez 0 pour quitter" << endl;
}