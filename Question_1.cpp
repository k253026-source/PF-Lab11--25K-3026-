#include<stdio.h>
#include<string.h>

struct Student {
    char name[50];
    int roll;
    int m1, m2, m3;
    float per;
    char grade[3];
};

char* getGrade(float p) {
    if(p >= 90) return "A+";
    else if(p >= 80) return "A";
    else if(p >= 70) return "B+";
    else if(p >= 60) return "B";
    else if(p >= 50) return "C";
    else return "F";
}

int main() {
    struct Student s[100];
    int n, i, choice;
    float avg = 0;

    printf("Enter number of students: ");
    scanf("%d", &n);

    for(i=0;i<n;i++){
        printf("\nEnter name: ");
        scanf("%s", s[i].name);

        printf("Enter roll number: ");
        scanf("%d", &s[i].roll);

        
        do{
            printf("Enter marks in 3 subjects: ");
            scanf("%d %d %d", &s[i].m1, &s[i].m2, &s[i].m3);
        }while(s[i].m1<0 || s[i].m1>100 || s[i].m2<0 || s[i].m2>100 || s[i].m3<0 || s[i].m3>100);

        s[i].per = (s[i].m1 + s[i].m2 + s[i].m3) / 3.0;
        strcpy(s[i].grade, getGrade(s[i].per));

        avg += s[i].per;
    }

    avg /= n;

    
    while(1){
        printf("\n1.Show All\n2.Search by Roll\n3.Search by Name\n4.Search by Grade\n5.Class Avg\n6.Rank List\n0.Exit\nChoice: ");
        scanf("%d", &choice);

        if(choice==0) break;

        if(choice==1){
            for(i=0;i<n;i++)
                printf("%s %d %.2f %s\n", s[i].name, s[i].roll, s[i].per, s[i].grade);
        }

        else if(choice==2){
            int r, f=0;
            printf("Enter roll: ");
            scanf("%d", &r);
            for(i=0;i<n;i++){
                if(s[i].roll==r){
                    printf("%s %d %.2f %s\n", s[i].name, s[i].roll, s[i].per, s[i].grade);
                    f=1;
                }
            }
            if(!f) printf("Not found\n");
        }

        else if(choice==3){
            char nm[50];
            int f=0;
            printf("Enter name: ");
            scanf("%s", nm);
            for(i=0;i<n;i++){
                if(strcmp(s[i].name,nm)==0){
                    printf("%s %d %.2f %s\n", s[i].name, s[i].roll, s[i].per, s[i].grade);
                    f=1;
                }
            }
            if(!f) printf("Not found\n");
        }

        else if(choice==4){
            char g[3];
            printf("Enter grade: ");
            scanf("%s", g);
            for(i=0;i<n;i++)
                if(strcmp(s[i].grade,g)==0)
                    printf("%s %d %.2f\n", s[i].name, s[i].roll, s[i].per);
        }

        else if(choice==5){
            printf("Class Average = %.2f\n", avg);
            printf("\nAbove Avg:\n");
            for(i=0;i<n;i++) if(s[i].per > avg)
                printf("%s %.2f\n", s[i].name, s[i].per);

            printf("\nBelow Avg:\n");
            for(i=0;i<n;i++) if(s[i].per < avg)
                printf("%s %.2f\n", s[i].name, s[i].per);
        }

        else if(choice==6){
         
            for(int a=0;a<n-1;a++){
                for(int b=0;b<n-a-1;b++){
                    if(s[b].per < s[b+1].per){
                        struct Student temp = s[b];
                        s[b] = s[b+1];
                        s[b+1] = temp;
                    }
                }
            }
            printf("\nRank List:\n");
            for(i=0;i<n;i++)
                printf("%d) %s %.2f\n", i+1, s[i].name, s[i].per);
        }
    }

    return 0;
}

