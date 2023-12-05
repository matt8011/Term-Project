![graphviz (3)](https://github.com/matt8011/Term-Project/assets/123590351/bb9111e0-581c-44f5-8067-de3c4acc6c6b)[text.txt](https://github.com/matt8011/Term-Project/files/13554772/text.txt)# CSC 212 Group 1 Final Project: Trie Data Structure
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
[Uploaamong, craft, fort, john, mine, night, us, wick, zebrading text.txt…]()

The Prefilled Graph Will Look Like So:
[Upldigraph G {

a -> m[color="red"];
m -> o[color="red"];
o -> n[color="red"];
n -> g[color="blue"];
c -> r[color="red"];
r -> a[color="red"];
a -> f[color="red"];
f -> t[color="blue"];
f -> o[color="red"];
o -> r[color="red"];
r -> t[color="blue"];
j -> o[color="red"];
o -> h[color="red"];
h -> n[color="blue"];
m -> i[color="red"];
i -> n[color="red"];
n -> e[color="blue"];
n -> i[color="red"];
i -> g[color="red"];
g -> h[color="red"];
h -> t[color="blue"];
u -> s[color="blue"];
w -> i[color="red"];
i -> c[color="red"];
c -> k[color="blue"];
z -> e[color="red"];
e -> b[color="red"];
b -> r[color="red"];
r -> a[color="blue"];

}oading text.txt_fill.dot…]()

Visual:
![Uploading<?xml version="1.0" encoding="UTF-8" standalone="no"?><!DOCTYPE svg PUBLIC "-//W3C//DTD SVG 1.1//EN" "http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd"><!-- Generated by graphviz version 2.40.1 (20161225.0304)
 --><!-- Title: G Pages: 1 --><svg xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" width="398pt" height="548pt" viewBox="0.00 0.00 398.00 548.00">
<g id="graph0" class="graph" transform="scale(1 1) rotate(0) translate(4 544)">
<title>G</title>
<polygon fill="#ffffff" stroke="transparent" points="-4,4 -4,-544 394,-544 394,4 -4,4"/>
<!-- a -->
<g id="node1" class="node">
<title>a</title>
<ellipse fill="none" stroke="#000000" cx="98" cy="-522" rx="27" ry="18"/>
<text text-anchor="middle" x="98" y="-517.8" font-family="Times,serif" font-size="14.00" fill="#000000">a</text>
</g>
<!-- m -->
<g id="node2" class="node">
<title>m</title>
<ellipse fill="none" stroke="#000000" cx="187" cy="-450" rx="27" ry="18"/>
<text text-anchor="middle" x="187" y="-445.8" font-family="Times,serif" font-size="14.00" fill="#000000">m</text>
</g>
<!-- a&#45;&gt;m -->
<g id="edge1" class="edge">
<title>a-&gt;m</title>
<path fill="none" stroke="#ff0000" d="M115.5835,-507.7751C128.834,-497.0557 147.1845,-482.2103 161.9661,-470.2522"/>
<polygon fill="#ff0000" stroke="#ff0000" points="164.1827,-472.9609 169.7558,-463.9503 159.78,-467.5188 164.1827,-472.9609"/>
</g>
<!-- f -->
<g id="node8" class="node">
<title>f</title>
<ellipse fill="none" stroke="#000000" cx="259" cy="-450" rx="27" ry="18"/>
<text text-anchor="middle" x="259" y="-445.8" font-family="Times,serif" font-size="14.00" fill="#000000">f</text>
</g>
<!-- a&#45;&gt;f -->
<g id="edge7" class="edge">
<title>a-&gt;f</title>
<path fill="none" stroke="#ff0000" d="M121.2103,-512.4301C146.438,-501.9225 187.853,-484.363 223,-468 224.7579,-467.1816 226.5577,-466.3291 228.3697,-465.4595"/>
<polygon fill="#ff0000" stroke="#ff0000" points="229.9465,-468.5846 237.3932,-461.0482 226.8721,-462.2959 229.9465,-468.5846"/>
</g>
<!-- o -->
<g id="node3" class="node">
<title>o</title>
<ellipse fill="none" stroke="#000000" cx="187" cy="-378" rx="27" ry="18"/>
<text text-anchor="middle" x="187" y="-373.8" font-family="Times,serif" font-size="14.00" fill="#000000">o</text>
</g>
<!-- m&#45;&gt;o -->
<g id="edge2" class="edge">
<title>m-&gt;o</title>
<path fill="none" stroke="#ff0000" d="M187,-431.8314C187,-424.131 187,-414.9743 187,-406.4166"/>
<polygon fill="#ff0000" stroke="#ff0000" points="190.5001,-406.4132 187,-396.4133 183.5001,-406.4133 190.5001,-406.4132"/>
</g>
<!-- i -->
<g id="node12" class="node">
<title>i</title>
<ellipse fill="none" stroke="#000000" cx="259" cy="-234" rx="27" ry="18"/>
<text text-anchor="middle" x="259" y="-229.8" font-family="Times,serif" font-size="14.00" fill="#000000">i</text>
</g>
<!-- m&#45;&gt;i -->
<g id="edge15" class="edge">
<title>m-&gt;i</title>
<path fill="none" stroke="#ff0000" d="M205.1467,-436.1389C230.9233,-415.1717 277.0074,-372.6387 295,-324 300.5511,-308.9938 299.6365,-303.3135 295,-288 291.7339,-277.2127 285.5236,-266.6108 279.1687,-257.6963"/>
<polygon fill="#ff0000" stroke="#ff0000" points="281.9513,-255.5732 273.1229,-249.7156 276.3715,-259.8001 281.9513,-255.5732"/>
</g>
<!-- n -->
<g id="node4" class="node">
<title>n</title>
<ellipse fill="none" stroke="#000000" cx="187" cy="-306" rx="27" ry="18"/>
<text text-anchor="middle" x="187" y="-301.8" font-family="Times,serif" font-size="14.00" fill="#000000">n</text>
</g>
<!-- o&#45;&gt;n -->
<g id="edge3" class="edge">
<title>o-&gt;n</title>
<path fill="none" stroke="#ff0000" d="M187,-359.8314C187,-352.131 187,-342.9743 187,-334.4166"/>
<polygon fill="#ff0000" stroke="#ff0000" points="190.5001,-334.4132 187,-324.4133 183.5001,-334.4133 190.5001,-334.4132"/>
</g>
<!-- r -->
<g id="node7" class="node">
<title>r</title>
<ellipse fill="none" stroke="#000000" cx="84" cy="-90" rx="27" ry="18"/>
<text text-anchor="middle" x="84" y="-85.8" font-family="Times,serif" font-size="14.00" fill="#000000">r</text>
</g>
<!-- o&#45;&gt;r -->
<g id="edge10" class="edge">
<title>o-&gt;r</title>
<path fill="none" stroke="#ff0000" d="M160.8052,-373.5955C134.0023,-367.5417 93.7132,-353.7972 75,-324 34.3948,-259.3442 58.2074,-163.6238 73.7776,-117.2096"/>
<polygon fill="#ff0000" stroke="#ff0000" points="77.1547,-118.1544 77.1375,-107.5595 70.544,-115.8526 77.1547,-118.1544"/>
</g>
<!-- h -->
<g id="node11" class="node">
<title>h</title>
<ellipse fill="none" stroke="#000000" cx="221" cy="-90" rx="27" ry="18"/>
<text text-anchor="middle" x="221" y="-85.8" font-family="Times,serif" font-size="14.00" fill="#000000">h</text>
</g>
<!-- o&#45;&gt;h -->
<g id="edge13" class="edge">
<title>o-&gt;h</title>
<path fill="none" stroke="#ff0000" d="M212.8569,-371.8739C237.6625,-364.6371 274.3146,-350.1361 295,-324 335.8105,-272.4359 321.3934,-245.3183 329,-180 330.8508,-164.1074 337.4117,-157.6104 329,-144 329,-144 283.7813,-121.3906 251.8626,-105.4313"/>
<polygon fill="#ff0000" stroke="#ff0000" points="253.365,-102.2694 242.8554,-100.9277 250.2344,-108.5304 253.365,-102.2694"/>
</g>
<!-- g -->
<g id="node5" class="node">
<title>g</title>
<ellipse fill="none" stroke="#000000" cx="221" cy="-162" rx="27" ry="18"/>
<text text-anchor="middle" x="221" y="-157.8" font-family="Times,serif" font-size="14.00" fill="#000000">g</text>
</g>
<!-- n&#45;&gt;g -->
<g id="edge4" class="edge">
<title>n-&gt;g</title>
<path fill="none" stroke="#0000ff" d="M191.2374,-288.0535C197.0401,-263.4774 207.5179,-219.1008 214.3659,-190.0974"/>
<polygon fill="#0000ff" stroke="#0000ff" points="217.8176,-190.7094 216.7092,-180.1727 211.0049,-189.1008 217.8176,-190.7094"/>
</g>
<!-- n&#45;&gt;i -->
<g id="edge18" class="edge">
<title>n-&gt;i</title>
<path fill="none" stroke="#ff0000" d="M197.8984,-289.3008C207.2493,-278.8049 220.7437,-265.2014 232.7586,-254.1132"/>
<polygon fill="#ff0000" stroke="#ff0000" points="235.2934,-256.5406 240.3821,-247.2478 230.609,-251.339 235.2934,-256.5406"/>
</g>
<!-- e -->
<g id="node13" class="node">
<title>e</title>
<ellipse fill="none" stroke="#000000" cx="111" cy="-234" rx="27" ry="18"/>
<text text-anchor="middle" x="111" y="-229.8" font-family="Times,serif" font-size="14.00" fill="#000000">e</text>
</g>
<!-- n&#45;&gt;e -->
<g id="edge17" class="edge">
<title>n-&gt;e</title>
<path fill="none" stroke="#0000ff" d="M171.2528,-291.0816C160.553,-280.945 146.219,-267.3654 134.2163,-255.9944"/>
<polygon fill="#0000ff" stroke="#0000ff" points="136.3937,-253.236 126.7271,-248.8993 131.5795,-258.3177 136.3937,-253.236"/>
</g>
<!-- g&#45;&gt;h -->
<g id="edge20" class="edge">
<title>g-&gt;h</title>
<path fill="none" stroke="#ff0000" d="M221,-143.8314C221,-136.131 221,-126.9743 221,-118.4166"/>
<polygon fill="#ff0000" stroke="#ff0000" points="224.5001,-118.4132 221,-108.4133 217.5001,-118.4133 224.5001,-118.4132"/>
</g>
<!-- c -->
<g id="node6" class="node">
<title>c</title>
<ellipse fill="none" stroke="#000000" cx="293" cy="-162" rx="27" ry="18"/>
<text text-anchor="middle" x="293" y="-157.8" font-family="Times,serif" font-size="14.00" fill="#000000">c</text>
</g>
<!-- c&#45;&gt;r -->
<g id="edge5" class="edge">
<title>c-&gt;r</title>
<path fill="none" stroke="#ff0000" d="M271.5574,-150.5734C266.8275,-148.2523 261.7961,-145.9329 257,-144 210.3852,-125.2136 154.5892,-108.8477 119.2173,-99.1956"/>
<polygon fill="#ff0000" stroke="#ff0000" points="119.9345,-95.764 109.3679,-96.5377 118.1106,-102.5222 119.9345,-95.764"/>
</g>
<!-- k -->
<g id="node17" class="node">
<title>k</title>
<ellipse fill="none" stroke="#000000" cx="293" cy="-90" rx="27" ry="18"/>
<text text-anchor="middle" x="293" y="-85.8" font-family="Times,serif" font-size="14.00" fill="#000000">k</text>
</g>
<!-- c&#45;&gt;k -->
<g id="edge25" class="edge">
<title>c-&gt;k</title>
<path fill="none" stroke="#0000ff" d="M293,-143.8314C293,-136.131 293,-126.9743 293,-118.4166"/>
<polygon fill="#0000ff" stroke="#0000ff" points="296.5001,-118.4132 293,-108.4133 289.5001,-118.4133 296.5001,-118.4132"/>
</g>
<!-- r&#45;&gt;a -->
<g id="edge6" class="edge">
<title>r-&gt;a</title>
<path fill="none" stroke="#ff0000" d="M65.8989,-103.4802C40.8794,-127.6255 0,-180.7254 0,-234 0,-378 0,-378 0,-378 0,-429.0414 40.9609,-477.103 70.1164,-502.7368"/>
<polygon fill="#ff0000" stroke="#ff0000" points="68.0778,-505.5956 77.9829,-509.356 72.5847,-500.2395 68.0778,-505.5956"/>
</g>
<!-- r&#45;&gt;a -->
<g id="edge29" class="edge">
<title>r-&gt;a</title>
<path fill="none" stroke="#0000ff" d="M73.9659,-107.1234C55.0789,-132.6831 18,-183.2623 18,-234 18,-378 18,-378 18,-378 18,-426.208 54.5396,-471.7579 78.4259,-498.264"/>
<polygon fill="#0000ff" stroke="#0000ff" points="76.0448,-500.8465 85.3782,-505.8604 81.2087,-496.1205 76.0448,-500.8465"/>
</g>
<!-- t -->
<g id="node9" class="node">
<title>t</title>
<ellipse fill="none" stroke="#000000" cx="221" cy="-18" rx="27" ry="18"/>
<text text-anchor="middle" x="221" y="-13.8" font-family="Times,serif" font-size="14.00" fill="#000000">t</text>
</g>
<!-- r&#45;&gt;t -->
<g id="edge11" class="edge">
<title>r-&gt;t</title>
<path fill="none" stroke="#0000ff" d="M105.4063,-78.75C128.3289,-66.7031 164.8884,-47.4893 190.7466,-33.8996"/>
<polygon fill="#0000ff" stroke="#0000ff" points="192.5203,-36.9214 199.7441,-29.171 189.2638,-30.725 192.5203,-36.9214"/>
</g>
<!-- f&#45;&gt;o -->
<g id="edge9" class="edge">
<title>f-&gt;o</title>
<path fill="none" stroke="#ff0000" d="M243.7307,-434.7307C233.803,-424.803 220.6847,-411.6847 209.5637,-400.5637"/>
<polygon fill="#ff0000" stroke="#ff0000" points="211.7933,-397.8436 202.2473,-393.2473 206.8436,-402.7933 211.7933,-397.8436"/>
</g>
<!-- f&#45;&gt;t -->
<g id="edge8" class="edge">
<title>f-&gt;t</title>
<path fill="none" stroke="#0000ff" d="M280.632,-439.0258C317.8397,-418.4319 390,-370.2146 390,-306 390,-306 390,-306 390,-162 390,-91.8588 304.6159,-48.6765 255.2291,-29.5661"/>
<polygon fill="#0000ff" stroke="#0000ff" points="256.1666,-26.18 245.5741,-25.9581 253.7162,-32.7372 256.1666,-26.18"/>
</g>
<!-- j -->
<g id="node10" class="node">
<title>j</title>
<ellipse fill="none" stroke="#000000" cx="115" cy="-450" rx="27" ry="18"/>
<text text-anchor="middle" x="115" y="-445.8" font-family="Times,serif" font-size="14.00" fill="#000000">j</text>
</g>
<!-- j&#45;&gt;o -->
<g id="edge12" class="edge">
<title>j-&gt;o</title>
<path fill="none" stroke="#ff0000" d="M130.2693,-434.7307C140.197,-424.803 153.3153,-411.6847 164.4363,-400.5637"/>
<polygon fill="#ff0000" stroke="#ff0000" points="167.1564,-402.7933 171.7527,-393.2473 162.2067,-397.8436 167.1564,-402.7933"/>
</g>
<!-- h&#45;&gt;n -->
<g id="edge14" class="edge">
<title>h-&gt;n</title>
<path fill="none" stroke="#0000ff" d="M206.8771,-105.7156C198.7465,-115.8532 189.3099,-129.7653 185,-144 171.306,-189.2281 176.4476,-244.8657 181.6,-277.7697"/>
<polygon fill="#0000ff" stroke="#0000ff" points="178.2118,-278.7273 183.3206,-288.009 185.115,-277.5672 178.2118,-278.7273"/>
</g>
<!-- h&#45;&gt;t -->
<g id="edge21" class="edge">
<title>h-&gt;t</title>
<path fill="none" stroke="#0000ff" d="M221,-71.8314C221,-64.131 221,-54.9743 221,-46.4166"/>
<polygon fill="#0000ff" stroke="#0000ff" points="224.5001,-46.4132 221,-36.4133 217.5001,-46.4133 224.5001,-46.4132"/>
</g>
<!-- i&#45;&gt;n -->
<g id="edge16" class="edge">
<title>i-&gt;n</title>
<path fill="none" stroke="#ff0000" d="M248.1268,-250.6709C238.7655,-261.1813 225.2396,-274.8163 213.2047,-285.9207"/>
<polygon fill="#ff0000" stroke="#ff0000" points="210.6601,-283.5021 205.57,-292.7941 215.3437,-288.7044 210.6601,-283.5021"/>
</g>
<!-- i&#45;&gt;g -->
<g id="edge19" class="edge">
<title>i-&gt;g</title>
<path fill="none" stroke="#ff0000" d="M249.9945,-216.937C245.5172,-208.4537 240.0048,-198.0092 234.993,-188.513"/>
<polygon fill="#ff0000" stroke="#ff0000" points="237.9678,-186.6509 230.2048,-179.4407 231.7771,-189.9182 237.9678,-186.6509"/>
</g>
<!-- i&#45;&gt;c -->
<g id="edge24" class="edge">
<title>i-&gt;c</title>
<path fill="none" stroke="#ff0000" d="M267.2305,-216.5708C271.1979,-208.1691 276.0429,-197.9091 280.4567,-188.5623"/>
<polygon fill="#ff0000" stroke="#ff0000" points="283.7401,-189.8057 284.8453,-179.2687 277.4104,-186.8166 283.7401,-189.8057"/>
</g>
<!-- b -->
<g id="node19" class="node">
<title>b</title>
<ellipse fill="none" stroke="#000000" cx="111" cy="-162" rx="27" ry="18"/>
<text text-anchor="middle" x="111" y="-157.8" font-family="Times,serif" font-size="14.00" fill="#000000">b</text>
</g>
<!-- e&#45;&gt;b -->
<g id="edge27" class="edge">
<title>e-&gt;b</title>
<path fill="none" stroke="#ff0000" d="M111,-215.8314C111,-208.131 111,-198.9743 111,-190.4166"/>
<polygon fill="#ff0000" stroke="#ff0000" points="114.5001,-190.4132 111,-180.4133 107.5001,-190.4133 114.5001,-190.4132"/>
</g>
<!-- u -->
<g id="node14" class="node">
<title>u</title>
<ellipse fill="none" stroke="#000000" cx="331" cy="-522" rx="27" ry="18"/>
<text text-anchor="middle" x="331" y="-517.8" font-family="Times,serif" font-size="14.00" fill="#000000">u</text>
</g>
<!-- s -->
<g id="node15" class="node">
<title>s</title>
<ellipse fill="none" stroke="#000000" cx="331" cy="-450" rx="27" ry="18"/>
<text text-anchor="middle" x="331" y="-445.8" font-family="Times,serif" font-size="14.00" fill="#000000">s</text>
</g>
<!-- u&#45;&gt;s -->
<g id="edge22" class="edge">
<title>u-&gt;s</title>
<path fill="none" stroke="#0000ff" d="M331,-503.8314C331,-496.131 331,-486.9743 331,-478.4166"/>
<polygon fill="#0000ff" stroke="#0000ff" points="334.5001,-478.4132 331,-468.4133 327.5001,-478.4133 334.5001,-478.4132"/>
</g>
<!-- w -->
<g id="node16" class="node">
<title>w</title>
<ellipse fill="none" stroke="#000000" cx="259" cy="-306" rx="27" ry="18"/>
<text text-anchor="middle" x="259" y="-301.8" font-family="Times,serif" font-size="14.00" fill="#000000">w</text>
</g>
<!-- w&#45;&gt;i -->
<g id="edge23" class="edge">
<title>w-&gt;i</title>
<path fill="none" stroke="#ff0000" d="M259,-287.8314C259,-280.131 259,-270.9743 259,-262.4166"/>
<polygon fill="#ff0000" stroke="#ff0000" points="262.5001,-262.4132 259,-252.4133 255.5001,-262.4133 262.5001,-262.4132"/>
</g>
<!-- z -->
<g id="node18" class="node">
<title>z</title>
<ellipse fill="none" stroke="#000000" cx="111" cy="-306" rx="27" ry="18"/>
<text text-anchor="middle" x="111" y="-301.8" font-family="Times,serif" font-size="14.00" fill="#000000">z</text>
</g>
<!-- z&#45;&gt;e -->
<g id="edge26" class="edge">
<title>z-&gt;e</title>
<path fill="none" stroke="#ff0000" d="M111,-287.8314C111,-280.131 111,-270.9743 111,-262.4166"/>
<polygon fill="#ff0000" stroke="#ff0000" points="114.5001,-262.4132 111,-252.4133 107.5001,-262.4133 114.5001,-262.4132"/>
</g>
<!-- b&#45;&gt;r -->
<g id="edge28" class="edge">
<title>b-&gt;r</title>
<path fill="none" stroke="#ff0000" d="M104.3258,-144.2022C101.2524,-136.0064 97.5384,-126.1024 94.1305,-117.0145"/>
<polygon fill="#ff0000" stroke="#ff0000" points="97.3858,-115.7274 90.5974,-107.593 90.8315,-118.1853 97.3858,-115.7274"/>
</g>
</g>
</svg> graphviz (3).svg…]()


-**Search**
-**Autocomplete**

