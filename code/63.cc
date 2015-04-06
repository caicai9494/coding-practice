
	int uniquePathsWithObstacles(int **obstacleGrid, int m, int n)
	{
	    const int X = m;
	    const int Y = n;
	    int grid[X][Y];

	    bool flag = false;
	    for(int i = 0; i < X; i++)
	    {
		if(obstacleGrid[i][0] == 1)
		    flag = true;
		if(flag)
		    grid[i][0] = 0;
		else 
		    grid[i][0] = 1;
	    }

	    flag = false;
	    for(int i = 0; i < Y; i++)
	    {
		if(obstacleGrid[0][i] == 1)
		    flag = true;
		if(flag)
		    grid[0][i] = 0;
		else 
		    grid[0][i] = 1;
	    }

	    for(int i = 1; i < X; i++)
	    {
		for(int j = 1; j < Y; j++)
		{
		    if(obstacleGrid[i][j] == 0)
	                grid[i][j] = grid[i-1][j] + grid[i][j-1];
		    else
			grid[i][j] = 0;
		}
	    }

	    return grid[m-1][n-1];

	}

int main()
{
    int **arr = new int*[1];
    arr[0] = new int[100];
    for(int i = 0; i < 100; i++)
	arr[0][i] = 0;

    uniquePathsWithObstacles(arr, 1, 100);

    return 0;
}
