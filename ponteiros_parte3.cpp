// ponteiros_parte3.cpp

#include <iostream>

int matriz[2][5];

void ExibirDados(){
    std::cout << std::endl;
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 5; j++){
            std::cout << "A posicao " << i+1 << " e " << j+1 << " : Endereco " << &matriz[i][j] << ", conteudo: " << matriz[i][j] << std::endl;
        }
    }
}

int main(void){
    std::cout << "Endereco e conteudo das posicoes da matriz ANTES de serem inicializadas." << std::endl;
    ExibirDados();

    std::cout << "\nAgora, insira os valores para as dez posicoes do vetor : " << std::endl;

    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 5; j++){
            std::cout << "\nInsira o valor para a posicao " << i+1 << " " << j+1 <<": ";
            std::cin >> matriz[i][j];
        }
    }

    std::cout << "Endereco e conteudo das posicoes da matriz DEPOIS de serem inicializadas." << std::endl;
    ExibirDados();

    return 0;
}
