#ifndef GLSPHERE_H
#define GLSPHERE_H

#include "myGLWidget.h"  //Heritage du Widget OpenGL
#include <GL/glu.h> //Intégration des fonctions glu


class GLSphere : public myGLWidget
{
    Q_OBJECT
public:
    explicit GLSphere(QWidget *parent = 0, int longueur = 100, int hauteur = 100);
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();

    void setX(double X);
    void setY(double Y);
    void setZ(double Z);
    void setOmega(double omega);
    void setDelta(double delta);

private:

      GLfloat x_var;
      GLfloat xo;
      GLfloat y_var;
      GLfloat yo;
      GLfloat z_var;
      double om_var;
      double dl_var;
};

#endif // GLSPHERE_H
