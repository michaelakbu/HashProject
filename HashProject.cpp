// Author : (Michaelangelo Bullard)

/*     This is a hash table function that:
	A. Create an integer array of size 20. Assigning # to each
	 location in the array indicating that the array is empty.
	B. Populate 18 elements of the array with random integer
	 numbers.
	C. If a collision occurs, linear probing will find the next
	 available position / location.
	D. The generated array will be displayed in 3 lines. First line
	 contain 6 numbers separated by a tab space, Second and
	 the Third lines contain 7 numbers separated by a tab space.
*/



#include<iostream>
#include <ctime>
#include <time.h>


using namespace std;



//class to create hash table
class hashTable
{

	//private variables
private:
	int hash_pos;
	int linearProb;
	int array[20];


	//public functions
public:
	hashTable();
	~hashTable();
	void insert(int data);
	void insert(int data, int n);// function with added display 
	int getlinearProb();
	void search(int data);
	int Hash(int key);
	int reHash(int key);
	void Delete(int data);
	void Display();

};


//constrcutor
hashTable::hashTable()
{
	linearProb = 0;
	hash_pos = 0;

	for (int i = 0; i < 20; i++) {
		array[i] = '#';
	}
}

//deconstrucor
hashTable::~hashTable() {

	for (int i = 0; i < 20; i++) {
		array[i] = '#';
	}
}

//function to input data to the table with no display
void hashTable::insert(int data) {
	int count = 0;

	hash_pos = Hash(data);
	if (hash_pos >= 20) {
		hash_pos = 0;
	}
	while (array[hash_pos] != '#') {
		hash_pos = reHash(hash_pos);
		//linearProb++; //linear prob incrementing 
		count++;
		if (count >= 20) {

			break;
		}
	}
	if (array[hash_pos] == '#') {
		array[hash_pos] = data;
	}




}

//cfunction to insert element in the table with correct display
void hashTable::insert(int data, int n) {
	int count = 0;


	cout << "\nInserting " << data << " in the Table. " << endl;
	hash_pos = Hash(data);
	if (hash_pos >= 20) {
		hash_pos = 0;
	}
	while (array[hash_pos] != '#') {
		hash_pos = reHash(hash_pos);
		linearProb++; //linear prob incrementing 
		count++;
		if (count >= 20) {
			cout << data << " is not inserted. Table is full\n" << endl;
			break;
		}
	}
	if (array[hash_pos] == '#') {
		array[hash_pos] = data;

		cout << data << " is inserted in location\t:\t" << hash_pos << endl;


	}

}
int hashTable::getlinearProb() {
	return linearProb;
}

//function to hash element
int hashTable::Hash(int Generated_Number) {
	return Generated_Number % 20;
}

//function to rehash element if needed
int hashTable::reHash(int Generated_Number) {

	return (Generated_Number + 1) % 20;

}


//functions to search for elements in the hash
void hashTable::search(int data) {

	int count = 1;

	cout << "\nSearching for " << data << " in the Table." << endl;


	//using hashing to search for elements
	hash_pos = Hash(data);
	if (hash_pos >= 20) {
		hash_pos = 0;

	}
	if (array[hash_pos] == data) {

		cout << data << " was found in location\t:\t" << hash_pos << endl;
	}
	while (array[hash_pos] != data) {
		hash_pos = reHash(hash_pos);
		if (array[hash_pos] == data) {

			cout << data << " was found in location\t:\t" << hash_pos << endl;


		}
		count++;
		if (count >= 20) {
			cout << data << " was not found in Table." << endl << endl;
			break;
		}
	}

}

//function to delete elements out of hash
void hashTable::Delete(int data) {

	bool isFound = false;


	int count = 1;

	cout << "\nDeleting " << data << " from the Table." << endl;

	//using hash to find and delete
	hash_pos = Hash(data);
	if (hash_pos >= 20) {
		hash_pos = 0;

	}
	if (array[hash_pos] == data) {
		isFound = true;
		array[hash_pos] = 35;
		cout << data << " is deleted from the Table." << endl << endl;
	}
	while (array[hash_pos] != data) {
		hash_pos = reHash(hash_pos);
		if (array[hash_pos] == data) {
			isFound = true;
			array[hash_pos] = 35;
			cout << data << " is deleted from the Table." << endl << endl;
		}
		count++;
		if (count >= 20) {
			if (isFound == false)
				cout << data << " was not found in Table." << endl << endl;
			break;
		}
	}
}

//functiont to display Hash
void hashTable::Display() {
	for (int i = 0; i < 20; i++) {
		if (array[i] == 35) {
			cout << "#\t";
		}
		else
			cout << array[i] << "\t";

		if (i == 5) {
			cout << endl;

		}
		else if (i == 12) {
			cout << endl;
		}
		else if (i == 19) {
			cout << endl;
		}
	}
}






int main() {

	srand(time(0));

	//variables
	int data = 0;
	hashTable userTable;


	//introduction

	cout << "Welcome to my Hashing Program" << endl;
	cout << "-----------------------------\n\n";

	cout << "A. Create an integer array of size 20. Assigning # to each\n   location in the array indicating that the array is empty." << endl;
	cout << "B. Populate 18 elements of the array with random integer\n   numbers. " << endl;
	cout << "C. If a collision occurs, linear probing will find the next\n   available position / location." << endl;
	cout << "D. The generated array will be displayed in 3 lines.First line" << endl;
	cout << "   contain 6 numbers separated by a tab space, Second and " << endl;
	cout << "   the Third lines contain 7 numbers separated by a tab space." << endl << endl << endl;

	// program starts

	cout << "The Generated Array.  " << endl << endl;
	for (int i = 0; i < 18; i++) {
		data = rand() % (169 - 164 + 1) + 164;
		userTable.insert(data);
	}

	//display
	userTable.Display();

	cout << endl << endl;

	//search
	userTable.search(168);

	userTable.search(172);


	//insert with displays

	userTable.insert(162, 0);

	userTable.insert(163, 0);

	userTable.insert(165, 0);

	//delete
	userTable.Delete(163);

	userTable.Delete(175);

	//display
	cout << "\n\nThe Final Array. " << endl;

	userTable.Display();



	//linear probing reqired
	cout << endl << endl << "The number of linear probes occurred when adding an element in the\nTable is " << userTable.getlinearProb();


	cout << endl << endl << "This Hashing Program was Implemented by\nMichaelangelo Bullard - November 27, 2023" << endl;

	return 0;
}
