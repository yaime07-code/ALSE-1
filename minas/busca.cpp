#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Buscaminas {
private:
    int filas, columnas, minas;
    vector<vector<int>> tablero;      // -1 = mina, otro = número de minas alrededor
    vector<vector<bool>> visible;     // casillas reveladas
    vector<vector<bool>> banderas;    // casillas marcadas con bandera
    bool juegoTerminado;

public:
    Buscaminas(int f=10, int c=10, int m=15) {
        filas = f;
        columnas = c;
        minas = m;
        juegoTerminado = false;

        tablero.assign(filas, vector<int>(columnas, 0));
        visible.assign(filas, vector<bool>(columnas, false));
        banderas.assign(filas, vector<bool>(columnas, false));

        generarMinas();
        contarMinas();
    }

    void generarMinas() {
        srand(time(0));
        int colocadas = 0;
        while (colocadas < minas) {
            int i = rand() % filas;
            int j = rand() % columnas;
            if (tablero[i][j] != -1) {
                tablero[i][j] = -1;
                colocadas++;
            }
        }
    }

    void contarMinas() {
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                if (tablero[i][j] == -1) continue;
                int contador = 0;
                for (int x = -1; x <= 1; x++) {
                    for (int y = -1; y <= 1; y++) {
                        int ni = i + x, nj = j + y;
                        if (ni >= 0 && ni < filas && nj >= 0 && nj < columnas && tablero[ni][nj] == -1) {
                            contador++;
                        }
                    }
                }
                tablero[i][j] = contador;
            }
        }
    }

    void mostrarTablero(bool revelarTodo=false) {
        cout << "   ";
        for (int j = 0; j < columnas; j++) cout << j << " ";
        cout << endl;

        for (int i = 0; i < filas; i++) {
            cout << i << " |";
            for (int j = 0; j < columnas; j++) {
                if (revelarTodo || visible[i][j]) {
                    if (tablero[i][j] == -1) cout << "💣";
                    else if (tablero[i][j] == 0) cout << " ";
                    else cout << tablero[i][j];
                } else if (banderas[i][j]) {
                    cout << "🚩";
                } else {
                    cout << "#";
                }
                cout << " ";
            }
            cout << endl;
        }
    }

    void revelar(int i, int j) {
        if (i < 0 || i >= filas || j < 0 || j >= columnas || visible[i][j] || banderas[i][j]) return;

        visible[i][j] = true;

        if (tablero[i][j] == -1) {
            juegoTerminado = true;
            cout << "\n💥 ¡Boom! Has pisado una mina.\n";
            mostrarTablero(true);
            return;
        }

        if (tablero[i][j] == 0) {
            // Revelar vecinos
            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    revelar(i+x, j+y);
                }
            }
        }
    }

    void alternarBandera(int i, int j) {
        if (i < 0 || i >= filas || j < 0 || j >= columnas || visible[i][j]) return;
        banderas[i][j] = !banderas[i][j];
    }

    bool terminado() { return juegoTerminado; }
};

int main() {
    int filas = 10, columnas = 10, minas = 15;
    Buscaminas juego(filas, columnas, minas);

    cout << "==== JUEGO DEL BUSCAMINAS ====\n";
    cout << "Comandos:\n";
    cout << "  R fila col   -> Revelar casilla\n";
    cout << "  F fila col   -> Colocar/Quitar bandera 🚩\n";

    while (!juego.terminado()) {
        juego.mostrarTablero();
        char accion;
        int x, y;
        cout << "\nIngresa comando (R/F) y coordenadas: ";
        cin >> accion >> x >> y;

        if (accion == 'R' || accion == 'r') {
            juego.revelar(x, y);
        } else if (accion == 'F' || accion == 'f') {
            juego.alternarBandera(x, y);
        }
    }

    cout << "\nFin del juego.\n";
    return 0;
}
