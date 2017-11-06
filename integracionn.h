#ifndef INTEGRACIONN_H
#define INTEGRACIONN_H

#include <QMainWindow>

namespace Ui {
class integracionN;
}

class integracionN : public QMainWindow
{
    Q_OBJECT

public:
    explicit integracionN(QWidget *parent = 0);
    ~integracionN();
   double Funcion(double x);//se define la funcion
                            //the function is defined
private:
    Ui::integracionN *ui;
private slots:
    void Calcular();//se definen los metodos que se utilizaran dentro del programa
                    //define the methods that will be used within the program
    void Borrar();
};

#endif // INTEGRACIONN_H
