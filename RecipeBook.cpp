#include <iostream>
#include <string>


using namespace std;
class RecipeBook {
	
	public:
		//public class Recipe pointed to by node
		class Recipe {
			string title;
			string instruct;
			public:
				Recipe (string titl,string inst) {
					title.assign(titl);
					instruct.assign(inst);
				}
				string getTitle () {
					return title;
				}
				string getInst () {
					return instruct;
				}
		};

	private:
		
	//create a Node object which can store pointer to recipe object and pointers to prev and next node
	class Node {
		public:
			Recipe * data;
			Node * next;
			Node * prev;
			//can contain no recipe
			Node () {}
			//can contain recipe pointer
			Node (Recipe rec) {
				data = &rec;
			}
	};

	//declare private head and tail nodes
	Node head;
	Node tail;
	int count;

	public:
		int getCount() {
			return count;
		}
	
		//Head and tail point to each other and null
		RecipeBook () {
			head.next = &tail;
			head.prev = 0;
			tail.prev = &head;
			tail.prev = 0;

			head.data = new Recipe("Start","Inst");
			tail.data = new Recipe("End","Inst");
			count = 0;
		}
		
		Recipe createRecipe(string t, string i) {
			Recipe rec(t,i);
			return rec;
		}
		//add recipe at end of book
		void add (Recipe rec) {
			//pointer to track current position, starting at head
			Node * current = &head;
			//create pointer to new node passing in a recipe object
			Node *newNode = new Node();
			newNode->data = &rec;
			//check if at item before tail, if not go to next
			while (current->next != &tail) {
				current = current->next;
			}
			//set newNode's next to tail
			newNode->next = current->next;
			//set tails previous to newNode
			newNode->next->prev = newNode;
			//set newNode's previous to item before last
			newNode->prev = current;
			//set item before last's next to newNode's address
			current->next = newNode;
			//add one to counter
			count++;
		}

		//returns the recipe object at given index
		Recipe getRecipe (int index) {
			//make sure in bounds of list
			if ((index < count) & (index >=0)) {
				//create pointer to zeroth element
				Node * current = head.next; 
				//go through list and stop on index
				for (int i = 0; i < index; i++) {
					current = current->next;
				}
				//return the recipe object at index
				return *(current->data);
			}
			else if (index >= count)
			{
				//not sure what you want here
				//since we have no recipes
				return *(head.data);
			}
			else {
				//not sure what you want here
				//since we have no recipes
				return *(tail.data);
			}
		}

		//utilizes the getRecipe function to get title of index recipe
		string getTitle(int index) {
			return getRecipe(index).getTitle();
		}
		//utilizes the getRecipe function to get instructions of index recipe
		string getInst(int index) {
			return getRecipe(index).getTitle();
		}

		//checks if two inputs title and instructions match;
		bool compareRec(Recipe one, Recipe two) {
			if ((one.getTitle() == two.getTitle()) & (one.getInst() == two.getInst())) {
				return true;
			}
			else {
				return false;
			}
		}
		
		//removes recipe from list given recipe object
		bool remove (Recipe rec) {
			//go through whole list
			for (int i = 0; i < count; i++) {
				//check if input recipe is identical to another in the list
				if (compareRec(rec, getRecipe(i))) {
					//if so, remove the one in list, reduce count, and return true
					removeByIndex(i);
					return true;
				}
			}
			//otherwise return false
			return false;
		}

		//find Recipe by name
		Recipe getRecipeByName(string titl) {
			Node * current = head.next; 
			//go through each item
			for (int i = 0; i < count; i++) {
				//if title = param return the recipe
				if (current->data->getTitle() == titl) {
					return getRecipe(i);
				}
				current = current->next;
			}
			//not sure what you'd want for alternate return
			//so I'm returning head's recipe to avoid seg fault
			return *(head.data);
		}

		//takes index and removes that recipe if exists returning true. Otherwise return false
		bool removeByIndex (int index) {
			//make sure index in bounds
			if ((index < count) & (index >=0)) {
				Node * current = head.next; 
				//step through list
				for (int i = 0; i < index; i++) {
					current = current->next;
				}
				//set prev element next pointer to item after index
				current->prev->next = current->next;
				//set next element prev pointer to item before index
				current->next->prev = current->prev;
				//decrement count;
				count--;
				//success
				return true;
			}
			//fail
			return false;
		}

};
class RecipeBookTest {

	RecipeBook recipes;
	public:
	RecipeBookTest () {
		recipes.add(recipes.createRecipe("Fettucini","Cook sauce and pasta."));
		recipes.add(recipes.createRecipe("Albondigas","Boil meatballs and veggies."));
		recipes.add(recipes.createRecipe("Buffalo Wings","Catch a buffalo. Cut off their little wings and release them back into the wild. Deep fry the wings."));
		
		cout << recipes.getCount()<< " recipes in book." << endl;
		for (int i = 0; i < recipes.getCount(); i++) {
			cout << recipes.getRecipe(i).getTitle() << endl;
		}
	}
};
	

int main() {

	RecipeBookTest test;
	/*
	RecipeBook recipes;
	RecipeBook::Recipe a("a","taste");
	recipes.add(a);
	//can make Recipe class private and use this instead
	recipes.add(recipes.createRecipe("b","taste"));
	recipes.add(recipes.createRecipe("c","taste"));

	RecipeBook::Recipe d("d","taste");
	recipes.add(d);
	RecipeBook::Recipe e("e","taste");
	recipes.add(e);
	RecipeBook::Recipe f("f","taste");
	recipes.add(f);
	RecipeBook::Recipe g("g","taste");
	recipes.add(g);
	recipes.removeByIndex(4); //remove recipe e
	recipes.remove(f);
	
	for (int j= 0; j < recipes.getCount(); j++) {
		cout << recipes.getRecipe(j).getTitle() << ": " << recipes.getRecipe(j).getInst() << endl;
	}
	*/
	

}
