/*
 * This program addresses the following problem from Gayle Laakmann McDowell's
 * CRACKING THE CODING INTERVIEW, SIXTH EDITION.
 *
 * ----------------------------------------------------------------------------
 * Robot in a Grid: Imagine a robot sitting on the upper left corner of grid 
 * with r rows and c columns. The robot can only move in two directions, right
 * and down, but certain cells are "off limits" such that the robot cannot step
 * on them. Design an algorithm to find a path for the robot from the top left
 * to the bottom right.
 * ----------------------------------------------------------------------------
 *
 * Author: Leran Ma (leranmalm@hotmail.com)
 * Date:   2:37 PM, Tuesday, August 16, 2022
 */

#include <iostream>

using namespace std;

int main()
{
    int r;
    cout << "Please enter r: ";
    cin >> r;

    int c;
    cout << "Please enter c: ";
    cin >> c;

    int grid[r][c];
    cout << "Please enter the grid: (0 => valid, 1 => invalid)\n";

    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            cin >> grid[i][j];
        }
    }

    // Process the first row and the first column
    for (int j = 1; j < c; ++j)
    {
        // For any cell on the first row, if the cell to the left of it cannot
        // be accessed, then this cell cannot be accessed either.
        if ( grid[0][j - 1] == 1 )
        {
            grid[0][j] = 1;
        }

        // For any cell on the first column, if the cell above it cannot be 
        // accessed, then this cell cannot be accessed either.
        if ( grid[j - 1][0] == 1 )
        {
            grid[j][0] = 1;
        }
    }

    // Annotate other cells row by row from left to the right
    // 2 indicate the cell could be reached from the left.
    // 3 indicate the cell could be reached from the top.
    for (int i = 1; i < r; ++i)
    {
        for (int j = 1; j < c; ++j)
        {
            if ( grid[i][j] == 1 )
            {
                continue;
            }
            if ( grid[i - 1][j] != 1 )
            {
                grid[i][j] = 3;
            }
            else if ( grid[i][j - 1] != 1 )
            {
                grid[i][j] = 2;
            }
            else
            {
                grid[i][j] = 1;
            }
        }
    }

    if ( grid[r - 1][c - 1] == 1 )
    {
        cout << "The bottom right corner is not reachable.";
        return 0;
    }

    // Tracing back to get a valid path
    int path[r + c - 2];
    int temp_r = r - 1;
    int temp_c = c - 1;
    for (int i = r + c - 3; i >= 0; --i)
    {
        path[i] = grid[temp_r][temp_c];
        if ( path[i] == 3 )
        {
            temp_r--;
        }
        else
        {
            temp_c--;
        }
    }

    for (int i = 0; i < r + c - 2; ++i)
    {
        if ( path[i] == 2 )
        {
            cout << "right ";
        }
        else
        {
            cout << "down ";
        }
    }
    
    return 0;
}
