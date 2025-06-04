// Desafio Batalha Naval
#include <stdio.h>

// Função para verificar se o posicionamento do navio é válido
int validarPosicao(char tabuleiro[10][10], int x, int y, int tamanho, char orientacao)
{
    if (orientacao == 'H')
    { // Horizontal
        if (y + tamanho > 10)
            return 0; // Fora dos limites
        for (int i = 0; i < tamanho; i++)
        {
            if (tabuleiro[x][y + i] != '0')
                return 0; // Sobreposição
        }
    }
    else if (orientacao == 'V')
    { // Vertical
        if (x + tamanho > 10)
            return 0; // Fora dos limites
        for (int i = 0; i < tamanho; i++)
        {
            if (tabuleiro[x + i][y] != '0')
                return 0; // Sobreposição
        }
    }
    return 1; // Posição válida
}

// Função para posicionar o navio no tabuleiro
void posicionarNavio(char tabuleiro[10][10], int x, int y, int tamanho, char orientacao)
{
    if (orientacao == 'H')
    { // Horizontal
        for (int i = 0; i < tamanho; i++)
        {
            tabuleiro[x][y + i] = '3';
        }
    }
    else if (orientacao == 'V')
    { // Vertical
        for (int i = 0; i < tamanho; i++)
        {
            tabuleiro[x + i][y] = '3';
        }
    }
}

// Função para verificar se o posicionamento do navio diagonal é válido
int validarPosicaoDiagonal(char tabuleiro[10][10], int x, int y, int tamanho, char direcao)
{
    if (direcao == 'D')
    { // Diagonal principal ↘
        if (x + tamanho > 10 || y + tamanho > 10)
            return 0; // Fora dos limites
        for (int i = 0; i < tamanho; i++)
        {
            if (tabuleiro[x + i][y + i] != '0')
                return 0; // Sobreposição
        }
    }
    else if (direcao == 'E')
    { // Diagonal secundária ↙
        if (x + tamanho > 10 || y - tamanho + 1 < 0)
            return 0; // Fora dos limites
        for (int i = 0; i < tamanho; i++)
        {
            if (tabuleiro[x + i][y - i] != '0')
                return 0; // Sobreposição
        }
    }
    return 1; // Posição válida
}

// Função para posicionar o navio diagonal no tabuleiro
void posicionarNavioDiagonal(char tabuleiro[10][10], int x, int y, int tamanho, char direcao)
{
    if (direcao == 'D')
    { // Diagonal principal ↘
        for (int i = 0; i < tamanho; i++)
        {
            tabuleiro[x + i][y + i] = '3';
        }
    }
    else if (direcao == 'E')
    { // Diagonal secundária ↙
        for (int i = 0; i < tamanho; i++)
        {
            tabuleiro[x + i][y - i] = '3';
        }
    }
}

int main()
{
    // Matriz de 10x10
    char tabuleiro[10][10];
    // Inicializa o tabuleiro com o valor 0, representando a água
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            tabuleiro[i][j] = '0';
        }
    }

    // Coordenadas e orientações dos navios
    int inicioNavio1X = 2, inicioNavio1Y = 3; // Navio 1: horizontal
    int inicioNavio2X = 5, inicioNavio2Y = 6; // Navio 2: vertical
    int inicioNavio3X = 0, inicioNavio3Y = 0; // Navio 3: diagonal principal ↘
    int inicioNavio4X = 0, inicioNavio4Y = 9; // Navio 4: diagonal secundária ↙
    char orientacaoNavio1 = 'H';              // Horizontal
    char orientacaoNavio2 = 'V';              // Vertical
    char direcaoNavio3 = 'D';                 // Diagonal principal ↘
    char direcaoNavio4 = 'E';                 // Diagonal secundária ↙
    int tamanhoNavio = 3;                     // Tamanho fixo dos navios

    // Validar e posicionar o primeiro navio (horizontal)
    if (validarPosicao(tabuleiro, inicioNavio1X, inicioNavio1Y, tamanhoNavio, orientacaoNavio1))
    {
        posicionarNavio(tabuleiro, inicioNavio1X, inicioNavio1Y, tamanhoNavio, orientacaoNavio1);
    }
    else
    {
        printf("Erro: Não foi possível posicionar o primeiro navio.\n");
        return 1;
    }

    // Validar e posicionar o segundo navio (vertical)
    if (validarPosicao(tabuleiro, inicioNavio2X, inicioNavio2Y, tamanhoNavio, orientacaoNavio2))
    {
        posicionarNavio(tabuleiro, inicioNavio2X, inicioNavio2Y, tamanhoNavio, orientacaoNavio2);
    }
    else
    {
        printf("Erro: Não foi possível posicionar o segundo navio.\n");
        return 1;
    }

    // Validar e posicionar o terceiro navio (diagonal principal ↘)
    if (validarPosicaoDiagonal(tabuleiro, inicioNavio3X, inicioNavio3Y, tamanhoNavio, direcaoNavio3))
    {
        posicionarNavioDiagonal(tabuleiro, inicioNavio3X, inicioNavio3Y, tamanhoNavio, direcaoNavio3);
    }
    else
    {
        printf("Erro: Não foi possível posicionar o terceiro navio (diagonal ↘).\n");
        return 1;
    }

    // Validar e posicionar o quarto navio (diagonal secundária ↙)
    if (validarPosicaoDiagonal(tabuleiro, inicioNavio4X, inicioNavio4Y, tamanhoNavio, direcaoNavio4))
    {
        posicionarNavioDiagonal(tabuleiro, inicioNavio4X, inicioNavio4Y, tamanhoNavio, direcaoNavio4);
    }
    else
    {
        printf("Erro: Não foi possível posicionar o quarto navio (diagonal ↙).\n");
        return 1;
    }

    // Exibir o tabuleiro no console
    printf("Tabuleiro:\n");
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}