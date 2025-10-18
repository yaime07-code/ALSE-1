#include <iostream>
#include <vector>
#include <string>
#include <sstream> 
using namespace std;

class Estudiante {
private:
    string carrera;
    double promedio;

public:
    Estudiante(string c, double p) {
        carrera = c;
        promedio = p;
    }
    
    string getCarrera() {
        return carrera;
    }

    double getPromedio() {
        return promedio;
    }

    void setPromedio(double p) {
        if (p > 0)
            promedio = p;
        else
            cout << "El promedio debe ser positivo." << endl;
    }

    void Curso() const {
        cout << "Hola, soy estudiante de la carrera " << carrera << " y mi promedio es de " << promedio << endl;
    }
};

class Empleado {
private:
    string cargo;
    double salario;
public: 
    Empleado(string c, double s){
        cargo = c;
        salario = s;
    }
    
    string getCargo() {
        return cargo;
    }

    double getSalario() {
        return salario;
    }

    void setPromedio(double p) {
        if (p > 0)
            salario = p;
        else
            cout << "El promedio debe ser positivo." << endl;
    }
    void trabajo() const{
        cout << "Trabajo en el cargo "<<cargo<< " y mi salario es de " <<salario<<endl;
    }
};


int main() {
    vector<Estudiante> estudiantes;
    vector<Empleado> empleados;

    int opcion;
    cout << "Seleccione una opción:\n";
    cout << "1. Ingresar estudiantes\n";
    cout << "2. Ingresar empleados\n";
    cout << "Opción: ";
    cin >> opcion;
    cin.ignore(); 
    if (opcion == 1) {
        string linea;
        cout << "\nIngrese los estudiantes (formato: carrera promedio, carrera promedio,...):\n";
        getline(cin, linea);

        stringstream ss(linea);
        string parte;


        while (getline(ss, parte, ',')) {
            stringstream sp(parte);
            string carrera;
            double promedio;
            sp >> carrera >> promedio;

            if (!carrera.empty() && promedio > 0)
                estudiantes.push_back(Estudiante(carrera, promedio));
        }

        cout << "\nLista de estudiantes:\n";
        for (const auto &e : estudiantes) {
            e.Curso();
        }

    } else if (opcion == 2) {
        string linea;
        cout << "\nIngrese los empleados (formato: cargo salario, cargo salario,...):\n";
        cin.ignore();
        getline(cin, linea);

        stringstream ss(linea);
        string parte;

        while (getline(ss, parte, ',')) {
            stringstream sp(parte);
            string cargo;
            double salario;
            sp >> cargo >> salario;

            if (!cargo.empty() && salario > 0)
                empleados.push_back(Empleado(cargo, salario));
        }

        cout << "\nLista de empleados:\n";
        for (const auto &emp : empleados) {
            emp.trabajo();
        }

    } else {
        cout << "Opción no válida." << endl;
    }

    return 0;
}