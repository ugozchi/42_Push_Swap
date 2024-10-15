![Push_swap_logo](.media/push_swap_logo.png)

![Grade badge](https://img.shields.io/badge/100_%2F_100-004d40?label=final%20grade&labelColor=151515&logo=data:image/svg%2bxml;base64,PHN2ZyB4bWxucz0iaHR0cDovL3d3dy53My5vcmcvMjAwMC9zdmciIGhlaWdodD0iMjRweCIgdmlld0JveD0iMCAwIDI0IDI0IiB3aWR0aD0iMjRweCIgZmlsbD0iI0ZGRkZGRiI+PHBhdGggZD0iTTAgMGgyNHYyNEgweiIgZmlsbD0ibm9uZSIvPjxwYXRoIGQ9Ik0xMiAxNy4yN0wxOC4xOCAyMWwtMS42NC03LjAzTDIyIDkuMjRsLTcuMTktLjYxTDEyIDIgOS4xOSA4LjYzIDIgOS4yNGw1LjQ2IDQuNzNMNS44MiAyMXoiLz48L3N2Zz4=) ![Language Badge](https://img.shields.io/badge/C-fe428e?logo=C&label=language&labelColor=151515) ![Norminette Badge](https://img.shields.io/badge/passing-brightgreen?logo=42&label=norminette&labelColor=151515)

# Push_swap ↪️

Ce projet consiste à trier une pile A par ordre croissant avec deux piles avec un nombre limité d'opérations disponibles. Les seules opérations possibles sont les suivantes :
* **sa** (swap a) : échanger les 2 premiers éléments en haut de la pile a. Ne rien faire s'il n'y a qu'un seul élément ou aucun élément.
* **sb** (swap b) : échanger les 2 premiers éléments en haut de la pile b. Ne rien faire s'il n'y a qu'un seul élément ou aucun élément.
* **ss** : sa et sb en même temps.
* **pa** (push a) : prendre le premier élément en haut de b et le mettre en haut de a. Ne rien faire si b est vide.
* **pb** (push b) : prendre le premier élément en haut de a et le mettre en haut de b. Ne rien faire si a est vide.
* **ra** (rotate a) : décaler tous les éléments de la pile a de 1 vers le haut. Le premier élément devient le dernier.
* **rb** (rotation b) : Décaler vers le haut tous les éléments de la pile b de 1. Le premier élément devient le dernier.
* **rr** : ra et rb en même temps.
* **rra** (rotation inverse a) : Décaler vers le bas tous les éléments de la pile a de 1. Le dernier élément devient le premier.
* **rrb** (rotation inverse b) : Décaler vers le bas tous les éléments de la pile b de 1. Le dernier élément devient le premier.
* **rrr** : rra et rrb en même temps.

Voici le [sujet](en.subject.pdf)

# Télécharge et test ⬇️

Clone le projet.

```
git clone https://github.com/ugozchi/42_Push_Swap.git
cd 42_Push_Swap
```

<br>

## Options possibles ⚙️

Ici, vous pouvez utiliser les options classiques d'un Makefile (options ci-dessous) mais aussi l'option bonus qui vous permettra d'ajouter vos fonctions bonus dans votre fichier archive libft.a si vous les avez fait.  
Toute cette partie correspond à ce que l'on doit rendre pour ce faire corriger.

<br>

| Option | Description |
| --- | --- |
| `make` | Créer un fichier archive libftpritnf.a avec tous les fichiers |
| `make clean` | Supprime le dossier contenant les fichiers objets ```.o```|
| `make fclean` | Execute `clean` puis supprime le fichier archive ```.a```|
| `make re` | Execute `fclean` puis `make` |

<br>

## Explication de l'algorithme de tri

### 1️⃣ Initialisation des arguments et préparation des piles
La première étape se déroule dans la fonction main :

1) Vérification des arguments
	- Si le programme est exécuté sans arguments `(ac == 1)`, ou si un seul argument vide est passé `(ac == 2 && !av[1][0])`, le programme appelle immédiatement `exit(EXIT_FAILURE)` et se termine.
	-Si un seul argument est passé, il est supposé être une chaîne contenant plusieurs nombres séparés par des espaces (exemple : `"1 2 3 4"`). Dans ce cas, le programme utilise `ft_split` pour diviser cette chaîne en plusieurs sous-chaînes représentant chaque nombre individuel.
