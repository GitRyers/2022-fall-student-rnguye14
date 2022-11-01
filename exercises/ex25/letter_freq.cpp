#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <algorithm>

using std::cout;
using std::cerr;
using std::endl;
using std::ifstream; 
using std::sort;
using std::vector; 

struct Bucket {
  char letter;
  unsigned count; 
};

bool compare_buckets(const Bucket &left, const Bucket &right) {
  if (left.count > right.count) {
    return true;
  }
  if (left.count < right.count) {
    return false;
  }
  return left.letter < right.letter; 
}

int main(int argc, char **argv) {
  if (argc != 2) {
    cerr << "Wrong number of inputs" << endl;
    return 1;
  }
  
  ifstream in(argv[1]);
  if (!in.is_open()) {
    cerr << "failed to open input file" << endl;
    return 1; 
  }

  vector<Bucket> hist;
  for (char ch = 'a'; ch <= 'z'; ch++) {
    Bucket b;
    b.letter = ch;
    b.count = 0;
    hist.push_back(b); 
  }
  
  char ch;
  while (in.get(ch)) {
    if (isalpha(ch)) {
      ch = tolower(ch);
      hist[ch - 'a'].count++;
    }
  }

  sort(hist.begin(), hist.end(), compare_buckets);

  for (vector<Bucket>::const_iterator it = hist.cbegin(); it != hist.cend(); it++) {
    if (it->count > 0) {
      cout << it->letter << ": " << it->count << endl;  
    }
  }

  return 0;
}