#include<bits/stdc++.h>

using namespace std;

/*
int	main()	begin	end	printf(	id	);	if(	)	;	id,	relop	$	L'	L	BODY	IF	B	DEF	LIST	COND
0	s2	 	 	 	 	 	 	 	 	 	 	 	 	 	1	 	 	 	 	 	 
1	 	 	 	 	 	 	 	 	 	 	 	 	acc	 	 	 	 	 	 	 	 
2	 	s3	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 
3	 	 	s4	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 
4	s9	 	 	 	s8	 	 	s10	 	 	 	 	 	 	 	5	7	 	6	 	 
5	 	 	 	s11	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 
6	s9	 	 	r7	s8	 	 	s10	 	 	 	 	 	 	 	13	7	12	6	 	 
7	s9	 	 	r7	s8	 	 	s10	 	 	 	 	 	 	 	13	7	14	6	 	 
8	 	 	 	 	 	s15	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 
9	 	 	 	 	 	s18	 	 	 	 	s17	 	 	 	 	 	 	 	 	16	 
10	 	 	 	 	 	s20	 	 	 	 	 	 	 	 	 	 	 	 	 	 	19
11	 	 	 	 	 	 	 	 	 	 	 	 	r1	 	 	 	 	 	 	 	 
12	 	 	 	r2	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 
13	 	 	 	r6	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 
14	 	 	 	r3	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 
15	 	 	 	 	 	 	s21	 	 	 	 	 	 	 	 	 	 	 	 	 	 
16	 	 	 	 	 	 	 	 	 	s22	 	 	 	 	 	 	 	 	 	 	 
17	 	 	 	 	 	s18	 	 	 	 	s17	 	 	 	 	 	 	 	 	23	 
18	 	 	 	 	 	 	 	 	 	r10	 	 	 	 	 	 	 	 	 	 	 
19	 	 	 	 	 	 	 	 	s24	 	 	 	 	 	 	 	 	 	 	 	 
20	 	 	 	 	 	 	 	 	 	 	 	s25	 	 	 	 	 	 	 	 	 
21	 	 	 	r4	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 
22	r8	 	 	r8	r8	 	 	r8	 	 	 	 	 	 	 	 	 	 	 	 	 
23	 	 	 	 	 	 	 	 	 	r9	 	 	 	 	 	 	 	 	 	 	 
24	 	 	s26	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 
25	 	 	 	 	 	s27	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 
26	s9	 	 	 	s8	 	 	s10	 	 	 	 	 	 	 	28	7	 	6	 	 
27	 	 	 	 	 	 	 	 	r11	 	 	 	 	 	 	 	 	 	 	 	 
28	 	 	 	s29	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 
29	r5	 	 	r5	r5	 	 	r5	
*/ 	 	 	 	 	 	 	 	 	 	 	 	 

map<pair<int,string>,pair<int,int>> action = {
    	{{0, "int"}, {1, 0}},

        // State 1
        {{1, "main"}, {2, 0}},

        // State 2
        {{2, "("}, {3, 0}},

        // State 3
        {{3, ")"}, {4, 0}},

        // State 4
        {{4, "begin"}, {5, 0}},

        // State 5
        {{5, "int"}, {10, 0}},
        {{5, "printf"}, {9, 0}},
        {{5, "if"}, {11, 0}},

        // State 6
        {{6, "end"}, {12, 0}},

        // State 7
        {{7, "int"}, {10, 0}},
        {{7, "end"}, {6, 1}},
        {{7, "printf"}, {9, 0}},
        {{7, "if"}, {11, 0}},

        // State 8
        {{8, "int"}, {10, 0}},
        {{8, "end"}, {6, 1}},
        {{8, "printf"}, {9, 0}},
        {{8, "if"}, {11, 0}},

        // State 9
        {{9, "("}, {16, 0}},

        // State 10
        {{10, "id"}, {18, 0}},

        // State 11
        {{11, "("}, {19, 0}},

        // State 12
        {{12, "$"}, {-1, -1}},

        // State 13
        {{13, "end"}, {1, 1}},

        // State 14
        {{14, "end"}, {5, 1}},

        // State 15
        {{15, "end"}, {2, 1}},

        // State 16
        {{16, "id"}, {20, 0}},

        // State 17
        {{17, ";"}, {21,0}},

        // State 18
        {{18, ";"}, {9, 1}},
        {{18, ","}, {22, 0}},

        // State 19
        {{19, "id"}, {24, 0}},

        // State 20
        {{20, ")"}, {25, 0}},

        // State 21
        {{21, "int"}, {7, 1}},
        {{21, "end"}, {7, 1}},
        {{21, "printf"}, {7, 1}},
        {{21, "if"}, {7, 1}},

        // State 22
        {{22, "id"}, {18, 0}},

        // State 23
        {{23, ")"}, {27, 0}},

        // State 24
        {{24, "relop"}, {28, 0}},

        // State 25
        {{25, ";"}, {29, 0}},

        // State 26
        {{26, ";"}, {8, 1}},

        // State 27
        {{27, "begin"}, {30, 0}},

        // State 28
        {{28, "id"}, {31, 0}},

        // State 29
        {{29, "end"}, {3, 1}},

        // State 30
        {{30, "int"}, {10, 0}},
        {{30, "printf"}, {9, 0}},
        {{30, "if"}, {11, 0}},

        // State 31
        {{31, ")"}, {10, 1}},

        // State 32
        {{32, "end"}, {33, 0}},

        // State 33
        {{33, "int"}, {4, 1}},
        {{33, "end"}, {4, 1}},
        {{33, "printf"}, {4, 1}},
        {{33, "if"}, {4, 1}}
};

