#include <stdio.h>
#include <time.h>

int main(){
	int year, month, day;
	if (scanf("%d-%d-%d", &year, &month, &day) != 3) return 1;
	struct tm date = {0};
	date.tm_year = year - 1900;
	date.tm_mon = month - 1;
	date.tm_mday = day + 1;
	date.tm_isdst = -1;
	mktime(&date);
	printf("%04d", date.tm_year + 1900);
	printf("-");
	printf("%02d", date.tm_mon + 1);
	printf("-");
	printf("%02d\n", date.tm_mday);
	return 0;
}
