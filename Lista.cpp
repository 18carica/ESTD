#include <iostream>

// Defini��o da estrutura do n� da lista
struct Node {
    int data;
    Node* next;
};

// Fun��o para inserir um elemento de forma ordenada na lista
void insertSorted(Node*& head, int data) {
    Node* newNode = new Node(); // Criando um novo n�
    newNode->data = data;       // Atribuindo o valor

    // Caso especial: inser��o no in�cio da lista ou lista vazia
    if (head == nullptr || head->data >= data) {
        newNode->next = head;
        head = newNode;
    } else {
        // Localizando o n� antes do ponto de inser��o
        Node* current = head;
        while (current->next != nullptr && current->next->data < data) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Fun��o para imprimir a lista e os endere�os dos n�s
void printList(Node* head) {
    while (head != nullptr) {
        std::cout << "Endereco: " << head << " - Dado: " << head->data << std::endl;
        head = head->next;
    }
}

// Fun��o para liberar a mem�ria alocada para os n�s
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

    // Pedindo ao usu�rio para inserir os n�meros
    std::cout << "Digite os numeros para inserir na lista (digite -1 para parar):\n";
    while (true) {
        std::cin >> num;
        if (num == -1)
            break;
        insertSorted(head, num);
    }

    // Imprimindo a lista e os endere�os dos n�s
    std::cout << "Lista ordenada:\n";
    printList(head);

    // Liberando a mem�ria alocada para os n�s
    deleteList(head);

    return 0;
}