map<pair<int,string>,int> go_to = {

        // State 5
        {{5, "BODY"}, 6},
        {{5, "IF"}, 8},
        {{5, "DEF"}, 7},

        // State 7
        {{7, "BODY"}, 14},
        {{7, "DEF"}, 7},
        {{7, "IF"}, 8},
        {{7, "B"}, 13},

        // State 8
        {{8, "BODY"}, 14},
        {{8, "DEF"}, 7},
        {{8, "IF"}, 8},
        {{8, "B"}, 15},

        // State 10
        {{10, "LIST"}, 17},

        // State 19
        {{19, "COND"}, 23},

        // State 22
        {{22, "LIST"}, 26},

        // State 30
        {{30, "BODY"}, 32},
        {{30, "IF"}, 8},
        {{30, "DEF"}, 7}
};

unordered_map<int,int> no_of_grammar_sym = {
    {0,7},
    {1,2},
    {2,2},
    {3,5},
    {4,7},
    {5,1},
    {6,1},
    {7,3},
    {8,3},
    {9,1},
    {10, 3}
};

unordered_map<int,string> g_sym = {
    {0,"L"},
    {1,"BODY"},
    {2,"BODY"},
    {3,"BODY"},
    {4,"IF"},
    {5,"B"},
    {6,"B"},
    {7,"DEF"},
    {8,"LIST"},
    {9,"LIST"},
    {10, "COND"}
};


vector<string> splitString(const string& input) {
    vector<string> words;
    istringstream iss(input);
    string word;
    while (iss >> word) {
        words.push_back(word);
    }
    return words;
}

unordered_map<int,string> grammar = {
		{0, "L -> int main ( ) begin BODY end"},
        {1, "BODY -> DEF B"},
        {2, "BODY -> IF B"},
        {3, "BODY -> printf ( id ) ;"},
        {4, "IF -> if ( COND ) begin BODY end"},
        {5, "B -> BODY"},
        {6, "B -> ''"},
        {7, "DEF -> int LIST ;"},
        {8, "LIST -> id , LIST"},
        {9, "LIST -> id"},
        {10, "COND -> id relop id"}
};




int main(){
    
    ifstream ipfile("token.txt");
    stringstream buffer;
    buffer << ipfile.rdbuf();
 
    string s = buffer.str();
    //cout<<s<<"\n";
    //s = "int main ( ) begin int id , id , id ; if ( id relop id id ) begin printf ( id ) ; end if ( id relop id ) begin printf ( id ) ; end if ( id relop id ) begin printf ( id ) ; end end";
    s += " $";
    vector<string> input;
    input = splitString(s);
    stack<int> st;
    st.push(0);
    int i=0;

    while(1){
        string a = input[i];
        int s = st.top();
        // cout << s << " " << a << endl;
        if (action[{s,a}].second==-1){
            cout << "Accepted" << endl;
            break;
        }
        else if (action.find({s,a})!=action.end()) {
            if (action[{s,a}].second==0){
                
                st.push(action[{s,a}].first);
                cout<< "SHIFT " << a << endl;
                i++;
            }else{
                int no = no_of_grammar_sym[action[{s,a}].first];
                while(no--) st.pop();
                st.push(go_to[{st.top(),g_sym[action[{s,a}].first]}]);
               cout << "REDUCE " <<  g_sym[action[{s,a}].first] <<   " : "  << grammar[action[{s,a}].first] << endl;
            }
        }
        else {
            cout << "Error" << endl;
            break;
        }
    }
     
    return 0;
}
