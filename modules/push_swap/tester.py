import subprocess
import random

# Définir le chemin vers votre programme push_swap
push_swap_path = "./push_swap"

# Définir le nombre d'itérations
num_iterations = 1000

# Définir les bornes min et max pour les entiers aléatoires
min_int = -2147483648  # Remplacez par la valeur minimale souhaitée
max_int = 2147483647   # Remplacez par la valeur maximale souhaitée

def generate_random_unique_list(size, min_val, max_val):
    # Générer une liste d'entiers aléatoires uniques
    random_list = random.sample(range(min_val, max_val + 1), size)
    return random_list

def run_push_swap_and_check(sorted_list):
    # Convertir la liste en une chaîne d'entiers séparés par des espaces
    input_str = ' '.join(map(str, sorted_list))

    # Exécuter le programme push_swap avec la liste générée en entrée
    result = subprocess.run([push_swap_path, input_str], stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)

    # Vérifier si le programme a affiché quelque chose sur la sortie standard
    return "OK" if result.stdout.strip() == "" else "KO"

def main():
    non_sorted_count = 0

    for _ in range(num_iterations):
        # Générer une liste aléatoire unique de 5 entiers
        random_list = generate_random_unique_list(5, min_int, max_int)

        # Exécuter le programme push_swap et vérifier le résultat
        result = run_push_swap_and_check(random_list)

        # Afficher la liste et le résultat de l'itération
        print(f"Liste: {random_list}, Résultat: {result}")

        # Compter le nombre de fois où le résultat est "KO"
        if result == "KO":
            non_sorted_count += 1

    # Afficher le récapitulatif final
    print("\nRécapitulatif final:")
    if non_sorted_count > 0:
        print(f"Il y a {non_sorted_count} listes qui ne sont pas triées.")
    else:
        print("Toutes les listes sont triées (OK).")

if __name__ == "__main__":
    main()
