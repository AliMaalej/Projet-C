#include "ets.h"

int ajouter_ets(Ets e,char* filename)
{
    FILE * f=fopen(filename, "a");
    if(f!=NULL)
    {
        fprintf(f,"%d %d %d %d %s %s\n", e.id, e.region, e.tel, e.capacite, e.nationalite, e.adresse);
        fclose(f);
        return 1;
    }
    else return 0;
}

int modifier_ets(int id,Ets e,char* filename)
{
    int etat=0;
    Ets etab;
    FILE * en=fopen(filename, "r");
    FILE * s=fopen("new.txt", "w");
    if(en!=NULL && s!=NULL)
    {
        while(fscanf(en,"%d %d %d %d %s %s\n", &etab.id, &etab.region, &etab.tel, &etab.capacite, etab.nationalite, etab.adresse)!=EOF)
        {
            if(etab.id == id)
            {
                fprintf(s,"%d %d %d %d %s %s\n", e.id, e.region, e.tel, e.capacite, e.nationalite, e.adresse);
                etat=1;
            }
            else
                fprintf(s,"%d %d %d %d %s %s\n", etab.id, etab.region, etab.tel, etab.capacite, etab.nationalite, etab.adresse);

        }
    }
    fclose(en);
    fclose(s);
    remove(filename);
    rename("new.txt", filename);
    return etat;
}


int supprimer_ets(int id,char* filename)
{
    int etat=0;
    Ets etab;
    FILE * e=fopen(filename, "r");
    FILE * s=fopen("new.txt", "w");
    if(e!=NULL && s!=NULL)
    {
        while(fscanf(e,"%d %d %d %d %s %s\n", &etab.id, &etab.region, &etab.tel, &etab.capacite, etab.nationalite, etab.adresse)!=EOF)
        {
            if(etab.id == id)
                etat=1;
            else
                fprintf(s,"%d %d %d %d %s %s\n", etab.id, etab.region, etab.tel, etab.capacite, etab.nationalite, etab.adresse);
        }
    }
    fclose(e);
    fclose(s);
    remove(filename);
    rename("new.txt", filename);
    return etat;
}



Ets chercher_ets(char* filename,int id)
{
    int etat=0;
    Ets etab;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(etat==0 && fscanf(f,"%d %d %d %d %s %s\n", &etab.id, &etab.region, &etab.tel, &etab.capacite, etab.nationalite, etab.adresse)!=EOF)
        {
            if(etab.id == id)
                etat=1;
        }
    }
    fclose(f);
    if(etat==0)
        etab.id=-1;
    return etab;

}



