// ponteiros_parte1.cpp

#include <iostream>

int A, B, C, D, E, F, G, H, I, J;

void ExibirDados(){
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
}

int main(void){
    std::cout << "Endereco e conteudo das variaveis ANTES de serem inicializadas." << std::endl;
    ExibirDados();

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
    ExibirDados();

    return 0;
}
