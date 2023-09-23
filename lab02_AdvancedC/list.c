#include "list.h"

/* Add a node to the end of the linked list. Assume head_ptr is non-null. */
//添加一个节点为列表 ，假设头节点不是空节点
void append_node (node** head_ptr, int new_data) {
	/* First lets allocate memory for the new node and initialize its attributes */
	/* YOUR CODE HERE */
	//对于创建一个新的节点，c语言可以使用malloc函数来分配内存
	node *new_node = (node*)malloc(sizeof(node));
	new_node->val = new_data;
	new_node->next = NULL;

	/* If the list is empty, set the new node to be the head and return */
	if (*head_ptr == NULL) {
		/* YOUR CODE HERE */
		*head_ptr = new_node;
		return;
	}
	node* curr = *head_ptr;
	while (curr->next != NULL) {
		curr = curr->next;
	}
	/* Insert node at the end of the list */
	/* YOUR CODE HERE */
	//尾插法
	curr ->next = new_node;
}

/* Reverse a linked list in place (in other words, without creating a new list).
   Assume that head_ptr is non-null. */
void reverse_list (node** head_ptr) {
	node* prev = NULL;
	node* curr = *head_ptr;
	node* next = NULL;
	while (curr != NULL) {
		/* INSERT CODE HERE */
		// prev = curr;
		// curr = curr->next;
		// next = curr->next;
		// curr->next = prev;
		// prev = curr;
		// curr = next;
		// next = next->next;
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	/* Set the new head to be what originally was the last node in the list */
	//*head_ptr = curr;
	head_ptr = prev;
	/* INSERT CODE HERE */
}



