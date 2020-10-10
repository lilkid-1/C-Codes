#include <bits/stdc++.h>
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
void insert(struct Trie *root, string words, int data, string s1[])
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
    // mapping words with respected to index of array where index is data of the respective word from 0 to N
    s1[data] = words;
}
// searching string with respected to input number
string search(struct Trie *root, string s1[], int ind)
{
    // returning the word according to given input number , s1 array consists of word with respect to index values
    // therefore the word will be at the given index of the s1 array returning that
    return s1[ind];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // declaring string arrays one for storing user input and other for storing words according to the number assigned
    // the number assigned will be the index of the s1 array containing the respective word
    string words[100000], s1[100000];
    string k;
    int i = 0;
    // the number to be searched from 0 to N
    int j;
    cin >> j;
    // until user provides input store string into string array
    while (cin >> k)
    {
        words[i] = k;
        i++;
    }
    // size of string array
    int size = sizeof(words) / sizeof(words[0]);
    // create root Node
    struct Trie *root = getNode();
    // inserting string and number with respect to root;
    for (int i = 0; i < size; i++)
        insert(root, words[i], i, s1);
    // string to be searched according to the given number
    if (j <= size)
    {
        // passing s1 array as parameter and the number to be searched for
        string ans = search(root, s1, j);
        cout << ans << "\n";
    }
    else
    {
        // if number to be found is greater than the size of dictionary then the number doesn't exist
        cout << "NOT FOUND"
             << "\n";
    }
}