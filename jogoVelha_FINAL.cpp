// jogoVelha.cpp

#include <iostream>
#include <cstdlib>
using namespace std;

bool jogador2 = false;
char JogadorAtual = 'X';
int tabuleiro[3][3];
int countJogadas = 0;
char Nome1[20];
char Nome2[20];

int OpcaoBatalhaNaval() { return 0; }

int MostrarTabuleiro() {
  cout << "\n\n  1 2 3\n";

  for (int i = 0; i < 3; ++i) {
    cout << i + 1 << " ";

    for (int j = 0; j < 3; ++j) {

      if (tabuleiro[i][j] == 'X')
        cout << "X|";
      else if (tabuleiro[i][j] == 'O')
        cout << "O|";
      else
        cout << "_|";
    }
    cout << endl;
  }
  cout << endl;

  return 0;
}

int LimparTabuleiro() {
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j)
      tabuleiro[i][j] = 0;
  }

  return 0;
}

int CheckVencedor() {
  for (int i = 0; i < 3; ++i) {
    // linha X
    if (tabuleiro[i][0] == tabuleiro[i][1] &&
        tabuleiro[i][1] == tabuleiro[i][2] && tabuleiro[i][0] == 'X'){
      MostrarTabuleiro();
      cout << "\n\nVencedor: "<< Nome1 << "\n\n";
      return 1;
    }

    // linha O
    if (tabuleiro[i][0] == tabuleiro[i][1] &&
        tabuleiro[i][1] == tabuleiro[i][2] && tabuleiro[i][0] == 'O'){
      MostrarTabuleiro();
      if (jogador2 == true)
        cout << "\n\nVencedor: "<< Nome2 << "\n\n";
      else
        cout << "\n\nVencedor: Computador\n\n";
      return 1;
    }

    // coluna X
    if (tabuleiro[0][i] == tabuleiro[1][i] &&
        tabuleiro[1][i] == tabuleiro[2][i] && tabuleiro[0][i] == 'X'){
      MostrarTabuleiro();
      cout << "\n\nVencedor: " << Nome1 << "\n\n";
      return 1;
    }

    // coluna O
    if (tabuleiro[0][i] == tabuleiro[1][i] &&
        tabuleiro[1][i] == tabuleiro[2][i] && tabuleiro[0][i] == 'O'){
      MostrarTabuleiro();
      if (jogador2 == true)
        cout << "\n\nVencedor: "<< Nome2 << "\n\n";
      else
        cout << "\n\nVencedor: Computador\n\n";
      return 1;
    }
  }
  // diagonal X
  if (tabuleiro[0][0] == tabuleiro[1][1] &&
          tabuleiro[1][1] == tabuleiro[2][2] &&
          tabuleiro[0][0] == 'X' ||
      tabuleiro[0][2] == tabuleiro[1][1] &&
          tabuleiro[1][1] == tabuleiro[2][0] &&
          tabuleiro[0][2] == 'X') {
    MostrarTabuleiro();
    cout << "\n\nVencedor: " << Nome1 << "\n\n";
    return 1;
  }

  // diagonal O
  if (tabuleiro[0][0] == tabuleiro[1][1] &&
          tabuleiro[1][1] == tabuleiro[2][2] &&
          tabuleiro[0][0] == 'O' ||
      tabuleiro[0][2] == tabuleiro[1][1] &&
          tabuleiro[1][1] == tabuleiro[2][0] &&
          tabuleiro[0][2] == 'O') {
    MostrarTabuleiro();
    if (jogador2 == true)
      cout << "\n\nVencedor: "<< Nome2 << "\n\n";
    else
      cout << "\n\nVencedor: Computador\n\n";
    return 1;
  }

  return 0;
}

int CheckEmpate() {
  if (countJogadas == 9){
    MostrarTabuleiro();
    cout << "\nDeu velha!\n";
    return 1;
  }
  return 0;
}

int JogadaRobo() {
  int posL = 0;
  int posC = 0;

  posL = rand()%3;
  posC = rand()%3;

  while (tabuleiro[posL][posC] != 0){
    posL = rand()%3;
    posC = rand()%3;
  }

  tabuleiro[posL][posC] = JogadorAtual;

  return 0;
}

