Assignment 6

Assignment Description. In this assignment, you will design a class to represent a book of recipes using a doubly linked list. Your recipe book will support methods to add a recipe and get a recipe at a position; your main will use these to print all the names of all the recipes in the book.

Create a C++ class called RecipeBook. Your class must implement the following variables, constructors, and methods:
Create a private inner class called Node for implementing doubly-linked list structures. Nodes should have variables for the node’s data, as well as references to the Next and Previous nodes in the list.
RecipeBook needs member variables for the head and tail Nodes in the list, as well as a count of the number of elements in the list.
An accessor method getCount(), to get the number of elements in the list.
A method add, which takes a Recipe object parameter and adds it to the end of the linked list.
A method public: Recipe get(int index), which takes an integer parameter and returns the Recipe object at that index (0-based) in the list.
Additionally, implement these methods:
public: boolean remove(Recipe r)
Takes a Recipe object and removes the node containing that object from the linked list, rearranging links as necessary to maintain the structure of the remaining list. Returns true if the given Recipe object was removed from the list, and false if it was not (meaning it was not found in the list).
public: Recipe searchByName(String recipeName)
Searches for a Recipe in the book with the exact name as given. Returns the ﬁrst Recipe whose name matches the parameter, or null if no such recipe is found.
Deliverables. Submit your .cpp source code ﬁle in a folder named assign6 in your csci133 folder. Make sure your compiled ﬁle name is assign6.


Assignment 7

Assignment Description. Create a second C++ class called RecipeBookTest. This class must do the following in code:

Construct a RecipeBook object.
Add three recipes of your choosing to the book using the add method.
Print out the number of items in the book, using the getCount() method.
Print out the names of the recipes in the book with the following procedure:
For each number i from 0 to getCount(), retrieve the Recipe at that index by calling get with a parameter of i.
Print out the name of the Recipe you retrieved from get.
Deliverables. Submit your .cpp source code ﬁle in a folder named assign7 in your csci133 folder. Make sure your compiled ﬁle name is assign7.
