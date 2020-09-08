// Gas Station / Ciruclar tour of Petrol Pump

int tour(petrolPump p[],int n)
{
   //Your code here
   int deficit=0, leftInTank=0,start=0;
   for(int i=0;i<n;i++){
     //Petrol left in the tank currently
       leftInTank+=p[i].petrol-p[i].distance;

       /* If it goes negative, store it as deficit */
       if(leftInTank <0){
           start=i+1;
           deficit+=leftInTank;
           leftInTank=0;
       }
   }
   return leftInTank+deficit>=0?start:-1;
}
