# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = "/home/qli/Documents/Installed programs/clion-2020.2.4/bin/cmake/linux/bin/cmake"

# The command to remove a file.
RM = "/home/qli/Documents/Installed programs/clion-2020.2.4/bin/cmake/linux/bin/cmake" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/qli/CLionProjects/philosophers/philo_one_rewrite

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/qli/CLionProjects/philosophers/philo_one_rewrite/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/rewrite.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/rewrite.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/rewrite.dir/flags.make

CMakeFiles/rewrite.dir/main.c.o: CMakeFiles/rewrite.dir/flags.make
CMakeFiles/rewrite.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/qli/CLionProjects/philosophers/philo_one_rewrite/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/rewrite.dir/main.c.o"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/rewrite.dir/main.c.o   -c /home/qli/CLionProjects/philosophers/philo_one_rewrite/main.c

CMakeFiles/rewrite.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/rewrite.dir/main.c.i"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/qli/CLionProjects/philosophers/philo_one_rewrite/main.c > CMakeFiles/rewrite.dir/main.c.i

CMakeFiles/rewrite.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/rewrite.dir/main.c.s"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/qli/CLionProjects/philosophers/philo_one_rewrite/main.c -o CMakeFiles/rewrite.dir/main.c.s

CMakeFiles/rewrite.dir/srcs/process_input.c.o: CMakeFiles/rewrite.dir/flags.make
CMakeFiles/rewrite.dir/srcs/process_input.c.o: ../srcs/process_input.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/qli/CLionProjects/philosophers/philo_one_rewrite/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/rewrite.dir/srcs/process_input.c.o"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/rewrite.dir/srcs/process_input.c.o   -c /home/qli/CLionProjects/philosophers/philo_one_rewrite/srcs/process_input.c

CMakeFiles/rewrite.dir/srcs/process_input.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/rewrite.dir/srcs/process_input.c.i"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/qli/CLionProjects/philosophers/philo_one_rewrite/srcs/process_input.c > CMakeFiles/rewrite.dir/srcs/process_input.c.i

CMakeFiles/rewrite.dir/srcs/process_input.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/rewrite.dir/srcs/process_input.c.s"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/qli/CLionProjects/philosophers/philo_one_rewrite/srcs/process_input.c -o CMakeFiles/rewrite.dir/srcs/process_input.c.s

CMakeFiles/rewrite.dir/srcs/libft/srcs/ft_atoi.c.o: CMakeFiles/rewrite.dir/flags.make
CMakeFiles/rewrite.dir/srcs/libft/srcs/ft_atoi.c.o: ../srcs/libft/srcs/ft_atoi.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/qli/CLionProjects/philosophers/philo_one_rewrite/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/rewrite.dir/srcs/libft/srcs/ft_atoi.c.o"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/rewrite.dir/srcs/libft/srcs/ft_atoi.c.o   -c /home/qli/CLionProjects/philosophers/philo_one_rewrite/srcs/libft/srcs/ft_atoi.c

CMakeFiles/rewrite.dir/srcs/libft/srcs/ft_atoi.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/rewrite.dir/srcs/libft/srcs/ft_atoi.c.i"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/qli/CLionProjects/philosophers/philo_one_rewrite/srcs/libft/srcs/ft_atoi.c > CMakeFiles/rewrite.dir/srcs/libft/srcs/ft_atoi.c.i

CMakeFiles/rewrite.dir/srcs/libft/srcs/ft_atoi.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/rewrite.dir/srcs/libft/srcs/ft_atoi.c.s"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/qli/CLionProjects/philosophers/philo_one_rewrite/srcs/libft/srcs/ft_atoi.c -o CMakeFiles/rewrite.dir/srcs/libft/srcs/ft_atoi.c.s

