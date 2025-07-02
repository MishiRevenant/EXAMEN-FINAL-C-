// abb.cpp — Árbol Binario de Búsqueda compatible con Dev C++
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
    if (value == root->data) return true;
    if (value < root->data) return searchNode(root->left, value);
    return searchNode(root->right, value);
}

// Recorridos
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

// Función de decisión: camino desde la raíz hasta el valor buscado
void decision(Node* root, int value) {
    if (root == NULL) return;
    cout << root->data;
    if (root->data == value) {
        cout << " -> Decision final" << endl;
        return;
    }
    if (value < root->data && root->left != NULL) {
        cout << " -> ";
        decision(root->left, value);
    } else if (value > root->data && root->right != NULL) {
        cout << " -> ";
        decision(root->right, value);
    } else {
        cout << " -> No encontrado" << endl;
    }
}

int menu() {
    cout << "********************" << endl;
    cout << "1. Insertar nodo" << endl;
    cout << "2. Buscar nodo" << endl;
    cout << "3. Mostrar In-Order" << endl;
    cout << "4. Mostrar Pre-Order" << endl;
    cout << "5. Mostrar Post-Order" << endl;
    cout << "6. Decision" << endl;
    cout << "0. Salir" << endl;
    cout << "Seleccione una opcion: ";
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
                cout << "Valor a insertar: ";
                cin >> valor;
                root = insertNode(root, valor);
                break;
            case 2:
                cout << "Valor a buscar: ";
                cin >> valor;
                cout << (searchNode(root, valor) ? "Encontrado" : "No encontrado") << endl;
                break;
            case 3:
                cout << "ABB In-Order: ";
                inOrder(root);
                cout << endl;
                break;
            case 4:
                cout << "ABB Pre-Order: ";
                preOrder(root);
                cout << endl;
                break;
            case 5:
                cout << "ABB Post-Order: ";
                postOrder(root);
                cout << endl;
                break;
            case 6:
                cout << "Decision (camino): ";
                cin >> valor;
                decision(root, valor);
                break;
            case 0:
                cout << "Adios" << endl;
                break;
            default:
                cout << "Opcion no valida" << endl;
        }
    } while (opcion != 0);
    return 0;
}

