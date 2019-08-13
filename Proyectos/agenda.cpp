#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

/*
 * En esta estructura se guardan los datos del usuario. Una estructura es similar
 * a una clase. Es una variable que puede contener otras variables en su interior.
 */
struct Usuario
{
    string id, nombre, edad;
};

unsigned pos_agenda = 0;
const unsigned TAMANO_AGENDA = 6;
Usuario datos_agenda[TAMANO_AGENDA];

/*
 * Guardo la lista de opciones en una enumeración para que sea más clara la 
 * lectura del código.
 */
enum OPCIONES
{
    AGREGAR=1, BORRAR, MOSTRAR, GUARDAR, SALIR
};
        
/*
 * Despliega el menú de opciones. La función devuelve una variable entera que
 * sólo puede contener los valores que se muestran en la enumeración OPCIONES.
 */
OPCIONES menu()
{
    // Muestra todas las posibles opciones.
    cout << "Seleccione una opción: " << endl;
    cout << "1: Agregar usuario" << endl;
    cout << "2: Borrar usuario" << endl;
    cout << "3: Mostrar usuarios almacenados" << endl;
    cout << "4: Guardar usuarios a almacenados a archivo" << endl;
    cout << "5: Salir" << endl << endl;
    
    // Recibe selección del usuario.
    int seleccion;
    cout << "Seleccione opcion: ";
    cin >> seleccion;
    
    // Verifica que la selección es correcta.
    if (seleccion > 0 && seleccion <= 5)
        return (OPCIONES)seleccion;
    else
    {
        // Si la opción no es válida vuelve a llamar a menú de forma recursiva.
        cout << "Opción no válida." << endl;
        return menu();
    }   
}

void agregar_usuario()
{
    if (pos_agenda < TAMANO_AGENDA)
    {
        // Pide información al usuario.
        Usuario usr;
        cout << "Introduza el ID del usuario: ";
        cin >> usr.id;
        cout << "Introduzca el nombre del usuario: ";
        cin >> usr.nombre;
        cout << "Introduzca la edad del usuario: ";
        cin >> usr.edad;
        
        // Se añade el usuario al final del vector datos_agenda.
        datos_agenda[pos_agenda] = usr;
        pos_agenda++;
        cout << "Usuario añadido." << endl << endl;
    }
    else
        cout << "No hay espacio para anadir a mas usuarios." << endl;
}

void borrar_usuario()
{
    // Para borrar un usuario se utilizará la ID.
    string id;
    cout << "Introduzca la ID del usuario que desea borrar: ";
    cin >> id;
    
    // Recorre todos los datos de la agenda para encontrar coincidencia.
    bool coincidencia = false;
    for (unsigned i=0; i<TAMANO_AGENDA; ++i)
    {
        if (id == datos_agenda[i].id)
        {
            // Cuando encuentra la coincidencia, recorre todos los datos hacia atrás (borrando el que coincide).
            for (unsigned j=i; j<TAMANO_AGENDA-1; ++j)
                datos_agenda[j] = datos_agenda[j+1];

            datos_agenda[TAMANO_AGENDA-1].id = "";
            datos_agenda[TAMANO_AGENDA-1].nombre = "";
            datos_agenda[TAMANO_AGENDA-1].edad = "";
            pos_agenda--;
            coincidencia = true;
            break;
        }
    }
    
    // Informa si se pudo borrar.
    if (coincidencia)
        cout << "Usuario borrado." << endl;
    else
        cout << "No se pudo borrar el usuario." << endl;
}

/* Esta función convierte una cadena de texto que contiene un número entero
 * a una variable int.
 */
int string_a_int(string str)
{
    return atoi(str.c_str());
}

void ordenar_burbuja()
{
    Usuario temp;
    
    // Recorre el vector temporal desde el inicio.
    for (unsigned i=0; i<TAMANO_AGENDA; ++i)
    {
        // Recorre el vector temporal desde la posición i.
        for (unsigned j=i+1; j<TAMANO_AGENDA; ++j)
        {
            /* Como la edad está almacenada en forma de texto es necesario
               convertirla a una variable numérica antes de comprarla. */
            if ((datos_agenda[i].edad != "") && (datos_agenda[j].edad != "") 
                && (string_a_int(datos_agenda[i].edad) > string_a_int(datos_agenda[j].edad)))
            {
                temp = datos_agenda[i];
                datos_agenda[i] = datos_agenda[j];
                datos_agenda[j] = temp;
            }
        }
    }
}

void mostrar_usuarios()
{
    /* Primero se ordenan los usuarios por edad utilizando el algoritmo de
       la burbuja */
    ordenar_burbuja();
    
    // Se muestran los usuarios almacenados.
    cout << "Usuarios almacenados en la agenda" << endl;
    cout << "=================================" << endl << endl;
    for (unsigned i=0; i<TAMANO_AGENDA; ++i)
    {
        cout << "ID: " << datos_agenda[i].id << endl;
        cout << "Nombre: " << datos_agenda[i].nombre << endl;
        cout << "Edad: " << datos_agenda[i].edad << endl << endl;
    }
    cout << "=================================" << endl << endl;
}

void guardar_archivo()
{
    /* Primero se verifica si la agenda no está vacía. En caso de que sí se
       sale de la función. */
    if (pos_agenda == 0)
    {
        cout << "No hay datos que guardar." << endl;
        return;
    }

    ordenar_burbuja();
    
    /* Se crea un archivo de salida, es decir, un archivo al cual sólo se
     * pueden escribir datos pero no leer, y se verifica que sí se pudo
     * crear correctamente el archivo. */
    ofstream archivo("Agenda.txt");
    if (archivo.is_open())
    {
        // Se añaden los datos al archivo.
        for (unsigned i=0; i<TAMANO_AGENDA; ++i)
        {
            archivo << "ID: " << datos_agenda[i].id << endl;
            archivo << "Nombre: " << datos_agenda[i].nombre << endl;
            archivo << "Edad: " << datos_agenda[i].edad << endl << endl;
        }
        
        // Se cierra el archivo.
        archivo.close();
        cout << "Archivo guardado." << endl << endl;
    }
    else
        cout << "Error desconocido: No se pudo crear el archivo." << endl;
}

int main()
{
    cout << "Agenda Personal Computarizada v5.6 Beta" << endl;
    cout << "Copyright (c) 2016 Alex Brother Software Inc. All Rights Reserved." << endl;
    
    // Menú principal.
    bool programa_funcionando = true;
    while (programa_funcionando)
    {
        OPCIONES seleccion = menu();
        switch(seleccion)
        {
        case AGREGAR:
            agregar_usuario();
            break;
        case BORRAR:
            borrar_usuario();
            break;
        case MOSTRAR:
            mostrar_usuarios();
            break;
        case GUARDAR:
            guardar_archivo();
            break;
        case SALIR:
            programa_funcionando = false;
            break;
        }
    }
    
    cout << "Programa terminado." << endl;
    return 0;
}