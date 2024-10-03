/*Jack is learning to type english from the beginning and he is making an error of repeating the same words in his texts over whatsapp. Write a function that will take input for his text sent to you and then keep only the unique texts.
Note that, the uniqueness is about being word specific not position, there are nothing but alphabets in the sentences and words are separated only with white space.

Constraints:
Words in the line<=10^5
Alphabets in the words<=20

Sample Input:
Send send the image send to to to me

Output:
Send the mage to me*/


#include<bits/stdc++.h>
using namespace std;

string removeDuplicates(string s){
    unordered_set<string> wordsSet;
    int n = s.size();
    vector<string> result;

    string words = "";

    for(int i = 0;i<n;i++){
        if(s[i] == ' '){
            if(!words.empty() && wordsSet.find(words) == wordsSet.end()){
                wordsSet.insert(words);
                result.push_back(words);
            }
            words = "";
        }
        else{
            words += s[i];
        }
    }

    if(!words.empty() && wordsSet.find(words) == wordsSet.end()){
                wordsSet.insert(words);
                result.push_back(words);
            }

    string output = "";
    for(int i = 0;i<result.size();i++){
        if(i!= 0){
            output += " ";
        }
        output += result[i];
    }
    return output;
}

int main(){
    string input;
    getline(cin,input);

    string output = removeDuplicates(input);
    cout << output;
}