#include <iostream>
#include <escenario.h>
using namespace std;

//PROTOTIPOS
int showMenu();
void playOption(int option);

//VARIABLES
Escenario miEscenario;

int main()
{    
    double d, Ho, Hd;
    cout << "Bienvenido al sistema de simulacion" << endl << endl;
    cout << "Por favor ingrese los parametros de configuracion de escenario." << endl << endl;
    cout << "Indique la distancia horizontal entre en caniones: ";
    cin >> d;
    cout << "Indique la altura en metros del canion ofensivo: ";
    cin >> Ho;
    cout << "Indique la altura en metros del canion defensivo: ";
    cin >> Hd;
    // Con los parametros se puede inicializar el escenario
    miEscenario = Escenario(d, Ho, Hd);
    // Inicializa elementos
    int option = -1; // Opción seleccionada
    while (option != 0) {
        system("CLS");
        // Mostrar en pantalla menu de configuracion inicial.
        option = showMenu();
        // Se ejecuta la accion seleccionada.
        playOption(option);
    }

    return 0;
}

int showMenu() {
    int opt=0;
    cout << endl << "MENU DE OPCIONES" << endl << endl;
    cout << "1. Generar disparos (al menos tres) ofensivos que comprometan la integridad del canion defensivo." << endl;
    cout << "2. Generar disparos (al menos tres) defensivos que comprometan la integridad del canion ofensivo." << endl;
    cout << "3. Dado un disparo ofensivo, generar (al menos tres) disparos defensivos, que impidan la destruccion del canion" << endl << "   defensivo sin importar el canion ofensivo" << endl;
    cout << "4. Dado un disparo ofensivo, generar (al menos tres) disparos defensivos, que impidan la destruccion de ambos caniones." << endl;
    cout << "5. Dado un disparo ofensivo efectivo, y un disparo defensivo efectivo para dicho ataque, generar (al menos tres)" << endl << "   disparos ofensivos, que neutralicen la defensa y permitan la efectividad del disparo ofensivo inicial." << endl;
    cout << "0. Salir" << endl;
    cout << endl << "Indique una opcion: ";
    cin >> opt;
    return opt;
}

void playOption(int option) {
    // Se valida la opcion ingresada
    switch (option) {
        case 1:
            MiRed.show();
            break;
        case 2:
            MiRed.addRouter();
            break;
        case 3:
            MiRed.removeRouter();
            break;
        case 4:
            MiRed.pathCalculate();
            break;
        case 5:
            MiRed.pathCalculate();
            break;
        case 6:
            MiRed.loadConfig();
            break;
        case 7:
            MiRed.loadRandom();
            break;
        case 0:
            return;
            break;
        default:
            cout << endl << "\tLa opcion seleccionada no es válida." << endl;
        break;
    }
}
