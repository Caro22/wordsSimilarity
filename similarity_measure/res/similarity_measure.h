#ifndef SIMILARITY_MEASURE_H
#define SIMILARITY_MEASURE_H

#include <QVector>
#include <math.h>

double dot_product(QVector<double> v1, QVector<double> v2);

double euclidean_normalization(QVector<double> vect);

double cosine_similarity(QVector<double> v1, QVector<double> v2);

#endif // SIMILARITY_MEASURE_H
