#include "../../prototypes.h"


void afficherLayoutMenu(BITMAP* page,BITMAP* layoutMenu[3],BITMAP* miniMap,t_borne borne,char *PseudoJoueur,int score, int deplAffX,int deplAffY,t_joueur joueur,t_listeMechant *horde,t_listedef *liste2,int PDV,int agrandissement)
{
    t_ennemi *actuel = horde->premier;
    t_defense *actuel2 =liste2->premier;

    draw_sprite(page,layoutMenu[0],220,0);
    draw_sprite(page,layoutMenu[1],400,969);

    textprintf_ex(page,font,425,980,makecol(255,255,255),-1,"Points de vie de la muraille:");
    if(agrandissement==0)
    {
        if(PDV<=2500)
        {
            rectfill(page,425,995,425 + (PDV*0.04),1005,makecol(255,0,0));
        }
        else
        {
            rectfill(page,425,995,425 + (PDV*0.04),1005,makecol(0,255,0));
        }

    }
    else if(agrandissement==1)
    {
        if(PDV<=5000)
        {
            rectfill(page,425,995,425 + (PDV*0.02),1005,makecol(255,0,0));
        }
        else
        {
            rectfill(page,425,995,425 + (PDV*0.02),1005,makecol(0,255,0));
        }

    }
    else if(agrandissement==2)
    {
        if(PDV<=7500)
        {
            rectfill(page,425,995,425 + (PDV*0.0133333333),1005,makecol(255,0,0));
        }
        else
        {
            rectfill(page,425,995,425 + (PDV*0.0133333333),1005,makecol(0,255,0));
        }

    }


    textprintf_ex(page,font,310,20,makecol(255,255,255),-1,"%d",joueur.or);
    textprintf_ex(page,font,310,42,makecol(255,255,255),-1,"%d",joueur.metal);
    textprintf_ex(page,font,310,65,makecol(255,255,255),-1,"%d",joueur.pierre);

    draw_sprite(page, miniMap,1103,0);
    draw_sprite(page, layoutMenu[2],1103,151);

    textprintf_ex(page,font,1113,161,makecol(255,255,255),-1,"%s",PseudoJoueur);
    textprintf_ex(page,font,1113,176,makecol(255,255,255),-1,"Score actuel :%d", (score+(PDV/5)+(joueur.or/10)+(joueur.metal/10)+(joueur.pierre/10)));
    textprintf_ex(page,font,1113,191,makecol(255,255,255),-1,"Vagues restantes: %d",horde->nbVague);

    rect(page,1104+(deplAffX/22),2+deplAffY/21,1104+59+(deplAffX/22),2+50+deplAffY/21,makecol(255,0,0));

    while(actuel!=NULL)
    {
        rectfill(page,1104+(actuel->x/22),actuel->y/21 - 4,1104+2+(actuel->x/22),actuel->y/21 - 2,makecol(255,0,0));
        actuel=actuel->suivant;
    }

    while(actuel2!=NULL)
    {
        rectfill(page,1104+(actuel2->x/22),actuel2->y/21 - 4,1104+2+(actuel2->x/22),actuel2->y/21 - 2,makecol(0,255,0));
        actuel2=actuel2->suivant;
    }

    rectfill(page,1104+(borne.xDeb/22),(borne.yDeb/21)-2,1114+(borne.xFin/22),2+(borne.yFin/21),makecol(200,200,200));

    actuel = NULL;
    free(actuel);
    actuel2 = NULL;
    free(actuel2);
}

