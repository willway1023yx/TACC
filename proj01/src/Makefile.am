# Define executable to create
bin_PROGRAMS = solver

# Define source code files which are part of the executable
solver_SOURCES = main.c parameter.h function.h parse_input.c init.c build_linear_system.c solve_system.c output.c error_norm.c

# library linkage
AM_CFLAGS = $(GRVY_CFLAGS) $(MASA_CXXFLAGS) -Wall -Wextra -Wshadow -Wunreachable-code
LIBS      = $(GRVY_LIBS) $(MASA_LIBS) -lm
