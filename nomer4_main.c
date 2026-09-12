#include <stdio.h>
#include "nomer4_c.h"

int main(){
	int input;
	int attampt = 0;
	int magazine[3];
	int counter = 0;
	while (attampt < 3){
		printf("Input 3x PIN: ");
		if (scanf("%d", &input) != 1) return 2;
		if (check(input) == 0) {
			printf("GRANTED\n");
			magazine[counter] = input;
			counter++;
			break;
		} else{
			attampt ++;
			printf("Error\n");
			magazine[counter] = input;
			counter++;
		}
	}
	if (attampt == 3){
		printf("DECLINED\n");
		magazine[counter] = input;
		counter++;
	}
	
	printf("\nMAGAZINE\n");
	for (int i = 0; i < counter; i++) {
		printf("%d\n", magazine[i]);
	}
	if (attampt == 3) {
		return 1;
	} else{
		return 0;
	}
}
