#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "user.h"

int main() {
    user u;

    // Get user input to populate the user structure
    printf("Enter user ID: ");
    scanf("%d", &u.id);

    printf("Enter user CIN: ");
    scanf("%d", &u.cin);

    printf("Enter user name: ");
    scanf("%s", u.nom);

    printf("Enter user surname: ");
    scanf("%s", u.prenom);

    printf("Enter user role: ");
    scanf("%s", u.role);

    printf("Enter user gender: ");
    scanf("%s", u.sexe);

    printf("Enter user organization: ");
    scanf("%s", u.ets);

    // Call the ajouter function to add the user to the file
    int result = ajouter("user.txt", u);

    if (result == 1)
        printf("\nUser added successfully\n");
    else
        printf("\nFailed to add user\n");

    return 0;
}
