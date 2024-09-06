import matplotlib.pyplot as plt
import numpy as np

def plot_triangle(ax, points, color, label):
    triangle = plt.Polygon(points, edgecolor=color, fill=None, linewidth=2, label=label)
    ax.add_patch(triangle)

def plot_point(ax, point, color, label):
    ax.plot(point[0], point[1], 'o', color=color, label=label)

def main():
    # Définition des points pour les triangles
    a, b, c = (0, 0), (5, 0), (0, 5)
    e, f, g = (-2, 6), (-2, 2), (4, 2)
    h, i, j = (4, 4), (7, 4), (4, 7)
    p = (2, 2)  # Point à tester

    # Création de la figure et des axes
    fig, ax = plt.subplots()
    
    # Définition des limites
    ax.set_xlim(-2, 8)
    ax.set_ylim(-2, 8)
    
    # Ajout de la grille
    ax.grid(True)
    ax.set_aspect('equal')

    # Tracer les triangles
    plot_triangle(ax, [a, b, c, a], 'blue', 'Triangle ABC (p inside)')
    plot_triangle(ax, [e, f, g, e], 'green', 'Triangle EFG (p not on border)')
    plot_triangle(ax, [h, i, j, h], 'red', 'Triangle HIJ (p outside)')
    
    # Tracer le point
    plot_point(ax, p, 'black', 'Point P')

    # Légende
    ax.legend()
    
    # Afficher le graphique
    plt.xlabel('X axis')
    plt.ylabel('Y axis')
    plt.title('Triangles and Point')
    plt.show()

if __name__ == "__main__":
    main()
