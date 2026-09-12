#include <stdio.h>
#include <time.h>

int main(){
	time_t times = time(NULL);
	struct tm *date = localtime(&times);
	printf("%04d", date -> tm_year + 1900);
	printf("-");
	printf("%02d", date -> tm_mon + 1);
	printf("-");
	printf("%02d", date -> tm_mday);
	printf("\n");
	return 0;
}
