#include <bits/stdc++.h>
using namespace std;
 
bool checkIdentifier(string lexeme)
{
    return regex_match(lexeme, regex("[a-zA-Z][a-zA-Z0-9]*"));
}
bool checkNumber(string lexeme)
{
    return regex_match(lexeme, regex("[0-9]+"));
}
 
int main()
{
    ifstream t("input.txt");
    freopen("output.txt", "w", stdout);
    ofstream tokfile("token.txt");

    // Check if the file was opened successfully
    if (!tokfile.is_open()) {
        std::cerr << "Failed to open file for writing!" << std::endl;
        return 1; // Return with error status
    }
 
    stringstream buffer;
    buffer << t.rdbuf();
 
    string input = buffer.str();
 
    unordered_map<string, string> tokens = {
        {"int", "keyword"},
        {"main", "keyword"},
        {"begin", "keyword"},
        {"if", "keyword"},
        {"printf", "keyword"},
        {"end", "keyword"},
        {"(", "popen"},
        {")", "pclose"},
        {";", "semicolon"},
        {"=", "operator"},
        {"-", "operator"},
        {">", "relop"},
        {"<", "relop"},
        {"[","sopen"},  
        {"]","sclose"},
        {",", "comma"},
        {";", "semicolumn"}
        };
 
    int len = input.length();
 
    string lexeme = "";
    string temp="+-=/()[],;";
 
    for (int i = 0; i < len; ++i)
    {
 
        if (temp.find(input[i])!=string::npos || input[i]=='\n' || input[i]=='\t' || input[i]==' ')
        {
           // if (lexeme.length() == 0)
                //continue;
 
            if (tokens.find(lexeme) != tokens.end())
            {
                cout << lexeme << " " << tokens[lexeme] << endl;
                if(tokens[lexeme] == "relop")	tokfile << "relop ";
                else tokfile << lexeme << " ";
            }
            else
            {
                if(checkIdentifier(lexeme)){
                	cout<<lexeme<<" identifier"<<endl;
                	tokfile << "id ";
                }
                else if(checkNumber(lexeme)){
                
                	cout<<lexeme<<" number"<<endl;
                	tokfile << "num ";
                }
                else{
                	if(lexeme.length()){
                		cout<<lexeme<<" Invalid\n";
                		exit(0);
                	}
                }
            }
            string t;
            t.push_back(input[i]);
            if(temp.find(input[i])!=string::npos){
            
            	tokfile << input[i] <<" ";
            	cout<<input[i] <<" "<< tokens[t] <<endl;
            }
            lexeme="";
        }
        else
        {
            lexeme.push_back(input[i]);
        }
    }
 	
 	tokfile.close();
 	
    return 0;
}
