#include <cs50.h>
#include <stdio.h> // For print function
#include <string.h>
#include <ctype.h>
#include <math.h>


//Prototypes
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
// Get text from user
    string text = get_string("Text: ");

    int nrOfLetters = count_letters(text);

    int nrOfWords = count_words(text);

    int nrOfSentences = count_sentences(text);

//Calculate grade (index)
    float L = (nrOfLetters / (float) nrOfWords) * 100;
    float S = (nrOfSentences / (float) nrOfWords) * 100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);
// L is average number of letters per 100 words
// S is average number of sentences per 100 words

//printf("%i index\n", index);

//Print grade
    if (index > 16)
    {
        printf("%s\n", "Grade 16+");
    }
    else if (index < 1)
    {
        printf("%s\n", "Before Grade 1");
    }
    else
    {
        printf("Grade %i\n", index);
    }

}


// Function to count letters
int count_letters(string text)
{
    int counter = 0; // Initialize counter

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isupper(text[i]))
        {
            counter = counter + 1;
        }
        else if (islower(text[i]))
        {
            counter = counter + 1;
        }
    }
    return counter;
}


// Function to count words
int count_words(string text)
{
    int counter = 0; // // Initialize counter

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == ' ')
        {
            counter = counter + 1;
        }
    }
    return counter + 1;
}


// Function to count sentences
int count_sentences(string text)
{
    int counter = 0; // // Initialize counter

    for (int i = 0, len = strlen(text); i <= len; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            counter = counter + 1;
        }
    }
    return counter;
}