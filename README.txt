*******************************
*                             *
*     Things to remember:     *
*                             *
*******************************
 ✅⚠️ ❌

 A. Requirements for Implementing List and Derivative ADTs

    1. LinkNode Structure/Class:
        - Two attributes:
            - Data attribute (reference/pointer to Currency class of Lab 2)
            - Pointer attribute to the next node
        - Not an inner class or member structure to the SinglyLinkedList class
          
    2. SinglyLinkedList Class:
        - Three private attributes:
            - Count attribute
            - LinkNode pointer/reference attribute named 'start', pointing to the start of the list
            - LinkNode pointer/reference attribute named 'end', pointing to the end of the list
        - Implement the following linked-list behaviors:
            - Getters/setters/constructors/destructors
            - createList method (optional for overloading purposes)
            - destroyList method (optional for overloading purposes)
            - addCurrency method
            - removeCurrency method
            - removeCurrency overload method
            - findCurrency method
            - getCurrency method
            - printList method
            - isListEmpty method
            - countCurrency method
            - Any other useful methods
          
    3. Stack Class (Derived from SinglyLinkedList):
        - No additional attributes
        - Implement usual stack methods:
            - Constructor and createStack method (optional)
            - push method
            - pop method
            - peek method
            - printStack method
            - Destructor and/or destroyStack method (optional)
        - Ensure Stack objects do not allow Linked List functions to be used on them
          
    4. Queue Class (Derived from SinglyLinkedList):
        - No additional attributes
        - Implement usual queue methods:
            - Constructor and createQueue method (optional)
            - enqueue method
            - dequeue method
            - peekFront method
            - peekRear method
            - printQueue method
            - Destructor and/or destroyQueue method (optional)
        - Ensure Queue objects do not allow Linked List functions to be used on them
          
    5. General Guidelines:
        - Ensure minimal and cohesive classes with adequate encapsulation
        - Reuse code and avoid duplication
          
B. Main Driver Program Demonstration:

    1. Welcome message including full name(s)
    2. Create Currency array with 20 Dollar objects
    3. Create SinglyLinkedList, Stack, and Queue objects
    4. Linked List Operations:
        - Add objects to the linked list
        - Search for specific objects
        - Remove nodes
        - Print list contents
    5. Stack Operations:
        - Push objects
        - Peek top
        - Pop objects
        - Print stack contents
    6. Queue Operations:
        - Enqueue objects
        - Peek front and end
        - Dequeue objects
        - Print queue contents
    7. Leaving message and cleanup

