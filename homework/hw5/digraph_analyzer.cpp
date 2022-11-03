#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cctype> 
#include "digraph_analyzer.h"

using std::cin; 
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::map; 
using std::ifstream;  

int main(int argc, char * argv[]) {
  // if number of arguments is not correct, exit with code 1!
  if (argc != 3) {
    cout<<"Invalid arguments"<<endl;
    return 1;
  }
   
  // if the "order" argument is not valid, exit with code 1!
  string order(argv[2]);
  if (order != "r" && order != "a" && order != "c") {
    cout<<"Invalid arguments"<<endl;
    return 1;
  }

  ifstream ifile(argv[1]);
  //if the input file cannot be opened, exit with code 2! 
  if (!(ifile.is_open())){
    cout<<"Input file could not be opened"<<endl; 
    return 2; 
  }

  //Creates initial vector of digraphs/trigraphs to search for
  vector<string> graph_vec = init_graphs(ifile); 
  
  //Creates map with keys being digraphs/trigraphs and values being a vector of container words 
  map<string, vector<string>> graph_map = find_graphs(ifile, graph_vec); 

  //Detects command option and prints accordingly
  if (order == "a") {
    print_ascii(graph_map); 
  }
  else if (order == "r") {
    print_rev(graph_map); 
  }
  else {
    print_count(graph_map); 
  }
  
  //Requests user input 
  cout << "q?>"; 
  string input;
  while (cin >> input) {
    //Detects for integer user input
    if (isnum_word(input)) { 
      int num_app = atoi(input.c_str()); //Converts word input to integer
      int num_found = 0; //Counts how many entries were printed 
      for (map<string, vector<string>>::const_iterator cmit = graph_map.cbegin(); cmit != graph_map.cend(); ++cmit) {
        if ((int) cmit->second.size() == num_app) { //Compares if input is equal to size of container word list
          print_entry(graph_map, cmit->first); //Prints entry if it does
          num_found++; //Increments for each time a word is found
        }
      }  

      //Handles exit conditions
      if (num_found == 0) {
        cout << "None" << endl; //If 0 prints, print None
        cout << "q?>"; 
        continue; 
      }
      else {
        cout << "q?>"; //Otherwise continues loop
        continue; 
      }
    }        

    //Uses word input in lowercase otherwise 
    string lowput = lower_string(input); 

    //Exits
    if (lowput == "exit") {
      break; 
    }

    //Searches for digraph entry and prints accordingly
    if (std::find(graph_vec.begin(), graph_vec.end(), lowput) != graph_vec.end()) { 
      print_qnum(graph_map, lowput); 
      cout << "q?>"; 
    }
    else {
      cout << "No such digraph" << endl;
      cout << "q?>";  
    }
  }
  
  return 0;
}