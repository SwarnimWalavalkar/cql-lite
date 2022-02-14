#include <errno.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>

#include "TABLE_VALUES.h"
#include "Controller.h"
#include "Repl.h"
#include "CommandProcessor.h"
#include "VirtualMachine.h"
#include "Table.h"
#include "Pager.h"


int main(int argc, char* argv[]) {

  uint32_t ID_SIZE = size_of_attribute(Row, id);
  uint32_t AUTHOR_SIZE = size_of_attribute(Row, author);
  uint32_t TITLE_SIZE = size_of_attribute(Row, title);
  uint32_t ID_OFFSET = 0;
  uint32_t AUTHOR_OFFSET = ID_OFFSET + ID_SIZE;
  uint32_t TITLE_OFFSET = AUTHOR_OFFSET + AUTHOR_SIZE;
  uint32_t ROW_SIZE = ID_SIZE + AUTHOR_SIZE + TITLE_SIZE;

  uint32_t PAGE_SIZE = 4096;
  uint32_t ROWS_PER_PAGE = PAGE_SIZE / ROW_SIZE;
  uint32_t TABLE_MAX_ROWS = ROWS_PER_PAGE * TABLE_MAX_PAGES;

  if(argc < 2) {
    printf("Must supply a database filename\n");
    exit(EXIT_FAILURE);
  }

  char* filename = argv[1];
  Table* table = db_open(filename);

  InputBuffer* input_buffer = new_input_buffer();
  while (true) {
    print_prompt();
    read_input(input_buffer);

    if (input_buffer->buffer[0] == '.') {
      switch (do_meta_command(input_buffer, table)) {
      case (META_COMMAND_SUCCESS):
        continue;
      case (META_COMMAND_UNRECOGNIZED_COMMAND):
        printf("Unrecognized command '%s'\n", input_buffer->buffer);
        continue;
      break;
      }
    }

    Statement statement;
    switch (prepare_statement(input_buffer, &statement)){
    case (PREPARE_SUCCESS):
      break;

    case (PREPARE_SYNTAX_ERROR):
      printf("Syntax error. Could not parse statement.\n");
      continue;

    case (PREPARE_UNRECOGNIZED_STATEMENT):
      printf("Unrecognized keyword at start of '%s'.\n", input_buffer->buffer);
      continue;
    }

    switch (execute_statement(&statement, table)) {
    case (EXECUTE_SUCCESS):
      printf("Done!\n");
      break;
    
    case (EXECUTE_TABLE_FULL):
      printf("Error: Table full.\n");
      break;
    }
  }
}