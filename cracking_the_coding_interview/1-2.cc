#include <cstring>
#include <cstdio>
#include <cstdlib>

void reverse(char* str) {

	char * head = str;
	char * cur_head = str;
	int len = 0;

	while (*cur_head != '\0') {
		cur_head = cur_head + 1;
		len += 1;
	}

	// restore head
	cur_head = head;

	char * new_str = (char*)calloc(len, 1);
	for (int i = 0; i < len/2; ++i) {
		int front_index = i;
		int back_index = len-i-1;

		// printf("%d %d\n", front_index, back_index);

		char tmp = str[front_index];
		// printf("%c\n", tmp);

		new_str[front_index] = str[back_index];
		new_str[back_index] = tmp;
	}

	printf("%s\n", str);
	str = new_str;
	printf("%s\n", str);
}

int main(void) {
	char * str = "abcdefgh";
	reverse(str);
	printf("%s\n", str);
}
