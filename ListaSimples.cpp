#include <iostream>

// Defini��o da estrutura do n� da lista
struct Node {
    int data;
    Node* next;
};

// Fun��o para inserir um elemento no in�cio da lista
void insertAtBeginning(Node*& head, int data) {
    Node* newNode = new Node(); // Criando um novo n�
    newNode->data = data;       // Atribuindo o valor
    newNode->next = head;       // Apontando para o antigo primeiro n�
    head = newNode;             // Tornando o novo n� o primeiro n�
}

// Fun��o para imprimir a lista e os endere�os dos n�s
void printList(Node* head) {
    while (head != nullptr) {
        std::cout << "Endereco: " << head << " - Dado: " << head->data << std::endl;
        head = head->next;
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
        insertAtBeginning(head, num);
    }

    // Imprimindo a lista e os endere�os dos n�s
    std::cout << "Lista:\n";
    printList(head);

    return 0;
}
