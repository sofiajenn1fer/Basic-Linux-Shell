#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <ctype.h>
#include "utils.h"

// prompts user for input then executes commands in a loop until user wishes to exit
void user_prompt_loop();
// returns the dynamically allocated user command (with no limit)
char * get_user_command();
// parses the command if there are multiple arguments and sends it to get executed if it is not /proc or exit
int parse_command(char *, char[]);
// exits the program with exit code
void exitFunc(char *, int, char[]);
// executes command in shell and creates child process
void execute_command(const char *File, char *const ArgumentVector[], char* message, int, char**, char*copy);


int main(int argc, char **argv){
   (void)argv;
    if (argc > 1){
    	fprintf(stderr, "Unknown argument\n");
        return 1;
    }else{
    	user_prompt_loop();
    }
    return 0;
}


void user_prompt_loop(){
   // variable which will be used to store user input
    char *message;

    // creating the .421sh file, getting user's ~ and creating hidden file in home directory
    char *home_dir = getenv("HOME");
    char *filename = ".421sh";
    char filepath[strlen(home_dir) + strlen(filename) + 2];
    strcpy(filepath, home_dir);
    filepath[strlen(home_dir)] = '/';
    filepath[strlen(home_dir) + 1] = '\0';
    strcat(filepath, filename);
    
    printf(">> ");
    message = get_user_command();
    int return_code = parse_command(message, filepath);

    // writes first command into .421sh, throws error if for some reason that file is inaccessible
    FILE *file = fopen(filepath, "a"); // Open file for writing
    if (file == NULL) 
        fprintf(stderr, "Error: Unable to create file\n");

    // Write something to the file
    fprintf(file, "%s\n", message);

    fclose(file); // Close the file

    // use parse command to return a code which satisfies this while loop. then with parse call exit etc
    while (return_code == 1){
        // free message each time to prevent mem leaks
        free(message);
        printf(">> ");
        // reallocate message by prompting user
        message = get_user_command();
        return_code = parse_command(message, filepath);

        // does same as what I have done above
        FILE *file = fopen(filepath, "a"); // Open file for writing
        if (file == NULL) 
            fprintf(stderr, "Error: Unable to create file\n");

        // Write something to the file
        fprintf(file, "%s\n", message);

        fclose(file); // Close the file

    }
    // free message if only "exit" was typed (normal exit, with no arguments)
    free(message);
}

char * get_user_command(){
    // creating a buffer for tracking and also keeping track of the position
    int buffer = 256;
    int position = 0;
    
    // allocating data for dynamic size
    char* message = malloc(sizeof(char)*buffer);

    int c;
    int flag = 1;

    while (flag == 1){
        c = fgetc(stdin);

        // reached end of string or user input, adding null terminator and ending loop
        if (c == EOF || c == '\n'){
            message[position] = '\0';
            flag = 0; 
        }else{
            message[position] = c;
        }

        position++;

        // if string is greater than first anticipated, increment buffer by 256 and reallocate to make copy string bigger
        if (position >= buffer){
            c = fgetc(stdin);
            buffer += 256;
            message = realloc(message, buffer);
        }
    }
    // return string
    return message;
}

