// writing our own malloc in c - youtube vid 2hr
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>


#define HEAP_CAPACITY 640000
#define HEAP_ALLOCED_CAP 1024

typedef struct
{
    void *start;
    size_t size;
} Heap_Chunk;

char heap[HEAP_CAPACITY] = {1};  
Heap_Chunk heap_alloced[HEAP_ALLOCED_CAP];
size_t heap_size = 0;
size_t chunks_alloced_size = 0;



void *heap_alloc(size_t size)
{
    assert(heap_size + size <= HEAP_CAPACITY && "memory overflow");
    assert(chunks_alloced_size + size <= HEAP_ALLOCED_CAP && "too many chunks");


    //void here is like simply saying idc datatype
    void *ptr1 = heap + heap_size; //current free address
    chunks_alloced_size += size;      

    const Heap_Chunk chunk = {
        .start = ptr1,
        .size = size,
    };
 


    assert(chunks_alloced_size <= HEAP_ALLOCED_CAP);

    heap_alloced[chunks_alloced_size] = chunk;
    chunks_alloced_size ++;

    return ptr1;
}


void heap_dump_alloced_chunks(void)
{
    printf("allocated chunks(%zu): \n", chunks_alloced_size);
    for(size_t i = 0; i < chunks_alloced_size; ++i){
        printf("start %p, size %zu \n", heap_alloced[i].start, heap_alloced[i].size);
    }
}


void *heap_free(void *ptr)
{
    (void) ptr;
    assert("TO DO, heap_free not implemented");
}


void heap_collect()
{
    assert("heap_collect not implemented");
}



int main()
{
    char *root = heap_alloc(4);

    for (int i = 0;i<100; ++i){
        printf("%d",root[i]); 
    }
        
    heap_dump_alloced_chunks();
    heap_free(root);
    return 0;
}

