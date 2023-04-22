
#include <iostream>
using namespace std;
int max(int num1, int num2);
int main()
{
   /*some speical coding tricks*/
   int a = 20;
   int b = sizeof(a)+6;
   int c=a>30? 1:15;
   int d = 5;
   int e;
   /* loop types*/
   int i=0;
   for(i=0;i<d;i++){
   	printf("GGWP%.10f\n",double(i));
   } 
   while (i>=0){
   	printf("Again\n");
   	i--;
   }
   do{
   	i+=1;
   	printf("%d\n",i);
   }
   while(i<-1);
   /*if else*/
   a = 100;
   if( a == 10 )
   {
   }
   else if( a == 20 )
   {
   }
   else
   {
   }

   /*switch */
   char grade = 'D';   
   switch(grade)
   {
   case 'A' :
      break;
   case 'B' :
   case 'C' :
      break;
   case 'D' :
      break;
   case 'F' :
      break;
   default :
      cout << "无效的成绩" << endl;
   }
 
   return 0;
}
/*function definition*/
int max(int num1, int num2) 
{
   int result; 
   if (num1 > num2)
      result = num1;
   else
      result = num2;
   return result; 
}
