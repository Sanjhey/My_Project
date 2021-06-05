// SA.SANJHEY HARIRAM (TIC TAC TOE).cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
int main() {
	int winner = 0, count = 0;
	int data[9], index, sign, player, flag, a, b;
	for (a = 0; a < 9; a++)
		data[a] = ' ';

	while (count < 9) {
		flag = 0;
		system("clear");
		printf("\n\n");
		printf("\t\t\t  %c | %c  | %c  \n", data[0], data[1], data[2]);
		printf("\t\t\t----+----+----\n");
		printf("\t\t\t  %c | %c  | %c  \n", data[3], data[4], data[5]);
		printf("\t\t\t----+----+---\n");
		printf("\t\t\t  %c | %c  | %c  \n", data[6], data[7], data[8]);
		if (count % 2 == 0) {
			sign = 'X';
			player = 1;
		}
		else {
			sign = 'O';
			player = 2;
		}
		printf("Move for player%d(1-9):", player);
		scanf("%d", &index);
		if (index < 1 || index > 9) {
			printf("Allowed index is 1 to 9!!\n");
			continue;
		}
		if (data[index - 1] == 'X' || data[index - 1] == 'Y') {
			printf("Position Already occupied!!\n");
			Sleep(1);
			continue;
		}
		data[index - 1] = sign;
		count++;


		for (a = 0; a < 9; a++) {
			if (a % 3 == 0)
				flag = 0;


			if (data[a] == sign)
				flag++;


			if (flag == 3) {
				winner = 1;
				goto win;
			}
		}


		flag = 0;
		for (a = 0; a < 3; a++) {
			for (b = a; b <= a + 6; b = b + 3) {
				if (data[b] == sign)
					flag++;
			}
			if (flag == 3) {
				winner = 1;
				goto win;
			}
			flag = 0;
		}
		if ((data[0] == sign && data[4] == sign && data[8] == sign) ||
			(data[2] == sign && data[4] == sign && data[6] == sign)) {
			winner = 1;
			goto win;
		}
	}
win:
	system("clear");
	printf("\n\n");
	printf("\t\t\t  %c | %c  | %c  \n", data[0], data[1], data[2]);
	printf("\t\t\t----+----+----\n");
	printf("\t\t\t  %c | %c  | %c  \n", data[3], data[4], data[5]);
	printf("\t\t\t----+----+---\n");
	printf("\t\t\t  %c | %c  | %c  \n\n", data[6], data[7], data[8]);
	if (winner) {
		printf("Player %d is the winner. Congrats!!\n", player);
	}
	else {
		printf("Match draw.. Best of luck for both\n");
	}
	return 0;
}



