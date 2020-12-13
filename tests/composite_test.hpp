#ifndef __COMPOSITE_TEST_HPP__
#define __COMPOSITE_TEST_HPP__

#include "gtest/gtest.h"
#include "../Composite/header/Passage.hpp"
#include "../Composite/header/Word.hpp"
#include "../Composite/header/Text.hpp"
#include "../Composite/header/TypingTest.hpp"


/* -------------------- TESTING WORD CLASS -------------------- */

/* ---------- TESTING WORD CONSTRUCTOR ---------- */
// TEST(CompositeWordConstructor, FailingTest) {
//     Text* a = new Word();
//     EXPECT_TRUE(a->check());
//     EXPECT_EQ(a->get_row(), 1);
//     EXPECT_EQ(a->get_col(), 1);
//     EXPECT_EQ(a->len(), 1);
// }

TEST(CompositeWordConstructor, Default) {
    Text* a = new Word();

    EXPECT_TRUE(a->check());
    EXPECT_EQ(a->get_row(), 0);
    EXPECT_EQ(a->get_col(), 0);
    EXPECT_EQ(a->len(), 0);
}

TEST(CompositeWordConstructor, OneWord) {
    Text* a = new Word("green");

    EXPECT_FALSE(a->check());
    EXPECT_EQ(a->get_row(), 0);
    EXPECT_EQ(a->get_col(), 0);
    EXPECT_EQ(a->len(), 5);
}

TEST(CompositeWordConstructor, PosWords) {
    Text* a = new Word("green", "green");

    EXPECT_TRUE(a->check());
    EXPECT_EQ(a->get_row(), 0);
    EXPECT_EQ(a->get_col(), 0);
    EXPECT_EQ(a->len(), 5);
}


/* ---------- TESTING WORD::CHECK() ---------- */
// TEST(CompositeWordCheck, FailingTest) {
//     Text* a = new Word(0, 0, "car", "truck");

//     EXPECT_TRUE(a->check());
// }

TEST(CompositeWordCheck, NoInput) {
    Text* a = new Word("truck");

    EXPECT_FALSE(a->check());
}

TEST(CompositeWordCheck, WordEmpty) {
    Text* a = new Word("", "banana");

    EXPECT_FALSE(a->check()); 
}

TEST(CompositeWordCheck, RefEmpty) { 
    Text* a = new Word("car", "");

    EXPECT_FALSE(a->check());
}

TEST(CompositeWordCheck, Incorrect) {
    Text* a = new Word("bat", "cat");

    EXPECT_FALSE(a->check());
}

TEST(CompositeWordCheck, Correct) {
    Text* a = new Word("calculator", "calculator");

    EXPECT_TRUE(a->check());
}

TEST(CompositeWordCheck, Punctuation) { 
    Text* a = new Word("then.", "then.");

    EXPECT_TRUE(a->check());
}

TEST(CompositeWordCheck, Case) {
    Text* a = new Word("Then.", "then.");

    EXPECT_FALSE(a->check());
}


/* ---------- TESTING WORD::LEN() ---------- */
// TEST(CompositeWordLen, FailingTest) {
//     Text* a = new Word(5, 72);

//     EXPECT_EQ(a->len(), 2);
// }

TEST(CompositeWordLen, Empty) {
    Text* a = new Word("");

    EXPECT_EQ(a->len(), 0); 
}

TEST(CompositeWordLen, Pos) {
    Text* a = new Word("hello", "hi");

    EXPECT_EQ(a->len(), 2);
}

TEST(CompositeWordLen, LargePos) {
    Text* a = new Word("amoxicilin", "amoxicilin");

    EXPECT_EQ(a->len(), 10);
}

TEST(CompositeWordLen, Punctuation) {
    Text* a = new Word("undoubtedly.", "undoubtedly.");

    EXPECT_EQ(a->len(), 12);
}

/* ---------- TESTING WORD::set_word() ---------- */
// TEST(CompositeWordSet, FailingTest) {
//     Word* a = new Word(10, 0, "", "disgusting");

//     a->set_word("disgusting");
//     EXPECT_FALSE(a->check());
// }

TEST(CompositeWordSet, Incorrect) {
    Word* a = new Word("", "nice");

    a->set_word("noce");
    EXPECT_FALSE(a->check());
}

TEST(CompositeWordSet, Correct) {
    Word* a = new Word("", "mountain");

    a->set_word("mountain");
    EXPECT_TRUE(a->check());
}

/* -------------------- END TESTING WORD CLASS -------------------- */



/* -------------------- TESTING PASSAGE CLASS -------------------- */

