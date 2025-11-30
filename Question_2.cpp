#include<stdio.h>
#include<string.h>

struct Account {
    char name[50];
    int accNo;
    char type[20];
    float balance;
};

float minBalance(char type[]){
    if(strcmp(type,"Savings")==0) return 1000;
    if(strcmp(type,"Current")==0) return 5000;
    if(strcmp(type,"Fixed")==0) return 10000;
    return 0;
}

float interest(char type[], float bal){
    if(strcmp(type,"Savings")==0) return bal*0.04;
    if(strcmp(type,"Fixed")==0) return bal*0.07;
    return 0;
}

int main(){
    struct Account acc[100];
    int n, i, choice;

    printf("Enter number of accounts: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("\nName: "); scanf("%s", acc[i].name);
        printf("Account No: "); scanf("%d",&acc[i].accNo);
        printf("Type (Savings/Current/Fixed): "); scanf("%s", acc[i].type);

        float min = minBalance(acc[i].type);
        do{
            printf("Initial Balance (min %.2f): ", min);
            scanf("%f",&acc[i].balance);
        }while(acc[i].balance < min);
    }

    while(1){
        printf("\n1.Deposit 2.Withdraw 3.Show 4.Interest 0.Exit\nChoice: ");
        scanf("%d",&choice);
        if(choice==0) break;

        int ac,f=0; float amt;
        printf("Enter Account No: "); scanf("%d",&ac);

        for(i=0;i<n;i++){
            if(acc[i].accNo==ac){
                f=1;
                if(choice==1){
                    printf("Deposit Amount: "); scanf("%f",&amt);
                    acc[i].balance += amt;
                }
                else if(choice==2){
                    printf("Withdraw Amount: "); scanf("%f",&amt);
                    if(acc[i].balance-amt < minBalance(acc[i].type))
                        printf("Cannot withdraw, minimum balance required.\n");
                    else acc[i].balance -= amt;
                }
                else if(choice==3){
                    printf("Name:%s\nAccNo:%d\nType:%s\nBalance:%.2f\n",
                        acc[i].name, acc[i].accNo, acc[i].type, acc[i].balance);
                }
                else if(choice==4){
                    printf("Interest: %.2f\n", interest(acc[i].type, acc[i].balance));
                }
                break;
            }
        }
        if(!f) printf("Account not found!\n");
    }

    return 0;
}

