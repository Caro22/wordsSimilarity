#include "db_similarity.h"

template<typename stru, typename Comparer>
void b_sort(stru vec, Comparer comp) {
    size_t size = vec.size();
    for(size_t i = 0; i < size; ++i) {
        for(size_t j = 0; j < i; ++j) {
            if(comp(vec[i], vec[j])) {
                auto temp = vec[i];
                vec[i] = vec[j];
                vec[j] = temp;
            }
        }
    }
}

DB_similarity_measurer::DB_similarity_measurer() :
    id_i(0),
    main_map(NULL)
{
    init_DB_connection();
}

void DB_similarity_measurer::init_DB_connection() {
    my.SQL_init("127.0.0.1", "root", "ratte", "words");
}
/*
void DB_similarity_measurer::get_map_from_pairs(String_Vector &ids, MY_S_VECTOR &result) {     //Obtiene el map de cada uno de pairs obtenido por get_pairs
    my.get_vector_pair(rid, ids);
    String_Vector::iterator it_i = ids.begin(),
                            it_f = ids.end();
    while(it_i != it_f) {
        result.push_back(MY_MAP(my.get_vector(*it_i)));
        ++it_i;
    }
}

void DB_similarity_measurer::heap_measurer(MY_S_VECTOR &res, MY_R_VECTOR &result) {

    get_map();

    String_Vector ids;
    get_map_from_pairs(ids, res);
    MY_S_VECTOR::iterator   it_i = res.begin(),
                            it_f = res.end();
    String_Vector::iterator it2_i = ids.begin();

    while(it_i != it_f) {
        int id2 = QString((*it2_i).data()).toInt();
        result.push_back(
            MY_PAIR(cosine_similarity(*main_map, id_i, (*it_i), id2),
                    my.get_morphs(id2))
        );
        /*double tmp = cosine_similarity(*main_map, id_i, (*it_i), id2);
        string tmp2 = my.get_morphs(id2);
        cout << id2 << " cos = " << tmp << " morphs: " << tmp2 << endl;
        result.push_back(MY_PAIR(tmp, tmp2));
        ++it_i;
        ++it2_i;
    }

    std::make_heap(result.begin(), result.end(), heap_pair_comparer());
    //b_sort(result, heap_pair_comparer());
    result.resize(10);
}*/

void DB_similarity_measurer::find_similar_words(string root, std::vector<string> &v_id, std::vector<string> &v_morphs) {
    root = Porter2Stemmer::stem(root);//  <--- Stemmer
    /*set_id(my.get_rid(root));*/
    string id = my.get_rid(root);
    my.get_f8_morphs(id, v_id, v_morphs);

}
