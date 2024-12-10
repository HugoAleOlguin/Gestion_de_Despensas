#include <iostream>   // Libreria estandar para entrada y salida de datos
#include <string>     // Libreria para manejo de cadenas de texto
#include <windows.h>  // Libreria para manejo de colores en consola (Windows)

using namespace std;

// ==========================================
// CONFIGURACION DE COLORES PARA LA CONSOLA
// ==========================================
// Funcion para cambiar el color del texto en la consola
void setColor(int color) {
    // Usa el handle de salida estandar para cambiar los colores
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

// Colores disponibles:
// 1 - Azul
// 2 - Verde
// 3 - Cyan (Azul verdoso)
// 4 - Rojo
// 5 - Magenta (Purpura)
// 6 - Amarillo
// 7 - Blanco
// 8-15 - Variaciones de brillo

// Funcion para resetear el color a blanco predeterminado
void resetColor() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 7);
}

// ==========================================
// ESTRUCTURA PRINCIPAL DEL PRODUCTO
// ==========================================
// Estructura para almacenar toda la informacion de un producto
// - Usa struct en lugar de class para simplicidad
// - Todos los campos son publicos por defecto
struct Producto {
    // NOTA: Cada campo representa un aspecto del producto
    string nombre;    // Nombre del producto (texto)
    int cantidad;     // Cantidad disponible en inventario (numero entero)
    float costo;      // Costo de compra (numero decimal)
    
    // PRECIOS CALCULADOS AUTOMATICAMENTE
    float precioVenta40;  // Precio con 40% de ganancia
    float precioVenta50;  // Precio con 50% de ganancia
    float precioVentaPersonalizado;  // Precio con ganancia personalizada
};

// ==========================================
// FUNCIONES DE CALCULO
// ==========================================
// Funcion para calcular el precio de venta basado en el porcentaje de ganancia
// PARAMETROS:
// - costo: precio base del producto
// - porcentajeGanancia: porcentaje adicional sobre el costo
// RETORNA: Precio final de venta
float calcularPrecioVenta(float costo, float porcentajeGanancia) {
    // FORMULA: Precio final = Costo * (1 + porcentaje/100)
    // Ejemplo: $10 con 40% de ganancia = $10 * (1 + 0.4) = $14
    return costo * (1 + porcentajeGanancia / 100);
}

// ==========================================
// FUNCIONES DE ENTRADA DE DATOS
// ==========================================
// Funcion para ingresar productos al sistema
void ingresarProductos(Producto productos[], int numProductos) {
    // Bucle para ingresar cada producto
    for (int i = 0; i < numProductos; i++) {
        // Limpia la pantalla para cada producto
        system("cls");
        
        // Cambia el color del encabezado
        setColor(11); // Cyan
        cout << "\n" << string(50, '=') << endl;
        cout << "        PRODUCTO " << i + 1 << endl;
        cout << string(50, '=') << endl;
        resetColor();
        
        // NOTA: Cada producto requiere 3 datos principales
        setColor(6); // Amarillo para instrucciones
        cout << " * Ingrese el nombre del producto: ";
        resetColor();
        cin >> productos[i].nombre;
        
        setColor(6);
        cout << " * Ingrese la cantidad del producto: ";
        resetColor();
        cin >> productos[i].cantidad;
        
        setColor(6);
        cout << " * Ingrese el costo del producto: $";
        resetColor();
        cin >> productos[i].costo;
        
        // Calcula precios automaticamente despues de ingresar el costo
        productos[i].precioVenta40 = calcularPrecioVenta(productos[i].costo, 40);
        productos[i].precioVenta50 = calcularPrecioVenta(productos[i].costo, 50);
        
        // Separador visual
        setColor(3); // Cyan
        cout << string(50, '-') << endl;
        resetColor();
    }
}

// ==========================================
// FUNCIONES DE CALCULO DE PRECIOS
// ==========================================
// Funcion para calcular precios con ganancia personalizada
void calcularPreciosPersonalizado(Producto productos[], int numProductos, float porcentajeGanancia) {
    // Recorre todos los productos y calcula el precio con el porcentaje especificado
    for (int i = 0; i < numProductos; i++) {
        productos[i].precioVentaPersonalizado = calcularPrecioVenta(productos[i].costo, porcentajeGanancia);
    }
}

