// para compilar este programa manualmente em linux:
// gcc -o tic-tac-toe tic-tac-toe.c tela.c tecla.c
// para executar:
// ./tic-tac-toe

#include "tela.h"
#include "tecla.h"

#include <stdio.h>
#include <stdbool.h>

#define LIN_MAX 20
#define COL_MAX 40

char verifica_ganhador(char w[3][3])
{

  // vitoria vertical e horizontal
  for (int i = 0; i < 3; i++)
  {
    if (w[0][i] == w[1][i] && w[1][i] == w[2][i] && w[0][i] != '\0')
      return w[0][i];
    if (w[i][0] == w[i][1] && w[i][1] == w[i][2] && w[i][0] != '\0')
      return w[i][0];
  }

  // vitoria diagonal
  if (w[0][0] == w[1][1] && w[1][1] == w[2][2] && w[0][0] != '\0')
  {
    return w[0][0];
  }
  else if (w[0][2] == w[1][1] && w[1][1] == w[2][0] && w[0][2] != '\0')
  {
    return w[0][2];
  }

  return 'N';
}

bool verifica_empate(char w[3][3]) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (w[i][j] == '\0') return false;
    }
  }
  return true;
}

void desenha_jogador(int lin, int col, char jogatual)
{
  tela_cor_normal();
  tela_lincol(lin * 2 + 12, col * 4 + 15);
  if (jogatual == 'X') {
    puts("✖️");
  } else {
    puts("🟣");
  }
  tela_lincol(10, 3);
  printf("Jogador atual: ");
  if (jogatual == 'X') {
    puts("✖️");
  } else {
    puts("🟣");
  }
}

void grava_xo_na_matriz(int lin, int col, char w[3][3], char jogador)
{
  if (w[lin][col] == '\0')
  {
    w[lin][col] = jogador;
  }
}

void desenha_tabuleiro(char w[3][3])
{
  //título
  tela_lincol(2, 2);
  printf("  ╔╗            ╔╗    ╔╗  ╔╗ ╔╗╔╗\n"); 
  tela_lincol(3, 2);
  printf("  ║║            ║║    ║╚╗╔╝║ ║║║║\n"); 
  tela_lincol(4, 2);
  printf("  ║╠══╦══╦══╗ ╔═╝╠══╗ ╚╗║║╔╩═╣║║╚═╦══╗\n"); 
  tela_lincol(5, 2);
  printf("╔╗║║╔╗║╔╗║╔╗║ ║╔╗║╔╗║  ║╚╝║║═╣║║╔╗║╔╗║\n"); 
  tela_lincol(6, 2);
  printf("║╚╝║╚╝║╚╝║╚╝║ ║╚╝║╔╗║  ╚╗╔╣║═╣╚╣║║║╔╗║\n"); 
  tela_lincol(7, 2);
  printf("╚══╩══╩═╗╠══╝ ╚══╩╝╚╝   ╚╝╚══╩═╩╝╚╩╝╚╝\n"); 
  tela_lincol(8, 2);
  printf("      ╔═╝║\n"); 
  tela_lincol(9, 2);
  printf("      ╚══╝"); 

  //tabuleiro
  tela_lincol(12, 15);
  printf("   ┃   ┃   \n");
  tela_lincol(13, 15);
  printf("━━━╋━━━╋━━━\n");
  tela_lincol(14, 15);
  printf("   ┃   ┃   \n");
  tela_lincol(15, 15);
  printf("━━━╋━━━╋━━━\n");
  tela_lincol(16, 15);
  printf("   ┃   ┃   \n");
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      tela_lincol(i * 2 + 12, j * 4 + 16);
      if (w[i][j] != '\0') {
        printf("%c", w[i][j]);
      } else {
        printf(" ");
      }
    }
  }
}

void contorno() {
  tela_cor_normal();
  tela_limpa();
  tela_cor_fundo(153, 50, 204);
  tela_lincol(1, 1);
  for (int i = 1; i <= COL_MAX; i++) {
    putchar(' ');
  }
  tela_lincol(LIN_MAX, 1);
  for (int i = 1; i <= COL_MAX; i++) { 
    putchar(' ');
  }
  for (int i = 2; i < LIN_MAX; i++) {
    tela_lincol(i, 1);
    putchar(' ');
    tela_lincol(i, COL_MAX);
    putchar(' ');
  }
  tela_cor_normal();
}

