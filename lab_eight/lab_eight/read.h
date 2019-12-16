#pragma once
char* readCharsBeforeSeparator(FILE*, char);
char* strFill();
Aviasales* readTicket(FILE*);
Aviasales* readTicket();
Aviasales* readFromFile(int&);
void addTicket(Aviasales*&, int&, Aviasales*);