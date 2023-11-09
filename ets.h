#ifndef ETS_H_INCLUDED
#define ETS_H_INCLUDED
#include <stdio.h>

typedef struct{
	int id,region,tel,capacite;
	char nationalite[50],adresse[50];
}Ets;

int ajouter_ets(Ets e,char* filename);
int modifier_ets(int id,Ets e,char* filename);
int supprimer_ets(int id,char* filename);
void afficher_ets(Ets e,char* filename);
Ets chercher_ets(char* filename,int id);

#endif
