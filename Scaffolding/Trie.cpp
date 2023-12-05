#include "Trie.h"
Trie::Trie() {
    //initializing an "empty" root
    root = new node('\'');
    dictionary << "about, above, abode, across, act, active, activity, add, afraid, after, again, age, ago, agree, air, all, alone, along, already, always, am, amount, an, and, angry, another, answer, any, anyone, anything, anytime, appear, apple, are, area, arm, army, around, arrive, art, as, ask, at, attack, aunt, autumn, away, baby, base, back, bad, bag, ball, bank, basket, bath, be, bean, bear, beautiful, beer, bed, bedroom, behave, before, begin, behind, bell, below, besides, best, better, between, big, bird, birth, birthday, bit, bite, black, bleed, block, blood, blow, blue, board, boat, body, boil, bone, book, border, born, borrow, both, bottle, bottom, bowl, box, boy, branch, brave, bread, break, breakfast, breathe, bridge, bright, bring, brother, brown, brush, build, burn, business, bus, busy, but, buy, by, cake, call, can, candle, cap, car, card, care, careful, careless, carry, case, cat, catch, central, century, certain, chair, chance, change, chase, cheap, cheese, chicken, child, children, chocolate, choice, choose, circle, city, class, clever, clean, clear, climb, clock, cloth, clothes, cloud, cloudy, close, coffee, coat, coin, cold, collect, colour, comb, comfortable, common, compare, come, complete, computer, condition, continue, control, cook, cool, copper, corn, corner, correct, cost, contain, count, country, course, cover, crash, cross, cry, cup, cupboard, cut, dance, dangerous, dark, daughter, day, dead, decide, decrease, deep, deer, depend, desk, destroy, develop, die, different, difficult, dinner, direction, dirty, discover, dish, direction, do, dog, door, double, down, draw, dream, dress, drink, drive, drop, dry, duck, dust, duty, each, ear, early, earn, earth, east, easy, eat, education, effect, egg, eight, either, electric, elephant, else, empty, end, enemy, enjoy, enough, enter, equal, entrance, escape, even, evening, event, ever, every, everyone, exact, everybody, examination, example, except, excited, exercise, expect, expensive, explain, extremely, eye, face, fact, fail, fall, false, family, famous, far, farm, father, fast, fat, fault, fear, feed, feel, female, fever, few, fight, fill, film, find, fine, finger, finish, fire, first, fit, five, fix, flag, flat, float, floor, flour, flower, fly, fold, food, fool, foot, football, for, force, foreign, forest, forget, forgive, fork, form, fox, four, free, freedom, freeze, fresh, friend, friendly, from, front, fruit, full, fun, funny, furniture, further, future, game, garden, gate, general, gentleman, get, gift, give, glad, glass, go, goat, god, gold, good, goodbye, grandfather, grandmother, grass, grave, great, green, grey, ground, group, grow, gun, hair, half, hall, hammer, hand, happen, happy, hard, hat, hate, have, he, head, healthy, hear, heavy, hello, help, heart, heaven, height, help, hen, her, here, hers, hide, high, hill, him, his, hit, hobby, hold, hole, holiday, home, hope, horse, hospital, hot, hotel, house, how, hundred, hungry, hour, hurry, husband, hurt, ice, idea, if, important, in, increase, inside, into, introduce, invent, iron, invite, is, island, it, its, jelly, job, join, juice, jump, just, keep, key, kill, kind, king, kitchen, kitten, knee, knife, knock, know, ladder, lady, lamp, land, large, last, late, lately, laugh, lazy, lead, leaf, learn, leave, leg, left, lend, length, less, lesson, let, letter, library, lie, life, light, like, lion, lip, list, listen, little, live, lock, lonely, long, look, lose, lot, love, low, lower, luck, machine, main, make, male, man, many, map, mark, market, marry, matter, may, me, meal, mean, measure, meat, medicine, meet, member, mention, method, middle, milk, million, mind, minute, miss, mistake, mix, model, modern, moment, money, monkey, month, moon, more, morning, most, mother, mountain, mouth, move, much, music, must, my, name, narrow, nation, nature, near, nearly, neck, need, needle, neighbour, neither, net, never, new, news, newspaper, next, nice, night, nine, no, noble, noise, none, nor, north, nose, not, nothing, notice, now, number, obey, object, ocean, of, off, offer, office, often, oil, old, on, one, only, open, opposite, or, orange, order, other, our, out, outside, over, own, page, pain, paint, pair, pan, paper, parent, park, part, partner, party, pass, past, path, pay, peace, pen, pencil, people, pepper, per, perfect, period, person, petrol, photograph, piano, pick, picture, piece, pig, pin, pink, place, plane, plant, plastic, plate, play, please, pleased, plenty, pocket, point, poison, police, polite, pool, poor, popular, position, possible, potato, pour, power, present, press, pretty, prevent, price, prince, prison, private, prize, probably, problem, produce, promise, proper, protect, provide, public, pull, punish, pupil, push, put, queen, question, quick, quiet, quite, radio, rain, rainy, raise, reach, read, ready, real, really, receive, record, red, remember, remind, remove, rent, repair, repeat, reply, report, rest, restaurant, result, return, rice, rich, ride, right, ring, rise, road, rob, rock, room, round, rubber, rude, rule, ruler, run, rush, sad, safe, sail, salt, same, sand, save, say, school, science, scissors, search, seat, second, see, seem, sell, send, sentence, serve, seven, several, sex, shade, shadow, shake, shape, share, sharp, she, sheep, sheet, shelf, shine, ship, shirt, shoe, shoot, shop, short, should, shoulder, shout, show, sick, side, signal, silence, silly, silver, similar, simple, single, since, sing, sink, sister, sit, six, size, skill, skin, skirt, sky, sleep, slip, slow, smoke, small, smell, smile, smoke, snow, so, soap, sock, soft, some, someone, something, sometimes, son, soon, sorry, sound, soup, south, space, speak, special, speed, spell, spend, spoon, sport, spread, spring, square, stamp, stand, star, start, station, stay, steal, steam, step, still, stomach, stone, stop, store, storm, story, strange, street, strong, structure, student, study, stupid, subject, substance, successful, such, sudden, sugar, suitable, summer, sun, sunny, support, sure, surprise, sweet, swim, sword, table, take, talk, tall, taste, taxi, tea, teach, team, tear, telephone, television, tell, ten, tennis, terrible, test, than, that, the, their, then, there, therefore, these, thick, thin, thing, think, third, this, though, threat, three, tidy, tie, title, to, today, toe, together, tomorrow, tonight, too, tool, tooth, top, total, touch, town, train, tram, travel, tree, trouble, true, trust, twice, try, turn, type, uncle, under, understand, unit, until, up, use, useful, usual, usually, vegetable, very, village, voice, visit, wait, wake, walk, want, warm, wash, waste, watch, water, way, we, weak, wear, weather, wedding, week, weight, welcome, well, west, wet, what, wheel, when, where, which, while, white, who, why, wide, wife, wild, will, win, wind, window, wine, winter, wire, wise, wish, with, without, woman, wonder, word, work, world, worry, worst, write, wrong, year, yes, yesterday, yet, you, young, your, zero";
}

