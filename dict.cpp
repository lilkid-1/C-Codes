#include <iostream>
using namespace std;

const int ALPHA_SIZE = 26;
struct Trie
{
    // children of specific root
    struct Trie *children[ALPHA_SIZE];
    // to mark end of string if string is in last char this will store true else false
    bool isEnd;
    // for frequency
    int data;
};
// function to create root
struct Trie *getNode(void)
{
    struct Trie *p = new Trie;

    p->isEnd = false;
    p->data = NULL;

    for (int i = 0; i < ALPHA_SIZE; i++)
        p->children[i] = NULL;

    return p;
}
// function to insert string into trie which takes parameter as root,string and its respective frequency
void insert(struct Trie *root, string words, int data)
{
    struct Trie *q = root;

    for (int i = 0; i < words.length(); i++)
    {
        int index = words[i] - 'a';
        if (!q->children[index])
            q->children[index] = getNode();
        // iterating to next element
        q = q->children[index];
    }
    // last char of string marked as true
    q->isEnd = true;
    // last char o fstring will contain the frequency of respective string
    q->data = data;
}
// search string into Trie
int search(struct Trie *root, string words)
{
    struct Trie *r = root;

    for (int i = 0; i < words.length(); i++)
    {
        int index = words[i] - 'a';
        if (!r->children[index])
            return 0;

        r = r->children[index];
    }
    // returning frequency of string which is stored in the last char of string
    return (r->data);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // declaring string array and frequency array to store string with respect to its input frequency
    string words[100000];
    int freq[100000];
    string k;
    int f;
    int i = 0;
    // until user provides input store string into string array and its frequency into frequency array
    while (cin >> k && cin >> f)
    {
        words[i] = k;
        freq[i] = f;
        i++;
    }
    // size of string array
    int size = sizeof(words) / sizeof(words[0]);
    // create root Node
    struct Trie *root = getNode();
    // inserting string and frequency with respect to root
    for (int i = 0; i < size; i++)
        insert(root, words[i], freq[i]);
    // string to be searched for
    string j;
    cin >> j;
    // function to search the desired string
    int ans = search(root, j);
    // if freq is greater than 0 it means that string exist in the dictionary then simply search and print yes with freq
    // else the key doesn t exist in dictionary cause the initial value for non existing key will be 0
    (ans > 0) ? cout << "YES"
                     << " " << ans << "\n"
              : cout << "No"
                     << "\n";
}