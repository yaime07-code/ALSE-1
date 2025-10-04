#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

struct Complejo {
    double real;
    double imag;
};

const double PI = acos(-1.0);
const double EPS = 1e-12;

// Magnitud
double magnitud(const Complejo &c) {
    return sqrt(c.real*c.real + c.imag*c.imag);
}

// Ángulo en grados desde la forma rectangular, normalizado a [0,360)
double angulo_deg_rect(const Complejo &c) {
    double th = atan2(c.imag, c.real) * 180.0 / PI; // [-180,180]
    // normalizar a [0,360)
    double mod = fmod(th, 360.0);
    if (mod < 0) mod += 360.0;
    return mod;
}

double normalize_deg(double th) {
    double mod = fmod(th, 360.0);
    if (mod < 0) mod += 360.0;
    return mod;
}

// Suma, resta, multiplicacion y division
Complejo sumaC(const Complejo &a, const Complejo &b) {
    return {a.real + b.real, a.imag + b.imag};
}

Complejo restaC(const Complejo &a, const Complejo &b) {
    return {a.real - b.real, a.imag - b.imag};
}

Complejo multiplicacion(const Complejo &a, const Complejo &b) {
    return { a.real*b.real - a.imag*b.imag, a.real*b.imag + a.imag*b.real };
}

bool divisionC(const Complejo &a, const Complejo &b, Complejo &out) {
    double denom = b.real*b.real + b.imag*b.imag;
    if (denom < EPS) return false; // division por cero o inestable
    out.real = (a.real*b.real + a.imag*b.imag) / denom;
    out.imag = (a.imag*b.real - a.real*b.imag) / denom;
    return true;
}

// Paralelo: Zpar = (Z1*Z2)/(Z1+Z2)
bool paralelo(const Complejo &z1, const Complejo &z2, Complejo &out) {
    Complejo sum = sumaC(z1, z2);
    Complejo prod = multiplicacion(z1, z2);
    return divisionC(prod, sum, out);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Complejo num1{}, num2{};
    cout << "Ingrese la parte real del primer numero complejo: ";
    if(!(cin >> num1.real)) return 0;
    cout << "Ingrese la parte imaginaria del primer numero complejo: ";
    cin >> num1.imag;
    cout << "Ingrese la parte real del segundo numero complejo: ";
    cin >> num2.real;
    cout << "Ingrese la parte imaginaria del segundo numero complejo: ";
    cin >> num2.imag;

    Complejo s = sumaC(num1, num2);
    Complejo r = restaC(num1, num2);
    Complejo p = multiplicacion(num1, num2);
    Complejo zpar;

    bool ok_paral = paralelo(num1, num2, zpar);

    cout << fixed << setprecision(6);
    cout << "\n--- Rectangular ---\n";
    cout << "Num1: " << num1.real << " + " << num1.imag << "i\n";
    cout << "Num2: " << num2.real << " + " << num2.imag << "i\n";
    cout << "Suma: " << s.real << " + " << s.imag << "i\n";
    cout << "Resta: " << r.real << " + " << r.imag << "i\n";
    cout << "Producto: " << p.real << " + " << p.imag << "i\n";
    if (ok_paral)
        cout << "Paralelo: " << zpar.real << " + " << zpar.imag << "i\n";
    else
        cout << "Paralelo: NO DEFINIDO (Z1+Z2 ≈ 0)\n";

    cout << "\n--- Fasorial (polar) ---\n";
    // ángulos desde forma rectangular
    double a1 = angulo_deg_rect(num1);
    double a2 = angulo_deg_rect(num2);
    double as = angulo_deg_rect(s);
    double ar = angulo_deg_rect(r);
    double ap = angulo_deg_rect(p);
    double apar = ok_paral ? angulo_deg_rect(zpar) : NAN;

    cout << "Num1:   " << magnitud(num1) << " ∠ " << a1 << "°\n";
    cout << "Num2:   " << magnitud(num2) << " ∠ " << a2 << "°\n";
    cout << "Suma:   " << magnitud(s)    << " ∠ " << as << "°\n";
    cout << "Resta:  " << magnitud(r)    << " ∠ " << ar << "°\n";
    cout << "Producto (rect): " << magnitud(p) << " ∠ " << ap << "°\n";
    if (ok_paral) cout << "Paralelo (rect): " << magnitud(zpar) << " ∠ " << apar << "°\n";

    // --- Comprobaciones por álgebra de fases (útil para debug) ---
    cout << "\n--- Comprobaciones (polar arithmetic) ---\n";
    // producto: ángulo(producto) debería ≈ a1 + a2 (normalizado)
    double ap_by_sum = normalize_deg(a1 + a2);
    cout << "Ángulo producto (atan2): " << ap << "°\n";
    cout << "Ángulo producto (a1 + a2): " << ap_by_sum << "°\n";
    cout << "Diferencia absoluta: " << fabs(normalize_deg(ap - ap_by_sum)) << "°\n";

    // paralelo: angle(paralelo) = a1 + a2 - angle( z1 + z2 )
    if (ok_paral) {
        double angle_sum = angulo_deg_rect(s); // ángulo de Z1+Z2
        double apar_by_formula = normalize_deg(a1 + a2 - angle_sum);
        cout << "Ángulo paralelo (atan2): " << apar << "°\n";
        cout << "Ángulo paralelo (a1+a2-angle(Z1+Z2)): " << apar_by_formula << "°\n";
        cout << "Diferencia absoluta: " << fabs(normalize_deg(apar - apar_by_formula)) << "°\n";
    } else {
        cout << "No se pudo comprobar paralelo (Z1+Z2 ≈ 0)\n";
    }

    return 0;
}
