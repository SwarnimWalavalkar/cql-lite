#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "Table.h"
#include "TABLE_VALUES.h"

void print_row(Row* row) {
  printf("(%d, %s, %s)\n", row->id, row->title, row->author);
}

void* row_slot(Table* table, uint32_t row_num) {
  uint32_t page_num = row_num / ROWS_PER_PAGE();

  void* page = get_page(table->pager, page_num);
  uint32_t row_offset = row_num % ROWS_PER_PAGE();
  uint32_t byte_offset = row_offset * ROW_SIZE();
  
  return page + byte_offset;
}

void serialize_row(Row* source, void* destination) {
  memcpy(destination + ID_OFFSET, &(source->id), ID_SIZE);
  memcpy(destination + AUTHOR_OFFSET(), &(source->author), AUTHOR_SIZE);
  memcpy(destination + TITLE_OFFSET(), &(source->title), TITLE_SIZE);
}

void deserialize_row(void* source, Row* destination) {
  memcpy(&(destination->id), source + ID_OFFSET, ID_SIZE);
  memcpy(&(destination->author), source + AUTHOR_OFFSET(), AUTHOR_SIZE);
  memcpy(&(destination->title), source + TITLE_OFFSET(), TITLE_SIZE);
}