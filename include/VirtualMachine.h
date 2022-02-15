#ifndef VM_H
#define VM_H

#include "Repl.h"
#include "Table.h"
#include "CommandProcessor.h"

typedef enum {
  META_COMMAND_SUCCESS,
  META_COMMAND_UNRECOGNIZED_COMMAND
} MetaCommandResult;

typedef enum { EXECUTE_SUCCESS, EXECUTE_TABLE_FULL } ExecuteResult;

MetaCommandResult do_meta_command(InputBuffer* input_buffer, Table* table);
ExecuteResult execute_statement(Statement* statement, Table* table);
ExecuteResult execute_insert(Statement* statement, Table* table);
ExecuteResult execute_select(Statement* statement, Table* table);
void print_constants();
void print_leaf_node(void* node);


#endif