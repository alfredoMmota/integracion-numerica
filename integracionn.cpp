//Programa elaborado para la solucion del metodo de integracion numerica version 1.0
#include "integracionn.h"
#include "ui_integracionn.h"
#include "math.h"
#include "cmath"//se agrega las librerias matematicas

integracionN::integracionN(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::integracionN)
{
    ui->setupUi(this);//se conectan los botones de la interfaz con el programa principal
                      //the buttons of the interface are connected to the main program
    connect(ui->evaluar,SIGNAL(clicked()),this,SLOT(Calcular()));
    connect(ui->clear,SIGNAL(clicked()),this,SLOT(Borrar()));
}
integracionN::~integracionN()
{
    delete ui;
}
//se declara la funcion que se va a utilizar para este metodo
//the function that is going to be used for this method is declared
double integracionN::Funcion(double x){
    return ((1/sqrt(2*3.1416))*exp(-(pow(x,2)/2)));
}
//se define lo que el programa realizara dentro de la funcion Calcular
//define what the program will do within the function Calculate
void integracionN::Calcular(){
    QString resultado,valor1,valor2;//se crean variables de tipo cadena para el resultado
                                    //String variables are created for the result
    double h,a,b,n,Integral,X0,X1,X2,X3,X4,X5,X6,error,valorR;//se definen variables de tipo doble para la solucion del problema
                                                              //double-type variables are defined for the solution of the problem
    valorR=0.682689;//se ingresa el valor verdadero de la integral para ver el error absoluto
                    //you enter the true value of the integral to see the absolute error
    b=ui->limext->value();//se toman los valores de los spin box para el desarrollo del metodo
                          //the values ​​of the spin boxes are taken for the development of the method
    a=ui->liminf->value();
    n=ui->intervalo->value();
    h=(b-a)/n;//se calcula el valor de h
              //the value of h is calculated
    X0=a;//se definen los valores de los intervalos
         //the values ​​of the intervals are defined
    X1=X0+h;
    X2=X1+h;
    X3=X2+h;
    X4=X3+h;
    X5=X4+h;
    X6=X5+h;
    //se realiza la formula para la determinacion del valor de la integral
    //the formula for the determination of the value of the integral is made
    Integral=(((h/2)*(Funcion(X0)+Funcion(X1)))+((h/2)*(Funcion(X1)+Funcion(X2)))+((h/2)*(Funcion(X2)+Funcion(X3)))+
              ((h/2)*(Funcion(X3)+Funcion(X4)))+((h/2)*(Funcion(X4)+Funcion(X5)))+((h/2)*(Funcion(X5)+Funcion(X6))));
    error=100*std::abs((Integral-valorR)/Integral);//se calcula el valor del error
                                                   //the error value is calculated
    //se crea el mensaje que se mostrara en la interfaz
    //the message that will be displayed on the interface is created
    resultado.append("El valor aproximado de la integral es: ").append(valor1.setNum(Integral)).append("\nCon un error de: ").
            append(valor2.setNum(error)).append("%");
    ui->Resultado->setText(resultado);//se visualiza el mensaje en la interfaz
                                      //the message is displayed on the interface
}
void integracionN::Borrar(){//se define el funcionamiento de la funcion Borrar
                            //the operation of the Delete function is defined
    ui->intervalo->setValue(0);//se regresan a 0 los valores de los spin box y double spin box
                               //the values ​​of the spin box and double spin box are returned to 0
    ui->limext->setValue(0.0);
    ui->liminf->setValue(0.0);
    ui->Resultado->clear();//se limpia la etiqueta Resultado para el proximo Calculo
                           //The result tag is cleaned for the next calculation
}
//programa elaborado por Jose Alfredo Mendoza Mota,Ana Karen Razo Francisco,Gibran Omar Estrada Gomez y Antonio de Jesus Herrera Diaz
