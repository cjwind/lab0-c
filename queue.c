/*
 * Code for basic C skills diagnostic.
 * Developed for courses 15-213/18-213/15-513 by R. E. Bryant, 2017
 * Modified to store strings, 2018
 */

/*
 * This program implements a queue supporting both FIFO and LIFO
 * operations.
 *
 * It uses a singly-linked list to represent the set of queue elements
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "harness.h"
#include "queue.h"

/*
  Create empty queue.
  Return NULL if could not allocate space.
*/
queue_t *q_new()
{
    queue_t *q = malloc(sizeof(queue_t));

    if (q == NULL) {
        return NULL;
    }

    q->head = q->tail = NULL;
    q->size = 0;

    return q;
}

/* Free all storage used by queue */
void q_free(queue_t *q)
{
    if (q == NULL) {
        return;
    }

    list_ele_t *p = NULL, *r = NULL;

    r = q->head;
    p = (q->head != NULL) ? q->head->next : NULL;

    while (r) {
        if (r->value != NULL) {
            free(r->value);
        }
        free(r);

        r = p;
        if (p != NULL) {
            p = p->next;
        }
    }

    /* Free queue structure */
    free(q);
}

/*
  Attempt to insert element at head of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
  Argument s points to the string to be stored.
  The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_head(queue_t *q, char *s)
{
    if (q == NULL) {
        return false;
    }

    list_ele_t *newh = malloc(sizeof(list_ele_t));
    if (newh == NULL) {
        return false;
    }

    newh->value = malloc(strlen(s) + sizeof(char));
    if (newh->value == NULL) {
        free(newh);
        return false;
    }

    strcpy(newh->value, s);

    newh->next = q->head;

    if (q->tail == NULL) {
        q->tail = newh;
    }

    q->head = newh;
    q->size++;
    return true;
}


/*
  Attempt to insert element at tail of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
  Argument s points to the string to be stored.
  The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_tail(queue_t *q, char *s)
{
    if (q == NULL) {
        return false;
    }

    list_ele_t *newEle = malloc(sizeof(list_ele_t));
    if (newEle == NULL) {
        return false;
    }

    newEle->next = NULL;
    newEle->value = malloc(strlen(s) + sizeof(char));
    if (newEle->value == NULL) {
        free(newEle);
        return false;
    }

    strcpy(newEle->value, s);

    if (q->head == NULL) {
        q->head = newEle;
    }

    if (q->tail != NULL) {
        q->tail->next = newEle;
    }

    q->tail = newEle;
    q->size++;

    return true;
}

/*
  Attempt to remove element from head of queue.
  Return true if successful.
  Return false if queue is NULL or empty.
  If sp is non-NULL and an element is removed, copy the removed string to *sp
  (up to a maximum of bufsize-1 characters, plus a null terminator.)
  The space used by the list element and the string should be freed.
*/
bool q_remove_head(queue_t *q, char *sp, size_t bufsize)
{
    if (q == NULL || q->head == NULL) {
        return false;
    }

    if (sp != NULL && q->head->value != NULL) {
        strncpy(sp, q->head->value, bufsize - 1);
        sp[bufsize - 1] = '\0';
    }

    list_ele_t *head = q->head;

    q->head = q->head->next;

    if (q->head == NULL) {
        q->tail = NULL;
    }

    free(head->value);
    free(head);

    q->size--;

    return true;
}

/*
  Return number of elements in queue.
  Return 0 if q is NULL or empty
 */
int q_size(queue_t *q)
{
    if (q == NULL || q->head == NULL) {
        return 0;
    }

    return q->size;
}

/*
  Reverse elements in queue
  No effect if q is NULL or empty
  This function should not allocate or free any list elements
  (e.g., by calling q_insert_head, q_insert_tail, or q_remove_head).
  It should rearrange the existing ones.
 */
void q_reverse(queue_t *q)
{
    /* You need to write the code for this function */
}
