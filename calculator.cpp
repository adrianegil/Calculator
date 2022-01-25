#include "calculator.h"
#include "ui_calculator.h"

#include <math.h>

double calVal = 0;

bool divTrigger = false;
bool multTrigger = false;
bool subTrigger = false;
bool addTrigger = false;




Calculator::Calculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Calculator)
{

    ui->setupUi(this);


    ui->Display->setText(QString::number(calVal));


    // BOTONES NUMEROS 0-9
    connect(ui->pushButton_0 , SIGNAL(released()),this, SLOT(NumPressed()));
    connect(ui->pushButton_1, SIGNAL(released()),this, SLOT(NumPressed()));
    connect(ui->pushButton_2, SIGNAL(released()),this, SLOT(NumPressed()));
    connect(ui->pushButton_3, SIGNAL(released()),this, SLOT(NumPressed()));
    connect(ui->pushButton_4, SIGNAL(released()),this, SLOT(NumPressed()));
    connect(ui->pushButton_5, SIGNAL(released()),this, SLOT(NumPressed()));
    connect(ui->pushButton_6, SIGNAL(released()),this, SLOT(NumPressed()));
    connect(ui->pushButton_7, SIGNAL(released()),this, SLOT(NumPressed()));
    connect(ui->pushButton_8, SIGNAL(released()),this, SLOT(NumPressed()));
    connect(ui->pushButton_9, SIGNAL(released()),this, SLOT(NumPressed()));


    // BOTON PUNTO
    connect(ui->pushButton_Point, SIGNAL(released()),this, SLOT(PressedPointer()));

    // BOTONES OPERANDOS
    connect(ui->pushButton_Div, SIGNAL(released()),this, SLOT(MathButtonPressed()));
    connect(ui->pushButton_Mul, SIGNAL(released()),this, SLOT(MathButtonPressed()));
    connect(ui->pushButton_Sub, SIGNAL(released()),this, SLOT(MathButtonPressed()));
    connect(ui->pushButton_Add, SIGNAL(released()),this, SLOT(MathButtonPressed()));

    // BOTONES FUNCIONES
    connect(ui->pushButton_Sen, SIGNAL(released()),this, SLOT(Seno()));
    connect(ui->pushButton_Cos, SIGNAL(released()),this, SLOT(Coseno()));
    connect(ui->pushButton_Exp, SIGNAL(released()),this, SLOT(Exponencial()));
    connect(ui->pushButton_Ln, SIGNAL(released()),this, SLOT(Logaritmo()));
    connect(ui->pushButton_Tan, SIGNAL(released()),this, SLOT(Tangente()));

    // BOTONES OTRAS FUNCIONES
    connect(ui->pushButton_SquareRoot, SIGNAL(released()),this, SLOT(SquareRoot()));
    connect(ui->pushButton_ChangeSign, SIGNAL(released()),this, SLOT(ChangeNumberSign()));
    connect(ui->pushButton_Mod, SIGNAL(released()),this, SLOT(Absoluto()));
    connect(ui->pushButton_Fact, SIGNAL(released()),this, SLOT(Factorial()));
    connect(ui->pushButton_Square, SIGNAL(released()),this, SLOT(Square()));

    // BOTONES ELIMINAR
    connect(ui->pushButton_CLOne, SIGNAL(released()),this, SLOT(ClearOne()));
    connect(ui->pushButton_AC, SIGNAL(released()),this, SLOT(Clear()));

    // BOTON RESULTADO
    connect(ui->pushButton_Equals, SIGNAL(released()),this, SLOT(EqualButton()));


}

Calculator::~Calculator()
{
    delete ui;
}



// MIS FUNCIONES

void Calculator::NumPressed(){

    QPushButton *button = (QPushButton *)sender();
    QString butVal = button->text();
    QString displayVal = ui->Display->text();




    {
        QString newVal = displayVal + butVal;
        double dblNewVal = newVal.toDouble();
        ui ->Display->setText(QString::number(dblNewVal,'g',16));

    }


}

void Calculator::MathButtonPressed(){

    divTrigger = false;
    multTrigger = false;
    subTrigger = false;
    addTrigger = false;

    QString displayVal = ui->Display->text();
    calVal = displayVal.toDouble();


    QPushButton *button = (QPushButton *)sender();

    QString butVal = button->text();

    if(QString::compare(butVal,"÷",Qt::CaseInsensitive)==0){
        ui->DisplayAux->setText(QString::number(calVal) + " ÷ " );
        divTrigger = true;
    }
    else  if(QString::compare(butVal,"×",Qt::CaseInsensitive)==0){

        ui->DisplayAux->setText(QString::number(calVal) + " × " );
        multTrigger = true;
    }
    else  if(QString::compare(butVal,"-",Qt::CaseInsensitive)==0){

       ui->DisplayAux->setText(QString::number(calVal) + " - " );
       subTrigger = true;
    }
    else  if(QString::compare(butVal,"+",Qt::CaseInsensitive)==0){
        ui->DisplayAux->setText(QString::number(calVal) + " + " );
        addTrigger = true;
    }

   ui->Display->setText("");


}