void afficherInfoBatimentBR(BITMAP* page)
{
    if(((mouse_y >=18)&&(mouse_y <=76)&&(mouse_x >=402)&&(mouse_x <=462)))
        {
            rectfill(page,400,98,554,202,makecol(255,255,255));
            rectfill(page,402,100,552,200,makecol(0,0,0));
            textprintf_ex(page,font,412,125,makecol(255,255,255),-1,"Coute:  100 OR");
            textprintf_ex(page,font,412,150,makecol(255,255,255),-1,"Produit: Or");
            textprintf_ex(page,font,412,175,makecol(255,255,255),-1,"Niveau : 1");
        }
        else if(((mouse_y >=18)&&(mouse_y <=76)&&(mouse_x >=464)&&(mouse_x <=524)))
        {
            rectfill(page,462,98,616,202,makecol(255,255,255));
            rectfill(page,464,100,614,200,makecol(0,0,0));
            textprintf_ex(page,font,474,125,makecol(255,255,255),-1,"Coute:  80 OR");
            textprintf_ex(page,font,474,150,makecol(255,255,255),-1,"Produit: Metal");
            textprintf_ex(page,font,474,175,makecol(255,255,255),-1,"Niveau : 1");

        }
        else if(((mouse_y >=18)&&(mouse_y <=76)&&(mouse_x >=526)&&(mouse_x <=586)))
        {
            rectfill(page,524,98,678,202,makecol(255,255,255));
            rectfill(page,526,100,676,200,makecol(0,0,0));
            textprintf_ex(page,font,536,125,makecol(255,255,255),-1,"Coute:  70 OR");
            textprintf_ex(page,font,536,150,makecol(255,255,255),-1,"Produit: Pierre");
            textprintf_ex(page,font,536,175,makecol(255,255,255),-1,"Niveau : 1");

        }
        else if(((mouse_y >=18)&&(mouse_y <=76)&&(mouse_x >=588)&&(mouse_x <=648)))
        {
            rectfill(page,584,98,740,202,makecol(255,255,255));
            rectfill(page,588,100,738,200,makecol(0,0,0));
            textprintf_ex(page,font,598,125,makecol(255,255,255),-1,"Coute:  200 OR");
            textprintf_ex(page,font,598,150,makecol(255,255,255),-1,"Produit: Or");
            textprintf_ex(page,font,598,175,makecol(255,255,255),-1,"Niveau : 2");

        }
        else if(((mouse_y >=18)&&(mouse_y <=76)&&(mouse_x >=650)&&(mouse_x <=710)))
        {
            rectfill(page,648,98,802,202,makecol(255,255,255));
            rectfill(page,650,100,800,200,makecol(0,0,0));
            textprintf_ex(page,font,660,125,makecol(255,255,255),-1,"Coute:  160 OR");
            textprintf_ex(page,font,660,150,makecol(255,255,255),-1,"Produit: Metal");
            textprintf_ex(page,font,660,175,makecol(255,255,255),-1,"Niveau : 2");

        }
        else if(((mouse_y >=18)&&(mouse_y <=76)&&(mouse_x >=712)&&(mouse_x <=772)))
        {
            rectfill(page,710,98,864,202,makecol(255,255,255));
            rectfill(page,712,100,862,200,makecol(0,0,0));
            textprintf_ex(page,font,722,125,makecol(255,255,255),-1,"Coute:  140 OR");
            textprintf_ex(page,font,722,150,makecol(255,255,255),-1,"Produit: Pierre");
            textprintf_ex(page,font,722,175,makecol(255,255,255),-1,"Niveau : 2");

        }
        if(((mouse_y >=18)&&(mouse_y <=76)&&(mouse_x >=774)&&(mouse_x <=834)))
        {
            rectfill(page,772,98,926,202,makecol(255,255,255));
            rectfill(page,774,100,924,200,makecol(0,0,0));
            textprintf_ex(page,font,784,125,makecol(255,255,255),-1,"Coute:  300 OR");
            textprintf_ex(page,font,784,150,makecol(255,255,255),-1,"Produit: Or");
            textprintf_ex(page,font,784,175,makecol(255,255,255),-1,"Niveau : 3");

        }
        else if(((mouse_y >=18)&&(mouse_y <=76)&&(mouse_x >=836)&&(mouse_x <=896)))
        {
            rectfill(page,834,98,988,202,makecol(255,255,255));
            rectfill(page,836,100,986,200,makecol(0,0,0));
            textprintf_ex(page,font,846,125,makecol(255,255,255),-1,"Coute:  240 OR");
            textprintf_ex(page,font,846,150,makecol(255,255,255),-1,"Produit: Metal");
            textprintf_ex(page,font,846,175,makecol(255,255,255),-1,"Niveau : 3");

        }
        else if(((mouse_y >=18)&&(mouse_y <=76)&&(mouse_x >=898)&&(mouse_x <=958)))
        {
            rectfill(page,896,98,1050,202,makecol(255,255,255));
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
            rectfill(page,400,98,554,202,makecol(255,255,255));
            rectfill(page,402,100,552,200,makecol(0,0,0));
            textprintf_ex(page,font,412,125,makecol(255,255,255),-1,"Coute:  70 Metal");
            textprintf_ex(page,font,412,150,makecol(255,255,255),-1,"Type: Double canon");
            textprintf_ex(page,font,412,175,makecol(255,255,255),-1,"Niveau : 1");
        }
        else if(((mouse_y >=18)&&(mouse_y <=76)&&(mouse_x >=464)&&(mouse_x <=524)))
        {
            rectfill(page,462,98,616,202,makecol(255,255,255));
            rectfill(page,464,100,614,200,makecol(0,0,0));
            textprintf_ex(page,font,474,125,makecol(255,255,255),-1,"Coute:  80 Metal");
            textprintf_ex(page,font,474,150,makecol(255,255,255),-1,"Type: Laser");
            textprintf_ex(page,font,474,175,makecol(255,255,255),-1,"Niveau : 1");

        }
        else if(((mouse_y >=18)&&(mouse_y <=76)&&(mouse_x >=526)&&(mouse_x <=586)))
        {
            rectfill(page,524,98,678,202,makecol(255,255,255));
            rectfill(page,526,100,676,200,makecol(0,0,0));
            textprintf_ex(page,font,536,125,makecol(255,255,255),-1,"Coute:  90 Metal");
            textprintf_ex(page,font,536,150,makecol(255,255,255),-1,"Type: Mitraillette");
            textprintf_ex(page,font,536,175,makecol(255,255,255),-1,"Niveau : 1");

        }
        else if(((mouse_y >=18)&&(mouse_y <=76)&&(mouse_x >=588)&&(mouse_x <=648)))
        {
            rectfill(page,584,98,740,202,makecol(255,255,255));
            rectfill(page,588,100,738,200,makecol(0,0,0));
            textprintf_ex(page,font,598,125,makecol(255,255,255),-1,"Coute:  140 Metal");
            textprintf_ex(page,font,598,150,makecol(255,255,255),-1,"Type: Double canon");
            textprintf_ex(page,font,598,175,makecol(255,255,255),-1,"Niveau : 2");

        }
        else if(((mouse_y >=18)&&(mouse_y <=76)&&(mouse_x >=650)&&(mouse_x <=710)))
        {
            rectfill(page,648,98,802,202,makecol(255,255,255));
            rectfill(page,650,100,800,200,makecol(0,0,0));
            textprintf_ex(page,font,660,125,makecol(255,255,255),-1,"Coute:  160 Metal");
            textprintf_ex(page,font,660,150,makecol(255,255,255),-1,"Type: Laser");
            textprintf_ex(page,font,660,175,makecol(255,255,255),-1,"Niveau : 2");

        }
        else if(((mouse_y >=18)&&(mouse_y <=76)&&(mouse_x >=712)&&(mouse_x <=772)))
        {
            rectfill(page,710,98,864,202,makecol(255,255,255));
            rectfill(page,712,100,862,200,makecol(0,0,0));
            textprintf_ex(page,font,722,125,makecol(255,255,255),-1,"Coute:  180 Metal");
            textprintf_ex(page,font,722,150,makecol(255,255,255),-1,"Type: Mitrailette");
            textprintf_ex(page,font,722,175,makecol(255,255,255),-1,"Niveau : 2");

        }
}