int IniciarJogo() {
  int l = 0; // variavel da linha
  int c = 0; // variavel da coluna
  int x = 0; // variavel temporaria
  JogadorAtual = 'X';
  countJogadas = 0;

  LimparTabuleiro();

  while (true) {
    MostrarTabuleiro();

    if (JogadorAtual == 'X')
      cout << "\nVez do jogador " << JogadorAtual << ", " << Nome1 << endl;
    else
      cout << "\nVez do jogador " << JogadorAtual << ", " << Nome2 << endl;

    x = 0;
    while (x < 1 || x > 3) {
      cout << "\nDigite a linha: ";
      cin >> x;
      if (x < 1 || x > 3 || cin.fail())
        cout << "\nPosição inválida. Tente novamente." << endl;
      else
        l = x - 1;
    }

    x = 0;
    while (x < 1 || x > 3) {
      cout << "\nDigite a coluna: ";
      cin >> x;
      if (x < 1 || x > 3 || cin.fail())
        cout << "\nPosição inválida. Tente novamente." << endl;
      else
        c = x - 1;
    }

    tabuleiro[l][c] = JogadorAtual;
    countJogadas++;

    // operador ternario
    JogadorAtual = (JogadorAtual == 'X') ? 'O' : 'X';

    if (CheckVencedor() || CheckEmpate())
      break;

    if (jogador2 != true && JogadorAtual == 'O'){
      cout << "\n\nVez do jogador " << JogadorAtual << ", COMPUTADOR\n";
      JogadaRobo();
      if (CheckVencedor() || CheckEmpate())
        break;
      JogadorAtual = (JogadorAtual == 'X') ? 'O' : 'X';
    }
  }

  return 0;
}

int RegistrarJogador() {
  cout << endl;
  cout << "Digite o nome do jogador 1: ";
  cin >> Nome1;

  if (jogador2 == true) {
    cout << endl;
    cout << "Digite o nome do jogador 2: ";
    cin >> Nome2;
  }

  cout << endl;
  cout << "Iniciando JOGO DA VELHA...\n\n";

  return 0;
}

int MenuJogoVelha() {
  cout << endl;
  cout << "===========================" << endl;
  cout << "      JOGO  DA  VELHA      " << endl;
  cout << "===========================" << endl;

  cout << "\nEscolha uma Opcao:" << endl;
  cout << "1 - PvC" << endl;
  cout << "2 - PvP" << endl;
  cout << "0 - Sair" << endl;
  cout << endl;

  return 0;
}

int OpcaoJogoVelha() {
  int n = 0;

  while (true) {
    MenuJogoVelha();
    cout << "\nESCOLHA UMA OPCAO: ";
    cin >> n;

    switch (n) {
    case 1:
      jogador2 = false;
      RegistrarJogador();
      IniciarJogo();
      break;
    case 2:
      jogador2 = true;
      RegistrarJogador();
      IniciarJogo();
      break;
    case 0:
      cout << "\n\nVoltando ao Menu Vetores e Matrizes..." << endl;
      return 0;
    default:
      cout << "\nOpcao invalida" << endl;
    }
  }
  return 0;
}

int MenuVetorMatriz() {
  cout << endl;
  cout << "__ MENU VETORES E MATRIZES __" << endl;
  cout << "(1) JOGO DA VELHA" << endl;
  cout << "(2) BATALHA NAVAL" << endl;
  cout << "(0) SAIR PARA O MENU PRINCIPAL" << endl;
  cout << endl;

  return 0;
}

int main(void) {
  MenuVetorMatriz();

  int n = 0;
  while (true) {
    cout << "\nESCOLHA UMA OPCAO: ";
    cin >> n;

    switch (n) {
    case 1:
      OpcaoJogoVelha();
      MenuVetorMatriz();
      break;
    case 2:
      OpcaoBatalhaNaval();
      MenuVetorMatriz();
      break;
    case 0:
      cout << "\n\nVoltando ao Menu Principal..." << endl;
      MenuVetorMatriz();
      return 0;
    default:
      cout << "\nOpcao invalida" << endl;
      MenuVetorMatriz();
    }
  }

  return 0;
}
