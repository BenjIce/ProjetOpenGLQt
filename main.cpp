#include <QApplication>
#include "GLTourelle.h"
#include "GLSphere.h"
#include <QtOpenGL>
#include <fenprincipale.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    FenPrincipale principale;


    //Affichage de la fenêtre
    principale.show();

    return app.exec();
}
