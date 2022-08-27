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
    string spaces;

    for (size_t i = 0; i < size;) {
        while (i < size && text[i] == ' ') {
            spaceNum++;
            i++;
        }
        if (i >= size)
            break ;
        words.push_back(i);
        while (i < size && text[i] != ' ') 
            i++;

        words.push_back(i);
        if (i >= size)
            break ;
    }
    if (words.size() > 2)
        dif = spaceNum / (words.size() / 2 - 1);
    else
        dif = spaceNum;


    for (int i = 0; i < dif; i++)
        spaces += " ";
    for (size_t j = 0; j < words.size(); j += 2) {
        newText += text.substr(words[j], words[j + 1] - words[j]);
        if (j != words.size() - 2)
            newText += spaces;
    }
    int mod = spaceNum - (dif * (words.size() / 2 - 1));
    for (int i = 0; i < mod; i++)
        newText += " ";
    return newText;
}

int main(int argc, char** argv) {
    if (argc == 2)
        cout << "rearrange spaces text: |" << reorderSpaces(argv[1]) << "|\n";
    return 0;
}