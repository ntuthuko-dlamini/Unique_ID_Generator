#include "generator.h"
#include <QRandomGenerator>

Generator::Generator(QString fname):fullName(fname), initialKey(""),uniqueId("")
{}



// function to generate uniqueID
QString Generator::calculateUniqueID() {

    QStringList list;

    //split full name to a lsit of words
    list = fullName.split(" ");


    //  extracting initials
    if(list.length() == 2 || list.length() == 3){


        uniqueId.append((list[0][0]).toUpper());
        uniqueId.append((list[1][0]).toUpper());


        // counting letters excluding spaces
        int letters = 0;

        foreach (QChar var, fullName) {
            if(var.isLetter()){
                letters++;
            }
        }

        //4-digit number
        QString four_digits = QString::number(letters);

         qDebug() << "Letters "<< letters;
         qDebug() << "Four Digits  "<< four_digits;

         while(four_digits.length() < 4){
            four_digits = four_digits + "0";
         }

         uniqueId += four_digits;
    }

    return uniqueId;
}


// Helper function: returns a  vowel character
bool isVowel(QChar c){
    if (c.isLower()){
         return (c == 'a' || c == 'e' || c == 'i'|| c == 'o'|| c == 'u');
    }
    return false;
}


// A function that generate initial key
QString Generator::calculateInitialKey() {

    //remove spaces from the full name and make all characters lowercase
    QString newFullName;
    foreach (QChar var, fullName) {
         if(var.isLetter()) {
            newFullName += var.toLower();
         }
    }

    qDebug() << " Full name without spaces " << newFullName;


    QString vowels;
    QString consonants;

    //Separate vowels and consonant
    foreach (QChar var, newFullName) {
         if(isVowel(var)) {
            vowels += var;
            qDebug()<< "vowels " << vowels;
         } else{
            consonants += var;
            qDebug()<< "consonants " << consonants;

         }
    }


    //shuffling vowel and consonant
    while(initialKey.length() <= 6){
        int vowelRandomIndex = QRandomGenerator::global()->bounded(vowels.length());
        int consonantRandomIndex = QRandomGenerator::global()->bounded(consonants.length());

        // select
        QChar c = consonants.at(consonantRandomIndex);
        QChar v = vowels.at(vowelRandomIndex);

        initialKey += c;
        initialKey += v;

    }

    qDebug() << initialKey;
    return initialKey;
}
