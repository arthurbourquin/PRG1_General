#include <iostream>
#include <string>
#include <cctype>

#include "ch08-string.h"

using std::cout, std::endl;
using std::string;

namespace ch08_string {
    void s01Char(){
        // Display char
        cout << 'A' << " " << (int) 'A' << endl;
        cout << '0' << " " << (int) '0' << ", " << '1' << " " << (int) '1' << endl;
        cout << char ('0' + 1) << " " << '0' + 1 << endl;
        cout << (int) '\n' << endl;

        for(char c = '0'; c <= '9' ; c++){
            cout << c - '0' << ", ";
        }
        cout << endl;

        // print special characters
        cout << "\\ \' \"" << endl;

        cout << std::boolalpha;

        //cctype - isalnum
        cout << "\nisalnum : " << endl;
        cout << "isalnum('a') = " << (bool) isalnum('a') << endl;
        cout << "isalnum('5') = " << (bool) isalnum('5') << endl;
        cout << "isalnum('?') = " << (bool) isalnum('?') << endl;

        cout << "\nisalpha : " << endl;
        cout << "isalpha('a') = " << (bool) isalpha('a') << endl;
        cout << "isalpha('5') = " << (bool) isalpha('5') << endl;
        cout << "isalpha('A') = " << (bool) isalpha('A') << endl;

        cout << "\niscntrl : " << endl;
        cout << "iscntrl('a') = " << (bool) iscntrl('a') << endl;
        cout << "iscntrl('5') = " << (bool) iscntrl('5') << endl;
        cout << "iscntrl('\\n') = " << (bool) iscntrl('\n') << endl;

        cout << "\nisdigit : " << endl;
        cout << "isdigit('a') = " << (bool) isdigit('a') << endl;
        cout << "isdigit('5') = " << (bool) isdigit('5') << endl;
        cout << "isdigit('\\n') = " << (bool) isdigit('\n') << endl;

        cout << "\nisxdigit : " << endl;
        cout << "isxdigit('a') = " << (bool) isxdigit('a') << endl;
        cout << "isxdigit('5') = " << (bool) isxdigit('5') << endl;
        cout << "isxdigit('g') = " << (bool) isxdigit('g') << endl;

        cout << "\nisgraph : " << endl;
        cout << "isgraph('a') = " << (bool) isgraph('a') << endl;
        cout << "isgraph('5') = " << (bool) isgraph('5') << endl;
        cout << "isgraph(' ') = " << (bool) isgraph(' ') << endl;

        cout << "\nisprint : " << endl;
        cout << "isprint('a') = " << (bool) isprint('a') << endl;
        cout << "isprint('5') = " << (bool) isprint('5') << endl;
        cout << "isprint(' ') = " << (bool) isprint(' ') << endl;

        cout << "\nislower : " << endl;
        cout << "islower('a') = " << (bool) islower('a') << endl;
        cout << "islower('A') = " << (bool) islower('A') << endl;

        cout << "\nisupper : " << endl;
        cout << "isupper('a') = " << (bool) isupper('a') << endl;
        cout << "isupper('A') = " << (bool) isupper('A') << endl;

        cout << "\nispunct : " << endl; //isgraph = true et isalnum = false
        cout << "ispunct('a') = " << (bool) ispunct('a') << endl;
        cout << "ispunct('(') = " << (bool) ispunct('(') << endl;

        cout << "\nisspace : " << endl;
        cout << "isspace('a') = " << (bool) isspace('a') << endl;
        cout << "isspace(' ') = " << (bool) isspace(' ') << endl;
        cout << "isspace('\\n') = " << (bool) isspace('\n') << endl;

        cout << "\nisblank : " << endl;
        cout << "isblank('a') = " << (bool) isblank('a') << endl;
        cout << "isblank(' ') = " << (bool) isblank(' ') << endl;
        cout << "isblank('\\n') = " << (bool) isblank('\n') << endl;

        cout << "\ntolower, toupper : " << endl;
        cout << "tolower('A') = " << (char) tolower('A') << endl;
        cout << "toupper('a') = " << (char) toupper('a') << endl;
        cout << "tolower('(') = " << (char) tolower('(') << endl;

        cout << endl << sectionSep << endl;

    }

