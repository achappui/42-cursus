import subprocess
import random

# Chemin vers le fichier exécutable
executable_path = "./push_swap"

# Nombre d'itérations
num_iterations = 1000

# Nombre d'éléments dans la liste
num_elements = 5

# Liste pour stocker tous les nombres d'instructions à chaque itération
all_instruction_counts = []

for _ in range(num_iterations):
    # Générer une liste de 100 entiers uniques (par exemple, de 1 à 100)
    input_list = random.sample(range(1, num_elements + 1), num_elements)
    
    # Convertir la liste en une chaîne d'arguments séparée par des espaces
    input_arguments = " ".join(map(str, input_list))
    
    # Appeler le programme push_swap avec les arguments générés
    result = subprocess.run([executable_path, input_arguments], capture_output=True, text=True)
    
    # Vérifier si le processus s'est terminé correctement (code de retour 0)
    if result.returncode == 0:
        # Ajouter le nombre d'instructions à la liste globale
        all_instruction_counts.append(int(result.stdout.strip()))
    else:
        print(f"Erreur lors de l'appel {len(all_instruction_counts) + 1}")

# Vérifier si la liste d'instructions n'est pas vide
if all_instruction_counts:
    # Afficher tous les nombres d'instructions générés
    print("Nombres d'instructions générés :")
    for i, count in enumerate(all_instruction_counts, start=1):
        print(f"Appel {i}: {count} instructions")

    # Trouver le plus petit et le plus grand nombre d'instructions
    min_instructions = min(all_instruction_counts)
    max_instructions = max(all_instruction_counts)
    print(f"\nLe plus petit nombre d'instructions nécessaire : {min_instructions}")
    print(f"Le plus grand nombre d'instructions nécessaire : {max_instructions}")
else:
    print("Aucune instruction n'a été renvoyée lors des appels.")
