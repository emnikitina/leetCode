#include <iostream>
#include <string>
#include <vector>

using namespace std;

string reorderSpaces(string text) {
    size_t size = text.size();
    size_t spaceNum = 0;
    string newText = "";
    int dif = 0;
    vector<size_t> words;

    cout << "size : " << size << endl;
    for (size_t i = 0; i < size;) {
        while (i < size && text[i] == ' ') {
            spaceNum++;
            i++;
        }
        if (i >= size)
            break ;
        words.push_back(i);
        cout << "start i: " << i << endl;
        while (i < size && text[i] != ' ') {
            // cout << "in word i: " << i << " letter: " << text[i] << endl;
            i++;
        }
        cout << " between i: " << i << endl;
        if (i >= size)
            break ;
        words.push_back(i);
        cout << "end i: " << i << endl;
    }
    cout << "words size: " << words.size()  << endl;
    if (words.size() > 2)
        dif = spaceNum / (words.size() / 2 - 1);
    else
        dif = spaceNum;
    cout << "space num: " << spaceNum << endl;
    
    cout << "dif: " << dif << endl;
    
    for (int i = 0; i < words.size(); i++)
        cout << "words i: " << words[i] << endl;

    size_t j = 0;
    string spaces;
    for (int i = 0; i < dif; i++)
        spaces += " ";
    size_t i = 0;
    while (i < size) {
        cout << " i: " << i << endl;
        newText += text.substr(words[j], words[j + 1] - words[j]);
        i += (words[j + 1] - words[j]);
        cout << "word: " << text.substr(words[j], words[j + 1] - words[j]) << " i: " << i << endl;
        //if (j == words.size())
        cout << " i: " << i << endl;
        if (i >= size - 1)
            break ;
        j += 2;
        // while (words[j] < words[j + 1]) {
        //     cout << "text: " << text[words[j]] << endl;
        //     newText += to_string(text[words[j]]);
        //     words[j]++;
        //     i++;
        // }
        // j += 2; 
        
        newText += spaces;
        i += dif;
        
    }
    cout << "here i: " << i << endl;
    for (i; i < size; i++)
        newText += " ";
    return newText;
}

int main(int argc, char** argv) {
    if (argc == 2)
        cout << "rearrange spaces text: \n|" << reorderSpaces(argv[1]) << "|\n";
    return 0;
}