
#include "Librarie_Snake.h"

void creare_matrice(int ***a, int n)
{
    (*a)=(int **)calloc(n+2, sizeof(int *));
    for(int i=0;i<=n+2; i++)
        (*a)[i]=(int *)calloc(n+2, sizeof(int));
    for(int i=0;i<=n+1; i++)
    {
        (*a)[0][i]=-1;
        (*a)[n+1][i]=-1;
        (*a)[i][0]=-1;
        (*a)[i][n+1]=-1;
    }
}

void eliberare_matrice(int ***a, int n)
{
    for(int i=0;i<=n+2;i++)
        free((*a)[i]);
    free(*a);
    (*a)=NULL;
}

void afisare_matrice(int **a, int n)
{
    for(int i=0;i<=n+1;i++) //0 -1 -2 >=1
    {
        for(int j=0;j<=n+1;j++)
        {
         if(a[i][j]==0)
         printf(" %c ", 48);
         if(a[i][j]==-1)
         printf(" %c ", 35);
         if(a[i][j]==-2)
         printf(" %c ", 126);
         if(a[i][j]>=1)
         printf(" %c ", 43);

        }
    printf("\n");
    }
    printf("\n");
}

void atribuire_inceput(int ***a, int n, int *x, int *y)
{
    int x_s=rand()%n+1, y_s=rand()%n+1;
    while(!((x_s>=1 && x_s<n) && (y_s>=1 && y_s<n) && (*a)[x_s][y_s]!=-1))
    {
        x_s=rand()%n+1;
        y_s=rand()%n+1;
    }
    (*x)=x_s;
    (*y)=y_s;
    (*a)[*x][*y]=1;
}
void atribuire_puncte(int ***a, int n)
{
    int contor=0;
    int x_s=rand()%n+1, y_s=rand()%n+1;
    while(!((x_s>=1 && x_s<=n) && (y_s>=1 && y_s<=n) && (*a)[x_s][y_s]==0) && (*a)[x_s][y_s]>=1 && contor<n*n)
    {
        x_s=rand()%n+1;
        y_s=rand()%n+1;
        contor++;
    }
    (*a)[x_s][y_s]=-2;
}
void update(int ***a, int n, int x, int y, int punctaj)
{
    int minim=0;
    int OK_caz_adaugare=0;
    while(minim<punctaj)
    {
        minim++;
        if(x+1<= n && (*a)[x+1][y]==minim)
        {
            (*a)[x][y]=minim;
            x++;
        }
        else if(y+1<=n && (*a)[x][y+1]==minim)
        {
            (*a)[x][y]=minim;
            y++;
        }
        else if(x-1>=1 && (*a)[x-1][y]==minim)
        {
            (*a)[x][y]=minim;
            x--;
        }
        else if(y-1>=1 && (*a)[x][y-1]==minim)
        {
            (*a)[x][y]=minim;
            y--;
        }
        else if(minim==punctaj)
            OK_caz_adaugare=1;
    }
    int variabila;
    if(OK_caz_adaugare)
    {
        variabila=(*a)[x][y];
        (*a)[x][y]=punctaj;
        if(variabila==-2)
            atribuire_puncte(&(*a), n);
    }
    else
    {
        variabila=(*a)[x][y];
        (*a)[x][y]=0;
        if(variabila==-2)
            atribuire_puncte(&(*a), n);
    }
    int OK=1;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        if((*a)[i][j]==-2)
            OK=0;
    if(OK)
        atribuire_puncte(&(*a), n);
}


int input(int ***a, int n, int *x, int *y, int *punctaj, int *caz_curent)
{
       char mutare;
       if(_kbhit())
       {
       mutare=_getch();
        switch ((unsigned char)mutare)
        {
        case 0xE0:
        mutare=_getch();
        switch(mutare)
        {
        case 72: // sus
            (*x)--;
            (*caz_curent)=1;
            break;
        case 80: // jos
            (*x)++;
            (*caz_curent)=2;
            break;
        case 75: // stanga
            (*y)--;
            (*caz_curent)=3;
            break;
        case 77: // dreapta
            (*y)++;
            (*caz_curent)=4;
            break;
        default:
            printf("Nu s-a introdus caracterul corespunzator!!!!\n");
            break;
        }
        }
       }
        else if((*caz_curent)==-1)
        {
            (*x)++;
            //printf("BAAAAAAAAAAAAAAAAAAA CAZU CURENT %d E ASTA \n", caz_curent);
        }
        else if((*caz_curent)!=-1)
        {
        switch((*caz_curent))
            {
            case 1:
                (*x)--;
                break;
            case 2:
                (*x)++;
                break;
            case 3:
                (*y)--;
                break;
            case 4:
                (*y)++;
                break;
            default:
                break;
            }
        }
        if ((*a)[*x][*y] == -2)
        {
            (*punctaj)++;
            atribuire_puncte(&(*a), n);
            (*a)[*x][*y] = 0;
        }
        else if ((*a)[*x][*y] >= 1 || (*a)[*x][*y]==-1)
        {
            printf("\n \rAi pierdut!!!!");
            return 0;
        }
        system("cls");
        update(&(*a), n, *x, *y, *punctaj);
       // afisare_matrice((*a), n);

    return 1;
}


