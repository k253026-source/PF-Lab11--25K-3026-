#include<stdio.h>
#include<string.h>

struct Employee {
    int id;
    char name[50];
    char dept[20];
    char desig[20];
    float salary;
    int joiningYear;
    char phone[15];
    char email[50];
};

int main(){
    struct Employee e[100];
    int n,i,choice;
    int currentYear = 2025; 

    printf("Enter number of employees: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("\nID: "); scanf("%d",&e[i].id);
        printf("Name: "); scanf("%s", e[i].name);
        printf("Department (IT/HR/Finance/Marketing/Operations): "); scanf("%s", e[i].dept);
        printf("Designation (Intern/Junior/Senior/Manager/Director): "); scanf("%s", e[i].desig);
        printf("Salary: "); scanf("%f",&e[i].salary);
        printf("Joining Year: "); scanf("%d",&e[i].joiningYear);
        printf("Phone: "); scanf("%s", e[i].phone);
        printf("Email: "); scanf("%s", e[i].email);
    }

    while(1){
        printf("\n1.Show All 2.Search Dept 3.Search Designation 4.Search Experience 5.Appraisal 0.Exit\nChoice: ");
        scanf("%d",&choice);
        if(choice==0) break;

        if(choice==1){
            for(i=0;i<n;i++){
                int exp = currentYear - e[i].joiningYear;
                printf("\nID:%d Name:%s Dept:%s Desig:%s Salary:%.2f Exp:%d\n", 
                    e[i].id, e[i].name, e[i].dept, e[i].desig, e[i].salary, exp);
            }
        }
        else if(choice==2){
            char d[20]; int f=0;
            printf("Enter Department: "); scanf("%s",d);
            for(i=0;i<n;i++){
                if(strcmp(e[i].dept,d)==0){
                    int exp = currentYear - e[i].joiningYear;
                    printf("ID:%d Name:%s Desig:%s Salary:%.2f Exp:%d\n", e[i].id, e[i].name, e[i].desig, e[i].salary, exp);
                    f=1;
                }
            }
            if(!f) printf("No employee found.\n");
        }
        else if(choice==3){
            char des[20]; int f=0;
            printf("Enter Designation: "); scanf("%s",des);
            for(i=0;i<n;i++){
                if(strcmp(e[i].desig,des)==0){
                    int exp = currentYear - e[i].joiningYear;
                    printf("ID:%d Name:%s Dept:%s Salary:%.2f Exp:%d\n", e[i].id, e[i].name, e[i].dept, e[i].salary, exp);
                    f=1;
                }
            }
            if(!f) printf("No employee found.\n");
        }
        else if(choice==4){
            int years; int f=0;
            printf("Enter minimum experience in years: "); scanf("%d",&years);
            for(i=0;i<n;i++){
                int exp = currentYear - e[i].joiningYear;
                if(exp >= years){
                    printf("ID:%d Name:%s Dept:%s Desig:%s Salary:%.2f Exp:%d\n", 
                        e[i].id, e[i].name, e[i].dept, e[i].desig, e[i].salary, exp);
                    f=1;
                }
            }
            if(!f) printf("No employee found.\n");
        }
        else if(choice==5){
            float percent; 
            printf("Enter appraisal percentage (5-15): "); 
            scanf("%f",&percent);
            for(i=0;i<n;i++){
                e[i].salary += e[i].salary * percent/100;
                printf("ID:%d Name:%s New Salary:%.2f\n", e[i].id, e[i].name, e[i].salary);
            }
        }
    }

    return 0;
}

