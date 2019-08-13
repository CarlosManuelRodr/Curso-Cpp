#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>
#include <ctime>
#include <sstream>
#include <cstdlib>
using namespace std;


/************************
*                       *
*        Auxiliar       *
*                       *
************************/

// Para funcion de mostrar directorio.
#ifdef WINDOWS
    #include <direct.h>
    #define GetCurrentDir _getcwd
#else
    #include <unistd.h>
    #define GetCurrentDir getcwd
#endif

// Para funciones matematicas.
double string_a_double(const std::string& s)
{
    std::istringstream i(s);
    double x;
    if (!(i >> x))
            return 0;
    return static_cast<double>(x);
}

/************************
*                       *
* Funciones de la shell *
*                       *
************************/

// Escribe texto en la shell.
void escribir(string arg)
{
    cout << arg;
}

// Lee archivo y muestra el texto.
void leer(string arg1)
{
    // Crea el archivo y trata de abrirlo.
    ifstream f;
    f.open(arg1);
    
    // Si logra abrirlo copia sus contenidos en un buffer y luego escribe el buffer en la shell.
    if (f.is_open())
    {
        std::string buffer((std::istreambuf_iterator<char>(f)),
             std::istreambuf_iterator<char>());
        cout << buffer;
    }
    else
        cout << "Error: La ruta del archivo no es valida.";
}

// Concatena dos archivos.
void unir(string arg1, string arg2, string arg3, string arg4)
{
    ifstream f1, f2;
    f1.open(arg1);
    f2.open(arg2);
    
    if (f1.is_open() && f2.is_open())
    {
        /* Guarda contenido de los archivos a cadenas de texto buffer1 y buffer2.
         * Los detalles de este metodo los puedes encontrar aqui:
         * http://stackoverflow.com/questions/2602013/read-whole-ascii-file-into-c-stdstring
         */
        
        std::string buffer1((std::istreambuf_iterator<char>(f1)),
             std::istreambuf_iterator<char>());
        std::string buffer2((std::istreambuf_iterator<char>(f2)),
             std::istreambuf_iterator<char>());

        string buffer_final = buffer1 + buffer2;
        
        // Verifica opciones.
        if (arg3 == "" || arg3 == "-p")
        {
            // Escribe el texto en la shell.
            string buffer_final = buffer1 + buffer2;
            cout << buffer_final;
        }
        if (arg3 == "-f")
        {
            // Crea un nuevo archivo para volcar el resultado en este nuevo archivo.
            if (!arg4.empty())
            {
                ofstream f_salida;
                f_salida.open(arg4);
                if (f_salida.is_open())
                {
                    f_salida << buffer_final;
                    f_salida.close();
                }
                else
                {
                    cout << "Error: No se pudo crear archivo de salida.";
                }
            }
            else
            {
                cout << "Error: La ruta del archivo de salida no es valida.";
            }
        }
    }
    else
    {
        if (!f1.is_open() && !f2.is_open())
        {
            cout << "Error: La ruta de ninguno de los archivos es valida.";
        }
        else
        {
            if (!f1.is_open())
                cout << "Error: La ruta del archivo 1 no es valida.";
            if (!f2.is_open())
                cout << "Error: La ruta del archivo 2 no es valida.";
        }
    }
}

// Muestra la fecha y hora actuales.
void tiempo()
{
    // Codigo de: http://stackoverflow.com/questions/997946/how-to-get-current-time-and-date-in-c
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
    cout << buf;
}

void sumar(string arg1, string arg2)
{
    double n1, n2;
    n1 = string_a_double(arg1);
    n2 = string_a_double(arg2);
    cout << n1 + n2;
}

void restar(string arg1, string arg2)
{
    double n1, n2;
    n1 = string_a_double(arg1);
    n2 = string_a_double(arg2);
    cout << n1 - n2;
}

void multiplicar(string arg1, string arg2)
{
    double n1, n2;
    n1 = string_a_double(arg1);
    n2 = string_a_double(arg2);
    cout << n1 * n2;
}

