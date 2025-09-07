#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm> // sort, find

using namespace std;

int main() {
    int nDias;
    cout << "Cuantos dias se registraran? ";
    cin >> nDias;

    // 1. Declarar vector dinamico de temperaturas
    vector<float> temperaturas(nDias);

    for (int i = 0; i < nDias; i++) {
        cout << "Ingrese la temperatura del dia " << (i + 1) << ": ";
        cin >> temperaturas[i];
    }

    // 2. Mostrar temperaturas usando puntero y calcular promedio
    float suma = 0;
    float* ptr = temperaturas.data(); // puntero al inicio del vector

    cout << "\nTemperaturas registradas:\n";
    for (int i = 0; i < nDias; i++) {
        cout << "Dia " << (i + 1) << ": " << *(ptr + i) << " C\n";
        suma += *(ptr + i);
    }
    cout << "Temperatura promedio: " << (suma / nDias) << " C\n";

    // 3. Buscar temperatura especifica
    float tempBuscar;
    cout << "\nIngrese una temperatura a buscar: ";
    cin >> tempBuscar;

    bool encontrada = false;
    for (int i = 0; i < nDias; i++) {
        if (temperaturas[i] == tempBuscar) {
            cout << "La temperatura " << tempBuscar << " C se encontro en el dia " << (i + 1) << ".\n";
            encontrada = true;
            break;
        }
    }
    if (!encontrada) {
        cout << "La temperatura no existe en el registro.\n";
    }

    // 4. Ordenar temperaturas
    sort(temperaturas.begin(), temperaturas.end());
    cout << "\nTemperaturas ordenadas:\n";
    for (float t : temperaturas) {
        cout << t << " C ";
    }
    cout << "\n";

    // 5. Manejo de lista de equipos
    list<string> equipos;
    int nEquipos;
    cout << "\nCuantos equipos desea registrar? ";
    cin >> nEquipos;
    cin.ignore();

    for (int i = 0; i < nEquipos; i++) {
        string nombre;
        cout << "Ingrese el nombre del equipo " << (i + 1) << ": ";
        getline(cin, nombre);
        equipos.push_back(nombre);
    }

    cout << "\nLista de equipos registrados:\n";
    for (auto it = equipos.begin(); it != equipos.end(); ++it) {
        cout << *it << "\n";
    }

    // Buscar equipo
    string buscarEquipo;
    cout << "\nIngrese el nombre de un equipo a buscar: ";
    getline(cin, buscarEquipo);
    auto it = find(equipos.begin(), equipos.end(), buscarEquipo);

    if (it != equipos.end()) {
        cout << "El equipo '" << buscarEquipo << "' fue encontrado en la lista.\n";
    } else {
        cout << "El equipo no esta en la lista.\n";
    }

    // Ordenar lista
    equipos.sort();
    cout << "\nLista de equipos ordenada:\n";
    for (const auto& eq : equipos) {
        cout << eq << "\n";
    }

    // Eliminar equipo
    string eliminarEquipo;
    cout << "\nIngrese el nombre de un equipo a eliminar: ";
    getline(cin, eliminarEquipo);
    equipos.remove(eliminarEquipo);

    cout << "\nLista de equipos despues de eliminar '" << eliminarEquipo << "':\n";
    for (const auto& eq : equipos) {
        cout << eq << "\n";
    }

    // Nota de autoevaluacion
    cout << "\n-----------------------------------\n";
    cout << "Autoevaluacion: 10/10\n";
    cout << "Nombre completo: [Tu Nombre Aqui]\n";
    cout << "-----------------------------------\n";

    return 0;
}


// Edwin Moises Cruz Perla autoevaluacion :9