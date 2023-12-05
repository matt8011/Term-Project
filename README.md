# CSC 212 Group 1 Final Project: Trie Data Structure
*By Matt Kyle, Evan O'Neill, Jacob Pierce, and Nitish Salvi*

## Overview
This project utilizes a Trie to implement an autocomplete function in C++. The user will interact with this program via command-line arguments (CLAs) and user inputs in an Ubuntu terminal. The following functions are implemented:
- Search
- Insert
- Print to File
- Repeated Words
  
## Setup
This program requires C++ to run alongside Ubuntu to test the program. 
### Installing an IDE
To properly run this program, an IDE should be installed. A few local IDEs we recommend are *CLion* and *VSCode*. If you are unable to utilize a local IDE then you can use *cs50.dev* as an Online IDE.
### Installing g++
Run the following commands:
**sudo apt-get update** and
**sudo apt-get install g++**
### Using an Input File
This can be done by putting articles, dictionaries, and texts into a .txt file. The input file can be any text you want to be autocompleted or to be used to fill the autocomplete reference text. An example text is provided in the **Scaffolding** folder named **dictionary.txt.**

## Compiling
1. Download the following files from this repository: **main.cpp**, **Trie.cpp**, **Trie.h**. These are located in the **Scaffolding** folder. (Make sure to also download a library mentioned in the **Downloading a Library** section.)
2. Open your IDE and navigate to the folder where you stored your files with the CLA "cd".
3. Compile the program using this CLA: **g++ main.cpp Trie.cpp -o *prog***. (where prog is what you want your program to run as)
4. Run the program with the following CLA: **./prog *inputFile.txt***. (where inputFile.txt is YOUR input file)
5. Follow the terminal commands.
## Debugging and Troubleshooting
### Unexpected Outputs for Autocomplete:
The autocomplete system has two features that may be misconstrued as errors.
  - **"The input text is a complete word":** If this message appears in an autocomplete text file, the input text matches a complete word in the dictionary, and there are no longer words.
  - **The completed words do not match the input:** The output file lists a bunch of completed words, but they don't start with your input. This is because there were no words that matched the exact input. Instead, your input was shortened until there were words that started with that.

For example:

  	law [la] :
	ladder
	lady
	lamp
There were no words begining with law, so the output showed words begining with la.

### There is no Output File:

- **"Search yielded no results":** This message only appears when searching for a word and not only does it not appear 0 times the value that would hold zero is empty. This is very rare check your search for special charcters and make sure that the tree has been filled.
- **"Autocomplete yielded no results":** This message is not as rare, it appears when all words that are being autocompleted have no results. Check your search for special charcters and make sure that the tree has been filled.

## Example Inputs and Outputs

### Menu Selection

- **First Menu**
- **Choice of Continuation**
- **Access File or Input Options**
- **File Editing Options**
- **Adding/Searching/Autocompletion Options**


