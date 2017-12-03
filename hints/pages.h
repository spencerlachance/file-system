#ifndef PAGES_H
#define PAGES_H

#include <stdio.h>

#include "bitmap.h"

typedef struct inode {
    int refs; // reference count
    int mode; // permission & type
    int size; // bytes for file
    void* block; // the data block this logs
    int num_blocks; // the number of data blocks
    char name[48];
} inode;

typedef struct super {
    unsigned char *imap;
    int imap_size;
    unsigned char *dmap;
    int dmap_size;
    int num_inodes;
    int num_blocks;
    inode* inodes;
    void* blocks;
} super;

void   pages_init(const char* path);
void   pages_free();
void*  pages_get_page(int pnum);
inode* pages_get_node(int node_id);
int    pages_find_empty();
void   print_node(pnode* node);
inode* pages_get_node_from_path(const char* path);

#endif
