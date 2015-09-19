#include <assert.h>
#include <stdlib.h>

#include "list.h"

// Takes a valid, sorted list starting at `head` and adds the element
// `new_element` to the list. The list is sorted based on the value of the
// `index` member in ascending order. Returns a pointer to the head of the list
// after the insertion of the new element.
list_t* insert_sorted(list_t* head, list_t* new_element) {
	assert(head != NULL);
	assert(new_element != NULL);

	//edge case: new_element goes in first
	if(new_element->index <= head->index)
	{
		new_element->next = head;
		return new_element;
	}
	list_t* prev_element = head;
	list_t* next_element = head;
	while(next_element != NULL && (next_element->index < new_element->index))
	{
		prev_element = next_element;
		next_element = next_element->next;
	}
	//check end condition
	if(next_element== NULL)//means that every element in the list is less than the new_element
	{
		prev_element->next = new_element;
	}
	else//this means that next_element's index is greater than new_elements
	{
		prev_element->next = new_element;
		new_element->next = next_element;
	}

	return head;
}

// Reverses the order of the list starting at `head` and returns a pointer to
// the resulting list. You do not need to preserve the original list.
list_t* reverse(list_t* head) {
	assert(head != NULL);

	list_t* next_element = head->next;
	head->next = NULL;
	list_t* temp;
	//next_element will point to the next unreversed node
	//ie 
	//		node <-  node <- node  node -> node -> null
	//				  		   ^    ^
	//				  	   	   |    |
	//						  next  head
	
	while(next_element != NULL)
	{
		temp = next_element->next;
		next_element->next = head;
		head = next_element;
		next_element = temp;
	}

	return head;
}

