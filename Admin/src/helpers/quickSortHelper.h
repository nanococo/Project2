// C++ program for Quick Sort on Singly Linked List
#pragma once
#include <iostream>
#include <cstdio>
#include <utility>
using namespace std;

/* a node of the singly linked list */
struct Node
{
    string aisleCode;
    string prodCode;
    string brandCode;
    int amount;
    struct Node *next;
};

void deleteList(Node** head_ref)
{

/* deref head_ref to get the real head */
    Node* current = *head_ref;
    Node* next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }

/* deref head_ref to affect the real head back
    in the caller. */
    *head_ref = NULL;
}

/* A utility function to insert a node at the beginning of linked list */
void push(struct Node** head_ref, int new_data, string newAisleCode, string newProdCode, string newBrandCode)
{
    /* allocate node */
    struct Node* new_node = new Node;

    /* put in the data  */
    new_node->amount  = new_data;
    new_node->aisleCode = std::move(newAisleCode);
    new_node->prodCode = std::move(newProdCode);
    new_node->brandCode = std::move(newBrandCode);

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref) = new_node;
}

/* A utility function to print linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        //printf("%d  ", node->amount);
        cout << "[" << node->aisleCode << ", " << node->prodCode << ", " << node->brandCode << ", " << node->amount << "]" << endl;
        node = node->next;
    }
    printf("\n");
}

// Returns the last node of the list 
struct Node *getTail(struct Node *cur)
{
    while (cur != NULL && cur->next != NULL)
        cur = cur->next;
    return cur;
}

// Partitions the list taking the last element as the pivot 
struct Node *partition(struct Node *head, struct Node *end,
                       struct Node **newHead, struct Node **newEnd)
{
    struct Node *pivot = end;
    struct Node *prev = NULL, *cur = head, *tail = pivot;

    // During partition, both the head and end of the list might change 
    // which is updated in the newHead and newEnd variables 
    while (cur != pivot)
    {
        if (cur->amount < pivot->amount)
        {
            // First node that has a value less than the pivot - becomes 
            // the new head 
            if ((*newHead) == NULL)
                (*newHead) = cur;

            prev = cur;
            cur = cur->next;
        }
        else // If cur node is greater than pivot 
        {
            // Move cur node to next of tail, and change tail 
            if (prev)
                prev->next = cur->next;
            struct Node *tmp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }

    // If the pivot data is the smallest element in the current list, 
    // pivot becomes the head 
    if ((*newHead) == NULL)
        (*newHead) = pivot;

    // Update newEnd to the current last node 
    (*newEnd) = tail;

    // Return the pivot node 
    return pivot;
}


//here the sorting happens exclusive of the end node 
struct Node *quickSortRecur(struct Node *head, struct Node *end)
{
    // base condition 
    if (!head || head == end)
        return head;

    Node *newHead = NULL, *newEnd = NULL;

    // Partition the list, newHead and newEnd will be updated 
    // by the partition function 
    struct Node *pivot = partition(head, end, &newHead, &newEnd);

    // If pivot is the smallest element - no need to recur for 
    // the left part. 
    if (newHead != pivot)
    {
        // Set the node before the pivot node as NULL 
        struct Node *tmp = newHead;
        while (tmp->next != pivot)
            tmp = tmp->next;
        tmp->next = NULL;

        // Recur for the list before pivot 
        newHead = quickSortRecur(newHead, tmp);

        // Change next of last node of the left half to pivot 
        tmp = getTail(newHead);
        tmp->next =  pivot;
    }

    // Recur for the list after the pivot element 
    pivot->next = quickSortRecur(pivot->next, newEnd);

    return newHead;
}

// The main function for quick sort. This is a wrapper over recursive 
// function quickSortRecur() 
void quickSort(struct Node **headRef)
{
    (*headRef) = quickSortRecur(*headRef, getTail(*headRef));
    return;
}
