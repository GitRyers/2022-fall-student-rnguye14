#include <iostream>
#include <fstream>
#include <vector>
#include <exception>
#include <stdexcept>

/* Collect integers from a file; store them in a vector */
std::vector<int> readFile(char* filename) {
  std::ifstream fin(filename);
  if (!fin.is_open()){
    throw std::ios_base::failure("ERROR: invalid file name!\n"); 
  }
  std::vector<int> numbers(10);

  int n = 0;
  size_t index = 0;
  while(true) {
    fin >> n;
    if (fin.eof()) { // if we're out of file, return
      return numbers;
    }
    if (fin.fail()) { // if we failed to read an int, throw an exception
      throw std::invalid_argument("File contains non-integer data!\n");
    }
    // otherwise, just add it into the vector
    numbers.at(index) = n;
    index++;
  }

  throw std::logic_error("ERROR: should never get here!");
  return numbers;
}

int main(int argc, char **argv) {
  if (argc < 2) {
    std::cout << "Error: program requires a filename as an argument\n";
    return 0;
  }

  std::vector<int> numbers;
  try {
    numbers = readFile(argv[1]);
  }
  catch(const std::out_of_range& e) {
    std::cout << "Exception: too many integers were provided" << std::endl; 
  }
  catch(const std::ios_base::failure& e) {
    std::cout << "Exception: invalid file name" << std::endl; 
  }
  catch (const std::invalid_argument& e) {
    std::cout << "Exception: file contains non-integer data" << std::endl; 
  }

  std::cout << "Read numbers: ";
  for(int &i : numbers) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  return 0;
}
