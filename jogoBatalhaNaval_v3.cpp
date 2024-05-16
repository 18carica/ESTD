// jogoBatalhaNaval_v2.cpp

#include <iostream>
#include <cstdlib>
using namespace std;

bool jogador2 = false;
int JogadorAtual = 1;
int tabJog1Navios[6][6];
int tabJog1Jogadas[6][6];
int tabJog2Navios[6][6];
int tabJog2Jogadas[6][6];
char Nome1[20];
char Nome2[20];
int QuantNavJ1 = 0;
int QuantNavJ2 = 0;

#define OCUPADO -3
#define FOGO -2
#define NADA -1
#define AGUA 0
#define Navio1 1
#define Navio2 2
#define Navio3 3
#define Navio4 4

int J1Nav2 = 0; int J1Nav3 = 0; int J1Nav4 = 0;
int J2Nav2 = 0; int J2Nav3 = 0; int J2Nav4 = 0;

int GuardarInfoJogadas(){
  int infoPos = 0;

  for (int i = 0; i < 6; ++i){
    for (int j = 0; j < 6; ++j){

      if (JogadorAtual == 1){

        if (tabJog1Jogadas[i][j] == OCUPADO){
          if (tabJog2Navios[i][j] != NADA){
            infoPos = tabJog2Navios[i][j];

            switch(infoPos){
            case 1:
              tabJog1Jogadas[i][j] = FOGO;
              QuantNavJ2--;
              tabJog2Navios[i][j] = FOGO;
              cout << "\n\nNavio tipo 1 do jogador 2 foi destruido!\n";
              break;
            case 2:
              tabJog1Jogadas[i][j] = FOGO;
              QuantNavJ2--;
              tabJog2Navios[i][j] = FOGO;
              J2Nav2++;
              if ((J2Nav2 % 2) == 0)
                cout << "\n\nNavio tipo 2 do jogador 2 foi destruido!\n";
              break;
            case 3:
              tabJog1Jogadas[i][j] = FOGO;
              QuantNavJ2--;
              tabJog2Navios[i][j] = FOGO;
              J2Nav3++;
              if ((J2Nav3 % 3) == 0)
                cout << "\n\nNavio tipo 3 do jogador 2 foi destruido!\n";
              break;
            case 4:
              tabJog1Jogadas[i][j] = FOGO;
              QuantNavJ2--;
              tabJog2Navios[i][j] = FOGO;
              J2Nav4++;
              if ((J2Nav4 % 4) == 0)
                cout << "\n\nNavio tipo 4 do jogador 2 foi destruido!\n";
              break;
            default:
              tabJog1Jogadas[i][j] = AGUA;
              tabJog2Navios[i][j] = AGUA;
            }
          }
          else{
            tabJog1Jogadas[i][j] = AGUA;
            tabJog2Navios[i][j] = AGUA;
          }
        }
      }
      else{

        if (tabJog2Jogadas[i][j] == OCUPADO){
          if (tabJog1Navios[i][j] != NADA){
            infoPos = tabJog1Navios[i][j];

            switch(infoPos){
            case 1:
              tabJog2Jogadas[i][j] = FOGO;
              QuantNavJ1--;
              tabJog1Navios[i][j] = FOGO;
              cout << "\n\nNavio tipo 1 do jogador 1 foi destruido!\n";
              break;
            case 2:
              tabJog2Jogadas[i][j] = FOGO;
              QuantNavJ1--;
              tabJog1Navios[i][j] = FOGO;
              J1Nav2++;
              if ((J1Nav2 % 2) == 0)
                cout << "\n\nNavio tipo 2 do jogador 1 foi destruido!\n";
              break;
            case 3:
              tabJog2Jogadas[i][j] = FOGO;
              QuantNavJ1--;
              tabJog1Navios[i][j] = FOGO;
              J1Nav3++;
              if ((J1Nav3 % 3) == 0)
                cout << "\n\nNavio tipo 3 do jogador 1 foi destruido!\n";
              break;
            case 4:
              tabJog2Jogadas[i][j] = FOGO;
              QuantNavJ1--;
              tabJog1Navios[i][j] = FOGO;
              J1Nav4++;
              if ((J1Nav4 % 4) == 0)
                cout << "\n\nNavio tipo 4 do jogador 1 foi destruido!\n";
              break;
            default:
              tabJog2Jogadas[i][j] = AGUA;
              tabJog1Navios[i][j] = AGUA;
            }
          }
          else{
            tabJog2Jogadas[i][j] = AGUA;
            tabJog1Navios[i][j] = AGUA;
          }
        }
      }
    }
  }
  return 0;
}

