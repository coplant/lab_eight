#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE

#include <windows.h>
#include <cstdio>
#include "struct.h"
#include "free.h"
#include "print.h"
#include "read.h"
#include "sort.h"
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int menu = 0;
	bool isClear = 1;
	int ticketsCount = 0;
	Aviasales* tickets = nullptr;
	while (true)
	{
		printf("\n\n---Выберите желаемое действие--- \n 1. Добавление элемента\n 2. Чтение базы данных из файла\n 3. Вывод базы на экран \n 4. Сортировка базы данных \n 5. Записать данные в файл \n 6. Удаление элемента  \n 7. Выход из программы \n");
		scanf("%d", &menu);
		switch (menu)
		{
		case 1: // Добавление элемента
			printf("\nДобавление элемента:\n--------------------------------\n");
			addTicket(tickets, ticketsCount, readTicket());
			printf("Информация успешно загружена!");
			isClear = 0;
			break;
		case 6: // Удаление элемента
			printf("\nУдаление элемента:\n--------------------------------\n");
			if (isClear)
			{
				printf("База данных пуста!");
			}
			else
			{
				int tickNumber = -1;
				printf("Введите номер билета\n");
				scanf("%d", &tickNumber);
				if (tickNumber > ticketsCount || tickNumber < 1)
				{
					printf("\nВы ввели несуществующий номер!");
				}
				else
				{
					deleteTicket(tickets, tickNumber, ticketsCount);
					printf("База данных успешно обновлена!");
				};
			};
			break;

		case 2: // Чтение из файла
			printf("\nЧтение базы данных:\n--------------------------------\n");
			if (isClear)
			{
				tickets = readFromFile(ticketsCount);
				printf("Информация успешно загружена!");
				isClear = 0;
			}
			else
			{
				freeTicketArr(tickets, ticketsCount);
				tickets = nullptr;
				ticketsCount = 0;
				tickets = readFromFile(ticketsCount);
				printf("Информация успешно загружена!");
				isClear = 0;
			};
			break;
		case 3: // Вывод на экран
			printf("\nВывод базы данных на экран:\n--------------------------------\n");
			if (isClear)
			{
				printf("Вы не выбрали базу данных!");
			}
			else
			{
				printTicketArr(tickets, ticketsCount);
			};
			break;
		case 4: // Сортировка
			printf("\nСортировка базы данных:\n--------------------------------\n");
			if (isClear)
			{
				printf("Вы не выбрали базу данных!");
			}
			else
			{
				sortArr(tickets, ticketsCount);
			};
			break;
		case 5: // Сохранение
			printf("\nЗапись базы данных в файл:\n--------------------------------\n");
			if (isClear)
			{
				printf("Вы не выбрали базу данных!");
			}
			else
			{
				saveDB(tickets, ticketsCount);
				printf("База данных успешно записана в файл!\n");
			};
			break;
		case 7: // Выход
			freeTicketArr(tickets, ticketsCount);
			printf("Вы успешно завершили работу программы.");
			return(0);
			break;
		default:
			printf("Такой функции не существует.");
			break;
		};
	}
	return 0;
}