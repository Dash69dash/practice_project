#include <iostream>
#include <string>
#include <set>
#include <map>
using namespace std;

void initialize_exclusion_set( set<string>& );
void process_file( map<string, int>&, const set<string>& );
void user_query( const map<string, int>& );
void display_word_count( const map<string, int>&, ofstream& );

int main() {
    // string first_name, last_name;
    // cout << "Enter your first name: ";
    // cin >> first_name;

    // cout << "hi " << first_name << ", please enter your last name: ";
    // cin >> last_name;
    // cout << '\n';

    // cout << "Hello, " << first_name << ' ' << last_name
    //      << "... and goodbye!\n";

    ifstream ifile( "F:/Code_myself/temp_filewords.txt" );

    return 0;
}