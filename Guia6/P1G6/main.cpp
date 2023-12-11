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
cin.exceptions(ios::failbit | ios::badbit);: Esta l�nea configura las excepciones de cin para que lance una excepci�n en caso de que ocurra un error de lectura (ios::failbit) o un error grave (ios::badbit). Esto permite manejar los errores de entrada de manera m�s eficiente.

double dato = 0.0;: Aqu� se declara una variable dato de tipo double y se inicializa con el valor 0.0. Esta variable se usar� para almacenar el valor ingresado por el usuario.

try { ... }: Se inicia un bloque try para capturar excepciones que puedan ocurrir durante la lectura del valor.

cin >> dato;: En esta l�nea, se intenta leer un valor de tipo double desde la entrada est�ndar (cin) y se almacena en la variable dato. Si el usuario ingresa un valor inv�lido (como una letra en lugar de un n�mero), se generar� una excepci�n.

catch(ios_base::failure &e) { ... }: Si se produce una excepci�n durante la lectura en el bloque try, se captura y se maneja en el bloque catch. La excepci�n capturada es de tipo ios_base::failure.

cout << e.what() << ": dato no v�lido" << endl;: Aqu� se imprime un mensaje de error que incluye el texto retornado por e.what(), que proporciona informaci�n sobre la excepci�n espec�fica que se produjo. El mensaje tambi�n indica que el dato no es v�lido.

cin.clear();: Esta l�nea se utiliza para restablecer el estado de cin, eliminando las banderas de error. Esto permite que cin siga siendo �til para futuras lecturas.

cin.ignore(numeric_limits<int>::max(), '\n');: Se llama a cin.ignore() para eliminar cualquier entrada incorrecta que qued� en el b�fer de entrada despu�s del error. Esto permite continuar con futuras operaciones de entrada sin problemas.

return dato;: Finalmente, la funci�n devuelve el valor dato, que podr�a ser 0.0 si se produjo un error durante la lectura o el valor v�lido que ingres� el usuario.

**/


int main()
{
    cout << leerDouble() << endl;
    return 0;
}
