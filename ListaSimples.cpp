#include <iostream>

// Definição da estrutura do nó da lista
struct Node {
    int data;
    Node* next;
};

// Função para inserir um elemento no início da lista
void insertAtBeginning(Node*& head, int data) {
    Node* newNode = new Node(); // Criando um novo nó
    newNode->data = data;       // Atribuindo o valor
    newNode->next = head;       // Apontando para o antigo primeiro nó
    head = newNode;             // Tornando o novo nó o primeiro nó
}

// Função para imprimir a lista e os endereços dos nós
void printList(Node* head) {
    while (head != nullptr) {
        std::cout << "Endereco: " << head << " - Dado: " << head->data << std::endl;
        head = head->next;
    }
}

int main() {
    Node* head = nullptr; // Inicializando a lista como vazia
    int num;

    // Pedindo ao usuário para inserir os números
    std::cout << "Digite os numeros para inserir na lista (digite -1 para parar):\n";
    while (true) {
        std::cin >> num;
        if (num == -1)
            break;
        insertAtBeginning(head, num);
    }

    // Imprimindo a lista e os endereços dos nós
    std::cout << "Lista:\n";
    printList(head);

    return 0;
}
