#include <iostream>

using namespace std;

int main()
{
    string name;
    cout << "Please type in your name: ";
    getline(cin,name);
    cout << "Hello " << name << "!" << endl;
    return 0;
}
