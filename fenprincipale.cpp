#include "fenprincipale.h"
#include <math.h>



FenPrincipale::FenPrincipale()
{

    // ----- FENETRE DEBUT -----

    //Titre de la fenêtre
    this->setWindowTitle("Tourelle 3D");

    //Création du layout vertical principal
    QGridLayout *layoutPrincipal = new QGridLayout;


    // ----- 1ERE GROUPBOX -----

    // Création de la GroupBox
    QGroupBox *groupbox1 = new QGroupBox("Modélisations 3D Temps Réel", this);

    // Création du Widget OpenGL
    //tourelle3D = new GLTourelle(this, 400, 240); //Ajout d'une nouvelle tourelle 3D dans la fenêtre d'une taille de 400x240
    sphere = new GLSphere(this, 400, 240); //Ajout d'une nouvelle représentation sphérique dans la fenêtre d'une taille de 400x240

    // Création du Layout OpenGL de la GroupBox1 et ajout des Widgets
    QHBoxLayout *layout1 = new QHBoxLayout;
    //layout1->addWidget(tourelle3D);
    layout1->addWidget(sphere);

    // Ajout du Layout à la GroupBox1
    groupbox1->setLayout(layout1);

    // Ajout de la GroupBox1 au Layout Principal
    layoutPrincipal->addWidget(groupbox1,1,1);

    // ----- 2EME GROUPBOX -----

    // Création de la GroupBox
    QGroupBox *groupbox2 = new QGroupBox("Valeurs des angles", this);

    // Création des Widgets

    //QLine
    QSlider *slider_delta = new QSlider(Qt::Horizontal,this);
    slider_delta->setRange(-90,90);
    QSlider *slider_omega = new QSlider(Qt::Horizontal,this);
    slider_omega->setRange(-180,180);
    QLCDNumber *x_disp = new QLCDNumber;
    x_disp->setSegmentStyle(QLCDNumber::Flat);
    QLCDNumber *y_disp = new QLCDNumber;
    y_disp->setSegmentStyle(QLCDNumber::Flat);
    QLCDNumber *z_disp = new QLCDNumber;
    z_disp->setSegmentStyle(QLCDNumber::Flat);

    QSlider *slider_deltaCons = new QSlider(Qt::Horizontal,this);
    slider_deltaCons->setRange(-90,90);
    QSlider *slider_omegaCons = new QSlider(Qt::Horizontal,this);
    slider_omegaCons->setRange(-180,180);
    QLCDNumber *xCons_disp = new QLCDNumber;
    xCons_disp->setSegmentStyle(QLCDNumber::Flat);
    QLCDNumber *yCons_disp = new QLCDNumber;
    yCons_disp->setSegmentStyle(QLCDNumber::Flat);
    QLCDNumber *zCons_disp = new QLCDNumber;
    zCons_disp->setSegmentStyle(QLCDNumber::Flat);

    // Création des layouts de la GroupBox2 et ajout des Widgets
    QGridLayout *layout2 = new QGridLayout;
    layout2->setColumnStretch(1,2);
    QFormLayout *coordonnees = new QFormLayout;
    coordonnees->addRow("Mesure de delta", slider_delta);
    coordonnees->addRow("Mesure de omega", slider_omega);
    coordonnees->addRow("Mesure - x :",x_disp);
    coordonnees->addRow("Mesure - y :",y_disp);
    coordonnees->addRow("Mesure - z :",z_disp);

    coordonnees->addRow("Consigne de delta", slider_deltaCons);
    coordonnees->addRow("Consigne de omega", slider_omegaCons);
    coordonnees->addRow("Consigne - x :",xCons_disp);
    coordonnees->addRow("Consigne - y :",yCons_disp);
    coordonnees->addRow("Consigne - z :",zCons_disp);

    // Ajout du Layout à la GroupBox2
    layout2->addLayout(coordonnees,1,1);
    groupbox2->setLayout(layout2);

    // Ajout de la GroupBox2 au Layout Principal
    layoutPrincipal->addWidget(groupbox2,2,1);

    //Connections
    QObject::connect(slider_delta,SIGNAL(valueChanged(int)),this,SLOT(MAJdelta(int)));
    QObject::connect(slider_omega,SIGNAL(valueChanged(int)),this,SLOT(MAJomega(int)));
    QObject::connect(this,SIGNAL(xChanged(double)),x_disp,SLOT(display(double)));
    QObject::connect(this,SIGNAL(yChanged(double)),y_disp,SLOT(display(double)));
    QObject::connect(this,SIGNAL(zChanged(double)),z_disp,SLOT(display(double)));

    QObject::connect(slider_deltaCons,SIGNAL(valueChanged(int)),this,SLOT(MAJdeltaCons(int)));
    QObject::connect(slider_omegaCons,SIGNAL(valueChanged(int)),this,SLOT(MAJomegaCons(int)));
    QObject::connect(this,SIGNAL(xConsChanged(double)),xCons_disp,SLOT(display(double)));
    QObject::connect(this,SIGNAL(yConsChanged(double)),yCons_disp,SLOT(display(double)));
    QObject::connect(this,SIGNAL(zConsChanged(double)),zCons_disp,SLOT(display(double)));

    // ----- FENETRE FIN -----

    //Ajout du LayoutPrincipal (vertical) à la fenêtre
    this->setLayout(layoutPrincipal);

}

