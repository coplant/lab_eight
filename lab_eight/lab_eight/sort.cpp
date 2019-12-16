#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE


#include <iostream>
#include <cstring>
#include "struct.h"
#include "sort.h"
#include "print.h"


void swap(Aviasales* left, Aviasales* right) {
	Aviasales _temp;
	_temp = *left;
	*left = *right;
	*right = _temp;
}

bool needToSwap(Aviasales* left, Aviasales* right, int choice) {
	if (choice == 3) {
		return strcmp(left->nameOfAirfield, right->nameOfAirfield) < 0;
	}
	else if (choice == 2) {
		if (left->time.hour == right->time.hour)
			return (left->time.minute < right->time.minute);
		else
			return (left->time.hour < right->time.hour);
	}
	else if (choice == 1) {
		if (left->dt.month == right->dt.month)
			return (left->dt.day < right->dt.day);
		else
			return (left->dt.month < right->dt.month);
	}
	else if (choice == 4) {
		return (left->travelTime < right->travelTime);
	}
	else if (choice == 5) {
		return (left->isBreak > right->isBreak);
	}
}

void sortArr(Aviasales* ticketArr, int arrSize) {
	printf("�������� ���� ��� ����������: \n1 - ����\n2 - �����\n3 - �������� ���������\n4 - ����� � ����\n5 - ������� ��������\n6 - ��������� �����\n\n");
	int choice = 0;
	scanf("%d", &choice);
	if (choice == 6)
	{
		return;
	}
	else
	{
		for (int i = 0; i < arrSize; i++)
		{
			for (int j = arrSize - 1; j > i; j--)
			{
				if (needToSwap(&ticketArr[j], &ticketArr[j - 1], choice))
				{
					swap(&ticketArr[j], &ticketArr[j - 1]);
				}
			}
		}
		printf("\n���� ������ ������� ��������������!\n");
		printTicketArr(ticketArr, arrSize);
	};
}

