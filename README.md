Q1)dict.cpp
Simple code for searching a string in a dictionary.
Used Trie data structure to store string and its respective frequency.
String and frequency to be stored until user stops providing input.
Last char of the respective word contains the frequency of overall respective word.
Passed the string to be searched as a parameter in the search operation and returned the frequency of the respective word.
If the frequency of word is greater than 0 then return yes with frequency else return no.

Code Compile
gcc filename.cpp


 > user input
 
 
  inputstring inputfrequency
  
  
 > user input
 
 
  searchstring
  
 
q2)dict2.cpp
Simple code for searching string on the basis of given numbers from 0 to N.
Used Trie Data Structure to store string and number respectively.
String and number to be stored until user stops providing input.
A temporary String array created which maps string with respect to its number as index of the array.
User provides any number from 0 to N which is passed as a parameter in search operation.
Temporary String array is also passed to the function so on providing the number we will return the string at the respective index of the user input if the number is less than equal to size of dictionary.If the input number is greater than the size of dictionary then there is no string matching the criteria.



Code Compile
gcc filename.cpp


> user input
   
  input number to be searched
  
  
 > user input
 
  inputstring inputnum
  
  (input num starting from 0 to length of Dictionary)
 
