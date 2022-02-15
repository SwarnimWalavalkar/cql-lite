#ifndef CURSOR_H
#define CURSOR_H

#include <stdint.h>
#include <stdbool.h>
#include "Table.h"

typedef struct {
  Table* table;
  uint32_t page_num;
  uint32_t cell_num;
  bool end_of_table;
} Cursor;

Cursor* table_start (Table* table);
Cursor* table_end (Table* table);
void* cursor_value(Cursor* cursor);
void cursor_advance(Cursor* cursor);

#endif