#include <bits/stdc++.h>
#include "minstack.h"
using namespace std;

int Q;

int main() {
	scanf("%d", &Q);
	while (Q--) {
		int op;
		scanf("%d", &op);
		if (op == 0) {
			int x;
			scanf("%d", &x);
			push(x);
		} else if (op == 1) pop();
		else if (op == 2) printf("%d\n", top());
		else printf("%d\n", getMin());
	}
}

