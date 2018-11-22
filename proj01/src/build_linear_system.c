#include <stdio.h>
#include "matrix.h"

/* Parameters need: N, k, h */

void build_linear_system()
{
	int i,j,l;
	int N;
	double b[N+1];
	double con = -k/(h*h);
	
	if(dimensions == 1)

	{
		if(fd_method == 2)
		{	
	
			double 1d2nd[2]; 
			1d2nd = {con, -2*con, con};
				
			Matrix* A = (Matrix*) malloc(sizeof(Matrix));
				 
			for(i=0;i<=N;i++)
			{	
				if((i==0)||(i==N))
				{
					A.nonzero[i] = 1;
        	                        A.col[i][0]  = i;
	                                A.val[N][0]  = con;
				}	
				else
				{
					A.nonzero[i] = 3;
					A.val[i]     = 1d2nd;
					for(j=0;j<A.nonzero[i],j++)
					A.col[i][j] = i-1+j;
				}
			}
		}

		if(fd_method == 4)
		{
			double 1d4th[5];
			1d4th = {-1/12*con, 4/3*con, -5/2*con, 4/3*con, -1/12*con};
				
			Matrix* A = (Matrix*) malloc(sizeof(Matrix));

			for(i=0;i<=N;i++)
			{
				if((i==0)||(i==1)||(i==N-1)||(i==N))
				{
					A.nonzero[i] = 1;
					A.col[i][0]  = i;
					A.val[i][0]  = con;
				}
				else
				{
					A.nonzero[i] = 5;
					A.val[i]     = 1d4th;
					for(j=0;j<A.nonzero[i],j++)
						A.col[i][j] = i-2+j;
				}
			}
		}
	}

	if(dimensions == 2)
	{
		if(fd_method == 2)
		{
			double 2d2nd[5];
			2d2nd = {con, con, -4*con, con, con};
			
			Matrix* A = (Matrix*) malloc(sizeof(Matrix));

			for(l=0;l<=N;l++)
			{
				if((l==0)||(l==N))
				{
					for(i=0;i<=N;i++)
					{ 
						A.nonzero[l*(N+1)+i] = 1;
						A.col[l*(N+1)+i][0]  = l*(N+1)+i;
						A.val[l*(N+1)+i][0]  = con;
					}
				}
				else
				{
					for(i=0;i<=N;i++)
					{
						if((i==0)||(i==N))
						{
							A.nonzero[l*(N+1)+i] = 1;
							A.col[l*(N+1)+i][0]  = l*(N+1)+i;
							A.val[l*(N+1)+i][0]  = con;
						}
						else
						{
							A.nonzero[l*(N+1)+i] = 5;
							A.col[l*(N+1)+i][0]  = (l-1)*(N+1)+i;
							A.col[l*(N+1)+i][4]  = (l+1)*(N+1)+i;
							for(j=1;j<A.nonzero[l*(N+1)+i]-1;j++)
							{
								A.col[l*(N+1)+i][j] = l*(N+1)+j-1;
							}
							A.val[l*(N+1)+i] = 2d2nd;
						}
					}
				}
				
			}
				
		}
				
                if(fd_method == 4)
		{
			double 2d4th[9];
			2d4th = {-1/12*con, 4/3*con, -1/12*con, 4/3*con, -5*con, 4/3*con, -1/12*con, 4/3*con, -1/12*con};
		
			Matrix* A = (Matrix*) malloc(sizeof(Matrix));
			
				
		}

	}	

}
