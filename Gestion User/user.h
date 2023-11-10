#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    int cin;
    char nom [30];
    char prenom [30];
    char role[30];
    char sexe [10];
    char ets [50];

} user;
int ajouter(char *, user );
int modifier( char *,int , user );
int supprimer(char *, int );
user chercher(char *, int);

#endif // USER_H_INCLUDED
