#ifndef FENPRINCIPALE_H
#define FENPRINCIPALE_H

//#include <QApplication>
//#include <QtWidgets>
#include <GLTourelle.h>
#include <GLSphere.h>

class FenPrincipale : public QWidget
{
    Q_OBJECT
public:
    FenPrincipale();


public slots:
    void MAJdelta(int delta);
    void MAJomega(int omega);

signals:
     void deltaChanged(double newDelta);
     void omegaChanged(double newOmega);
     void xChanged(double newX);
     void yChanged(double newY);
     void zChanged(double newZ);

private:
    GLTourelle *tourelle3D;
    GLSphere *sphere;
    QLCDNumber *lcd_omega;
    QSlider *slider_omega;
    QLCDNumber *lcd_delta;
    QSlider *slider_delta;
    QLabel *label;
    QLCDNumber *x_disp;
    QLCDNumber *y_disp;
    QLCDNumber *z_disp;
    double omega_value;
    double delta_value;
    double x;
    double y;
    double z;

public slots:


};

#endif // FENPRINCIPALE_H
