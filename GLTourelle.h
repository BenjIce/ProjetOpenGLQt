#ifndef GLTOURELLE_H
#define GLTOURELLE_H

#include "myGLWidget.h"  //Heritage du Widget OpenGL
#include <GL/glu.h> //Intégration des fonctions glu

class GLTourelle : public myGLWidget
{
    Q_OBJECT
public:
    explicit GLTourelle(QWidget *parent = 0, int longueur = 100, int hauteur = 100 );
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();

};

#endif // GLTOURELLE_H

