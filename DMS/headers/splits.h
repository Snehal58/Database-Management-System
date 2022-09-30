#include<bits/stdc++.h>
using namespace std;

fstream schema;
string space_delimiter = " ";
vector<string> split_query(string str, char delimiter)
{
    vector<string> tokens;
    
    stringstream check1(str);
    //1#ASHU#PPUR#
    string token;

    while(getline(check1, token, delimiter))
    {
        tokens.push_back(token);
        
    }

    return tokens;
}
vector<string> split_create(string str)
{
    vector<string> tokens;
    
    tokens = split_query(str, '(');
    
    string token;

    stringstream check1(tokens[1]);

    vector<string> sub_tokens;

    while(getline(check1, token, ','))
    {
        sub_tokens.push_back(token);
    }

    return sub_tokens;
}

//CREATE TABLE dept( id INT, name STR);