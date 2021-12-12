<p align="center"><h1 align="center">Projet Info 1 - Gestion de dates</h1></p>

Ce projet a pour but la réalisation de fonctions permettant la manipulation de dates réprésentées par un type composé.

---

## <ins>Algorithme</ins>
Voici une grande partie l'algorithme de tout le projet codé en C++  
Les surcharges d'opérateur n'étant pas fesables en algorithme, des fonctions les remplacents ici  
Certaines fonctions en C étant litéralement impossibles à traduire en algoithme, elle ne sont donc pas présentes ici  

---

### <ins>Lexique principal</ins>

**{Type composé : date}**  
date : un type composé de  
<p>
<
  <ul>
    <li>jour  : un entier</li>
    <li>mois  : un entier</li>
    <li>année : un entier</li>
  </ul>
>
</p>

**{Création d'une variable de type date}**  
d : une date

**{Déclaration des fonctions utilisées}**
Menu : la fonction (vide) -> vide  
Saisie : la fonction (vide) -> une date  
Ajouter : la fonction (daj : une date, str : une chaine de charactères) -> une date  
Afficher : la fonction (daf: une date) -> vide  
Convertir : la fonction (dc : une date) -> un entier  
Modélisation : la fonction () ->  


### <ins>Définition des fonctions</ins>

{  
&ensp;R : Permet d'afficher le menu  
&ensp;E : vide  
&ensp;S : vide  
}  
Menu : la fonction (vide) -> vide  

**Lexique {Local}:**  
&ensp;vide  

**Algorithme {Local} :**  
Début  
&ensp;Ecrire ("Bienvenue sur ce programme de gestion de dates)  

&ensp;Ecrire ("Pour saisir une date, tapez 1")  
&ensp;Ecrire ("Pour Afficher la date saisie, tapez 2")  
&ensp;Ecrire ("Pour ajouter 2 dates, tapez 3")  
&ensp;Ecrire ("Pour convertir une date en JENSAISRIEN, tapez 4")  
&ensp;Ecrire ("Pour MODELISATION PTN FONCTION DE MERDE, tapez 5")  
&ensp;Ecrire ("Sinon, tapez 0 pour quitter")  
Fin  
<br>  
<br>  
 
{  
&ensp;R : Permet d'afficher une date  
&ensp;E : vide  
&ensp;S : vide  
}  
Afficher : la fonction (daf: une date) -> vide 

**Lexique {Local} :**  
&ensp;vide

**Algorithme {Local} :**  
Début  
&ensp;Ecrire (daf)  
Fin  
<br>  
<br>  

{  
&ensp;R : Permet de saisir une date  
&ensp;E : vide  
&ensp;S : 1 date  
}  
Afficher : la fonction (d: une date) -> vide 

**Lexique {Local} :**  
&ensp;ds : 1 date  

**Algorithme {Local} :**  
Début  
&ensp;Ecrire ("Saisir le jour")  
&ensp;Lire (ds.jour)  
&ensp;Ecrire ("Saisir le mois")  
&ensp;Lire (ds.mois)  
&ensp;Ecrire ("Saisir l'année")  
&ensp;Lire (ds.année)  

&ensp;Retourner date  
Fin  


