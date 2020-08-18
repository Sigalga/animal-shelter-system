#include "stmt_string_generator.hpp"

using namespace std;

namespace ashs
{

void StmtStringGenerator::AddStringFunc(const Key key, StringFunc func)
{ 
    stringFuncs.insert(pair<Key, StringFunc>(key, func));
}

// void StmtStringGenerator::AddStringFunc(const string& str, StringFunc func)
// {
//     stringFuncs.insert(pair<Key, StringFunc>(const_cast<string&>(str), func));
// }

void StmtStringGenerator::AddStringFunc(const char* cStr, StringFunc func)
{
    string str(cStr);
    stringFuncs.insert(pair<Key, StringFunc>(str, func));
}

void StmtStringGenerator::RemoveStringFunc(const Key key)
{
    try
    {
        stringFuncs.erase(key);
    }
    catch(const std::out_of_range& e)
    {
    }
}

vector<StmtStringGenerator::Key>* StmtStringGenerator::GetKeys()
{
    vector<Key>* vec = new vector<Key>;
    for (FuncMap::iterator it = stringFuncs.begin();
        it != stringFuncs.end();
        ++it)
    {
        vec->push_back(it->first);
    }

    return vec;
}

string& StmtStringGenerator::GenerateString(const Key key, const string& col, const string& val1, const string& val2)
{
    try
    {
        return stringFuncs.at(key)(col, val1, val2);
    }
    catch(const std::out_of_range& e)
    {
        return *(new string(""));
    }
}

} // namespace ashs