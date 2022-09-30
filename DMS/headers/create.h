#include<bits/stdc++.h>
using namespace std;

void create(string query)
{
    vector<string> tokens = split_query(query, ' ');
    string table_name = tokens[2];

   table_name.erase(table_name.length() - 1, table_name.length());
    vector<string> col_var = split_create(query);

    for(int i = 0; i < col_var.size(); i++)
    {
        if(col_var[i][0] == ' ')
        {
            col_var[i].erase(0, 2);
        }
    }


    string :: iterator itr = col_var[col_var.size() - 1].end();

    col_var[col_var.size() - 1].erase(itr - 2, itr);

   unordered_map<string,string>col_map;
   vector<string> col_names;

    for(int i = 0; i < col_var.size(); i++)
    {
        vector<string> temp;

        temp = split_query(col_var[i], ' ');
        col_map[temp[0]] = temp[1];
        col_names.push_back(temp[0]);
    }

    unordered_map<string,string> :: iterator map_itr;


    fstream dataFile(dir + table_name+".txt", ios::in);

    if(dataFile)
    {
        cout<<"Table Already Exists!!!!"<<endl;
        return;
    }
    else
    {
        dataFile.close();
        schema.open(dir + "SCHEMA.txt", ios::app);

        dataFile.open(dir + table_name+".txt", ios::out);
        schema<<table_name<<"#";
        for(int i = 0; i < col_names.size(); i++)
        {
            map_itr = col_map.find(col_names[i]);
            if(map_itr != col_map.end())
            {
                schema<<map_itr->first<<"#"<<map_itr->second<<"#";
            }
        }
        schema<<"#"<<endl;

        for(int i = 0; i < col_names.size(); i++)
        {
            map_itr = col_map.find(col_names[i]);
            if(map_itr != col_map.end())
            {
                dataFile<<map_itr->first<<"#";
            }
        }
        dataFile<<1<<endl;



        dataFile.close();
        schema.close();
    }

    cout<<"Table Created."<<endl;


}
