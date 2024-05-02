// S110-Search-Sort-App.cpp 
// Goal: Demonstration of sequential and binary search.
//       Explore various sort algorithms.
// ----------------------------------------------------

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void experiment01();
void experiment02();
void experiment03();
void experiment04();
vector<string> readFromDisk(string fileName);
void showDatabase(vector<string> vcountry, vector<string> vcapital,
                  vector<string> vlanguage, vector<string> vcurrency);
int sequentialSearch(vector<string> v, string key);


int main()
{
    experiment01();     //explore sequential search

    cout << "\nAll done!\n";
}

//User-defined functions ----------------------------------------------
void experiment01()
{
    vector<string> vcountry  = readFromDisk("c:/temp/xcountry.txt");
    vector<string> vcapital  = readFromDisk("c:/temp/xcapital.txt");
    vector<string> vcurrency = readFromDisk("c:/temp/xcurrency.txt");
    vector<string> vlanguage = readFromDisk("c:/temp/xlanguage.txt");
    showDatabase(vcountry, vcapital, vlanguage, vcurrency);

    string line;
    do
    {
        cout << "\nEnter country name [xxx to end]: ";
        getline(cin, line);
        if (line == "xxx") break;
        int dbpos = sequentialSearch(vcountry, line);
        if (dbpos == -1)
        {
            cout << "Country not found (" << line << ")\n";
            cout << "Try again";
        }
        else
        {
            cout << "\t Country:   " << vcountry[dbpos] << endl
                << "\t Capital:   " << vcapital[dbpos] << endl
                << "\t Language:  " << vlanguage[dbpos] << endl
                << "\t Currency:  " << vcurrency[dbpos] << endl << endl;
        }

    } while (true);

}

void showDatabase(vector<string> vcountry,  vector<string> vcapital, 
                  vector<string> vlanguage, vector<string> vcurrency)
{
    for (int i = 0; i < vcountry.size(); i++)
    {
        cout << "DB Position: " << i << endl
            << "\t Country:   " << vcountry[i] << endl
            << "\t Capital:   " << vcapital[i] << endl
            << "\t Language:  " << vlanguage[i] << endl
            << "\t Currency:  " << vcurrency[i] << endl << endl;
   }

}


vector<string> readFromDisk(string fileName)
{
    vector<string> answer;
    ifstream myfile(fileName);
    if (!myfile) {
        cout << "ERROR - file not found " << fileName << endl;
        exit(1);
    }
    string line;
    while (getline(myfile, line)) {
        answer.push_back(line);
    }
    myfile.close();
    return answer;
}

int sequentialSearch(vector<string> v, string key)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == key) return i;
    }
    return -1;
}
