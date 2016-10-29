/*
 * Escreva um programa que mostre o tabuleiro resolvido de um campo minado.
 * O programa deve aceitar tabuleiro de tamanho N.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int howManyBombs(int side)
{
  return side + (side / 5 * 2);
}

void addBombs(int side, char board[side][side])
{
  int i, qte = howManyBombs(side);
  for (i = 0; i < qte; i++)
  {
    int x = rand() % side, y = rand() % side;
    board[x][y] = '*';
  }
}

void createBoard(int side, char board[side][side])
{
  int i, j;
  for (i = 0; i < side; i++)
  {
    for (j = 0; j < side; j++)
    {
      board[i][j] = ' ';
    }
  }
}

void printBoard(int side, char board[side][side])
{
  int i, j;
  printf("..:: Campo Minado ::..\n\n");
  for (i = 0; i < side; i++)
  {
    for (j = 0; j < side; j++)
    {
      printf(" %c ", board[i][j]);
      if (j < side - 1)
      {
        printf("|");
      }
    }
    printf("\n");
    if (i < side - 1)
    {
      for (j = 0; j < side; j++)
      {
        printf("---");
        if (j < side - 1)
        {
          printf("-");
        }
      }
    }
    printf("\n");
  }
}

void addLabel(int side, char board[side][side], int x, int y)
{
  int i, label = 0;
  if (board[x][y] == '*') {
    return;
  }
  if (x > 0) {
    if (y > 0 && board[x - 1][y - 1] == '*')
    {
      label++;
    }
    if (board[x - 1][y] == '*')
    {
      label++;
    }
    if (y < side -1 && board[x - 1][y + 1] == '*')
    {
      label++;
    }
  }
  if (y > 0 && board[x][y - 1] == '*')
  {
    label++;
  }
  if (y < side -1 && board[x][y + 1] == '*')
  {
    label++;
  }
  if (x < side - 1) {
    if (y > 0 && board[x + 1][y - 1] == '*')
    {
      label++;
    }
    if (board[x + 1][y] == '*')
    {
      label++;
    }
    if (y < side -1 && board[x + 1][y + 1] == '*')
    {
      label++;
    }
  }
  board[x][y] = label > 0 ? label + '0' : ' ';
}

void addLabels(int side, char board[side][side])
{
  int i, j;
  for (int i = 0; i < side; i++)
  {
    for (int j = 0; j < side; j++)
    {
      addLabel(side, board, i, j);
    }
  }
}

int main(int argc, char const *argv[])
{
  char usage[] = "Como usar:\n\t%s <LADO>\n\n\tLADO\tIndica o tamanho do lado do tabuleiro maior que 1\n\t\tEx.: %s 5\n\n";
  if (argc > 1) {
    int side = atoi(argv[1]);
    if (side > 1) {
      char board[side][side];
      srand(time(NULL));
      createBoard(side, board);
      addBombs(side, board);
      addLabels(side, board);
      printBoard(side, board);
    }
    else {
      printf(usage, argv[0], argv[0]);
    }
  }
  else {
    printf(usage, argv[0], argv[0]);
  }
}