void dividir(string arg1, string arg2)
{
    double n1, n2;
    n1 = string_a_double(arg1);
    n2 = string_a_double(arg2);
    cout << n1 / n2;
}

void limpiar()
{
#ifdef _WIN32
    system("cls");
#elif __linux__
    system("clear");
#endif
}

void mostrar_directorio()
{
    // Fuente: http://stackoverflow.com/questions/143174/how-do-i-get-the-directory-that-a-program-is-running-from
    char directorio[FILENAME_MAX];
    if (!GetCurrentDir(directorio, sizeof(directorio)))
    {
        cout << "Error al tratar de mostrar directorio.";
    }
    directorio[sizeof(directorio) - 1] = '\0'; /* not really required */
    cout << directorio;
}

void crear_archivo(string arg)
{
    ofstream f;
    f.open(arg);
    if (f.is_open())
    {
        cout << "Archivo creado correctamente.";
        f.close();
    }
    else
        cout << "Error al crear el archivo.";
}

void celar()
{
    // Funcion celosa: A sugerencia de Alejandro.
    int aleatorio = rand() % 7;
    
    switch (aleatorio)
    {
    case 0:
        cout << "De seguro andabas con la otra.";
        break;
    case 1:
        cout << "Antes pasabas tiempo conmigo, ahora pareciera que ya ni existo para ti";
        break;
    case 2:
        cout << "Quien es esa que te escribe tantos mensajes?";
        break;
    case 3:
        cout << "Celosa? Yo? Para nada.";
        break;
    case 4:
        cout << "Por que tanto perfume? Con quien vas?";
        break;
    case 5:
        cout << "Quién era la que te llamo? Y que quiere o que? Y de donde la conoces?";
        break;
    case 6:
        cout << "Por que le da like a tus fotos de facebook? Quiere contigo o que?";
        break;
    }
}

void instrucciones()
{
    cout << "Instrucciones: Introducir el comando deseado seguido de sus "
            "argumentos separados por espacios en caso de que sean necesarios.\n"
            "Ejemplo: unir Texto1.txt Texto2.txt -f Textofinal.txt\n"
            "La lista de comandos disponibles es:\n\n"
            "escribir: Escribe en la terminal.\nSintaxis: escribir [texto]\n\n"
            "leer: Lee archivo.\nSintaxis: leer [ruta del archivo]\n\n"
            "unir: Une dos archivos.\nSintaxis: unir [ruta de archivo 1] [ruta de archivo 2] [opcion] [ruta opcional de archivo de salida]\n"
            "opciones:\n-p Escribir el resultado en la pantalla (opcion por defecto).\n-f Escribir el resultado en un archivo.\n\n"
            "tiempo: Muestra la fecha y hora actuales.\n\n"
            "sumar: Suma dos numeros.\nSintaxis: sumar [numero 1] [numero 2]\n\n"
            "restar: Resta dos numeros.\nSintaxis: restar [numero 1] [numero 2]\n\n"
            "multiplicar: Multiplica dos numeros.\nSintaxis: multiplicar [numero 1] [numero 2]\n\n"
            "dividir: Divide dos numeros.\nSintaxis: dividir [numero 1] [numero 2]\n\n"
            "limpiar: Limpia el shell.\n\n"
            "mostrardirectorio: Muestra el directorio actual.\n\n"
            "creararchivo: Crear archivo.\nSintaxis: creararchivo [ruta del archivo]\n\n"
            "celar: El programa se pone celoso.\n\n"
            "salir: Se sale de la shell.";
}

/************************
*                       *
*         Shell         *
*                       *
************************/


// Variables de la shell.
string entrada;     // Entrada que introduce el usuario en la shell.
string comando;     // Instruccion que va a ejecutar la shell.
string arg1, arg2, arg3, arg4;     // Argumentos opcionales para los comandos de la shell.

