#include <iostream>
#include <cstdlib>
#include <ctime>

char xando(int value); // makes 1 a X and 2 an O

int main()
{
    int itmp1, itmp2, itmp3;
    char ctmp1, ctmp2, ctmp3;
    int winner = 0;
    int count = 0;
    
    srand(time(NULL));
    int computerX = 0;
    int computerY = 0;
    bool compFree = false; // Is the space the computer chose free?
    
    int arr[3][3];
    
    for (int rows = 0; rows < 3; rows++)
    {
        for (int cols = 0; cols < 3; cols++)
        {
            arr[rows][cols] = 0;
        }
    }

    std::cout << "Tic Tac Toe\n";
    std::cout << "Enter a row and then enter a column\n";
    std::cout << "Format: x y (Index starts at 1)\n";
    
    int x = 0;
    int y = 0;
    bool end = false; // set true win someone wins
    while (!end)
    {
        std::cin >> x;
        std::cin >> y;
        while ((0 > x) || (x > 3) || (0 > y) || ( y > 3))
        {
            std::cout << "try again\n";
            std::cin >> x;
            std::cin >> y;
        }
        std::cout << "\n";
        if ((arr[x - 1][y - 1] == 1) || (arr[x - 1][y - 1] == 2)) // This should be a while loop
        {
           std::cout << "Space is taken, try again\n\n";
           count -= 1;
        }
        else
        {
            arr[x - 1][y - 1] = 1;
            
            // check for winner
            if (((arr[0][0] == 1) && (arr[0][1] == 1) && (arr[0][2] == 1)) // row 1
            || ((arr[1][0] == 1) && (arr[1][1] == 1) && (arr[1][2] == 1))  // row 2
            || ((arr[2][0] == 1) && (arr[2][1] == 1) && (arr[2][2] == 1))  // row 3
            || ((arr[0][0] == 1) && (arr[1][0] == 1) && (arr[2][0] == 1))  // col 1
            || ((arr[0][1] == 1) && (arr[1][1] == 1) && (arr[2][1] == 1))  // col 2
            || ((arr[0][2] == 1) && (arr[1][2] == 1) && (arr[2][2] == 1))  // col 3
            || ((arr[0][0] == 1) && (arr[1][1] == 1) && (arr[2][2] == 1))  // diag 1
            || ((arr[0][2] == 1) && (arr[1][1] == 1) && (arr[2][0] == 1)))  // diag 2
            {
                end = true;
                winner = 1;
            }
            // Computer's turn
            else
            {
                while (compFree == false)
                {
                    computerX = (rand() % 3) + 1;
                    computerY = (rand() % 3) + 1;
                    if ((arr[computerX - 1][computerY - 1] != 1) && (arr[computerX - 1][computerY - 1] != 2))
                    {
                        arr[computerX - 1][computerY - 1] = 2;
                        compFree = true;
                    }
                }
                // check if the computer is the winner
                if (((arr[0][0] == 2) && (arr[0][1] == 2) && (arr[0][2] == 2)) // row 1
                || ((arr[1][0] == 2) && (arr[1][1] == 2) && (arr[1][2] == 2))  // row 2
                || ((arr[2][0] == 2) && (arr[2][1] == 2) && (arr[2][2] == 2))  // row 3
                || ((arr[0][0] == 2) && (arr[1][0] == 2) && (arr[2][0] == 2))  // col 1
                || ((arr[0][1] == 2) && (arr[1][1] == 2) && (arr[2][1] == 2))  // col 2
                || ((arr[0][2] == 2) && (arr[1][2] == 2) && (arr[2][2] == 2))  // col 3
                || ((arr[0][0] == 2) && (arr[1][1] == 2) && (arr[2][2] == 2))  // diag 1
                || ((arr[0][2] == 2) && (arr[1][1] == 2) && (arr[2][0] == 2)))  // diag 2
                {
                    end = true;
                    winner = 2;
                }
            }
        }
        
        count += 1;
        if (count == 5)
        {
            end = true;
            winner = 0;
        }
        
        compFree = false; // Reset for the free space check
        
        // Print Table
        itmp1 = arr[0][0];
        itmp2 = arr[0][1];
        itmp3 = arr[0][2];
        ctmp1 = xando(itmp1);
        ctmp2 = xando(itmp2);
        ctmp3 = xando(itmp3);
        std::cout << ctmp1 << " | " << ctmp2 << " | " << ctmp3 << "\n";
        std::cout << "---------\n";
        
        itmp1 = arr[1][0];
        itmp2 = arr[1][1];
        itmp3 = arr[1][2];
        ctmp1 = xando(itmp1);
        ctmp2 = xando(itmp2);
        ctmp3 = xando(itmp3);
        std::cout << ctmp1 << " | " << ctmp2 << " | " << ctmp3 << "\n";
        std::cout << "---------\n";
        
        itmp1 = arr[2][0];
        itmp2 = arr[2][1];
        itmp3 = arr[2][2];
        ctmp1 = xando(itmp1);
        ctmp2 = xando(itmp2);
        ctmp3 = xando(itmp3);
        std::cout << ctmp1 << " | " << ctmp2 << " | " << ctmp3 << "\n\n";
    }
    
    if (winner == 1)
    {
        std::cout << "You win!";
    }
    else if(winner == 2)
    {
        std::cout << "The Computer Wins!";
    }
    else
    {
        std::cout << "It's a Draw!";
    }
    
    return 0;
}

char xando(int value)
{
    if (value == 1)
    {
        return 'X';
    }
    else if (value == 2)
    {
        return 'O';
    }
    else
    {
        return ' ';
    }
}
