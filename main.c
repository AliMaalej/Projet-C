#include <stdio.h>
#include <string.h>
#include "ets.h"

int main()
{
    Ets e1= {1,1,658,32,"National","Technopole_Ghazela"},e2= {2,2,711,64,"International","France,Paris"},e3;
    int test=ajouter_ets( e1, "ets.txt");

    if(test==1)
        printf("\najout d'etablissement avec succés");
    else printf("\nechec ajout");

    test=modifier_ets( 1, e2, "ets.txt");

    if(test==1)
        printf("\nModification d'etablissement avec succés");
    else printf("\nechec Modification");

    test=supprimer_ets( 2, "ets.txt");

    if(test==1)
        printf("\nSuppression d'etablissement avec succés");
    else printf("\nechec Suppression");

    e3=chercher_ets("ets.txt", 3);

    if(e3.id==-1)
        printf("\nintrouvable\n");

    return 0;
}