// ==========================================
// FUNCIONES DE VISUALIZACION
// ==========================================
// Funcion para mostrar la lista de productos
void mostrarProductos(const Producto productos[], int numProductos, bool mostrarPersonalizado = false, float porcentajePersonalizado = 0) {
    // Encabezado con color
    setColor(10); // Verde
    cout << string(60, '=') << endl;
    cout << "::::::::::  LISTA COMPLETA DE PRODUCTOS  ::::::::::" << endl;
    cout << string(60, '=') << endl;
    resetColor();
    
    // Muestra cada producto
    for (int i = 0; i < numProductos; i++) {
        // Separador de productos
        setColor(3); // Cyan
        cout << string(50, '-') << endl;
        
        // Nombre del producto en color
        setColor(14); // Amarillo brillante
        cout << "|| Producto: " << productos[i].nombre << endl;
        resetColor();
        
        cout << string(50, '-') << endl;
        
        // Detalles del producto
        setColor(7); // Blanco
        cout << " >> Cantidad en inventario: " << productos[i].cantidad << endl;
        cout << " >> Costo: $" << productos[i].costo << endl;
        cout << " >> Precio con 40% de ganancia: $" << productos[i].precioVenta40 << endl;
        cout << " >> Precio con 50% de ganancia: $" << productos[i].precioVenta50 << endl;
        
        // Muestra precio personalizado si esta habilitado
        if (mostrarPersonalizado) {
            setColor(13); // Magenta
            cout << " >> Precio con " << porcentajePersonalizado << "% de ganancia: $" 
                 << productos[i].precioVentaPersonalizado << endl;
            resetColor();
        }
        
        // Separador final
        setColor(3);
        cout << string(50, '*') << endl;
        resetColor();
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


// Funcion para mostrar informacion del software
void mostrarInformacionSoftware() {
    system("cls");
    
    // Encabezado principal
    setColor(14); // Amarillo
    cout << string(50, '=') << endl;
    cout << "::::::  SISTEMA DE GESTION DE DESPENSA  ::::::" << endl;
    cout << string(50, '=') << endl;
    resetColor();
    
    // Seccion de informacion
    setColor(11); // Cyan
    cout << string(50, '-') << endl;
    cout << "           INFORMACION DEL SOFTWARE          " << endl;
    cout << string(50, '-') << endl;
    resetColor();
    
    // Detalles del software
    setColor(7); // Blanco
    cout << " >> Nombre: Sistema de Gestion de Despensa" << endl;
    cout << " >> Version: 2.1" << endl;
    cout << " >> Autor: Hugo Olguin" << endl;
    cout << " >> Fecha: Octubre 2024" << endl;
    resetColor();
    
    // Proximas actualizaciones
    setColor(10); // Verde
    cout << string(50, '-') << endl;
    cout << "         PROXIMAS ACTUALIZACIONES         " << endl;
    cout << string(50, '-') << endl;
    resetColor();
    
    // Lista de actualizaciones
    setColor(6); // Amarillo
    cout << " >> - Sistema de modificacion de productos" << endl;
    cout << " >> - Control de inventario avanzado" << endl;
    cout << " >> - Sistema de reportes" << endl;
    cout << " >> - Exportacion de datos" << endl;
    cout << " >> - Interfaz grafica" << endl;
    resetColor();
    
    cout << string(50, '-') << endl;
    
    setColor(13);  // Magenta
    cout << "Changelog Version 2.1:" << endl;
    resetColor();
    cout << "- Mejoras visuales en la interfaz" << endl;
    cout << "- Agregado sistema de colores" << endl;
    cout << "- Optimizacion de presentacion" << endl;
    
    cout << string(50, '-') << endl;
    
    cout << "Para reportar errores o sugerencias:" << endl;
    cout << "email: hugod.ies9012@gmail.com" << endl;
}



// ==========================================
// FUNCION PRINCIPAL (MAIN)
// ==========================================
int main() {
    // Variables principales
    int numProductos = 0;     // Contador de productos
    Producto productos[50];   // Arreglo para almacenar productos
    int opcion;               // Almacena la opcion del menu
    
    // BUCLE PRINCIPAL DEL PROGRAMA
    do {
        // Limpia la pantalla
        system("cls");
        
        // MENU PRINCIPAL CON COLORES Y SIMBOLOS
        setColor(10); // Verde
        cout << string(50, '=') << endl;
        cout << "::::  SOFTWARE PARA TU DESPENSA  ::::" << endl;
        cout << string(50, '=') << endl;
        resetColor();
        
        // Opciones del menu con colores
        setColor(11); // Cyan
        cout << " 1. Ingresar productos" << endl;
        cout << " 2. Mostrar todos los productos" << endl;
        cout << " 3. Calcular precios con ganancia personalizada" << endl;
        cout << " 4. Buscar producto" << endl;
        cout << " 5. Modificar productos (Proximamente)" << endl;
        cout << " 6. Control de inventario (Proximamente)" << endl;
        cout << " 7. Reportes y estadisticas (Proximamente)" << endl;
        cout << " 8. Informacion del software" << endl;
        cout << " 9. Salir" << endl;
        resetColor();
        
        // Solicitar opcion
        setColor(6); // Amarillo
        cout << string(50, '-') << endl;
        cout << " Seleccione una opcion: ";
        resetColor();
        
        cin >> opcion;
        
        // Limpiar pantalla
        system("cls");
        
        // SWITCH PRINCIPAL CON COLORES Y DETALLES
        switch (opcion) {
            case 1:  // Ingresar productos
                setColor(14); // Amarillo
                cout << string(50, '=') << endl;
                cout << "        INGRESO DE PRODUCTOS       " << endl;
                cout << string(50, '=') << endl;
                resetColor();
                
                // Solicitar numero de productos
                setColor(11); // Cyan
                cout << " Cuantos productos desea ingresar?: ";
                resetColor();
                cin >> numProductos;
                
                // Validar limite de productos
                if (numProductos > 50) {
                    setColor(12); // Rojo
                    cout << " *** El maximo de productos es 50. *** " << endl;
                    resetColor();
                    numProductos = 50;
                }
                
                // Llamar funcion de ingreso
                ingresarProductos(productos, numProductos);
                break;
                
            case 2:  // Mostrar productos
                if (numProductos == 0) {
                    setColor(12); // Rojo
                    cout << string(50, '!') << endl;
                    cout << " *** Primero debe ingresar productos *** " << endl;
                    cout << string(50, '!') << endl;
                    resetColor();
                } else {
                    mostrarProductos(productos, numProductos);
                }
                break;
                
            case 3:  // Calcular precios personalizados
                if (numProductos == 0) {
                    setColor(12); // Rojo
                    cout << string(50, '!') << endl;
                    cout << " *** Primero debe ingresar productos *** " << endl;
                    cout << string(50, '!') << endl;
                    resetColor();
                } else {
                    float porcentaje;
                    
                    // Solicitar porcentaje personalizado
                    setColor(14); // Amarillo
                    cout << " Ingrese el porcentaje de ganancia deseado: ";
                    resetColor();
                    cin >> porcentaje;
                    
                    // Calcular y mostrar precios
                    calcularPreciosPersonalizado(productos, numProductos, porcentaje);
                    mostrarProductos(productos, numProductos, true, porcentaje);
                }
                break;
                
            case 4:  // Buscar producto
                if (numProductos == 0) {
                    setColor(12); // Rojo
                    cout << string(50, '!') << endl;
                    cout << " *** Primero debe ingresar productos *** " << endl;
                    cout << string(50, '!') << endl;
                    resetColor();
                } else {
                    buscarProducto(productos, numProductos);
                }
                break;
                
            // Casos 5-7: Funciones proximamente
            case 5:  
            case 6:  
            case 7:  
                setColor(13); // Magenta
                cout << string(50, '~') << endl;
                cout << " Esta funcion estara disponible en la proxima actualizacion. " << endl;
                cout << string(50, '~') << endl;
                resetColor();
                break;
                
            case 8:  // Informacion del software
                mostrarInformacionSoftware();
                break;
                
            case 9:  // Salir
                setColor(10); // Verde
                cout << string(50, '=') << endl;
                cout << "     *** Gracias por usar el programa ***     " << endl;
                cout << string(50, '=') << endl;
                resetColor();
                break;
                
            default:  // Opcion invalida
                setColor(12); // Rojo
                cout << string(50, '!') << endl;
                cout << " *** Opcion invalida. Por favor, intente nuevamente *** " << endl;
                cout << string(50, '!') << endl;
                resetColor();
        }
        
        // Pausa antes de volver al menu
        if (opcion != 9) {
            setColor(3); // Cyan
            cout << endl << " Presione Enter para continuar...";
            resetColor();
            cin.get();
            cin.get();
        }
        
    } while (opcion != 9);
    
    return 0;
}

// NOTAS FINALES DEL PROGRAMA
// =============================

// PROXIMAS MEJORAS:
// - Persistencia de datos
// - Interfaz grafica
// - Validaciones adicionales
// - Opciones de exportacion