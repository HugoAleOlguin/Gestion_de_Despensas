#include <iostream>
#include <string>
using namespace std;

// ==========================================
// ESTRUCTURA PRINCIPAL
// ==========================================
// Esta estructura almacena toda la información
// relacionada con cada producto en la tienda
struct Producto {
    string nombre;    // Nombre del producto
    int cantidad;     // Cantidad en inventario
    float costo;      // Costo de compra
    float precioVenta40;  // Precio con 40% de ganancia
    float precioVenta50;  // Precio con 50% de ganancia
    float precioVentaPersonalizado;  // Precio con ganancia personalizada
};

// ==========================================
// FUNCIONES DE CÁLCULO
// ==========================================
// Función que calcula el precio de venta según el porcentaje de ganancia
// Parámetros:
// - costo: el costo base del producto
// - porcentajeGanancia: el porcentaje de ganancia deseado
float calcularPrecioVenta(float costo, float porcentajeGanancia) {
    return costo * (1 + porcentajeGanancia / 100);
}

// ==========================================
// FUNCIONES DE ENTRADA DE DATOS
// ==========================================
// Función para ingresar los productos al sistema
// Parámetros:
// - productos[]: array donde se almacenarán los productos
// - numProductos: cantidad de productos a ingresar
void ingresarProductos(Producto productos[], int numProductos) {
    // Ciclo para ingresar cada producto
    for (int i = 0; i < numProductos; i++) {
        cout << "Producto " << i + 1 << ":" << endl;
        cout << "Ingrese el nombre del producto: ";
        cin >> productos[i].nombre;
        
        cout << "Ingrese la cantidad del producto: ";
        cin >> productos[i].cantidad;
        
        cout << "Ingrese el costo del producto: $";
        cin >> productos[i].costo;
        
        // Cálculo automático de precios con diferentes ganancias
        productos[i].precioVenta40 = calcularPrecioVenta(productos[i].costo, 40);
        productos[i].precioVenta50 = calcularPrecioVenta(productos[i].costo, 50);
    }
}

// ==========================================
// FUNCIONES DE CÁLCULO DE PRECIOS
// ==========================================
// Función para calcular precios con ganancia personalizada
// Parámetros:
// - productos[]: array de productos
// - numProductos: cantidad total de productos
// - porcentajeGanancia: porcentaje de ganancia deseado
void calcularPreciosPersonalizado(Producto productos[], int numProductos, float porcentajeGanancia) {
    for (int i = 0; i < numProductos; i++) {
        productos[i].precioVentaPersonalizado = calcularPrecioVenta(productos[i].costo, porcentajeGanancia);
    }
}

// ==========================================
// FUNCIONES DE VISUALIZACIÓN
// ==========================================
// Función para mostrar la lista completa de productos
void mostrarProductos(const Producto productos[], int numProductos, bool mostrarPersonalizado = false, float porcentajePersonalizado = 0) {
    cout << "=== Lista de productos ===" << endl;
    
    for (int i = 0; i < numProductos; i++) {
        cout << endl << "Producto: " << productos[i].nombre << endl;
        cout << "Cantidad en inventario: " << productos[i].cantidad << endl;
        cout << "Costo: $" << productos[i].costo << endl;
        cout << "Precio con 40% de ganancia: $" << productos[i].precioVenta40 << endl;
        cout << "Precio con 50% de ganancia: $" << productos[i].precioVenta50 << endl;
        
        if (mostrarPersonalizado) {
            cout << "Precio con " << porcentajePersonalizado << "% de ganancia: $" 
                 << productos[i].precioVentaPersonalizado << endl;
        }
        cout << "----------------------------------------" << endl;
    }
}

// Función para buscar un producto específico
void buscarProducto(const Producto productos[], int numProductos) {
    string nombreBuscar;
    cout << "Ingrese el nombre del producto a buscar: ";
    cin >> nombreBuscar;
    
    bool encontrado = false;
    for (int i = 0; i < numProductos; i++) {
        if (productos[i].nombre == nombreBuscar) {
            cout << endl << "Producto encontrado:" << endl;
            cout << "Nombre: " << productos[i].nombre << endl;
            cout << "Cantidad: " << productos[i].cantidad << endl;
            cout << "Costo: $" << productos[i].costo << endl;
            cout << "Precio con 40% de ganancia: $" << productos[i].precioVenta40 << endl;
            cout << "Precio con 50% de ganancia: $" << productos[i].precioVenta50 << endl;
            encontrado = true;
            break;
        }
    }
    
    if (!encontrado) {
        cout << "Producto no encontrado." << endl;
    }
}

