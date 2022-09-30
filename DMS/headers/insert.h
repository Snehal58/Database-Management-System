#include<bits/stdc++.h>
using namespace std;
void insert(string query)
{
    vector<string> tokens = split_query(query, ' ');
    string table_name = tokens[2];

    vector<string> values = split_create(query);

    for(int i = 0; i < values.size(); i++)
    {
        if(values[i][0] == ' ')
        {
            values[i].erase(0, 1);
        }
    }

    string :: iterator itr = values[values.size() - 1].end();
    values[values.size() - 1].erase(itr - 2, itr);


    fstream dataFile(dir + table_name+".txt", ios::in);

    if(dataFile)
    {
        dataFile.close();
        dataFile.open(dir + table_name+".txt", ios::app);
        for(int i = 0; i < values.size(); i++)
        {
            dataFile<<values[i]<<"#";
            
        }
        dataFile<<"1#"<<endl;
        

        dataFile.close();
    }
    else
    {
        cout<<"No Such Table exists!!!"<<endl;
        return;
    }

    cout<<"Record inserted."<<endl;

    
    
}
