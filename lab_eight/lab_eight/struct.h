#pragma once

struct Date
{
	int day, month;
};
struct Time
{
	int hour, minute;
};
struct Aviasales
{
	Date dt;
	Time time;
	char* nameOfAirfield;
	int travelTime;
	bool isBreak;
};