# Groupe de goix_a

# AbstractVM ETNA 2019

![texte alt](https://www.cidj.com/sites/default/files/styles/full_offre/public/2019-07/etna%20logo_0.png?itok=jYO5-50N "Logo ETNA")

## Compile + Execution:

1. Changer PATH TO FILE pour mettre le chemin vers le fichier a executer

2. Si le projet n'a jamais etais lancer créé les dossier obj et bin

```bash
mkdir obj && mkdir bin

make && cd bin && ./abstractvm PATH TO FILE && cd ..
```

## OS & Version tester

- ### Mac osx Catalina

  - GNU Make 3.81
  - GCC 4.2.1
  - clang 11.0.0

- ### Debian 10
  - GNU Make 4.2.1
  - gcc version 8.3.0
