#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <map> 
#include <sstream>
#include <cctype>
#include <utility>
#include "digraph_analyzer.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::map; 
using std::pair; 
using std::ifstream; 
using std::stringstream; 

vector<string> init_graphs(std::istream& in) {
    //Initializes vector
    vector<string> graph_vec;

    //Extracts and assigns first line of input text to stringstream
    string line; 
    getline(in, line); 
    stringstream ss(line);

    //Searches every word in line
    string word;
    while(ss >> word) {
        //Skips first integer telling number of digraphs to search for
        if (isdigit(word[0])) {
            continue; 
        }
        //Adds digraphs to digraph vector
        graph_vec.push_back(word); 
    }
    return graph_vec; 
} 

map<string, vector<string>> find_graphs(std::istream& in, vector<string> graph_vec) {
    //Initializes map of digraphs/trigraphs
    map<string, vector<string>> graph_map; 
    for (vector<string>::const_iterator cvit = graph_vec.cbegin(); cvit != graph_vec.cend(); ++cvit) {
        vector<string> cont_vec; 
        graph_map[*cvit] = cont_vec; 
    }

    //Skips first line in input file 
    string line; 
    getline(in, line); 
    
    //Searches through every line in text
     while(getline(in, line)) {
        //Uses stringstream to temporarily hold line information
        stringstream ss(line); 
        string word;
        while(ss >> word) {
            //Reads in each word from line and checks for digraphs/trigraphs
            for (map<string, vector<string>>::iterator mit = graph_map.begin(); mit != graph_map.end(); ++mit) {
                if (word.find(mit->first) != std::string::npos) {
                    //Converts each character to lowercase without punctuation
                    string ret_word; 
                    for (size_t i = 0; i < word.size(); i++) {
                        if ((word[i] != '.') && (word[i] != ',') && (word[i] != '?') && (word[i] != '!')) {
                            ret_word += tolower(word[i]);
                        }
                    }
                    mit->second.push_back(ret_word);                 
                }     
            } 
        }
    }
    return graph_map; 
}

void print_ascii(map<string, vector<string>> graph_map) {
    //Iterates through each map entry
    for (map<string, vector<string>>::const_iterator cmit = graph_map.cbegin(); cmit != graph_map.cend(); ++cmit) {
        //Prints key
        cout << cmit->first << ": ["; 
        unsigned int count = 0; //Keeps track of number of entries
        for (vector<string>::const_iterator cvit = cmit->second.cbegin(); cvit != cmit->second.cend(); ++cvit) {
            count++; 
            if (count != cmit->second.size()) { //For every entry but the last, a comma and space is printed after the word
                cout << *cvit << ", "; 
            }
            else {
                cout << *cvit; //Final word is printed without comma nor space
            }
        }
        cout << "]" << endl; //Prints final bracket and new line character
    }
}

void print_rev(map<string, vector<string>> graph_map) {
    //Iterates through map in reverse order
    for (map<string, vector<string>>::const_reverse_iterator crmit = graph_map.crbegin(); crmit != graph_map.crend(); ++crmit) {
        //Prints digraph/trigraph
        cout << crmit->first << ": ["; 
        unsigned int count = 0; //Counts number of entries 
        for (vector<string>::const_iterator cvit = crmit->second.cbegin(); cvit != crmit->second.cend(); ++cvit) {
            count++; 
            if (count != crmit->second.size()) { //Every word but the last is printed with a comma and space after the container word
                cout << *cvit << ", "; 
            }
            else {
                cout << *cvit; //Final container word is printed without a comma nor space
            }
        }
        cout << "]" << endl; //Ends digraph/trigraph with a bracket and newline
    }
}

bool cmp_str(std::string a, std::string b) {
    //Sees if string a is larger than string b
    if (a.size() > b.size()) {
        return true; 
    }

    //Sees if string b is larger than string a
    if (a.size() < b.size()) {
        return false; 
    }

    //Returns if a is less than b based on ascii order
    return a < b; 
}

void print_count(map<string, vector<string>> graph_map) {
    //Initializes vector of digraphs 
    vector<string> keys; 
    for (map<string, vector<string>>::const_iterator cmit = graph_map.cbegin(); cmit != graph_map.cend(); ++cmit) {
        keys.push_back(cmit->first); 
    }

    //Sorts digraphs 
    sort(keys.begin(), keys.end(), cmp_str); 

    //Iterates through sorted digraph vector
    for (vector<string>::const_iterator cvit1 = keys.cbegin(); cvit1 != keys.cend(); ++cvit1) {
        cout << *cvit1 << ": ["; 
        unsigned int count = 0; //Counts number of entries 
        for (vector<string>::const_iterator cvit2 = graph_map[*cvit1].cbegin(); cvit2 != graph_map[*cvit1].cend(); ++cvit2) {
            count++; 
            if (count != graph_map[*cvit1].size()) { //Every word but the last is printed with a comma and space after the container word
                cout << *cvit2 << ", "; 
            }
            else {
                cout << *cvit2; //Final container word is printed without a comma nor space
            }
        }
        cout << "]" << endl; //Ends digraph/trigraph with a bracket and newline       
    }
}