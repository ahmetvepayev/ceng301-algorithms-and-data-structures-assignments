# These are my assignments completed as a part of the course CENG301 Algorithms and Data Structures given in METU (Middle East Technical University) Fall 2021

## Assignment 1 - Pointers

+ The main function first manipulates a pair of integers with a series of function calls and using pointers. The pair before the manipulations and the pair obtained after the manipulations represent two different point coordinates in the X-Y plane. The function also takes two integer values from the user as radii of two circles. The circles use the points generated beforehand as their center. Finally there is a function call to check if the two circles intersect.
+ Second part of the assignment is to determine the output of the following piece of code and to explain the reason for the output :

    ![Imgur](https://i.imgur.com/UKahypV.png)


## Assignment 2 - Linked Lists

The assignment consists of simulating a part of the management application for a logistics company with a simple system :

+ The company uses trucks for shipments and there is only one type of cargo called "Item".
+ Each truck has a maximum weight of items and a maximum number of items it can hold.
+ Each truck also has a 'fullness' threshold value for total item weight indicating that the truck is ready for departure.
+ The user can manage the system via console commands and keep track of the system by using commands that generate current status reports.

The code implementation of the system is as follows :

+ Truck and Item are two separate classes. Item class is responsible for only its own members' mechanisms. Truck class is reponsible for its own members' mechanisms as well as keeping track of the Item instances assigned to the particular Truck instance. The console commands are also implemented as static methods of the Truck class.
+ The trucks are stored as a doubly linked list where each truck is a node in the linked list. The system keeps track of the head and tail of the linked list and also the total number of trucks.
+ The items are stored as singly linked lists where each item is a node in the linked list. The truck holding the items keeps track of the total weight and number of items in that truck.
+ Each truck and item has a position value that indicates its position in the related linked list. The position index starts from 1 for both trucks and items.
+ Adding an item to the system places it in the first available truck. The truck with available space that is closest to the head of the doubly linked list will always take the item. If none of the existing trucks can accommodate the item or if there are no existing trucks in the system, a new Truck instance is created, added to the end of the doubly linked list and finally the item is placed in that truck.
+ If a single item's weight exceeds the maximum weight a truck can carry, the item is rejected.

The console commands are as follows :

| Command | Description |
|---------|-------------|
| ai (itemWeight) | Add an item with the given weight. |
| ri (truckPosition) (itemPosition) | Remove the item at position (itemPosition) in the truck at position (truckPosition). |
| depart | Remove trucks from the system which have reached their maximum item number or have passed the 'fullness' threshold. |
| rs | Generate a summary report of the current trucks in the system. |
| rd | Generate a detailed report of all the trucks and items in the system. |
| q | Quit. |


## Assignment 3 - Stack & Queues

The program asks the user to input a consecutive series of brackets and it checks if the brackets are enclosed. The program uses an implementation of a stack which uses two queues.

Examples

+ Enclosed :

        (([[{}]]))

+ Non-enclosed :

        ({([]))
        [([][])]
        {([(]))}


## Assignment 4 - Trees

A library uses a system where it stores book information in a binary search tree. Anyone wanting to access a particular book, has to traverse the tree and find the id of the book. Visitors of this particular library like to search for books in pairs, so the job of this program is to take the id of the two books and return the root id of the smallest subtree that contains both the books.

The program first asks for the book ids to enter into the system, then asks for the ids of the books a visitor is requesting and finally returns the id of the node which serves as the root of the smallest subtree containing the requested pair.