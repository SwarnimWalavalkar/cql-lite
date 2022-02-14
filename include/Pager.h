#ifndef PAGER_H
#define PAGER_H

#include <stdint.h>

typedef struct {
  int file_descriptor;
  uint32_t file_length;
  void* pages[100];
} Pager;

void* get_page(Pager* pager, uint32_t page_num);
Pager* pager_open(const char* filename);
void pager_flush(Pager* pager, uint32_t page_num, uint32_t size);

#endif