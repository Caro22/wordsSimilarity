#ifndef SIMILARITY_MEASURE_MAP_H
#define SIMILARITY_MEASURE_MAP_H

#include <QMap>
#include <math.h>

typedef int type1;
typedef double type2;
typedef QMap<type1,type2> MY_MAP;

const type2 default_value = 0.0;

double dot_product(MY_MAP &v1, MY_MAP &v2);

double dot_product(MY_MAP &v1, type1 &id1, MY_MAP &v2, type1 &id2);

double euclidean_normalization(MY_MAP &vect);

double cosine_similarity(MY_MAP &v1, MY_MAP &v2);

double cosine_similarity(MY_MAP &v1, type1 id1, MY_MAP &v2, type1 id2);

#endif // SIMILARITY_MEASURE_MAP_H
