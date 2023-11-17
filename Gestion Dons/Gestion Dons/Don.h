#ifndef DON_H_INCLUDED
#define DON_H_INCLUDED

#include <stdio.h>

typedef struct
{
    int id;
    char prenom[100]; // Add the prenom field
    char nom[100];
    char gs[10]; // groupe sanguin
    int quantite; // quantité de sang en mL
} Don;

// ajouter
int AjouterDon(char *fichier,Don don);
int IDExiste(char *fichier, int id);

// modifier
int ModifierDon(char *fichier,int id,Don don);

// supprimer
int SupprimerDon(char *fichier,int id);

// chercher
Don ChercherDon(char *fichier,int id);

// afficher
void AfficherDon(char *fichier);

//quantitépartype
int quantite_type(char nomFichier[], char type_sang[]);

//sang rare
void sang_rare(char nomFichier[], char sangRare[]);

#endif // DON_H_INCLUDED
