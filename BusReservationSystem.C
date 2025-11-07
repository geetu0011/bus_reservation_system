#include <stdio.h>
int main()
{
    int totalSeats = 50;
    int availableSeats = 50;
    int amount = 500;
    int choice;
    int seat;
    int bus;

    printf("\n**************** BUS RESERVATION SYSTEM *****************\n");


    do
    {
        printf("\n1. Book Ticket");
        printf("\n2. Cancel Ticket"); 
        printf("\n3. Check Bus Status");
        printf("\n4. Exit");
        printf("\nEnter your choice:-");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Enter Bus Number:- ");
            scanf("%d", &bus);
            printf("Enter Number of Seats to Book:- ");
            scanf("%d", &seat);

            if (seat > 0 && seat <= availableSeats)
            {
                availableSeats -= seat;
                printf("\nBooking Successful %d seats booked on Bus %d\n", seat, bus);
                printf("Amount:- Rs.%d\n", seat * amount);
            }
            else
                printf("Invalid or Not enough seats\n");
        }

        else if (choice == 2)
        {
            printf("Enter Bus Number:- ");
            scanf("%d", &bus);
            printf("Enter Number of Seats to Cancel:- ");
            scanf("%d", &seat);

            if (seat > 0 && availableSeats + seat <= totalSeats)
            {
                availableSeats += seat;
                printf("\nCancellation Successful %d seats cancelled on Bus %d\n", seat, bus);
            }
            else
                printf("Invalid cancellation\n");
        }

        else if (choice == 3)
        {
            printf("\nBus Number:- 101");
            printf("\nFrom:- Delhi To Goa");
            printf("\nTotal Seats:- %d", totalSeats);
            printf("\nAvailable Seats:- %d", availableSeats);
            printf("\nAmount per Seat: Rs.%d\n",amount);
        }

        else if (choice == 4)
        {
            printf("\nTHANKUUUUUUU \n");
        }
        else
            printf("Invalid..Try again.\n");

    } 
    while (choice != 4);

    return 0;
}