int checkPosiJogadas(int l, int c){
  if (JogadorAtual == 1){
    if (tabJog1Jogadas[l][c] != NADA){
      cout << "\nPosicao OCUPADA. Tente novamente." << endl;
      return 0;
    }
    else{
      tabJog1Jogadas[l][c] = OCUPADO;
      return 1;
    }
  }
  else{
    if (tabJog2Jogadas[l][c] != NADA){
      cout << "\nPosicao OCUPADA. Tente novamente." << endl;
      return 0;
    }
    else{
      tabJog2Jogadas[l][c] = OCUPADO;
      return 1;
    }
  }
}

int RegistrarJogadas(){
  int l = 0; // variavel da linha
  int c = 0; // variavel da coluna
  int x = 0; // variavel temporaria

  do{
    while (x < 1 || x > 6){
      cout << "\nDigite a linha: ";
      cin >> x;
      if (x < 1 || x > 6 || cin.fail())
        cout << "\nPosicao invalida. Tente novamente." << endl;
      else{
        l = x - 1;
        break;
      }
    }

    x = 0;

    while(x < 1 || x > 6){
      cout << "\nDigite a coluna: ";
      cin >> x;
      if (x < 1 || x > 6 || cin.fail())
        cout << "\nPosicao invalida. Tente novamente." << endl;
      else{
        c = x - 1;
        break;
      }
    }

  }while (!(checkPosiJogadas(l,c)));

  return 0;
}

int LimparTabuleiros(){
  for (int i = 0; i < 6; ++i) {
    for (int j = 0; j < 6; ++j){
      tabJog1Navios[i][j] = NADA;
      tabJog1Jogadas[i][j] = NADA;
      tabJog2Navios[i][j] = NADA;
      tabJog2Jogadas[i][j] = NADA;
    }
  }

  return 0;
}

int CheckVencedor(){
  if (QuantNavJ2 == 0){
    cout << "\nTODOS OS NAVIOS DO JOGADOR 2 FORAM DESTRUIDOS!\n";
    cout << "O jogador " << Nome1 << " VENCEU!!\n\n";

    return 1;
  }
  else if(QuantNavJ1 == 0){
    cout << "\nTODOS OS NAVIOS DO JOGADOR 1 FORAM DESTRUIDOS!\n";
    cout << "O jogador " << Nome2 << " VENCEU!!\n\n";

    return 1;
  }
  else
    return 0;
}

int MostrarTabuleiros(){
  if (JogadorAtual == 1){
    cout << "\nNavios do Jogador 1: " << Nome1 << endl;
    cout << "\n  1 2 3 4 5 6\n";

    for (int i = 0; i < 6; ++i){
      cout << i + 1 << " ";
      for (int j = 0; j < 6; ++j){

        if (tabJog1Navios[i][j] == NADA)
          cout << "  ";
        else if (tabJog1Navios[i][j] == AGUA)
          cout << "O ";
        else if (tabJog1Navios[i][j] == FOGO)
          cout << "X ";
        else if (tabJog1Navios[i][j] == Navio1)
          cout << "1 ";
        else if (tabJog1Navios[i][j] == Navio2)
          cout << "2 ";
        else if (tabJog1Navios[i][j] == Navio3)
          cout << "3 ";
        else if (tabJog1Navios[i][j] == Navio4)
          cout << "4 ";
      }
      cout << "\n";
    }
    cout << endl;
    cout << "\nJogadas disponiveis"<< endl;
    cout << "\n  1 2 3 4 5 6\n";

    for (int i = 0; i < 6; ++i){
      cout << i + 1 << " ";
      for (int j = 0; j < 6; ++j){

        if (tabJog1Jogadas[i][j] == NADA)
          cout << "  ";
        else if (tabJog1Jogadas[i][j] == AGUA)
          cout << "O ";
        else if (tabJog1Jogadas[i][j] == FOGO)
          cout << "X ";
      }
      cout << "\n";
    }
    cout << endl;
  }
  else{
    cout << "\nNavios do Jogador 2: " << Nome2 << endl;
    cout << "\n  1 2 3 4 5 6\n";

    for (int i = 0; i < 6; ++i){
      cout << i + 1 << " ";
      for (int j = 0; j < 6; ++j){

        if (tabJog2Navios[i][j] == NADA)
          cout << "  ";
        else if (tabJog2Navios[i][j] == AGUA)
          cout << "O ";
        else if (tabJog2Navios[i][j] == FOGO)
          cout << "X ";
        else if (tabJog2Navios[i][j] == Navio1)
          cout << "1 ";
        else if (tabJog2Navios[i][j] == Navio2)
          cout << "2 ";
        else if (tabJog2Navios[i][j] == Navio3)
          cout << "3 ";
        else if (tabJog2Navios[i][j] == Navio4)
          cout << "4 ";
      }
      cout << "\n";
    }
    cout << endl;
    cout << "\nJogadas disponiveis"<< endl;
    cout << "\n  1 2 3 4 5 6\n";

    for (int i = 0; i < 6; ++i){
      cout << i + 1 << " ";
      for (int j = 0; j < 6; ++j){

        if (tabJog2Jogadas[i][j] == NADA)
          cout << "  ";
        else if (tabJog2Jogadas[i][j] == AGUA)
          cout << "O ";
        else if (tabJog2Jogadas[i][j] == FOGO)
          cout << "X ";
      }
      cout << "\n";
    }
    cout << endl;
  }

  return 0;
}

