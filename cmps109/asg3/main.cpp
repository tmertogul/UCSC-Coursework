// Tim Mertogul
// tmertogu@ucsc.edu
// Michael Lowe
// mimlowe@ucsc.edu
// CMPS109
// Spring 2015
// ASG 3

// $Id: main.cpp,v 1.8 2015-04-28 19:23:13-07 - - $

#include <cstdlib>
#include <exception>
#include <iostream>
#include <string>
#include <unistd.h>
#include <fstream>

using namespace std;

#include "listmap.h"
#include "xpair.h"
#include "util.h"

using str_str_map = listmap<string,string>;
using str_str_pair = str_str_map::value_type;

bool equals;
extern int ms;

void scan_options (int argc, char** argv) {
    opterr = 0;
    for (;;) {
        int option = getopt (argc, argv, "@:");
        if (option == EOF) break;
        switch (option) {
            case '@':
                traceflags::setflags (optarg);
                break;
            default:
                complain() << "-" << (char) optopt << ": invalid option"
                << endl; 
                break;
        }
    }
}

bool iit(str_str_pair pair){
    if(ms>0) return true;
    else cerr << pair.first << ": key not found" << endl;
    return false;
}

string trim(const string& input) {
    size_t first = input.find_first_not_of(" \t");
    size_t last = input.find_last_not_of(" \t");
    // string::npos  18446744073709551615
    if (first == string::npos){                    
        return "";
    }
    return input.substr(first, last+1-first);
}

str_str_pair separate(const string& dis){
    string Key = "";
    string Value = "";
    size_t pos = dis.find_first_of("=");
    if(dis[0] != '#' && dis.size() != 0){
        Key += trim(dis.substr (0, pos));   
        Value += trim(dis.substr (pos+1));  
        // string::npos  18446744073709551615
        if( pos == string::npos ){                    
            equals = false;
            Value = "";
        } 
    } else { equals = false; } 
    str_str_pair pair(Key, Value);
    return pair;
}

int checkPair(str_str_pair pair){
    int type = 0;
    if(pair.first != "") type += 100;
    if(equals) type += 10;
    if(pair.second != "") type += 1;
    return type;
} 

bool infile(string& f){
    if(f.compare("-")) return true;
    return false;
}

void evaluate(str_str_map& test, string& filename, istream& in){
    string line = "";
    if(infile(filename)){
        ifstream in(filename);
        cin.rdbuf(in.rdbuf());  
    } 
    for (size_t i = 0; getline(in, line); ++i){
        equals = true;
        cout << filename << ": " << i+1 << ": " << line << endl;
        str_str_pair pair = separate(trim(line));
        switch (checkPair(pair)) {
            case 100: if(iit(pair)) test.find(pair.first); break;
            case 110: if(iit(pair)) test.rm(pair.first); break;
            case 111: test.insert(pair); cout << pair << endl; break;
            case 10:  test.print(); break;
            case 11:  test.printVal(pair.second); break;
            default:  break;
        }
    }
}

int main (int argc, char** argv) {
    
    //sys_info::set_execname (argv[0]);
    string name = string(argv[0]);
    size_t slashpos = name.find_last_of ('/') + 1;
    name = name.substr (slashpos);
    scan_options (argc, argv);
    str_str_map test;
    string filename = "-";
    for (int i = 0; i < argc; i++) {
        if(i==0) { i++; }
        if(argc >= 2) {
            filename = string(argv[i]);
            ifstream in(filename);
            if(!in.good()){
                cerr << name << ": " << filename << 
                                ": No such file or directory" << endl;
            } else { evaluate(test, filename, in); }
        } else { evaluate(test, filename, cin); }
    }
    return EXIT_SUCCESS;
}
