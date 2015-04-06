int min(int a, int b) { return a > b ? b : a;}

	int minPathSum(int **grid, int nRows, int nCols)
	{
	    const int R = nRows;
	    const int C = nCols;

	    int path[R][C];
	    for(int i = 0; i < R; i++)
		for(int j = 0; j < C; j++)
		    path[i][j] = 0;

	    path[0][0] = grid[0][0];
	    for(int i = 1; i < R; i++)
		path[i][0] = path[i-1][0] + grid[i][0];
	    for(int i = 1; i < C; i++)
		path[0][i] = path[0][i-1] + grid[0][i];

	    for(int i = 1; i < R; i++)
		for(int j = 1; j < C; j++)
		    path[i][j] = min(path[i-1][j], path[i][j-1]) + grid[i][j];


	    return path[R-1][C-1];
	}