void exibe_mensagem(char* msg[])
{
  for (int i = 0; msg[i] != NULL; i++) {
    tela_lincol(LIN_MAX / 3 + i, 7);
    printf("%s", msg[i]);
  }
}

void exibe_ganhador(char ganhador, bool empate)
{
  char* msg_x[] = {
    "╔═╗╔═╗          ╔╗        ╔╗",
    "╚╗╚╝╔╝          ║║        ║║",
    " ╚╗╔╝  ╔══╦══╦═╗║╚═╦══╦╗╔╗║║",
    " ╔╝╚╗  ║╔╗║╔╗║╔╗╣╔╗║╔╗║║║║╚╝",
    "╔╝╔╗╚╗ ║╚╝║╔╗║║║║║║║╚╝║╚╝║╔╗",
    "╚═╝╚═╝ ╚═╗╠╝╚╩╝╚╩╝╚╩══╩══╝╚╝",
    "       ╔═╝║",
    "       ╚══╝", NULL
  };

  char* msg_o[] = {
    "╔═══╗          ╔╗        ╔╗",
    "║╔═╗║          ║║        ║║",
    "║║ ║║ ╔══╦══╦═╗║╚═╦══╦╗╔╗║║",
    "║║ ║║ ║╔╗║╔╗║╔╗╣╔╗║╔╗║║║║╚╝",
    "║╚═╝║ ║╚╝║╔╗║║║║║║║╚╝║╚╝║╔╗",
    "╚═══╝ ╚═╗╠╝╚╩╝╚╩╝╚╩══╩══╝╚╝",
    "      ╔═╝║",
    "      ╚══╝", NULL
  };

  char* msg_empate[] = {
    "╔═══╗        ╔╗    ╔╗",
    "║╔══╝       ╔╝╚╗   ║║",
    "║╚══╦╗╔╦══╦═╩╗╔╬══╗║║",
    "║╔══╣╚╝║╔╗║╔╗║║║║═╣╚╝",
    "║╚══╣║║║╚╝║╔╗║╚╣║═╣╔╗",
    "╚═══╩╩╩╣╔═╩╝╚╩═╩══╝╚╝",
    "       ║║",
    "       ╚╝", NULL
  };

  for (int i = 1; i <= LIN_MAX; i++) {
    contorno();
    if (ganhador == 'X') {
      exibe_mensagem(msg_x);
    } else if (ganhador == 'O') {
      exibe_mensagem(msg_o);
    } else if (empate) {
      exibe_mensagem(msg_empate);
    }
    for (int j = i; j <= LIN_MAX; j++) {
      tela_cor_fundo(255 - (i * LIN_MAX / 2), 50, 204);
      tela_lincol(j, 1);
      for (int k = 1; k <= COL_MAX; k++) {
        putchar(' ');
      }
    }
    if (tecla_le_char() == '\n') {
      break;
    }
    tela_atualiza();
  }
}

int main()
{
  // inicialização de variáveis que representam o estado do jogo
  char w[3][3]  = {{'\0'}};
  bool fim = false;
  int lin_jogador = 1;
  int col_jogador = 1;
  char jogador_atual = 'X';
  char ganhador = ' ';
  bool empate = false;

  // inicialização do programa
  tela_ini();
  tecla_ini();
  tela_mostra_cursor(false);

  // laço principal, onde uma partida é jogada
  while (!fim)
  {
    // alterações do estado à partir de entradas
    char c = tecla_le_char();
    if (c == 's' && lin_jogador < 2) lin_jogador++;
    if (c == 'w' && lin_jogador > 0) lin_jogador--;
    if (c == 'a' && col_jogador > 0) col_jogador--;
    if (c == 'd' && col_jogador < 2) col_jogador++;
    if (c == '\n' && w[lin_jogador][col_jogador] == '\0') {
      grava_xo_na_matriz(lin_jogador, col_jogador, w, jogador_atual);
      jogador_atual = (jogador_atual == 'X' ? 'O' : 'X');
    }

    // alterações do estado independentes das entradas
    tela_cor_normal();
    tela_limpa();
    ganhador = verifica_ganhador(w);
    empate = verifica_empate(w);
    if ((ganhador == 'X') || (ganhador == 'O') || (empate)) {
      fim = true;
    }
    
    // desenho da tela à partir do estado
    contorno();
    desenha_tabuleiro(w);
    desenha_jogador(lin_jogador, col_jogador, jogador_atual);
    tela_atualiza();
  }

  exibe_ganhador(ganhador, empate);

  // finalização do programa
  tecla_fim();
  tela_fim();
}