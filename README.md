# Le jardin secret 

**A grid-based exploration game developed in C using ncurses.**

## Overview

The Secret Garden is a grid-based movement game developed in C as part of the Imperative Programming 2 course.

The player takes on the role of a gardener exploring an enchanted garden, collecting flowers and reaching the exit while avoiding thorn bushes.

## Game Objective

Collect all the flowers on the grid and reach the exit without touching any thorn bushes.

## Game Elements

| Element | Description |
|---|---|
| GRASS | Walkable area |
| HEDGE | Impassable obstacle |
| GARDENER | Player-controlled character |
| FLOWER | Collectible item |
| THORN | Trap that ends the game |
| EXIT | Becomes accessible after collecting all flowers |

## Features

- Gardener movement using the arrow keys.
- Collision detection with obstacles.
- Flower collection.
- Win and lose condition detection.
- Grid loading from external text files.
- Five difficulty levels.
- Terminal-based interface using the `ncurses` library.

## Technologies

- **Programming language:** C
- **Library:** ncurses
- **Compiler:** GCC
- **Build tool:** Make

## Project Structure

```text
Jardin-Secret/
│
├── main.c
├── grille.c
├── grille.h
├── pion.c
├── pion.h
├── Makefile
├── README.md
│
├── facile.txt
├── moyen.txt
├── difficile.txt
├── tres_difficile.txt
└── expert.txt
```

##  Installation and Execution

### 1. Requirements

On Debian / Ubuntu, install the ncurses library:

```bash
sudo apt install libncurses-dev
```

### 2. Compilation

From the project root directory, run:

```bash
make
```

### 3. Launch the Game

To start the game with the easy level:

```bash
./jeu facile.txt
```

To launch another level, replace `facile.txt` with the desired level file.

## Controls

| Key | Action |
|---|---|
| ↑ | Move up |
| ↓ | Move down |
| ← | Move left |
| → | Move right |
| Q / q | Quit the game |

---

**Academic Project — Imperative Programming 2**
