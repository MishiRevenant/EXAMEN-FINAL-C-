// abb.cpp — Árbol Binario de Búsqueda orientado a decisiones deportivas

#include <iostream>     // Librería para entrada/salida estándar
#include <locale.h>     // Librería para configuración regional
using namespace std;

// Estructura que representa un nodo del ABB
struct Node {
    int data;           // Valor almacenado (clave del nodo)
    Node* left;         // Puntero al subárbol izquierdo
    Node* right;        // Puntero al subárbol derecho
};

// Inserta un nuevo nodo en el ABB de forma recursiva
Node* insertNode(Node* root, int value) {
    if (root == NULL) {                         // Si el árbol está vacío
        Node* newNode = new Node;               // Crear nuevo nodo
        newNode->data = value;                  // Asignar valor
        newNode->left = NULL;                   // No tiene hijo izquierdo
        newNode->right = NULL;                  // No tiene hijo derecho
        return newNode;                         // Nuevo nodo como raíz
    }
    if (value < root->data) {                   // Si el valor es menor, va al subárbol izquierdo
        root->left = insertNode(root->left, value);
    } else if (value > root->data) {            // Si es mayor, al subárbol derecho
        root->right = insertNode(root->right, value);
    }
    return root;                                // Retornar raíz actual (sin cambios)
}

// Busca un valor dentro del ABB
bool searchNode(Node* root, int value) {
    if (root == NULL) return false;             // No encontrado
    if (root->data == value) return true;       // Encontrado
    if (value < root->data)                     // Buscar en el subárbol izquierdo
        return searchNode(root->left, value);
    return searchNode(root->right, value);      // Buscar en el derecho
}

// Recorrido in-order: izquierda, raíz, derecha
void inOrder(Node* root) {
    if (root == NULL) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

// Recorrido pre-order: raíz, izquierda, derecha
void preOrder(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

// Recorrido post-order: izquierda, derecha, raíz
void postOrder(Node* root) {
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

// Imprime un mensaje basado en el valor del nodo, asociándolo con un deporte
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

// Simula una decisión recorriendo el ABB desde la raíz hasta encontrar un valor
void decision(Node* root, int value) {
    Node* curr = root;
    while (curr != NULL) {
        printMessage(curr->data);               // Imprimir mensaje en el nodo actual
        if (value == curr->data) return;        // Nodo encontrado
        else if (value < curr->data)            // Ir al subárbol izquierdo
            curr = curr->left;
        else                                    // Ir al derecho
            curr = curr->right;
    }
    cout << "\tNodo no encontrado en el árbol\n";
}

// Muestra un menú de opciones y retorna la opción elegida por el usuario
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

// Función principal: ciclo interactivo con menú
int main() {
    setlocale(LC_ALL, "Spanish");  // ?? Permite mostrar acentos y caracteres especiales en español

    Node* root = NULL;             // Árbol vacío al inicio
    int opcion, valor;             // Variables de control

    do {
        opcion = menu();           // Mostrar menú
        switch (opcion) {
            case 1:                // Insertar nuevo nodo
                cout << "Ingrese nodo: ";
                cin >> valor;
                if (searchNode(root, valor)) {
                    cout << "Elemento ya existía.\n";
                } else {
                    root = insertNode(root, valor);
                    cout << "Elemento no existía, se acaba de ingresar.\n";
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
                cout << "Opción no válida\n";
        }
    } while (opcion != 6);

    return 0;
}
