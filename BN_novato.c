#include <stdio.h>

// define o tamanho do tabuleirto
#define Linha 10
#define Colunas 10

int main()
{
    int tabu[Linha][Colunas]; //variavel de que recebe o tamanho

    char linha[10] = {'A','B','C','D','E','F','G','H','I','J'}; // char de letras para localizar

    // print do nome do jogo mais letra de localização
    printf("BATALHA NAVAL \n");
    printf("  %c %c %c %c %c %c %c %c %c %c\n", linha[0], linha[1], linha[2], linha[3], linha[4], linha[5], linha[6], linha[7], linha[8], linha[9] );

    
    for(int i = 0; i<Linha; i ++)//for para impremir primeiro so linhas com contagem apartir do 1
    {
        printf("%d.", i + 1); // faz a soma para inicio com linhas em com numero de 1 a 10

        for(int j = 0; j < Colunas; j++) // for para impremir o numeros de colunas
        {
            printf("%d ", tabu[i][j] = 0); // inicia o tabuleiro com tudo em 0
        }
        printf("\n"); //pula para iniciar a proxima linha aparte do 0
    }


    printf("\n"); // pula linha para proxima configuração


    // Define as coordenadas de início e o tamanho dos navios
    int nv_hor_lin = 9;
    int nv_hor_col = 3;
    int nv_vert_lin = 5;
    int nv_vert_col = 7;
    int tamanho_navio = 3;

    // Adiciona os navios ao tabuleiro

        for (int j = nv_hor_col; j < nv_hor_col + tamanho_navio; j++) {
            tabu[nv_hor_lin][j] = 3; // 3 representa o navio
        }


        for (int i = nv_vert_lin; i < nv_vert_lin + tamanho_navio; i++) {
            tabu[i][nv_vert_col] = 3; // 3 representa o navio
        }

        //re-imprime o nome e letras de localisar os navos
        printf("   BATALHA NAVAL \n");
        printf("  %c %c %c %c %c %c %c %c %c %c\n", linha[0], linha[1], linha[2], linha[3], linha[4], linha[5], linha[6], linha[7], linha[8], linha[9] );

        // Imprime o tabuleiro
        for (int i = 0; i < Linha; i++) 
        {
            printf("%d ", i + 1); // Imprime o número da linha

            for (int j = 0; j < Colunas; j++)// imprime numero de colunas
            {
                printf("%d ", tabu[i][j]); // inicia o tabuleiro com navios juntos 
            }
            printf("\n"); // pula a linha para começar a poxima linha sem misturar os programas
        }

    return 0;
}
