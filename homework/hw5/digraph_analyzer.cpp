#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
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

  vector<string> graph_vec = init_graphs(ifile); 
  
  map<string, vector<string>> graph_map = find_graphs(ifile, graph_vec); 

  if (order == "a") {
    print_ascii(graph_map); 
  }
  else if (order == "r") {
    print_rev(graph_map); 
  }
  else {
    print_count(graph_map); 
  }

  cout << "q?>"; 
  string input;
  while (cin >> input) {
    if (isdigit(input[0])) {
    
    } 
  }
  
  return 0;
}


