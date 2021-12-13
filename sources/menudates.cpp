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
	char in[11];
	is >> in;
	d = Date{ 0, 0, 0 };

	int status = 0;
	int i = 0;
	int j = 0;
	while( in[i] != '\0' && i < 11 ) {
		if (in[i] == ':') {
			j = 0;
			status++;
		}
		else {
			switch (status)
			{
			case 0:
				if (j != 0) d.j *= 10;
				d.j += in[i] - 48;
				break;
			case 1:
				if (j != 0) d.m *= 10;
				d.m += in[i] - 48;
				break;
			case 2:
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
	Date ds = d1;

	ds.a += d2.a;
	ds.j += d2.j;

	while (ds.j > (365 + (Bisextile(ds.a) ? 1 : 0))) {
		ds.j -= (365 + (Bisextile(ds.a) ? 1 : 0));
		ds.a += 1;
	}

	while (ds.j > MOIS[ds.m - 1] + ((Bisextile(ds.a) && ds.m == 2) ? 1 : 0)) {
		ds.j -= MOIS[ds.m - 1] + ((Bisextile(ds.a) && ds.m == 2) ? 1 : 0);
		ds.m += 1;
	}

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
* R : Converti une chaine de charactère en une date
* E : une chaine de charactères
* S : une date
*/
Date Convertir(const char str[11]) {
	Date d;

	d.j = (str[0] - 48) * 10 + (str[1] - 48);
	d.m = (str[3] - 48) * 10 + (str[4] - 48);
	d.a = (str[6] - 48) * 1000 + (str[7] - 48) * 100 + (str[8] - 48) * 10 + (str[9] - 48);

	return d;
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