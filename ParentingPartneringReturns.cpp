#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <iterator>

std::pair<int, int> split(const std::string &line)
{
  std::vector<int> vec;
  std::istringstream is(line);
  vec = std::vector<int>(std::istream_iterator<int>(is), std::istream_iterator<int>());
  std::pair<int, int> pair;
  pair.first = vec.front();
  pair.second = vec.back();
  return pair;
}

bool isAvailable(std::vector<std::pair<int, int>> &person, std::pair<int, int> time)
{
  for (std::pair<int, int> slot : person)
  {
    bool start_overlap = (time.first < slot.second && time.first >= slot.first);
    bool end_overlap = (time.second > slot.first && time.second <= slot.second);
    bool encompass = (time.first < slot.first && time.second > slot.second);
    if (start_overlap || end_overlap || encompass)
    {
      return false;
    }
  }
  return true;
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
    std::vector<std::pair<int, int>> c, j;
    std::pair<int, int> time;
    bool test = true;
    for (size_t i = 0; i < N; i++)
    {
      getline(std::cin, line);
      if (test)
      {
        std::stringstream stream(line);
        time = split(line);

        if (isAvailable(c, time))
        {
          schedule.append("C");
          c.push_back(time);
        }
        else if (isAvailable(j, time))
        {
          schedule.append("J");
          j.push_back(time);
        }
        else
        {
          schedule = "IMPOSSIBLE";
          test = false;
          // break;
        }
      }
    }
    std::cout << "Case #" << t + 1 << ": " << schedule << std::endl;
  }
}
