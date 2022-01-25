#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

void letInWord(std::string,std::string, int[], int);
void letInRightSpot(std::string,std::string, int[], int);
void inputAndCheck(std::string, std::string);

int main(int argc, char * argv[])
{
    std::ifstream wordFileIn;
    wordFileIn.open(argv[1]);
    if(wordFileIn.fail()){
        std::cout << "File failed to open. \n";
        return -1;
    }
    std::string arrOfWords[5757];
    std::string word;
    srand(time(NULL));
    int wordLoc = rand() % 5757; // 0 - 5756 index
    int indexFill = 0;
    while(getline(wordFileIn,word)){
        arrOfWords[indexFill] = word;
        indexFill++;
    }
    std::string input;
    std::string correctWord = arrOfWords[wordLoc];
    for (int i = 5; i >= 0; i--){
        std::cout << "Input Guess: \n";
        getline(std::cin, input);
        for(char &c : input){
            c = tolower(c);
        }
        std::cout << input << std::endl;
        inputAndCheck(correctWord,input);
    }
    return 0;
}

void inputAndCheck(std::string correct, std::string input){
    int arrayOfIn[] = {0,0,0,0,0};
    int size = 5;
    int arrayOfCorr[] = {0,0,0,0,0};
    letInWord(input,correct,arrayOfIn,size);
    letInRightSpot(input,correct,arrayOfCorr,size);
}

void letInWord(std::string Guess, std::string Correct, int arr[], int size){
    for (int i = 0; i < Correct.size(); i++){
        int count = std::count(Guess.begin(), Guess.end(), Correct[i]);
        arr[i] = count;
    }
}
void letInRightSpot(std::string guess, std::string correct, int arr[], int size){
    for(int i = 0; i < correct.size(); i++){
        if(guess[i]==correct[i]){
            arr[i] = 1;
        }
    }
}