#include<bits/stdc++.h>
using namespace std;

void describe(string query)
{
    vector<string> tokens = split_query(query, ' ');

    string table_name = tokens[1];
    table_name.erase(table_name.size() - 1, table_name.size());

    vector<string> schema_records;

    schema.open(dir + "SCHEMA.txt", ios::in);
    string data;
    while (!schema.eof())
    {
        string record;
        getline(schema, record);
       
        if (record.substr(0, table_name.length()+1).compare(table_name + "#") == 0)
        {
            
            schema_records.push_back(record);
            data = record;
        }
    }
    vector<string> record_vector = split_query(data,'#');
    cout<<record_vector[0]<<endl;
    for(int i = 1; i < record_vector.size(); i++)
    {
        cout<<record_vector[i];
        if((i+1) < record_vector.size())
        cout<<" = "<<record_vector[++i]<<endl;

    }


    cout <<endl;
    schema.close();
}
