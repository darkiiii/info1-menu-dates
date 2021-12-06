#include <iostream>
#include "menudates.h"

using std::cout; using std::cin; using std::endl;

int main() {
	int choix = -1;
	Date d1;
	bool init = false;
	char toad[100];
	cout << "Bienvenue sur ce programme de gestion de dates" << endl << endl;
	do
	{
		Menu();
		cin >> choix;
		cout << endl;
		switch (choix)
		{
		case 1:
			cout << "Veuillez saisir une date dans le format JJ:MM:AAAA : ";
			d1 = Saisie();
			init = true;
			break;
		case 2:
			if (!init) {
				cout << "Vous devez d'abord saisir une date" << endl;
			}
			else {
				cout << "La date enregistree est : ";
				Affiche(d1);
				cout << endl;
			}
			break;
		case 3:
			if (!init) {
				cout << "Vous devez d'abord saisir une date" << endl;
			}
			else {
				cout << "Veuillez saisir le nombre a ajouter avec j/m/a colle pour jour/mois/annee : ";
				cin >> toad;
				d1 = Ajouter(d1, toad);
			}
			break;
		}
	} while (choix != 0);

	return 0;
}