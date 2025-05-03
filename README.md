<!---banner--->
<h1 align="center"> 
📄 get_next_line
</h1>

> Un projet 42 pour lire une ligne d'un fichier à chaque appel de fonction, en C !

<p align="center">
    <img src="https://res.cloudinary.com/dzo1cimyr/image/upload/v1746300692/cub3d_dn7sub.gif" width="800">
</p>

---

## ✨ Présentation

`get_next_line` est une fonction qui permet de lire, à chaque appel, la ligne suivante d'un descripteur de fichier donné. Elle gère la mémoire dynamiquement et fonctionne même avec des fichiers volumineux ou des lectures multiples en parallèle (version bonus).

---

## 🚀 Fonctionnalités

- Lecture ligne par ligne d'un fichier (ou d'un flux)
- Gestion efficace de la mémoire
- Compatible avec n'importe quel descripteur de fichier
- Version bonus : gestion simultanée de plusieurs fichiers

---

## ⚙️ Utilisation

### Compilation

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o gnl
```

### Exemple d'utilisation

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void) {
    int fd = open("mon_fichier.txt", O_RDONLY);
    char *line;
    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
```

---

## 🏅 Version Bonus

La version bonus (`get_next_line_bonus.c/.h/.utils_bonus.c`) permet de lire plusieurs fichiers en parallèle, chaque descripteur de fichier ayant son propre état interne.

---

## 📦 Fichiers

- `get_next_line.c` / `get_next_line.h` : version principale
- `get_next_line_utils.c` : fonctions utilitaires
- `get_next_line_bonus.c` / `get_next_line_bonus.h` : version bonus multi-fd
- `get_next_line_utils_bonus.c` : utilitaires pour la version bonus

---

## 🛠️ Technologies & Langages utilisés

<p align="left">
  <img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/c/c-original.svg" alt="C" width="40" height="40"/> <img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/linux/linux-original.svg" alt="Linux" width="40" height="40"/> <img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/vim/vim-original.svg" alt="Vim" width="40" height="40"/>
</p>

