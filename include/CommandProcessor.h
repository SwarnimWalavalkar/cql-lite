#ifndef CMD_PRSR_H
#define CMD_PRSR_H

#include "Repl.h"
#include "Table.h"

typedef enum {PREPARE_SUCCESS, PREPARE_SYNTAX_ERROR,  PREPARE_UNRECOGNIZED_STATEMENT} PrepareResult;
typedef enum {STATEMENT_INSERT, STATEMENT_SELECT} StatementType;

typedef struct {
  StatementType type;
  Row row_to_insert;
} Statement;

PrepareResult prepare_statement(InputBuffer* input_buffer, Statement* statement);

#endif