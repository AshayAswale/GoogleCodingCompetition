#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <iterator>
#include <algorithm>

bool isValidNum(std::vector<std::vector<int>> &latin_square, int row, int col, int num, int N)
{
  bool in_row, in_col;
  for (size_t i = 0; i < N; i++)
  {
    in_row = num == latin_square.at(row).at(i);
    in_col = num == latin_square.at(i).at(col);
    if (in_row || in_col)
      return false;
  }
  return true;
}

bool rowcolFiller(std::vector<std::vector<int>> &latin_square, int iter_col, int N)
{
  // tracing row-cols
  for (size_t i = (N - 1); i > iter_col; --i)
  {
    bool row_possible = false;
    bool col_possible = false;
    // checking all the numbers
    for (int num = 1; num <= N; num++)
    {
      if (isValidNum(latin_square, iter_col, i, num, N))
      {
        latin_square.at(iter_col).at(i) = num;
        row_possible = true;
        break;
      }
    }
    for (int num = 1; num <= N; num++)
    {
      if (isValidNum(latin_square, i, iter_col, num, N))
      {
        if (num == latin_square.at(iter_col).at(N - 1) && i == N - 1)
          continue;
        latin_square.at(i).at(iter_col) = num;
        col_possible = true;
        break;
      }
    }
    if (!col_possible)
    {
      int num = latin_square.at(iter_col).at(N - 1);
      if (isValidNum(latin_square, i, iter_col, num, N))
      {
        latin_square.at(i).at(iter_col) = num;
        col_possible = true;
      }
    }
    if (!row_possible || !col_possible)
      return false;
  }
  return true;
}

bool makeLatinSquare(std::vector<int> &sum, std::vector<std::vector<int>> &latin_square)
{
  int N = sum.size();
  bool possible;
  for (size_t i = 0; i < N; i++)
  {
    latin_square.at(i).at(i) = sum.at(i);
  }
  for (size_t i = 0; i < N; i++)
  {
    possible = rowcolFiller(latin_square, i, N);
    if (!possible)
      return false;
  }
  return true;
}

void getFirstSum(std::vector<int> &open_list, const int N, const int K)
{
  int max_dig = (K - N) / (N - 1);
  if (K == N * N)
  {
    open_list.assign(N, N);
    return;
  }

  open_list.assign(N, 1);
  for (size_t i = 0; i < max_dig; i++)
  {
    open_list.at((N - 1) - i) = N;
  }

  int rem = (K - N) % (N - 1);
  open_list.at(((N - 1) - max_dig)) += rem;
}

void split(const std::string &line, std::vector<int> &vec)
{
  std::istringstream is(line);
  vec = std::vector<int>(std::istream_iterator<int>(is), std::istream_iterator<int>());
}

int main()
{
  std::string line;
  std::getline(std::cin, line);
  int T = std::stoi(line);

  for (size_t t = 0; t < T; t++)
  {
    std::getline(std::cin, line);
    std::vector<int> temp;
    split(line, temp);

    int N = temp.front();
    int K = temp.back();
    std::string possibility;
    std::vector<std::vector<int>> latin_square(N, std::vector<int>(N));
    std::vector<int> sums;

    for (size_t i = 0; i < N; i++)
    {
      latin_square.at(i).assign(N, 0);
    }

    getFirstSum(sums, N, K);
    if (makeLatinSquare(sums, latin_square))
    {
      std::cout << "Case #" << t + 1 << ": "
                << "POSSIBLE" << std::endl;
      for (size_t i = 0; i < latin_square.size(); i++)
      {
        for (size_t j = 0; j < latin_square.front().size(); j++)
        {
          std::cout << latin_square.at(i).at(j) << " ";
        }
        std::cout << std::endl;
      }
    }
    else
    {
      std::cout << "Case #" << t + 1 << ": "
                << "IMPOSSIBLE" << std::endl;
    }
  }
  return 0;
}