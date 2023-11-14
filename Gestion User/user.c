#include "user.h"
#include <stdio.h>

int ajouter(char *filename, user u)
{
    FILE *f = fopen(filename, "a");
    if (f != NULL)
    {
        fprintf(f, "%d %d %s %s %s %s %s\n", u.id, u.cin, u.nom, u.prenom, u.role, u.sexe, u.ets);
        fclose(f);
        return 1;
    }
    else
        return 0;
}

int modifier(char *filename, int id, user nouv)
{
    int tr = 0;
    user u;
    FILE *f = fopen(filename, "r");
    FILE *f2 = fopen("nouv.txt", "w");
    if (f != NULL && f2 != NULL)
    {
        while (fscanf(f, "%d %d %s %s %s %s %s\n", &u.id, &u.cin, u.nom, u.prenom, u.role, u.sexe, u.ets) != EOF)
        {
            if (u.id == id)
            {
                fprintf(f2, "%d %d %s %s %s %s %s\n", nouv.id, nouv.cin, nouv.nom, nouv.prenom, nouv.role, nouv.sexe, nouv.ets);
                tr = 1;
            }
            else
                fprintf(f2, "%d %d %s %s %s %s %s\n", u.id, u.cin, u.nom, u.prenom, u.role, u.sexe, u.ets);
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;
}

int supprimer(char *filename, int id)
{
    int tr = 0;
    user u;
    FILE *f = fopen(filename, "r");
    FILE *f2 = fopen("nouv.txt", "w");
    if (f != NULL && f2 != NULL)
    {
        while (fscanf(f, "%d %d %s %s %s %s %s\n", &u.id, &u.cin, u.nom, u.prenom, u.role, u.sexe, u.ets) != EOF)
        {
            if (u.id == id)
                tr = 1;
            else
                fprintf(f2, "%d %d %s %s %s %s %s\n", u.id, u.cin, u.nom, u.prenom, u.role, u.sexe, u.ets);
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;
}

user chercher(char *filename, int id)
{
    user u;
    int tr = 0;
    FILE *f = fopen(filename, "r");
    if (f != NULL)
    {
        while (tr == 0 && fscanf(f, "%d %d %s %s %s %s %s\n", &u.id, &u.cin, u.nom, u.prenom, u.role, u.sexe, u.ets) != EOF)
        {
            if (u.id == id)
                tr = 1;
        }
    }
    fclose(f);
    if (tr == 0)
        u.id = -1;
    return u;
}
