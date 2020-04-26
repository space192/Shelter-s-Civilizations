#include "../prototypes.h"


void animation(BITMAP *image[4], BITMAP *buffer, t_defense *defense,int deplAffX, int deplAffY)
{
    double angleTemp;
    int NumeroImage;
    int i;
    int x=0;
    int y=0;
    BITMAP *temp;
    if(defense->type <= 3)
    {
        temp = create_bitmap(image[defense->type-1]->w/8, image[defense->type-1]->h/8);
    }
    else if(defense->type == 4)
    {
        temp = create_bitmap(image[0]->w/8, image[0]->h/8);
    }
    else if(defense->type == 5)
    {
        temp = create_bitmap(image[1]->w/8, image[1]->h/8);
    }
    else if(defense->type == 6)
    {
        temp = create_bitmap(image[2]->w/8, image[2]->h/8);
    }
    BITMAP *turret60 = create_bitmap(60,60);
    BITMAP *turret120 = create_bitmap(120,120);
    angleTemp = defense->angle * 1.40625;
    NumeroImage = (angleTemp / 5.625 )+ 1;
    if(defense->type != 3 && defense->type != 6)
    {
        for(i=1; i < NumeroImage; i++)
        {
            if(x >=temp->w*7)
            {
                x = 0;
                y+=temp->h;
            }
            else
            {
                x+=temp->w;
            }
        }
    }
    else
    {
        for(i=1; i < NumeroImage; i++)
        {
            if(y >=temp->h*7)
            {
                y = 0;
                x+=temp->w;
            }
            else
            {
                y+=temp->h;
            }
        }
    }
    if(defense->type <= 3)
    {
        blit(image[defense->type-1], temp, x, y, 0,0,temp->w, temp->h);
    }
    else if(defense->type == 4)
    {
        blit(image[0], temp, x, y, 0,0,temp->w, temp->h);
    }
    else if(defense->type == 5)
    {
        blit(image[1], temp, x, y, 0,0,temp->w, temp->h);
    }
    else if(defense->type == 6)
    {
        blit(image[2], temp, x, y, 0,0,temp->w, temp->h);
    }
    if(defense->type <= 3)
    {
        stretch_blit(temp, turret60,0,0,temp->w, temp->h, 0,0,turret60->w, turret60->h);
        masked_blit(turret60, buffer, 0,0,defense->x-turret60->w/2-deplAffX, defense->y-turret60->h/2-deplAffY, SCREEN_W, SCREEN_H);
    }
    else
    {
        stretch_blit(temp, turret120,0,0,temp->w, temp->h, 0,0,turret120->w, turret120->h);
        masked_blit(turret120, buffer, 0,0,defense->x-turret120->w/2-deplAffX, defense->y-turret120->h/2-deplAffY, SCREEN_W, SCREEN_H);
    }
    destroy_bitmap(turret60);
    destroy_bitmap(turret120);
    destroy_bitmap(temp);
}

