#include "Node.h"
#include "Tree.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv) {
    const int ARGUMENTS = 2;
    
    // check the command line argument, an input file name is needed
    if (argc != ARGUMENTS)
    {
        cout << "Usage: " << argv[0] << " <filename>" << endl;
        return 1;
    }   

        // check if the input file can be opened successfully
    ifstream infile;
    infile.open(argv[1]);
    if (!infile.good())
    {
        cout << "Cannot open the file named " << argv[1] << endl;
        return 2;
    }  
    
    // read in the terms from the input file
    // line by line and store into Autocomplete object
    Tree tree;
    int next;
    
    while (infile >> next)
    {
        tree.insert(next);
    }    
    
    tree.printTree();

    bool cont = true;
    int value;
    char continueInput;
    do {
        while (true)
        {
            cout << "What integer value would you like to look for? ";
            cin >> value;
            cin.ignore(256, '\n');

            if (cin.fail())
            {
                string check_input;
                cin.clear();
                cout << "Invalid input, please try again..." << endl;
                continue;
            } 
            else {
                break;
            }  
        }

        tree.searchTree(value);

        while (true)
        {
            cout << "Do you want to search for another value (y/n)? ";
            cin >> continueInput;
            if (continueInput == 'y') {
                break;
            }
            if (continueInput == 'n') {
                cont = false;
                break;
            }
        }
    } while (cont == true);

    return 0;
}