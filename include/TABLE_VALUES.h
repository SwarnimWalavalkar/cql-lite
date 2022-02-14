#ifndef TABLE_VALUES
#define TABLE_VALUES

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

#endif