#include "login.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void reg()
{
    
    printf("Create Username: ");
    scanf("%s", &username);
    
    printf("Create a Password: ");
    scanf("%s", &password);

    // creates and opens file using username
    FILE *fptr = fopen("username.txt","a");

    //checks if there is any error opening the file
    if(fptr == NULL)
    {
        printf("file can't  be opened\n");
        exit(1);
    }
    //stores the user's information in text file
    fprintf(fptr,"Username: %s Password: %s\n",username , password);

    printf("You have successfully registered");

    fclose(fptr);


}

void login()
{
    printf("Enter your username: ");
    scanf("%s", &username);
    printf("Enter your password: ");
    scanf("%s", &password);
    FILE *fptr = fopen("username.txt","r+");
    //loops through the file line by line
    while(fgets(filecontent,sizeof(filecontent),fptr))
    {
            //checks whether correct username and password is entered
            if(strstr(filecontent,username)!=0 && strstr(filecontent,password)!=0)
            {
                printf("Login successfull\n");
            }
    }
    fclose(fptr);
    
}

int main()
{ 
  printf("Select option: \n     -1 to login\n     -2 to register\n");
  scanf("%d", &a);

  if(a == 1)
  {
     login();
  }
  else if(a == 2)
  {
      reg();
  }
  return 0;
}
