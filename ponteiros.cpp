// ponteiros.cpp

#include <iostream>

int A, B, C, D, E, F, G, H, I, J;
int vetor[10];
int matriz[2][5];

int ExibirDados(int n){
    switch(n){
    case 1:
        std::cout << std::endl;
        std::cout << "A: Endereco " << &A << ", conteudo: " << A << std::endl;
        std::cout << "B: Endereco " << &B << ", conteudo: " << B << std::endl;
        std::cout << "C: Endereco " << &C << ", conteudo: " << C << std::endl;
        std::cout << "D: Endereco " << &D << ", conteudo: " << D << std::endl;
        std::cout << "E: Endereco " << &E << ", conteudo: " << E << std::endl;
        std::cout << "F: Endereco " << &F << ", conteudo: " << F << std::endl;
        std::cout << "G: Endereco " << &G << ", conteudo: " << G << std::endl;
        std::cout << "H: Endereco " << &H << ", conteudo: " << H << std::endl;
        std::cout << "I: Endereco " << &I << ", conteudo: " << I << std::endl;
        std::cout << "J: Endereco " << &J << ", conteudo: " << J << std::endl;
        break;
    case 2:
        std::cout << std::endl;
        for (int i = 0; i < 10; ++i){
            std::cout << "A posicao " << i+1 << ": Endereco " << &vetor[i] << ", conteudo: " << vetor[i] << std::endl;
        }
        break;
    case 3:
        std::cout << std::endl;
        for (int i = 0; i < 2; i++){
            for (int j = 0; j < 5; j++){
                std::cout << "A posicao " << i+1 << " e " << j+1 << " : Endereco " << &matriz[i][j] << ", conteudo: " << matriz[i][j] << std::endl;
            }
        }
        break;
    default:
        std::cout << "\nERRO AO EXIBIR" << std::endl;
    }

    return 0;
}

int Ponteiro1(){
    std::cout << "Endereco e conteudo das variaveis ANTES de serem inicializadas." << std::endl;
    ExibirDados(1);

    std::cout << "\nAgora, insira os valores para as dez variaveis: " << std::endl;
    std::cout << "\nInsira o valor para o A: ";
    std::cin >> A;
    std::cout << "\nInsira o valor para o B: ";
    std::cin >> B;
    std::cout << "\nInsira o valor para o C: ";
    std::cin >> C;
    std::cout << "\nInsira o valor para o D: ";
    std::cin >> D;
    std::cout << "\nInsira o valor para o E: ";
    std::cin >> E;
    std::cout << "\nInsira o valor para o F: ";
    std::cin >> F;
    std::cout << "\nInsira o valor para o G: ";
    std::cin >> G;
    std::cout << "\nInsira o valor para o H: ";
    std::cin >> H;
    std::cout << "\nInsira o valor para o I: ";
    std::cin >> I;
    std::cout << "\nInsira o valor para o J: ";
    std::cin >> J;
    std::cout << std::endl;

    std::cout << "Endereco e conteudo das variaveis DEPOIS de serem inicializadas." << std::endl;
    ExibirDados(1);

    return 0;
}

int Ponteiro2(){
    std::cout << "Endereco e conteudo das posicoes do vetor ANTES de serem inicializadas." << std::endl;
    ExibirDados(2);

    std::cout << "\nAgora, insira os valores para as dez posicoes do vetor : " << std::endl;

    for (int i = 0; i < 10; ++i){
        std::cout << "\nInsira o valor para a posicao " << i+1 <<": ";
        std::cin >> vetor[i];
    }

    std::cout << std::endl;

    std::cout << "Endereco e conteudo das posicoes do vetor DEPOIS de serem inicializadas." << std::endl;
    ExibirDados(2);

    return 0;
}

int Ponteiro3(){
    std::cout << "Endereco e conteudo das posicoes da matriz ANTES de serem inicializadas." << std::endl;
    ExibirDados(3);

    std::cout << "\nAgora, insira os valores para as dez posicoes do vetor : " << std::endl;

    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 5; j++){
            std::cout << "\nInsira o valor para a posicao " << i+1 << " " << j+1 <<": ";
            std::cin >> matriz[i][j];
        }
    }

    std::cout << "Endereco e conteudo das posicoes da matriz DEPOIS de serem inicializadas." << std::endl;
    ExibirDados(3);

    return 0;
}

void MenuPonteiros(){
    std::cout << std::endl;
    std::cout << "____ MENU PONTEIROS ____" << std::endl;
    std::cout << "(1) PONTEIRO 1 \n(2) PONTEIRO 2 \n(3) PONTEIRO 3" << std::endl;
    std::cout << "(0) SAIR" << std::endl;
}

int main(void){
    MenuPonteiros();

    int n = 0;
    while (true){
        std::cout << "\nESCOLHA UMA OPCAO: ";
        std::cin >> n;

        switch (n){
            case 1:
                Ponteiro1();
                MenuPonteiros();
                break;
            case 2:
                Ponteiro2();
                MenuPonteiros();
                break;
            case 3:
                Ponteiro3();
                MenuPonteiros();
                break;
            case 0:
                std::cout << "Voltando ao Menu Principal..." << std::endl;
                return 0;
            default:
                std::cout << "Opcao invalida" << std::endl;
                MenuPonteiros();
        }
    }

    return 0;
}
