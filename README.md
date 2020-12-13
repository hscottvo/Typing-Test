# An Efficient Code Typing Trainer
 
Authors: [Scott Vo](https://github.com/hscottvo), [Danin Namiranian](https://github.com/Danin1993), [Brian Arciga](https://github.com/brianarciga1)

## Project Description
* Typing is an essential skill in today's technology-based society, especially to people who type for a living. The first thing that comes to mind with the thought of "professional typist" is programming. As a programmer, be it in C++ or SQL, typing is the most important interface between a programmer and their computer. Typing efficiency is important to programmers because they need to be efficient in writing code, and finding the where each letter is on a keyboard should be the least of their worries. 
  * There will be choices of text in the form of a set of random words, or a paragraph or quote. The test material will be pulled from a local database. 
  * Typing tests will record the time that the user takes to finish typing everything. It then takes the total number of characters in the correctly typed words, and calculates words per minute (WPM). A word is calculated as 5 characters in this test. 
### Technologies
[C++](https://www.cplusplus.com/) is our main programming language.  
[Git](https://git-scm.com/) is our version control software.  
[ncurses](https://pubs.opengroup.org/onlinepubs/7908799/xcurses/curses.h.html) is our main input/output tool, taking in key presses, then refreshing and outputting text in a window.  
[Vim](https://www.vim.org/) is our low-level text editor.  
[Visual Studio Code](https://code.visualstudio.com/) is our high-level text editor.  
[CMake](https://cmake.org/) is used to generate Makefiles.  
[Google Test Framework](https://github.com/google/googletest) is the main unit testing tool we are using. 

### Design Patterns
* The input will be the keypresses of the user. The output will be the words that the user types, in colors depending on the correctness of the user's input. 
* We intend to use the Composite, Observer and Strategy design patterns for the project. 
  * Composite will be useful to manage the multiple components that will be a part of the test, such as the text material window, timer, and key input. 
    * An Initializer object will be the main running loop of the program. It will instantiate Typing Tests with settings based on what the user has set beforehand. 
    * Text classes will handle the storage of test material and validating user inputs when compared to the material. 
    * UserList will hold a vector of Users to interface with the Observer class.
    * TypingTest will use the classes from the Strategy pattern to retrieve passages for the user to type.
  * Strategy pattern will be used to read and display typing material. 
    * There will be at least 3 main strategies, creating typing material with:
      1. Quotes
      2. Paragraphs
      3. A collection of random words
  * Observer will be used to keep track of users on a leader board. Users will be ranked based on their typing efficiency.
    * There would be three main functions. Users will have the option to add and reset their scores.
    * Users should also be able to return the score for the top users.
    * A leaderboard object would contain child Score (name TBD) objects and would change and return results based on test results and score queries.

## Class Diagram

<img src="https://docs.google.com/drawings/d/e/2PACX-1vSwanho9HYGWpyReDs0W0ro39obf76mRsjeyf73z6PT0jZE5E_Qc7GBUylH1muTeXfJJjXDmGRLVoDr/pub?w=2552&amp;h=1644">

 ## Screenshots
![Typing Gameplay - Incorrect words are highlighted](https://user-images.githubusercontent.com/56327086/101737483-caa1fe80-3a79-11eb-80dc-e40c713de45a.JPG)
![Test Results](https://user-images.githubusercontent.com/56327086/101737106-48193f00-3a79-11eb-9926-380cafc8cfb0.JPG)
![User Login](https://user-images.githubusercontent.com/56327086/101737319-8d3d7100-3a79-11eb-9490-8b9f399d4da8.JPG)

 ## Installation/Usage
First, clone the repository using git, then use ```cd``` to move into the repo. 
``` 
git clone https://github.com/cs100/final-project-svo021-dnami001-barci003.git
cd final-project-svo021-dnami001-barci003
```
To build and compile: 
  In your terminal, install the [ncurses](https://pubs.opengroup.org/onlinepubs/7908799/xcurses/curses.h.html) library by entering the command:  
  <code>sudo apt-get install libncurses5-dev libncursesw5-dev</code>  
  Then enter the commands:  
  <code> cmake .</code>  
  <code> make </code>  
To run the existing executable, enter the command:  
  <code>./TypingTest</code>  
and follow the instructions. 
 ## Testing
 Testing for non-void functions was done using GoogleTest. For features handling the program's GUI, the developer manually checked for bugs on normal, edge, and corner cases. 
 <details><summary> GoogleTest output </summary>
 <p>
```./test  
[==========] Running 65 tests from 16 test suites.  
[----------] Global test environment set-up.  
[----------] 3 tests from CompositeWordConstructor  
[ RUN      ] CompositeWordConstructor.Default  
[       OK ] CompositeWordConstructor.Default (0 ms)  
[ RUN      ] CompositeWordConstructor.OneWord  
[       OK ] CompositeWordConstructor.OneWord (0 ms)  
[ RUN      ] CompositeWordConstructor.PosWords  
[       OK ] CompositeWordConstructor.PosWords (0 ms)  
[----------] 3 tests from CompositeWordConstructor (1 ms total)  
  
[----------] 7 tests from CompositeWordCheck  
[ RUN      ] CompositeWordCheck.NoInput  
[       OK ] CompositeWordCheck.NoInput (0 ms)  
[ RUN      ] CompositeWordCheck.WordEmpty  
[       OK ] CompositeWordCheck.WordEmpty (0 ms)  
[ RUN      ] CompositeWordCheck.RefEmpty  
[       OK ] CompositeWordCheck.RefEmpty (0 ms)  
[ RUN      ] CompositeWordCheck.Incorrect  
[       OK ] CompositeWordCheck.Incorrect (0 ms)  
[ RUN      ] CompositeWordCheck.Correct  
[       OK ] CompositeWordCheck.Correct (0 ms)  
[ RUN      ] CompositeWordCheck.Punctuation  
[       OK ] CompositeWordCheck.Punctuation (0 ms)  
[ RUN      ] CompositeWordCheck.Case  
[       OK ] CompositeWordCheck.Case (0 ms)  
[----------] 7 tests from CompositeWordCheck (0 ms total)  
  
[----------] 4 tests from CompositeWordLen  
[ RUN      ] CompositeWordLen.Empty  
[       OK ] CompositeWordLen.Empty (0 ms)  
[ RUN      ] CompositeWordLen.Pos  
[       OK ] CompositeWordLen.Pos (0 ms)  
[ RUN      ] CompositeWordLen.LargePos  
[       OK ] CompositeWordLen.LargePos (0 ms)  
[ RUN      ] CompositeWordLen.Punctuation  
[       OK ] CompositeWordLen.Punctuation (0 ms)  
[----------] 4 tests from CompositeWordLen (0 ms total)  
  
[----------] 2 tests from CompositeWordSet  
[ RUN      ] CompositeWordSet.Incorrect  
[       OK ] CompositeWordSet.Incorrect (0 ms)  
[ RUN      ] CompositeWordSet.Correct  
[       OK ] CompositeWordSet.Correct (0 ms)  
[----------] 2 tests from CompositeWordSet (0 ms total)  
  
[----------] 1 test from CompositePassageConstructor  
[ RUN      ] CompositePassageConstructor.Constructor  
[       OK ] CompositePassageConstructor.Constructor (0 ms)  
[----------] 1 test from CompositePassageConstructor (0 ms total)  
  
[----------] 4 tests from CompositePassageLen  
[ RUN      ] CompositePassageLen.Empty  
[       OK ] CompositePassageLen.Empty (0 ms)  
[ RUN      ] CompositePassageLen.Incomplete  
[       OK ] CompositePassageLen.Incomplete (0 ms)  
[ RUN      ] CompositePassageLen.CompleteIncorrect  
[       OK ] CompositePassageLen.CompleteIncorrect (0 ms)  
[ RUN      ] CompositePassageLen.OneLongWord  
[       OK ] CompositePassageLen.OneLongWord (0 ms)  
[----------] 4 tests from CompositePassageLen (1 ms total)  
  
[----------] 9 tests from CompositePassageCorrect  
[ RUN      ] CompositePassageCorrect.OneEmpty  
[       OK ] CompositePassageCorrect.OneEmpty (0 ms)  
[ RUN      ] CompositePassageCorrect.OneCorrect  
[       OK ] CompositePassageCorrect.OneCorrect (0 ms)  
[ RUN      ] CompositePassageCorrect.TooLong  
[       OK ] CompositePassageCorrect.TooLong (0 ms)  
[ RUN      ] CompositePassageCorrect.TooShort  
[       OK ] CompositePassageCorrect.TooShort (0 ms)  
[ RUN      ] CompositePassageCorrect.BeforeEmpty  
[       OK ] CompositePassageCorrect.BeforeEmpty (0 ms)  
[ RUN      ] CompositePassageCorrect.BeforeIncorrect  
[       OK ] CompositePassageCorrect.BeforeIncorrect (0 ms)  
[ RUN      ] CompositePassageCorrect.MiddleIncorrect  
[       OK ] CompositePassageCorrect.MiddleIncorrect (0 ms)  
[ RUN      ] CompositePassageCorrect.SmallAllCorrect  
[       OK ] CompositePassageCorrect.SmallAllCorrect (0 ms)  
[ RUN      ] CompositePassageCorrect.LargeAllCorrect  
[       OK ] CompositePassageCorrect.LargeAllCorrect (0 ms)  
[----------] 9 tests from CompositePassageCorrect (0 ms total)  
  
[----------] 5 tests from CompositePassageCheck  
[ RUN      ] CompositePassageCheck.Empty  
[       OK ] CompositePassageCheck.Empty (0 ms)  
[ RUN      ] CompositePassageCheck.IncompleteCorrect  
[       OK ] CompositePassageCheck.IncompleteCorrect (0 ms)  
[ RUN      ] CompositePassageCheck.IncompleteIncorrect  
[       OK ] CompositePassageCheck.IncompleteIncorrect (0 ms)  
[ RUN      ] CompositePassageCheck.CompleteCorrect  
[       OK ] CompositePassageCheck.CompleteCorrect (0 ms)  
[ RUN      ] CompositePassageCheck.CompleteIncorrect  
[       OK ] CompositePassageCheck.CompleteIncorrect (0 ms)  
[----------] 5 tests from CompositePassageCheck (1 ms total)  
  
[----------] 5 tests from CompositeTestGetAccuracy  
[ RUN      ] CompositeTestGetAccuracy.Empty  
[       OK ] CompositeTestGetAccuracy.Empty (0 ms)  
[ RUN      ] CompositeTestGetAccuracy.Fifty  
[       OK ] CompositeTestGetAccuracy.Fifty (0 ms)  
[ RUN      ] CompositeTestGetAccuracy.RoundUp  
[       OK ] CompositeTestGetAccuracy.RoundUp (0 ms)  
[ RUN      ] CompositeTestGetAccuracy.RoundDown  
[       OK ] CompositeTestGetAccuracy.RoundDown (0 ms)  
[ RUN      ] CompositeTestGetAccuracy.Perfect  
[       OK ] CompositeTestGetAccuracy.Perfect (0 ms)  
[----------] 5 tests from CompositeTestGetAccuracy (1 ms total)  
  
[----------] 2 tests from STG_Test_Language  
[ RUN      ] STG_Test_Language.English  
[       OK ] STG_Test_Language.English (0 ms)  
[ RUN      ] STG_Test_Language.Spanish  
[       OK ] STG_Test_Language.Spanish (0 ms)  
[----------] 2 tests from STG_Test_Language (0 ms total)  
  
[----------] 2 tests from STG_Test_DataBase  
[ RUN      ] STG_Test_DataBase.getDataBaseSuccess  
[       OK ] STG_Test_DataBase.getDataBaseSuccess (0 ms)  
[ RUN      ] STG_Test_DataBase.getDataBaseFaild  
[       OK ] STG_Test_DataBase.getDataBaseFaild (1 ms)  
[----------] 2 tests from STG_Test_DataBase (1 ms total)  
  
[----------] 6 tests from STG_Test_ParagraphGenerator  
[ RUN      ] STG_Test_ParagraphGenerator.normalIndex  
[       OK ] STG_Test_ParagraphGenerator.normalIndex (0 ms)  
[ RUN      ] STG_Test_ParagraphGenerator.outIndex0  
[       OK ] STG_Test_ParagraphGenerator.outIndex0 (1 ms)  
[ RUN      ] STG_Test_ParagraphGenerator.outIndex1  
[       OK ] STG_Test_ParagraphGenerator.outIndex1 (2 ms)  
[ RUN      ] STG_Test_ParagraphGenerator.outIndex2
[       OK ] STG_Test_ParagraphGenerator.outIndex2 (1 ms)  
[ RUN      ] STG_Test_ParagraphGenerator.size1  
[       OK ] STG_Test_ParagraphGenerator.size1 (0 ms)  
[ RUN      ] STG_Test_ParagraphGenerator.size2  
[       OK ] STG_Test_ParagraphGenerator.size2 (0 ms)  
[----------] 6 tests from STG_Test_ParagraphGenerator (4 ms total)  
  
[----------] 8 tests from STG_Test_QuoteGenerator  
[ RUN      ] STG_Test_QuoteGenerator.normalIndex0  
[       OK ] STG_Test_QuoteGenerator.normalIndex0 (0 ms)  
[ RUN      ] STG_Test_QuoteGenerator.normalIndex1  
[       OK ] STG_Test_QuoteGenerator.normalIndex1 (1 ms)  
[ RUN      ] STG_Test_QuoteGenerator.normalIndex2  
[       OK ] STG_Test_QuoteGenerator.normalIndex2 (0 ms)  
[ RUN      ] STG_Test_QuoteGenerator.outIndex0  
[       OK ] STG_Test_QuoteGenerator.outIndex0 (1 ms)  
[ RUN      ] STG_Test_QuoteGenerator.outIndex1  
[       OK ] STG_Test_QuoteGenerator.outIndex1 (1 ms)  
[ RUN      ] STG_Test_QuoteGenerator.outIndex2  
[       OK ] STG_Test_QuoteGenerator.outIndex2 (1 ms)  
[ RUN      ] STG_Test_QuoteGenerator.size1  
[       OK ] STG_Test_QuoteGenerator.size1 (0 ms)  
[ RUN      ] STG_Test_QuoteGenerator.size2  
[       OK ] STG_Test_QuoteGenerator.size2 (0 ms)  
[----------] 8 tests from STG_Test_QuoteGenerator (5 ms total)   
  
[----------] 3 tests from STG_Test_WordSetGenerator  
[ RUN      ] STG_Test_WordSetGenerator.outIndex0  
[       OK ] STG_Test_WordSetGenerator.outIndex0 (1 ms)  
[ RUN      ] STG_Test_WordSetGenerator.outIndex1  
[       OK ] STG_Test_WordSetGenerator.outIndex1 (1 ms)  
[ RUN      ] STG_Test_WordSetGenerator.outIndex2  
[       OK ] STG_Test_WordSetGenerator.outIndex2 (0 ms)  
[----------] 3 tests from STG_Test_WordSetGenerator (2 ms total)  
  
[----------] 1 test from IObserver  
[ RUN      ] IObserver.AddUser  
[       OK ] IObserver.AddUser (0 ms)  
[----------] 1 test from IObserver (0 ms total)  
  
[----------] 3 tests from Observer  
[ RUN      ] Observer.AddUser2  
[       OK ] Observer.AddUser2 (0 ms)  
[ RUN      ] Observer.AddUser3  
[       OK ] Observer.AddUser3 (0 ms)  
[ RUN      ] Observer.AddUser4  
[       OK ] Observer.AddUser4 (0 ms)  
[----------] 3 tests from Observer (0 ms total)  
  
[----------] Global test environment tear-down  
[==========] 65 tests from 16 test suites ran. (16 ms total)  
[  PASSED  ] 65 tests.```
