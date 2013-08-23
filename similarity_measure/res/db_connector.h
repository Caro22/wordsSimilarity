#ifndef DB_CONNECTOR_H
#define DB_CONNECTOR_H

#include <mysql.h>
#include <iostream>
#include <fstream>
#include <map>
#include <QString>

using namespace std;

const size_t buffer_size=100;
typedef int type1;
typedef double type2;
typedef std::pair<type1, type2> std_pair;
typedef std::map<type1,type2> std_map;

class DB_connector {
public:
    DB_connector();

    ~DB_connector();

    void SQL_init(char *dir, char *usr, char *pass, char *database);

    /*void id_Obtainer(char *val, string& ret);

    void SQL_sentence_maker(char* inFile, char* outFile);*/

    void get_f8_morphs(string &id, std::vector<string> &v_id, std::vector<string> &v_morphs);

    void get_vector_pair(string &rid, std::vector<string> &rid2);

    string get_rid(string &root);

    string get_morphs(type1);

    std_map get_vector(string &val);

private:
    MYSQL *my;
};

#endif // DB_CONNECTOR_H
