#ifndef STEMMER_H
#define STEMMER_H

#include "porter_stemmer.h"

class stemmer
{
public:
    stemmer(){}
    ~stemmer(){}
    QString root(QString word){
        QString A = Porter2Stemmer::stem(word.toStdString()).c_str();
        return A;
    }
};

#endif // STEMMER_H
