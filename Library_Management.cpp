// # include<iostream>
// # include<string>
// # include<vector>
// # include<algorithm>
// # include<map>
// using namespace std;

// // Member class
// class Member{
// public:
//     // map<string, string> members;
//     vector<pair<string, string>>members;
//     string member_name;
//     string join_date;
//     Member():members(members), member_name(member_name), join_date(join_date){}

//     // register a new member
//     bool reg_member(string member_name, string join_date){
//         if(!find_member(member_name)){
//             members.push_back({member_name, join_date});
//             // members.insert(member_name, join_date);
//             return true;
//         }
//         return false;
//     }

//     // cancel a membership
//     bool cancel_member(string member_name){
//         if(find_member(member_name)){
//             for(const auto &i : members){
//                 if(i.first == member_name){
//                     members.erase(i);
//                 }
//             }
//             // members.erase(member_name, date);
//             // members.erase(member_name);
//             return true;
//         }
//         return false;
//     }

//     // returns true if member alread exists
//     bool find_member(string member_name){
//         for(auto i : members){
//             if(i.first == member_name) return true;
//         }
//         // if(members.find(member_name) != members.end()) return true;
//         return false;
//     }
// };



// class Book{
// public:
//     vector<vector<string>> book_matrix;
//     string book_name;
//     string date_of_check_out;
//     string date_of_return;
//     map<string, int> book_map;
//     Book():book_matrix(book_matrix), book_name(book_name), date_of_check_out(date_of_check_out), date_of_return(date_of_return), book_map(book_map){}

//     // return true if book exists
//     bool search_book(string book_name){
//         if(book_map.find(book_name) != book_map.end()) return true;
//         return false;
//     }

//     // 
//     bool check_out(string member_name, string book_name){
//         Member member;
//         if(member.find_member(member_name) and search_book(book_name)) return true;
//         return false;
//     }

//     bool find_in_map(string book_name){
//         if(book_map.find(book_name) != book_map.end()){
//             return true;
//         }
//         return false;
//     }

//     bool return_book(string book_name){
//         if(find_in_map(book_name) and !search_book(book_name))return true;
//         return false;
//     }

//     // return the indices of the book location 
//     int find_pos(string book_name){
//         for(int i = 0; i < 5; i++){
//             for(int j = 0; j < 5; j++){
//                 if(book_matrix[i][j] == book_name) return i, j;
//             }
//         }
//         return -1, -1;
//     }
// };



// class Library_management{
// public:
//     Member member;
//     Book book;
//     void run() {
//         while (true) {
//             cout << "\n1.Register Member\n" << "2.Cancel Member\n" << "3.Search Book\n" << "4.Check Out Book\n" << "5.Return Book/n" << "6.Exit" << "Enter menu id : ";
//             int choice;
//             cin >> choice;
//             if (choice == 1) {
//                 string member_name, date_of_join;
//                 cin >> member_name >> date_of_join;
//                 if(member.reg_member(member_name, date_of_join)){
//                         cout << "SUCCESS, Registered " << member_name << endl;
//                 }
//                 else{
//                     cout << "FAILURE, Already registered " << member_name << ", " << date_of_join;
//                 }
//             } 
//             else if (choice == 2) {
//                 string member_name;
//                 cin >> member_name;
//                 if(member.cancel_member(member_name)){
//                     cout << "SUCCESS, Membership cancelled " << member_name;
//                 }
//                 else{
//                     cout << "FAILURE, Not registered member" << member_name;
//                 }
//             } 
//             else if (choice == 3) {
//                 string book_name;
//                 cin >> book_name;
//                 if(book.search_book(book_name)){
//                     int row, col;
//                     row, col = book.find_pos(book_name);
//                     cout << "SUCCESS, Found " << book_name << ", " << row << ", " << col;
//                 }
//                 else{
//                     cout << "FAILURE, " << book_name << "Not found";
//                 }
//             }
//             else if (choice == 4) {
//                 string member_name, book_name;
//                 cin >> member_name >> book_name;
//                 if(book.check_out(member_name, book_name)){
//                     cout << "SUCCESS, " << member_name << " borrowed " << book_name;
//                 }
//                 else if(!member.find_member(member_name)){
//                     cout << "FAILURE, " << member_name << "is not a registered member";
//                 }
//                 else if(book.search(book_name)){
//                     cout << "FAILURE " << book_name << " is already returned";
//                 }
//                 else{
//                     cout << "FAILURE, " << book_name << "is not found";
//                 }
//             }
//             else if (choice == 5) {
//                 string book_name, date_of_return;
//                 cin >> book_name >> date_of_return;
//                 if(book.return_book(book_name, date_of_return)){
//                     cout << "SUCCESS, Returned " << book_name;
//                 }
//                 else if(book.find_in_map(book_name)){
//                     cout << 
//                 }
//             }
//             else if (choice == 6) {
//                 break;
//             } 
//             else {
//                 cout << "Invalid choice. Try again.\n";
//             }
//         }
//     }

// };

// int main(){
//     Library_management library;
//     library.run();
//     return 0;
// }




#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

// Member class
class Member {
public:
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
    vector<vector<string>> book_matrix = vector<vector<string>>(5, vector<string>(5, ""));
    map<string, bool> book_map;

    Book() {
        // List of book names
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

    // Return true if book exists
    bool search_book(const string& book_name) {
        return (book_map.find(book_name) != book_map.end() && book_map[book_name]);
    }

    // Check out a book for a member
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
    Member member;
    Book book;

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
    Library_management library;
    library.run();
    return 0;
}
