// cars.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cars.h"

void afficherMenu() {
    printf("\n--- Menu Gestion de Location de Voitures ---\n");
    printf("1. Ajouter une voiture\n");
    printf("2. Afficher la liste des voitures disponibles\n");
    printf("3. Rechercher une voiture\n");
    printf("4. Trier les voitures\n");
    printf("0. Quitter\n");
}

void ajouterVoiture() {
    FILE *file = fopen(FILENAME, "a");
    if (!file) {
        printf("Erreur d'ouverture du fichier !\n");
        return;
    }

    Voiture v;
    printf("Entrez l'ID de la voiture : ");
    scanf("%d", &v.id);
    getchar();
    printf("Marque : ");
    fgets(v.marque, 50, stdin);
    strtok(v.marque, "\n");
    printf("Nom d'utilisateur : ");
    fgets(v.utilisateur, 50, stdin);
    strtok(v.utilisateur, "\n");
    printf("Modèle : ");
    fgets(v.modele, 50, stdin);
    strtok(v.modele, "\n");
    printf("Carburant : ");
    fgets(v.carburant, 20, stdin);
    strtok(v.carburant, "\n");
    printf("Nombre de places : ");
    scanf("%d", &v.places);
    getchar();
    printf("Transmission (Automatique/Manuelle) : ");
    fgets(v.transmission, 15, stdin);
    strtok(v.transmission, "\n");
    printf("Prix de location par jour : ");
    scanf("%f", &v.prix);
    printf("Disponible (1: Oui, 0: Non) : ");
    scanf("%d", &v.disponible);

    fprintf(file, "%d,%s,%s,%s,%s,%d,%s,%.2f,%d\n", v.id, v.marque, v.utilisateur, v.modele, v.carburant, v.places, v.transmission, v.prix, v.disponible);
    fclose(file);
    printf("Voiture ajoutée avec succès !\n");
}

void afficherVoitures() {
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        printf("Aucune voiture enregistrée.\n");
        return;
    }
    Voiture v;
    printf("\nListe des voitures disponibles :\n");
    printf("ID | Marque | Utilisateur | Modèle | Carburant | Places | Transmission | Prix | Disponible\n");
    while (fscanf(file, "%d,%49[^,],%49[^,],%49[^,],%19[^,],%d,%14[^,],%f,%d\n", &v.id, v.marque, v.utilisateur, v.modele, v.carburant, &v.places, v.transmission, &v.prix, &v.disponible) != EOF) {
        printf("%d | %s | %s | %s | %s | %d | %s | %.2f | %s\n", v.id, v.marque, v.utilisateur, v.modele, v.carburant, v.places, v.transmission, v.prix, v.disponible ? "Oui" : "Non");
    }
    fclose(file);
}

void rechercherVoiture() {
    char marque[50];
    printf("Entrez la marque de la voiture à rechercher : ");
    fgets(marque, 50, stdin);
    strtok(marque, "\n");

    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        printf("Aucune voiture enregistrée.\n");
        return;
    }
    Voiture v;
    printf("\nRésultats de recherche :\n");
    while (fscanf(file, "%d,%49[^,],%49[^,],%49[^,],%19[^,],%d,%14[^,],%f,%d\n", &v.id, v.marque, v.utilisateur, v.modele, v.carburant, &v.places, v.transmission, &v.prix, &v.disponible) != EOF) {
        if (strcmp(v.marque, marque) == 0) {
            printf("%d | %s | %s | %s | %s | %d | %s | %.2f | %s\n", v.id, v.marque, v.utilisateur, v.modele, v.carburant, v.places, v.transmission, v.prix, v.disponible ? "Oui" : "Non");
        }
    }
    fclose(file);
}

void trierVoitures() {
    printf("Fonction de tri à implémenter\n");
}

