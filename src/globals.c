#include "globals.h"

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

const uint32_t NODE_TYPE_SIZE = sizeof(uint8_t);
const uint32_t NODE_TYPE_OFFSET = 0;
const uint32_t IS_ROOT_SIZE = sizeof(uint8_t);
const uint32_t IS_ROOT_OFFSET = NODE_TYPE_SIZE;
const uint32_t PARENT_POINTER_SIZE = sizeof(uint32_t);

uint32_t PARENT_POINTER_OFFSET(void) {return IS_ROOT_OFFSET + IS_ROOT_SIZE;}
uint8_t COMMON_NODE_HEADER_SIZE(void) {return NODE_TYPE_SIZE + IS_ROOT_SIZE + PARENT_POINTER_SIZE;}

const uint32_t LEAF_NODE_NUM_CELLS_SIZE = sizeof(uint32_t);

uint32_t LEAF_NODE_NUM_CELLS_OFFSET(void) {return COMMON_NODE_HEADER_SIZE();}
uint32_t LEAF_NODE_HEADER_SIZE(void) {return COMMON_NODE_HEADER_SIZE() + LEAF_NODE_NUM_CELLS_SIZE;}

const uint32_t LEAF_NODE_KEY_SIZE = sizeof(uint32_t);
const uint32_t LEAF_NODE_KEY_OFFSET = 0;

uint32_t LEAF_NODE_VALUE_SIZE(void) {return ROW_SIZE();}
uint32_t LEAF_NODE_VALUE_OFFSET(void) {return LEAF_NODE_KEY_OFFSET + LEAF_NODE_KEY_SIZE;}
uint32_t LEAF_NODE_CELL_SIZE(void) {return LEAF_NODE_KEY_SIZE + LEAF_NODE_VALUE_SIZE();}
uint32_t LEAF_NODE_SPACE_FOR_CELLS(void) {return PAGE_SIZE - LEAF_NODE_HEADER_SIZE();}
uint32_t LEAF_NODE_MAX_CELLS(void) {return LEAF_NODE_SPACE_FOR_CELLS() / LEAF_NODE_CELL_SIZE();}