/* ---------- TESTING PASSAGE CONSTRUCTOR ---------- */
// TEST(CompositePassageConstructor, FailingTest) {
//     Text* a = new Passage();

//     EXPECT_EQ(a->len(), 1);
//     EXPECT_FALSE(a->check());
// }

TEST(CompositePassageConstructor, Constructor) {
    std::vector<std::string> ref = {"The", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog."};

    Passage* a = new Passage(0, 0, ref);

    EXPECT_EQ(a->len(), 36);
    EXPECT_FALSE(a->check());
}

/* ---------- TESTING PASSAGE::LEN() ---------- */

TEST(CompositePassageLen, Empty) {
    std::vector<std::string> ref = {"The", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog."};

    Passage* a = new Passage(0, 0, ref);

    EXPECT_EQ(a->len(), 36);
    EXPECT_FALSE(a->check());
}

TEST(CompositePassageLen, Incomplete) {
    std::vector<std::string> ref = {"The", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog."};

    Passage* a = new Passage(0, 0, ref);

    a->add_word("The");

    EXPECT_EQ(a->len(), 36);
    EXPECT_FALSE(a->check());   
}

TEST(CompositePassageLen, CompleteIncorrect) {
    std::vector<std::string> ref = {"The", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog."};

    Passage* a = new Passage(0, 0, ref);

    a->add_word("The");
    a->add_word("quick");    
    a->add_word("brown");    
    a->add_word("fox");    
    a->add_word("jumps");
    a->add_word("over");
    a->add_word("the");
    a->add_word("lazy");
    a->add_word("dog/");
    
    EXPECT_EQ(a->len(), 36);
    
} 

TEST(CompositePassageLen, OneLongWord) {
    std::vector<std::string> ref = {"The", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog."};

    Passage* a = new Passage(0, 0, ref);

    a->add_word("Thequickbrownfoxjumpsoverthelazydog.");
    
    EXPECT_EQ(a->len(), 36);
    
} 

/* ---------- TESTING PASSAGE::GET_CORRECT_CHARACTERS -------- */

TEST(CompositePassageCorrect, OneEmpty) {
    std::vector<std::string> ref = {"The", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog."};

    Passage* a = new Passage(0, 0, ref);

    EXPECT_EQ(a->get_correct_characters(), 0);
}

TEST(CompositePassageCorrect, OneCorrect) {
    std::vector<std::string> ref = {"The", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog."};

    Passage* a = new Passage(0, 0, ref);

    a->add_word("The");

    EXPECT_EQ(a->get_correct_characters(), 3);
}

TEST(CompositePassageCorrect, TooLong) {
    std::vector<std::string> ref = {"The", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog."};

    Passage* a = new Passage(0, 0, ref);

    a->add_word("The");
    a->add_word("quickk");

    EXPECT_EQ(a->get_correct_characters(), 3);
}

TEST(CompositePassageCorrect, TooShort) {
    std::vector<std::string> ref = {"The", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog."};

    Passage* a = new Passage(0, 0, ref);

    a->add_word("The");
    a->add_word("quic");

    EXPECT_EQ(a->get_correct_characters(), 3);
}

TEST(CompositePassageCorrect, BeforeEmpty) {
    std::vector<std::string> ref = {"The", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog."};

    Passage* a = new Passage(0, 0, ref);

    a->add_word("");
    a->add_word("quick");

    EXPECT_EQ(a->get_correct_characters(), 5);
}

TEST(CompositePassageCorrect, BeforeIncorrect) {
    std::vector<std::string> ref = {"The", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog."};

    Passage* a = new Passage(0, 0, ref);

    a->add_word("teh");
    a->add_word("quick");

    EXPECT_EQ(a->get_correct_characters(), 5);
}

TEST(CompositePassageCorrect, MiddleIncorrect) {
    std::vector<std::string> ref = {"The", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog."};

    Passage* a = new Passage(0, 0, ref);

    a->add_word("The");
    a->add_word("qucik");
    a->add_word("brown");

    EXPECT_EQ(a->get_correct_characters(), 8);
}

TEST(CompositePassageCorrect, SmallAllCorrect) {
    std::vector<std::string> ref = {"The", "quick", "brown"};

    Passage* a = new Passage(0, 0, ref);

    a->add_word("The");
    a->add_word("quick");
    a->add_word("brown");

    EXPECT_EQ(a->get_correct_characters(), 13);
}

TEST(CompositePassageCorrect, LargeAllCorrect) {
    std::vector<std::string> ref = {"The", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog."};

    Passage* a = new Passage(0, 0, ref);

    a->add_word("The");
    a->add_word("quick");    
    a->add_word("brown");    
    a->add_word("fox");    
    a->add_word("jumps");
    a->add_word("over");
    a->add_word("the");
    a->add_word("lazy");
    a->add_word("dog.");

    EXPECT_EQ(a->get_correct_characters(), 36);
}

/* ---------- TESTING PASSAGE::CHECK() ---------- */

TEST(CompositePassageCheck, Empty) {
    std::vector<std::string> ref = {"The", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog."};

    Passage* a = new Passage(0, 0, ref);

    EXPECT_FALSE(a->check());
}

TEST(CompositePassageCheck, IncompleteCorrect) {
    std::vector<std::string> ref = {"The", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog."};

    Passage* a = new Passage(0, 0, ref);

    a->add_word("The");
    a->add_word("quick");    
    a->add_word("brown");    
    a->add_word("fox");    
    a->add_word("jumps");
    a->add_word("over");
    a->add_word("the");

    EXPECT_FALSE(a->check());
}

TEST(CompositePassageCheck, IncompleteIncorrect) {
    std::vector<std::string> ref = {"The", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog."};

    Passage* a = new Passage(0, 0, ref);

    a->add_word("The");
    a->add_word("quick");    
    a->add_word("brown");    
    a->add_word("f0x");    
    a->add_word("jumps");
    a->add_word("ovver");
    a->add_word("the");

    EXPECT_FALSE(a->check());
}

TEST(CompositePassageCheck, CompleteCorrect) {
    std::vector<std::string> ref = {"The", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog."};

    Passage* a = new Passage(0, 0, ref);

    a->add_word("The");
    a->add_word("quick");    
    a->add_word("brown");    
    a->add_word("fox");    
    a->add_word("jumps");
    a->add_word("over");
    a->add_word("the");
    a->add_word("lazy");
    a->add_word("dog.");
    
    EXPECT_TRUE(a->check());
    
} 

TEST(CompositePassageCheck, CompleteIncorrect) {
    std::vector<std::string> ref = {"The", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog."};

    Passage* a = new Passage(0, 0, ref);

    a->add_word("Teh");
    a->add_word("quock");    
    a->add_word("brpwn");    
    a->add_word("fox");    
    a->add_word("jumps");
    a->add_word("over");
    a->add_word("teh");
    a->add_word("lazy");
    a->add_word("dog!");
    
    EXPECT_FALSE(a->check());
    
} 


/* -------------------- TESTING TEST CLASS -------------------- */

/* ---------- TESTING Test::get_accuracy() ----------- */

TEST(CompositeTestGetAccuracy, Empty){
    TypingTest* a = new TypingTest();
    
    std::vector<std::string> ref = {"The", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog."};

    Passage* b = new Passage(0, 0, ref);

    a->set_body(b);

    EXPECT_EQ(a->get_accuracy(), "0.00%");
}

TEST(CompositeTestGetAccuracy, Fifty){
    TypingTest* a = new TypingTest();
    
    std::vector<std::string> ref = {"Hi", "by"};

    Passage* b = new Passage(0, 0, ref);
    
    b->add_word("Hi");
    b->add_word("B");

    a->set_body(b);

    EXPECT_EQ(a->get_accuracy(), "50.00%");
}

TEST(CompositeTestGetAccuracy, RoundUp){
    TypingTest* a = new TypingTest();
    
    std::vector<std::string> ref = {"Hi", "by", "pi"};

    Passage* b = new Passage(0, 0, ref);
    
    b->add_word("Hi");
    b->add_word("B");
    b->add_word("pi");

    a->set_body(b);

    EXPECT_EQ(a->get_accuracy(), "66.66%");
}

TEST(CompositeTestGetAccuracy, RoundDown){
    TypingTest* a = new TypingTest();
    
    std::vector<std::string> ref = {"Hi", "by", "pi"};

    Passage* b = new Passage(0, 0, ref);
    
    b->add_word("Hi");
    b->add_word("B");
    b->add_word("Pi");

    a->set_body(b);

    EXPECT_EQ(a->get_accuracy(), "33.33%");
}

TEST(CompositeTestGetAccuracy, Perfect){
    TypingTest* a = new TypingTest();
    
    std::vector<std::string> ref = {"The", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog."};

    Passage* b = new Passage(0, 0, ref);

    b->add_word("The");
    b->add_word("quick");    
    b->add_word("brown");    
    b->add_word("fox");    
    b->add_word("jumps");
    b->add_word("over");
    b->add_word("the");
    b->add_word("lazy");
    b->add_word("dog.");

    a->set_body(b);

    EXPECT_EQ(a->get_accuracy(), "100.00%");
}

#endif 