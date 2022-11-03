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

//Helper functions 
string lower_string(string word) {
    //Initializes lowered string variable
    string ret_word; 

    //Iterates through each letter of parameter word
    for (size_t i = 0; i < word.size(); i++) {
        if ((word[i] != '.') && (word[i] != ',') && (word[i] != '?') && (word[i] != '!')) { //Detects if word has puncutation
            ret_word += tolower(word[i]); //Adds lowered character to return string
        }
    }
    return ret_word; 
}

bool cmp_entries(pair<string, vector<string>> a, pair<string, vector<string>> b) {
    //Sees if number of counts in a are larger than b
    if (a.second.size() > b.second.size()) {return true;}

    //Sees if number of counts in a are larger than b
    if (a.second.size() < b.second.size()) {return false;}

    //Returns if a is less than b based on ascii order
    return a.first < b.first; 
}

bool isnum_word(string word) {
    for (size_t i = 0; i < word.size(); i++) {
        if (!isdigit(word[i])) {
            return false;
        }
    }
    return true; 
}

//Main code functions
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
                    string ret_word = lower_string(word); 
                    mit->second.push_back(ret_word);                 
                }     
            } 
        }
    }
    return graph_map; 
}

void print_entry(std::map<std::string, std::vector<std::string>> graph_map, std::string key) {
    cout << key << ": ["; //Prints digraph/trigraph and start of bracket
    unsigned int count = 0; //Keeps track of number of entries
    for (vector<string>::const_iterator cvit = graph_map[key].cbegin(); cvit != graph_map[key].cend(); ++cvit) {
        count++; 
        if (count != graph_map[key].size()) { //For every entry but the last, a comma and space is printed after the word
            cout << *cvit << ", "; 
        }
        else {
            cout << *cvit; //Final word is printed without comma nor space
        }
    }
    cout << "]" << endl; //Prints final bracket and new line character
}

void print_ascii(map<string, vector<string>> graph_map) {
    //Iterates through each map entry, which is already in ASCII order
    for (map<string, vector<string>>::const_iterator cmit = graph_map.cbegin(); cmit != graph_map.cend(); ++cmit) { 
        print_entry(graph_map, cmit->first); //Prints each entry
    }
}

void print_rev(map<string, vector<string>> graph_map) {
    //Iterates through map in reverse order
    for (map<string, vector<string>>::const_reverse_iterator crmit = graph_map.crbegin(); crmit != graph_map.crend(); ++crmit) {
        print_entry(graph_map, crmit->first); //Prints each entry
    }
}

void print_count(map<string, vector<string>> graph_map) {
    //Initializes vector of digraph counts
    vector<pair<string, vector<string>>> vals; 
    for (map<string, vector<string>>::const_iterator cmit = graph_map.cbegin(); cmit != graph_map.cend(); ++cmit) {
        vals.push_back(*cmit); 
    }

    //Sorts digraphs 
    sort(vals.begin(), vals.end(), cmp_entries); 

    //Iterates through sorted digraph vector
    for (vector<pair<string, vector<string>>>::const_iterator cvit = vals.cbegin(); cvit != vals.cend(); ++cvit) {
        print_entry(graph_map, cvit->first);       
    }
}

void print_qnum(map<string, vector<string>> graph_map, string key) {
    cout << graph_map[key].size() << ": ["; //Prints num of entries for digraph and start of bracket
    unsigned int count = 0; //Keeps track of number of entries
    for (vector<string>::const_iterator cvit = graph_map[key].cbegin(); cvit != graph_map[key].cend(); ++cvit) {
        count++; 
        if (count != graph_map[key].size()) { //For every entry but the last, a comma and space is printed after the word
            cout << *cvit << ", "; 
        }
        else {
            cout << *cvit; //Final word is printed without comma nor space
        }
    }
    cout << "]" << endl; //Prints final bracket and new line character
}