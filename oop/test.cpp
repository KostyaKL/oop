#include "headers.h"
#include <iostream>
using namespace std;

int func2(int n) {
	int i, input, prev, count, start, biggest_count, biggest_start;
	
	count = 0;
	start = 0;
	biggest_count = 0;
	biggest_start = 0;

	printf("enter %d digits, only 1 or 0 allowed:\n", n);
	do {
		scanf("%d", &input);
		if (input < 0 || input>1) {
			printf("\nonly 1 or 0 allowed\n");
		}
	} while (input < 0 || input>1);
	prev = input;

	for (i = 1;i < n;i++) {
		do {
			scanf("%d", &input);
			if (input < 0 || input>1) {
				printf("\nonly 1 or 0 allowed\n");
			}
		} while (input < 0 || input>1);
		

		if (input == prev) {
			count++;
		}
		else {
			if (count > biggest_count) {
				biggest_count = count;
				biggest_start = start;
			}
			count = 0;
			start = i;
		}
		prev = input;
	}
	return biggest_start + 1;
}

void test() {
	int n, pos;
	printf("enter how many digits is your number(n): ");
	do {
		scanf("%d", &n);
		if (n < 1)
			printf("n must be a positive integer (at least 1), try again: ");
	} while (n < 1);

	pos = func2(n);

	printf("\nthe longest straight of same digits start at position %d", pos);

	printf("\n\n");
	system("pause");
}