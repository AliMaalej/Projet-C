#include"donneur.h"
#include <stdio.h>
int ajout_donneur(donneur d, char *filename)
{
    FILE * f=fopen(filename,"a");
    if (f!= NULL)
    {
        fprintf(f, "%d %s %s %d %d %d %d %s %s %d %s %s \n", d.id_donneur, d.nom_donneur, d.prenom_donneur, d.cin_donneur, d.DN_jour_donneur, d.DN_mois_donneur, d.DN_annee_donneur, d.sexe_donneur, d.hebergement_donneur, d.numero_donneur, d.mail_donneur, d.maladie_chronique_donneur);
        fclose(f);
        return 1;
    }
         else
            {
               return 0;
            }
}


int supprimer_donneur(int id_donneur,char* filename)
{
    int tr=0;
    donneur d;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %s %s %d %d %d %d %s %s %d %s %s\n",&d.id_donneur, d.nom_donneur, d.prenom_donneur, &d.cin_donneur, &d.DN_jour_donneur, &d.DN_mois_donneur, &d.DN_annee_donneur, d.sexe_donneur, d.hebergement_donneur, &d.numero_donneur, d.mail_donneur, d.maladie_chronique_donneur)!=EOF)
        {
            if(d.id_donneur== id_donneur)
                tr=1;
            else
                fprintf(f2,"%d %s %s %d %d %d %d %s %s %d %s %s \n", d.id_donneur, d.nom_donneur, d.prenom_donneur, d.cin_donneur, d.DN_jour_donneur, d.DN_mois_donneur, d.DN_annee_donneur, d.sexe_donneur, d.hebergement_donneur, d.numero_donneur, d.mail_donneur, d.maladie_chronique_donneur);
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;
}
//////////////////////////////////////////////////////////////////////////////
int modifier_donneur(int id_donneur, donneur nouv,char* filename)
{
    int tr=0;
    donneur d;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %s %s %d %d %d %d %s %s %d %s %s\n",&d.id_donneur, d.nom_donneur, d.prenom_donneur, &d.cin_donneur, &d.DN_jour_donneur, &d.DN_mois_donneur, &d.DN_annee_donneur, d.sexe_donneur, d.hebergement_donneur, &d.numero_donneur, d.mail_donneur, d.maladie_chronique_donneur)!=EOF)
        {
            if(d.id_donneur== id_donneur)
            {
                fprintf(f2,"%d %s %s %d %d %d %d %s %s %d %s %s\n",nouv.id_donneur, nouv.nom_donneur, nouv.prenom_donneur, nouv.cin_donneur, nouv.DN_jour_donneur, nouv.DN_mois_donneur, nouv.DN_annee_donneur, nouv.sexe_donneur, nouv.hebergement_donneur, nouv.numero_donneur, nouv.mail_donneur, nouv.maladie_chronique_donneur);
                tr=1;
            }
            else
                fprintf(f2,"%d %s %s %d %d %d %d %s %s %d %s %s\n",d.id_donneur, d.nom_donneur, d.prenom_donneur, d.cin_donneur, d.DN_jour_donneur, d.DN_mois_donneur, d.DN_annee_donneur, d.sexe_donneur, d.hebergement_donneur, d.numero_donneur, d.mail_donneur, d.maladie_chronique_donneur);

        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;

}
/////////////////////////////////////////////////////////////////////////////////////

donneur chercher_donneur(int id_donneur ,char *filename )
{
    donneur d;
    int tr=0;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(tr==0&& fscanf(f,"%d %s %s %d %d %d %d %s %s %d %s %s\n",&d.id_donneur, d.nom_donneur, d.prenom_donneur, &d.cin_donneur, &d.DN_jour_donneur, &d.DN_mois_donneur, &d.DN_annee_donneur, d.sexe_donneur, d.hebergement_donneur, &d.numero_donneur, d.mail_donneur, d.maladie_chronique_donneur)!=EOF)
        {
            if(d.id_donneur== id_donneur)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
        d.id_donneur=-1;
    return d;

}
