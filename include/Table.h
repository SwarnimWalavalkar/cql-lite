#ifndef TABLE_H
#define TABLE_H

#include "Pager.h"

#define COLUMN_TITLE_SIZE 255 
#define COLUMN_AUTHOR_SIZE 32
typedef struct {
  uint32_t id;
  char title[COLUMN_TITLE_SIZE];
  char author[COLUMN_AUTHOR_SIZE];
} Row;

typedef struct {
  uint32_t root_page_num;
  Pager* pager;
} Table;

void print_row(Row* row);
void serialize_row(Row* source, void* destination);
void deserialize_row(void* source, Row* destination);
void* row_slot(Table* table, uint32_t row_num);

#endif