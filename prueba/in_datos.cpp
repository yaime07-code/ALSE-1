#include <iostream>
#include <sqlite3.h>

int main() {
    sqlite3* db;
    sqlite3_stmt* stmt;
    char* errMsg = nullptr;

    // Abrir la base de datos
    if (sqlite3_open("ejemplo.db", &db)) {
        std::cerr << "Error al abrir base de datos: " << sqlite3_errmsg(db) << std::endl;
        return 1;
    }

    // Insertar datos
    const char* insertSQL = "INSERT INTO datos (valor) VALUES ('Texto desde C++');";
    if (sqlite3_exec(db, insertSQL, nullptr, nullptr, &errMsg) != SQLITE_OK) {
        std::cerr << "Error al insertar datos: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    }

    // Leer datos
    const char* selectSQL = "SELECT id, valor FROM datos;";
    if (sqlite3_prepare_v2(db, selectSQL, -1, &stmt, nullptr) == SQLITE_OK) {
        std::cout << "Contenido de la tabla:\n";
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            int id = sqlite3_column_int(stmt, 0);
            const unsigned char* valor = sqlite3_column_text(stmt, 1);
            std::cout << "ID: " << id << ", Valor: " << valor << std::endl;
        }
        sqlite3_finalize(stmt);
    } else {
        std::cerr << "Error en consulta SELECT\n";
    }

    sqlite3_close(db);
    return 0;
}