int parser(string entrada, string &comando, string &arg1, string &arg2, 
           string &arg3, string &arg4)
{
    /* Si la entrada no es vacia se procesara. En caso contrario se manda una señal de error.
     * La convención para señales sera:
     * 0 si el parseo es exitoso.
     * 1 si no hay entrada.
     * 2 si hubo un error al parsear.
     */
    
    if (!entrada.empty())
    {
        // Primero se preprocesa la entrada, se eliminaran los espacios innecesarios.
        for (unsigned i=0; i<entrada.size()-1; ++i)
        {
            // Busca los lugares donde hay espacios.
            if (entrada[i] == ' ' && entrada[i+1] == ' ')
            {
                entrada.erase(i+1, 1);  // Si encuentra dos espacios juntos los borra.
                --i;                    // Regresa el contador para no perder espacios
                                        // (esto pasaria si hay mas de 2 espacios juntos).
            }
        }

        // Si hay espacios al principio o final del comando tambien se eliminan.
        if (entrada.size() > 1)
        {
            if (entrada[0] == ' ')
                entrada.erase(0, 1);
            if (entrada[entrada.size()-1] == ' ')
                entrada.erase(entrada.size()-1, 1);
        }


        // Ahora se separara buscando espacios.
        arg1 = arg2 = arg3 = arg4 = "";
        int pos_inicio = 0;
        int tamano_extraccion;
        int parametro = 0;
        for (unsigned i=0; i<entrada.size(); ++i)
        {
            if (entrada[i] == ' ' || i+1 == entrada.size())
            {
                if (entrada[i] == ' ')
                    tamano_extraccion = i-pos_inicio;
                else
                    tamano_extraccion = entrada.size() - pos_inicio;
                
                switch (parametro)
                {
                case 0:
                    comando = entrada.substr(pos_inicio, tamano_extraccion);
                    break;
                case 1:
                    arg1 = entrada.substr(pos_inicio, tamano_extraccion);
                    break;
                case 2:
                    arg2 = entrada.substr(pos_inicio, tamano_extraccion);
                    break;
                case 3:
                    arg3 = entrada.substr(pos_inicio, tamano_extraccion);
                    break;
                case 4:
                    arg4 = entrada.substr(pos_inicio, tamano_extraccion);
                    break;
                
                }
                
                pos_inicio = i+1;
                ++parametro;
            }
        }
        
        // No se pudo parsear nada.
        if (parametro == 0)
            return 2;
        
        return 0;
    }
    else
        return 1;
}

void prompt()
{
    while (true)
    {
        // Pide entrada al usuario.
        string entrada;
        cout << "> ";
        getline(std::cin, entrada);

        // Ejecuta parser y verifica si hay errores.
        int resultado = parser(entrada, comando, arg1, arg2, arg3, arg4);
        if (resultado == 1)
        {
            cout << "> ";
        }
        if (resultado == 2)
        {
            cout << "> Error al interpretar entrada.";
        }

        // Busca coincidencia entre el comando y los nombres de las funciones disponibles.
        if (comando == "escribir")
            escribir(arg1);
        else if (comando == "leer")
            leer(arg1);
        else if (comando == "unir")
            unir(arg1, arg2, arg3, arg4);
        else if (comando == "tiempo")
            tiempo();
        else if (comando == "sumar")
            sumar(arg1, arg2);
        else if (comando == "restar")
            restar(arg1, arg2);
        else if (comando == "multiplicar")
            multiplicar(arg1, arg2);
        else if (comando == "dividir")
            dividir(arg1, arg2);
        else if (comando == "limpiar")
            limpiar();
        else if (comando == "mostrardirectorio")
            mostrar_directorio();
        else if (comando == "creararchivo")
            crear_archivo(arg1);
        else if (comando == "celar")
            celar();
        else if (comando == "instrucciones")
            instrucciones();
        else if (comando == "salir")
            return;
        else
            cout << "> \"" << comando << "\": Comando invalido."; 
        
        cout << endl;
    }
}



int main()
{
    srand (time(NULL)); // Inicializa el generador de aleatorios para la funcion celar.
    prompt();
    return 0;
}