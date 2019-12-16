#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE

#include <cstring>
#include "struct.h"
#include "free.h"


void freeTicketArr(Aviasales* ticketArr, int arrSize) {
	for (int i = 0; i < arrSize; i++)
	{
		delete[] ticketArr[i].nameOfAirfield;
	}
	delete[] ticketArr;
}

void deleteTicket(Aviasales*& ticketArr, int tickNum, int& tickCount) {
	tickNum--;
	tickCount--;
	Aviasales* newArr = new Aviasales[tickCount];
	for (int i = tickNum; i < tickCount; i++)
	{
		ticketArr[i].dt = ticketArr[i + 1].dt;
		ticketArr[i].isBreak = ticketArr[i + 1].isBreak;
		ticketArr[i].time = ticketArr[i + 1].time;
		ticketArr[i].travelTime = ticketArr[i + 1].travelTime;
		strcpy(ticketArr[i].nameOfAirfield, ticketArr[i + 1].nameOfAirfield);
	}
	for (int i = 0; i < tickCount; i++)
		newArr[i] = ticketArr[i];
	delete[] ticketArr[tickCount].nameOfAirfield;
	delete[] ticketArr;
	ticketArr = newArr;
}
