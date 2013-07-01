package SRM539;

public class FoxBomb {
	private int c;
	
	private void dfs(int i, int j, int dir, String[] grid, int change)
	{
		if(i>=0 && i<grid.length && j>=0 && j<grid[i].length() && grid[i].charAt(j) == '.')
		{
			System.out.println(i + " " + j + " " + change);
			if(change > c)
			{
				c = change;
			}
			switch(dir)
			{
			case 0:
				dfs(i-1, j, 1, grid, change);
				dfs(i, j-1, 2, grid, change);
				dfs(i+1, j, 3, grid, change);
				dfs(i, j+1, 4, grid, change);
				break;
			case 1:
				dfs(i-1, j, 1, grid, change);
				dfs(i, j-1, 2, grid, change+1);
				dfs(i, j+1, 4, grid, change+1);
				break;
			case 2:
				dfs(i-1, j, 1, grid, change+1);
				dfs(i, j-1, 2, grid, change);
				dfs(i+1, j, 3, grid, change+1);
				break;
			case 3:
				dfs(i, j-1, 2, grid, change+1);
				dfs(i+1, j, 3, grid, change);
				dfs(i, j+1, 4, grid, change+1);
				break;
			case 4:
				dfs(i-1, j, 1, grid, change+1);
				dfs(i+1, j, 3, grid, change+1);
				dfs(i, j+1, 4, grid, change);
				break;
			}
		}
	}
	
	private int isFloor(int i, int j, String[] grid)
	{
		if(i>=0 && i<grid.length && j>=0 && j<grid[i].length())
		{
			return grid[i].charAt(j) == '.'?1:0;
		}
		return 0;
	}
	
	public int getMinimumCost(String[] grid){
		for(int i=0;i<grid.length;++i)
		{
			for(int j=0;j<grid[i].length();++j)
			{
				if(grid[i].charAt(j) == '.')
				{
					dfs(i,j,0,grid,0);
					if(isFloor(i-1, j, grid) + isFloor(i+1,j,grid) + isFloor(i, j-1, grid) + isFloor(i,j+1,grid) > 1)
					{
						++c;
					}
					return c;
				}
			}
		}
		return 0;
	}
}
