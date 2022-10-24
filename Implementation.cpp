#include "HEADER.h"
// function to take the input
string takingInput(){
    string msg; getline(cin, msg);
    return msg;
}
// function to store the words of the statement in a vector of strings
void newString(string msg){
    string nMsg = "";
    vector<string> vec;
    int m = 0;
    int j = 0;
    for (int i = 0; i <= msg.size(); i++){
        if(msg[i] == 32 or msg[i] == '\0'){
            string sub = msg.substr(j, i - j);
            if (ispunct(sub[sub.size()-1])) {
                char c = sub[sub.size()-1];
                string q = "";
                q += c;
                sub.erase(sub.size() - 1, 1);
                vec.push_back(sub);
                vec.push_back(q);
            }
            else {
                vec.push_back(sub);
            }

            j = (i + 1);
        }
    }
    // replacing she and he

    for (string &word : vec){
        if (word == "She" or word == "He") {
            word = "He or she";
        }
        else if (word == "she" or word == "he") {
            word = "he or she";
        }
        else if (word == "Him" or word == "Her"){
            word = "Him or her";
        }
        else if (word == "him" or word == "her") {
            word = "him or her";
        }
    }
// editing the spaces between words and punctuations
    vec.push_back(" ");
    for (int i = 0; i < vec.size() - 1; i++){
        if (ispunct(vec[i + 1][0])){
            nMsg += (vec[i] + vec[i + 1]);
            nMsg += " ";
            i++;
        }
        else
            nMsg += (vec[i] + " ");

    }
    cout << nMsg << endl;
}
