// menuETDD.cpp

#include <iostream>
using namespace std;

int Pilha[50];
int tamanhoPilha = 0;
int Fila[50];
int tamanhoFila = 0;

int MostrarFila(){
    if (tamanhoFila > 0 && tamanhoFila <= 50){
        if (tamanhoFila == 1) 
          cout << "\nO primeiro e unico item da fila é " << Fila[0] << "." << endl;
        else
          cout << "\nO primeiro e ultimo itens da fila são " << Fila[0] << " e " << Fila[tamanhoFila-1] << "." << endl;
    }
    else
        cout << "\nA fila esta vazia." << endl;
    return 0;
}

int RemFila(){
    if (tamanhoFila > 0 && tamanhoFila <= 50){
        //int posNum = 0;
        //cout << "\nInforme a posicao que deseja remover entre 1 e " << tamanhoFila << ": " << endl;
        //cin >> posNum;
      
        cout << "\nO valor " << Fila[0] << " foi removido da fila." << endl;
  
        for (int i = 0; i < 50; i++)
          Fila[i] = Fila[i+1];
          
        tamanhoFila--;

      if (tamanhoFila < 50)
          cout << "\nA fila tem " << 50 - (tamanhoFila) << " espacos livres." << endl;
      else
          cout << "\nA fila tem " << 50 - (tamanhoFila) << " espaco livre." << endl;
    }
    else
        cout << "\nNao tem nenhum item na fila." << endl;

    return 0;
}

int AddFila(){
    int numAdd = 0;
    if (tamanhoFila <= 50){
        cout << "\nInforme o valor que deseja adicionar: " << endl;
        cin >> numAdd;

        Fila[tamanhoFila] = numAdd;

        tamanhoFila++;

        cout << "\nO valor " << numAdd << " foi adicionado na posicao " << tamanhoFila << endl;
    }
    else
        cout << "\nNao ha espaco desponivel" << endl;
    return 0;
}

int MenuFila(){
    cout << endl;
    cout << "__ MENU FILA __" << endl;
    cout << "(1) ADICIONAR ITEM"<< endl;
    cout << "(2) REMOVER ITEM" << endl;
    cout << "(3) MOSTRAR PRIMEIRO E ULTIMO ITENS" << endl;
    cout << "(0) VOLTAR" << endl;

    return 0;
}

int OpcaoFila(){
    MenuFila();

    int n = 0;
    while (true){
        cout << "\nESCOLHA UMA OPCAO: ";
        cin >> n;

        switch (n){
            case 1:
                AddFila();
                MenuFila();
                break;
            case 2:
                RemFila();
                MenuFila();
                break;
            case 3:
                MostrarFila();
                MenuFila();
                break;
            case 0:
                cout << "Voltando ao Menu Principal..." << endl;
                return 0;
            default:
                cout << "Opcao invalida" << endl;
                MenuFila();
        }
    }
}

int MostrarPilha(){
    if (tamanhoPilha > 0)
        cout << "\nO topo da pilha e o valor " << Pilha[tamanhoPilha] << "." << endl;
    else
        cout << "\nA pilha esta vazia." << endl;
    return 0;
}

int RemPilha(){
    if (tamanhoPilha > 0 && tamanhoPilha <= 50){
        cout << "\nO valor " << Pilha[tamanhoPilha] << " foi removido da pilha." << endl;

        Pilha[tamanhoPilha] = 0;
        tamanhoPilha--;

        if (tamanhoPilha < 50)
            cout << "\nA pilha tem " << 50 - (tamanhoPilha) << " espacos livres." << endl;
        else
            cout << "\nA pilha tem " << 50 - (tamanhoPilha) << " espaco livre." << endl;
    }
    else
        cout << "\nNao tem nenhum item na pilha." << endl;

    return 0;
}

int AddPilha(){
    int numAdd = 0;
    if (tamanhoPilha <= 50){
        cout << "\nInforme o valor que deseja adicionar: " << endl;
        cin >> numAdd;

        tamanhoPilha++;

        Pilha[tamanhoPilha] = numAdd;

        cout << "\nO valor " << numAdd << " foi adicionado na posicao " << tamanhoPilha << endl;
    }
    else
        cout << "\nNao ha espaco desponivel" << endl;
    return 0;
}

int MenuPilha(){
    cout << endl;
    cout << "__ MENU PILHA __" << endl;
    cout << "(1) ADICIONAR ITEM"<< endl;
    cout << "(2) REMOVER ITEM" << endl;
    cout << "(3) MOSTRAR ULTIMO ITEM" << endl;
    cout << "(0) VOLTAR" << endl;

    return 0;
}

int OpcaoPilha(){
    MenuPilha();

    int n = 0;
    while (true){
        cout << "\nESCOLHA UMA OPCAO: ";
        cin >> n;

        switch (n){
            case 1:
                AddPilha();
                MenuPilha();
                break;
            case 2:
                RemPilha();
                MenuPilha();
                break;
            case 3:
                MostrarPilha();
                MenuPilha();
                break;
            case 0:
                cout << "Voltando ao Menu Principal..." << endl;
                return 0;
            default:
                cout << "Opcao invalida" << endl;
                MenuPilha();
        }
    }
}

int MenuPrin(){
    cout << endl;
    cout << "__ MENU __" << endl;
    cout << "(1) PILHA \n(2) FILA \n(3) VETORES E MATRIZES" << endl;
    cout << "(4) PROGRAMA 4 \n(5) PROGRAMA 5 \n(0) SAIR" << endl;

    return 0;
}

int main(void){
    MenuPrin();

    int n = 0;
    while (true){
        cout << "\nESCOLHA UMA OPCAO: ";
        cin >> n;

        switch (n){
            case 1:
                OpcaoPilha();
                MenuPrin();
                break;
            case 2:
                OpcaoFila();
                MenuPrin();
                break;
            case 3:
                cout << "o programa 3 foi escolhido" << endl;
                MenuPrin();
                break;
            case 4:
                cout << "o programa 4 foi escolhido" << endl;
                MenuPrin();
                break;
            case 5:
                cout << "o programa 5 foi escolhido" << endl;
                MenuPrin();
                break;
            case 0:
                cout << "\nSaindo do programa..." << endl;
                return 0;
            default:
                cout << "\nopcao invalida" << endl;
                MenuPrin();
        }
    }
}