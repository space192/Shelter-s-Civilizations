#include "../../prototypes.h"


void afficherLayoutMenu(BITMAP* page,BITMAP* layoutMenu,BITMAP* miniMap, int deplAffX,int deplAffY,t_joueur joueur)
{
    draw_sprite(page,layoutMenu,220,0);
    textprintf_ex(page,font,310,20,makecol(255,255,255),-1,"%d",joueur.or);
    textprintf_ex(page,font,310,42,makecol(255,255,255),-1,"%d",joueur.metal);
    textprintf_ex(page,font,310,65,makecol(255,255,255),-1,"%d",joueur.pierre);

    draw_sprite(page, miniMap,1103,0);
    rect(page,1104+(deplAffX/22),2+deplAffY/21,1104+59+(deplAffX/22),2+50+deplAffY/21,makecol(255,0,0));
}

void afficherInfoBatimentBR(BITMAP* page)
{
    if(((mouse_y >=18)&&(mouse_y <=76)&&(mouse_x >=402)&&(mouse_x <=462)))
        {
            rectfill(page,402,100,552,200,makecol(0,0,0));
            textprintf_ex(page,font,412,125,makecol(255,255,255),-1,"Coute:  100 OR");
            textprintf_ex(page,font,412,150,makecol(255,255,255),-1,"Produit: Or");
            textprintf_ex(page,font,412,175,makecol(255,255,255),-1,"Niveau : 1");
        }
        else if(((mouse_y >=18)&&(mouse_y <=76)&&(mouse_x >=464)&&(mouse_x <=524)))
        {
            rectfill(page,464,100,614,200,makecol(0,0,0));
            textprintf_ex(page,font,474,125,makecol(255,255,255),-1,"Coute:  80 OR");
            textprintf_ex(page,font,474,150,makecol(255,255,255),-1,"Produit: Metal");
            textprintf_ex(page,font,474,175,makecol(255,255,255),-1,"Niveau : 1");

        }
        else if(((mouse_y >=18)&&(mouse_y <=76)&&(mouse_x >=526)&&(mouse_x <=586)))
        {
            rectfill(page,526,100,676,200,makecol(0,0,0));
            textprintf_ex(page,font,536,125,makecol(255,255,255),-1,"Coute:  70 OR");
            textprintf_ex(page,font,536,150,makecol(255,255,255),-1,"Produit: Pierre");
            textprintf_ex(page,font,536,175,makecol(255,255,255),-1,"Niveau : 1");

        }
        else if(((mouse_y >=18)&&(mouse_y <=76)&&(mouse_x >=588)&&(mouse_x <=648)))
        {
            rectfill(page,588,100,738,200,makecol(0,0,0));
            textprintf_ex(page,font,598,125,makecol(255,255,255),-1,"Coute:  200 OR");
            textprintf_ex(page,font,598,150,makecol(255,255,255),-1,"Produit: Or");
            textprintf_ex(page,font,598,175,makecol(255,255,255),-1,"Niveau : 2");

        }
        else if(((mouse_y >=18)&&(mouse_y <=76)&&(mouse_x >=650)&&(mouse_x <=710)))
        {
            rectfill(page,650,100,800,200,makecol(0,0,0));
            textprintf_ex(page,font,660,125,makecol(255,255,255),-1,"Coute:  160 OR");
            textprintf_ex(page,font,660,150,makecol(255,255,255),-1,"Produit: Metal");
            textprintf_ex(page,font,660,175,makecol(255,255,255),-1,"Niveau : 2");

        }
        else if(((mouse_y >=18)&&(mouse_y <=76)&&(mouse_x >=712)&&(mouse_x <=772)))
        {
            rectfill(page,712,100,862,200,makecol(0,0,0));
            textprintf_ex(page,font,722,125,makecol(255,255,255),-1,"Coute:  140 OR");
            textprintf_ex(page,font,722,150,makecol(255,255,255),-1,"Produit: Pierre");
            textprintf_ex(page,font,722,175,makecol(255,255,255),-1,"Niveau : 2");

        }
        if(((mouse_y >=18)&&(mouse_y <=76)&&(mouse_x >=774)&&(mouse_x <=834)))
        {
            rectfill(page,774,100,924,200,makecol(0,0,0));
            textprintf_ex(page,font,784,125,makecol(255,255,255),-1,"Coute:  300 OR");
            textprintf_ex(page,font,784,150,makecol(255,255,255),-1,"Produit: Or");
            textprintf_ex(page,font,784,175,makecol(255,255,255),-1,"Niveau : 3");

        }
        else if(((mouse_y >=18)&&(mouse_y <=76)&&(mouse_x >=836)&&(mouse_x <=896)))
        {
            rectfill(page,836,100,986,200,makecol(0,0,0));
            textprintf_ex(page,font,846,125,makecol(255,255,255),-1,"Coute:  240 OR");
            textprintf_ex(page,font,846,150,makecol(255,255,255),-1,"Produit: Metal");
            textprintf_ex(page,font,846,175,makecol(255,255,255),-1,"Niveau : 3");

        }
        else if(((mouse_y >=18)&&(mouse_y <=76)&&(mouse_x >=898)&&(mouse_x <=958)))
        {
            rectfill(page,898,100,1048,200,makecol(0,0,0));
            textprintf_ex(page,font,908,125,makecol(255,255,255),-1,"Coute:  210 OR");
            textprintf_ex(page,font,908,150,makecol(255,255,255),-1,"Produit: Pierre");
            textprintf_ex(page,font,908,175,makecol(255,255,255),-1,"Niveau : 3");

        }
}