CMakeFiles/rewrite.dir/srcs/initialise_philos.c.o: CMakeFiles/rewrite.dir/flags.make
CMakeFiles/rewrite.dir/srcs/initialise_philos.c.o: ../srcs/initialise_philos.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/qli/CLionProjects/philosophers/philo_one_rewrite/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/rewrite.dir/srcs/initialise_philos.c.o"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/rewrite.dir/srcs/initialise_philos.c.o   -c /home/qli/CLionProjects/philosophers/philo_one_rewrite/srcs/initialise_philos.c

CMakeFiles/rewrite.dir/srcs/initialise_philos.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/rewrite.dir/srcs/initialise_philos.c.i"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/qli/CLionProjects/philosophers/philo_one_rewrite/srcs/initialise_philos.c > CMakeFiles/rewrite.dir/srcs/initialise_philos.c.i

CMakeFiles/rewrite.dir/srcs/initialise_philos.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/rewrite.dir/srcs/initialise_philos.c.s"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/qli/CLionProjects/philosophers/philo_one_rewrite/srcs/initialise_philos.c -o CMakeFiles/rewrite.dir/srcs/initialise_philos.c.s

CMakeFiles/rewrite.dir/clean_up.c.o: CMakeFiles/rewrite.dir/flags.make
CMakeFiles/rewrite.dir/clean_up.c.o: ../clean_up.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/qli/CLionProjects/philosophers/philo_one_rewrite/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/rewrite.dir/clean_up.c.o"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/rewrite.dir/clean_up.c.o   -c /home/qli/CLionProjects/philosophers/philo_one_rewrite/clean_up.c

CMakeFiles/rewrite.dir/clean_up.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/rewrite.dir/clean_up.c.i"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/qli/CLionProjects/philosophers/philo_one_rewrite/clean_up.c > CMakeFiles/rewrite.dir/clean_up.c.i

CMakeFiles/rewrite.dir/clean_up.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/rewrite.dir/clean_up.c.s"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/qli/CLionProjects/philosophers/philo_one_rewrite/clean_up.c -o CMakeFiles/rewrite.dir/clean_up.c.s

# Object files for target rewrite
rewrite_OBJECTS = \
"CMakeFiles/rewrite.dir/main.c.o" \
"CMakeFiles/rewrite.dir/srcs/process_input.c.o" \
"CMakeFiles/rewrite.dir/srcs/libft/srcs/ft_atoi.c.o" \
"CMakeFiles/rewrite.dir/srcs/initialise_philos.c.o" \
"CMakeFiles/rewrite.dir/clean_up.c.o"

# External object files for target rewrite
rewrite_EXTERNAL_OBJECTS =

rewrite: CMakeFiles/rewrite.dir/main.c.o
rewrite: CMakeFiles/rewrite.dir/srcs/process_input.c.o
rewrite: CMakeFiles/rewrite.dir/srcs/libft/srcs/ft_atoi.c.o
rewrite: CMakeFiles/rewrite.dir/srcs/initialise_philos.c.o
rewrite: CMakeFiles/rewrite.dir/clean_up.c.o
rewrite: CMakeFiles/rewrite.dir/build.make
rewrite: CMakeFiles/rewrite.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/qli/CLionProjects/philosophers/philo_one_rewrite/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable rewrite"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rewrite.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/rewrite.dir/build: rewrite

.PHONY : CMakeFiles/rewrite.dir/build

CMakeFiles/rewrite.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/rewrite.dir/cmake_clean.cmake
.PHONY : CMakeFiles/rewrite.dir/clean

CMakeFiles/rewrite.dir/depend:
	cd /home/qli/CLionProjects/philosophers/philo_one_rewrite/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/qli/CLionProjects/philosophers/philo_one_rewrite /home/qli/CLionProjects/philosophers/philo_one_rewrite /home/qli/CLionProjects/philosophers/philo_one_rewrite/cmake-build-debug /home/qli/CLionProjects/philosophers/philo_one_rewrite/cmake-build-debug /home/qli/CLionProjects/philosophers/philo_one_rewrite/cmake-build-debug/CMakeFiles/rewrite.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/rewrite.dir/depend

