#include <QApplication>
#include "Static.h"

int main(int argc, char *argv[]) {
    // Clase que contiene el loop principal
    QApplication app(argc, argv);
    // Instancio el greeter
    StaticImage Static;
    Static.show();
    // Arranca el loop de la UI
    return app.exec();
}
