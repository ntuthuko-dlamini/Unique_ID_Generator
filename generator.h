#ifndef GENERATOR_H
#define GENERATOR_H
#include <QString>
#include <QDebug>

class Generator{

    public:
        Generator(QString fname);
        QString calculateUniqueID();
        QString calculateInitialKey();

    private:
        QString fullName;
        QString uniqueId;
        QString initialKey;

};
#endif // GENERATOR_H
