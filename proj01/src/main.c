#include "function.h"

int main(int argc, char *argv[])
{
	
	if(argc < 2)
	{
		grvy_printf(GRVY_ERROR, "\nUsage: solver [input-file] \n\n");
		exit(1);		
	}

	/* Define global struct and variable */
	struct Parameter solver;

	grvy_timer_init("Steady Heat Equation Solver");
	
	/* Run functions step by step*/ 	
	parse_input(&solver, argv[1]);
	init(&solver);
	build_linear_system(&solver);
	solve_system(&solver);
	output(&solver);

	grvy_timer_finalize();
	
	grvy_timer_summarize();

	return 0;
}
