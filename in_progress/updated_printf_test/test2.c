#include <stdio.h>
#include <stdint.h>

void afficherBits4Octets(const void *ptr) {
    // Utilisation d'un pointeur de type uint8_t pour accéder aux octets
    const uint8_t *octets = (const uint8_t *)ptr;

    // Boucle à travers les octets
    for (int i = 0; i < 4; i++) {
        // Utilisation de l'opérateur "&" pour afficher chaque bit
        for (int j = 7; j >= 0; j--) {
            printf("%d", (octets[i] >> j) & 1);
        }
        printf(" "); // Ajouter un espace pour améliorer la lisibilité
    }

    printf("\n");
}

void afficherBits4OctetsInverse(const void *ptr) {
    // Utilisation d'un pointeur de type uint8_t pour accéder aux octets
    const uint8_t *octets = (const uint8_t *)ptr;

    // Boucle à travers les octets (dans l'ordre inverse)
    for (int i = 3; i >= 0; i--) {
        // Utilisation de l'opérateur "&" pour afficher chaque bit
        for (int j = 7; j >= 0; j--) {
            printf("%d", (octets[i] >> j) & 1);
        }
        printf(" "); // Ajouter un espace pour améliorer la lisibilité
    }

    printf("\n");
}


int main() {
    // unsigned long long valeur = 1844674407370955161ULL;
    // afficherBitsFloat(valeur);
	//printf("%b\n", (0b10000010 afficherBits4Octets- 0b01111111));
	float	test;

	// test = 1.0;
	// printf("%.1f\n", test);
	// afficherBits4OctetsInverse(&test);
	// test = 2.0;
	// printf("%.1f\n", test);
	// afficherBits4OctetsInverse(&test);

	test = 12356.45;
	printf("%.20f\n", test);
	afficherBits4OctetsInverse(&test);

	printf("%d\n", 0b00000000000010110011001100110011);
	// test = 123.456;
	// printf("%.20f\n", test);
	// afficherBits4OctetsInverse(&test);
	// test = 123.999;
	// printf("%.20f\n", test);
	// afficherBits4OctetsInverse(&test);

    return 0;
}
