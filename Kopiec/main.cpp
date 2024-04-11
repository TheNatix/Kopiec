#include <iostream>

using namespace std;

int main() {
	const int values[] = { 4,5,8,3,8,2 };
	int size = sizeof(values) / sizeof(int);
	int* tab = (int *)malloc(size*sizeof(int));


	return 0;
}