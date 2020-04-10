#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <iterator>

int main()
{
  std::string line;
  std::getline(std::cin, line);
  int T = std::stoi(line);

  const std::string open_par = "(";
  const std::string close_par = ")";

  for (size_t t = 1; t <= T; t++)
  {
    getline(std::cin, line);
    size_t par_counter = 0;
    for (size_t i = 0; i < line.size(); i++)
    {
      int n = (int)(line.at(i)) - (int)'0';
      // Inserting open paranthesis
      for (size_t par = par_counter; par < n && n != par_counter; par++)
      {
        line.insert(i, open_par);
        i++;
        par_counter++;
      }

      // Inserting closing paranthesis
      for (size_t par = par_counter; par > n && n != par_counter; par--)
      {
        line.insert(i, close_par);
        i++;
        par_counter--;
      }
    }
    // Close ending paranthesis
    for (size_t par = par_counter; par > 0; par--)
    {
      line.append(close_par);
      par_counter--;
    }
    std::cout << "Case #" << t << ": " << line << std::endl;
  }
}