void Calculator::EqualButton(){


    double solution = 0.0;

    QString displayVal = ui->Display->text();

    double dblDisplayVal = displayVal.toDouble();


    if(divTrigger||multTrigger||subTrigger||addTrigger){

        if(divTrigger){

            solution = calVal/dblDisplayVal;

             ui->DisplayAux->setText(QString::number(calVal) + " ÷ " + QString::number(dblDisplayVal));

            divTrigger= false;

        }else if(multTrigger){

            solution = calVal*dblDisplayVal;

             ui->DisplayAux->setText(QString::number(calVal) + " × " + QString::number(dblDisplayVal));

              multTrigger= false;

        }if(subTrigger){

            solution = calVal-dblDisplayVal;

             ui->DisplayAux->setText(QString::number(calVal) + " - " + QString::number(dblDisplayVal));


             subTrigger= false;


        }if(addTrigger){

            solution = calVal+dblDisplayVal;


            ui->DisplayAux->setText(QString::number(calVal) + " + " + QString::number(dblDisplayVal));

            addTrigger = false;

        }


    }

    ui->Display->setText(QString::number(solution));


    calVal = solution;

}

void Calculator::ChangeNumberSign(){


    QString displayVal = ui->Display->text();

    double dblDisplayVal = displayVal.toDouble();

    double dblDisplayValSign = -1 * dblDisplayVal;


    ui->Display->setText(QString::number(dblDisplayValSign));

}

void Calculator::SquareRoot(){

    QString displayVal = ui->Display->text();

    double dblDisplayVal = displayVal.toDouble();

    double dblDisplaySQRT = sqrt(dblDisplayVal);

   ui->DisplayAux->setText("√("+QString::number(dblDisplayVal)+")");
    ui->Display->setText(QString::number(dblDisplaySQRT));


}

void Calculator::Seno(){

    QString displayVal = ui->Display->text();

    double dblDisplayVal = displayVal.toDouble();

    double dblDisplaySeno = sin(dblDisplayVal);

    ui->DisplayAux->setText("sen("+QString::number(dblDisplayVal)+")");
    ui->Display->setText(QString::number(dblDisplaySeno));

}

void Calculator::Coseno(){

    QString displayVal = ui->Display->text();

    double dblDisplayVal = displayVal.toDouble();

    double dblDisplayCoseno = cos(dblDisplayVal);

    ui->DisplayAux->setText("cos("+QString::number(dblDisplayVal)+")");
    ui->Display->setText(QString::number(dblDisplayCoseno));

}

void Calculator::Tangente(){

    QString displayVal = ui->Display->text();

    double dblDisplayVal = displayVal.toDouble();

    double dblDisplayTangente = tan(dblDisplayVal);

    ui->DisplayAux->setText("tan("+QString::number(dblDisplayVal)+")");
    ui->Display->setText(QString::number(dblDisplayTangente));
}

void Calculator::Exponencial(){

    QString displayVal = ui->Display->text();

    double dblDisplayVal = displayVal.toDouble();

    double dblDisplayExp = exp(dblDisplayVal);

    ui->DisplayAux->setText("exp("+QString::number(dblDisplayVal)+")");
    ui->Display->setText(QString::number(dblDisplayExp));



}

void Calculator::Logaritmo(){

    QString displayVal = ui->Display->text();

    double dblDisplayVal = displayVal.toDouble();

    double dblDisplayLog = log(dblDisplayVal);

    ui->DisplayAux->setText("ln("+QString::number(dblDisplayVal)+")");

    ui->Display->setText(QString::number(dblDisplayLog));



}

void Calculator::Absoluto(){

    QString displayVal = ui->Display->text();

    double dblDisplayVal = displayVal.toDouble();

    double dblDisplayAbs = fabsl(dblDisplayVal);

    ui->DisplayAux->setText("|"+QString::number(dblDisplayVal)+"|");

    ui->Display->setText(QString::number(dblDisplayAbs));



}

void Calculator::Factorial(){


    QString displayVal = ui->Display->text();

    double dblDisplayVal = displayVal.toDouble();



    double dblDisplayFac=1;

    if(dblDisplayVal <= 1){

       dblDisplayFac = 1;
    }
    else{

        for (int i = dblDisplayVal; i >= 1; i--) {

            dblDisplayFac*=i;
        }


    }

    ui->DisplayAux->setText(QString::number(dblDisplayVal)+"!");

    ui->Display->setText(QString::number(dblDisplayFac));


}

void Calculator::Square(){

    QString displayVal = ui->Display->text();

    double dblDisplayVal = displayVal.toDouble();

    double dblDisplaySqu = dblDisplayVal * dblDisplayVal;

    ui->DisplayAux->setText("("+QString::number(dblDisplayVal)+")"+"²");

    ui->Display->setText(QString::number(dblDisplaySqu));



}

void Calculator::ClearOne(){

    QString displayVal = ui->Display->text();


    int l = displayVal.length();

       if(l > 1){
       displayVal.resize(l-1);
      }
       else{

           displayVal="0";
       }


ui->Display->setText(displayVal);

}

void Calculator::PressedPointer(){


    QString butVal = ".";
    QString displayVal = ui->Display->text();
    bool found = false;


    for (int i = 0; i < displayVal.length(); i++) {

        if(displayVal[i].toLatin1()=='.'){
            found = true;
        }


    }

    if(!found){


        QString newVal = displayVal + butVal;


      ui ->Display->setText(newVal);
    }


}

void Calculator::Clear(){

    calVal = 0;

   ui->DisplayAux->setText("");
   ui->Display->setText(QString::number(calVal));


}

