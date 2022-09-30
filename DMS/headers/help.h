#include<bits/stdc++.h>
using namespace std;
void help(string query)
{
    vector<string>tokens = split_query(query, ' ');

    if(tokens.size() == 1 && tokens[0] == "HELP")
    {
        cout<<"HELP"<<endl;
        cout<<"Use following help commands to get help for a particular command: "<<endl;
        cout<<"\t"<<"-- HELP CREATE --> Help for CREATE command"<<endl;
        cout<<"\t"<<"-- HELP SELECT --> Help for SELECT command"<<endl;
        cout<<"\t"<<"-- HELP DESCRIBE --> Help for DESCRIBE command"<<endl;
        cout<<"\t"<<"-- HELP DROP --> Help for DROP command"<<endl;
        cout<<"\t"<<"-- HELP TRUNCATE --> Help for TRUNCATE command"<<endl;
        cout<<"\t"<<"-- HELP DELETE --> Help for DELETE command"<<endl;
        cout<<"\t"<<"-- HELP INSERT --> Help for INSERT command"<<endl;
        cout<<"\t"<<"-- HELP TABLES --> List all Tables"<<endl;    
        cout<<endl;
        return;
    }

    else if(tokens[1] == "CREATE;")
    {
        cout<<"CREATE is used to create a new table \n";
        cout<<"\t"<<"CREATE TABLE table_name (attr_name1 attr_type1, attr_name2 attr_type2,. . .);\n\n";
        return;
    }

    else if(tokens[1] == "DROP;")
    {
        cout<<"DROP is used to delete a table along with data\n";
        cout<<"\t"<<"DROP TABLE table_name;\n\n";

        return;
    }

    else if(tokens[1] == "DESCRIBE;")
    {
        cout<<"DESCRIBE Describes the schema of table T_NAME\n";
        cout<<"\t"<<"DESCRIBE table_name;\n\n";
        return;
    }

    else if(tokens[1] == "INSERT;")
    {
        cout<<"INSERT is used to insert a record in the table\n";
        cout<<"\t"<<"INSERT INTO table_name VALUES(attr_value1,attr_value2, …);\n\tNote that NULL is not permitted for any attribute.";
        return;
    }


    else if(tokens[1] == "DELETE;")
    {
        cout<<"DELETE is used to delete an entry from a table\n";
        cout<<"\t"<<"DELETE FROM table_name WHERE condition_list;\n\n";
        return;
    }

    else if(tokens[1] == "SELECT;")
    {
        cout<<"SELECT is used to select a set of records from the given table\n";
        cout<<"\t"<<"SELECT attr_list FROM table_list WHERE condition_list;\n\n";
        return;
    }
    else if(tokens[1] == "TABLES;")
    {
        schema.open(dir + "SCHEMA.txt", ios::in);
        while(!schema.eof())
        {
            string table;
            getline(schema, table);
            if(!table.empty())
            {
                vector<string> data = split_query(table, '#');
                cout<<data[0]<<endl;
            }
        }
        schema.close();
        return;
    }
    else if(tokens[1] == "TRUNCATE;")
    {
        cout<<"TRUNCATE is used to delete all records from the given table\n";
        cout<<"\t"<<"TRUNCATE TABLE table_name;\n\n";
        return;
    }
}
