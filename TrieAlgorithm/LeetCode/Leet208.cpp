#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    char data;
    bool terminal;
    vector<Node *> child;
    Node(char data){
        this->data = data;
        this->terminal = false;
        this->child.resize(26, NULL);
    }
    void makeTerminal(){
        this->terminal = true;
    }
};

class Trie {
public:
    Node *root;
    Trie() {
        root = new Node('\0');
    }
    
    void insert(string word) {
        Node *head = root;
        for (int i = 0; i < word.size(); i++){
            if(!head->child[word[i] - 'a']) {
                head->child[word[i] - 'a'] = new Node(word[i]);
            }
            head = head->child[word[i] - 'a'];
        }
        head->makeTerminal();
    }
    
    bool search(string word) {
        Node *head = root;
        for (int i = 0; i < word.size(); i++){
            if(!head->child[word[i] - 'a']) {
                return false;
            }
            head = head->child[word[i] - 'a'];
        }
        return head->terminal;
    }
    
    bool startsWith(string prefix) {
        Node *head = root;
        for (int i = 0; i < prefix.size(); i++){
            if(!head->child[prefix[i] - 'a' ]) {
                return false;
            }
            head = head->child[prefix[i] - 'a'];
        }
        return true;
    }
};

int main() {
    cout << "" << endl;
    return 0;
}