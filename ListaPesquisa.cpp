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

// Fun��o para trocar os dados de dois n�s
void swap(Node* a, Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

// Fun��o para ordenar a lista usando Bubble Sort
void bubbleSort(Node* head) {
    int swapped;
    Node* ptr1;
    Node* lptr = nullptr;

    // Caso a lista esteja vazia
    if (head == nullptr)
        return;

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

// Fun��o para pesquisar um elemento na lista
Node* search(Node* head, int data) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == data) {
            return current;
        }
        current = current->next;
    }
    return nullptr; // Retorna nullptr se o elemento n�o for encontrado
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

    // Ordenando a lista
    bubbleSort(head);

    // Imprimindo a lista e os endere�os dos n�s
    std::cout << "Lista ordenada:\n";
    printList(head);

    // Pedindo ao usu�rio para pesquisar um n�mero
    std::cout << "Digite o numero para pesquisar na lista:\n";
    std::cin >> num;
    Node* result = search(head, num);
    if (result != nullptr) {
        std::cout << "Numero " << num << " encontrado no endereco: " << result << std::endl;
    } else {
        std::cout << "Numero " << num << " nao encontrado na lista.\n";
    }

    // Liberando a mem�ria alocada para os n�s
    deleteList(head);

    return 0;
}
