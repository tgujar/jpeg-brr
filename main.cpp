//
// Created by Tanmay Gujar on 3/31/23.
//

#include <iostream>
#include <fstream>


using namespace std;
int main() {
    ifstream f;
    f.open("test.txt");
    if (f.is_open()) cout << "its open";
    string line;
    while(f >> line) cout << line << endl;
    return 0;
}