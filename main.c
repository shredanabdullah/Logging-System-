#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<windows.h>

struct user{
  char fullName[50];
  char email[100];
  char password[50];
  char passwordCheck[50];
  char userName[50];
  char phoneNumber[11];
};

void generateUserName(char email[100],char username[50]){
 for(int i=0;i<strlen(email);i++){
    if(email[i]=='@') break;
    else username[i]=email[i];
 }
}

int main()
{
    system("color 6F");
    FILE *fp;
    int choice;
    int userFound=0;
    char userName[50];
    char password[50];
    struct user userObj;

    printf("\n\t\t\t-------------------- Welcome to our Logging system --------------------\n");
    printf("\n   If you don't have account please sign up first\n");
    printf("\n   If you already have an account please login in\n");
    printf("\nChoose your operation");
    printf("\n1.Sign Up");
    printf("\n2.Login In");
    printf("\n3.Exit");
    printf("\n\nEnter your choice: ");
    scanf("%d",&choice);

    switch(choice){
        case 1:
              system("cls");
              printf("Enter your Full name: ");
              scanf(" %[^\n]s", userObj.fullName); // Read the entire line including spaces
              printf("Enter your Email: ");
              scanf(" %[^\n]s", userObj.email);
              printf("Enter your phone number: ");
              scanf(" %[^\n]s", userObj.phoneNumber);
              printf("Set your password: ");
              scanf(" %[^\n]s", userObj.password);
              printf("Confirm your password: ");
              scanf(" %[^\n]s", userObj.passwordCheck);
              if (!strcmp(userObj.password,userObj.passwordCheck))
                {
                    printf("\nyour password is matched!");
                    generateUserName(userObj.email,userObj.userName);
                    fp=fopen("Users.dat","a+");
                    fwrite(&userObj,sizeof(struct user),1,fp);
                        if(fwrite!=0)  printf("\nyour user name is %s",userObj.userName);
                        else {
                                printf("\nsomething went wrong");
                                fclose(fp);
                                Beep(650,250);}
                }
              else printf("\npassword is not matched.");
            break;

        case 2:
            printf("Enter your user name: ");
            scanf(" %[^\n]", userName); // Read the entire line including spaces
            printf("Enter your password: ");
            scanf(" %[^\n]", password);
            fp=fopen("Users.dat","r");

            while (fread(&userObj, sizeof(struct user), 1, fp)) {
                if (!strcmp(userObj.userName, userName)){
                    if (!strcmp(userObj.password, password)){
                        system("cls");
                        printf("\n\t\t\tWelcome %s ", userObj.fullName);
                        printf("\n\t\tFull Name: %s ", userObj.fullName);
                        printf("\n\t\tEmail: %s ", userObj.email);
                        printf("\n\t\tUser Name: %s ", userObj.userName);
                        printf("\n\t\tPhone Number: %s ", userObj.phoneNumber);
                        userFound = 1;
                        }
                    else {
                            printf("\nInvalid password or username");
                            Beep(650, 250);
                        }
                }
           }

            if (!userFound) {
                printf("\nInvalid user");
                Beep(650, 250);
            }

            fclose(fp);

                break;
        case 3:
                printf("Thank You!,Bye!");
                return 0;
    }

    return 0;
}
