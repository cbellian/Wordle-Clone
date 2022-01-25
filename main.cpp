#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <time.h>

int main(int argc, char * argv[])
{
    std::ifstream wordFileIn;
    wordFileIn.open(argv[1]);
    if(wordFileIn.fail())
    {
        std::cout << "File failed to open. \n";
        return -1;
    }
    std::string arrOfWords[5757];
    std::string word;
    srand(time(NULL));
    int wordLoc = rand() % 5757; // 0 - 5756 index
    int indexFill = 0;
    while(getline(wordFileIn,word))
    {
        arrOfWords[indexFill] = word;
        indexFill++;
    }
    std::string correctWord = arrOfWords[wordLoc];
    std::string string1, string2, string3, string4, string5, string6;
    std::cout << "First input: \n";
    getline(std::cin, string1);
    
    return 0;
}