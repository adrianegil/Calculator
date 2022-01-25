#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>


namespace Ui {
class Calculator;
}

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    explicit Calculator(QWidget *parent = 0);
    ~Calculator();

private:
    Ui::Calculator *ui;


  private slots:

    void PressedPointer();
    void NumPressed();
    void MathButtonPressed();
    void EqualButton();
    void ChangeNumberSign();
    void SquareRoot();
    void Seno();
    void Coseno();
    void Tangente();
    void Exponencial();
    void Logaritmo();
    void Absoluto();
    void Factorial();
    void Square();
    void ClearOne();
    void Clear();

};

#endif // CALCULATOR_H
