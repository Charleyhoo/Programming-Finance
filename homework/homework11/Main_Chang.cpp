#include <iostream>
#include <string>
#include "Booklist_Chang.h"
#include "Booklist_Chang.cpp"


int main() {
    bool in_menu = true;
    int user_selection;
    int isbn_select = 0;
    int pos_select;

    // Instantiate object of type BookList.
    BookList mybooks;

    while (in_menu) {
        // Menu print for method selection.
        std::cout << "What would you like to do?" << std::endl;
        std::cout << " 1. add an element to end of list" << std::endl;
        std::cout << " 2. add an element at a location" << std::endl;
        std::cout << " 3. find an element by book name (linear search)" << std::endl;
        std::cout << " 4. find an element by book name (binary search)" << std::endl;
        std::cout << " 5. delete an element at position" << std::endl;
        std::cout << " 6. delete an element by book name" << std::endl;
        std::cout << " 7. sort the list  (using selection sort)" << std::endl;
        std::cout << " 8. sort the list  (using bubble sort)" << std::endl;
        std::cout << " 9. print the list" << std::endl;
        std::cout << " 0. exit" << std::endl;
        std::cout << "\nPlease select a menu option: ";

        // Get user selection and call proper BookList method for operation.
        std::cin >> user_selection;
        switch (user_selection) {
            case 1 : {
                std::cout << "Please type in the element: ";
                std::cin >> isbn_select;
                mybooks.insert(isbn_select);
                break;
            }
            case 2 : {
                std::cout << "Please type in the element:";
                std::cin >> isbn_select;
                std::cout << "At what position? ";
                std::cin >> pos_select;
                mybooks.insert_at(pos_select, isbn_select);
                break;
            }
            case 3 : {
                std::cout << "Select ISBN number to find: ";
                std::cin >> isbn_select;
                pos_select = mybooks.find_book(isbn_select);
                if (pos_select < 0) {
                    std::cout << "No book found for ISBN " << isbn_select << "."
                    << std::endl;
                } else {
                    // Returning user friendly index + 1.
                    std::cout << "ISBN " << isbn_select << " is in position "
                    << pos_select + 1 << "." << std::endl;
                }
                break;
            }
            case 4 : {
                // Check if the list is sorted.
                if (mybooks.get_sorted()) {
                    std::cout << "Select ISBN number to find: ";
                    std::cin >> isbn_select;
                    pos_select = mybooks.find_book_binary(isbn_select);
                    if (pos_select < 0) {
                        std::cout << "No book found for ISBN " << isbn_select << "."
                        << std::endl;
                    } else {
                        // Returning user friendly index + 1.
                        std::cout << "ISBN " << isbn_select << " is in position "
                        << pos_select + 1 << "." << std::endl;
                    }
                } else {
                    std::cout << "Your book list needs to be sorted before using this operation." << std::endl;
                }
                break;
            }
            case 5 : {
                std::cout << "Select a position to delete: ";
                std::cin >> pos_select;
                mybooks.delete_at(pos_select);
                break;
            }
            case 6 : {
                std::cout << "Select an ISBN to delete from your list: ";
                std::cin >> isbn_select;
                mybooks.delete_isbn(isbn_select);
                break;
            }
            case 7 : {
                mybooks.sort_books_selection();
                break;
            }
            case 8 : {
                mybooks.sort_books_bubble();
                break;
            }
            case 9 : {
                mybooks.print_list();
                break;
            }
            case 0 : {
                in_menu = false;
                break;
            }
            default : {
                std::cout << "Invalid menu option." << std::endl;
            }
        }
    }
    return 0;
}