2) Conversion des arguments en liste chaînée
	- Après avoir divisé les arguments ou après avoir reçu plusieurs arguments directement, le programme les convertit en une pile chaînée (`t_list`). Chaque nombre est vérifié pour s'assurer qu'il est bien un entier valide et qu'il ne dépasse pas les limites d'un `int` (avec `check_int` et `ft_atoi`).
	- Ensuite, le programme vérifie s'il y a des doublons dans les arguments à l'aide de la fonction `check_double`.
3) Vérification si la pile est déjà triée
	- Une fois la pile construite, avant de lancer les algorithmes de tri, le programme appelle `is_sort` pour voir si la pile est déjà dans l'ordre croissant.
	- Si la pile est déjà triée, le programme libère la mémoire et termine l'exécution immédiatement, car aucune autre action n'est nécessaire.
4) Allocation de la structure `t_data`
	- Une fois que le programme est prêt à trier, il alloue une structure `t_data`. Cette structure stockera des informations critiques pour le tri, notamment :
		- `med`: La médiane de la pile (utilisée comme pivot pour le tri rapide).
		- `best`: Le coût minimal de déplacement des éléments lors du tri par insertion.
		- D'autres champs pour les coûts et mouvements nécessaires lors de l'insertion des éléments.

### 2️⃣ Tri rapide (quick_sort)
Le tri rapide (quick sort) est un algorithme divisé en deux grandes étapes :
I) Séparation des éléments par rapport à un pivot.
II) Réarrangement récursif de chaque sous-ensemble.

1) Calcul de la médiane comme pivot
	- Avant de trier, le programme détermine un pivot en calculant la médiane des valeurs présentes dans la pile `a`.
	Processus :
		- La pile `a` est convertie en un tableau via `get_tab`.
		- Le tableau est trié avec l'algorithme du tri à bulles dans `bubble_sort`. Bien que simple, cet algorithme n'est efficace que pour de petits ensembles de données, ce qui est suffisant ici, car il est utilisé uniquement pour déterminer le pivot.
		- La médiane (élément central du tableau trié) est choisie comme pivot.
2) Poussée des éléments dans la pile `b`
	- Une fois la médiane calculée, le programme parcourt la pile `a` et déplace les éléments inférieurs à la médiane dans la pile `b` en utilisant la fonction `ft_pb`.
	Cas possibles :
		- Si l'élément en tête de la pile `a` est inférieur au pivot (médiane), il est poussé dans la pile `b`.
		- Si l'élément est supérieur ou égal au pivot, il est déplacé en bas de la pile `a` avec une rotation vers le haut (`ft_ra`).
		- Si `is_sort` retourne vrai, c'est-à-dire que la pile `a` est déjà triée après un certain nombre de rotations, ou si tous les éléments inférieurs au pivot ont été poussés dans `b`, la boucle est interrompue.
3) Tri récursif
	- Après avoir poussé les éléments de `a` vers `b`, le programme appelle récursivement quick_sort sur les sous-piles restantes pour continuer le processus de tri.
	- Cas de base : Si la taille de `a` tombe à 3 éléments ou moins, la fonction `small_sort` est appelée pour trier directement cette petite pile. Ce cas est géré séparément car il ne nécessite que quelques mouvements simples (rotations et échanges).

### 3️⃣Tri par insertion (insert_sort)
Une fois que les éléments inférieurs au pivot ont été poussés dans `b`, le programme commence à réinsérer ces éléments dans `a` en les triant :