// Función para mostrar la información del software
void mostrarInformacionSoftware() {
    cout << "=== Información del Software ===" << endl;
    cout << "Nombre: Sistema de Gestión de Despensa" << endl;
    cout << "Versión: 1.0.0" << endl;
    cout << "Autor: Hugo Olguin" << endl;
    cout << "Fecha: Octubre 2024" << endl;
    cout << endl;
    cout << "Próximas actualizaciones:" << endl;
    cout << "- Sistema de modificación de productos" << endl;
    cout << "- Control de inventario avanzado" << endl;
    cout << "- Sistema de reportes" << endl;
    cout << "- Exportación de datos" << endl;
    cout << "- Interfaz gráfica" << endl;
    cout << endl;
    cout << "Para reportar errores o sugerencias:" << endl;
    cout << "email: hugod.ies9012@gmail.com" << endl;
}

// ==========================================
// FUNCIÓN PRINCIPAL
// ==========================================
int main() {
    // Declaración de variables principales
    int numProductos = 0;
    Producto productos[50];  // Array fijo de 50 productos máximo
    int opcion;
    
    // Bucle principal del programa
    do {
        // Limpia la pantalla para mejor visualización
        system("cls");
        
        // Muestra el menú principal
        cout << "=== Software para tu despensa ===" << endl;
        cout << "1. Ingresar productos" << endl;
        cout << "2. Mostrar todos los productos" << endl;
        cout << "3. Calcular precios con ganancia personalizada" << endl;
        cout << "4. Buscar producto" << endl;
        cout << "5. Modificar productos (Próximamente)" << endl;
        cout << "6. Control de inventario (Próximamente)" << endl;
        cout << "7. Reportes y estadísticas (Próximamente)" << endl;
        cout << "8. Información del software" << endl;
        cout << "9. Salir" << endl;
        cout << "Seleccione una opcion: ";
        
        cin >> opcion;
        
        system("cls");
        
        // Manejo de las diferentes opciones del menú
        switch (opcion) {
            case 1:  // Ingresar productos
                cout << "¿Cuantos productos desea ingresar?: ";
                cin >> numProductos;
                if (numProductos > 50) {
                    cout << "El maximo de productos es 50." << endl;
                    numProductos = 50;
                }
                ingresarProductos(productos, numProductos);
                break;
                
            case 2:  // Mostrar productos
                if (numProductos == 0) {
                    cout << "Primero debe ingresar productos." << endl;
                } else {
                    mostrarProductos(productos, numProductos);
                }
                break;
                
            case 3:  // Calcular precios personalizados
                if (numProductos == 0) {
                    cout << "Primero debe ingresar productos." << endl;
                } else {
                    float porcentaje;
                    cout << "Ingrese el porcentaje de ganancia deseado: ";
                    cin >> porcentaje;
                    calcularPreciosPersonalizado(productos, numProductos, porcentaje);
                    mostrarProductos(productos, numProductos, true, porcentaje);
                }
                break;
                
            case 4:  // Buscar producto
                if (numProductos == 0) {
                    cout << "Primero debe ingresar productos." << endl;
                } else {
                    buscarProducto(productos, numProductos);
                }
                break;
                
            case 5:  // Modificar productos (Próximamente)
                cout << "Esta función estará disponible en la próxima actualización." << endl;
                break;
                
            case 6:  // Control de inventario (Próximamente)
                cout << "Esta función estará disponible en la próxima actualización." << endl;
                break;
                
            case 7:  // Reportes (Próximamente)
                cout << "Esta función estará disponible en la próxima actualización." << endl;
                break;
                
            case 8:  // Información del software
                mostrarInformacionSoftware();
                break;
                
            case 9:  // Salir
                cout << "¡Gracias por usar el programa!" << endl;
                break;
                
            default:  // Opción inválida
                cout << "Opcion invalida. Por favor, intente nuevamente." << endl;
        }
        
        // Pausa antes de volver al menú principal
        if (opcion != 9) {
            cout << endl << "Presione Enter para continuar...";
            cin.get();
            cin.get();
        }
        
    } while (opcion != 9);
    
    return 0;
}