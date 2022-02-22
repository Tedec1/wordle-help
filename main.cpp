#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <fstream>

std::set<std::string> read_word_list(const std::string& file_name){
    std::set<std::string> word_list;
    std::ifstream fin;
    fin.open(file_name);
    while(!fin.eof()){
        std::string s;
        getline(fin,s);
        if(s.length() == 5){
            word_list.insert(s);
        }
    }
    fin.close();
    return word_list;
}

int main() {
    std::string letters;
    std::cout << "enter letters left" << std::endl;
    std::cin >> letters;

    std::string ending;
    std::cout << "enter ending" << std::endl;
    std::cin >> ending;
    if(ending == "_"){
        ending = "";
    }


    std::string beginning;
    std::cout << "enter beginning" << std::endl;
    std::cin >> beginning;
    if(beginning == "_"){
        beginning = "";
    }

    std::cout << "letters left in middle" << std::endl;
    int x;
    std::cin >> x;

    std::vector<std::string> list;
    std::vector<std::string> temp_list;

    for (char c: letters) {
        list.push_back(beginning + c);
    }

    while(x > 0){
        for (const std::string & s: list) {
            for (char c: letters) {
                temp_list.push_back(s + c);
            }
        }
        list.clear();
        list = temp_list;
        temp_list.clear();
        x--;
    }
    std::set<std::string> word_list = read_word_list("dictionary.txt");

    for (const std::string & s: list) {
        temp_list.push_back(s + ending);
    }

    for (const std::string & s: temp_list) {
        if(word_list.count(s)){
            std::cout << s << std::endl;
        }
    }
//
//    for (std::string s: word_list) {
//        std::cout << s << std::endl;
//    }
    return 0;
}
