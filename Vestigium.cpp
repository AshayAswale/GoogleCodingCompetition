#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <iterator>

void printKRC(std::vector<std::vector<int>> &board, int T)
{
  int N = board.size();
  int row_repeat = 0, col_repeat = 0, sum_dia = 0;
  for (int i = 0; i < N; i++)
  {
    bool is_repeat_row = false, is_repeat_col = false;
    for (int j = 0; j < N; j++)
    {
      for (int k = j + 1; k < N; k++)
      {
        if (board.at(j).at(i) == board.at(k).at(i) && !is_repeat_col)
        {
          col_repeat++;
          // std::cout << "col repeat " << i << std::endl;
          is_repeat_col = true;
        }
        if (board.at(i).at(j) == board.at(i).at(k) && !is_repeat_row)
        {
          row_repeat++;
          // std::cout << "row repeat " << j << std::endl;
          is_repeat_row = true;
        }
        // std::cout << sum_dia << " from " << board.at(i).at(i);
        if (is_repeat_col && is_repeat_row)
          break;
      }
    }
    sum_dia += board.at(i).at(i);
  }
  std::cout << "Case #" << T << ": " << sum_dia << " " << row_repeat << " " << col_repeat << std::endl;
}

void split(const std::string &line, std::vector<int> &vec)
{
  std::istringstream is(line);
  vec = std::vector<int>(std::istream_iterator<int>(is), std::istream_iterator<int>());
}

int main()
{
  std::string line;

  // T
  std::getline(std::cin, line);
  int T = std::stoi(line);
  int T_stat = T;

  while (T > 0)
  {
    getline(std::cin, line);
    int N = std::stoi(line);
    std::vector<std::vector<int>> board;
    board.resize(N);
    int i = 0;
    while (N > 0)
    {
      board.at(i).resize(N--);
      getline(std::cin, line);
      std::stringstream stream(line);
      split(line, board.at(i++));
    }

    printKRC(board, T_stat - T + 1);

    --T;
  }
  return 0;
}