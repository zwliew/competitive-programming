#include <iostream>
#include <string>

int main() {
  int N;
  std::cin >> N;

  const std::string mew("MEW");
  const std::string meow("MEOW");

  int female = 0;
  int male = 0;

  while (N--) {
    std::string in;
    std::cin >> in;

    if (!in.compare(meow)) {
      female++;
    } else if (!in.compare(mew)) {
      male++;
    }
  }

  if (!male) {
    std::cout << "OMG MEEEAHHHH!!!!" << std::endl;
  } else {
    std::cout << female / male << std::endl;
  }
}
