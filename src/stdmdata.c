#include "../stdmdata.h"
#include <string.h>

arraylist* arraylist_create(i32 nsize)
{
    arraylist* list = malloc(sizeof(arraylist));
    list->length = 0;
    list->nsize = nsize;
    list->data = NULL;
    list->actualsize = 0;
    return list;
}

void arraylist_resize(arraylist* list, i32 length)
{
    list->actualsize = length * list->nsize;
    list->data = realloc(list->data, list->actualsize);
}

void arraylist_add(arraylist* list, void* value)
{
    ++list->length;
    if (list->actualsize < list->length * list->nsize)
        arraylist_resize(list, list->length);
    arraylist_set(list, list->length - 1, value);
}

void arraylist_pop(arraylist* list)
{
    if (list->length > 0)
        --list->length;
}

void arraylist_clear(arraylist* list)
{
    list->length = 0;
    list->actualsize = 0;
    if (list->data != NULL)
    {
        free(list->data);
        list->data = NULL;
    }
}

void arraylist_delete(arraylist* list, i32 index)
{
    void* temp = alloca(list->nsize);
    for (i32 i = index; i < list->length; ++i)
    {
        memcpy(temp, arraylist_at(list, i + 1), list->nsize);
        arraylist_set(list, i, temp);
    }
    --list->length;
}

void arraylist_free(arraylist* list)
{
    if (list->data != NULL)
        free(list->data);
    free(list);
}

arrayqueue* arrayqueue_create(i32 length, i32 nsize)
{
    arrayqueue* queue = malloc(sizeof(arrayqueue));
    queue->length = length;
    queue->nsize = nsize;
    queue->data = malloc(length * nsize);
    queue->start = 0;
    queue->end = 0;
    queue->actualsize = 0;
    return queue;
}

void* arrayqueue_at(arrayqueue* queue, i32 index)
{
    return NULL;
}

void arrayqueue_set(arrayqueue* queue, i32 index)
{
    return;
}

void* arrayqueue_peek(arrayqueue* queue)
{
    return NULL;
}

void arrayqueue_enqueue(arrayqueue* queue, void* value)
{
    return;
}

void* arrayqueue_dequeue(arrayqueue* queue)
{
    return NULL;
}

void arrayqueue_delete(arrayqueue* queue, i32 index)
{
    return;
}

void arrayqueue_clear(arrayqueue* queue)
{
    return;
}

void arrayqueue_free(arrayqueue* queue)
{
    if (queue->data != NULL)
        free(queue->data);
    free(queue);
}