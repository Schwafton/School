package game;
public class GameGrid //Class that holds our Game Grid
{
    char[][] gameGrid = new char[20][20];

    //Constructor-----------------------------------------------------------------------------------------------
    public GameGrid(char[][] initialData)
    {
        gameGrid = initialData;
    }

    //Gets the character at a given cordinate
    public char getGridData(int x, int y)
    {
        return gameGrid[x][y];
    }

    //Returns the entire character[][] grid
    public char[][] getGrid()
    {
        return gameGrid;
    }

    //Sets the data at a given cordinate to a certain character
    public void setGridData(int x, int y, char c)
    {
        gameGrid[x][y] = c;
    }

    //Sets the Game Grid's grid to given char[][]
    public void setGrid(char[][] grid)
    {
        gameGrid = grid;
    }

    //Displays the current contents of the Grid-----------------------------------------------------------------
    public void DisplayGrid()
    {
        //Display the contents of this Game Grid's char[][]
        for(int i = 0; i < 20; i++)
        {
            if (i != 0)
                System.out.println();

            for(int j = 0; j < 20; j++)
                System.out.print(gameGrid[i][j]);
        }
        
        System.out.println(); //End with a new line

    }

    //Function to update the Grid by one generation/iteration----------------------------------------------------------
    public void nextGeneration()
    {
        //Establish an empty grid to store results in
        char[][] referenceGrid = new char[20][20];
        
        //Master Loop to iterate through the entire grid-----------------------------------------------------------------
        for (int i = 0; i < 20; i++)
        {
            for (int j = 0; j < 20; j++)
            {
            
            int numberOfLiveNeighbors = 0;
            
            //Loops through the 3x3 grid around the given cordinate, x & y = -1,0,1
            for (int x = -1; x <= 1; x++)
            {
                for (int y = -1; y <= 1; y++)
                {
                    //If neighbor cordinate is valid and is alive, increment our counter----------------------
                    if (((i+x >= 0) && (i+x < 20)) && ((j+y>=0) && (j+y < 20))) //If cordinate is valid
                    {
                        if(this.getGridData(i+x, j+y) == '+') //If it was alive
                            numberOfLiveNeighbors++;
                    }
                }
            }
                //Don't count the cell itself as a neighbor
                if(this.getGridData(i, j) == '+')
                    numberOfLiveNeighbors -= 1; 

                //GAME OF LIFE RULES-----------------------------------------------------------
                
                //If this cell is living and has less than two live neighbors
                if((this.getGridData(i, j) == '+') && numberOfLiveNeighbors < 2)
                    referenceGrid[i][j] = '.'; //Set the current grid to dead

                    //If this cell is living and has more than 3 Neighbors
                else if((this.getGridData(i, j) == '+') && (numberOfLiveNeighbors > 3))
                    referenceGrid[i][j] = '.'; //Set the current grid to dead

                //If this cell is dead and has 3 Neighbors
                else if(this.getGridData(i, j) == '.' && numberOfLiveNeighbors == 3)
                    referenceGrid[i][j] = '+'; //Set the current grid to Alive
                else 
                    referenceGrid[i][j] = this.getGridData(i,j); //If none of the previous conditions were met, no change
            }
        }
        //After setting all the data to reference grid and all steps are done, update our actual grid object with the data
        this.setGrid(referenceGrid); 
    }
}