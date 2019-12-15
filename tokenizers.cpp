########## Uses strinstream and char as delim ###########

#include<sstream>
#include<vector>

using namespace std;

vector<string> tokenizer(string str, char delim)
{
    vector<string> vs;
    string token;
    
    std::stringstream ss(str);

    while( getline(ss, token, delim) )
        vs.push_back(token);

    return vs;
}

########################################################

########Uses only std::string as source and delimiter###

#include<vector>

using namespace std;

vector<string> tokenizer(string str, string delim)
{
    vector<string> vs;
    size_t pos;
    string token;
    
    do {
        pos = str.find_first_of(delim);
        token = str.substr(0,pos);
        vs.push_back(token);
        str = str.substr(pos+1);
    }
    while(pos != string::npos);

    return vs;
}
#########################################################
