struct Date
{
	int j;
	int m;
	int a;
};

/*
* R : teste si une ann�e est bisextile
* E : un nombre
* S : un bool�en
*/
bool Bisextile(int a);

/*
* R : Converti une chaine de charact�re en une date
* E : une chaine de charact�res
* S : une date
*/
Date Convertir(const char[11]);

/*
* R : Ajoute deux dates ou un nombre de jours/mois/ann�es
* E : une date + une chaine de caract�re
* S : une date
*/
Date Ajouter(Date, char[]);

/*
* R : Rend une date valide si elle ne l'est pas
* E : une date
* S : une date
*/
Date Verif(Date);

/*
* R : Permet d'afficher le menu
* E : vide
* S : vide
*/
void Menu(void);

/*
* R : Affiche une date dans le format JJ:MM:AAAA
* E : une date
* S : vide
*/
void Affiche(Date);

/*
* R : Demande � l'utilisateur de saisir une date
* E : vide
* S : une date
*/
Date Saisie(void);