void afficherInfo(BITMAP* page)
{
    if(((mouse_y >=18)&&(mouse_y <=76)&&(mouse_x >=402)&&(mouse_x <=462)))
        {
            rectfill(page,400,98,592,202,makecol(255,255,255));
            rectfill(page,402,100,590,200,makecol(0,0,0));

            textprintf_ex(page,font,412,125,makecol(255,255,255),-1,"Permet de construire:");
            textprintf_ex(page,font,412,150,makecol(255,255,255),-1,"Batiment de production");

        }
        else if(((mouse_y >=18)&&(mouse_y <=76)&&(mouse_x >=464)&&(mouse_x <=524)))
        {
            rectfill(page,462,98,646,202,makecol(255,255,255));
            rectfill(page,464,100,644,200,makecol(0,0,0));
            textprintf_ex(page,font,474,125,makecol(255,255,255),-1,"Permet de construire:");
            textprintf_ex(page,font,474,150,makecol(255,255,255),-1,"Batiments de defense");

        }
        else if(((mouse_y >=18)&&(mouse_y <=76)&&(mouse_x >=526)&&(mouse_x <=586)))
        {
            rectfill(page,524,98,708,202,makecol(255,255,255));
            rectfill(page,526,100,706,200,makecol(0,0,0));
            textprintf_ex(page,font,536,125,makecol(255,255,255),-1,"Permet de construire:");
            textprintf_ex(page,font,536,150,makecol(255,255,255),-1,"Fondations");

        }
        else if(((mouse_y >=18)&&(mouse_y <=76)&&(mouse_x >=588)&&(mouse_x <=648)))
        {
            rectfill(page,586,98,810,142,makecol(255,255,255));
            rectfill(page,588,100,808,140,makecol(0,0,0));
            textprintf_ex(page,font,598,125,makecol(255,255,255),-1,"Amelioration de batiments");


        }
        else if(((mouse_y >=18)&&(mouse_y <=76)&&(mouse_x >=650)&&(mouse_x <=710)))
        {
            rectfill(page,648,98,852,142,makecol(255,255,255));
            rectfill(page,650,100,850,140,makecol(0,0,0));
            textprintf_ex(page,font,660,125,makecol(255,255,255),-1,"Supression de batiments");


        }
        else if(((mouse_y >=18)&&(mouse_y <=76)&&(mouse_x >=712)&&(mouse_x <=772)))
        {
            rectfill(page,710,98,934,142,makecol(255,255,255));
            rectfill(page,712,100,932,140,makecol(0,0,0));
            textprintf_ex(page,font,722,125,makecol(255,255,255),-1,"Deplacements de batiments");
        }
        if(((mouse_y >=18)&&(mouse_y <=76)&&(mouse_x >=774)&&(mouse_x <=834)))
        {
            rectfill(page,772,98,956,202,makecol(255,255,255));
            rectfill(page,774,100,954,200,makecol(0,0,0));
            textprintf_ex(page,font,784,125,makecol(255,255,255),-1,"Agrandir votre base");
            textprintf_ex(page,font,784,150,makecol(255,255,255),-1,"Coute : 1300 pierres");

        }

}


