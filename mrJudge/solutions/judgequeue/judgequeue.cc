//#include "judgequeue.h"
#include <list>
#include <vector>
#include <cstdint>

std::list<int32_t> l;
std::vector<std::list<int32_t>::iterator> it;

/* Initialize function */
void init(int X, int N) {
  it = std::vector<std::list<int32_t>::iterator>(N + 1);
}

/* Update functions */
void push_front(int subID) {
  l.emplace_front(subID);
  it.at(subID) = l.begin();
}

void push_back(int subID) {
  l.emplace_back(subID);
  it.at(subID) = --l.end();
}

void insert_before(int subID, int ref) {
  it.at(subID) = l.emplace(it.at(ref), subID);
}

void insert_after(int subID, int ref) {
  auto i = it.at(ref);
  i++;
  it.at(subID) = l.emplace(i, subID);
}

/* Access functions */
int queue_front() {
  return l.front();
}

int queue_back() {
  return l.back();
}

int sub_before(int ref) {
  auto i = it.at(ref);
  i--;
  return *i;
}

int sub_after(int ref) {
  auto i = it.at(ref);
  i++;
  return *i;
}

/* Modify functions */
void pop_front() {
  l.pop_front();
}

void pop_back() {
  l.pop_back();
}

void erase(int subID) {
  l.erase(it.at(subID));
}

/* Uncomment the following for testing, comment it back for submission */
#include <cstdio>
#include <cstring>
using namespace std;
int main () {
    int X, N;
    scanf("%d%d", &X, &N);
    init(X, N);
    char command[50];
    for (int i = 0, A, B; i < X; ++i) {
        scanf("%s", command);
        if (strcmp(command, "push_back") == 0) {
            scanf("%d", &A);
            push_back(A);
        }
        else if (strcmp(command, "push_front") == 0) {
            scanf("%d", &A);
            push_front(A);
        }
        else if (strcmp(command, "insert_before") == 0) {
            scanf("%d%d", &A, &B);
            insert_before(A, B);
        }
        else if (strcmp(command, "insert_after") == 0) {
            scanf("%d%d", &A, &B);
            insert_after(A, B);
        }
        else if (strcmp(command, "queue_front") == 0) {
            printf("%d\n", queue_front());
        }
        else if (strcmp(command, "queue_back") == 0) {
            printf("%d\n", queue_back());
        }
        else if (strcmp(command, "sub_before") == 0) {
            scanf("%d", &A);
            printf("%d\n", sub_before(A));
        }
        else if (strcmp(command, "sub_after") == 0) {
            scanf("%d", &A);
            printf("%d\n", sub_after(A));
        }
        else if (strcmp(command, "pop_front") == 0) {
            pop_front();
        }
        else if (strcmp(command, "pop_back") == 0) {
            pop_back();
        }
        else if (strcmp(command, "erase") == 0) {
            scanf("%d", &A);
            erase(A);
        }
        else {
            printf("Invalid command '%s'\n", command);
            return 0;
        }
    }
}

