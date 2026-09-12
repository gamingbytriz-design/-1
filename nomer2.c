#include <stdio.h>

int main(){
	int beg, end;
	printf("Input two numbers: \n");
	if (scanf("%x", &beg) != 1) return 1;
	if (scanf("%x", &end) != 1) return 1;
	printf("\nSymbol\n");
	int counter = 0;
	printf("-----------------------------\n");
	for (int i = beg; i <= end; i++){
		if (i < 32 || i > 126) continue;
		printf("%c ", (char)i);
		counter++;
		if (counter % 10 == 0) {
			printf("\n");
		}
	}
	printf("\n");
	return 0;
}
	
