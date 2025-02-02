#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool PhoneticConversion(string PhoneticInput);
bool Alphaconversion(string AlphaInput);
bool Morseconversion(string MorseInput);

typedef struct
{
    char letter;
    string morse;
    string phonetic;
} MorsePhonetic;

MorsePhonetic alphabet[] = {{'A', ".-", "Alpha"},    {'B', "-...", "Bravo"},   {'C', "-.-.", "Charlie"}, {'D', "-..", "Delta"},
                            {'E', ".", "Echo"},      {'F', "..-.", "Foxtrot"}, {'G', "--.", "Golf"},     {'H', "....", "Hotel"},
                            {'I', "..", "India"},    {'J', ".---", "Juliet"},  {'K', "-.-", "Kilo"},     {'L', ".-..", "Lima"},
                            {'M', "--", "Mike"},     {'N', "-.", "November"},  {'O', "---", "Oscar"},    {'P', ".--.", "Papa"},
                            {'Q', "--.-", "Quebec"}, {'R', ".-.", "Romeo"},    {'S', "...", "Sierra"},   {'T', "-", "Tango"},
                            {'U', "..-", "Uniform"}, {'V', "...-", "Victor"},  {'W', ".--", "Whiskey"},  {'X', "-..-", "X-ray"},
                            {'Y', "-.--", "Yankee"}, {'Z', "--..", "Zulu"},    {'0', "-----", "Zero"},   {'1', ".----", "One"},
                            {'2', "..---", "Two"},   {'3', "...--", "Tree"},   {'4', "....-", "Four"},   {'5', ".....", "Five"},
                            {'6', "-....", "Six"},   {'7', "--...", "Seven"},  {'8', "---..", "Eight"},  {'9', "----.", "Niner"}};

int main(void)
{
    int page = 0;

    while (true)
    {
        int pagechk;

        pagechk = isdigit(page);

        if (page == 0 || pagechk == 0)
        {
            printf("\n");
            page = 0;
            string test = "Welcome to Aviation Phonetics and Morse Code Converter.\n- Type '1' to convert letters and numbers to "
                          "phonetics.\n- Type '2' to convert letters and numbers to morse code.\n- Type '3' to convert morse code "
                          "to letters and numbers.\n- Type '4' to exit.\nNumber: ";
            page = get_int("%s", test);
        }

        if (page == 1)
        {
            string esc = "~!";
            printf("To return to the menu, type '~!'.\n");
            string PhoneticInput = get_string("Enter a line of plaintext: ");
            if (strcmp(PhoneticInput, esc) == 0)
            {
                page = 0;
            }
            else
            {
                PhoneticConversion(PhoneticInput);
                printf("\n");
            }
        }

        if (page == 2)
        {
            string esc = "~!";
            printf("To return to the menu, type '~!'.\n");
            string UserInput = get_string("Enter a line of plaintext: ");
            if (strcmp(UserInput, esc) == 0)
            {
                page = 0;
            }
            else
            {
                int component;
                int valid = 0;
                for (component = 0; component <= strlen(UserInput) - 1; component++)
                {
                    if (isalnum(UserInput[component]) == 0 && UserInput[component] != 32)
                    {
                        valid = 1;
                        break;
                    }
                }

                if (valid == 1)
                {
                    printf("Unsupported characters.\n");
                }
                else
                {
                    if (Alphaconversion(UserInput) == true)
                    {
                        printf("\n");
                        page = 2;
                    }
                }
            }
        }

        if (page == 3)
        {
            string esc = "~!";
            printf("To return to the menu, type '~!'.\n");
            string MorseLine = get_string("Enter a line of Morse code: ");
            if (strcmp(MorseLine, esc) == 0)
            {
                page = 0;
            }
            else
            {
                int component3;
                int valid3 = 0;
                for (component3 = 0; component3 <= strlen(MorseLine) - 1; component3++)
                {
                    if ((MorseLine[component3] != 32) && (MorseLine[component3] != 47) && (MorseLine[component3] != 46) &&
                        (MorseLine[component3] != 45))
                    {
                        valid3 = 1;
                        break;
                    }
                }
                if (valid3 == 1)
                {
                    printf("Unsupported characters.\n");
                }
                else
                {
                    if (Morseconversion(MorseLine) == true)
                    {
                        printf("\n");
                        page = 3;
                    }
                }
            }
        }

        if (page == 4)
        {
            exit(0);
        }

    }
}