    void s02String01(){
        // string constructors

        cout << "\nstring constructeurs : " << endl;
        string s1 = "Hello, World!";
        cout << "s1 : " << s1 << endl;
        
        string s2(s1);
        cout << "s2 : " << s2 << endl;        

        string s5(10, 'F');
        cout << "s5 : " << s5 << ", length : " << s5.length() << endl;

        string s6("Hello, World!", 5); // number of characters to copy from the start of s1
        cout << "s6 : " << s6 << ", length : " << s6.length() << endl;

        string s7(s1, 5); // position of the first character to copy from s1
        cout << "s7 : " << s7 << ", length : " << s7.length() << endl;

        string s8(s1, 7, 5); // position of the first character to copy from s1 and number of characters to copy
        cout << "s8 : " << s8 << ", length : " << s8.length() << endl;

        cout << endl << sectionSep << endl;


    }

    void s02String02(){
        // =, assign

        cout << "\naffectation (=) : " << endl;
        //string s1 = 'a'; //uncomment to see the effect
        string s2;
        s2 = 'a';
        cout << "s2 : " << s2 << endl;

        string s3, s4;
        s3 = "Hello, World!";
        s4 = s3;
        cout << "s3 : " << s3 << endl;
        cout << "s4 : " << s4 << endl;

        cout << "\naffectation (assign) : " << endl;
        string s5, s6, s7, s8,
                world("World!"),
                hw("Hello, World!");
        s5.assign(world);
        s6.assign(hw, 7, 6);
        s7.assign("World!");
        s8.assign("World!!!!", 6);
        cout << "s5 : " << s5 << endl;
        cout << "s6 : " << s6 << endl;
        cout << "s7 : " << s7 << endl;
        cout << "s8 : " << s8 << endl;

        string s9;
        s9.assign(6, 'W');
        cout << "s9 : " << s9 << endl;


        cout << endl << sectionSep << endl;
    }

    void s02String03(){
        // +, +=, append

        cout << "\nConcatenation (+) : " << endl;
        string s;
        string s1("Hello, ");
        string s2("World!");
        s = s1 + s2;
        cout << "s : " << s << endl;

        s = "Hello, " + s2;
        cout << "s : " << s << endl;
        s = s1 + "World!";
        cout << "s : " << s << endl;

        //s = "Hello, " + "World!"; //uncomment to see the effect

        s = s1 + 'F';
        cout << "s1 : " << s1 << ",s1 + 'F' : " << s << endl;

        cout << "\nConcatenation (+=) : " << endl;
        string str("Hello");
        cout << "str : " << str << endl;
        str += ',';       // equivalent to str = str + ',';
        cout << "str += ',' : " << str << endl;
        str += " World!"; // equivalent to str = str + " World!";
        cout << "str += \" World!\" : " << str << endl;

        cout << "\nConcatenation (append) : " << endl;
        string s5, s6, s7, s8,
                world("World!"),
                hw("Hello, World!");
        s5.append(world);
        s6.append(hw, 7, 6);
        s7.append("World!");
        s8.append("World!!!!", 6);
        cout << "s5 : " << s5 << endl;
        cout << "s6 : " << s6 << endl;
        cout << "s7 : " << s7 << endl;
        cout << "s8 : " << s8 << endl;

        string s9;
        s9.assign(6, 'W');
        cout << "s9 : " << s9 << endl;


        cout << endl << sectionSep << endl;
    }

