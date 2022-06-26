#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int red = image[i][j].rgbtRed;
            int blue = image[i][j].rgbtBlue;
            int green = image[i][j].rgbtGreen;

            int avg = round(((float)red + (float)blue + (float)green) / 3);
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int red = image[i][j].rgbtRed;
            int blue = image[i][j].rgbtBlue;
            int green = image[i][j].rgbtGreen;

            int sepiaRed = round(0.393 * red + 0.769 * green + 0.189 * blue);
            int sepiaGreen = round(0.349 * red + 0.686 * green + 0.168 * blue);
            int sepiaBlue = round(0.272 * red + 0.534 * green + 0.131 * blue);


            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtGreen = sepiaGreen;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = temp;

        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE org[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            org[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i == 0)
            {
                if (j == 0)
                {
                    image[i][j].rgbtRed = round((org[i][j].rgbtRed + org[i + 1][j].rgbtRed + org[i][j + 1].rgbtRed + org[i + 1][j + 1].rgbtRed) / 4);

                    image[i][j].rgbtGreen = round((org[i][j].rgbtGreen + org[i + 1][j].rgbtGreen + org[i][j + 1].rgbtGreen + org[i + 1][j + 1].rgbtGreen) / 4);

                    image[i][j].rgbtBlue = round((org[i][j].rgbtBlue + org[i + 1][j].rgbtBlue + org[i][j + 1].rgbtBlue + org[i + 1][j + 1].rgbtBlue) / 4);
                }
                else if (j == width - 1)
                {
                    image[i][j].rgbtRed = round((org[i][j].rgbtRed + org[i + 1][j].rgbtRed + org[i][j - 1].rgbtRed + org[i + 1][j - 1].rgbtRed) / 4);

                    image[i][j].rgbtGreen = round((org[i][j].rgbtGreen + org[i + 1][j].rgbtGreen + org[i][j - 1].rgbtGreen + org[i + 1][j - 1].rgbtGreen) / 4);

                    image[i][j].rgbtBlue = round((org[i][j].rgbtBlue + org[i + 1][j].rgbtBlue + org[i][j - 1].rgbtBlue + org[i + 1][j - 1].rgbtBlue) / 4);
                }
                else
                {
                    image[i][j].rgbtRed = round((org[i][j].rgbtRed + org[i + 1][j].rgbtRed + org[i][j - 1].rgbtRed + org[i + 1][j - 1].rgbtRed + org[i][j + 1].rgbtRed + org[i + 1][j + 1].rgbtRed) / 6);

                    image[i][j].rgbtGreen = round((org[i][j].rgbtGreen + org[i + 1][j].rgbtGreen + org[i][j - 1].rgbtGreen + org[i + 1][j - 1].rgbtGreen + org[i][j + 1].rgbtGreen + org[i + 1][j + 1].rgbtGreen) / 6);

                    image[i][j].rgbtBlue = round((org[i][j].rgbtBlue + org[i + 1][j].rgbtBlue + org[i][j - 1].rgbtBlue + org[i + 1][j - 1].rgbtBlue + org[i][j + 1].rgbtBlue + org[i + 1][j + 1].rgbtBlue) / 6);
                }
            }
            else if (i > 0 && i < height - 1)
            {
                if (j == 0)
                {
                    image[i][j].rgbtRed = round((org[i][j].rgbtRed + org[i + 1][j].rgbtRed + org[i - 1][j].rgbtRed + org[i + 1][j + 1].rgbtRed + org[i][j + 1].rgbtRed + org[i - 1][j + 1].rgbtRed) / 6);

                    image[i][j].rgbtGreen = round((org[i][j].rgbtGreen + org[i + 1][j].rgbtGreen + org[i- 1][j].rgbtGreen + org[i + 1][j + 1].rgbtGreen + org[i][j + 1].rgbtGreen + org[i - 1][j + 1].rgbtGreen) / 6);

                    image[i][j].rgbtBlue = round((org[i][j].rgbtBlue + org[i + 1][j].rgbtBlue + org[i - 1][j].rgbtBlue + org[i + 1][j + 1].rgbtBlue + org[i][j + 1].rgbtBlue + org[i - 1][j + 1].rgbtBlue) / 6);
                }
                else if (j == width - 1)
                {
                    image[i][j].rgbtRed = round((org[i][j].rgbtRed + org[i + 1][j].rgbtRed + org[i - 1][j].rgbtRed + org[i + 1][j - 1].rgbtRed + org[i][j - 1].rgbtRed + org[i - 1][j - 1].rgbtRed) / 6);

                    image[i][j].rgbtGreen = round((org[i][j].rgbtGreen + org[i + 1][j].rgbtGreen + org[i- 1][j].rgbtGreen + org[i + 1][j - 1].rgbtGreen + org[i][j - 1].rgbtGreen + org[i - 1][j - 1].rgbtGreen) / 6);

                    image[i][j].rgbtBlue = round((org[i][j].rgbtBlue + org[i + 1][j].rgbtBlue + org[i - 1][j].rgbtBlue + org[i + 1][j - 1].rgbtBlue + org[i][j - 1].rgbtBlue + org[i - 1][j - 1].rgbtBlue) / 6);
                }
                else
                {
                    image[i][j].rgbtRed = round((org[i][j].rgbtRed + org[i][j - 1].rgbtRed + org[i][j + 1].rgbtRed + org[i + 1][j - 1].rgbtRed + org[i + 1][j + 1].rgbtRed + org[i + 1][j].rgbtRed + org[i - 1][j - 1].rgbtRed + org[i - 1][j + 1].rgbtRed + org[i - 1][j].rgbtRed) / 9);

                    image[i][j].rgbtGreen = round((org[i][j].rgbtGreen + org[i][j - 1].rgbtGreen + org[i][j + 1].rgbtGreen + org[i + 1][j - 1].rgbtGreen + org[i + 1][j + 1].rgbtGreen+ org[i + 1][j].rgbtGreen + org[i - 1][j - 1].rgbtGreen + org[i - 1][j + 1].rgbtGreen + org[i - 1][j].rgbtGreen) / 9);

                    image[i][j].rgbtBlue = round((org[i][j].rgbtBlue + org[i][j - 1].rgbtBlue + org[i][j + 1].rgbtBlue + org[i + 1][j - 1].rgbtBlue + org[i + 1][j + 1].rgbtBlue + org[i + 1][j].rgbtBlue + org[i - 1][j - 1].rgbtBlue + org[i - 1][j + 1].rgbtBlue + org[i - 1][j].rgbtBlue) / 9);
                }
            }
            else if (i == height - 1)
            {
                if (j == 0)
                {
                    image[i][j].rgbtRed = round((org[i][j].rgbtRed + org[i - 1][j].rgbtRed + org[i][j + 1].rgbtRed + org[i - 1][j + 1].rgbtRed) / 4);

                    image[i][j].rgbtGreen = round((org[i][j].rgbtGreen + org[i - 1][j].rgbtGreen + org[i][j + 1].rgbtGreen + org[i - 1][j + 1].rgbtGreen) / 4);

                    image[i][j].rgbtBlue = round((org[i][j].rgbtBlue + org[i - 1][j].rgbtBlue + org[i][j + 1].rgbtBlue + org[i - 1][j + 1].rgbtBlue) / 4);
                }
                else if (j == width - 1)
                {
                    image[i][j].rgbtRed = round((org[i][j].rgbtRed + org[i - 1][j].rgbtRed + org[i][j - 1].rgbtRed + org[i - 1][j - 1].rgbtRed) / 4);

                    image[i][j].rgbtGreen = round((org[i][j].rgbtGreen + org[i - 1][j].rgbtGreen + org[i][j - 1].rgbtGreen + org[i - 1][j - 1].rgbtGreen) / 4);

                    image[i][j].rgbtBlue = round((org[i][j].rgbtBlue + org[i - 1][j].rgbtBlue + org[i][j - 1].rgbtBlue + org[i - 1][j - 1].rgbtBlue) / 4);
                }
                else
                {
                    image[i][j].rgbtRed = round((org[i][j].rgbtRed + org[i - 1][j].rgbtRed + org[i][j - 1].rgbtRed + org[i - 1][j - 1].rgbtRed + org[i][j + 1].rgbtRed + org[i - 1][j + 1].rgbtRed) / 6);

                    image[i][j].rgbtGreen = round((org[i][j].rgbtGreen + org[i - 1][j].rgbtGreen + org[i][j - 1].rgbtGreen + org[i - 1][j - 1].rgbtGreen + org[i][j + 1].rgbtGreen + org[i - 1][j + 1].rgbtGreen) / 6);

                    image[i][j].rgbtBlue = round((org[i][j].rgbtBlue + org[i - 1][j].rgbtBlue + org[i][j - 1].rgbtBlue + org[i - 1][j - 1].rgbtBlue + org[i][j + 1].rgbtBlue + org[i - 1][j + 1].rgbtBlue) / 6);
                }
            }
        }
    }

}
