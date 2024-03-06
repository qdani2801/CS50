#include "helpers.h"
#include <math.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float average = 0;
    int new_color = 0;
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            average = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed)/3.0;
            new_color = round(average);
            image[i][j].rgbtBlue = new_color;
            image[i][j].rgbtGreen = new_color;
            image[i][j].rgbtRed = new_color;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepia_red, sepia_green, sepia_blue;

    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            sepia_red = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            sepia_green = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            sepia_blue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);

            if (sepia_red > 255){
                sepia_red = 255;
            }
            if (sepia_green > 255){
                sepia_green = 255;
            }
            if (sepia_blue > 255){
                sepia_blue = 255;
            }

            image[i][j].rgbtBlue = sepia_blue;
            image[i][j].rgbtGreen = sepia_green;
            image[i][j].rgbtRed = sepia_red;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int reflect_blue, reflect_green, reflect_red;
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width/2; j++){
            reflect_blue = image[i][j].rgbtBlue;
            reflect_green = image[i][j].rgbtGreen;
            reflect_red = image[i][j].rgbtRed;

            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;

            image[i][width - j - 1].rgbtBlue = reflect_blue;
            image[i][width - j - 1].rgbtGreen = reflect_green;
            image[i][width - j - 1].rgbtRed = reflect_red;

        }

    }
    return;
}


// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

    // Taking a copy image for assistance
    RGBTRIPLE copy[height][width];

    // Storing all pixel values of Original Image into Copy Image by looping over i's and j's of image array
    for (int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            copy[i][j] = image[i][j];
        }
    }

    // Now iterating over original images pixel row by row to blur it by taking average of copy images pixels which remain unchanged
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){

            // Initializing all the values of blur_blue, blur_green, blur_red and number values to 0 to store a new average for every new pixel
            int blur_blue = 0;
            int blur_green = 0;
            int blur_red = 0;
            int number = 0;
            int central_i;
            int central_j;

            // Taking a central point number of 0 and going over its -1 , 0, and 1 in each direction to take all the neighbouring pixel's average for its blue, green and red pixel and assigning the average to Original Image pixel at the image[i][j]th position
            for (central_i = i - 1; central_i <= i + 1; central_i++){
                for (central_j = j - 1; central_j <= j + 1; central_j++){
                    // Checking if the central_i value doesnt cross the boundaries in Edge and Corner cases of Pixels
                    if (central_i >= 0 && central_i < height && central_j >= 0 && central_j < width){
                        blur_blue += copy[central_i][central_j].rgbtBlue;
                        blur_green += copy[central_i][central_j].rgbtGreen;
                        blur_red += copy[central_i][central_j].rgbtRed;
                        number++;
                    }
                }
            }
            // Assigning the new average values of BGR for each pixel in the intended Original Image pixel
            image[i][j].rgbtBlue = round((float) blur_blue / number);
            image[i][j].rgbtGreen = round((float) blur_green / number);
            image[i][j].rgbtRed = round((float) blur_red / number);

        }
    }

    return;
}


