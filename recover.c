#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

// Defining BYTE and JPEG size in int
typedef uint8_t BYTE;
const int JPEG = 512;

int main(int argc, char *argv[]){

    // Taking image as null pointer to store output image
    FILE *image = NULL;

    // Taking character image_name of size 8, number of image to keep count of images and Buffer size of 512 BYTE
    char image_name[8];
    int num_of_img = 0;
    BYTE buffer[JPEG];

    // If more than 1 Command line argument passed, display Error message and return 1
    if (argc != 2){
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }

    // Open the card.raw as read on file pointer
    FILE *file = fopen(argv[1], "r");

    // If file is empty, Display the error message and return 1
    if (file == NULL){
        printf("CANT OPEN\n");
        return 1;
    }

    // Loop over the file as long as it returns 512
    // fread takes buffer address, runs 1 block for 512 Size and Reads file (card.raw)
    while (fread(&buffer, 1, JPEG, file) == 512){

        // Check for the JPEG header
        if ((buffer[0] == 0xff) && (buffer[1] == 0xd8) && (buffer[2] == 0xff) && ((buffer[3] & 0xf0) == 0xe0)){

            // If the image count is 0 then open the new image and write on it
            if (num_of_img == 0){
                sprintf(image_name, "%03i.jpg", num_of_img);
                image = fopen(image_name, "w");
                fwrite(buffer, 1, JPEG, image);

                // Increament the number of images
                num_of_img += 1;
            }

            // If the image count is more than 0 then close previous file, generate new file and write on it the data from file
            else {
                fclose(image);
                sprintf(image_name, "%03i.jpg", num_of_img);
                image = fopen(image_name, "w");
                fwrite(buffer, 1, JPEG, image);

                // Increament the number of images
                num_of_img += 1;
            }
        }

        // If JPEG header not found then keep reading
        else{
            if (num_of_img > 0){
            fwrite(buffer, 1, JPEG, image);
            }

        }
    }
    fclose(image);
    fclose(file);
    return 0;
}

// 
