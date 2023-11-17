#include "Don.h"
#include <stdio.h>
#include <string.h>

int AjouterDon(char *fichier, Don don) {
    FILE *f = fopen(fichier, "a"); //Ajouter a la fin du fichier
    if (f == NULL) {
        printf("Erreur d'ouverture du fichier pour l'ajout\n");
        return 0;
    }
    fprintf(f, "%d %s %s %s %d\n", don.id, don.prenom, don.nom, don.gs, don.quantite);
    fclose(f);
    return 1;
}

int ModifierDon(char *fichier, int id, Don don) {
    FILE *f = fopen(fichier, "r"); //read
    if (f == NULL) { printf("Erreur d'ouverture du fichier pour la fonction modifier\n"); return 0; }
    FILE *tempF = fopen("temp.txt", "w"); //write ( reecriture totale)
    if (tempF == NULL) { printf("Erreur d'ouverture du fichier temporaire pour la fonction modifier\n"); fclose(f); return 0; }
    int trouve = 0;
    Don tmpDon; 
    while (fscanf(f, "%d %s %s %s %d", &tmpDon.id, tmpDon.prenom, tmpDon.nom, tmpDon.gs, &tmpDon.quantite) == 5) {
        if (tmpDon.id == id) {
            fprintf(tempF, "%d %s %s %s %d\n", don.id, don.prenom, don.nom, don.gs, don.quantite);
            trouve = 1;
        } else {
            fprintf(tempF, "%d %s %s %s %d\n", tmpDon.id, tmpDon.prenom, tmpDon.nom, tmpDon.gs, tmpDon.quantite);
        }
    }
    fclose(f); fclose(tempF);
    if (!trouve) { printf("Don avec l'ID %d non trouve pour la modification\n", id); remove("temp.txt"); return 0; }
    remove(fichier); rename("temp.txt", fichier);
    return 1;
}

int SupprimerDon(char *fichier, int id) {
    FILE *f = fopen(fichier, "r");
    if (f == NULL) { printf("Erreur d'ouverture du fichier pour la suppression\n"); return 0; }
    FILE *tempF = fopen("temp.txt", "w");
    if (tempF == NULL) { printf("Erreur d'ouverture du fichier temporaire pour la suppression\n"); fclose(f); return 0; }
    int trouve = 0;
    Don tmpDon;
    while (fscanf(f, "%d %s %s %s %d", &tmpDon.id, tmpDon.prenom, tmpDon.nom, tmpDon.gs, &tmpDon.quantite) == 5) {
        if (tmpDon.id == id) { trouve = 1; }
        else { fprintf(tempF, "%d %s %s %s %d\n", tmpDon.id, tmpDon.prenom, tmpDon.nom, tmpDon.gs, tmpDon.quantite); }
    }
    fclose(f); fclose(tempF);
    if (!trouve) { printf("Don avec l'ID %d non trouve pour la suppression\n", id); remove("temp.txt"); return 0; }
    remove(fichier); rename("temp.txt", fichier);
    return 1;
}

Don ChercherDon(char *fichier, int id) {
    FILE *f = fopen(fichier, "r");
    Don don; don.id = -1;
    if (f == NULL) { printf("Erreur d'ouverture du fichier pour la recherche\n"); return don; }
    while (fscanf(f, "%d %s %s %s %d", &don.id, don.prenom, don.nom, don.gs, &don.quantite) == 5) {
        if (don.id == id) { fclose(f); return don; }
    }
    fclose(f); return don;
}

void AfficherDon(char *fichier) {
    FILE *f = fopen(fichier, "r");
    if (f == NULL) {
        printf("Erreur d'ouverture du fichier pour l'affichage\n");
        return;
    }
    Don don;
    int readResult;
    while ((readResult = fscanf(f, "%d %19s %19s %3s %d", &don.id, don.prenom, don.nom, don.gs, &don.quantite)) == 5) {
        printf("ID: %d, Prenom: %s, Nom: %s, Groupe Sanguin: %s, Quantite: %d\n", don.id, don.prenom, don.nom, don.gs, don.quantite);
    }
    if (readResult != EOF) {
        printf("Erreur de lecture du fichier\n");
    }
    fclose(f);
    return;
}

// Fonction pour calculer la quantité disponible par type de sang
int quantite_type(char nomFichier[], char type_sang[]) {
    FILE *f = fopen(nomFichier, "r");//lecture
    if (f == NULL) {
        perror("Erreur d'ouverture du fichier pour la lecture");
        return -1; // Indiquer une erreur
    }

    int quantiteTotale = 0;
    Don don;

    while (fscanf(f, "%d %s %s %s %d", &don.id, don.prenom, don.nom, don.gs, &don.quantite) == 5) {
        // Vérifier si le type de sang correspond
        if (strcmp(don.gs, type_sang) == 0) {
            quantiteTotale += don.quantite;
        }
    }

    fclose(f);
    return quantiteTotale;
}

// Fonction pour rechercher le type de sang le plus rare
void sang_rare(char nomFichier[], char sangRare[]) {
    char *types_sang[] = {"A+", "A-", "B+", "B-", "AB+", "AB-", "O+", "O-"};
    
    int quantite_min = -1; // Initialisation avec une valeur non valide
    int quantite;
    
    for (int i = 0; i < sizeof(types_sang) / sizeof(types_sang[0]); ++i) {
        quantite = quantite_type(nomFichier, types_sang[i]);

        if (quantite >= 0 && (quantite_min == -1 || quantite < quantite_min)) {
            quantite_min = quantite;
            strcpy(sangRare, types_sang[i]);
        }
    }
}


