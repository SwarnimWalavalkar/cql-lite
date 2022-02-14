#include <stdlib.h>
#include <string.h>
#include "VirtualMachine.h"

#include "Table.h"
#include "Controller.h"

#include "TABLE_VALUES.h"

MetaCommandResult do_meta_command(InputBuffer* input_buffer, Table* table) {
  if(strcmp(input_buffer->buffer, ".exit") == 0) {
    db_close(table);
    exit(EXIT_SUCCESS);
  }else {
    return META_COMMAND_UNRECOGNIZED_COMMAND;
  }
}

ExecuteResult execute_insert(Statement* statement, Table* table) {
  if (table->num_rows >= TABLE_MAX_ROWS) {
    return EXECUTE_TABLE_FULL;
  }

  Row* row_to_insert = &(statement->row_to_insert);

  serialize_row(row_to_insert, row_slot(table, table->num_rows));
  table->num_rows += 1;

  return EXECUTE_SUCCESS;
}

ExecuteResult execute_select(Statement* statement, Table* table) {
  Row row;
  for (uint32_t i = 0; i < table->num_rows; i++) {
    deserialize_row(row_slot(table, i), &row);
    print_row(&row);
  }
  return EXECUTE_SUCCESS;
}

ExecuteResult execute_statement(Statement* statement, Table* table) {
  switch (statement->type) {
  case (STATEMENT_INSERT):
    return execute_insert(statement, table);

  case (STATEMENT_SELECT):
    return execute_select(statement, table);
  }
}