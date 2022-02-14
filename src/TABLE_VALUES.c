#include "TABLE_VALUES.h"

const uint32_t PAGE_SIZE = 4096;
const uint32_t ID_SIZE = size_of_attribute(Row, id);
const uint32_t AUTHOR_SIZE = size_of_attribute(Row, author);
const uint32_t TITLE_SIZE = size_of_attribute(Row, title);
const uint32_t ID_OFFSET = 0;

uint32_t AUTHOR_OFFSET(void) {return ID_OFFSET + ID_SIZE;}
uint32_t TITLE_OFFSET(void) {return AUTHOR_OFFSET() + AUTHOR_SIZE;}
uint32_t ROW_SIZE(void) {return ID_SIZE + AUTHOR_SIZE + TITLE_SIZE;}

uint32_t ROWS_PER_PAGE(void) {return PAGE_SIZE / ROW_SIZE();}
uint32_t TABLE_MAX_ROWS(void) {return ROWS_PER_PAGE() * TABLE_MAX_PAGES;}