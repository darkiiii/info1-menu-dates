#include <iostream>
#include "menudates.h"

using std::cout; using std::cin; using std::endl;

int main() {
	int choix = -1;
	Date d1{};
	Date d2{};
	bool init = false;

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
			cin >> d1;
			init = true;
			break;
		case 2:
			if (!init) {
				cout << "Vous devez d'abord saisir une date" << endl;
			}
			else {
				cout << "La date enregistree est : " << d1 << endl;
			}
			break;
		case 3:
			if (!init) {
				cout << "Vous devez d'abord saisir une date" << endl;
			}
			else {
				cout << "Veuillez saisir la date a ajouter dans le format JJ:MM:AAAA : ";
				cin >> d2;
				d1 = d1 + d2;
				cout << "Le resultat de l'addition est : " << d1 << endl;
				cout << "Il a remplace la date enregistre precedement" << endl;
			}
			break;
		}
	} while (choix != 0);

	return 0;
}