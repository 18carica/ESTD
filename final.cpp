int MenuVetoresMatrizes() {
    cout << endl;
    cout << "__ MENU VETORES E MATRIZES __" << endl;
    cout << "(1) Jogo da Velha" << endl;
    cout << "(2) Batalha Naval" << endl;
    cout << "(0) VOLTAR" << endl;
    return 0;
}

int MenuPonteiros() {
    cout << endl;
    cout << "__ MENU PONTEIROS __" << endl;
    cout << "(1) Variável" << endl;
    cout << "(2) Vetor" << endl;
    cout << "(3) Matriz" << endl;
    cout << "(0) VOLTAR" << endl;
    return 0;
}

int MenuLista() {
    cout << endl;
    cout << "__ MENU LISTA __" << endl;
    cout << "(1) Lista 1" << endl;
    cout << "(2) Lista 2" << endl;
    cout << "(3) Lista 3" << endl;
    cout << "(4) Lista 4" << endl;
    cout << "(5) Lista 5" << endl;
    cout << "(0) VOLTAR" << endl;
    return 0;
}

int OpcaoPrin() {
    MenuPrin();
    int n = 0;
    while (true) {
        cout << "\nESCOLHA UMA OPCAO: ";
        cin >> n;

        switch (n) {
            case 1:
                OpcaoPilha();
                MenuPrin();
                break;
            case 2:
                OpcaoFila();
                MenuPrin();
                break;
            case 3:
                int opcaoVetoresMatrizes;
                do {
                    opcaoVetoresMatrizes = 0;
                    MenuVetoresMatrizes();
                    cout << "\nESCOLHA UMA OPCAO: ";
                    cin >> opcaoVetoresMatrizes;

                    switch (opcaoVetoresMatrizes) {
                        case 1:
                            // Implement Jogo da Velha logic
                            cout << "Jogo da Velha selecionado." << endl;
                            break;
                        case 2:
                            // Implement Batalha Naval logic
                            cout << "Batalha Naval selecionado." << endl;
                            break;
                        case 0:
                            break;
                        default:
                            cout << "Opcao invalida" << endl;
                    }
                } while (opcaoVetoresMatrizes != 0);
                break;
            case 4:
                int opcaoPonteiros;
                do {
                    opcaoPonteiros = 0;
                    MenuPonteiros();
                    cout << "\nESCOLHA UMA OPCAO: ";
                    cin >> opcaoPonteiros;

                    switch (opcaoPonteiros) {
                        case 1:
                            // Implement Variável Ponteiro logic
                            cout << "Variável selecionada." << endl;
                            break;
                        case 2:
                            // Implement Vetor Ponteiro logic
                            cout << "Vetor selecionado." << endl;
                            break;
                        case 3:
                            // Implement Matriz Ponteiro logic
                            cout << "Matriz selecionada." << endl;
                            break;
                        case 0:
                            break;
                        default:
                            cout << "Opcao invalida" << endl;
                    }
                } while (opcaoPonteiros != 0);
                break;
            case 5:
                int opcaoLista;
                do {
                    opcaoLista = 0;
                    MenuLista();
                    cout << "\nESCOLHA UMA OPCAO: ";
                    cin >> opcaoLista;

                    switch (opcaoLista) {
                        case 1:
                            // Implement Lista 1 logic
                            cout << "Lista 1 selecionada." << endl;
                            break;
                        case 2:
                            // Implement Lista 2 logic
                            cout << "Lista 2 selecionada." << endl;
                            break;
                        case 3:
                            // Implement Lista 3 logic
                            cout << "Lista 3 selecionada." << endl;
                            break;
                        case 4:
                            // Implement Lista 4 logic
                            cout << "Lista 4 selecionada." << endl;
                            break;
                        case 5:
                            // Implement Lista 5 logic
                            cout << "Lista 5 selecionada." << endl;
                            break;
                        case 0:
                            break;
                        default:
                            cout << "Opcao invalida" << endl;
                    }
                } while (opcaoLista != 0);
                break;
            case 0:
                cout << "\nSaindo do programa..." << endl;
                return 0;
            default:
                cout << "\nOpcao invalida" << endl;
                MenuPrin();
        }
    }
}

int main(void) {
    OpcaoPrin();
    return 0;
}