1) Insertion des éléments de `b` dans `a`
	- Le programme parcourt la pile `b` et tente de réinsérer les éléments dans `a` tout en conservant l'ordre croissant de`a`.
	Cas possibles :
		- La fonction `can_push` vérifie si l'élément en tête de `b` peut être poussé en tête de `a` en respectant l'ordre croissant. Si c'est le cas, l'élément est poussé dans `a` via `ft_pa`.
		- Si l'insertion directe n'est pas possible, le programme doit calculer le meilleur mouvement à effectuer pour repositionner les éléments. Les fonctions suivantes sont utilisées :
			- `count_move`: Calcule le nombre de mouvements nécessaires pour chaque élément de `b` en tenant compte de sa position dans `a`.
			- `cost_move`: Ajuste les coûts en fonction de la taille des piles et des rotations nécessaires.
			- `best_move`: Sélectionne le mouvement le plus optimal en minimisant le coût total de déplacement.
		- Une fois le meilleur mouvement déterminé, `do_mov` est appelé pour exécuter ce mouvement (rotations, échanges, ou insertion).
2) Rotation finale pour trier `a`
	- Après avoir réinséré tous les éléments de `b` dans `a`, la fonction `end_rot` vérifie si `a` est correctement triée.
		- Si nécessaire, des rotations supplémentaires sont effectuées pour terminer le tri.
		- Si `best_rot` indique qu'une rotation vers le haut est préférable, des rotations `ft_ra` sont effectuées. Sinon, des rotations inverses (`ft_rra`) sont utilisées.

### 4️⃣ Gestion des mouvements et rotations
Le programme utilise plusieurs types de mouvements pour réorganiser les piles :

1) Rotations simultanées :
	- `ft_rr`: Effectue une rotation simultanée vers le haut des piles `a` et `b`.
	- `ft_rrr`: Effectue une rotation simultanée inverse des piles `a` et `b`.
2) Rotations individuelles :
	- `ft_ra` et `ft_rra`: Rotation vers le haut et rotation inverse pour la pile `a`.
	- `ft_rb` et `ft_rrb`: Rotation vers le haut et rotation inverse pour la pile `b`.

### 5️⃣ Cas particuliers
1) Si la pile contient 3 éléments ou moins
	- Quand `quick_sort` détecte que la taille de `a` est de 3 éléments ou moins, `small_sort` est utilisée pour trier cette pile. Cette fonction utilise des rotations et des échanges simples pour trier efficacement une petite pile.
2) Si la pile est déjà triée
	- À chaque étape du tri, le programme vérifie si la pile est déjà triée en utilisant `is_sort`. Cela permet d'arrêter le tri plus tôt si la pile est déjà dans l'ordre correct, optimisant ainsi les performances.

### 6️⃣ Nettoyage et libération de la mémoire
À la fin du processus de tri, le programme libère toutes les ressources allouées :
	- Les piles `a` et `b` sont libérées via `free_list`, qui parcourt chaque élément de la pile et libère la mémoire associée.
	- La structure `t_data` est également libérée.

<br>

## Tests et visualisation 📋

<br>

On peut visualiser comment marche l'algorithle grâce à [o-reo](https://github.com/o-reo) et son [Push_swap visualizer](https://github.com/o-reo/push_swap_visualizer)

![algo](.media/algo.gif)

On peut aussi le tester grâce à complexity. Ce programme va tester l'algorithme autant de fois que 'lon le souhaite avec des données différentes.

### Pour 100 nombres

Ici on demande 500 itérations de 100 nombres différents avec un objectif de tri en moins de 700 coups (pour avoir tous les points)

![complexity_100](.media/complexity_100.gif)

Ici on demande 100 itérations de 500 nombres différents avec un objectif de tri en moins de 5500 coups (pour avoir tous les points)

![complexity_100](.media/complexity_100.gif)

Dans les deux cas notre algorithme passe 100% des tests. Victoire !!!

<br>

## Note Final et Commentaires 📔

<br>

| |
| --- |
| ![](.media/note.png) |


| | |
| --- | --- |
| Correcteur 1 | <img src=".media/com1.png" /> |
| Correcteur 2 | <img src=".media/com2.png" /> |
| Correcteur 3 | <img src=".media/com3.png" /> |