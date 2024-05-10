#include <QApplication>
#include <QInputDialog>
#include <QMessageBox>
#include "widget.h"
#include "generator.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Widget parentWidget;

    QString fullname = QInputDialog::getText(&parentWidget, "Generator", "Enter your full name here:",QLineEdit::Normal);

    if(!fullname.isEmpty())
    {
        Generator gen(fullname);

        QString key = gen.calculateInitialKey();

        QString id = gen.calculateUniqueID();

        QMessageBox::information(&parentWidget,"Results","Unique ID: "+id+"\nInitial Key: "+key+"");

    } else{
        QMessageBox::information(&parentWidget,"Results","You have not entered a full name:");
    }


    return a.exec();
}
