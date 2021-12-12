struct Date
{
	int j;
	int m;
	int a;
};

// Surchage de l'opérateur << pour le rendre compatible avec les dates
std::ostream& operator<<(std::ostream& os, const Date& d);
std::istream& operator>>(std::istream& os, Date& d);
Date operator+(Date const& d1, Date const& d2);

/*
* R : teste si une année est bisextile
* E : un nombre
* S : un booléen
*/
bool Bisextile(int a);

/*
* R : Converti une chaine de charactère en une date
* E : une chaine de charactères
* S : une date
*/
Date Convertir(const char[11]);

/*
* R : Ajoute deux dates ou un nombre de jours/mois/années
* E : une date + une chaine de caractère
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