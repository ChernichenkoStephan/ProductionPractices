#include "pch.h"

#include "../src/e/linear.cpp"

using std::string;

TEST(Lab2, RunAllPossibleTests) {

  string e0 = solve_linear(7, 7, 7, 7, 7, 7);
  ASSERT_STREQ(e0.c_str(), "1 -1 1");

  string e1 = solve_linear(0, 0, 0, 0, 0, 0);
  ASSERT_STREQ(e1.c_str(), "5");

  string e2 = solve_linear(7, 7, 0, 7, 7, 7);
  ASSERT_STREQ(e2.c_str(), "2 0 1");

  string e3 = solve_linear(0, 7, 0, 0, 7, 7);
  ASSERT_STREQ(e3.c_str(), "0");

  string e4 = solve_linear(0, 0, 7, 0, 0, 7);
  ASSERT_STREQ(e4.c_str(), "3 1");

  string e6 = solve_linear(6.66, 6.66, 6.66, 6.66, 6.66, 6.66);
  ASSERT_STREQ(e6.c_str(), "1 -1 1");

  string e5 = solve_linear(0, 0, 0, 7, 0, 7);
  ASSERT_STREQ(e5.c_str(), "4 1");

  string e7 = solve_linear(7, 0, 7, 7, 0, 7);
  ASSERT_STREQ(e7.c_str(), "2 0 1");

}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
