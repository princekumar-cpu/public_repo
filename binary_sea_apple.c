#include <stdio.h>
#define MAX 20

struct records
{
    char employee_name[20];
    int emp_no, emp_salary;
};

int binary_search(struct records employees[MAX], int key, int lb, int ub)
{
    int mid,count =0;
    while (lb <= ub)
    {
        mid = (lb + ub) / 2;
        if (employees[mid].emp_no == key)
        {
            return count;
        }
        else if (employees[mid].emp_no < key)
        {
            lb = mid + 1;
            count += 1;
        }
        else
        {
            ub = mid - 1;
            count += 1;
        }
    }
    return -1;
}

int main()
{
    int n, key, pos1, pos2;
    struct records employees[MAX];
    printf("\n\nHow many record you want to enter :     ");
    scanf("%d", &n);
    printf("___________Enter the details_____________\n\n");
    for (int i = 0; i < n; i++)
    {
        printf("\nDetails of Employee %d  \n", i + 1);
        printf("Employee Number\t\t:   ");
        scanf("%d", &employees[i].emp_no);
        printf("Employee Name\t\t:   ");
        scanf("%s", &employees[i].employee_name);
        printf("Employee Salary\t\t:   ");
        scanf("%d", &employees[i].emp_salary);
    }
    printf("\nEnter the element your want to search : ");
    scanf("%d", &key);
    pos1 = linear_search(employees, n, key);
    pos2 = binary_search(employees, key, 0, n);
    if (pos1 == -1 && pos2 == -1)
    {
        printf("Record not found\n");
    }
    else
    {
        printf("\nDetails of Employee of id : %d  \n", key);
        printf("\nEmployee Name : %s\t:\t", employees[pos1].employee_name);
        printf("\nEmployee Salary : %d\t:\t", employees[pos1].emp_salary);
        printf("\n\nCost of linear search to find this record is %d", pos1 + 1);
        printf("\nCost of Binary search to find this record is %d", pos2 + 1);
    }
    return 0;
}