#define _USE_MATH_DEFINES

#include <iostream>
#include <unistd.h>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include <vector>
#include <tuple>

using namespace std;



int main(void){
    ifstream fin;
    ofstream fout;
    string buf, token;
    stringstream ss;
    vector<tuple<int, int, int> > v;
    vector<tuple<int, int, int> > f;
    vector<tuple<double, double, double> > normal_vector;
    

    fin.open("basketball_player_fr0001_qp12_qt12.obj", ifstream::in);
    if(!fin.is_open()){
        cout << "Open input file error" << endl;
        return 0;
    }

    fout.open("basketball_player_conversion.obj", ios::out | ios::trunc);

    while(getline(fin, buf)){
        for(auto &i : buf)  if(i == '/')    i = ' ';
        ss.str(buf);
        ss >> token;
        if(token.compare("v") == 0){
            v.push_back(make_tuple(0, 0, 0));
            ss >> get<0>(v.back()) >> get<1>(v.back()) >> get<2>(v.back());
            //fout << get<0>(v.back()) << " " << get<1>(v.back()) << " " << get<2>(v.back()) << endl;
        }
        else if(token.compare("f") == 0){
            int temp;
            f.push_back(make_tuple(0, 0, 0));
            ss >> get<0>(f.back()) >> temp >> get<1>(f.back()) >> temp >> get<2>(f.back());
            fout << get<0>(f.back()) << " " << get<1>(f.back()) << " " << get<2>(f.back()) << endl;
        }
        ss.clear();
    }

    fin.close();
    fout.close();

    return 0;
}