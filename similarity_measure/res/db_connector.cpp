#include "db_connector.h"

DB_connector::DB_connector() :
    my(new MYSQL)
{
}

DB_connector::~DB_connector() {
    mysql_close(my);
}

void DB_connector::SQL_init(char *dir, char *usr, char *pass, char *database) {
    my = mysql_init(NULL);

    if (my == NULL) {
        fprintf(stderr, "%s\n", mysql_error(my));
        exit(1);
    }

    if (mysql_real_connect(my, dir, usr, pass, database, 0, NULL, 0) == NULL) {
        fprintf(stderr, "%s\n", mysql_error(my));
        mysql_close(my);
        exit(1);
    }
}
/*
void DB_connector::id_Obtainer(char *val, string& ret) {
    string query = "SELECT * FROM roots WHERE root = '";
    query += val;
    query += "'";
    mysql_query(my, query.data());
    MYSQL_RES *result = mysql_store_result(my);
    MYSQL_ROW row;
    row = mysql_fetch_row(result);
    string id(row[0]);
    ret = id;
    mysql_free_result(result);
}

void DB_connector::SQL_sentence_maker(char* inFile, char* outFile) {
    ifstream iFile(inFile);
    ofstream oFile(outFile);

    char *val1 = new char[buffer_size];
    char *val2 = new char[buffer_size];
    char *val3 = new char[buffer_size];

    oFile << "US" << endl;
    oFile << "INSERT INTO testrelations VALUES" << endl;

    bool first = true;

    while(true) {
        if(iFile.eof())
            break;
        else {
            iFile>>val1;
            iFile>>val2;
            iFile>>val3;

            string id1,
                    id2;
            id_Obtainer(val1, id1);
            cout << "id1: " << id1 << endl;
            id_Obtainer(val2, id2);
            cout << "id2: " << id2 << endl;

            if(!first)
                oFile << "," << endl;
            else
                first = false;
            oFile <<"(" << id1 << ", " << id2 << ", " << val3 << ")";
        }
    }

    oFile <<";"<<endl;
}*/

void DB_connector::get_vector_pair(string &rid, std::vector<string> &rid2) {
    string query = "select distinct id_root1 from relations_data where id_root2 in (select id_root2	from relations_data where id_root1 ="
                    + rid + ")";
    mysql_query(my, query.data());
    MYSQL_RES *result = mysql_store_result(my);
    MYSQL_ROW row;
    while(row = mysql_fetch_row(result)) {
        string temp1 = row[0];
        if(rid != temp1)
            rid2.push_back(temp1);
    }
    mysql_free_result(result);
}

string DB_connector::get_rid(string &root) {
    string query = "SELECT * FROM roots WHERE root = '";
    query += root + "'";
    mysql_query(my, query.data());
    MYSQL_RES *result = mysql_store_result(my);
    MYSQL_ROW row;
    string ret = (row = mysql_fetch_row(result)) ? row[0] : "0";
    mysql_free_result(result);

    return ret;
}

string DB_connector::get_morphs(type1 rid) {
    string query = "SELECT morphs FROM roots WHERE rid = ";
    char buffer[10];
    itoa(rid, buffer, 10);
    query += buffer;
    mysql_query(my, query.data());
    MYSQL_RES *result = mysql_store_result(my);
    MYSQL_ROW row = mysql_fetch_row(result);
    string res(row[0]);
    mysql_free_result(result);

    return res;
}

void DB_connector::get_f8_morphs(string &id, std::vector<string> &v_id, std::vector<string> &v_morphs) {
    string query = "select b.root, b.morphs from (select * from relations_data where id_root1="
            + id + ") as a inner join roots as b on a.id_root2 = b.rid order by weight desc limit 20";
    mysql_query(my, query.data());
    MYSQL_RES *result = mysql_store_result(my);
    MYSQL_ROW row;

    string id_qstr, morphs_qstr;
    while(row = mysql_fetch_row(result)) {
        id_qstr = row[0];
        morphs_qstr = row[1];
        v_id.push_back(id_qstr);
        v_morphs.push_back(morphs_qstr);
    }

    mysql_free_result(result);
}

std_map DB_connector::get_vector(string &val) {
    std_map ret;
    string query = "SELECT id_root2, weight FROM relations_data WHERE id_root1 = ";
    query += val;
    mysql_query(my, query.data());
    MYSQL_RES *result = mysql_store_result(my);
    MYSQL_ROW row;

    QString id2_qstr, w_qstr;
    while(row = mysql_fetch_row(result)) {
        id2_qstr = row[0];
        w_qstr = row[1];

        int id2 = id2_qstr.toInt();
        double weight = w_qstr.toDouble();
        ret.insert(std_pair(id2, weight));
    }

    mysql_free_result(result);

    return ret;
}
