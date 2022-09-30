#include<bits/stdc++.h>
using namespace std;

void truncate(string query)
{
    
    vector<string> tokens = split_query(query, ' ');
    string table_name = tokens[2];
    table_name.erase(table_name.size() - 1, table_name.size());
    fstream dataFile(dir + table_name+".txt", ios::in);
    if(dataFile)
    {
        string first;
        getline(dataFile, first);
        dataFile.clear();
        dataFile.close();
        dataFile.open(dir + table_name+".txt", ios::out);
        dataFile<<first<<endl;
        dataFile.close();
    }
    else{
        cout<<"Table doen't exits!"<<endl;
        return;
    }
    cout<<"All records deleted."<<endl;
    
}
