
#include "Librarie_Snake.h"

int main()
{
    srand(time(NULL));
    int **matrice, n, caz_curent=-1;
    printf("-----------SNAKE-----------\n");
    printf("Te misti cu sagetute, +-ul reprezinta sarpele, ~ marul si # granita\n");
    char caracter_continuare;
        printf("Vrei sa incepi un joc nou? (Y/N)");
    while(scanf("%c", &caracter_continuare) && (caracter_continuare=='y' || caracter_continuare=='Y') )
    {
              int punctaj=1;
              getchar();
              printf("\n \rCat de mare vrei sa fie tabela?");
              scanf("%d", &n);
              creare_matrice(&matrice,n);
              int OK=1;
              int x,y;
              atribuire_inceput(&matrice, n, &x, &y);
              atribuire_puncte(&matrice, n);
              //afisare_matrice(matrice, n);
              while(OK)
              {
                  OK=input(&matrice, n, &x, &y, &punctaj, &caz_curent);
                  afisare_matrice(matrice, n);
                  Sleep(1000);
              }
              printf("Punctaj acumulat:  %d\n", punctaj-1);
              getchar();
              printf("Vrei sa incepi un nou joc?");

    }
    return 0;
    
}
