#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

const int max_books = 20; // no more than 20

void insert(int mylist[], int *num_in_list, int new_element)
{
    // Indicate the insert already exists if non-negative
    int shift_index = -1;
    // check if more than 20 books;
    if (*num_in_list > max_books)
    {
        cout << "Cannnot exceed more than 20 books"<< endl;
        return;
    }

    for (int i = 0; i < *num_in_list; i++)
    {
        // remove element, shift list, add item to last, and don't increment if
        // ISBN already exists
        if (mylist[i] == new_element)
        {
            cout << "ISBN value" << new_element << "already exists. Moving to end of lists" << endl;
            shift_index = i;
        }
    }
    if (shift_index >= 0)
    {
        // shift all elements down.
        for (int i = shift_index; i < *num_in_list - 1; i++)
        {
            int *last = mylist + i;
            last = mylist + i + 1;
        }
        // List size did not change so subtract one
        int *last = mylist + *num_in_list - 1;
        *last = new_element;
    }
    else
    {
        int *last = mylist + *num_in_list;
        *num_in_list = *num_in_list + 1;
        *last = new_element;
    }
    return;
};

void insert_at(int mylist[], int *num_in_list, int at_position, int new_element)
{
    int shift_index = -1;
    if (*num_in_list > max_books)
    {
        cout << "Cannot exceed more than" << max_books << "books" << endl;
        return;
    }
    if (*num_in_list < at_position)
    {
        cout << "There's only" << *num_in_list << "books." << endl;
        return;
    }
    else if (at_position < 0)
    {
        cout << "Position selection most be non-negative" << endl;
        return;
    }
    for (int i = 0; i < *num_in_list; i++)
    {
        if (mylist[i] == new_element)
        {
            cout << "ISBN value" << new_element << "already exists. Removing that entry and shifting to new position." << endl;
            shift_index = i;
        }
    }
    if (shift_index >= 0)
    {
        for (int i = shift_index; i < *num_in_list - 1; i++)
        {
            int *last = mylist + i;
            last = mylist + i + 1;
        }
        *num_in_list = *num_in_list - 1;
    }
    for (int i = *num_in_list - 1; i >= at_position; i--)
    {
        cout << i << endl;
        int *last = mylist + i + 1;
        *last = mylist[i];
    }
    int *last = mylist + at_position;
    *last = new_element;
    *num_in_list = *num_in_list + 1;
    return;
}

void delete_item_position(int mylist[], int *num_in_list, int position)
{
    if (*num_in_list < position)
    {
        cout << "Sepecified element does not exist." << endl;
        return;
    }
    else if (position < 0)
    {
        cout << "Positioin selection most be non-negative." << endl;
        return;
    }
    for (int i = position; i < *num_in_list - 1; i++)
    {
        int *last = mylist + i;
        *last = mylist[i + 1];
    }
    *num_in_list = *num_in_list - 1;
    return;
}

void print(int mylist[], int num_in_list)
{
    for (int i = 0; i < num_in_list; i++)
    {
        cout << mylist[i] << endl;
    }
};

int main()
{
    bool homework4 = true;
    int user_selection;
    int books[20];
    int num_books = 0;
    int element_1 = 0;
    int pos_select;

    while (homework4)
    {
        int choice;
        cout << "\n1. add an element to end of list \n";
        cout << "2. add an element at a location \n";
        cout << "3. find an element by ISBN number (linear search)\n";
        cout << "4. find an element by ISBN number (binary search)\n";
        cout << "5. delete an element at position\n";
        cout << "6. delete an element by ISBN number\n";
        cout << "7. sort the list (using selection sort)\n";
        cout << "8. sort the list (using bubble sort)\n";
        cout << "9. print the list\n";
        cout << "10. exit\n";
        cout << "Put your choice: \n";
        cin >> choice;
        switch (choice)
        {

        case 1:
        {
            cout << "Please type in the element \n";
           
            cin >> element_1;
            insert(books, &num_books, element_1);

            break;
        }
        case 2:
        {
            cout << "Select ISBN number to insert:";
            cin >> element_1;
            cout << "Select a position to insert into: ";
            cin >> pos_select;
            insert_at(books, &num_books, pos_select, element_1);

            break;
        }
        case 3:
        {

            break;
        }
        case 4:
        {

            break;
        }
        case 5:
        {
            cout << "Select a position to delete: ";
            cin >> pos_select;
            delete_item_position(books, &num_books, pos_select);

            break;
        }
        case 6:
        {

            break;
        }
        case 7:
        {

            break;
        }
        case 8:
        {

            break;
        }
        case 9:
        {
            print(books, num_books);

            break;
        }
        case 10:
        {
            homework4 = false;

            break;
        }
        default:
        {
            cout << "Invalid menu option." << endl;
        }
        }
    }
    return 0;
}