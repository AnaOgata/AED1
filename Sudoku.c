#include <stdio.h>
#include <stdbool.h>

bool linha_valida(int matriz[9][9], int linha, int n) {
    int aux = 0;
    for(int coluna = 0; coluna < 9; coluna++) {
        if(matriz[linha][coluna] == n)
            aux++;
    }
    if (aux != 1) return false;
    return true;
}
//Essa função serve para verificar se se um número é válido na linha que ele foi inserido

bool coluna_valida(int matriz[9][9], int coluna, int n) {
    int aux = 0;
    for(int linha = 0; linha < 9; linha++) {
        if(matriz[linha][coluna] == n)
            aux++;
    }
    if (aux != 1) return false;
    return true;
}
//Essa função faz o mesmo que a anterior, só que para os números que estão inseridos na coluna

bool sudokinho_valido(int matriz[9][9], int iLinha, int iColuna, int n) {
    int aux = 0;
    for(int linha = 0; linha < 3; linha++) {
        for(int coluna = 0; coluna < 3; coluna++) {
            if(matriz[linha + iLinha][coluna + iColuna] == n)
                aux++;
        }
    }
    if (aux != 1) return false;
    return true;
}
//Essa função serve para verificar se um número não se repete em cada quadradrinho de 3X3 do sudoku

bool valido(int matriz[9][9], int linha, int coluna, int n) {
    return linha_valida(matriz, linha, n) && coluna_valida(matriz, coluna, n) && sudokinho_valido(matriz, linha - (linha % 3), coluna - (coluna % 3), n);
}
//Essa função confere as posições do sudoku

bool sudoku_valido(int matriz[9][9]) {
    for(int linha = 0; linha < 9; linha++) {
        for(int coluna = 0; coluna < 9; coluna++) {
            if(!valido(matriz, linha, coluna, matriz[linha][coluna]))
                return false;
        }
    }
    return true;
}
//Essa função confere se a matriz inserida pode ser a solução de um sudoku

int main() {
    int n;
    scanf("%d", &n);

    for(int instancia = 1; instancia <= n; instancia++) {
        int matriz[9][9];
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                scanf("%d", &matriz[i][j]);
            }
        }
        //Até agora o programa só leu as informações obrigatórias do enunciado

        printf("Instancia %d\n", instancia);
        if(sudoku_valido(matriz)) printf("SIM\n");
        else printf("NAO\n");

        printf("\n");
        //Aqui é onde se faz toda a verificação dos dados inseridos
    } 
    return 0;
}
