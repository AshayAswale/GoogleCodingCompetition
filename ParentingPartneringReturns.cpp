#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <iterator>
#include <algorithm>

std::pair<std::pair<int, int>, int> split(const std::string &line, int i)
{
  std::vector<int> vec;
  std::istringstream is(line);
  vec = std::vector<int>(std::istream_iterator<int>(is), std::istream_iterator<int>());
  std::pair<std::pair<int, int>, int> pair;
  pair.first.first = vec.front();
  pair.first.second = vec.back();
  pair.second = i;
  return pair;
}

int main()
{
  std::string line;
  std::getline(std::cin, line);
  int T = std::stoi(line);

  for (size_t t = 0; t < T; t++)
  {
    std::string schedule;
    std::getline(std::cin, line);
    int N = std::stoi(line);
    int c, j;
    c = 0;
    j = 0;
    std::vector<std::pair<std::pair<int, int>, int>> time;
    bool test = true;
    schedule.resize(N);
    time.resize(N);

    for (size_t i = 0; i < N; i++)
    {
      getline(std::cin, line);
      std::stringstream stream(line);
      time.at(i) = split(line, i);
    }

    std::sort(time.begin(), time.end());

    for (std::pair<std::pair<int, int>, int> t : time)
    {
      if (t.first.first >= c)
      {
        schedule.at(t.second) = 'C';
        c = t.first.second;
      }
      else if (t.first.first >= j)
      {
        schedule.at(t.second) = 'J';
        j = t.first.second;
      }
      else
      {
        schedule = "IMPOSSIBLE";
        break;
      }
    }
    std::cout << "Case #" << t + 1 << ": " << schedule << std::endl;
  }
}
