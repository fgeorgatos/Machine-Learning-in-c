#include"header.h"

void recommendation()
{
 int unseen[MAX_UNSEEN],p,k,x,w,l,association[TOTAL_MOVIE+1],wc,wi=0,i1,wc1,t,i,j;
 for(i=0;i<MAX_USER-1;i++)
 {
   x=1;
   for(l=0;l<TOTAL_MOVIE;l++)
   {
     unseen[l]=0;
   }
   for(i1=0;i1<TOTAL_MOVIE;i1++)
   {
     association[i1]=0;
   }
   for(j=0;j<TOTAL_MOVIE;j++)
   {
     p=0;
    for(k=0;k<user[i].mcount-1;k++)
    {
      w=user[i].watchmovie[k];
      if(j==w)
     {  
       p++; 
       break;
     }
    }
    if(p==0)
    {
      unseen[x]=j;
      x++;
    }
   }  
   /*printf("\n user %d unseen movie\n",i);
   for(l=0;l<x-1;l++)
   {
     printf("%d  ",unseen[l]);
   }
   printf("\n Total Unseen Movie : %d\n",x);*/
   int sp,mp,m,movie_recommend[NO_OF_RECOMMENDED],tot_unseen,tot_movie;
   for(j=0;j<MAX_USER-1;j++)
   {
     wc=0; 
     if(i!=j)
     { 
       for(k=0;k<user[i].mcount;k++)
       {
         for(l=0;l<user[j].mcount;l++)
         { 
           if(user[i].watchmovie[k]==user[j].watchmovie[l])
           {
             wc++;
             break;
           }
         }
       }
       if(wc>=NSIMILARMOVIE)
       {
         for(l=0;l<user[j].mcount;l++)
         {
           wc1=0;
           for(k=0;k<user[i].mcount;k++)
           {
             if(user[i].watchmovie[k]==user[j].watchmovie[l])
             {
               wc1++;
               break;
             }
           }
           if(wc1==0)
           {
             wi=user[j].watchmovie[l];
             association[wi]=association[wi]+1;
           }
         }
       }
     }
   }
   /* printf("\nuser  %d association\n",i);
   for(i1=0;i1<TOTAL_MOVIE;i1++)
   {
    printf("%d ",association[i1]);
   }
   printf("\n");*/
   float score[TOTAL_MOVIE+1],sc,sc1,score_recommend[NO_OF_RECOMMENDED],sc2;
   tot_unseen=x;
   tot_movie=TOTAL_MOVIE;
   for(m=0;m<TOTAL_MOVIE;m++)
   {
     score[m]=0;
   }
   for(mp=0;mp<TOTAL_MOVIE;mp++)
   {
     if(association[mp]>0)
    {
      sc=(float)tot_unseen/tot_movie;
      sc1=(float)association[mp]/tot_unseen;
      score[mp]=sc*sc1;
    }
   }
   int tk,tp,t1;
   for(t=0;t<NO_OF_RECOMMENDED-1;t++)
   {
     sc2=0;
     for(tk=0;tk<TOTAL_MOVIE;tk++)
     {
       if(sc2<score[tk])
       {
         sc2=score[tk];
         tp=tk;
       }
     }
     movie_recommend[t]=tp;
     score_recommend[t]=sc2;
     score[tp]=0;
    }
    /* printf("\nuser  : %d Movie Recommended \nMovie id : ",i);
    for(t1=0;t1<NO_OF_RECOMMENDED-1;t1++)
    {
      printf("%d    ",movie_recommend[t1]);
    }*/
/*------------------------------------------------- Precision Calculation Part --------------------------------------------------------------*/
    printf(" User : %d \n",i);
    int pcount=user[i].mcount*TRAININGPERCENT;
    int pcount_test=user[i].mcount*TESTPERCENT;
    int save_movie_recommend[NO_OF_RECOMMENDED];
    for(t1=0;t1<NO_OF_RECOMMENDED-1;t1++)
    {
      save_movie_recommend[tp]=movie_recommend[tp];
    }
    printf("No. of Traing data : %d , No. of Test Data %d",pcount,pcount_test);
    printf("\n");
  }  //for loop i close
  printf("\n");
}
