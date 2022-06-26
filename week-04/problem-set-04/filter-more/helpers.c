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

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // Create temp array
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }
    // Initialise Sobel arrays
    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};
    // Loop through rows
    for (int i = 0; i < height; i++)
    {
        // Loop through columns
        for (int j = 0; j < width; j++)
        {
            // Initialise ints
            float Gx_red;
            float Gx_blue;
            float Gx_green;
            float Gy_red;
            float Gy_blue;
            float Gy_green;
            Gx_red = Gx_blue = Gx_green = Gy_red = Gy_blue = Gy_green = 0;
            // For each pixel, loop vertical and horizontal
            for (int k = -1; k < 2; k++)
            {
                for (int l = -1; l < 2; l++)
                {
                    // Check if pixel is outside rows
                    if (i + k < 0 || i + k >= height)
                    {
                        continue;
                    }
                    // Check if pixel is outside columns
                    if (j + l < 0 || j + l >= width)
                    {
                        continue;
                    }
                    // Otherwise add to sums
                    Gx_red += temp[i + k][j + l].rgbtRed * Gx[k + 1][l + 1];
                    Gx_green += temp[i + k][j + l].rgbtGreen * Gx[k + 1][l + 1];
                    Gx_blue += temp[i + k][j + l].rgbtBlue * Gx[k + 1][l + 1];
                    Gy_red += temp[i + k][j + l].rgbtRed * Gy[k + 1][l + 1];
                    Gy_green += temp[i + k][j + l].rgbtGreen * Gy[k + 1][l + 1];
                    Gy_blue += temp[i + k][j + l].rgbtBlue * Gy[k + 1][l + 1];
                }
            }
            // Calculate Sobel operator
            int red = round(sqrt(Gx_red * Gx_red + Gy_red * Gy_red));
            int green = round(sqrt(Gx_green * Gx_green + Gy_green * Gy_green));
            int blue = round(sqrt(Gx_blue * Gx_blue + Gy_blue * Gy_blue));
            // Cap at 255
            if (red > 255)
            {
                red = 255;
            }
            if (green > 255)
            {
                green = 255;
            }
            if (blue > 255)
            {
                blue = 255;
            }
            // Assign new values to pixels
            image[i][j].rgbtRed = red;
            image[i][j].rgbtGreen = green;
            image[i][j].rgbtBlue = blue;
        }
    }
    return;
}
