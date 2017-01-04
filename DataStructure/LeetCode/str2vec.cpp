#include <iostream>
#include <sstream>
//leetcode上的数组一般是以：[5,4,7,3,null,2,null,-1,null,9]这样的形式出现，
//我写的这个函数用来将string版的"[5,4,7,3,null,2,null,-1,null,9]"，变为vector版的{5,4,7,3,null,2,null,-1,null,9}
//这里用了一个C++标准库中Input/output library中<sstream>的stringstream
vector<int> str2vec(string s){
    vector<int> vec;
    for(int i=1;i<s.size()-1;i++){
        string buffer="";
        while(i<s.size()-1 && s.at(i)!=','){
            buffer += s.at(i);
            i++;
        }
        stringstream ss;
        ss << buffer;
        int n;
        ss >> n;
        vec.push_back(n);
    }
    return vec;
}