//public insert
int Trie::insert(std::string inString) {
    //If there are multiple words in the input string
    //this calls insert for each individual word in the string
    bool many = false;
    for(int i =0; i<inString.size(); i++){
        if(inString[i] == ' '){
            many = true;
            break;
        }
    }
    //if there are multiple words in the string{
    if(many) {
        std::string str;
        //storing the string in a string stream lends to easy traversal
        std::stringstream ss(inString);
        while(ss >> str){
            if(str[str.size()-1] == ',' || str[str.size()-1] == '.')str = str.substr(0,str.size()-1);
            insert(str.substr(0,str.size()), true);
        }
    }
    //if there aren't multiple words in the string{
    else insert(inString, true);

    return 0;
}

//private insert
void Trie::insert(std::string key, bool priv) {
//     key = keyCheck(key);
    //temp will be the parent node of the current char
    node* temp = root;
    for(int i =0; i<key.size(); i++) {
        bool found = false;
        unsigned int size = 0;
        if(!(temp->subs.empty())) size = temp->subs.size();
        for(int j =0; j<size; j++){
            if(temp->subs[j]->data == key[i]){
                //if the char being added to the tree exists in the tree don't add it
                //the parent node is changed to the found char
                temp = temp->subs[j];
                found = true;
                //if the final char to be added exists in the tree tell the tree it's a word
                if(i == key.size()-1){
                    temp->word.first = true;
                    temp->word.second++;
                }
                break;
            }
        }
        //if the char doesn't exist in the tree add it
        if(!found){
            while(i<key.size()){
                temp->subs.push_back(new node(key[i]));
                temp = temp->subs[temp->subs.size()-1];
                i++;
            }
            temp->word.first = true;
            temp->word.second++;
            break;
        }
    }
}


//private String search
int Trie::strSearch(std::string value) {
    //temp is the parent node
    node* temp = root;
    for(int i =0; i<value.size(); i++) {
        bool found = false;
        for(int j =0; j<temp->subs.size(); j++){
            if(temp->subs[j]->data == value[i]){
                temp = temp->subs[j];
                found = true;
                //if the final char to be searched exists in the tree check it's a word
                if(i == value.size()-1){
                    //if the final char doesnt dictate a word return 0
                    if(!temp->word.first)return 0;
                    else return temp->word.second;
                }
                break;
            }
        }
        //if the char doesn't exist in the tree
        if(!found)return 0;
    }
    return 0;
}



