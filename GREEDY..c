#include<stdio.h>
#define max 100
double computemaxvalue(double w,double weight[],double value[],double ratio[],int nitems)
{
 double cw=0;
 double cv=0;
 printf("\n Items considered are:");
 while(cw<w)
 {
  int item = getNextItem(weight,value,ratio,nitems);
  if(item==-1)
  {
   break;
  }
  printf("%d",item+1);
  if(cw+weight[item]<=w)
  {
   cw+=weight[item];
   cv+=value[item];
   ratio[item]=0;
  }
  else{
   cv+=(ratio[item]*(w-cw));
   cw+=(w-cw);
  break;
  }
 }
return cv;
}

int getNextItem(double weight[],double value[],double ratio[],int nitems)
{
 double highest=0;
 int index=-1;
 int i;
 for(i=0;i<nitems;i++)
 {
  if(ratio[i]>highest)
   {
    highest=ratio[i];
    index=i;
   }
  }
return index;
}



int main()
{ int i;
  int nitems;
 double w;
 double weight[max];
  double value[max];
 double ratio[max];
 printf("Enter the number of items\n");
scanf("%d",&nitems);
 printf("Enter the weight of items:\n");
 for(i=0;i<nitems;i++)
  scanf("%lf",&weight[i]);
 printf("Enter the values/profit of the items\n");
for(i=0;i<nitems;i++)
   scanf("%lf",&value[i]);
for(i=0;i<nitems;i++)
   ratio[i]=value[i]/weight[i];
printf("Enter the capacity of the knapsack");
  scanf("%lf",&w);
printf("\n The max value in a knapsack of capacity %2f is %2f \n",w,computemaxvalue(w,weight,value,ratio,nitems));
return 0;
}

