#include "helpers.h"
#include <math.h>
#include <cs50.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE pixel = image[i][j];
            // Get the average of eveyr pixel
            int avg = round((pixel.rgbtRed + pixel.rgbtGreen + pixel.rgbtBlue) / 3.0);
            // change the value of every pixel to the average
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = avg;
        }
    }
}


// Create a function "swap" to switch the images address of relection
void swap(RGBTRIPLE * pixel1, RGBTRIPLE * pixel2)
{
    RGBTRIPLE temp = *pixel1;
    *pixel1 = *pixel2;
    *pixel2 = temp;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            // Swap 'parallel' positioning pixels Using address
            swap(&image[i][j], &image[i][width - 1 - j]);
        }
    }
}

// function to receive a blurred pixel
RGBTRIPLE blurred_pixel(int i, int j, int height, int width, RGBTRIPLE image[height][width])
{
    int redValue, blueValue, greenValue;
    redValue = blueValue = greenValue = 0;
    int numOfValidPixels = 0;

    for (int di = -1; di <= 1; di++)
    {
        for (int dj = -1; dj <= 1; dj++)
        {
            int new_i = i + di;
            int new_j = j + dj;
            if (new_i >= 0 && new_i < height && new_j >= 0 && new_j < width)
            {
                numOfValidPixels++;
                // Get the values of the pixels
                redValue += image[new_i][new_j].rgbtRed;
                blueValue += image[new_i][new_j].rgbtBlue;
                greenValue += image[new_i][new_j].rgbtGreen;
            }
        }
    }
    RGBTRIPLE blurry_pixel;
    // Average the values with the number of valid pixels and assign them
    blurry_pixel.rgbtRed = round((float) redValue / numOfValidPixels);
    blurry_pixel.rgbtBlue = round((float) blueValue / numOfValidPixels);
    blurry_pixel.rgbtGreen = round((float) greenValue / numOfValidPixels);
    return blurry_pixel;
}

// Blur image - making a "new image"
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE new_image[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j =0; j < width; j++)
        {
            new_image[i][j] = blurred_pixel(i, j, height, width, image);
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = new_image[i][j];
        }
    }
}

int cap(int x)
{
    // return x < 255 ? x: 255;
    if (x > 255)
    {
        return 255;
    } else {
        return x;
    }
}

// bool is_valid_pixel(int i, int j, int height, int width)
// {
//     return i >= 0 && i < height && j >= 0 && j < width;
// }
RGBTRIPLE edge_pixel(int i, int j, int height, int width, RGBTRIPLE image[height][width])
{
    int Gx[3][3] = {{ -1, 0, 1 }, {-2, 0, 2}, {-1, 0 ,1}};
    int redValueX, blueValueX, greenValueX, redValueY, blueValueY, greenValueY;
    redValueX = blueValueX = greenValueX = redValueY = blueValueY = greenValueY = 0;
    for (int di = -1; di <= 1; di++)
    {
        for (int dj = -1; dj <= 1; dj++)
        {
            // if (is_valid_pixel(i + di, j + dj, height, width))
            if (i + di >= 0 && i + di < height && j + dj >= 0 && j + dj < width)
            {
                int weightX = Gx[di + 1][dj + 1];
                redValueX += weightX * image[i + di][j + dj].rgbtRed;
                greenValueX += weightX * image[i + di][j + dj].rgbtGreen;
                blueValueX += weightX * image[i + di][j + dj].rgbtBlue;

                int weightY = Gx[dj + 1][di + 1];
                redValueY += weightY * image[i + di][j + dj].rgbtRed;
                greenValueY += weightY * image[i + di][j + dj].rgbtGreen;
                blueValueY += weightY * image[i + di][j + dj].rgbtBlue;
            }
        }
    }
    RGBTRIPLE pixel;

    pixel.rgbtRed = cap(round(sqrt(redValueX*redValueX + redValueY*redValueY)));
    pixel.rgbtGreen = cap(round(sqrt(greenValueX*greenValueX + greenValueY*greenValueY)));
    pixel.rgbtBlue = cap(round(sqrt(blueValueX*blueValueX + blueValueY*blueValueY)));

    return pixel;
}
// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE new_image[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j =0; j < width; j++)
        {
            new_image[i][j] = edge_pixel(i, j, height, width, image);
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = new_image[i][j];
        }
    }
}
