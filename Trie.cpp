#include <iostream>
#include <string>
#include <vector>

using namespace std;

class TrieNode
{
public:
    TrieNode *children[26];
    bool isWord;
    TrieNode()
    {
        for (int i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }
        isWord = false;
    }
};

class Trie
{
public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode();
    }
    void insert(string word)
    {
        TrieNode *node = root;
        for (char c : word)
        {
            if (node->children[c - 'a'] == nullptr)
            {
                node->children[c - 'a'] = new TrieNode();
            }
            node = node->children[c - 'a'];
        }
        node->isWord = true;
    }
    bool search_prefix(string word)
    {
        TrieNode *node = root;
        for (char c : word)
        {
            int u = c - 'a';
            if (node->children[u] == nullptr)
            {
                return false;
            }
            node = node->children[u];
        }
        return node->isWord;
    }
    bool match(string word, TrieNode *node, int i)
    {
        if (node == nullptr)
            return false;
        if (i == word.size())
            return node->isWord;
        if (word[i] == '.')
        {
            for (int j = 0; j < 26; j++)
            {
                if (match(word, node->children[j], i + 1))
                {
                    return true;
                }
            }
            return false;
        }
        else
        {
            return match(word, node->children[word[i] - 'a'], i + 1);
        }
    }
    bool search(string word)
    {
        return match(word, root, 0);
    }
};

int main()
{
    Trie trie;
    trie.insert("bad");
    trie.insert("dad");
    trie.insert("mad");
    cout << trie.search("pa.") << endl;
    cout << trie.search("b.d") << endl;
    cout << trie.search(".a.") << endl;
    return 0;
}