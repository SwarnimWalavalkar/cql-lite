#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "Table.h"
#include "globals.h"

void print_row(Row* row) {
  printf("(%d, %s, %s)\n", row->id, row->title, row->author);
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