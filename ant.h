#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Ant
{
    private:
        string name;
        string color;
        int age;

    public:
        void setData(string n, string c, int a)
        {
            name = n;
            color = c;
            age = a;
        }
        string getName()
        {
            return name;
        }
        string getColor()
        {
            return color;
        }
        int getAge()
        {
            return age;
        }
        void setAge(int a)
        {
            age = a;
        }
        int getFirstNameLetter()
        {
            int nameLength = name.length();
            char cName[nameLength + 1];

            strcpy(cName, name.c_str());

            return cName[0];
        }
};