// Lab 5 - 16 June 2024
// lab5.cpp
// Linhnam Le & Andrew Nunez Forsberg
// This assignment demonstrates a Hashtable

#include "Dollar.h"
#include "HashTable.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cctype>
#include <algorithm>

using namespace std;


//valid is any number thats not negitive 
bool valid(string s){

    try {
        size_t size;
        std::stod(s, &size);
        if (size != s.size()) {
            return false;
        }
        if (stod(s) < 0){
          return false;
        }
        return true;

    } catch (const std::invalid_argument& e) {
        return false;
    } catch (...) {
        return false;
    }
}



// Pre-determined data and table size per assignment instructions
const int TABLE_SIZE = 29;
const int SIZE = 20;
const double TEST_VALS[SIZE] = {
    57.12, 23.44, 87.43, 68.99, 111.22, 44.55, 77.77, 18.36, 543.21, 20.21,
    345.67, 36.18, 48.48, 101.00, 11.00, 21.00, 51.00, 1.00, 251.00, 151.00
};

int main()
{
    // create hash table
    HashTable table(TABLE_SIZE);

    // Data seeding  
    for (double num : TEST_VALS) {
        Dollar* insertedDollar = new Dollar(num);
        table.insert(*insertedDollar);
    }

    table.display();

    while (true) {
        // Get input
        std::string input = "";
        cout << "\nCommands: add/insert, search, quit" << endl;
        cout << "For search enter a currency value, e.g. \"search 12.44\"" << endl;
        std::getline(std::cin, input);

        // cout << "Getline successful..." << endl;

        // Tokenize the input
        std::istringstream iss(input);
        std::vector<std::string> tokens;
        std::string token;

        // cout << "Input tokenized..." << endl;

        while (iss >> token) {
            tokens.push_back(token);
        }
        
        // cout << "Token push-back successful..." << endl;

        // Quit condition
        if (tokens[0] == "q" || tokens[0] == "quit") { return 0; }

        // *** Search call ***
        // TODO: fix input validation
        else if (tokens[0] == "search") {
            // Compact lambda function to identify errant inputs
            // Flags true if characters other than number or decimal point found
            // Uses cctype header
            bool hasLetters = find_if( tokens[1].begin(), tokens[1].end(), [] (char c) { return isalpha(c); } ) != tokens[1].end();

            if (hasLetters) { // Search code will not proceed if input cannot be read
                cout << "Failed to recognize numerical input - please try again";
            }

            else { // Actual search code exists here inside else statement
                // cout << "Entering search..." << endl;
                Dollar searchCurr(stod(tokens[1]));
                // cout << "searchCurr call successful..." << endl;
                int indexResult = table.search(searchCurr);

                // Search will return -1 if the given input is NOT found on the table
                if (indexResult == -1) {
                    cout << "Invalid Data" << endl;
                }
                else {
                    cout << "Index: " << indexResult << endl;
                }
            }
        }   else if (tokens[0] == "add" || tokens[0] ==  "insert") {
              for (int i = 1; i < tokens.size(); i++) {
                if (valid(tokens[i])) {
                  //write to screen and output
                  cout << "Inserting value : " << tokens[i] << endl;
                  //perform op
                  Dollar* addCurr = new Dollar(stod(tokens[i]));
                  table.insert(*addCurr);

                }else {
                  //if invalid value enterd
                  cout << "Invalid Value entered : " << tokens[i] << endl;
                } 
              }

              table.display();
            }

        // Repeat if cmd not known
        else {
            cout << "Command not recognized - please search or quit";
        }


    }

    return 0;
}
