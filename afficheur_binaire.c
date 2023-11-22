#include <stdio.h>

// Fonction pour afficher la représentation binaire d'un entier signé
void afficherBinaire(int nombre) {
    int i;
    int taille = sizeof(int) * 8; // Taille en bits de l'entier signé

    // Parcours de chaque bit de l'entier et affichage
    for (i = taille - 1; i >= 0; i--) {
        // Utilisation de l'opérateur de décalage pour accéder à chaque bit
        if ((nombre >> i) & 1) {
            printf("1");
        } else {
            printf("0");
        }

        // Ajout d'un espace pour améliorer la lisibilité
        if (i % 4 == 0) {
            printf(" ");
        }
    }

    printf("\n");
}

int main() {
    int entier;

    // Demande à l'utilisateur de saisir un entier
    printf("Veuillez entrer un entier : ");
    scanf("%d", &entier);

    // Appel de la fonction pour afficher la représentation binaire
    printf("Représentation binaire de %d : ", entier);
    afficherBinaire(entier);

    return 0;
}
