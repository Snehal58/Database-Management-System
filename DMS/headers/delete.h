#include<bits/stdc++.h>
using namespace std;

void Delete(string query)
{
    int count = 0;
    vector<string> tokens = split_query(query, ' ');
    vector<string>table_records;
    string table_name = tokens[2];
    //table_name.erase(table_name.size() - 1, table_name.size());
    fstream dataFile(dir + table_name+".txt", ios::in);
    dataFile.close();
    dataFile.open(dir + table_name+".txt", ios::in);
    if(tokens[tokens.size() - 2].compare("WHERE") == 0)
    {
            string table_name = tokens[tokens.size() - 3];
            dataFile.open(table_name+".txt", ios::in);
            vector<string> conditions = split_query(tokens[tokens.size() - 1], '=');
            conditions[1].erase(conditions[1].size() - 1, conditions[1].size());
            string record;
            getline(dataFile, record);
            
            unordered_map<string, int> colms;
            vector<string>record_vector = split_query(record, '#');
            for(int i = 0; i < record_vector.size(); i++)
            {
                colms[record_vector[i]] = i;
            }
    
            if(tokens[1] == "FROM")
            {
               
                dataFile.close();
                dataFile.open(dir + table_name+".txt", ios::in);
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
                        count++;
                    }
                }

                
            }
    }
    else{
        string table_name = tokens[2];
        dataFile.close();
        truncate("TRUNCATE TABLE "+table_name); 
        return;
    }
    dataFile.clear();
    dataFile.close();
    dataFile.open(dir + table_name+".txt", ios::out);
    set<string> data;
    for(auto I : table_records)
    {
        if(!I.empty())
        dataFile<<I<<endl;
    }
    
    dataFile.close();
    cout<<count<<" records deleted."<<endl;

}
