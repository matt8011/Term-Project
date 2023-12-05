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

To commit to a user-friendly application, our code displayes a menu with options before and after every action made by the user, until the user quits the application. There are a wide range of options to choose from and many separate menus that will appear.

- **First Menu**
- <img width="399" alt="Screen Shot 2023-12-04 at 10 16 29 PM" src="https://github.com/matt8011/Term-Project/assets/123590351/95b46caf-34a3-4683-b3f4-569c0f87c31c">

- **Choice of Continuation**
- <img width="275" alt="Screen Shot 2023-12-04 at 10 18 50 PM" src="https://github.com/matt8011/Term-Project/assets/123590351/deec0517-8f37-409a-bebd-1ea2bc10b45b">

- **Access File or Input Options**
- <img width="246" alt="Screen Shot 2023-12-04 at 10 19 09 PM" src="https://github.com/matt8011/Term-Project/assets/123590351/05ad6b3b-3ae1-4f6e-8bd0-ad5009e23e60">

- **File Editing Options**
- <img width="174" alt="Screen Shot 2023-12-04 at 10 19 23 PM" src="https://github.com/matt8011/Term-Project/assets/123590351/693d5e40-a092-4641-9b72-f95d606680f6">

- **Adding/Searching/Autocompletion Options**
- <img width="188" alt="Screen Shot 2023-12-04 at 10 24 44 PM" src="https://github.com/matt8011/Term-Project/assets/123590351/58f8b2ff-3d81-4243-8ca2-7981bd5add89">

### Output Files

Whenever an action is performed by the user (autocomplete, search, add, etc..) an output file will be created based on the action that was prompted by the user's selection.

-**Prefill**

With Input Text:

-*"among, craft, fort, john, mine, night, us, wick, zebra"*


The Prefilled Graph Will Look Like So:

-<img width="161" alt="Screen Shot 2023-12-04 at 10 40 25 PM" src="https://github.com/matt8011/Term-Project/assets/123590351/6030abb3-54f1-41df-abc6-5ff5646a93dc">


Visual:

-<img width="391" alt="Screen Shot 2023-12-04 at 10 42 57 PM" src="https://github.com/matt8011/Term-Project/assets/123590351/4297b34e-70c6-4bd7-a7e6-b0988945dcbc">

*The red pointers indicate that there is no word that ends with the next character from the character it is coming from. The blue pointers indicate that there IS a word that ends with the charcter it is being pointed to, from the character it is chained to.*


-**Adding Words**-

After adding these words to the tree:

-*"place, can, trash, statement, straw, sink"*

The new graph looks like this:

- <img width="507" alt="Screen Shot 2023-12-04 at 11 03 51 PM" src="https://github.com/matt8011/Term-Project/assets/123590351/39448c4a-b01c-48c2-9b8d-ba498e561986">


-**Search**

After searching for the following words:

-*"wick, plant, place"*

The following output file is created:

Search Queries and results:

wick was found 1 times
plant was found 1 times
place was found 2 times

*Note: Since wick and plant both exist in two separate databases (wick -> input.txt, plant -> dictionary in trie.h), they both are found only once. However, the word place exists in both databases, making its found value 2.*


-**Autocomplete**

After prompting the following autocomplete queries:

-*"str, zqu, po"*

The following output file is created:

Auto-completions:

str [str] :
	straw
	strange
	street
	strong
	structure
zqu [z] :
	zebra
	zero
po [po] :
	pocket
	point
	poison
	police
	polite
	pool
	poor
	popular
	position
	possible
	potato
	pour
	power

*Note: Because 'zqu' is read as a typo, the autoComplete function uses backtracking to find the first substring in 'zqu' that has any type of results for an autocompletion, which in this case is 'z'* 
