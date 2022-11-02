#ifndef DIGRAPH_ANALYZER_H
#define DIGRAPH_ANALYZER_H

//Initiates vector of digraphs/trigraphs to search for
std::vector<std::string> init_graphs(std::istream& in); 

//Search text for digraphs/trigraphs
std::map<std::string, std::vector<std::string>> find_graphs(std::istream& in, std::vector<std::string> graph_vec); 

//Print contents of digraph/trigraph map in ASCII order
void print_ascii(std::map<std::string, std::vector<std::string>> graph_map);

//Print contents of digraph/trigraph map in reverse order
void print_rev(std::map<std::string, std::vector<std::string>> graph_map);

//Compares digraphs/trigraphs
bool cmp_str(std::string a, std::string b);

//Print contents of digraph/trigraph map by frequency
void print_count(std::map<std::string, std::vector<std::string>> graph_map);

#endif