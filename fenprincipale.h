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
    void MAJdeltaCons(int deltaCons);
    void MAJomegaCons(int omegaCons);

signals:
     void deltaChanged(double newDelta);
     void omegaChanged(double newOmega);
     void xChanged(double newX);
     void yChanged(double newY);
     void zChanged(double newZ);

     void deltaConsChanged(double newDeltaCons);
     void omegaConsChanged(double newOmegaCons);
     void xConsChanged(double newXCons);
     void yConsChanged(double newYCons);
     void zConsChanged(double newZCons);

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

    QLCDNumber *lcd_omegaCons;
    QSlider *slider_omegaCons;
    QLCDNumber *lcd_deltaCons;
    QSlider *slider_deltaCons;
    QLCDNumber *xCons_disp;
    QLCDNumber *yCons_disp;
    QLCDNumber *z_Consdisp;
    double omegaCons_value;
    double deltaCons_value;
    double xCons;
    double yCons;
    double zCons;



};

#endif // FENPRINCIPALE_H
