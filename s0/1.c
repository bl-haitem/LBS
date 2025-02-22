#include<stdio.h>
#include<string.h>

typedef struct 
{
    char name[50];
    int pop;
}city;

city cities[100];

void swap (city *a, city *b) {
city temp = *a;
*a = *b;
*b =temp;
}

void sort (city cities[] , int n){
    for ( int i = 0; i < n-1; i++)
    {
        for ( int j = 0; j < n-i-1; j++)
        {
            if (cities[j].pop>cities[j+1].pop)
            {
                swap(&cities[j], &cities[j+1]);
            }
            
        }
        
    }
    
}

int main (){
int n, i;   
city cities[100] ; 
printf("enter number of cities ");
scanf("%d", &n);
for ( i = 0; i < n; i++)
{
    printf("city name ");
    scanf(" %[^\n]", cities[i].name);
    printf("population ");
    scanf("%d", &cities[i].pop);
}
int j;
sort (cities, n);
printf("sorted city");
for ( j = 0; j < n; j++)
{
    printf("%s - %d ; ", cities[j].name, cities[j].pop);
}


return (0);
}