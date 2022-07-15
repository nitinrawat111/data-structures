#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int *arr;
int capacity = 0;
int len = 0;

int insert(int index, int element)
{
    if(index < 0 || index >len)
    {
        return 0;
    }
    if(len == capacity)
    {
        if(capacity == 0)
        {
            capacity = 2;
        }
        else
        {
            capacity *= 2;;
        }

        int *temparr = (int*) malloc(capacity*sizeof(int));
         
        int i;
        for(i = 0; i < index; i++)
        {
            temparr[i] = arr[i];
        }
        
        temparr[index] = element;
        
        for(i ; i<len; i++)
        {
            temparr[i+1] = arr[i];
        }
        
        arr=temparr;
        
    }
    else
    {
        for(int i = len-1; i >= index; i--)
        {
            arr[i+1] = arr[i];
        }
        
        arr[index] = element;

    }
    
    len++;

    return 1;
}

void append(int element)
{
    if(len == capacity)
    {
        if(capacity == 0)
        {
            capacity = 2;
        }
        else
        {
            capacity *= 2;;
        }

        int *temparr = (int*) malloc(capacity*sizeof(int));
        
        for(int i = 0; i < len; i++)
        {
            temparr[i] = arr[i];
        }
        
        arr=temparr;
        arr[len] = element;
    }
    else
    {
        arr[len] = element;
    }
    
    len++;
}

void delete_at(int index)
{
    if(index < 0 || index > len-1)
    {
        printf("Invalid index : %d . Press any key.", index);
        getch();
        return;
    }
    
    int element=arr[index];

    for(int i = index; i < len-1; i++)
    {
        arr[i] = arr[i+1];
    }
    
    len--;
    printf("Element %d at index %d deleted. Press any key.", element, index);
    getch();
}

int delete_last()
{
    if(len == 0)
    {
        return 0;
    }
    len--;
    return 1;
}

int delete(int element)
{
    for(int i = 0; i<len; i++)
    {
        if(arr[i] == element)
        {
            delete_at(i);
            return 1;
        }
    }

    return 0;
}

void print_arr()
{
    for(int i = 0; i<len; i++)
    {
        printf("| %d ", arr[i]);
    }
    printf("|");
}

void clear()
{
    free(arr);
    capacity=0;
    len=0;
}

int main()
{
    int choice;
    int element, index;

    do
    {
        system("cls");
        printf("1. Append element\n");
        printf("2. Insert element at index\n");
        printf("3. Delete last element\n");
        printf("4. Delete element\n");
        printf("5. Delete element by index\n");
        printf("6. Print array\n");
        printf("7. Clear array\n");
        printf("8. Exit\n");
        printf("Enter a choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: system("cls");
                    printf("Enter element to be appended : ");
                    scanf("%d", &element);
                    append(element);
                    printf("%d appended to the array. Press any key.", element);
                    getch();
                    break;
            
            case 2: system("cls");
                    printf("Enter index where element is to be inserted : ");
                    scanf("%d", &index);
                    printf("Enter element to be inserted : ");
                    scanf("%d", &element);
                    if(insert(index, element))
                    {
                        printf("%d inserted successfully at index %d. Press any key.", element, index);
                    }
                    else
                    {
                        printf("Invalid index : %d . Press any key.", index);
                    }
                    getch();
                    break;
            
            case 3: system("cls");
                    if(delete_last())
                    {
                        printf("Last element %d deleted successfully. Press any key.", arr[len]);
                    }
                    else
                    {
                        printf("Array is empty. Press any key.");
                    }
                    getch();
                    break;

            case 4: system("cls");
                    printf("Enter element to be deleted : ");
                    scanf("%d", &element);
                    if(delete(element) == 0)
                    {
                        printf("Element not found. Press any key.");
                        getch();
                    }
                    break;
                    

            case 5: system("cls");
                    printf("Enter index at which element is to be deleted : ");
                    scanf("%d", &index);
                    delete_at(index);
                    break;
            
            case 6: system("cls");
                    print_arr();
                    printf("\n Press any key to continue");
                    getch();
                    break;

            case 7: system("cls");
                    clear();
                    printf("Array cleared. Press any key.");
                    getch();
                    break;

            case 8: return 0;

            default: system("cls");
                     printf("Invalid choice. Press any key....");
                     getch();
        }
    }while(1);
}