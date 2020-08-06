#include <iostream>
#include <string>
#include <cstdlib> // For the exit function
#include <fstream> // For ifstream
using namespace std;

int main()
{
string name; // To hold a file name
string inputLine; // To hold a line of input
int lines = 0; // Counter for line numbers
ifstream file; // File stream object

// Get the name of the file.
cout << "Enter the file name: ";
getline(cin, name);

// Open the file.
file.open(name);

// Test for errors.
if (!file)
{
cout << "Error opening " << name << endl;
exit(EXIT_FAILURE);
}

// Display the first ten lines from the file.
while (!file.eof() && lines < 10)
{
// Get a line.
getline(file, inputLine, '\n');

// Increment the line counter.
lines++;

// Display the line.
cout << lines << ":" << inputLine << endl;
}

// If the file had less than 10 lines,
// indicate that the entire file has been
// displayed.
if (lines < 10)
cout << "\nThe entire file has been displayed.\n";

// Close the file.
file.close();

return 0;
}
