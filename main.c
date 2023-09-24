#include <stdio.h>
#include <stdlib.h>
#include<locale.h>
#include <time.h>

#define M 4
#define N M*M


void apres(){
    printf("************* JOGO DA MEMÓRIA ************\n\n");
}

void forma(char cartas[]){
    int x = 0;

    for (int i=0; i<2; i++){
        for (int j=0; j<(N/2); j++){
            cartas[x] = j;
            x++;
        }
    }
}

void montatab(char cartas[], char tab[M][M]){
    int x = 0;
    for (int i=0; i<M; i++){
        for (int j=0; j<M; j++){
            tab [i][j] = cartas[x];
            x++;
        }
    }
}

void embaralhar(char cartas[]){
	for (int i = 0; i < N; i++){
		int r = rand() % N;
		int temp = cartas[i];
		cartas[i] = cartas[r];
		cartas[r] = temp;
	}
}

void mostratab(char tab[M][M]){
    for (int i=0; i<M; i++){
        for (int j=0; j<M; j++){
            printf(" | %d |", tab[i][j]);
        }
        printf("\n");
    }
}

void temporizador(char tab[M][M]){
    for (int i=3; i>0; i--){
        apres();
        mostratab(tab);
        printf("\n\nDesaparecendo em (%d) segundos", i);
        for (int j=0; j<3; j++){
            printf(".");
            Sleep(400);
        }
        Sleep(50);
        system("cls");
    }
}

void tabuleiroescondido(char tabescond[M][M]){
    for(int i=0; i<M; i++){
        for (int j=0; j<M; j++){
            tabescond[i][j] = '*';
        }
    }
}

int main(){
    setlocale(LC_ALL, "");
    srand(time(NULL));

    char tab[M][M];
    char cartas[N];
    char tabescond[M][M];
    int line, col;

    forma(cartas);

    embaralhar(cartas);

    montatab(cartas, tab);

    apres();

    printf("\n\nAperte qualquer tecla para começar . . .");
    getchar();
    fflush(stdin);
    system("cls");

    apres();

    mostratab(tab);

    system("cls");

    temporizador(tab);

    tabuleiroescondido(tabescond);

    printf("\n\nESCOLHENDO A POSIÇÃO");
    printf("\nDigite a *LINHA*: ");
    scanf("%d", &line);
    printf("\nDigite a *COLUNA*: ");
    scanf("%d", &col);



























}
