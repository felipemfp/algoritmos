/*
 * Escreva um programa que funcione como um Jogo da Velha para 2 jogadores.
 */

#include <stdio.h>

#define SIZE    3

void createBoard(char board[SIZE][SIZE])
{
  int i, j;
  for (i = 0; i < SIZE; i++)
  {
    for (j = 0; j < SIZE; j++)
    {
      board[i][j] = ' ';
    }
  }
}

void printBoard(char board[SIZE][SIZE])
{
  int i, j;
  printf("\n.: Tabuleiro :.\n\n");
  printf("   ");
  for (j = 0; j < SIZE; j++)
  {
    printf(" %d ", j + 1);
    if (j < SIZE - 1)
    {
      printf(" ");
    }
  }
  printf("\n  -");
  for (j = 0; j < SIZE; j++)
  {
    printf("---");
    printf("-");
  }
  printf("\n");
  for (i = 0; i < SIZE; i++)
  {
    printf("%d |", i + 1);
    for (j = 0; j < SIZE; j++)
    {
      printf(" %c ", board[i][j]);
      printf("|");
    }
    printf("\n");
    printf("  -");
    for (j = 0; j < SIZE; j++)
    {
      printf("---");
      printf("-");
    }
    printf("\n");
  }
}

char checkMove(char board[SIZE][SIZE], int x, int y)
{
  if (x < 0 || y < 0)
  {
    return 0;
  }
  if (x >= SIZE || y >= SIZE)
  {
    return 0;
  }
  if (board[x][y] != ' ')
  {
    return 0;
  }
  return 1;
}

int checkWinColumn(char board[SIZE][SIZE], int x, int y)
{
  int i, n = 0;
  for (i = 0; i < SIZE; i++)
  {
    if (board[x][i] == board[x][y])
    {
      n++;
    }
  }
  return n == 3 ? 1 : 0;
}

int checkWinRow(char board[SIZE][SIZE], int x, int y)
{
  int i, n = 0;
  for (i = 0; i < SIZE; i++)
  {
    if (board[i][y] == board[x][y])
    {
      n++;
    }
  }
  return n == 3 ? 1 : 0;
}

int checkWinDiagonal(char board[SIZE][SIZE], int x, int y)
{
  int i, n = 0;
  for (i = 0; i < SIZE; i++)
  {
    if (board[i][i] == board[x][y])
    {
      n++;
    }
  }
  if (n == 3)
  {
    return 1;
  }
  else
  {
    n = 0;
  }
  for (i = 0; i < SIZE; i++)
  {
    if (board[2 - i][i] == board[x][y])
    {
      n++;
    }
  }
  return n == 3 ? 1 : 0;
}

int checkWin(char board[SIZE][SIZE], char c, int x, int y)
{
  board[x][y] = c;
  if (checkWinRow(board, x, y))
  {
    return 1;
  }
  else if (checkWinColumn(board, x, y))
  {
    return 1;
  }
  else if (checkWinDiagonal(board, x, y))
  {
    return 1;
  }
  return 0;
}

int checkDraw(char board[SIZE][SIZE])
{
  int i, j;
  for (i = 0; i < SIZE; i++)
  {
    for (j = 0; j < SIZE; j++)
    {
      if (board[i][j] == ' ')
      {
        return 0;
      }
    }
  }
  return 1;
}

int main(int argc, char const *argv[])
{
  int newGame = 1;
  int player = 0, gameover = 0, winner;
  char board[SIZE][SIZE];
  char identifier[] = { 'X', 'O' };
  char enterKey;
  printf("..:: JOGO DA VELHA ::..\n\nModo de jogo: 2 jogadores\nFormato de Jogada: <LINHA> <COLUNA>\n\n");
  printf("Pressione ENTER para continuar...\n");
  scanf("%c", &enterKey);
  createBoard(board);
  printBoard(board);
  while (!gameover)
  {
    int i, j;
    printf("\nQual sua próxima jogada, Jogador %d (%c)? ", player + 1, identifier[player]);
    scanf("%d %d", &i, &j);
    while (!checkMove(board, i - 1, j - 1))
    {
      printf("JOGADA INVÁLIDA!\nQual sua próxima jogada, Jogador %d (%c)? ", player + 1, identifier[player]);
      scanf("%d %d", &i, &j);
    }
    if (checkWin(board, identifier[player], i - 1, j - 1))
    {
      winner = player;
      gameover = 1;
    }
    else if (checkDraw(board))
    {
      winner = -1;
      gameover = 1;
    }
    player = player ? 0 : 1;
    printBoard(board);
  }
  printf("\n\nJOGO TERMINADO!!!\n");
  if (winner >= 0)
  {
    printf("O Jogador %d (%c) ganhou.\n", winner + 1, identifier[winner]);
  }
  else
  {
    printf("Houve um empate.\n");
  }
  return 0;
}
