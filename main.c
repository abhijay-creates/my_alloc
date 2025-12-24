// writing our own malloc in c - youtube vid 2hr
#include<stdio.h>
#include<assert.h>

//fragmentation can happen. thats why malloc is very bad

#define HEAP_CAPACITY 640000
#define HEAP_ALLOCED_CAP 1024

typedef struct
{
    void *start;
    size_t size;
} Heap_Chunk;

char heap[HEAP_CAPACITY] = {0};  
Heap_Chunk heap_alloced[HEAP_ALLOCED_CAP];
size_t heap_size = 0;





void *heap_alloc(size_t size)
{
    assert(heap_size + size <= HEAP_CAPACITY && "memory overflow");

    //void here is like simply saying idc datatype
    void *ptr1 = heap + heap_size;
    heap_size += size;
    return ptr1;

    const Heap_Chunk chunk = {
        .start = result,
        .size = size,
    };

    assert(heap_alloced_size <= HEAP_ALLOCED_CAP);
    heap_alloced[heap_alloced_size++] = chunk;


    return ptr1;
}


void *heap_free(void *ptr)
{
    (void) ptr;
    
    //assert just double checks that if something youre trying to do
    //and if actually that much memory required is there, then ok or
    //else abort 
    assert("TO DO, heap_free not implemented");
}


void heap_collect()
{
    assert("heap_collect not implemented");
}



int main()
{
    char *root = heap_alloc(0);
    for (int i =0; i<26 ; ++i){
        root[i] = i + 'A';
    }
    heap_free(root);
}




//1
//implement heap allocator,
//implement heap deallocator
//implement 