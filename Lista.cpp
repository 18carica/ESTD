#include <iostream>

// Definição da estrutura do nó da lista
struct Node {
    int data;
    Node* next;
};

// Função para inserir um elemento de forma ordenada na lista
void insertSorted(Node*& head, int data) {
    Node* newNode = new Node(); // Criando um novo nó
    newNode->data = data;       // Atribuindo o valor

    // Caso especial: inserção no início da lista ou lista vazia
    if (head == nullptr || head->data >= data) {
        newNode->next = head;
        head = newNode;
    } else {
        // Localizando o nó antes do ponto de inserção
        Node* current = head;
        while (current->next != nullptr && current->next->data < data) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Função para imprimir a lista e os endereços dos nós
void printList(Node* head) {
    while (head != nullptr) {
        std::cout << "Endereco: " << head << " - Dado: " << head->data << std::endl;
        head = head->next;
    }
}

// Função para liberar a memória alocada para os nós
void deleteList(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
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
        insertSorted(head, num);
    }

    // Imprimindo a lista e os endereços dos nós
    std::cout << "Lista ordenada:\n";
    printList(head);

    // Liberando a memória alocada para os nós
    deleteList(head);

    return 0;
}
