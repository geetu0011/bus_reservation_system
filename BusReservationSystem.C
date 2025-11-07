#include <stdio.h>
#include <string.h>

int main()
{
    char usernames[10][50];
    char passwords[10][50];
    int userCount = 0;
    int loggedIn = 0;
    char name[50], pass[50];

    int totalSeats = 50;
    int availableSeats = 50;
    int amount = 500;
    int choice, seat, bus;

    printf("\n================ BUS RESERVATION SYSTEM ================\n");

    while (1)
    {
        
        if (loggedIn == 0)
        {
            printf("\n1. Register");
            printf("\n2. Login");
            printf("\n3. Exit");
            printf("\nEnter your choice: ");
            scanf("%d", &choice);

            if (choice == 1)
            {
                if (userCount < 10)
                {
                    printf("Enter username: ");
                    scanf("%s", usernames[userCount]);
                    printf("Enter password: ");
                    scanf("%s", passwords[userCount]);
                    userCount++;
                    printf("Registration Successful!\n");
                }
                else
                {
                    printf(" User limit reached.\n");
                }
            }
            else if (choice == 2)
            {
                printf("Enter username: ");
                scanf("%s", name);
                printf("Enter password: ");
                scanf("%s", pass);

                int found = 0;
                for (int i = 0; i < userCount; i++)
                {
                    if (strcmp(usernames[i], name) == 0 && strcmp(passwords[i], pass) == 0)
                    {
                        loggedIn = 1;
                        found = 1;
                        printf("\nLogin Successful! Welcome %s\n", name);
                        break;
                    }
                }

                if (!found)
                    printf("Wrong username or password.\n");
            }
            else if (choice == 3)
            {
                printf("\nThank you for using the system!\n");
                break;
            }
            else
            {
                printf("Invalid choice, try again.\n");
            }
        }

        
        else
        {
            printf("\n================ BUS MENU ================\n");
            printf("1. Book Ticket\n");
            printf("2. Cancel Ticket\n");
            printf("3. Check Bus Status\n");
            printf("4. Logout\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

          
            if (choice == 1)
            {
                printf("Enter Bus Number: ");
                scanf("%d", &bus);
                printf("Enter Number of Seats to Book: ");
                scanf("%d", &seat);

                if (seat > 0 && seat <= availableSeats)
                {
                    availableSeats -= seat;
                    printf("\nBooking Successful!");
                    printf("\nBus Number: %d", bus);
                    printf("\nSeats Booked: %d", seat);
                    printf("\nTotal Amount: Rs.%d\n", seat * amount);
                }
                else
                {
                    printf("Not enough seats or invalid number.\n");
                }
            }

            
            else if (choice == 2)
            {
                printf("Enter Bus Number: ");
                scanf("%d", &bus);
                printf("Enter Number of Seats to Cancel: ");
                scanf("%d", &seat);

                if (seat > 0 && (availableSeats + seat) <= totalSeats)
                {
                    availableSeats += seat;
                    printf("\nCancellation Successful!");
                    printf("\nBus Number: %d", bus);
                    printf("\nSeats Cancelled: %d\n", seat);
                }
                else
                {
                    printf("Invalid cancellation.\n");
                }
            }

           
            else if (choice == 3)
            {
                printf("\n================ BUS STATUS ================\n");
                printf("Bus Number: 101\n");
                printf("Route: Delhi to Goa\n");
                printf("Total Seats: %d\n", totalSeats);
                printf("Available Seats: %d\n", availableSeats);
                printf("Amount per Seat: Rs.%d\n", amount);
                printf("===========================================\n");
            }

            else if (choice == 4)
            {
                loggedIn = 0;
                printf("\nYou have logged out.\n");
            }

            
            else
            {
                printf("Invalid choice, try again.\n");
            }
        }
    }

    return 0;
}
