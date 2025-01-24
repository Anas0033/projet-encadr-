// main.c
#include <stdio.h>
#include "cars.h"

int main() {
    int choix;
    do {
        afficherMenu();
        printf("\nEntrez votre choix : ");
        scanf("%d", &choix);
        getchar(); // Consommer le retour à la ligne

        switch (choix) {
            case 1:
                ajouterVoiture();
                break;
            case 2:
                afficherVoitures();
                break;
            case 3:
                rechercherVoiture();
                break;
            case 4:
                trierVoitures();
                break;
            case 0:
                printf("\nMerci d'utiliser notre application.\n");
                break;
            default:
                printf("\nChoix invalide, veuillez réessayer.\n");
        }
    } while (choix != 0);

    return 0;
}


