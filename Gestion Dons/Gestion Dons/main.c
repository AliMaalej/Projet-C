#include "Don.h"
#include <stdio.h>
#include <string.h>

int main() {
    int choix;
    char sangRare[4];
    char type_Sang[4];

    do {
        printf("\nMenu :\n");
        printf("1. Ajouter un don\n");
        printf("2. Modifier un don\n");
        printf("3. Supprimer un don\n");
        printf("4. Afficher les dons\n");
        printf("5. Afficher la quantite par type de sang\n");
        printf("6. Afficher le type de sang le plus rare\n");
        printf("0. Quitter\n");
        printf("Choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1: // Ajouter un don
                printf("Entrez les details du don :\n");
                Don nouveauDon;
                printf("ID : ");
                scanf("%d", &nouveauDon.id);
                printf("Prenom : ");
                scanf("%s", nouveauDon.prenom);
                printf("Nom : ");
                scanf("%s", nouveauDon.nom);
                printf("Groupe Sanguin : ");
                scanf("%s", nouveauDon.gs);
                printf("Quantite : ");
                scanf("%d", &nouveauDon.quantite);
                AjouterDon("dons.txt", nouveauDon);
                break;

            case 2: // Modifier un don
                printf("Entrez l'ID du don à modifier : ");
                int idAModifier;
                scanf("%d", &idAModifier);
                Don donAModifier = ChercherDon("dons.txt", idAModifier);
                if (donAModifier.id != -1) {
                    printf("Entrez les nouveaux details du don :\n");
                    printf("ID : ");
                    scanf("%d", &donAModifier.id);
                    printf("Prenom : ");
                    scanf("%s", donAModifier.prenom);
                    printf("Nom : ");
                    scanf("%s", donAModifier.nom);
                    printf("Groupe Sanguin : ");
                    scanf("%s", donAModifier.gs);
                    printf("Quantite : ");
                    scanf("%d", &donAModifier.quantite);
                    ModifierDon("dons.txt", idAModifier, donAModifier);
                } else {
                    printf("Don non trouve avec l'ID %d\n", idAModifier);
                }
                break;

            case 3: // Supprimer un don
                printf("Entrez l'ID du don à supprimer : ");
                int idASupprimer;
                scanf("%d", &idASupprimer);
                SupprimerDon("dons.txt", idASupprimer);
                break;

            case 4: // Afficher les dons
                printf("Liste des dons :\n");
                AfficherDon("dons.txt");
                break;

            case 5: // Afficher la quantité par type de sang
        	printf("Entrez le type de sang (A, B, AB, O) : ");
        	scanf("%s", type_Sang);
        	int quantite = quantite_type("dons.txt", type_Sang);
        	if (quantite != -1) {
           	 printf("Quantite totale pour le type de sang %s : %d\n", type_Sang, quantite);
        	} else {
            	printf("Erreur lors du calcul de la quantite par type de sang.\n");
        	}
    		break;


            case 6: // Afficher le type de sang le plus rare
                sang_rare("dons.txt", sangRare);
                printf("Le type de sang le plus rare est : %s\n", sangRare);
                break;

            case 0: // Quitter
                printf("Au revoir!\n");
                break;

            default:
                printf("Choix invalide. Veuillez entrer un nombre entre 0 et 6.\n");
        }
    } while (choix != 0);

    return 0;
}



