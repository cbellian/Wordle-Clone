#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

void letInWord(std::string,std::string, int[], int);
void letInRightSpot(std::string,std::string, char[], int[], int);
bool inputAndCheck(std::string, std::string);
bool winConditions(bool[], int);

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
        std::cout << correctWord << std::endl;
        bool win = inputAndCheck(correctWord,input);
        if(win)
        {
            std::cout << "WIN \n";
            return 1;
        }
    }
    return 0;
}
void letInWord(std::string Guess, std::string Correct, int arr[], int size){
    for (int i = 0; i < Correct.size(); i++){
        int count = std::count(Guess.begin(), Guess.end(), Correct[i]);
        arr[i] = count;
    }
}
void letInRightSpot(std::string guess, std::string correct, char wordSpot[], bool arr[], int size){
    for(int i = 0; i < correct.size(); i++){
        if(guess[i]==correct[i]){
            arr[i] = 1;
        }
    }
    for(int i = 0; i < size; i++){
        if(arr[i] == 1){
            wordSpot[i] = correct[i];
        }
        else if(arr[i] == 0){
            wordSpot[i] = '_';
        }
    }
}
bool winConditions(bool correct[], int size){
    int count = std::count(correct, correct + 5, 1);
    if (count == 5)
    {
        return 1;
    }
    return 0;
}
bool inputAndCheck(std::string correct, std::string input){
    int arrayOfIn[] = {0,0,0,0,0};
    int size = 5;
    bool arrayOfCorr[] = {0,0,0,0,0};
    char wordRight[5];
    letInWord(input,correct,arrayOfIn,size);
    letInRightSpot(input,correct,wordRight,arrayOfCorr,size);
    bool win = winConditions(arrayOfCorr,size);
    if (win)
    {
        return 1;
    }
    else{
        for(int i = 0; i<size;i++){
            std::cout << wordRight[i];
        }
    }
    return 0;
}