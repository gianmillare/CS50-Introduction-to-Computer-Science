#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <stdint.h>

// decalre the BYTE dependency
typedef uint8_t BYTE;

// define the constants for memory size
#define BLOCK_SIZE 512
#define FILE_NAME_SIZE 8

// functions created
bool starting_new_jpg(BYTE buffer[]);

int main(int argc, char *argv[])
{
    // Check is the command line has enough inputs
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    // read the file placed into argv[1] --> FILE* ptr = fopen(<filename>, <operations>);
    FILE* infile = fopen(argv[1], "r");

    // If the file is empty or unreadable, return an error message
    if (infile == NULL)
    {
        printf("File not found\n");
        return 1;
    }

    // Create the block of memory using the predefined block size of 512
    BYTE buffer[BLOCK_SIZE];

    // decalre an integer to use for naming the written filed below (sprintf etc)
    int file_name_num = 0;

    // set a variable to check if you found the first jpg file to false
    bool found_first_jpg = false;

    // declare a file as an output file
    FILE* outfile;


    // read through the buffer --> fread(<buffer>, <size>, <qty>, <file pointer>);
    while (fread(buffer, BLOCK_SIZE, 1, infile))
    {
        // if you find the header of a new jpg file, start a new BYTE --> function starting_new_jpg
        if (starting_new_jpg(buffer))
        {
            // if this is the first JPG, then set found_first_jpg to true.
            if (!found_first_jpg)
            {
                found_first_jpg = true;
            }
            else
            {
                // if it is not the first jpg, close the previous one, and write a new file
                fclose(outfile);
            }
            // create a file to write the BYTEs you read previously
            char filename[FILE_NAME_SIZE];
            // Format of writing the file --> sprintf(filename, "%03i.jpg", #)
            sprintf(filename, "%03i.jpg", file_name_num++);

            // write the data/memory into the new file using --> FILE* ptr = fopen(<filename>, <operations>);
            outfile = fopen(filename, "w");

            // if the file created finds an error, return
            if (outfile == NULL)
            {
                return 1;
            }

            // write the file --> fwrite(<buffer>, <size>, <qty>, <file pointer>);
            fwrite(buffer, BLOCK_SIZE, 1, outfile);
        }
        else if (found_first_jpg)
        {
            // if the first jpg was found and the next one was not found, continue writing the previous file
            fwrite(buffer, BLOCK_SIZE, 1, outfile);
        }
    }
    // Once completed, close the files
    fclose(outfile);
    fclose(infile);
}

// start of a new JPG is 0xff, 0xd8, 0xff, 0xe''
bool starting_new_jpg(BYTE buffer[])
{
    // to check the fourth bit, use bitwise syntax--> buffer[3] & 0xf0 == 0xe0
    return buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0;
}