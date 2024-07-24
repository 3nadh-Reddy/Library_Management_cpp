// include headers
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

// Member class
class Member {
public:
    // vector pair to store member_name and join_date respectively
    vector<pair<string, string>> members;

    // Register a new member
    bool reg_member(const string& member_name, const string& join_date) {
        if (!find_member(member_name)) {
            members.push_back({member_name, join_date});
            return true;
        }
        return false;
    }

    // Cancel a membership
    bool cancel_member(const string& member_name) {
        for (auto it = members.begin(); it != members.end(); ++it) {
            if (it->first == member_name) {
                members.erase(it);
                return true;
            }
        }
        return false;
    }

    // Returns true if member already exists
    bool find_member(const string& member_name) {
        for (auto& i : members) {
            if (i.first == member_name) return true;
        }
        return false;
    }

    // Find the date of joining for a member
    string find_date_of_join(const string& member_name){
        for(auto& member : members){
            if(member.first == member_name) return member.second;
        }
        return "";
    }
};

// Book class
class Book {
public:
    // Initialization of book self as a matrix(considering 5 rows and 5 columns)
    vector<vector<string>> book_matrix = vector<vector<string>>(5, vector<string>(5, ""));
    // maintaning a map for checking availability of books
    map<string, bool> book_map;

    // Default Constructor
    Book() {
        // List of book names(Initialization)
        vector<string> book_names = {"TheStranger", "CrimeandPunishment", "Meditations", "Metamorphosis", "TheIdiot", 
                                     "BrothersKaramazov", "TheWingsofFire", "BeyondGoodandEvil", "ThusSpokeZarathustra", "TheRepublic",
                                     "Dune", "HarryPotter", "TheHamlet", "Frankenstein", "NormalPeople",
                                     "TheSecret", "TheMagic", "GATE", "JEE", "CAT",
                                     "Math", "Electrical", "Mechanical", "ComputerScience", "Newspapers"};
        
        // Initialize book_map with book names and set availability to true
        for (const auto& book_name : book_names) {
            book_map[book_name] = true;
        }

        // Initialize book_matrix with book names
        int k = 0;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                book_matrix[i][j] = book_names[k++];
            }
        }
    }

    // Return true if book exists, false if not present or book already checked out
    bool search_book(const string& book_name) {
        return (book_map.find(book_name) != book_map.end() && book_map[book_name]);
    }

    // Check out (i.e member borrows) a book for a member
    bool check_out(Member& member, const string& member_name, const string& book_name) {
        if (member.find_member(member_name) && search_book(book_name) && book_map[book_name]) {
            book_map[book_name] = false; // Mark book as checked out
            return true;
        }
        return false;
    }

    // Return a book
    bool return_book(const string& book_name) {
        if (book_map.find(book_name) != book_map.end() && !book_map[book_name]) {
            book_map[book_name] = true; // Mark book as returned
            return true;
        }
        return false;
    }

    // Return the indices of the book location
    pair<int, int> find_position(const string& book_name) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (book_matrix[i][j] == book_name) return {i+1, j+1};
            }
        }
        return {-1, -1};
    }
};

// Library_management class
class Library_management {
public:
    // Creating objects for Member and Book classes
    Member member;
    Book book;

    // Input format no spaces for a given variable's value(i.e; Instead of "The Republic", input "TheRepublic" to avoid infinite loop)
    void run() {
        cout << "**** Welcome to the Library Management System ****\n";
        while (true) {
            cout << "Available menu\n1. Register Member\n2. Cancel Member\n3. Search Book\n4. Check Out Book\n5. Return Book\n6. Exit\nEnter menu id: ";
            int choice;
            cin >> choice;
            if (choice == 1) {
                string member_name, date_of_join;
                cout << "Enter member name and date of join: ";
                cin >> member_name >> date_of_join;
                if (member.reg_member(member_name, date_of_join)) cout << "SUCCESS, Registered " << member_name << endl;
                else cout << "FAILURE, Already registered " << member_name << ", " << member.find_date_of_join(member_name) << endl;
            } 
            else if (choice == 2) {
                string member_name;
                cout << "Enter member name: ";
                cin >> member_name;
                if (member.cancel_member(member_name)) cout << "SUCCESS, Membership cancelled " << member_name << endl;
                else cout << "FAILURE, Not registered member " << member_name << endl;
            } 
            else if (choice == 3) {
                string book_name;
                cout << "Enter book name: ";
                cin >> book_name;
                if (book.search_book(book_name)) {
                    auto pos = book.find_position(book_name);
                    cout << "SUCCESS, Found " << book_name << " at (row : " << pos.first << ", col : " << pos.second << ")\n";
                } 
                else cout << "FAILURE, " << book_name << " Not found\n";
            }
            else if (choice == 4) {
                string member_name, book_name;
                cout << "Enter member name and book name: ";
                cin >> member_name >> book_name;
                if (book.check_out(member, member_name, book_name)) cout << "SUCCESS, " << member_name << " borrowed " << book_name << endl;
                else if (!member.find_member(member_name)) cout << "FAILURE, " << member_name << " is not a registered member\n";
                else if (!book.search_book(book_name)) cout << "FAILURE, " << book_name << " is not found\n";
                else cout << "FAILURE, " << book_name << " is already checked out\n";
            } 
            else if (choice == 5) {
                string book_name;
                cout << "Enter book name: ";
                cin >> book_name;
                if (book.return_book(book_name)) cout << "SUCCESS, Returned " << book_name << endl;
                else{
                    if(book.search_book(book_name)) cout << book_name << " is already returned" << endl;
                    else cout << book_name << " is not from this library" << endl;
                }
            } 
            else if (choice == 6) break;
            else cout << "Invalid choice. Try again.\n";
        }
    }
};

int main() {
    // Create ann object for Library_management
    Library_management library;
    library.run();
    return 0;
}