int MostrarTabInicio(){
  if (JogadorAtual == 1){
    cout << "\nNavios do Jogador 1: " << Nome1 << endl;
    cout << "\n  1 2 3 4 5 6\n";

    for (int i = 0; i < 6; ++i){
      cout << i + 1 << " ";
      for (int j = 0; j < 6; ++j){

        if (tabJog1Navios[i][j] == NADA)
          cout << "  ";
        else if (tabJog1Navios[i][j] == Navio1)
          cout << "1 ";
        else if (tabJog1Navios[i][j] == Navio2)
          cout << "2 ";
        else if (tabJog1Navios[i][j] == Navio3)
          cout << "3 ";
        else if (tabJog1Navios[i][j] == Navio4)
          cout << "4 ";
      }
      cout << "\n";
    }
  }
  if (JogadorAtual == 2 && jogador2 == true){
    cout << "\nNavios do Jogador 2: " << Nome2 << endl;
    cout << "\n  1 2 3 4 5 6\n";

    for (int i = 0; i < 6; ++i){
      cout << i + 1 << " ";
      for (int j = 0; j < 6; ++j){

        if (tabJog2Navios[i][j] == NADA)
          cout << "  ";
        else if (tabJog2Navios[i][j] == Navio1)
          cout << "1 ";
        else if (tabJog2Navios[i][j] == Navio2)
          cout << "2 ";
        else if (tabJog2Navios[i][j] == Navio3)
          cout << "3 ";
        else if (tabJog2Navios[i][j] == Navio4)
          cout << "4 ";
      }
      cout << "\n";
    }
  }
  return 0;
}

int checkPosiPecas(int l, int c){
  if (JogadorAtual == 1){
    if (tabJog1Navios[l][c] != NADA){
      cout << "\nPosicao OCUPADA. Tente novamente." << endl;
      return 0;
    }
    else{
      return 1;
    }
  }
  else{
    if (tabJog2Navios[l][c] != NADA){
      cout << "\nPosicao OCUPADA. Tente novamente." << endl;
      return 0;
    }
    else{
      return 1;
    }
  }
}

int RegistrarPecas(int n){
  int l = 0; // variavel da linha
  int c = 0; // variavel da coluna
  int x = 0; // variavel temporaria

  cout << "\nEscolha a posicao inicial da peca:\n";

  do{
    while (x < 1 || x > 6){
      cout << "\nDigite a linha: ";
      cin >> x;
      if (x < 1 || x > 6 || cin.fail())
        cout << "\nPosicao invalida. Tente novamente." << endl;
      else{
        l = x - 1;
        break;
      }
    }

    x = 0;
    while(x < 1 || x > 6){
      cout << "\nDigite a coluna: ";
      cin >> x;
      if (x < 1 || x > 6 || cin.fail())
        cout << "\nPosicao invalida. Tente novamente." << endl;
      else{
        c = x - 1;
        break;
      }
    }
  }while (!(checkPosiPecas(l,c)));

  if (n != 1){
    int direcao = 0;
    cout << "\nDirecoes:" << endl;
    cout << "\n(1) Direita\n(2) Esquerda";
    cout << "\n(3) Cima\n(4) Baixo\n";

    cout << "\nQual direcao deseja adicionar a peca: ";
    cin >> direcao;

    switch(direcao){
      case 1:
        for (int i = 0; i < n; i++){
          if (c+n <= 6){
            if (checkPosiPecas[l][c+i]){
              if (JogadorAtual == 1)
                tabJog1Navios[l][c+i] = n;
              else
                tabJog2Navios[l][c+i] = n;
            }
            else{
              cout << "\nNao pode colocar uma peca em cima da outra." << endl;
              break;
            }
          }
          else{
            cout << "\nA Peca nao pode ir nessa direcao." << endl;
            break;
          }
        }
        break;
      case 2:
        for (int i = 0; i < n; i++){
          if (c-n >= -1){
            if (checkPosiPecas[l][c-i]){
              if (JogadorAtual == 1)
                tabJog1Navios[l][c-i] = n;
              else
                tabJog2Navios[l][c-i] = n;
            }
            else{
              cout << "\nNao pode colocar uma peca em cima da outra." << endl;
              break;
            }
          }
          else{
            cout << "\nA Peca nao pode ir nessa direcao." << endl;
            break;
          }
        }
        break;
      case 3:
        for (int i = 0; i < n; i++){
          if (l-n >= -1){
            if (checkPosiPecas[l-i][c]){
              if (JogadorAtual == 1)
                tabJog1Navios[l-i][c] = n;
              else
                tabJog2Navios[l-i][c] = n;
            }
            else{
              cout << "\nNao pode colocar uma peca em cima da outra." << endl;
              break;
            }
          }
          else{
            cout << "\nA Peca nao pode ir nessa direcao." << endl;
            break;
          }
        }
        break;
      case 4:
        for (int i = 0; i < n; i++){
          if (l+n <= 6){
            if (checkPosiPecas[l+i][c]){
              if (JogadorAtual == 1)
                tabJog1Navios[l+i][c] = n;
              else
                tabJog2Navios[l+i][c] = n;
            }
            else{
              cout << "\nNao pode colocar uma peca em cima da outra." << endl;
              break;
            }
          }
          else{
            cout << "\nA Peca nao pode ir nessa direcao." << endl;
            break;
          }
        }
        break;
      default:
        cout << "\nOpcao invalida. Tente novamente.";
    }
  }
  else{
    if (JogadorAtual == 1)
      tabJog1Navios[l][c] = n;
    else
      tabJog2Navios[l][c] = n;
  }

  return 0;
}

