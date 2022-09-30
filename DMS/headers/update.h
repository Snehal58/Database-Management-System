#include<bits/stdc++.h>
using namespace std;
void update(string query)
{
    int count = 0;
    vector<string>table_records;
    
    query.erase(query.size() - 1, query.size());
    vector<string> tokens = split_query(query, ' ');
    string table_name = tokens[1];
   // table_name.erase(table_name.size() - 1, table_name.size());

    fstream dataFile(dir + table_name+".txt", ios::in);
    if(!dataFile)
    {
        cout<<"Table doesn't exists!"<<endl;
        return;
    }
    vector<string> conditions = split_query(tokens[tokens.size() - 1], '=');
    //conditions[1].erase(conditions[1].size() - 1, conditions[1].size());
    vector<string> updates = split_query(tokens[3], '=');
    string record;
    getline(dataFile, record);
    if(!record.empty())
    table_records.push_back(record);
    unordered_map<string, int> colms;
    vector<string>record_vector = split_query(record, '#');
            for(int i = 0; i < record_vector.size(); i++)
            {
                colms[record_vector[i]] = i;
            }
    
    // vector<string>record_vector = split_query(record, '#');
    
                while(!dataFile.eof())
                {
                    
                    getline(dataFile, record);
                    
                    if(record.empty())
                    break;
                    record_vector = split_query(record, '#');

                    if(record_vector[record_vector.size() - 1] == "0")
                    {
                        continue;
                    }
                    bool flag = true;
                    for(int i = 0; i < record_vector.size() - 1; i++)
                    {
                        if(record_vector[colms[conditions[0]]].compare(conditions[1])==0 )
                        {
                            flag = false;
                           
                        }
                
                    }
                   
                    if(flag)
                    {
                        if(!record.empty())
                        table_records.push_back(record);
                    }
                    else{
    
                        record_vector[colms[updates[0]]] = updates[1];
                        record = "";
                        for(auto I : record_vector)
                        {
                            record+= I;
                            record+= "#";
                        }
                        table_records.push_back(record);
                        count++;
                    }
                }
        dataFile.clear();
        dataFile.close();
        dataFile.open(dir + table_name+".txt", ios::out);
        for(auto I : table_records)
        {
            dataFile<<I<<endl;
        }
        dataFile.close();
        cout<<count<<" rows affected."<<endl;
        return;      
  
                  
}