int parse_command(char * message, char filepath[]){

    // unescape string getting rid of any escape characters (\n, \t, \\, etc)
    char *unescape_msg = unescape(message, stderr);
    if (unescape_msg == NULL){
    	free(unescape_msg);
    	return 1;
    }
    // making copy of string because strtok() edits the string passed
    char *copy = malloc((strlen(unescape_msg) + 1) * sizeof(char));
    strcpy(copy, unescape_msg);
    // freeing the output from unescape because that is dynamically allocated
    free(unescape_msg);
    
   // checking if the message has any spaces or is essentially a "string" input
   // example: "echo hello world" with quotes is treated as a string  
   if (count_spaces(message) > 0 && (message[0] != '"' || message[strlen(message) - 1] != '"')){
        // tracker variables
        size_t i = 0;
        size_t count = 0;
        int flag = 0;
        int fnum;

        // checking for spaces using strtok()
        char *p = strtok(copy, " ");
        char **array = NULL;
        array = malloc(sizeof(char*));

        // iterate through string to save arguments which do not have space in array
        //array is dynamically allocated
        while (p != NULL){
            array[count] = malloc((strlen(p) + 1) * sizeof(char));
            strcpy(array[count], p);
            count++;
            char **temp = realloc(array, (count + 1) * sizeof(char*));
            array = temp;
            p = strtok(NULL, " ");
        }

        // checking if command contains "exit". since there are spaces that means exit is run with an argument
        if (strcmp(array[0], "exit") == 0){
            // checking if the argument could be of negative value '-'
            for (i = 0; i < strlen(array[1]); i++){
                if (i == 0 && array[1][i] == '-')
                    flag = 1;
                else{
                    // if any character is not a digit, reprompt user and freeing any variables
                    if (!(isdigit(array[1][i]))){
                        for (int i = 0; i < count; i++) 
                            free(array[i]);
                        free(array);
                        free(copy);
                        return 1;
                    }
                }
                // if any character is not a digit, reprompt user and freeing any variables
                if (flag && i != 0){
                    if (!(isdigit(array[1][i]))){
                        for (int i = 0; i < count; i++) 
                            free(array[i]);
                        free(array);
                        flag = 0;
                        free(copy);
                        return 1;
                    }
                }
                    
            }

            // else if the argument is really an int, convert the string to int
            fnum = atoi(array[1]);
            if (flag){
                // since atoi() did not return the negative value, manually making it negative
                int sign = -1;
                fnum += sign;
                fnum +=1;
            }

            // freeing all my variables before i prepare to exit the program
            for (int i = 0; i < count; i++) 
                free(array[i]);
            free(array);
            free(copy);

            exitFunc(message, fnum, filepath);               
        }else if (strcmp(array[0], "/proc") == 0){
            // checking if the command includes /proc, this means I will be reading from filesystems
            int total_size = 0;

            // getting total size of all arguments because I need to concatenate the arguments
            // also checking if second argument is missing '/' such as /proc [pid]/[command]
            for (i = 0; i < count; i ++){
                if (i != 0 && array[i][0] != '/')
                    total_size+=1;
                total_size += strlen(array[i]);
            }

            // creating a variable which will be the path name
            char path[total_size+1]; 
            strcpy(path, array[0]);
            // if second argument is missing '/', will add it in there else ignore
            if (array[1][0] != '/')
                path[strlen(array[0])] = '/';
            // have to add null terminator before strcat()
            path[strlen(array[0]) + 1] = '\0';
            strcat(path, array[1]);

            // opening file path I created from user input to read
            FILE *fd = fopen(path, "r");

            // if the file was a valid file in /proc filesystems
            if (fd != NULL){
                do
                {
                    // Taking input single character at a time
                    char c = fgetc(fd);
            
                    // Checking for end of file
                    if (feof(fd))
                        break ;
            
                    printf("%c", c);
                }  while(1);
                fclose(fd);
            }else
                // error if file does not exist
                fprintf(stderr, "Can't open %s\n", path ); 
            printf("\n");       
        }else{
            // if command is not /proc or exit and has spaces, am passing that to execute_command()
            // reallocating array so that I can add "NULL" argument because that is what execvp() takes
            char **temp = realloc(array, (count + 1) * sizeof(char*));
            array = temp;
            for (int i = count; i < count + 1; i++)
                array[i] = NULL;
            execute_command(array[0], array, message, count, array, copy);
        }
        // after all operations have been executed, freeing dynamic memory so I do not get leaks
        for (int i = 0; i < count; i++) 
            free(array[i]);
        free(array);
        free(copy);
        
    }else if (strcmp(message, "exit") != 0){
        // this means the command has no spaces
        char proc[] = "/proc";
        char *foundproc;

        // checking if user message includes /proc
        foundproc = strstr(message, proc);

        // if the message includes /proc, read from /proc filesystems
        if (foundproc != NULL){
            FILE *fd = fopen(message, "r");  

            // same as before, read through path is it exists else throw error       
            if (fd != NULL){
                do
                {
                    // Taking input single character at a time
                    char c = fgetc(fd);
            
                    // Checking for end of file
                    if (feof(fd))
                        break ;
            
                    printf("%c", c);
                }  while(1);
                fclose(fd);
            }else
                fprintf(stderr, "Can't open %s\n", message );
            printf("\n");
            free(copy);
            return 1; 

        }else if (strcmp(message, "history") == 0){
            // if the command is "history", print last 10 messages unless there were less than 10 inputted
            int counter = 0;
            int tracker = 0;
            FILE *fp; 
            char buf[ 128 ]; 

            // filepath I passed in from earlier (~/.421sh)
            // here I am tracking how many commands have been written so far
            if( !(fp = fopen(filepath, "r")) ) 
            { 
                fprintf(stderr, "Can't open %s\n", filepath ); 
            } 
            while( fgets( buf, sizeof(buf), fp ) ) 
                counter++;        
            fclose( fp ); 

            // this is where I check if the commands are less than 10 if so I print them all
            if (counter < 11){
                if( !(fp = fopen(filepath, "r")) ) 
            { 
                fprintf(stderr, "Can't open %s\n", filepath ); 
            } 
            while( fgets( buf, sizeof(buf), fp ) ) 
                printf("%s", buf);        
            fclose( fp ); 
            }else{
                // i print the most recent 10 commands
                int limit = counter - 10;
                if( !(fp = fopen(filepath, "r")) ) 
            { 
                fprintf(stderr, "Can't open %s\n", filepath ); 
            } 
                while( fgets( buf, sizeof(buf), fp ) ){
                    tracker++;
                    if (tracker > limit)
                        printf("%s", buf);        
                }       
                fclose( fp ); 
            }
            free(copy);
        }else{
            // this is an execute_command argument, so I pass that in
            char *temp[2];
            temp[0] = copy;
            temp[1] = NULL;
            execute_command(temp[0], temp, message, 0, NULL, copy);

            free(copy);
        }
    }else{
        free(copy);
        return 0; 
    }
    return 1;   
}

void execute_command(const char *File, char *const ArgumentVector[], char* message, int length, char** array, char* copy){
   // creating a child process
    pid_t pid = fork();
    int status;

    // checking if child process has successfully been created
    if(pid == 0){
        execvp(File, ArgumentVector);

        // if there has been an error (if the command didn't exist etc), I exit the child process and free my variables
        perror("execvp");
        char error[1] = {'0'};
        if (length > 0){
            for (int i = 0; i < length; i++) 
                free(array[i]);
            free(array);
        }
        free(copy);
        exitFunc(message, -1, error);
    }
    else{
        // parent waits for child to terminate then exits function
        waitpid(pid, &status, 0);
        return;
    }
}


// exit helper, exits program if exit has parameter or execvp command does not exist
void exitFunc(char * message, int code, char filepath[]){
    // this is for execvp(), I write that command, same as the other times I have called this
    if (filepath[0] != '0'){
        FILE *file = fopen(filepath, "a"); // Open file for writing
        if (file == NULL) 
            fprintf(stderr, "Error: Unable to create file\n");

        // Write something to the file
        fprintf(file, "%s\n", message);

        fclose(file); // Close the file  
    }
    
    // free message and exit program
    free(message);
    exit(code);
}