void afficherInfoBatimentD(BITMAP* page)
{
    if(((mouse_y >=18)&&(mouse_y <=76)&&(mouse_x >=402)&&(mouse_x <=462)))
        {
            rectfill(page,402,100,552,200,makecol(0,0,0));
            textprintf_ex(page,font,412,125,makecol(255,255,255),-1,"Coute:  70 Metal");
            textprintf_ex(page,font,412,150,makecol(255,255,255),-1,"Type: Double canon");
            textprintf_ex(page,font,412,175,makecol(255,255,255),-1,"Niveau : 1");
        }
        else if(((mouse_y >=18)&&(mouse_y <=76)&&(mouse_x >=464)&&(mouse_x <=524)))
        {
            rectfill(page,464,100,614,200,makecol(0,0,0));
            textprintf_ex(page,font,474,125,makecol(255,255,255),-1,"Coute:  80 Metal");
            textprintf_ex(page,font,474,150,makecol(255,255,255),-1,"Type: Laser");
            textprintf_ex(page,font,474,175,makecol(255,255,255),-1,"Niveau : 1");

        }
        else if(((mouse_y >=18)&&(mouse_y <=76)&&(mouse_x >=526)&&(mouse_x <=586)))
        {
            rectfill(page,526,100,676,200,makecol(0,0,0));
            textprintf_ex(page,font,536,125,makecol(255,255,255),-1,"Coute:  90 Metal");
            textprintf_ex(page,font,536,150,makecol(255,255,255),-1,"Type: Mitraillette");
            textprintf_ex(page,font,536,175,makecol(255,255,255),-1,"Niveau : 1");

        }
        else if(((mouse_y >=18)&&(mouse_y <=76)&&(mouse_x >=588)&&(mouse_x <=648)))
        {
            rectfill(page,588,100,738,200,makecol(0,0,0));
            textprintf_ex(page,font,598,125,makecol(255,255,255),-1,"Coute:  140 Metal");
            textprintf_ex(page,font,598,150,makecol(255,255,255),-1,"Type: Double canon");
            textprintf_ex(page,font,598,175,makecol(255,255,255),-1,"Niveau : 2");

        }
        else if(((mouse_y >=18)&&(mouse_y <=76)&&(mouse_x >=650)&&(mouse_x <=710)))
        {
            rectfill(page,650,100,800,200,makecol(0,0,0));
            textprintf_ex(page,font,660,125,makecol(255,255,255),-1,"Coute:  160 Metal");
            textprintf_ex(page,font,660,150,makecol(255,255,255),-1,"Type: Laser");
            textprintf_ex(page,font,660,175,makecol(255,255,255),-1,"Niveau : 2");

        }
        else if(((mouse_y >=18)&&(mouse_y <=76)&&(mouse_x >=712)&&(mouse_x <=772)))
        {
            rectfill(page,712,100,862,200,makecol(0,0,0));
            textprintf_ex(page,font,722,125,makecol(255,255,255),-1,"Coute:  180 Metal");
            textprintf_ex(page,font,722,150,makecol(255,255,255),-1,"Type: Mitrailette");
            textprintf_ex(page,font,722,175,makecol(255,255,255),-1,"Niveau : 2");

        }
}


