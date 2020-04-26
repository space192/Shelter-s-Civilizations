#include "../../prototypes.h"

void gererDeplacement(int *deplAffX,int *deplAffY)
{
    if((key[KEY_UP]||(key[KEY_W]))&&(*deplAffY>0))
    {
        *deplAffY-=8;
    }
    if((key[KEY_DOWN]||(key[KEY_S]))&&(*deplAffY<2048))
    {
        *deplAffY+=8;
    }
    if((key[KEY_LEFT]||(key[KEY_A]))&&(*deplAffX>0))
    {
        *deplAffX-=8;
    }
    if((key[KEY_RIGHT]||(key[KEY_D]))&&(*deplAffX<2560))
    {
        *deplAffX+=8;
    }
}

void gererMusique(int *condition,int *musique,int voice[6])
{
    if(*condition==1)
    {
        voice_start(voice[*musique]);
        voice_set_volume(voice[*musique],50);
        *condition=0;
    }
    if(voice_get_position(voice[*musique])==-1)
    {
        if((*musique)<5)
        {
            (*musique)++;
        }
        if((*musique)==5)
        {
            (*musique)=0;
        }
        *condition = 1;
    }
}

void gererPause(BITMAP *page,int *pauseActive, BITMAP* pause[4], int *volumeMusique,int *musique,int voice[6])
{
    int x,y;
    if(*pauseActive ==0)
    {
        draw_sprite(page,pause[0],0,0);
    }
    if(*pauseActive !=0)
    {
        draw_sprite(page,pause[1],0,0);
    }
    if(*pauseActive ==1)
    {
        draw_sprite(page,pause[3],400,350);
    }
    if(*pauseActive ==2)
    {
        draw_sprite(page,pause[2],400,350);
        rectfill(page,584,461,584+((*volumeMusique)/2),461+10,makecol(255,255,255));
        rectfill(page,584+((*volumeMusique)/2),457,584+((*volumeMusique)/2)+15,457+18,makecol(180,180,180));
    }

    if((mouse_b & 1)&&(mouse_y >=0)&&(mouse_y <=60)&&(mouse_x >=0)&&(mouse_x <=60))
    {
        *pauseActive = 1;
    }


    /*if((mouse_b & 1))
    {
        x = mouse_x;
        y = mouse_y;
        printf("%d",x);
        printf(" %d\n",y);
    }*/

    if((mouse_b & 1)&&(mouse_y >=386)&&(mouse_y <470)&&(mouse_x >=500)&&(mouse_x <=710)&&(*pauseActive==1))
    {
        *pauseActive = 0;
    }
    if((mouse_b & 1)&&(mouse_y >=470)&&(mouse_y <533)&&(mouse_x >=500)&&(mouse_x <=710)&&(*pauseActive==1))
    {
        *pauseActive = 2;
    }
    if((mouse_b & 1)&&(mouse_y >=372)&&(mouse_y <404)&&(mouse_x >=535)&&(mouse_x <=668)&&(*pauseActive==2))
    {
        *pauseActive = 0;
    }
    if((mouse_b & 1)&&(mouse_y >=461)&&(mouse_y <481)&&(mouse_x >=584)&&(mouse_x <=710)&&(*pauseActive==2))
    {
        *volumeMusique = (mouse_x-584)*2;
        voice_set_volume(voice[*musique],*volumeMusique);
    }
}
