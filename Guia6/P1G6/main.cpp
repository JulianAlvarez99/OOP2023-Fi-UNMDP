#include <iostream>
#include <limits>


using namespace std;


double leerDouble()
{
    cin.exceptions(ios::failbit | ios::badbit);

    double dato = 0.0;
    try
    {
        cin >> dato;
    }
    catch(ios_base::failure &e)
    {
        cout<<e.what()<<": dato no valido" << endl;
        cin.clear();
        cin.ignore(numeric_limits<int>::max(), '\n');
    }
    return dato;
}
/**
cin.exceptions(ios::failbit | ios::badbit);: Esta línea configura las excepciones de cin para que lance una excepción en caso de que ocurra un error de lectura (ios::failbit) o un error grave (ios::badbit). Esto permite manejar los errores de entrada de manera más eficiente.

double dato = 0.0;: Aquí se declara una variable dato de tipo double y se inicializa con el valor 0.0. Esta variable se usará para almacenar el valor ingresado por el usuario.

try { ... }: Se inicia un bloque try para capturar excepciones que puedan ocurrir durante la lectura del valor.

cin >> dato;: En esta línea, se intenta leer un valor de tipo double desde la entrada estándar (cin) y se almacena en la variable dato. Si el usuario ingresa un valor inválido (como una letra en lugar de un número), se generará una excepción.

catch(ios_base::failure &e) { ... }: Si se produce una excepción durante la lectura en el bloque try, se captura y se maneja en el bloque catch. La excepción capturada es de tipo ios_base::failure.

cout << e.what() << ": dato no válido" << endl;: Aquí se imprime un mensaje de error que incluye el texto retornado por e.what(), que proporciona información sobre la excepción específica que se produjo. El mensaje también indica que el dato no es válido.

cin.clear();: Esta línea se utiliza para restablecer el estado de cin, eliminando las banderas de error. Esto permite que cin siga siendo útil para futuras lecturas.

cin.ignore(numeric_limits<int>::max(), '\n');: Se llama a cin.ignore() para eliminar cualquier entrada incorrecta que quedó en el búfer de entrada después del error. Esto permite continuar con futuras operaciones de entrada sin problemas.

return dato;: Finalmente, la función devuelve el valor dato, que podría ser 0.0 si se produjo un error durante la lectura o el valor válido que ingresó el usuario.

**/


int main()
{
    cout << leerDouble() << endl;
    return 0;
}
