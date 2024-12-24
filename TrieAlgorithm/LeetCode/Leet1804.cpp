#include <bits/stdc++.h>

using namespace std;


class Node {
public:
    char data;
    int terminal;
    int count;
    vector<Node *> child;
    Node(char data){
        this->data = data;
        this->terminal = 0;
        this->child.resize(26, NULL);
        this->count = 0;
    }
    void makeTerminal(){
        this->terminal++;
    }
};

class Trie{
public:
    Node *root;
    Trie() {
        root = new Node('\0');
        root->count = 1;
    }

    void insert(string word) {
        Node *head = root;
        for (int i = 0; i < word.size(); i++){
            if(!head->child[word[i] - 'a']) {
                head->child[word[i] - 'a'] = new Node(word[i]);
            }
            head = head->child[word[i] - 'a'];
            head->count++;
        }
        head->makeTerminal();
    }

    int countWordsEqualTo(string word){
        Node *head = root;
        for (int i = 0; i < word.size(); i++){
            if(!head->child[word[i] - 'a']) {
                return 0;
            }
            head = head->child[word[i] - 'a'];
        }
        return head->terminal;
    }

    int countWordsStartingWith(string prefix){
        Node *head = root;
        for (int i = 0; i < prefix.size(); i++){
            if(!head->child[prefix[i] - 'a' ]) {
                return 0;
            }
            head = head->child[prefix[i] - 'a'];
        }
        return head->count;
    }

    void erase(string word){
        Node *head = root;
        for (int i = 0; i < word.size(); i++){
            head = head->child[word[i] - 'a'];
            head->count--;
        }
        head->terminal--;
        return;
    }
};

int main() {
    cout << "" << endl;
    return 0;
}