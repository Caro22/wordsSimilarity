#include "similarity_measure_map.h"

#include <iostream>
using namespace std;

double dot_product(MY_MAP &v1, MY_MAP &v2) {
    MY_MAP::iterator
            it1_B = v1.begin(),
            it1_E = v1.end();

    double temp = 0;

    while(it1_B != it1_E) {
        temp += v2.value(it1_B.key(), default_value) * it1_B.value();
        ++it1_B;
    }

    return temp;
}

double dot_product(MY_MAP &v1, type1 &id1, MY_MAP &v2, type1 &id2) {
    double temp = dot_product(v1, v2);

    if(v1.value(id1, default_value) == 0 || v2.value(id2, default_value) == 0)
        temp += v1.value(id2, default_value) * v2.value(id1, default_value);

    return temp;
}

double euclidean_normalization(MY_MAP &vect) {
    MY_MAP::iterator
            it_B = vect.begin(),
            it_E = vect.end();

    double temp = 0;

    while(it_B != it_E) {
        temp += pow(it_B.value(), 2.0);
        ++it_B;
    }

    temp = sqrt(temp * 1.0);
    return temp;
}

double cosine_similarity(MY_MAP &v1, MY_MAP &v2) {
    return (dot_product(v1, v2) * 1.0 / (euclidean_normalization(v1) * euclidean_normalization(v2)));
}

double cosine_similarity(MY_MAP &v1, type1 id1, MY_MAP &v2, type1 id2) {
    return (dot_product(v1, id1, v2, id2) * 1.0 / (euclidean_normalization(v1) * euclidean_normalization(v2)));
}
