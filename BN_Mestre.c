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
    int nv_hor_lin = 0;
    int nv_hor_col = 4;

    int nv_vert_lin = 4;
    int nv_vert_col = 9;
    int tamanho_navio = 3;

    //define as coordenadas do inico da diagonal para navios

    int nv_diag_lin = 0;
    int nv_diag_col = 0;
    int nv_dig2_lin = 0;
    int nv_dig2_col = 9;

    // Define as coordenadas do centro da cruz e seu tamanho
    int cruz_lin = 7;
    int cruz_col = 3;
    int tamanho_braco_horizontal = 2;
    int tamanho_braco_vertical = 1;
    int cruz_valor = 5; 
 
    // cone com cordenada e tamanho

    int cone_topo_lin = 2;
    int cone_base_lin = 4;
    int cone_centro_col = 4;
    int cone_valor = 5;

     // Define e posiciona octaedro losango 
    int octa_lin = 6;
    int octa_col = 7;
    int octa_tam = 1;
    int octa_val = 5;

    // Adiciona os navios ao tabuleiro

    // Navio horizontal
    for (int j = nv_hor_col; j < nv_hor_col + tamanho_navio; j++) {
        if (nv_hor_lin >= 0 && nv_hor_lin < Linha && j >= 0 && j < Colunas)
        {
            tabu[nv_hor_lin][j] = 3; // 3 representa o navio
        }
    }

    // Navio vertical
    for (int i = nv_vert_lin; i < nv_vert_lin + tamanho_navio; i++) 
    {
        if (i >= 0 && i < Linha && nv_vert_col >= 0 && nv_vert_col < Colunas) 
        {
            tabu[i][nv_vert_col] = 3; // 3 representa o navio
        }
    }

    //Diagonal superio esquerda para diagonal inferio direita
    for (int k = 0; k < tamanho_navio; k++) 
    {
        int linha_atual = nv_diag_lin + k; // coloca o navio na linhas determinada pela localização
        int coluna_atual = nv_diag_col + k; // coloca o navio na colunas determinada pela localização
        if (linha_atual >= 0 && linha_atual < Linha && coluna_atual >= 0 && coluna_atual < Colunas) 
        {
            tabu[linha_atual][coluna_atual] = 3; // 3 representa o navio
        }
    }

    //Diagonal superio direita para diagonal inferio esquerda

    for (int k = 0; k < tamanho_navio; k++) 
    {
        int linha_atual = nv_dig2_lin + k; // coloca o navio na linhas determinada pela localização
        int coluna_atual = nv_dig2_col - k; // coloca o navio na colunas determinada pela localização
        if (linha_atual >= 0 && linha_atual < Linha && coluna_atual >= 0 && coluna_atual < Colunas) 
        {
            tabu[linha_atual][coluna_atual] = 3; // 3 representa o navio
        }
    }

    //Colocando as figuras no tabuleiro

    // Representação da cruz usando loops for e if
    for (int i = cruz_lin - tamanho_braco_vertical; i <= cruz_lin + tamanho_braco_vertical; i++) 
    {
        for (int j = cruz_col - tamanho_braco_horizontal; j <= cruz_col + tamanho_braco_horizontal; j++) 
        {
            if (i >= 0 && i < Linha && j >= 0 && j < Colunas) 
            {
                // Condição para marcar as células da cruz
                if (i == cruz_lin || j == cruz_col)
                {
                    tabu[i][j] = cruz_valor;
                }
            }
        }
    }

    // Representação do perfil do cone (triângulo)
    for (int i = cone_topo_lin; i <= cone_base_lin; i++)
    {
        // Calcula a largura do cone nesta linha
        int largura = i - cone_topo_lin;
        for (int j = cone_centro_col - largura; j <= cone_centro_col + largura; j++) 
        {
            if (i >= 0 && i < Linha && j >= 0 && j < Colunas) 
            {
                tabu[i][j] = cone_valor;
            }
        }
    }

            // Coloca o Octo no tabulheiro

    for (int i = octa_lin - octa_tam; i <= octa_lin + octa_tam; i++) 
    {
        for (int j = octa_col - octa_tam; j <= octa_col + octa_tam; j++) 
        {
            if (i >= 0 && i < Linha && j >= 0 && j < Colunas) 
            {
            int dl = i - octa_lin;
            int dc = j - octa_col;

                if ((dl >= 0 && dc >= 0 && dl + dc <= octa_tam) ||
                    (dl >= 0 && dc <= 0 && dl - dc <= octa_tam) ||
                    (dl <= 0 && dc >= 0 && -dl + dc <= octa_tam) ||
                    (dl <= 0 && dc <= 0 && -dl - dc <= octa_tam)) 
                {
                    tabu[i][j] = octa_val;
                }
            }
        }
    }


    //re-imprime o nome e letras de localisar os navos
    printf("  BATALHA NAVAL \n");
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
