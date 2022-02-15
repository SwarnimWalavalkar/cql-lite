#ifndef GLOBALS
#define GLOBALS

#include <stdint.h>
#include "Table.h"

#define size_of_attribute(Struct, Attribute) sizeof(((Struct*)0)->Attribute)

#define TABLE_MAX_PAGES 100

extern const uint32_t ID_SIZE;
extern const uint32_t AUTHOR_SIZE;
extern const uint32_t TITLE_SIZE;
extern const uint32_t ID_OFFSET;
extern const uint32_t PAGE_SIZE;

extern uint32_t AUTHOR_OFFSET(void);
extern uint32_t TITLE_OFFSET(void);
extern uint32_t ROW_SIZE(void);
extern uint32_t ROWS_PER_PAGE(void);
extern uint32_t TABLE_MAX_ROWS(void);

extern const uint32_t NODE_TYPE_SIZE;
extern const uint32_t NODE_TYPE_OFFSET;
extern const uint32_t IS_ROOT_SIZE;
extern const uint32_t IS_ROOT_OFFSET;
extern const uint32_t PARENT_POINTER_SIZE;

extern uint32_t PARENT_POINTER_OFFSET(void);
extern uint8_t COMMON_NODE_HEADER_SIZE(void);

extern const uint32_t LEAF_NODE_NUM_CELLS_SIZE;

extern uint32_t LEAF_NODE_NUM_CELLS_OFFSET(void);
extern uint32_t LEAF_NODE_HEADER_SIZE(void);

const uint32_t LEAF_NODE_KEY_SIZE;
const uint32_t LEAF_NODE_KEY_OFFSET;

uint32_t LEAF_NODE_VALUE_SIZE(void);
uint32_t LEAF_NODE_VALUE_OFFSET(void);
uint32_t LEAF_NODE_CELL_SIZE(void);
uint32_t LEAF_NODE_SPACE_FOR_CELLS(void);
uint32_t LEAF_NODE_MAX_CELLS(void);

#endif