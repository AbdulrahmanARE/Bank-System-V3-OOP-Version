#pragma once

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class clsString
{

private:
    string _Value;

public:

    clsString()
    {

        _Value = "";
    }

    clsString(string Value)
    {

        _Value = Value;
    }


    void SetValue(string Value) {
        _Value = Value;
    }

    string GetValue() {
        return _Value;
    }
    __declspec(property(get = GetValue, put = SetValue)) string Value;

    static short Length(string S1)
    {
        return S1.length();
    };

    short Length()
    {
        return _Value.length();
    };

    static string UpperAllString(string S1)
    {
        for (short i = 0; i < S1.length(); i++) {
            S1[i] = toupper(S1[i]);
        }
        return S1;
    }

    void UpperAllString() {
        _Value = UpperAllString(_Value);
    }

    static string LowerAllString(string S1)
    {
        for (short i = 0; i < S1.length(); i++) {
            S1[i] = tolower(S1[i]);
        }
        return S1;
    }

    void LowerAllString() {
        _Value = LowerAllString(_Value);
    }

    static char InvertLetterCase(char char1)
    {
        return isupper(char1) ? tolower(char1) : toupper(char1);
    }

    static string InvertAllLettersCase(string S1)
    {
        for (char& c : S1)
        {
            c = InvertLetterCase(c);
        }
        return S1;
    }

    void InvertAllLettersCase() {
        _Value = InvertAllLettersCase(_Value);
    } 

    enum enWhatToCount { SmallLetters, CapitalLetters, All };

    static short CountLetters(string S1, enWhatToCount WhatToCount = enWhatToCount::All)
    {


        if (WhatToCount == enWhatToCount::All)
        {
            return S1.length();
        }

        short Counter = 0;

        for (short i = 0; i < S1.length(); i++)
        {

            if (WhatToCount == enWhatToCount::CapitalLetters && isupper(S1[i]))
                Counter++;


            if (WhatToCount == enWhatToCount::SmallLetters && islower(S1[i]))
                Counter++;


        }

        return Counter;

    }

    static short CountCapitalLetters(string S1)
    {

        short Counter = 0;

        for (short i = 0; i < S1.length(); i++)
        {

            if (isupper(S1[i]))
                Counter++;

        }

        return Counter;
    }

    short CountCapitalLetters()
    {
        return CountCapitalLetters(_Value);
    }

    static short CountSmallLetters(string S1)
    {

        short Counter = 0;

        for (short i = 0; i < S1.length(); i++)
        {

            if (islower(S1[i]))
                Counter++;

        }

        return Counter;
    }

    short CountSmallLetters()
    {
        return CountSmallLetters(_Value);
    }

    static char invertCase(char letter) {
        return isupper(letter) ? tolower(letter) : toupper(letter);
    }

    static short CountSpecificLetter(string S1, char Letter, bool MatchCase = true)
    {

        short Counter = 0;

        for (short i = 0; i < S1.length(); i++)
        {

            if (MatchCase)
            {
                if (S1[i] == Letter)
                    Counter++;
            }
            else
            {
                if (tolower(S1[i]) == tolower(Letter))
                    Counter++;
            }

        }

        return Counter;
    }

    short CountSpecificLetter(char Letter, bool MatchCase = true)
    {
        return CountSpecificLetter(_Value, Letter, MatchCase);
    }

    static bool IsVowel(char l) {
        l = tolower(l);
        return (l == 'a' || l == 'e' || l == 'i' || l == 'o' || l == 'u');
    }

    static short CountVowels(string S1)
    {
        short count = 0;
        for (short i = 0; i < S1.length(); i++) {

            if (IsVowel(S1[i])) {
                count++;
            }
        }
        return count;
    }

    short  CountVowels()
    {
        return CountVowels(_Value);
    }

    static string  UpperFirstLetterOfEachWord(string S1)
    {

        bool isFirstLetter = true;

        for (short i = 0; i < S1.length(); i++)
        {

            if (S1[i] != ' ' && isFirstLetter)
            {
                S1[i] = toupper(S1[i]);

            }

            isFirstLetter = (S1[i] == ' ' ? true : false);

        }

        return S1;
    }

    void  UpperFirstLetterOfEachWord()
    {
        
        _Value = UpperFirstLetterOfEachWord(_Value);
    }

    static string  LowerFirstLetterOfEachWord(string S1)
    {

        bool isFirstLetter = true;

        for (short i = 0; i < S1.length(); i++)
        {

            if (S1[i] != ' ' && isFirstLetter)
            {
                S1[i] = tolower(S1[i]);

            }

            isFirstLetter = (S1[i] == ' ' ? true : false);

        }

        return S1;
    }

    void  LowerFirstLetterOfEachWord()
    {
        _Value = LowerFirstLetterOfEachWord(_Value);
    }

    static short CountWords(string S1)
    {

        string delim = " ";
        short Counter = 0;
        short pos = 0;
        string sWord;


        while ((pos = S1.find(delim)) != std::string::npos)
        {
            sWord = S1.substr(0, pos);
            if (sWord != "")
            {
                Counter++;
            }


            S1.erase(0, pos + delim.length());
        }

        if (S1 != "")
        {
            Counter++;
        }

        return Counter;

    }

    short CountWords()
    {
        return CountWords(_Value);
    };

    static vector<string> Split(string S1, string delim) {
    	vector<string> vString;
    	short pos = 0;
       	string sWord; 
       	while ((pos = S1.find(delim)) != string::npos)
       	{
       		sWord = S1.substr(0, pos);
       		
    			vString.push_back(sWord);
      
       		S1.erase(0, pos + delim.length()); 
       	}
       	if (S1 != "")
       	{
    		vString.push_back(S1);
       	}
    	return vString;
    }

    vector<string> Split(string delim) {
        return Split(_Value, delim);
    }

    static string ReverseWordsInString(string S1)
    {
        vector<string> vString;
        string S2 = "";
        vString = Split(S1, " ");
        vector<string>::iterator iter = vString.end();
        while (iter != vString.begin())
        {
            --iter;
            S2 += *iter + " ";
        }
        S2 = S2.substr(0, S2.length() - 1);
        return S2;
    }

    string ReverseWordsInString() {
        return ReverseWordsInString(_Value);
    }

    static string TrimLeft(string S1)
    {
        for (short i = 0; i < S1.length(); i++)
        {
            if (S1[i] != ' ')
            {
                return S1.substr(i, S1.length() - i);
            }
        }
        return "";
    }

    string TrimLeft() {
        return TrimLeft(_Value);
    }

    static string TrimRight(string S1)
    {
        for (short i = S1.length() - 1; i >= 0; i--)
        {
            if (S1[i] != ' ')
            {
                return S1.substr(0, i + 1);
            }
        }
        return "";
    }

    string TrimRight() {
        return TrimRight(_Value);
    }

    static string Trim(string S1)
    {
        return (TrimLeft(TrimRight(S1)));
    }

    string Trim() {
        return Trim(_Value);
    }

    static string JoinString(vector<string> vString, string delim) {
        string S1 = "";
        for (string& s : vString)
            S1 += s + delim;
        return S1.substr(0, S1.length() - delim.length());
    }

    static string JoinString(string ArrString[], short Length, string delim) {
        string S1 = "";
        for (short i = 0; i < Length; i++)
            S1 += ArrString[i] + delim;
        return S1.substr(0, S1.length() - delim.length());
    }

    static string ReplaceWordInStringUsingBuiltInFunction(string S1, string StringToReplace, string sRepalceTo)
    {
        short pos = S1.find(StringToReplace);
        while (pos != std::string::npos)
        {
            S1 = S1.replace(pos, StringToReplace.length(), sRepalceTo);
            pos = S1.find(StringToReplace);
        }
        return S1;
    }

    string ReplaceWordInStringUsingBuiltInFunction(string StringToReplace, string sRepalceTo) {
      return ReplaceWordInStringUsingBuiltInFunction(_Value,  StringToReplace, sRepalceTo);

    }
    
    static string ReplaceWord(string S1, string StringToReplace, string sRepalceTo, bool MatchCase = true)
    {
        vector<string> vString = Split(S1, " ");
        for (string& s : vString)
        {
            if (MatchCase)
            {
                if (s == StringToReplace)
                {
                    s = sRepalceTo;
                }
            }
            else
            {
                if (LowerAllString(s) == LowerAllString(StringToReplace))

                {
                    s = sRepalceTo;
                }
            }
        }
        return JoinString(vString, " ");
    }
     
    string ReplaceWord(string StringToReplace, string sRepalceTo, bool MatchCase = true) {
        return ReplaceWord( _Value, StringToReplace, sRepalceTo, MatchCase);
    }

    static string RemovePunctuations(string S1)
    {
        string S2 = "";
        for (short i = 0; i < S1.length(); i++)
        {
            if (!ispunct(S1[i]))
            {
                S2 += S1[i];
            }
        }
        return S2;
    }

    string RemovePunctuations() {
        return RemovePunctuations(_Value);
    }
    
};
