#ifndef DB_SIMILARITY_H
#define DB_SIMILARITY_H

#include "res/db_connector.h"
#include "res/similarity_measure_map.h"
#include "stemmer/porter_stemmer.h"
#include <vector>

typedef std::pair<double, string> MY_PAIR;
typedef std::vector< MY_MAP > MY_S_VECTOR;
typedef std::vector<MY_PAIR> MY_R_VECTOR;
typedef std::vector<string> String_Vector;

struct heap_pair_comparer {
    inline bool operator() (MY_PAIR &p1, MY_PAIR &p2) {
        //return () ? true : false;
        return std::get<0>(p1) < std::get<0>(p2);
    }
};

class DB_similarity_measurer
{
public:
    DB_similarity_measurer();

    ~DB_similarity_measurer() {}

    //void get_map_from_pairs(std::vector<string> &ids, MY_S_VECTOR &result);

    void init_DB_connection();
/*
    void set_id(string id) {
        rid = id;
        id_i = QString(rid.data()).toInt();
    }

    void get_map() {
        if(!id_i)
            throw QString("Intente con otra palabra.");

        if(main_map)
            delete main_map;
        main_map = new MY_MAP(my.get_vector(rid));
    }

    void heap_measurer(MY_S_VECTOR &res, MY_R_VECTOR &result);
*/
    void find_similar_words(string root, std::vector<string> &v_id, std::vector<string> &v_morphs);

    void special_query(string &id);

private:
    DB_connector my;
    string rid;
    type1 id_i;
    MY_MAP *main_map;
};

#endif // DB_SIMILARITY_H
