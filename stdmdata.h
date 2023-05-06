#ifndef STDMDATA_H
#define STDMDATA_H

#include "stdm.h"
#include <string.h>

typedef struct arraylist
{
    i32 length;
    i32 nsize;
    void* data;
    i32 actualsize;
} arraylist;

arraylist* arraylist_create(i32 nsize);
void arraylist_resize(arraylist* list, i32 length);
static inline void* arraylist_at(arraylist* list, i32 index) { return (void*)((char*)list->data + (index * list->nsize)); }
static inline void arraylist_set(arraylist* list, i32 index, void* value) { memcpy((char*)list->data + (index * list->nsize), value, list->nsize); }
void arraylist_add(arraylist* list, void* value);
void arraylist_pop(arraylist* list);
void arraylist_delete(arraylist* list, i32 index);
void arraylist_clear(arraylist* list);
void arraylist_free(arraylist* list);

typedef struct arrayqueue
{
    i32 length;
    i32 nsize;
    void* data;
    i32 start;
    i32 end;
    i32 actualsize;
} arrayqueue;

arrayqueue* arrayqueue_create(i32 length, i32 nsize);
void* arrayqueue_at(arrayqueue* queue, i32 index);
void arrayqueue_set(arrayqueue* queue, i32 index);
void* arrayqueue_peek(arrayqueue* queue);
void arrayqueue_enqueue(arrayqueue* queue, void* value);
void* arrayqueue_dequeue(arrayqueue* queue);
void arrayqueue_delete(arrayqueue* queue, i32 index);
void arrayqueue_clear(arrayqueue* queue);
void arrayqueue_free(arrayqueue* queue);

#endif