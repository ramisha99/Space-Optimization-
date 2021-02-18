#include <iostream>
#include <fstream>
#include "print_neatly2.h"
#include<vector>

int main() {
    std::ifstream input;
    input.open("input.txt");
    std::string word;
    std::vector<std::string> words;
    
    //create an int array as long as the vector //calculate the length of each word and put it in the array
    while (input >> word)
        words.push_back(word);
    input.close();
    std::cout << "Read " << words.size() << " words." << std::endl;
    int* a = (int*)calloc(sizeof(int), words.size());
    std::vector < std::string>::iterator itr;
    int count = 0;//counter for how many words have been processed 
    for (itr = words.begin(); itr < words.end(); itr++)
    {
        int length = itr->length();
        a[count++] = length;
    }

    std::cout << "Enter max line length:";
    int maxWidth;
    std::cin >> maxWidth;

    solveWordWrap(a,words.size(),maxWidth, words);
    std::cout << std::endl;

    return 0;
    
}//