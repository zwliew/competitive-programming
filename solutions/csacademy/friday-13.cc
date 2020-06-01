#include <iostream>
#include <vector>

using namespace std;

int main() {
  string s;
  cin >> s;
  vector<string> days = {"Monday", "Tuesday",  "Wednesday", "Thursday",
                         "Friday", "Saturday", "Sunday"};
  vector<int> months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int day;
  for (day = 0; day < 7; ++day) {
    if (days[day] == s) {
      break;
    }
  }

  int count = 0;
  int dayMonth = 1;
  int month = 0;
  for (int i = 0; i < 365; ++i) {
    if (dayMonth == 13 && days[day] == "Friday") {
      ++count;
    }
    day = (day + 1) % 7;
    ++dayMonth;
    if (dayMonth > months[month]) {
      dayMonth = 1;
      month++;
    }
  }
  cout << count;
}