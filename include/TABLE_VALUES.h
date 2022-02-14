#ifndef TABLE_VALUES
#define TABLE_VALUES

#include <stdint.h>
#include "Table.h"

#define size_of_attribute(Struct, Attribute) sizeof(((Struct*)0)->Attribute)

const uint32_t ID_SIZE;
const uint32_t AUTHOR_SIZE;
const uint32_t TITLE_SIZE;
const uint32_t ID_OFFSET;
const uint32_t AUTHOR_OFFSET;
const uint32_t TITLE_OFFSET;
const uint32_t ROW_SIZE;

const uint32_t PAGE_SIZE;
#define TABLE_MAX_PAGES 100
const uint32_t ROWS_PER_PAGE;
const uint32_t TABLE_MAX_ROWS;

#endif