bool PhoneticConversion(string PhoneticInput)
{
    // int page;
    string target = PhoneticInput;
    int index;
    string output = NULL;
    int i;
    printf("Phonetic: ");
    for (i = 0; i < strlen(target); i++)
    {
        if (target[i] == 32)
        {
            printf("/ ");
        }
        else
        {
            for (index = 0; index <= 35; index++)
            {
                char targetUp = toupper(target[i]);
                if (targetUp == alphabet[index].letter)
                {
                    output = alphabet[index].phonetic;
                    printf("%s ", output);
                }
            }
        }
    }
    printf("\n");
    return true;
}

bool Alphaconversion(string AlphaInput)
{

    string target = AlphaInput;
    int index;
    string output = NULL;
    int i;
    
    printf("Morsecode: ");
    for (i = 0; i < strlen(target); i++)
    {
        if (target[i] == 32)
        {
            // printf("%c", target[i]);
            printf("/ ");
            // output += target[i];
        }
        else
        {
            for (index = 0; index <= (sizeof(alphabet) / sizeof(alphabet[0]) - 1); index++)
            {
                // for (i = 1; i <= 3; i ++)
                //{
                // if (i = )
                //}
                // if (strcmp(target, alphabet[index].morse) == 0)
                if (isalpha(target[i]) && islower(target[i]))
                {
                    if (toupper(target[i]) == alphabet[index].letter)
                    {
                        output = alphabet[index].morse;
                        printf("%s ", output);
                        // printf
                    }
                }
                if (target[i] == alphabet[index].letter)
                {
                    output = alphabet[index].morse;
                    printf("%s ", output);
                    // printf
                }
                // else if (strcmp(&UserInput[i], " " == 0))
                //{
                // printf("%c", UserInput[i])
                //}

                // for (row == 0)
                // if (column == target)
                //{
                // letter = row;
                //}
            }
            // return output;
        }
    }
    printf("\n");
    return true;
}

bool Morseconversion(string MorseInput)
{

    char output3;
    int index;
    int i;
    // char *delimiters = " ";
    char *morseitem = strtok(MorseInput, " ");
    // char *morseword = strtok(MorseInput, " / ");
    printf("Plaintext: ");
    // for (i = 0; i < strlen(MorseInput); i ++)
    //{
    // printf("Hi");
    // if (MorseInput[i] != 32)
    //{
    // charactertosearch = chara
    //}
    //}
    // while (morseword != NULL)
    //{
    while (morseitem != NULL)
    {
        // printf("Item: %s\n", morseitem);
        for (index = 0; index <= (sizeof(alphabet) / sizeof(alphabet[0]) - 1); index++)
        {
            // char alphabetmorse = alphabet[index].morse;
            // printf("MorseInput: %s", MorseInput);
            // printf("Morse: %s\n", alphabet[index].morse);
            // if (MorseInput == alphabet[index].morse)
            if ((morseitem != NULL) && (strcmp(morseitem, "/") == 0))
            {
                // printf("%c", target[i]);
                printf(" ");
                morseitem = strtok(NULL, " ");
                // output += target[i];
            }
            else if ((morseitem != NULL) && (strcmp(morseitem, alphabet[index].morse) == 0))
            {
                // printf("YES");
                // output3 = "YES";
                // printf("%s", output3);
                output3 = alphabet[index].letter;
                printf("%c", output3);
                morseitem = strtok(NULL, " ");
            }

            // printf("%c", output3);
            // morseword = strtok(NULL, " / ");
        }
        // morseword = strtok(NULL, " / ");
    }
    // morseword = strtok(NULL, " / ");
    // }
    // printf("%s", output3);
    printf("\n");
    return true;
}
