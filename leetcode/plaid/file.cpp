
#include <stdio.h>

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
    ifstream infile("file.txt");

    // Method 1: Read token by token
    int a;
    int b;
    while (infile >> a >> b) {
        cout << a << " "<< b << endl;
    }

    // Method 2: Line-based parsing
    // string line;
    // while (getline(infile, line)) {
    //     istringstream iss(line);
    //     int a;
    //     int b;
    //     if (!(iss >> a >> b)) {
    //         break;
    //     }
    //     cout << line << endl;
    // }

    // Method 3: Delimiter-based parsing
    // string line;
    // while (getline(infile, line)) {
    //     istringstream iss(line);
    //     string a;
    //     string b;
    //     getline(iss, a, ',');
    //     getline(iss, b);
    //     if (iss) {
    //         cout << a << " " << b << endl;
    //     }
    // }

    return 0;
}
