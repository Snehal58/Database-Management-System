#include<bits/stdc++.h>
using namespace std;


void drop(string query)
{
    vector<string> tokens = split_query(query, ' ');
    string table_name = tokens[2];

    table_name.erase(table_name.length() - 1, table_name.length());

    schema.open(dir + "SCHEMA.txt", ios::in);
    vector<string> tables;
    while(!schema.eof())
    {
        string table;
        getline(schema, table);
        if(table.find(table_name) !=-1)
        {
            continue;
        }
        else{
            if(!table.empty())
            tables.push_back(table);
        }

    }
    table_name = dir + table_name + ".txt";
    const char* file = table_name.c_str();
    
    schema.clear();
    schema.close();
    schema.open(dir + "SCHEMA.txt",ios::out);
    for(auto I : tables)
    {
        schema<<I<<endl;
    }
    int status = remove(file);
    if(status == 0)
        cout<<"Table Dropped!!!"<<endl;
    else
        cout<<"Error!!! Table was not dropped"<<endl;

    schema.close();
}
