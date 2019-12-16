#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include "struct.h"
#include "print.h"

void printTicketArr(Aviasales* ticketArr, int arrSize) {
	for (int i = 0; i < arrSize; i++)
	{
		printf("%.2i.%.2i; %.2i:%.2i; %s; %d; ", ticketArr[i].dt.day, ticketArr[i].dt.month, ticketArr[i].time.hour, ticketArr[i].time.minute, ticketArr[i].nameOfAirfield, ticketArr[i].travelTime);
		ticketArr[i].isBreak == 1 ? printf("Завтрак включён\n") : printf("Без завтрака\n");
	}
}

void saveDB(Aviasales* ticketArr, int arrSize) {
	FILE* file = fopen("D:\\database.txt", "w");
	for (int i = 0; i < arrSize; i++)
	{
		fprintf(file, "%.2i.%.2i;%.2i:%.2i;%s;%d;\n", ticketArr[i].dt.day, ticketArr[i].dt.month, ticketArr[i].time.hour, ticketArr[i].time.minute, ticketArr[i].nameOfAirfield, ticketArr[i].travelTime);
	}
	fclose(file);
}
