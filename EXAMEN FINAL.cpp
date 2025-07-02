// abb.cpp — Árbol Binario de Decisión (Deporte) en un solo archivo compatible con DevC++ (C++98)
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// Inserta un nuevo nodo en el ABB
Node* insertNode(Node* root, int value) {
    if (root == NULL) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else if (value > root->data) {
        root->right = insertNode(root->right, value);
    }
    return root;
}

// Busca un valor en el ABB
bool searchNode(Node* root, int value) {
    if (root == NULL) return false;
    if (root->data == value) return true;
    if (value < root->data) return searchNode(root->left, value);
    return searchNode(root->right, value);
}

// Recorridos del árbol
void inOrder(Node* root) {
    if (root == NULL) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void preOrder(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node* root) {
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

// Mapea valor del nodo al mensaje de deporte
void printMessage(int v) {
    switch (v) {
        case 20: cout << "\tTe interesa el deporte\n"; break;
        case 12: cout << "\tPractica DEPORTES DE EQUIPO\n"; break;
        case 8:  cout << "\tPractica FÚTBOL\n"; break;
        case 15: cout << "\tPractica VOLEIBOL\n"; break;
        case 30: cout << "\tPractica DEPORTES INDIVIDUALES\n"; break;
        case 25: cout << "\tPractica NATACIÓN\n"; break;
        case 35: cout << "\tPractica TENIS\n"; break;
        default: cout << "\tValor no corresponde a un deporte\n"; break;
    }
}

// Recorre desde la raíz hasta el nodo buscado imprimiendo mensajes
void decision(Node* root, int value) {
    Node* curr = root;
    while (curr != NULL) {
        printMessage(curr->data);
        if (value == curr->data) {
            return;
        } else if (value < curr->data) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }
    cout << "\tNodo no encontrado en el árbol\n";
}

// Menú interactivo según consigna
int menu() {
    cout << "********************\n";
    cout << "Menu\n";
    cout << "1. Insertar nodo\n";
    cout << "2. Mostrar In-Order\n";
    cout << "3. Mostrar Pre-Order\n";
    cout << "4. Mostrar Post-Order\n";
    cout << "5. Decision\n";
    cout << "6. Salir\n";
    cout << "Seleccione opcion: ";
    int opt;
    cin >> opt;
    return opt;
}

int main() {
    Node* root = NULL;
    int opcion, valor;
    do {
        opcion = menu();
        switch (opcion) {
            case 1:
                cout << "Ingrese nodo: ";
                cin >> valor;
                if (searchNode(root, valor)) {
                    cout << "Elemento ya existía.\n";
                } else {
                    root = insertNode(root, valor);
                    cout << "Elemento No existía, se acaba de ingresar.\n";
                }
                break;
            case 2:
                cout << "ABB In-Order: ";
                inOrder(root);
                cout << "\n";
                break;
            case 3:
                cout << "ABB Pre-Order: ";
                preOrder(root);
                cout << "\n";
                break;
            case 4:
                cout << "ABB Post-Order: ";
                postOrder(root);
                cout << "\n";
                break;
            case 5:
                cout << "Ingrese valor a buscar: ";
                cin >> valor;
                decision(root, valor);
                break;
            case 6:
                cout << "Saliendo del programa.\n";
                break;
            default:
                cout << "Opcion no valida\n";
        }
    } while (opcion != 6);
    return 0;
}


