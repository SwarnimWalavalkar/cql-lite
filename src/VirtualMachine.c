#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "VirtualMachine.h"

#include "Table.h"
#include "Cursor.h"
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
  if (table->num_rows >= TABLE_MAX_ROWS()) {
    return EXECUTE_TABLE_FULL;
  }

  Row* row_to_insert = &(statement->row_to_insert);
  Cursor* cursor = table_end(table);

  serialize_row(row_to_insert, cursor_value(cursor));
  table->num_rows += 1;

  return EXECUTE_SUCCESS;
}

ExecuteResult execute_select(Statement* statement, Table* table) {
  Cursor* cursor = table_start(table);
  Row row;
  while (!(cursor->end_of_table)) {
    deserialize_row(cursor_value(cursor), &row);
    print_row(&row);
    cursor_advance(cursor);
  }
  free(cursor);

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