void FenPrincipale::MAJdelta(int delta){

            delta_value = (double(delta)/180)*M_PI;
            emit deltaChanged(delta_value);

            x = 2*cos(delta_value)*cos(omega_value);
            y = 2*cos(delta_value)*sin(omega_value);
            z = 2*sin(delta_value);
            emit xChanged(x);
            emit yChanged(y);
            emit zChanged(z);
            sphere->setX(x);
            sphere->setY(y);
            sphere->setZ(z);
            sphere->setDelta(delta_value);
            //sphere->setOmega(omega_value);
}

void FenPrincipale::MAJomega(int omega){

    omega_value = (double(omega)/180)*M_PI;
    emit omegaChanged(omega_value);

    x = 2*cos(delta_value)*cos(omega_value);
    y = 2*cos(delta_value)*sin(omega_value);
    z = 2*sin(delta_value);
    emit xChanged(x);
    emit yChanged(y);
    emit zChanged(z);
    sphere->setX(x);
    sphere->setY(y);
    sphere->setZ(z);
    sphere->setOmega(omega_value);
    if (delta_value!=0.0){
    sphere->setDelta(delta_value);
    }
}

void FenPrincipale::MAJdeltaCons(int deltaCons){

            deltaCons_value = (double(deltaCons)/180)*M_PI;
            emit deltaConsChanged(deltaCons_value);

            xCons = 2*cos(deltaCons_value)*cos(omegaCons_value);
            yCons = 2*cos(deltaCons_value)*sin(omegaCons_value);
            zCons = 2*sin(deltaCons_value);
            emit xConsChanged(xCons);
            emit yConsChanged(yCons);
            emit zConsChanged(zCons);
            sphere->setXCons(xCons);
            sphere->setYCons(yCons);
            sphere->setZCons(zCons);
            sphere->setDeltaCons(deltaCons_value);
            //sphere->setOmega(omega_value);
}

void FenPrincipale::MAJomegaCons(int omegaCons){

    omegaCons_value = (double(omegaCons)/180)*M_PI;
    emit omegaConsChanged(omegaCons_value);

    xCons = 2*cos(deltaCons_value)*cos(omegaCons_value);
    yCons = 2*cos(deltaCons_value)*sin(omegaCons_value);
    zCons = 2*sin(deltaCons_value);
    emit xConsChanged(xCons);
    emit yConsChanged(yCons);
    emit zConsChanged(zCons);
    sphere->setXCons(xCons);
    sphere->setYCons(yCons);
    sphere->setZCons(zCons);
    sphere->setOmegaCons(omegaCons_value);
    if (deltaCons_value!=0.0){
    sphere->setDeltaCons(deltaCons_value);
    }
}
