#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int b = image[i][j].rgbtBlue;
            int g = image[i][j].rgbtGreen;
            int r = image[i][j].rgbtRed;
            int greyAvg = round( (float) (b+g+r)/3);

            image[i][j].rgbtBlue = greyAvg;
            image[i][j].rgbtGreen = greyAvg;
            image[i][j].rgbtRed = greyAvg;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width/2; j++)
        {
           RGBTRIPLE n = image[i][j];
           image[i][j] = image[i][width-j-1];
           image[i][width-j-1] = n;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    int redAvg;
    int greenAvg;
    int blueAvg;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
           temp[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i == 0 && j == 0) // top left corner
            {
                redAvg = round( (float) (temp[i][j].rgbtRed + temp[i][j+1].rgbtRed + temp[i+1][j].rgbtRed + temp[i+1][j+1].rgbtRed)/4);
                greenAvg = round( (float) (temp[i][j].rgbtGreen + temp[i][j+1].rgbtGreen + temp[i+1][j].rgbtGreen + temp[i+1][j+1].rgbtGreen)/4);
                blueAvg = round( (float) (temp[i][j].rgbtBlue + temp[i][j+1].rgbtBlue + temp[i+1][j].rgbtBlue + temp[i+1][j+1].rgbtBlue)/4);
            }
            else if (i == 0 && j != 0 && j != width-1) // top edge
            {
                redAvg = round( (float) (temp[i][j].rgbtRed + temp[i][j+1].rgbtRed + temp[i+1][j].rgbtRed + temp[i+1][j+1].rgbtRed + temp[i+1][j-1].rgbtRed + temp[i][j-1].rgbtRed)/6);
                greenAvg = round( (float) (temp[i][j].rgbtGreen + temp[i][j+1].rgbtGreen + temp[i+1][j].rgbtGreen + temp[i+1][j+1].rgbtGreen + temp[i+1][j-1].rgbtGreen + temp[i][j-1].rgbtGreen)/6);
                blueAvg = round( (float) (temp[i][j].rgbtBlue + temp[i][j+1].rgbtBlue + temp[i+1][j].rgbtBlue + temp[i+1][j+1].rgbtBlue + temp[i+1][j-1].rgbtBlue + temp[i][j-1].rgbtBlue)/6);
            }
            else if (i == 0 && j == width-1) // top right corner
            {
                redAvg = round( (float) (temp[i][j].rgbtRed + temp[i][j-1].rgbtRed + temp[i+1][j].rgbtRed + temp[i+1][j-1].rgbtRed)/4);
                greenAvg = round( (float) (temp[i][j].rgbtGreen + temp[i][j-1].rgbtGreen + temp[i+1][j].rgbtGreen + temp[i+1][j-1].rgbtGreen)/4);
                blueAvg = round( (float) (temp[i][j].rgbtBlue + temp[i][j-1].rgbtBlue + temp[i+1][j].rgbtBlue + temp[i+1][j-1].rgbtBlue)/4);
            }
            else if (i != 0 && i != height-1 && j == 0) // left edge
            {
                redAvg = round( (float) (temp[i][j].rgbtRed + temp[i+1][j].rgbtRed + temp[i+1][j+1].rgbtRed + temp[i][j+1].rgbtRed + temp[i-1][j+1].rgbtRed + temp[i-1][j].rgbtRed)/6);
                greenAvg = round( (float) (temp[i][j].rgbtGreen + temp[i+1][j].rgbtGreen + temp[i+1][j+1].rgbtGreen + temp[i][j+1].rgbtGreen + temp[i-1][j+1].rgbtGreen + temp[i-1][j].rgbtGreen)/6);
                blueAvg = round( (float) (temp[i][j].rgbtBlue + temp[i+1][j].rgbtBlue + temp[i+1][j+1].rgbtBlue + temp[i][j+1].rgbtBlue + temp[i-1][j+1].rgbtBlue + temp[i-1][j].rgbtBlue)/6);
            }
            else if (i != 0 && i != height-1 && j == width-1) // right edge
            {
                redAvg = round( (float) (temp[i][j].rgbtRed + temp[i+1][j].rgbtRed + temp[i+1][j-1].rgbtRed + temp[i][j-1].rgbtRed + temp[i-1][j-1].rgbtRed + temp[i-1][j].rgbtRed)/6);
                greenAvg = round( (float) (temp[i][j].rgbtGreen + temp[i+1][j].rgbtGreen + temp[i+1][j-1].rgbtGreen + temp[i][j-1].rgbtGreen + temp[i-1][j-1].rgbtGreen + temp[i-1][j].rgbtGreen)/6);
                blueAvg = round( (float) (temp[i][j].rgbtBlue + temp[i+1][j].rgbtBlue + temp[i+1][j-1].rgbtBlue + temp[i][j-1].rgbtBlue + temp[i-1][j-1].rgbtBlue + temp[i-1][j].rgbtBlue)/6);
            }
            else if (i == height-1 && j == 0) // bottom left corner
            {
                redAvg = round( (float) (temp[i][j].rgbtRed + temp[i][j+1].rgbtRed + temp[i-1][j].rgbtRed + temp[i-1][j+1].rgbtRed)/4);
                greenAvg = round( (float) (temp[i][j].rgbtGreen + temp[i][j+1].rgbtGreen + temp[i-1][j].rgbtGreen + temp[i-1][j+1].rgbtGreen)/4);
                blueAvg = round( (float) (temp[i][j].rgbtBlue + temp[i][j+1].rgbtBlue + temp[i-1][j].rgbtBlue + temp[i-1][j+1].rgbtBlue)/4);
            }
            else if (i == height-1 && j == width-1) // bottom right corner
            {
                redAvg = round( (float) (temp[i][j].rgbtRed + temp[i][j-1].rgbtRed + temp[i-1][j].rgbtRed + temp[i-1][j-1].rgbtRed)/4);
                greenAvg = round( (float) (temp[i][j].rgbtGreen + temp[i][j-1].rgbtGreen + temp[i-1][j].rgbtGreen + temp[i-1][j-1].rgbtGreen)/4);
                blueAvg = round( (float) (temp[i][j].rgbtBlue + temp[i][j-1].rgbtBlue + temp[i-1][j].rgbtBlue + temp[i-1][j-1].rgbtBlue)/4);
            }
            else if (i == height-1 && j != 0 && j != width-1) // bottom edge
            {
                redAvg = round( (float) (temp[i][j].rgbtRed + temp[i][j+1].rgbtRed + temp[i-1][j].rgbtRed + temp[i-1][j+1].rgbtRed + temp[i-1][j-1].rgbtRed + temp[i][j-1].rgbtRed)/6);
                greenAvg = round( (float) (temp[i][j].rgbtGreen + temp[i][j+1].rgbtGreen + temp[i-1][j].rgbtGreen + temp[i-1][j+1].rgbtGreen + temp[i-1][j-1].rgbtGreen + temp[i][j-1].rgbtGreen)/6);
                blueAvg = round( (float) (temp[i][j].rgbtBlue + temp[i][j+1].rgbtBlue + temp[i-1][j].rgbtBlue + temp[i-1][j+1].rgbtBlue + temp[i-1][j-1].rgbtBlue + temp[i][j-1].rgbtBlue)/6);
            }
            else // the middle
            {
                redAvg = round( (float) (temp[i][j].rgbtRed + temp[i][j+1].rgbtRed + temp[i-1][j].rgbtRed + temp[i-1][j+1].rgbtRed + temp[i-1][j-1].rgbtRed + temp[i][j-1].rgbtRed + temp[i+1][j].rgbtRed + temp[i+1][j-1].rgbtRed + temp[i+1][j+1].rgbtRed)/9);
                greenAvg = round( (float) (temp[i][j].rgbtGreen + temp[i][j+1].rgbtGreen + temp[i-1][j].rgbtGreen + temp[i-1][j+1].rgbtGreen + temp[i-1][j-1].rgbtGreen + temp[i][j-1].rgbtGreen + temp[i+1][j].rgbtGreen + temp[i+1][j-1].rgbtGreen + temp[i+1][j+1].rgbtGreen)/9);
                blueAvg = round( (float) (temp[i][j].rgbtBlue + temp[i][j+1].rgbtBlue + temp[i-1][j].rgbtBlue + temp[i-1][j+1].rgbtBlue + temp[i-1][j-1].rgbtBlue + temp[i][j-1].rgbtBlue + temp[i+1][j].rgbtBlue + temp[i+1][j-1].rgbtBlue + temp[i+1][j+1].rgbtBlue)/9);
            }

            image[i][j].rgbtRed = redAvg;
            image[i][j].rgbtGreen = greenAvg;
            image[i][j].rgbtBlue = blueAvg;
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    int GxK[3][3] = {{-1,0,1}, {-2,0,2},{-1,0,1}};
    int GyK[3][3] = {{-1,-2,-1}, {0,0,0},{1,2,1}};

    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
           temp[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int opRed[3][3] = {{0,0,0},{0,0,0},{0,0,0}};
            int opGreen[3][3] = {{0,0,0},{0,0,0},{0,0,0}};
            int opBlue[3][3] = {{0,0,0},{0,0,0},{0,0,0}};

            if (i == 0 && j == 0) // top left corner
            {
                opRed[1][1] = temp[i][j].rgbtRed; opRed[1][2] = temp[i][j+1].rgbtRed; opRed[2][1] = temp[i+1][j].rgbtRed; opRed[2][2] = temp[i+1][j+1].rgbtRed;
                opGreen[1][1] = temp[i][j].rgbtGreen; opGreen[1][2] = temp[i][j+1].rgbtGreen; opGreen[2][1] = temp[i+1][j].rgbtGreen; opGreen[2][2] = temp[i+1][j+1].rgbtGreen;
                opBlue[1][1] = temp[i][j].rgbtBlue; opBlue[1][2] = temp[i][j+1].rgbtBlue; opBlue[2][1] = temp[i+1][j].rgbtBlue; opBlue[2][2] = temp[i+1][j+1].rgbtBlue;
            }
            else if (i == 0 && j != 0 && j != width-1) // top edge
            {
                opRed[1][0] = temp[i][j-1].rgbtRed; opRed[1][1] = temp[i][j].rgbtRed; opRed[1][2] = temp[i][j+1].rgbtRed; opRed[2][0] = temp[i+1][j-1].rgbtRed; opRed[2][1] = temp[i+1][j].rgbtRed; opRed[2][2] = temp[i+1][j+1].rgbtRed;
                opGreen[1][0] = temp[i][j-1].rgbtGreen; opGreen[1][1] = temp[i][j].rgbtGreen; opGreen[1][2] = temp[i][j+1].rgbtGreen; opGreen[2][0] = temp[i+1][j-1].rgbtGreen; opGreen[2][1] = temp[i+1][j].rgbtGreen; opGreen[2][2] = temp[i+1][j+1].rgbtGreen;
                opBlue[1][0] = temp[i][j-1].rgbtBlue; opBlue[1][1] = temp[i][j].rgbtBlue; opBlue[1][2] = temp[i][j+1].rgbtBlue; opBlue[2][0] = temp[i+1][j-1].rgbtBlue; opBlue[2][1] = temp[i+1][j].rgbtBlue; opBlue[2][2] = temp[i+1][j+1].rgbtBlue;
            }
            else if (i == 0 && j == width-1) // top right corner
            {
                opRed[1][0] = temp[i][j-1].rgbtRed; opRed[1][1] = temp[i][j].rgbtRed; opRed[2][0] = temp[i+1][j-1].rgbtRed; opRed[2][1] = temp[i+1][j].rgbtRed;
                opGreen[1][0] = temp[i][j-1].rgbtGreen; opGreen[1][1] = temp[i][j].rgbtGreen; opGreen[2][0] = temp[i+1][j-1].rgbtGreen; opGreen[2][1] = temp[i+1][j].rgbtGreen;
                opBlue[1][0] = temp[i][j-1].rgbtBlue; opBlue[1][1] = temp[i][j].rgbtBlue; opBlue[2][0] = temp[i+1][j-1].rgbtBlue; opBlue[2][1] = temp[i+1][j].rgbtBlue;
            }
            else if (i != 0 && i != height-1 && j == 0) // left edge
            {
                opRed[0][1] = temp[i-1][j].rgbtRed; opRed[0][2] = temp[i-1][j+1].rgbtRed; opRed[1][1] = temp[i][j].rgbtRed; opRed[1][2] = temp[i][j+1].rgbtRed; opRed[2][1] = temp[i+1][j].rgbtRed; opRed[2][2] = temp[i+1][j+1].rgbtRed;
                opGreen[0][1] = temp[i-1][j].rgbtGreen; opGreen[0][2] = temp[i-1][j+1].rgbtGreen; opGreen[1][1] = temp[i][j].rgbtGreen; opGreen[1][2] = temp[i][j+1].rgbtGreen; opGreen[2][1] = temp[i+1][j].rgbtGreen; opGreen[2][2] = temp[i+1][j+1].rgbtGreen;
                opBlue[0][1] = temp[i-1][j].rgbtBlue; opBlue[0][2] = temp[i-1][j+1].rgbtBlue; opBlue[1][1] = temp[i][j].rgbtBlue; opBlue[1][2] = temp[i][j+1].rgbtBlue; opBlue[2][1] = temp[i+1][j].rgbtBlue; opBlue[2][2] = temp[i+1][j+1].rgbtBlue;
            }
            else if (i != 0 && i != height-1 && j == width-1) // right edge
            {
                opRed[0][0] = temp[i-1][j-1].rgbtRed; opRed[0][1] = temp[i-1][j].rgbtRed; opRed[1][0] = temp[i][j-1].rgbtRed; opRed[1][1] = temp[i][j].rgbtRed; opRed[2][0] = temp[i+1][j-1].rgbtRed; opRed[2][1] = temp[i+1][j].rgbtRed;
                opGreen[0][0] = temp[i-1][j-1].rgbtGreen; opGreen[0][1] = temp[i-1][j].rgbtGreen; opGreen[1][0] = temp[i][j-1].rgbtGreen; opGreen[1][1] = temp[i][j].rgbtGreen; opGreen[2][0] = temp[i+1][j-1].rgbtGreen; opGreen[2][1] = temp[i+1][j].rgbtGreen;
                opBlue[0][0] = temp[i-1][j-1].rgbtBlue; opBlue[0][1] = temp[i-1][j].rgbtBlue; opBlue[1][0] = temp[i][j-1].rgbtBlue; opBlue[1][1] = temp[i][j].rgbtBlue; opBlue[2][0] = temp[i+1][j-1].rgbtBlue; opBlue[2][1] = temp[i+1][j].rgbtBlue;
            }
            else if (i == height-1 && j == 0) // bottom left corner
            {
                opRed[0][1] = temp[i-1][j].rgbtRed; opRed[0][2] = temp[i-1][j+1].rgbtRed; opRed[1][1] = temp[i][j].rgbtRed; opRed[1][2] = temp[i][j+1].rgbtRed;
                opGreen[0][1] = temp[i-1][j].rgbtGreen; opGreen[0][2] = temp[i-1][j+1].rgbtGreen; opGreen[1][1] = temp[i][j].rgbtGreen; opGreen[1][2] = temp[i][j+1].rgbtGreen;
                opBlue[0][1] = temp[i-1][j].rgbtBlue; opBlue[0][2] = temp[i-1][j+1].rgbtBlue; opBlue[1][1] = temp[i][j].rgbtBlue; opBlue[1][2] = temp[i][j+1].rgbtBlue;
            }
            else if (i == height-1 && j == width-1) // bottom right corner
            {
                opRed[0][0] = temp[i-1][j-1].rgbtRed; opRed[0][1] = temp[i-1][j].rgbtRed; opRed[1][0] = temp[i][j-1].rgbtRed; opRed[1][1] = temp[i][j].rgbtRed;
                opGreen[0][0] = temp[i-1][j-1].rgbtGreen; opGreen[0][1] = temp[i-1][j].rgbtGreen; opGreen[1][0] = temp[i][j-1].rgbtGreen; opGreen[1][1] = temp[i][j].rgbtGreen;
                opBlue[0][0] = temp[i-1][j-1].rgbtBlue; opBlue[0][1] = temp[i-1][j].rgbtBlue; opBlue[1][0] = temp[i][j-1].rgbtBlue; opBlue[1][1] = temp[i][j].rgbtBlue;
            }
            else if (i == height-1 && j != 0 && j != width-1) // bottom edge
            {
                opRed[0][0] = temp[i-1][j-1].rgbtRed; opRed[0][1] = temp[i-1][j].rgbtRed; opRed[0][2] = temp[i-1][j+1].rgbtRed; opRed[1][0] = temp[i][j-1].rgbtRed; opRed[1][1] = temp[i][j].rgbtRed; opRed[1][2] = temp[i][j+1].rgbtRed;
                opGreen[0][0] = temp[i-1][j-1].rgbtGreen; opGreen[0][1] = temp[i-1][j].rgbtGreen; opGreen[0][2] = temp[i-1][j+1].rgbtGreen; opGreen[1][0] = temp[i][j-1].rgbtGreen; opGreen[1][1] = temp[i][j].rgbtGreen; opGreen[1][2] = temp[i][j+1].rgbtGreen;
                opBlue[0][0] = temp[i-1][j-1].rgbtBlue; opBlue[0][1] = temp[i-1][j].rgbtBlue; opBlue[0][2] = temp[i-1][j+1].rgbtBlue; opBlue[1][0] = temp[i][j-1].rgbtBlue; opBlue[1][1] = temp[i][j].rgbtBlue; opBlue[1][2] = temp[i][j+1].rgbtBlue;
            }
            else
            {
                opRed[0][0] = temp[i-1][j-1].rgbtRed; opRed[0][1] = temp[i-1][j].rgbtRed; opRed[0][2] = temp[i-1][j+1].rgbtRed; opRed[1][0] = temp[i][j-1].rgbtRed; opRed[1][1] = temp[i][j].rgbtRed; opRed[1][2] = temp[i][j+1].rgbtRed; opRed[2][0] = temp[i+1][j-1].rgbtRed; opRed[2][1] = temp[i+1][j].rgbtRed; opRed[2][2] = temp[i+1][j+1].rgbtRed;
                opGreen[0][0] = temp[i-1][j-1].rgbtGreen; opGreen[0][1] = temp[i-1][j].rgbtGreen; opGreen[0][2] = temp[i-1][j+1].rgbtGreen; opGreen[1][0] = temp[i][j-1].rgbtGreen; opGreen[1][1] = temp[i][j].rgbtGreen; opGreen[1][2] = temp[i][j+1].rgbtGreen; opGreen[2][0] = temp[i+1][j-1].rgbtGreen; opGreen[2][1] = temp[i+1][j].rgbtGreen; opGreen[2][2] = temp[i+1][j+1].rgbtGreen;
                opBlue[0][0] = temp[i-1][j-1].rgbtBlue; opBlue[0][1] = temp[i-1][j].rgbtBlue; opBlue[0][2] = temp[i-1][j+1].rgbtBlue; opBlue[1][0] = temp[i][j-1].rgbtBlue; opBlue[1][1] = temp[i][j].rgbtBlue; opBlue[1][2] = temp[i][j+1].rgbtBlue; opBlue[2][0] = temp[i+1][j-1].rgbtBlue; opBlue[2][1] = temp[i+1][j].rgbtBlue; opBlue[2][2] = temp[i+1][j+1].rgbtBlue;
            }

            int gxRed = 0;
            int gyRed = 0;
            int Gred = 0;

            int gxGreen = 0;
            int gyGreen = 0;
            int Ggreen = 0;

            int gxBlue = 0;
            int gyBlue = 0;
            int Gblue = 0;

            for (int m = 0; m < 3; m++)
            {
                for (int n = 0; n < 3; n++)
                {
                    gxRed += (GxK[m][n]* opRed[m][n]);
                    gyRed += (GyK[m][n]* opRed[m][n]);

                    gxGreen += (GxK[m][n]* opGreen[m][n]);
                    gyGreen += (GyK[m][n]* opGreen[m][n]);

                    gxBlue += (GxK[m][n]* opBlue[m][n]);
                    gyBlue += (GyK[m][n]* opBlue[m][n]);
                }
            }

            Gred = round(sqrt((gxRed*gxRed + gyRed*gyRed)));
            Ggreen = round(sqrt((gxGreen*gxGreen + gyGreen*gyGreen)));
            Gblue = round(sqrt((gxBlue*gxBlue + gyBlue*gyBlue)));

            if (Gred > 255)
            {
                Gred = 255;
            }

            if (Ggreen > 255)
            {
                Ggreen = 255;
            }

            if (Gblue > 255)
            {
                Gblue = 255;
            }

            image[i][j].rgbtRed = Gred;
            image[i][j].rgbtGreen = Ggreen;
            image[i][j].rgbtBlue = Gblue;

        }
    }
    return;
}
