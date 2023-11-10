#ifndef DONNEUR_H_INCLUDED
#define DONNEUR_H_INCLUDED
#include<stdio.h>
typedef struct
{
int id_donneur;
char nom_donneur[20];
char prenom_donneur[20];
int cin_donneur;
int DN_jour_donneur;
int DN_mois_donneur;
int DN_annee_donneur;
char sexe_donneur[10];
char hebergement_donneur[20];
int numero_donneur;
char mail_donneur[30];
char maladie_chronique_donneur[20];
}donneur;

int ajout_donneur(donneur d, char* filename);
int modifier_donneur(int id_donneur, donneur nouv,char* filename);
int supprimer_donneur(int id_donneur,char* filename);
void afficher_donneur(char * filename);
donneur chercher_donneur(int id_donneur ,char *filename );


#endif // DONNEUR_H_INCLUDED
