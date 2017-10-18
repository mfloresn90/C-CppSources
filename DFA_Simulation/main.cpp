/* 
 * File:   main.cpp
 * Author: mfloresn90
 *
 * Created on August 23, 2017, 9:25 PM
 */

#include <cstdlib>
#include "DfaConfig.hpp"

using namespace std;

int main(int argc, char** argv) {

    DfaConfig dfa;

    dfa.setDfaName("dfa.txt");
    bool result = false;
    int opc = 0;
    int p = 0;
    int cardQ = dfa.getDfaQCardinality();
    int cardF = dfa.getDfaFCardinality();
    int* f = dfa.getDfaF(cardF);
    int* cardSa = dfa.getDfaSaCardinality();
    int total = cardSa[0] * cardSa[1];
    int ** deltaA = dfa.getDfaDeltaA(cardSa[0], cardSa[1], total);
    string regex = dfa.getDfaRegEx();
    string rho;

    do {
        system("clear");
        cout << "\nAutomata Finito Determinista (ADF v1.0)\n" << endl;
        cout << "cardQ = " << cardQ << endl;
        cout << "cardF = " << cardF << endl;
        cout << endl;
        for (int x = 0; x < cardF; x++) {
            cout << "f[" << x << "] = " << f[x] << endl;
        }
        for (int i = 0; i < cardSa[0]; i++) {
            for (int j = 0; j < cardSa[1]; j += 2) {
                cout << "Sa[" << i << "] = " << deltaA[i][j] << " || " << deltaA[i][j + 1] << endl;
            }
        }
        cout << endl;
        cout << "1.- Insertar cadena."
                "\n2.- Salir."
                "\n\n\t¿Que desea hacer? ";
        cin >> opc;

        switch (opc) {

            case 1:
                rho.clear();
                result = false;
                cout << "\nRegEx: " << regex << endl;
                cout << "Inserte la cadena (rho): ";
                cin >> rho;

                p = 0;
                cout << "\nEstado inicial -> (q0) -> ";
                for (int x = 0; x < rho.length(); x++) {
                    //cout << "rho[" << x << "] = " << rho[x] << endl;
                    p = deltaA[p][rho[x] - 48];
                    if (x < rho.length() - 1) {
                        cout << "Se cambio a (q" << p << ") -> ";
                    } else if (x == rho.length() - 1) {
                        cout << "Se cambio a (q" << p << ")" << endl;
                    }
                }

                for (int x = 0; x < cardF; x++) {
                    if (f[x] == p) {
                        result = true;
                    }
                }

                if (result == true) {
                    cout << "\nLa cadena '" << rho << "' es aceptada por el AFD" << endl;
                } else {
                    cout << "\nLa cadena '" << rho << "' no es aceptada por el AFD" << endl;
                }
                rho.clear();
                
                cout << "\nPresiona ENTER para continuar... " << endl;
                //system("pause"); //Windows
                system("read"); //Mac/Linux
                break;

            case 2:
                cout << "\n\nSaliendo..." << endl;
                break;

            default:
                cout << "\n\nOpcion invalida, intentalo de nuevo." << endl;
                cout << "\nPresiona ENTER para continuar... " << endl;
                //system("pause"); //Windows
                system("read"); //Mac/Linux
                break;
        }

    } while (opc != 2);

    return (EXIT_SUCCESS);

}

