#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
void creare_matrice(int ***a, int n);
void eliberare_matrice(int ***a, int n);
void afisare_matrice(int **a, int n);
void atribuire_inceput(int ***a, int n, int *x, int *y);
void atribuire_puncte(int ***a, int n);
void update(int ***a, int n, int x, int y, int punctaj);
int input(int ***a, int n, int *x, int *y, int *punctaj, int *caz_curent);
