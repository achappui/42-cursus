import subprocess
import random
import statistics

# --- Paramètres ---
EXEC_PATH = "./PmergeMe"  # chemin vers ton exécutable
RUNS = 100  # nombre de tests
MIN_SIZE = 3000
MAX_SIZE = 3000
RANGE_MIN = 0
RANGE_MAX = 100000

results = []
bad_sorts = 0

for _ in range(RUNS):
    # Choisit une taille aléatoire pour ce test
    N = random.randint(MIN_SIZE, MAX_SIZE)

    # Vérifie que la plage est suffisante pour N éléments uniques
    if N > RANGE_MAX - RANGE_MIN + 1:
        raise ValueError(
            f"La plage ({RANGE_MIN}-{RANGE_MAX}) est trop petite pour {N} éléments uniques"
        )

    # Génère N nombres uniques dans la plage
    numbers = random.sample(range(RANGE_MIN, RANGE_MAX + 1), N)

    # Exécute le programme
    proc = subprocess.run(
        [EXEC_PATH] + list(map(str, numbers)), capture_output=True, text=True
    )

    out_lines = proc.stdout.strip().splitlines()

    # Récupère toutes les lignes sauf la dernière (qui doit être "Comp: X")
    sorted_lines = out_lines[:-1]
    comp_line = out_lines[-1]

    # Vérifie si la sortie est bien triée et contient tous les éléments attendus
    try:
        sorted_numbers = list(map(int, sorted_lines))
        is_sorted = sorted_numbers == sorted(sorted_numbers) and set(
            sorted_numbers
        ) == set(numbers)
    except ValueError:
        is_sorted = False

    # Récupère le compteur
    comp = comp_line.split(":")[1].strip() if comp_line.startswith("Comp:") else "N/A"

    # Affiche tout sur une seule ligne
    print(
        f"input (N={N}): {numbers[:10]}{'...' if N > 10 else ''} | output: {sorted_numbers[:10]}{'...' if N > 10 else ''} | comp: {comp} | tri: {'YES' if is_sorted else 'NO'}"
    )

    if is_sorted and comp != "N/A":
        results.append(int(comp))
    else:
        bad_sorts += 1

# --- Analyse ---
if results:
    worst = max(results)
    best = min(results)
    avg = statistics.mean(results)

    print(f"\n--- Résultats sur {RUNS} exécutions ---")
    print(f"Best case :  {best} comparaisons")
    print(f"Worst case : {worst} comparaisons")
    print(f"Average :    {avg:.2f} comparaisons")
    print(f"Tri incorrect détecté : {bad_sorts} cas")
else:
    print("Erreur : aucune valeur 'Comp:' trouvée dans les sorties.")
