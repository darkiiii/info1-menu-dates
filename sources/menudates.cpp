#include <iostream>
#include "menudates.h"

using std::cout; using std::cin; using std::endl;

const int MOIS[12] = { 31, 28, 31, 30, 31, 30, 31, 30, 31, 30, 31, 30 };

unsigned long long int PuissanceDe10(int i) {
	unsigned long long int n = 1;
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
* R : Ajoute deux dates ou un nombre de jours/mois/années
* E : une date + une chaine de caractère
* S : une date
*/
Date Ajouter(Date di, char l[]) {
	Date ds = di;

	int taille;
	for (taille = 0; l[taille] != '\0'; taille++);
	int mult = 0;
	switch (l[taille-1])
	{
	case 'j':
		for (int i = taille - 1; i >= 0; i--) {
			ds.j += PuissanceDe10(mult) * (l[i] - 48);
			mult++;
		}
		break;
	case 'm':
		for (int i = taille - 1; i >= 0; i--) {
			ds.m += PuissanceDe10(mult) * (l[i] - 48);
			mult++;
		}
		break;
	case 'a':
		for (int i = taille - 1; i >= 0; i--) {
			ds.a += PuissanceDe10(mult) * (l[i] - 48);
			mult++;
		}
		break;
	}

	return Verif(ds);
}

/*
* R : Rend une date valide si elle ne l'est pas
* E : une date
* S : une date
*/
Date Verif(const Date di) {
	Date d = di;
	int nbjm = d.m - (Bisextile(d.a) && (d.m == 2)) ? 0 : 1;
	while(d.j > MOIS[nbjm]) {
		d.j -= MOIS[nbjm];
		d.m++;
		int nbjm = d.m - (Bisextile(d.a) && (d.m == 2)) ? 0 : 1;
	}
	
	while (d.m > 12) {
		d.m -= 1;
		d.a++;
	}

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

/*
* R : Affiche une date dans le format JJ:MM:AAAA
* E : une date
* S : vide
*/
void Affiche(Date d) {
	cout << d.j << ":" << d.m << ":" << d.a;
}

/*
* R: Demande à l'utilisateur de saisir une date
* E : vide
* S : une date
*/
Date Saisie(void) {
	char str[11];
	Date d;

	cin >> str;

	d = Convertir(str);

	return Verif(d);
}