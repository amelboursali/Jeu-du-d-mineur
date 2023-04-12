#include <stdio.h>
#include <stdlib.h>

char **GRILLE;           
char **MINES;            
int k=20;
int N=10;
int kautour=0;

void affichage_depart()
{
    int i,j;
    GRILLE=(char**)malloc(sizeof(char*)*N);
    for (i=0; i<N; i++)
    {
        GRILLE[i]=(char*)malloc(sizeof(char)*N);
        for (j=0;j<N;j++)
        {
            GRILLE[i][j]='_';
        }
    }
    for(i=0; i<=N-1; i++)
    {
        for(j=0;j<=N-1;j++)
        {
            if(j==0)
            {
                printf("\n|%c|",GRILLE[i][j]);
            }
            else{
                printf("%c|",GRILLE[i][j]);
            }
        }
    }
    printf("\n");
}

void mine()
{
    int x,y,i,j;

    MINES=(char**)malloc(sizeof(char*)*N);

    for(i=0;i<=N;i++)
    {
        MINES[i]=(char*)malloc(sizeof(char)*N+1);
        for(j=0;j<=N;j++)
        {
            MINES[i][j]='_';
        }
    }

    for(i=0;i<k;i++)
    {
        x=rand()%N;
        y=rand()%N;

        if(MINES[x][y]=='_') MINES[x][y]='M';
        else k++;
    }
}

void mine_autour(int x, int y)
{
    if(MINES[x][y]=='M') printf("Perdu\n");
    
    if(x>0 && y>0)
    {
        if (MINES[x - 1][y] == 'M')
            kautour++;
        if (MINES[x + 1][y] == 'M')
            kautour++;
        if (MINES[x][y - 1] == 'M')
            kautour++;
        if (MINES[x][y + 1] == 'M')
            kautour++;
        if (MINES[x - 1][y - 1] == 'M')
            kautour++;
        if (MINES[x + 1][y - 1] == 'M')
            kautour++;
        if (MINES[x + 1][y + 1] == 'M')
            kautour++;
        if (MINES[x - 1][y + 1] == 'M')
            kautour++;
    }
}

void autour_case(x, y)
{
    if (kautour == 0) 
        GRILLE[x][y] = ' ';
    if (kautour == 1) 
        GRILLE[x][y] = '1';
    if (kautour == 2) 
        GRILLE[x][y] = '2';
    if (kautour == 3) 
        GRILLE[x][y] = '3';
    if (kautour == 4) 
        GRILLE[x][y] = '4';
    if (kautour == 5) 
        GRILLE[x][y] = '5';
    if (kautour == 6) 
        GRILLE[x][y] = '6';
    if (kautour == 7) 
        GRILLE[x][y] = '7';
    if (kautour == 8) 
        GRILLE[x][y] = '8';
    if (MINES[x][y] == 'M') 
        GRILLE[x][y] = 'M';
}

void drapeau(int x, int y)
{
    k--;
    GRILLE[x][y] = 'X';
    printf("Il reste %d mines.\n", k);
}

void grille2(int x, int y)
{
    int i, j;
    for (i=0; i<=N-1; i++)
    {
        for (j=0; j<=N-1; j++)
        {
            if (j==0)
            {
                printf("\n|%c|", GRILLE[i][j]);
            }
            else {
                printf("%c|", GRILLE[i][j]);
            }
        }
    }
    printf("\n");
}

int main ()
{
    int x, y, n, m = 0;
    
    printf("Demineur :");
    printf("\n");
    printf("10x10 avec 20 mines :\n\n");

    affichage_depart();
    mine();

    while (m == 0 && k > 0)
    {
        printf("\n1 : Découvrir une case\n2 : Placer un drapeau\n\n");
        scanf("%d", &n);
        kautour = 0;

        if (n == 1)
        {
            printf("Coordonnées de la case :\n");
            scanf("\n%d",&x);
            scanf("\n%d",&y);
            mine_autour(x,y);
            autour_case(x,y);
            if (MINES[x][y] == 'M') m = 1;
            grille2(x, y);
        }
        if (n == 2)
        {
            printf("Coordonnées du drapeau :\n");
            scanf("\n%d",&x);
            scanf("\n%d",&y);
            drapeau(x,y);
            grille2(x, y);
        }
    }
    if (k == 0) printf("\nGagné");
    return 0;
}