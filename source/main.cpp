#include <iostream>

using namespace std;

int main()
{
    int opMenu;
    double d, Ho, Hd;
    cout << "Bienvenido al sistema de simulacion" << endl << endl;
    cout << "Por favor ingrese los parametros de configuracion de escenario." << endl << endl;
    cout << "Indique la distancia horizontal entre en caniones: ";
    cin >> d;
    cout << "Indique la altura en metros del canion ofensivo: ";
    cin >> Ho;
    cout << "Indique la altura en metros del canion defensivo: ";
    cin >> Hd;
    while (true) {
        // Menu para seleccionar las opciones a simular
        cout << endl << "MENU DE OPCIONES" << endl << endl;
        cout << "1. Generar disparos (al menos tres) ofensivos que comprometan la integridad del canion defensivo." << endl;
        cout << "2. Generar disparos (al menos tres) defensivos que comprometan la integridad del canion ofensivo." << endl;
        cout << "3. Dado un disparo ofensivo, generar (al menos tres) disparos defensivos, que impidan la destruccion del canion" << endl << "   defensivo sin importar el canion ofensivo" << endl;
        cout << "4. Dado un disparo ofensivo, generar (al menos tres) disparos defensivos, que impidan la destruccion de ambos caniones." << endl;
        cout << "5. Dado un disparo ofensivo efectivo, y un disparo defensivo efectivo para dicho ataque, generar (al menos tres)" << endl << "   disparos ofensivos, que neutralicen la defensa y permitan la efectividad del disparo ofensivo inicial." << endl;
        cout << "6. Salir" << endl;
        cout << endl << "Indique una opcion: ";
        cin >> opMenu;
        switch (opMenu) {
            case 6:
                exit(0);
                break;
            default:
                cout << "La opcion seleccionada no existe";
                break;
        }
    }

    return 0;
}
