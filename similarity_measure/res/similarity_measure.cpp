#include "similarity_measure.h"

double dot_product(QVector<double> v1, QVector<double> v2) {
    if(v1.size() != v2.size())
        return 0;

    QVector<double>::iterator
            it1_B = v1.begin(),
            it1_E = v1.end(),
            it2_B = v2.begin();

    double temp = 0;

    while(it1_B != it1_E) {
        temp += *it1_B * *it2_B;
        ++it1_B;
        ++it2_B;
    }

    return temp;
}

double euclidean_normalization(QVector<double> vect) {
    QVector<double>::iterator
            it_B = vect.begin(),
            it_E = vect.end();

    double temp = 0;

    while(it_B != it_E) {
        temp += pow((*it_B), 2.0);
        ++it_B;
    }

    temp = sqrt(temp);
    return temp;
}

double cosine_similarity(QVector<double> v1, QVector<double> v2) {
    return (dot_product(v1, v2) / (euclidean_normalization(v1) * euclidean_normalization(v2)));
}
