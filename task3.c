// void* - вказівник на невизначений тип

#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include <stddef.h>

typedef struct Block {
    size_t size;
    struct Block* next;
    int free;
} Block;

#define MEM_SIZE 256 * 256
#define BLOCK_SIZE sizeof(Block)

char memory[MEM_SIZE];
Block* mem_list = (Block*)memory;

void init_memory() {
    mem_list->size = MEM_SIZE - BLOCK_SIZE;
    mem_list->next = NULL;
    mem_list->free = 1;
}

void* my_malloc(size_t size) {
    Block* curr = mem_list;
    while (curr) {
        if (curr->free && curr->size >= size) {
            if (curr->size >= size + BLOCK_SIZE) {
                Block* temp = (Block*)((char*)curr + BLOCK_SIZE + size);
                temp->size = curr->size - size - BLOCK_SIZE;
                temp->next = curr->next;
                temp->free = 1;
                curr->next = temp;
                curr->size = size;
            }
            curr->free = 0;
            return (char*)curr + BLOCK_SIZE;
        }
        curr = curr->next;
    }
    return NULL;
}

void my_free(void* ptr) {
    if (!ptr) return;
    Block* block = (Block*)((char*)ptr - BLOCK_SIZE);
    block->free = 1;
}

void print_memory() {
    Block* curr = mem_list;
    while (curr) {
        printf("Розташування %p: Розмір=%lu, Статус=%d\n", (void*)curr, curr->size, curr->free);
        curr = curr->next;
    }
}

int main() {
    init_memory();
    
    void* a = my_malloc(256);
    void* b = my_malloc(128);
    print_memory();
    
    my_free(a);
    print_memory();
    
    return 0;
}
