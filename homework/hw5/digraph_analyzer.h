#ifndef DIGRAPH_ANALYZER_H
#define DIGRAPH_ANALYZER_H


//HELPER FUNCTIONS 

//Converts strings to lowercase without punctuation
std::string lower_string(std::string word); 

//Compares digraphs/trigraphs
bool cmp_entries(std::pair<std::string, std::vector<std::string>> a, std::pair<std::string, std::vector<std::string>> b);

//Detects if word has all alphabetical characters
bool isnum_word(std::string word); 



//MAIN FUNCTIONS

//Initiates vector of digraphs/trigraphs to search for
std::vector<std::string> init_graphs(std::istream& in); 

//Search text for digraphs/trigraphs
std::map<std::string, std::vector<std::string>> find_graphs(std::istream& in, std::vector<std::string> graph_vec); 

//Prints a single entry from graph map
void print_entry(std::map<std::string, std::vector<std::string>> graph_map, std::string key); 

//Print contents of digraph/trigraph map in ASCII order
void print_ascii(std::map<std::string, std::vector<std::string>> graph_map);

//Print contents of digraph/trigraph map in reverse order
void print_rev(std::map<std::string, std::vector<std::string>> graph_map);

//Print contents of digraph/trigraph map by frequency
void print_count(std::map<std::string, std::vector<std::string>> graph_map);

//Print query with given number of entries
void print_qnum(std::map<std::string, std::vector<std::string>> graph_map, std::string word);

#endif