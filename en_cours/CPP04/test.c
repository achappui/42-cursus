#include <stdio.h>

// Codes de couleurs ANSI
#define RESET   "\033[0m"       // Réinitialiser les attributs de couleur
#define BOLD    "\033[1m"       // Texte en gras
#define UNDERLINE "\033[4m"     // Texte souligné

// Couleurs de texte basiques
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

// Couleurs de texte étendues (ANSI 256 couleurs)
#define TURQUOISE   "\033[38;5;51m"   // Turquoise
#define DARK_TURQUOISE "\033[38;5;30m" // Turquoise foncé
#define SALMON      "\033[38;5;210m"  // Saumon
#define DARK_SALMON  "\033[38;5;130m" // Saumon foncé
#define OLIVE       "\033[38;5;58m"   // Olive
#define DARK_OLIVE  "\033[38;5;22m"   // Olive foncé
#define TEAL        "\033[38;5;36m"   // Teal
#define DARK_TEAL   "\033[38;5;18m"   // Teal foncé
#define CORAL       "\033[38;5;209m"  // Coral
#define DARK_CORAL  "\033[38;5;166m"  // Coral foncé
#define IVORY       "\033[38;5;255m"  // Ivoire
#define DARK_IVORY  "\033[38;5;250m"  // Ivoire foncé
#define INDIGO      "\033[38;5;54m"   // Indigo
#define DARK_INDIGO "\033[38;5;18m"   // Indigo foncé
#define PEACH       "\033[38;5;216m"  // Peach
#define DARK_PEACH  "\033[38;5;214m"  // Peach foncé
#define MINT        "\033[38;5;152m"  // Mint
#define DARK_MINT   "\033[38;5;82m"   // Mint foncé
#define PLUM        "\033[38;5;99m"   // Plum
#define DARK_PLUM   "\033[38;5;55m"   // Plum foncé

int main() {
    // Affichage avec les couleurs de texte basiques
    printf(BLACK   "Black\n"   RESET);
    printf(RED     "Red\n"     RESET);
    printf(GREEN   "Green\n"   RESET);
    printf(YELLOW  "Yellow\n"  RESET);
    printf(BLUE    "Blue\n"    RESET);
    printf(MAGENTA "Magenta\n" RESET);
    printf(CYAN    "Cyan\n"    RESET);
    printf(WHITE   "White\n"   RESET);

    // Affichage avec les couleurs de texte étendues (ANSI 256 couleurs)
    printf(TURQUOISE   "Turquoise\n"   RESET);
    printf(DARK_TURQUOISE "Dark Turquoise\n" RESET);
    printf(SALMON      "Salmon\n"      RESET);
    printf(DARK_SALMON  "Dark Salmon\n" RESET);
    printf(OLIVE       "Olive\n"       RESET);
    printf(DARK_OLIVE  "Dark Olive\n"  RESET);
    printf(TEAL        "Teal\n"        RESET);
    printf(DARK_TEAL   "Dark Teal\n"   RESET);
    printf(CORAL       "Coral\n"       RESET);
    printf(DARK_CORAL  "Dark Coral\n"  RESET);
    printf(IVORY       "Ivory\n"       RESET);
    printf(DARK_IVORY  "Dark Ivory\n"  RESET);
    printf(INDIGO      "Indigo\n"      RESET);
    printf(DARK_INDIGO "Dark Indigo\n" RESET);
    printf(PEACH       "Peach\n"       RESET);
    printf(DARK_PEACH  "Dark Peach\n"  RESET);
    printf(MINT        "Mint\n"        RESET);
    printf(DARK_MINT   "Dark Mint\n"   RESET);
    printf(PLUM        "Plum\n"        RESET);
    printf(DARK_PLUM   "Dark Plum\n"   RESET);

    return 0;
}
