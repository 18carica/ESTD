#include <iostream>

int vetor[10];

void ExibirDados(){
    std::cout << std::endl;
    std::cout << "A posicao 01: Endereco " << &vetor[0] << ", conteudo: " << vetor[0] << std::endl;
    std::cout << "A posicao 02: Endereco " << &vetor[1] << ", conteudo: " << vetor[1] << std::endl;
    std::cout << "A posicao 03: Endereco " << &vetor[2] << ", conteudo: " << vetor[2] << std::endl;
    std::cout << "A posicao 04: Endereco " << &vetor[3] << ", conteudo: " << vetor[3] << std::endl;
    std::cout << "A posicao 05: Endereco " << &vetor[4] << ", conteudo: " << vetor[4] << std::endl;
    std::cout << "A posicao 06: Endereco " << &vetor[5] << ", conteudo: " << vetor[5] << std::endl;
    std::cout << "A posicao 07: Endereco " << &vetor[6] << ", conteudo: " << vetor[6] << std::endl;
    std::cout << "A posicao 08: Endereco " << &vetor[7] << ", conteudo: " << vetor[7] << std::endl;
    std::cout << "A posicao 09: Endereco " << &vetor[8] << ", conteudo: " << vetor[8] << std::endl;
    std::cout << "A posicao 10: Endereco " << &vetor[9] << ", conteudo: " << vetor[9] << std::endl;
}

int main(void){
    std::cout << "Endereco e conteudo das posicoes do vetor ANTES de serem inicializadas." << std::endl;
    ExibirDados();

    std::cout << "\nAgora, insira os valores para as dez posicoes do vetor : " << std::endl;
    std::cout << "\nInsira o valor para a posicao 01: ";
    std::cin >> vetor[0];
    std::cout << "\nInsira o valor para a posicao 02: ";
    std::cin >> vetor[1];
    std::cout << "\nInsira o valor para a posicao 03: ";
    std::cin >> vetor[2];
    std::cout << "\nInsira o valor para a posicao 04: ";
    std::cin >> vetor[3];
    std::cout << "\nInsira o valor para a posicao 05: ";
    std::cin >> vetor[4];
    std::cout << "\nInsira o valor para a posicao 06: ";
    std::cin >> vetor[5];
    std::cout << "\nInsira o valor para a posicao 07: ";
    std::cin >> vetor[6];
    std::cout << "\nInsira o valor para a posicao 08: ";
    std::cin >> vetor[7];
    std::cout << "\nInsira o valor para a posicao 09: ";
    std::cin >> vetor[8];
    std::cout << "\nInsira o valor para a posicao 10: ";
    std::cin >> vetor[9];
    std::cout << std::endl;

    std::cout << "Endereco e conteudo das posicoes do vetor DEPOIS de serem inicializadas." << std::endl;
    ExibirDados();

    return 0;
}
