// my first program in C++
#include <iostream>
#include "git2/rev-parse.h"

int main()
{
  struct parse_state ps = {0};

  parse_revision(&ps, "HEAD");
}
