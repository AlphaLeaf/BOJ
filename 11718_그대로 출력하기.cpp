#include <iostream>

using namespace std;

int main() {
	char j;
	while (1) {
		j = getchar();
		if (j == EOF) {
			break;
		}
		putchar(j);
	}
}