#include<bits/stdc++.h>
using namespace std;

void select(string query)
{
    int count  = 0;
    vector<string> tokens = split_query(query, ' ');

    string table_name = tokens[tokens.size() - 1];
    table_name.erase(table_name.size() - 1, table_name.size());

    fstream dataFile(dir + table_name+".txt", ios::in);
    dataFile.close();
    dataFile.open(dir + table_name+".txt", ios::in);
    if(tokens[tokens.size() - 2].compare("WHERE") == 0)
    {
            string table_name = tokens[tokens.size() - 3];
            dataFile.open(dir + table_name+".txt", ios::in);
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
    
            if(tokens[1] == "*")
            {
                cout<<"_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ "<<std::endl;
                for(int i = 0; i < record_vector.size() - 1; i++)
                {
                    cout<<setw(20)<<record_vector[i]<<" | ";
                }
                cout<<endl;
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

                    for(int i = 0; i < record_vector.size() - 1; i++)
                    {
                        if(record_vector[colms[conditions[0]]].compare(conditions[1])==0 ){
                            cout<<setw(20)<<record_vector[i]<<" | ";
                            count++;
                           
                        }
                        
                    }
                     cout<<endl;
                    
                }

                cout<<"_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _  "<<endl;
                
            }
            else
            {
                vector<string>queried_cols;
                vector<int> column_indices;
                
                for(int i = 1; i < tokens.size() - 4; i++)
                {
                    queried_cols.push_back(tokens[i]);
            
                }

                for(int i = 0; i < queried_cols.size() - 1; i++)
                {
                    queried_cols[i].erase(queried_cols[i].size() - 1);
                }
                dataFile.close();
                dataFile.open(dir + table_name+".txt", ios::in);
                string cols;
                getline(dataFile, cols);
                count++;
                vector<string>columns = split_query(cols, '#');
                columns.pop_back();
                for(int i = 0; i < queried_cols.size(); i++)
                {
                    for(int j = 0; j < columns.size(); j++)
                    {
                        if(queried_cols[i].compare(columns[j])==0)
                        {
                            column_indices.push_back(j);
                        }
                    }
                }

                cout<<"_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ "<<endl;  
                dataFile.seekg(0);
                while(!dataFile.eof())
                {
                    string record;
            
                    getline(dataFile, record);
                    if(record.empty())
                    break;
                    vector<string>record_vector = split_query(record, '#');

                    if(record_vector[record_vector.size() - 1] == "0")
                    {
                        continue;
                    }
                    if(record_vector[colms[conditions[0]]].compare(conditions[1])==0)
                    {
                          
                            for(int i = 0; i < column_indices.size(); i++)
                            {
                                
                                cout<<setw(20)<<record_vector[column_indices[i]]<<" | ";
                                
                            }
                            count++;
                            cout<<endl;
                    }
                    
                }

                cout<<"_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _  "<<std::endl;
                

            }

    }
    else{
        if(tokens[1] == "*")
        {
            cout<<"_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ "<<std::endl;
            
            while(!dataFile.eof())
            {
                string record;
                getline(dataFile, record);
                vector<string>record_vector = split_query(record, '#');
                if(record.empty())
                break;
                if(record_vector[record_vector.size() - 1] == "0")
                {
                    continue;
                }

                for(int i = 0; i < record_vector.size() - 1; i++)
                {
                    cout<<setw(20)<<record_vector[i]<<" | ";
                    
                }
                count++;
                cout<<endl;
            }
            
            cout<<"_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _  "<<std::endl;
            
        }
        else
        {
            vector<string>queried_cols;
            vector<int> column_indices;
            
            for(int i = 1; i < tokens.size() - 2; i++)
            {
                queried_cols.push_back(tokens[i]);
            }

            for(int i = 0; i < queried_cols.size() - 1; i++)
            {
                queried_cols[i].erase(queried_cols[i].size() - 1);
            }

            string cols;
            getline(dataFile, cols);
            count++;
            vector<string>columns = split_query(cols, '#');
            columns.pop_back();
            for(int i = 0; i < queried_cols.size(); i++)
            {
                for(int j = 0; j < columns.size(); j++)
                {
                    if(queried_cols[i] == columns[j])
                    {
                        column_indices.push_back(j);
                    }
                }
            }

            cout<<"_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ "<<std::endl;  
            dataFile.seekg(0);
            while(!dataFile.eof())
            {
                string record;
        
                getline(dataFile, record);
                if(record.empty())
                break;
                vector<string>record_vector = split_query(record, '#');

                if(record_vector[record_vector.size() - 1] == "0")
                {
                    continue;
                }

                for(int i = 0; i < column_indices.size(); i++)
                {
                    cout<<setw(20)<<record_vector[column_indices[i]]<<" | ";
                    
                }
                count++;
                cout<<endl;
            }

            cout<<"_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _  "<<std::endl;
            

        }
    }
    
    dataFile.close();
    cout<<count - 1<<" records found."<<endl;
}
