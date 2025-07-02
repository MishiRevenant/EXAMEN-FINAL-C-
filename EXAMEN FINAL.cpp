#include <iostream> 
using namespace std; 
#include <locale.h>     // Librería para configuración regional


// Definición de la estructura Node para un nodo del Árbol Binario de Búsqueda ABB
struct Node {
    int data;       // Almacena el valor entero del nodo
    Node* left;     // Puntero al nodo hijo izquierdo
    Node* right;    // Puntero al nodo hijo derecho
};


// Recibe la raíz actual del árbol y el valor a insertar
Node* insertNode(Node* root, int value) {
    // Si la raíz es nula árbol vacío o posición de inserción encontrada
    if (root == NULL) {
        Node* newNode = new Node; // Crea un nuevo nodo dinámicamente
        newNode->data = value;    // Asigna el valor al campo data del nuevo nodo
        newNode->left = NULL;     // Inicializa el puntero izquierdo a NULL
        newNode->right = NULL;    // Inicializa el puntero derecho a NULL
        return newNode;           // Retorna el nuevo nodo como la raíz de este subárbol
    }
    // Si el valor a insertar es menor que los datos del nodo actual
    if (value < root->data) {
        // Llama recursivamente a insertNode para el subárbol izquierdo
        root->left = insertNode(root->left, value);
    }
    // Si el valor a insertar es mayor que los datos del nodo actual
    else if (value > root->data) {
        // Llama recursivamente a insertNode para el subárbol derecho
        root->right = insertNode(root->right, value);
    }
    // Si el valor ya existe (value == root->data), no se hace nada y se retorna la raíz actual
    return root; 
}


// Recibe la raíz actual del árbol y el valor a buscar
bool searchNode(Node* root, int value) {
    // Si la raíz es nula, el valor no se encontró
    if (root == NULL) return false;
    // Si el valor es igual a los datos del nodo actual, se encontró
    if (root->data == value) return true;
    // Si el valor es menor que los datos del nodo actual, busca en el subárbol izquierdo
    if (value < root->data) return searchNode(root->left, value);
    // Si el valor es mayor que los datos del nodo actual, busca en el subárbol derecho
    return searchNode(root->right, value);
}

// Función para el recorrido In-Order Izquierda, Raíz, Derecha
void inOrder(Node* root) {
    //Si la raíz es nula, no hay nada que recorrer
    if (root == NULL) return;
    inOrder(root->left);    // Recorre el subárbol izquierdo
    cout << root->data << " "; // Imprime los datos del nodo actual
    inOrder(root->right);   // Recorre el subárbol derecho
}

// Función para el recorrido Pre-Order Raíz, Izquierda, Derecha
void preOrder(Node* root) {
    // Si la raíz es nula, no hay nada que recorrer
    if (root == NULL) return;
    cout << root->data << " "; // Imprime los datos del nodo actual
    preOrder(root->left);   // Recorre el subárbol izquierdo
    preOrder(root->right);  // Recorre el subárbol derecho
}

// Función para el recorrido Post-Order Izquierda, Derecha, Raíz
void postOrder(Node* root) {
    //Si la raíz es nula, no hay nada que recorrer
    if (root == NULL) return;
    postOrder(root->left);  // Recorre el subárbol izquierdo
    postOrder(root->right); // Recorre el subárbol derecho
    cout << root->data << " "; // Imprime los datos del nodo actual
}

void printMessage(int v) {  // Utiliza una sentencia switch para imprimir un mensaje basado en el valor de v

    switch (v) {
        case 20: cout << "\tTe interesa el deporte\n"; break; // Si v es 20
        case 12: cout << "\tPractica DEPORTES DE EQUIPO\n"; break; // Si v es 12
        case 8:  cout << "\tPractica FÚTBOL\n"; break; // Si v es 8
        case 15: cout << "\tPractica VOLEIBOL\n"; break; // Si v es 15
        case 30: cout << "\tPractica DEPORTES INDIVIDUALES\n"; break; // Si v es 30
        case 25: cout << "\tPractica NATACIÓN\n"; break; // Si v es 25
        case 35: cout << "\tPractica TENIS\n"; break; // Si v es 35
        default: cout << "\tValor no corresponde a un deporte\n"; break; // Si v no coincide con ningún caso
    }
}

// Simula un proceso de decisión o ruta en el árbol
void decision(Node* root, int value) {
    Node* curr = root; // Inicializa un puntero curr a la raíz del árbol
    while (curr != NULL) {
        printMessage(curr->data); // Imprime el mensaje de deporte asociado al nodo actual
        
        if (value == curr->data) { // Si el valor buscado es igual a los datos del nodo actual
            return; 
        }
        
        else if (value < curr->data) {  // Si el valor buscado es menor que los datos del nodo actual
            curr = curr->left; // Mueve curr al hijo izquierdo
        }
        // Si el valor buscado es mayor que los datos del nodo actual
        else {
            curr = curr->right; // Mueve curr al hijo derecho
        }
    }
    // Si el bucle termina curr es NULL y el nodo no fue encontrado
    cout << "\tNodo no encontrado en el árbol\n";
}

// Función que muestra el menú interactivo al usuario
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

// Función principal donde comienza la ejecución del programa
int main() {
    setlocale(LC_ALL, "Spanish");  // ?? Permite mostrar acentos y caracteres especiales en español
    Node* root = NULL; // Inicializa la raíz del ABB como NULL árbol vacío
    int opcion, valor; // Declara variables para la opción del menú y el valor del nodo
    do { 
        opcion = menu(); // Llama a la función menu para obtener la opción del usuario
        switch (opcion) { 
            case 1: 
                cout << "Ingrese nodo: "; // Pide al usuario que ingrese un valor
                cin >> valor;             
               
                if (searchNode(root, valor)) {
                    cout << "Elemento ya existía.\n"; // Si existe, imprime un mensaje
                } else {
                    root = insertNode(root, valor); // Si no existe, lo inserta en el árbol
                    cout << "Elemento No existía, se acaba de ingresar.\n"; // Confirma la inserción
                }
                break; 
            case 2: // Si la opción es 2 Mostrar In-Order
                cout << "ABB In-Order: "; // Imprime una etiqueta
                inOrder(root);            // Llama a la función inOrder para mostrar el recorrido
                cout << "\n";             // Imprime un salto de línea
                break; 
            case 3: // Si la opción es 3 Mostrar Pre-Order
                cout << "ABB Pre-Order: "; // Imprime una etiqueta
                preOrder(root);           // Llama a la función preOrder para mostrar el recorrido
                cout << "\n";             // Imprime un salto de línea
                break; 
            case 4: // Si la opción es 4 Mostrar Post-Order
                cout << "ABB Post-Order: "; // Imprime una etiqueta
                postOrder(root);            // Llama a la función postOrder para mostrar el recorrido
                cout << "\n";               // Imprime un salto de línea
                break; 
            case 5: // Si la opción es 5 Decision
                cout << "Ingrese valor a buscar: "; // Pide al usuario el valor a buscar para la decisión
                cin >> valor;                       // Lee el valor
                decision(root, valor);              // Llama a la función decision
                break; 
            case 6: // Si la opción es 6 Salir
                cout << "Saliendo del programa.\n"; // Imprime un mensaje de salida
                break; 
            default: // Si la opción no es ninguna de las anteriores
                cout << "Opcion no valida\n"; // Imprime un mensaje de opción no válida
        }
    } while (opcion != 6); // El bucle continúa mientras la opción no sea 6 Salir
    return 0; 
}
