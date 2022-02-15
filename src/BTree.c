#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BTree.h"
#include "Table.h"
#include "Cursor.h"
#include "globals.h"

uint32_t* leaf_node_num_cells(void* node) {
  return node + LEAF_NODE_NUM_CELLS_OFFSET();
}

void* leaf_node_cell(void* node, uint32_t cell_num) {
  return node + LEAF_NODE_HEADER_SIZE() + cell_num * LEAF_NODE_CELL_SIZE();
}

uint32_t* leaf_node_key(void* node, uint32_t cell_num) {
  return leaf_node_cell(node, cell_num);
}

void* leaf_node_value(void* node, uint32_t cell_num) {
  return leaf_node_cell(node, cell_num) + LEAF_NODE_KEY_SIZE;
}

void leaf_node_insert(Cursor* cursor, uint32_t key, Row* value) {
  void* node = get_page(cursor->table->pager, cursor->page_num);

  uint32_t num_cells = *leaf_node_num_cells(node);

  if(num_cells >= LEAF_NODE_MAX_CELLS()) {
    //TODO: IMPLEMENT SPLITTING LEAF NODE
    printf("Splitting not supported");
    exit(EXIT_FAILURE);
  }

  if(cursor->cell_num < num_cells) {
    for (uint32_t i = num_cells; i > cursor->cell_num; i--) {
      memcpy(leaf_node_cell(node, i), leaf_node_cell(node, i-1), LEAF_NODE_CELL_SIZE());
    }
  }

  *(leaf_node_num_cells(node)) += 1;
  *(leaf_node_key(node, cursor->cell_num)) = key;
  serialize_row(value, leaf_node_value(node, cursor->cell_num));
}


void initialize_leaf_node(void* node) { *leaf_node_num_cells(node) = 0; }