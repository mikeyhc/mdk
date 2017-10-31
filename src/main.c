#include <stdio.h>
#include <string.h>

#define BUFSIZE 1000
#define PROMPT "m)"

void
eval(const char *input)
{
	printf("%s\n", input);
}

int
main(void)
{
	char buf[BUFSIZE];
	printf(PROMPT);
	while (fgets(buf, BUFSIZE, stdin)) {
		eval(buf);
		printf(PROMPT);
	}
	printf("\n");
	return 0;
}
