#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Table.h"

Table* db_open(const char* filename);
void db_close(Table* table);

#endif