    void s02String04(){
        // [], at, length, size, empty, resize, substr, insert

        cout << "\nAcces aux caracteres : " << endl;
        string s = "0123456789";
        cout << "s : " << s << endl;
        cout << "s[3] : " << s[3] << ", s.at(3) : " << s.at(3) << endl;
        s[3] = '0';
        cout << "s : "  << s << endl;

        cout << "\nTaille - empty : " << endl;
        s = "0123456789";
        cout << "s : "  << s << endl;
        cout << "s.length() : "  << s.length() << ", s.size() : "  << s.size() << endl;

        string sEmpty;
        cout << std::boolalpha << "s.empty() : " << s.empty() << ", sEmpty.empty() : " << sEmpty.empty() << endl;

        cout << "\nresize : " << endl;
        s = "0123456789";
        cout << "s : "  << s << endl;
        s.resize(11, '!');
        cout << "s : "  << s << endl;
        s.resize(4);
        cout << "s : "  << s << endl;
        s.resize(6);
        cout << "s : "  << s << endl;

        cout << "\nsubstr : " << endl;
        s = "0123456789";
        cout << "s : "  << s << endl;
        string sub;

        sub = s.substr(0, 5);
        cout << "sub : "  << sub << endl;
        sub = s.substr(3, 4);
        cout << "sub : "  << sub << endl;
        sub = s.substr(7);
        cout << "sub : "  << sub << endl;
        sub = s.substr();
        cout << "sub : "  << sub << endl;

        cout << "\ninsert : " << endl;
        s = "0123456789";
        string str2 = "---";
        string str3 = "!****!!!";
        cout << "s : "  << s << endl;

        s.insert(4, str2);
        cout << "s : "  << s << endl;
        s.insert(9, str3, 1, 4);
        cout << "s : "  << s << endl;
        s.insert(0, "##$$$$$$", 2);
        cout << "s : "  << s << endl;
        s.insert(0, "$$$$-");
        cout << "s : "  << s << endl;
        s.insert(s.length()-1, 5, ':');
        cout << "s : "  << s << endl;
        s.insert(s.length(), 2, '=');
        cout << "s : "  << s << endl;


        cout << endl << sectionSep << endl;
    }

    void s02String05(){
        // replace, clear, erase, sequence

        cout << "\nreplace : " << endl;
        string base = "0123456789";
        string str2 = "***";
        string str3 = "----";
        string str4 = "01234";

        string s = base;
        cout << "s : "  << s << endl;
        s.replace(5, 3, str2);
        cout << "s : "  << s << endl;
        s.replace(5, 3, str3);
        cout << "s : "  << s << endl;
        s.replace(6, 2, str4, 2, 3);
        cout << "s : "  << s << endl;
        s.replace(6, 3, 2, '!');
        cout << "s : "  << s << endl;


        cout << "\nclear : " << endl;
        cout << "s : "  << s << ", s.legnth : " << s.length() << endl;
        s.clear();
        cout << "s : "  << s << ", s.legnth : " << s.length() << endl;

        cout << "\nerase : " << endl;
        s = "0123456789";
        cout << "s : "  << s << ", s.legnth : " << s.length() << endl;
        s.erase(5, 3);
        cout << "s : "  << s << ", s.legnth : " << s.length() << endl;
        s.erase(3);
        cout << "s : "  << s << ", s.legnth : " << s.length() << endl;


        cout << "\nsequence : " << endl;
        s = "0123456789";
        cout << "s : "  << s << endl;
        cout << "s.erase(0, 3).append(\"aaa\") : " << s.erase(0, 3).append("aaa") << endl;


        cout << endl << sectionSep << endl;
    }

