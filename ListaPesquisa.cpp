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

// Função para trocar os dados de dois nós
void swap(Node* a, Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

// Função para ordenar a lista usando Bubble Sort
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

// Função para pesquisar um elemento na lista
Node* search(Node* head, int data) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == data) {
            return current;
        }
        current = current->next;
    }
    return nullptr; // Retorna nullptr se o elemento não for encontrado
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

    // Ordenando a lista
    bubbleSort(head);

    // Imprimindo a lista e os endereços dos nós
    std::cout << "Lista ordenada:\n";
    printList(head);

    // Pedindo ao usuário para pesquisar um número
    std::cout << "Digite o numero para pesquisar na lista:\n";
    std::cin >> num;
    Node* result = search(head, num);
    if (result != nullptr) {
        std::cout << "Numero " << num << " encontrado no endereco: " << result << std::endl;
    } else {
        std::cout << "Numero " << num << " nao encontrado na lista.\n";
    }

    // Liberando a memória alocada para os nós
    deleteList(head);

    return 0;
}
