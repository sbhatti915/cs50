#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#define BlockSize 512

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover memory card \n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");

    if (file == NULL)
    {
        printf("File isn't there \n");
        return 1;
    }

    BYTE buffer[BlockSize];
    int imgCount = 0;
    FILE *outPicture = NULL;
    char filename[8];
    bool firstPic = false;

    while (fread(buffer, BlockSize, 1, file) == 1)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (firstPic == false)
            {
                firstPic = true;
            }
            else
            {
                fclose(outPicture);
            }

            sprintf(filename, "%03i.jpg", imgCount++);
            outPicture = fopen(filename, "w");

            if (outPicture == NULL)
            {
                return 1;
            }
            fwrite(buffer, BlockSize, 1, outPicture);
        }
        else if(firstPic == true)
        {
            fwrite(buffer, BlockSize, 1, outPicture);
        }
    }

    // close last jpeg file
    fclose(outPicture);

    fclose(file);

    // success
    return 0;

}