    void s02String06(){
        // find, rfind, find_first_of, find_last_of, find_first_not_of, find_last_not_of

        cout << "\nfind : " << endl;
        string s("There are two needles in this haystack with needles.");
        string s2("needle");

        cout << "s : "  << s << endl;
        size_t first_needle   = s.find(s2);
        if(first_needle != string::npos){
            cout << "First needle was found at pos : " << first_needle << endl;
        }else{
            cout << "First needle was not found" << endl;
        }
        size_t second_needle  = s.find(s2, first_needle + 1);
        if(second_needle != string::npos){
            cout << "Second needle was found at pos : " << second_needle << endl;
        }else{
            cout << "Second needle was not found" << endl;
        }
        size_t find_sky = s.find("sky");
        if(find_sky != string::npos){
            cout << "Sky was found at pos : " << find_sky << endl;
        }else{
            cout << "Sky was not found" << endl;
        }

        first_needle = s.find("needles are small", 0, 6);
        if(first_needle != string::npos){
            cout << "First needle was found at pos : " << first_needle << endl;
        }else{
            cout << "First needle was not found" << endl;
        }
        second_needle = s.find("needles are small", first_needle + 1, 6);
        if(second_needle != string::npos){
            cout << "Second needle was found at pos : " << second_needle << endl;
        }else{
            cout << "Second needle was not found" << endl;
        }
        size_t find_are = s.find("are you here", 0, 3);
        if(find_are != string::npos){
            cout << "Are was found at pos : " << find_are << endl;
        }else{
            cout << "Are was not found" << endl;
        }

        size_t first_point    = s.find('.');
        if(first_point != string::npos){
            cout << "first_point was found at pos : " << first_point << endl;
        }else{
            cout << "first_point was not found" << endl;
        }

        second_needle  = s.rfind(s2);
        if(second_needle != string::npos){
            cout << "Using rfind, Second needle was found at pos : " << second_needle << endl;
        }else{
            cout << "Second needle was not found" << endl;
        }

        s.replace(s.find(s2), s2.length(), "preposition");
        cout << "s : "  << s << endl;



        cout << "\nfind_first_of : " << endl;
        s = string("Hello World!");
        string vowels = string("aeiouyAEIOUY"); // voyelles

        cout << "s : "  << s << endl;
        size_t first_vowel = s.find_first_of(vowels);
        cout << "Staring from position 0, first vowel is found at : " << first_vowel << endl;
        cout << "next vowel is found at : " << s.find_first_of(vowels, first_vowel + 1) << endl;
        cout << "s.find_first_of(\"Good Bye!\") : " << s.find_first_of("Good Bye!") << endl;
        cout << "s.find_first_of(\"Good Bye!\", 0, 4) : " << s.find_first_of("Good Bye!", 0, 4) << endl;
        cout << "<< s.find_first_of('x') : " << s.find_first_of('x') << endl;


        cout << "\nfind_first_not_of : " << endl;
        s = "recherche de caracteres non-alphabetiques ...";
        size_t found = s.find_first_not_of("abcdefghijklmnopqrstuvwxyz ");

        cout << "Le premier caractere non-alphabetique est "
             << s.at(found)
             << " a la position "
             << found << endl;


        cout << endl << sectionSep << endl;
    }
    void s02String07(){
        // <, >, <=, >=, ==, !=
        string s1 = "Hello";
        string s2 = "Hello";
        string s3 = "hello";
        string s4 = "Hello 1";
        string s5 = "Hel";

        cout << "\n<, >, <=, >=, == : " << endl;
        cout << "s1 : "  << s1 << endl;
        cout << "s2 : "  << s2 << endl;
        cout << "s3 : "  << s3 << endl;
        cout << "s4 : "  << s4 << endl;
        cout << "s5 : "  << s5 << endl;
        cout << std::boolalpha
                << "(s1 == s2) : " << (s1 == s2) << ", (s1 == s3) : " << (s1 == s3) << ", (s1 < s3) : " << (s1 < s3)
                << " (s1 <= s4) : " << (s1 <= s4) << ", (s1 > s5) : " << (s1 > s5)
                << std::noboolalpha << endl;


        cout << endl << sectionSep << endl;
    }

}