vector< vector< int > > rotatematrix90(vector< vector<int> > &a)
{

	//declaration
	int top;
	int left;
	int right;
	int bottom;
	int hold;
	int outside_to_center = 0;
	int accross_inline = 0;
	int the_last = a.size() - 1;
	int decrease = a.size() - 1;

	if (a.size() == 1)
	{
		;
	}
	else
	{
		//performances.
		while (outside_to_center < a.size() - 2)
		{
			while (accross_inline < the_last)  //because at a.size() - 1 index is edge, that if we rotate it, it will get duplicate.		//because we have rotate the edges in first, that we not retota it again, if we do, the edges of matrix will rotate 180* than another shape.   
			{
				/*top = a[outside_to_center][accross_inline];
				left = a[decrease][outside_to_center];
				right = a[accross_inline][the_last];
				bottom = a[the_last][decrease];*/

				//keep top value
				hold = a[outside_to_center][accross_inline];	//hold = top
				//swap performances

				//assign left to top value
				a[outside_to_center][accross_inline] = a[decrease][outside_to_center];		//top = left

				//assign bottom to left value
				a[decrease][outside_to_center] = a[the_last][decrease];			//left = bottom

				//assign right to bottom value
				a[the_last][decrease] = a[accross_inline][the_last];			//bottom = right;

				//after assign all everything we need, assign 'hold' (keep an old-top index) to right - to get rotate 90 degree
				a[accross_inline][the_last] = hold;	//right = hold - 'hold' keep old 'top' value

				//to get rotate 90 degree different with edges of matrix, we must to increase the collumn in top and row in right, decrease collumn in bottom and row in left to get element need to rotate.
				decrease--;				//get the next values of an bottom and left to rotate.
				accross_inline++;		//get the next values of an top and right to rotate.
			}
			outside_to_center++;		//conered the matrix into the core of the matrix.
			the_last--;					//conered the matrix into the core of the matrix.

			accross_inline = outside_to_center;
			decrease = the_last;			//get a value to decrease 
		}
	}
	return a;
}