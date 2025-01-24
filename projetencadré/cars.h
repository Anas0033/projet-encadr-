// cars.h
#ifndef CARS_H
#define CARS_H

#define MAX_CARS 100
#define FILENAME "cars.csv"

typedef struct {
    int id;
    char marque[50];
    char utilisateur[50];
    char modele[50];
    char carburant[20];
    int places;
    char transmission[15];
    float prix;
    int disponible;
} Voiture;

void afficherMenu();
void ajouterVoiture();
void afficherVoitures();
void rechercherVoiture();
void trierVoitures();

#endif
