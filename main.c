/*
 * File:   main.c
 * Author: Ouwesh
 *
 * Created on 23 November 2018, 11:52
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> //libabry used for bool variables.
#include <time.h> // used for time purposes.
#include <string.h> // used for string functions.
/*
 *
 */
int input();// declaration of function
int main()
{
    char ans;// variable to store the key entered where to retry the program or not
    do{
    srand(time(NULL)); // seeds different values each time the programs starts
    int i=0; // to count number of words
    int count=1; // to display the position number while output
    char password[100]; // stores each password in that array
    memset(password, 0, sizeof(password)); //resets the array password each time the program is executed
    int numofwords=input();// calls function input
    printf("Number of words to be generated: %d\n", numofwords);
    printf("Generating Password\n");
    while (numofwords!=i) // variable i is used to count the number of words in the loop and onces it ends loops exits
    {
        printf("%d ", count);
        char filenumber[10]; //variable to store the filenumber in characters
        int RandomFileNumber = rand() % ((7 + 1) - 4) + 4; //  formula is ((Max+1)-Min) + Min
        sprintf(filenumber, "%d",RandomFileNumber);  //converts the random integer generated for the passsword to string so that if can be used in fopen
        FILE* passwordfile = fopen(filenumber, "r");// opening a file passwordfile (range of word file, read mode)
        bool copy_characters = false; // sets it to false so as loop does not end
        int linenumber = 1;// default line of file
        int RandomL = rand() % ((500 + 1) - 1) + 1; //  formula is ((Max+1)-Min) + Min
        int desiredline = RandomL; // setting the required line to the random file
        static int index = 0;// resets when is run though loops (variable which stores each characters of passwords)
        /*  This loop will go one by 1 and copy the random line generated
        After line is found it copies it to a variable password*/
        for (;;)   //infinite loop ends when eof
        {
            int pass = fgetc(passwordfile);
            if (EOF == pass)     //IF LOOP REACHES END OF FILE
            {
                break;        // It exits
            }
            else if ('\n' == pass)     // if there is a new line
            {
                ++linenumber; // increments line by 1
                if (desiredline == linenumber)
                {
                    copy_characters = true;
                    if (count != 1) // as soon as a new line is found, it adds a -
                    {
                        password[index] = '-'; //if statement is ignored at first line
                        index++;
                    }
                }
                else if (copy_characters)     // compares and if it is true it ends the loop
                {
                    break;
                }
            }
            else if (copy_characters)      //copies the password of the given line
            {
                printf("%c", pass);
                password[index] = pass; //adding each character to the variable password
                index++;
            }
        }
        fclose(passwordfile);
        count++;
        i++;
        printf("\n"); //prints a new line after each password has been generated
    }
    printf("Your e-t-r password is: %s", password);
    printf ("\nDo you want to try again?\nType yes to try again\nPress any letter to exit\n");
    scanf(" %c", &ans);
    }
    while (ans == 'y' || ans == 'Y'); // if anyone of the response is input the program will retry
    printf ("\nThank you for using Easy-Password Generator by Ouwesh Seeroop\nBye!");
    return 0;
}
int input () // function to input number
{
    int numofwords;
    printf("Welcome to Easy-Password Generator by Ouwesh Seeroo\nUsage: Enter Number of words (between 2 and 5)\n");
    fflush(stdin); //clear the buffer to avoid errors
    scanf("%d", &numofwords);
    while (numofwords < 2 || numofwords > 5)	// if an invalid number is entered this loop will execute
    {
        printf ("Invalid number, Please enter a number between 2 and 5\n");
        scanf ("%d", &numofwords);
        continue;
    }
    return numofwords;
}

