#include <bits/stdc++.h>

using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];
    bool isTerminalNode;
    TrieNode(char c)
    {
        data = c;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminalNode = false;
    }
};
class Trie
{
public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode('#');
    }
    void insertChar(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminalNode = true;
            return;
        }
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index])
            child = root->children[index];
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        insertChar(child, word.substr(1));
    }

    void insert(string word)
    {
        insertChar(root, word);
        cout << word << "  inserted in Trie\n";
    }

    bool searchChar(TrieNode *root, string word)
    {
        if (word.length() == 0)
            return root->isTerminalNode;
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index])
            child = root->children[index];
        else
            return false;
        return searchChar(child, word.substr(1));
    }
    bool search(string word)
    {
        return searchChar(root, word);
    }

    bool startsWithChar(TrieNode *root, string word)
    {
        if (word.length() == 0)
            return true;
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index])
            child = root->children[index];
        else
            return false;
        return startsWithChar(child, word.substr(1));
    }
    bool startsWith(string prefix)
    {
        return startsWithChar(root, prefix);
    }
};

int main()
{
    Trie T;
    T.insert("apple");
    if (T.search("app"))
        cout << "app found";
    else
        cout << "app not found\n";
    if (T.startsWith("aple"))
        cout << "Found starting with aple" << endl;
    else
        cout << "Couldn't find starting with apple\n";
    T.insert("app");
    if (T.search("app"))
        cout << "app found";
    else
        cout << "app not found\n";

    return 0;
}