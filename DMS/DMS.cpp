#include<bits/stdc++.h>
using namespace std;
string dir = "db/";
#include"headers/splits.h"
#include"headers/create.h"
#include"headers/insert.h"
#include"headers/select.h"
#include"headers/help.h"
#include"headers/truncate.h"
#include"headers/delete.h"
#include"headers/drop.h"
#include"headers/describe.h"
#include"headers/update.h"

int main()
{
    string query;
    
    do
    {
        cout<<"\nMySQL >> ";
        getline(cin, query);

        string :: iterator itr = query.end();

        if(*(itr-1) != ';')
        {
            cout<<"\nError, Missing semicolon!!!"<<endl;
        }
        vector<string> tokens = split_query(query, ' ');

        cout<<endl;
        

        int query_index;

        if(tokens[0] == "SELECT")
        {
            query_index = 1;
        }
        else if(tokens[0] == "CREATE")
        {
            query_index = 2;
        }
        else if(tokens[0] == "DROP")
        {
            query_index = 3;
        }
        else if(tokens[0] == "TRUNCATE")
        {
            query_index = 4;
        }
        else if(tokens[0] == "DELETE")
        {
            query_index = 5;
        }
        else if(tokens[0] == "DESCRIBE")
        {
            query_index = 6;
        }
        else if(tokens[0] == "HELP")
        {
            query_index = 7;
        }
        else if(tokens[0] == "INSERT")
        {
            query_index = 8;
        }
        else if(tokens[0] == "UPDATE")
        {
            query_index = 9;
        }
        else if(tokens[0] == "QUIT;")
        {
            query_index = 10;
        }
        


        switch (query_index)
        {
            case 1:
                select(query);
                break;
            
            case 2:
                create(query);
                break;
            
            case 3:
                drop(query);
                break;
            case 4:
                truncate(query);
                break;
            case 5:
                Delete(query);
                break;
            
            case 6:
                describe(query);
                break;
            
            case 7:
                help(query);
                break;
            
            case 8:
                insert(query);
                break;
            case 9:
                
                update(query);
                break;
            case 10:
                exit(0);
                break;
            default:
                break;
        }

    } while (query.compare("quit;") != 0);

    return 0;
    
}