void Trie::fileWrite(std::string ofname){
    //creating the DOT file
    std::ofstream os(ofname);
    os << "digraph G {" << std::endl << std::endl;
    node* temp = root;
    //callling file print for all of the first layer of the tree
    //if called with node prints a little wacky
    for(int i = 0; i< root->subs.size(); i++){
        temp = root->subs[i];
        filePrint(temp);
    }
    //putting the filePrint output into the out file
    os << stream.rdbuf();
    os << std::endl << "}";
    os.close();
}


//private print
void Trie::filePrint(node* rootNode){
    //iterating through all chars that the rootNode points too
    if (!rootNode->subs.empty())for(int i = 0; i < rootNode->subs.size(); i++) {
        std::string color = "red";
        //if the char is the last of a word the color is blue
        if(rootNode->subs[i]->word.first) color = "blue";
        stream << char(rootNode->data) << " -> " << char(rootNode->subs[i]->data) << "[color=\"" + color << "\"];" << std::endl;
        if(!rootNode->subs[i]->subs.empty()){
            //recursive step to check all nodes
            filePrint(rootNode->subs[i]);
        }
    }
}

std::vector<std::string> Trie::autoComp(std::string val) {
    //temp is the parent node
    node* temp = root;
    int valdex = val.size();
    for(int i =0; i<val.size(); i++) {
        bool found = false;
        for(int j =0; j<temp->subs.size(); j++){
            if(temp->subs[j]->data == val[i]){
                temp = temp->subs[j];
                found = true;
                if(temp->word.first && temp->subs.empty()) return {"The input text is a complete word"};
                break;
            }
        }
        //if the char doesn't exist in the tree
        if(!found){
            valdex = i;
            if(i == 0) return {};
            break;
        }
    }
    countLeaves(temp);
    compOptions = std::vector<std::string> (autoSize*2, val.substr(0,valdex));
    autoSize = 0;
    compSearch(temp, autoSize, val.substr(0,valdex));
    return compOptions;
}

void Trie::compSearch(Trie::node* rootNode, int& index, std::string prefix) {
    // Check if the current node is the end of a word
    if (rootNode->word.first) {
        compOptions[index] = prefix;
        index++;
    }

    // Iterate through all characters that the rootNode points to
    for (int i = 0; i < rootNode->subs.size(); i++) {
        std::string newPrefix = prefix + rootNode->subs[i]->data;

        // Recursive step to check all nodes
        compSearch(rootNode->subs[i], index, newPrefix);
    }
}


void Trie::countLeaves(Trie::node *rootNode) {
    //iterating through all chars that the rootNode points too
    if (!rootNode->subs.empty())for(int i = 0; i < rootNode->subs.size(); i++) {
        if(rootNode->subs[i]->word.first)autoSize++;
        if(!rootNode->subs[i]->subs.empty()){
            //recursive step to check all nodes
            countLeaves(rootNode->subs[i]);
        }
    }
}

void Trie::autoFileWrite(std::string ofname, std::vector<std::pair<std::string, std::vector<std::string>>> optionList) {
    //creating the DOT file
    std::ofstream os(ofname);
    os << "Auto-completions:" << std::endl << std::endl;
    for(int i = 0; i<optionList.size(); i++){
        std::string prefix = optionList[i].second[0].substr(0,optionList[i].first.size());
        std::string precheck = optionList[i].first;
        while(prefix != precheck){
            precheck = precheck.substr(0,precheck.size()-1);
            prefix = prefix.substr(0,prefix.size()-1);
        }
        os << optionList[i].first << " [" << prefix <<"] :" << std::endl;
        for(int j = 0; j<optionList[i].second.size(); j++){
            if(optionList[i].first != optionList[i].second[j] && optionList[i].second[j].size() > optionList[i].first.size())os << char(9) << optionList[i].second[j] << std::endl;
        }
    }
    os.close();
}

void Trie::searchFileWrite(std::string ofname, std::vector< std::pair<std::string, int> > searchList) {
    //creating the DOT file
    std::ofstream os(ofname);
    os << "Search Queries and results" << std::endl << std::endl;
    for(int i = 0; i<searchList.size(); i++){
        std::string wasIt = "not found";
        if(searchList[i].second!=0){
            wasIt = "found ";
            wasIt += std::to_string(searchList[i].second);
            wasIt += " times";
        }
        os << searchList[i].first << " was " << wasIt << std::endl;
    }
    os.close();
}
