#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/***********************************************
* Function:  new_stack()
*
* Description:
*  This function creates a placeholder for a new stack pointer element.
*
* Returns:
*  Pointer to a NULL stack.
*
************************************************/
STACK new_stack() 
{
    //  set the pointer to NULL (since no memory has been allocated yet)
    STACK new = NULL;

    //  return the NULL stack pointer to the caller
    return new;
}

/***********************************************
* Function:  push_stack()
*
* Description:
*  This function accepts a pointer to a stack and
*  a value to be added to the end of the stack.  The
*  passed in stack pointer is updated to point to the
*  new end of the stack (last member of the linked list).
*
* Returns:
*  None.
*
************************************************/
void push_stack(STACK *s, SVALUE val) 
{
    //  allocate storage space to hold the passed value in the stack
    STACK new = (STACK) malloc(sizeof(struct stack));

    //  store the passed value in the newly allocated stack space
    new->data = val;

    //  point to the prior member in the stack list
    new->head = *s;

    // set the stack pointer to this new stack element (the new end of the stack list)
    *s = new;
}

/***********************************************
* Function:  pop_stack()
*
* Description:
*  This function removes the last item pushed onto
*  the stack and returns the pushed value of the
*  pushed item to the caller.
*  The last member of the stack list is freed up,
*  so that the stack list is now one element shorter.
*  Note that if we reach the head of the stack list,
*  we return a value of -1.
*
* Returns:
*  Value stored in the last element on the stack.
*
************************************************/
SVALUE pop_stack(STACK *s)
{
    SVALUE val;
    STACK temp;

    //  check to see if we have reached the head of the stack list
    if (*s == NULL) {
      //  reached the head of the list, always return -1
      val = -1;
    }
    else {
      //  grab the stored value from the stack element
      val = (*s)->data;

      //  get the pointer to this last element in the stack list
      temp = (*s);
      //  set the stack pointer to point to the prior element in the list
      *s = (*s)->head;
      //  free the last element in the list
      free(temp);
    }

    //  report the stored stack value to the caller
    return val;
}


/***********************************************
* Function:  print_svalue()
*
* Description:
*  This function prints out the value stored in the stack element
*
* Returns:
*  None.
*
************************************************/
// Printer for svalue
void print_svalue( SVALUE value )
{
    //  print out the value passed to us
    printf( "%d", value );
}

/***********************************************
* Function:  print_stack()
*
* Description:
*  This function prints out the contents of the 
*  data values stored in the stack.
*  The stack is traversed from the last element (tail)
*  until the first element (head) is reached.
*
*  Note that we do not use the pop_stack() function
*  to traverse the stack list as we do not want to
*  change/destroy the stack list, as would happen if
*  we used pop_stack().
*
* Returns:
*  None.
*
************************************************/
// Printer for stack
void print_stack( STACK stack )
{
STACK ptr = stack;  //  start with the passed in stack element

    //  loop until we reach the head of the stack
    while( ptr != NULL )
    {
        //  print out the data value in the current stack element
        printf( "%d\n", ptr->data );

        //  move to the next element in the stack
        ptr = ptr->head;
    }

    //  print -1 to show that we have hit the stack head, and therefore printed the entire stack contents
    printf( "-1\n" );
}