int MenuPecas(){
  cout << endl;
  cout << "TIPO 1 - 1" << endl;
  cout << "TIPO 2 - 22" << endl;
  cout << "TIPO 3 - 333" << endl;
  cout << "TIPO 4 - 4444" << endl;
  cout << endl;

  return 0;
}

int PosiPecas(){
  int pecas = 0;
  int n = 0;

  while(true){
    MenuPecas();
    cout << "\nESCOLHA UMA OPCAO: ";
    cin >> n;

    MostrarTabInicio();

    switch (n){
    case 1:
      if (JogadorAtual == 1)
        QuantNavJ1++;
      else
        QuantNavJ2++;
      RegistrarPecas(1);
      pecas++;
      break;
    case 2:
      if (JogadorAtual == 1)
        QuantNavJ1+=2;
      else
        QuantNavJ2+=2;
      RegistrarPecas(2);
      pecas++;
      break;
    case 3:
      if (JogadorAtual == 1)
        QuantNavJ1+=3;
      else
        QuantNavJ2+=3;
      RegistrarPecas(3);
      pecas++;
      break;
    case 4:
      if (JogadorAtual == 1)
        QuantNavJ1+=4;
      else
        QuantNavJ2+=4;
      RegistrarPecas(4);
      pecas++;
      break;
    default:
      cout << "\nOpcao invalida" << endl;
    }

    if (pecas == 4)
      break;
  }

  return 0;
}

int IniciarJogo(){
  JogadorAtual = 1;
  LimparTabuleiros();

  cout << "\nJogador 1 deve selecionar as posicoes da suas pecas.\n";
  PosiPecas();
  cout << "\n\n";

  if (jogador2 == true){
    cout << "\nJogador 2 deve selecionar as posicoes da suas pecas.\n";
    JogadorAtual = 2;
    PosiPecas();
    JogadorAtual = 1;
    cout << "\n\n";
  }

  while(true){
    MostrarTabuleiros();

    if (JogadorAtual == 1)
      cout << "\nVez do jogador 1: " << Nome1 << endl;
    else
      cout << "\nVez do jogador 2: " << Nome2 << endl;

    RegistrarJogadas();
    GuardarInfoJogadas();

    JogadorAtual = (JogadorAtual == 1) ? 2 : 1;

    if (CheckVencedor())
      break;


    if (jogador2 != true && JogadorAtual == 2){
      cout << "\nVez do jogador 2: COMPUTADOR" << endl;
      //JogadaRobo();
      if (CheckVencedor())
        break;
      else
        JogadorAtual = (JogadorAtual == 1) ? 2 : 1;
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
  cout << "Iniciando BATALHA NAVAL...\n\n";

  return 0;
}

int MenuBatalhaNaval() {
  cout << endl;
  cout << "===========================" << endl;
  cout << "       BATALHA NAVAL       " << endl;
  cout << "===========================" << endl;

  cout << endl;
  cout << "1 - PvC" << endl;
  cout << "2 - PvP" << endl;
  cout << "0 - Sair" << endl;
  cout << endl;

  return 0;
}

int OpcaoBatalhaNaval() {
  int n = 0;

  while (true) {
    MenuBatalhaNaval();
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

int OpcaoJogoVelha() { return 0; }

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
