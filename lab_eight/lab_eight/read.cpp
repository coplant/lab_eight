#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE

#include <conio.h>
#include <cstdio>
#include <cstdlib>
#include "struct.h"
#include "read.h"


char* readCharsBeforeSeparator(FILE* from, char separator) {
	char* str = nullptr;
	char tmpCh = ' ';
	int strlen = 0;
	do
	{
		fscanf(from, "%c", &tmpCh);
		char* tmpStr = new char[strlen + 1];
		for (int i = 0; i < strlen; i++)
		{
			tmpStr[i] = str[i];
		}
		tmpStr[strlen] = tmpCh;
		strlen++;
		delete[] str;
		str = tmpStr;
	} while (tmpCh != separator);

	str[strlen - 1] = '\0';
	return str;
}

char* strFill() {
	int len = 1;
	char* tmpStr = NULL;
	char* resultStr = new char[len];
	while (true)
	{
		resultStr[len - 1] = _getch();
		if (resultStr[len - 1] == '\0')
		{
			continue;
		}
		if (resultStr[len - 1] == 13)
		{
			resultStr[len - 1] = '\0';
			break;
		}
		if (resultStr[len - 1] == '\b')
		{
			printf("%c", resultStr[len - 1]);
			printf("%c", ' ');
			printf("%c", resultStr[len - 1]);
			tmpStr = new char[len - 1];
			for (int i = 0; i < len - 2; i++)
			{
				tmpStr[i] = resultStr[i];
			}
			delete[] resultStr;
			resultStr = tmpStr;
			len--;
		}
		else
		{
			printf("%c", resultStr[len - 1]);
			tmpStr = new char[len + 1];
			for (int i = 0; i < len; i++)
			{
				tmpStr[i] = resultStr[i];
			}
			delete[] resultStr;
			resultStr = tmpStr;
			len++;
		}
	}
	return resultStr;
}

Aviasales* readTicket(FILE* from) {
	Aviasales* read = new Aviasales;
	fscanf(from, "%d.%d;%d:%d;", &read->dt.day, &read->dt.month, &read->time.hour, &read->time.minute);
	read->nameOfAirfield = readCharsBeforeSeparator(from, ';');
	fscanf(from, "%d;\n", &read->travelTime);
	if (read->travelTime > 4)
		read->isBreak = 1;
	else
		read->isBreak = 0;

	return read;
}

Aviasales* readTicket() {
	Aviasales* read = new Aviasales;
	printf("Введите дату в формате XX.XX\n");
	scanf("%d.%d", &read->dt.day, &read->dt.month);
	printf("Введите время в формате XX:XX\n");
	scanf("%d:%d", &read->time.hour, &read->time.minute);
	printf("Введите название аэропорта\n");
	read->nameOfAirfield = strFill();
	printf("\nВведите время в пути\n");
	scanf("%d", &read->travelTime);
	printf("\n");
	if (read->travelTime > 4)
		read->isBreak = 1;
	else
		read->isBreak = 0;
	return read;
}

Aviasales* readFromFile(int& size) {
	FILE* file;
	if ((file = fopen("D:\\database.txt", "r")) == NULL)
	{
		printf("Файл не найден!\n");
		exit(0);
	}
	if (getc(file) == EOF)
	{
		printf("Файл пуст!");
		exit(0);
	}

	Aviasales* readTickets = nullptr;
	fclose(file);
	file = fopen("D:\\database.txt", "r");
	while (!feof(file))
	{
		addTicket(readTickets, size, readTicket(file));
	}
	fclose(file);

	return readTickets;
}

void addTicket(Aviasales*& ticketArr, int& tickCount, Aviasales* toAdd) {
	Aviasales* newArr = new Aviasales[tickCount + 1];
	for (int i = 0; i < tickCount; i++)
	{
		newArr[i] = ticketArr[i];
	}
	newArr[tickCount] = *toAdd;
	tickCount++;
	delete[] ticketArr;
	ticketArr = newArr;
}

