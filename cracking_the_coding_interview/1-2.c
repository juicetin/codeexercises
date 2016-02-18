#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void reverse(char* str) {

	// Maintain head
	char * cur_head = str;

	// Length of string
	int len = 0;

	// Get length
	while (*cur_head != '\0') {
		cur_head = cur_head + 1;
		len += 1;
	}

	// Exchange
	for (int i = 0; i < len/2; ++i) {
		int front_index = i;
		int back_index = len-i-1;

		printf("%d %d\n", front_index, back_index);

		char tmp = str[front_index];
		printf("%c\n", tmp);
		printf("%c %c\n", str[front_index], str[back_index]);

		str[front_index] = str[back_index];
		str[back_index] = tmp;
	}
}

int main(void) {
	// char * str = "abcdefgh";
	char str[256];
	fgets(str, 256, stdin);
	reverse(str);
	printf("%s\n", str);
}
