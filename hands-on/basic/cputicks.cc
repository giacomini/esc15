#include <iostream>
#include <iomanip>
#include <chrono>
#include <cmath>

double test1(int n_iter)
{
  double sum = 0.;
  double const step = M_PI / n_iter;
  auto total_time = std::chrono::high_resolution_clock::duration{};

  double val = 0.;
  for (int i = 0; i < n_iter; ++i, val += step) {
    auto start = std::chrono::high_resolution_clock::now();
    sum += sin(val);
    auto end = std::chrono::high_resolution_clock::now();

    auto dtime = end - start;
    std::cout << '#' << i << ' ' << std::setw(5) << dtime.count() << '\n';
    total_time += dtime;
  }

  std::cout << "TOTAL " << total_time.count() << '\n';

  return sum;
}

double test2(int n_iter)
{
  double sum = 0.;
  double const step = M_PI / n_iter;

  auto start = std::chrono::high_resolution_clock::now();
  double val = 0.;
  for (int i = 0; i < n_iter; ++i, val += step) {
    sum += sin(val);
  }
  auto end = std::chrono::high_resolution_clock::now();

  auto total_time = end - start;
  std::cout << "TOTAL " << total_time.count() << '\n';

  return sum;
}

int main(int argc, char* argv[])
{
  int const n_iter = (argc > 1) ? std::stoi(argv[1]) : 10;

  auto const t1 = test1(n_iter);
  std::cout << "test1(): " << std::setprecision(3) << t1 << '\n';

  auto const t2 = test2(n_iter);
  std::cout << "test2(): " << std::setprecision(3) << t2 << '\n';
}
