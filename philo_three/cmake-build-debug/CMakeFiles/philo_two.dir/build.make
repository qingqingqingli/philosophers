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
CMAKE_SOURCE_DIR = /home/qli/CLionProjects/philosophers/philo_two

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/qli/CLionProjects/philosophers/philo_two/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/philo_two.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/philo_two.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/philo_two.dir/flags.make

CMakeFiles/philo_two.dir/main.c.o: CMakeFiles/philo_two.dir/flags.make
CMakeFiles/philo_two.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/qli/CLionProjects/philosophers/philo_two/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/philo_two.dir/main.c.o"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/philo_two.dir/main.c.o   -c /home/qli/CLionProjects/philosophers/philo_two/main.c

CMakeFiles/philo_two.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/philo_two.dir/main.c.i"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/qli/CLionProjects/philosophers/philo_two/main.c > CMakeFiles/philo_two.dir/main.c.i

CMakeFiles/philo_two.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/philo_two.dir/main.c.s"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/qli/CLionProjects/philosophers/philo_two/main.c -o CMakeFiles/philo_two.dir/main.c.s

CMakeFiles/philo_two.dir/srcs/check_status.c.o: CMakeFiles/philo_two.dir/flags.make
CMakeFiles/philo_two.dir/srcs/check_status.c.o: ../srcs/check_status.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/qli/CLionProjects/philosophers/philo_two/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/philo_two.dir/srcs/check_status.c.o"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/philo_two.dir/srcs/check_status.c.o   -c /home/qli/CLionProjects/philosophers/philo_two/srcs/check_status.c

CMakeFiles/philo_two.dir/srcs/check_status.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/philo_two.dir/srcs/check_status.c.i"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/qli/CLionProjects/philosophers/philo_two/srcs/check_status.c > CMakeFiles/philo_two.dir/srcs/check_status.c.i

CMakeFiles/philo_two.dir/srcs/check_status.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/philo_two.dir/srcs/check_status.c.s"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/qli/CLionProjects/philosophers/philo_two/srcs/check_status.c -o CMakeFiles/philo_two.dir/srcs/check_status.c.s

CMakeFiles/philo_two.dir/srcs/clean_up.c.o: CMakeFiles/philo_two.dir/flags.make
CMakeFiles/philo_two.dir/srcs/clean_up.c.o: ../srcs/clean_up.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/qli/CLionProjects/philosophers/philo_two/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/philo_two.dir/srcs/clean_up.c.o"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/philo_two.dir/srcs/clean_up.c.o   -c /home/qli/CLionProjects/philosophers/philo_two/srcs/clean_up.c

CMakeFiles/philo_two.dir/srcs/clean_up.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/philo_two.dir/srcs/clean_up.c.i"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/qli/CLionProjects/philosophers/philo_two/srcs/clean_up.c > CMakeFiles/philo_two.dir/srcs/clean_up.c.i

CMakeFiles/philo_two.dir/srcs/clean_up.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/philo_two.dir/srcs/clean_up.c.s"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/qli/CLionProjects/philosophers/philo_two/srcs/clean_up.c -o CMakeFiles/philo_two.dir/srcs/clean_up.c.s

CMakeFiles/philo_two.dir/srcs/initialise_philos.c.o: CMakeFiles/philo_two.dir/flags.make
CMakeFiles/philo_two.dir/srcs/initialise_philos.c.o: ../srcs/initialise_philos.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/qli/CLionProjects/philosophers/philo_two/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/philo_two.dir/srcs/initialise_philos.c.o"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/philo_two.dir/srcs/initialise_philos.c.o   -c /home/qli/CLionProjects/philosophers/philo_two/srcs/initialise_philos.c

CMakeFiles/philo_two.dir/srcs/initialise_philos.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/philo_two.dir/srcs/initialise_philos.c.i"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/qli/CLionProjects/philosophers/philo_two/srcs/initialise_philos.c > CMakeFiles/philo_two.dir/srcs/initialise_philos.c.i

CMakeFiles/philo_two.dir/srcs/initialise_philos.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/philo_two.dir/srcs/initialise_philos.c.s"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/qli/CLionProjects/philosophers/philo_two/srcs/initialise_philos.c -o CMakeFiles/philo_two.dir/srcs/initialise_philos.c.s

CMakeFiles/philo_two.dir/srcs/libft_functions.c.o: CMakeFiles/philo_two.dir/flags.make
CMakeFiles/philo_two.dir/srcs/libft_functions.c.o: ../srcs/libft_functions.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/qli/CLionProjects/philosophers/philo_two/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/philo_two.dir/srcs/libft_functions.c.o"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/philo_two.dir/srcs/libft_functions.c.o   -c /home/qli/CLionProjects/philosophers/philo_two/srcs/libft_functions.c

CMakeFiles/philo_two.dir/srcs/libft_functions.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/philo_two.dir/srcs/libft_functions.c.i"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/qli/CLionProjects/philosophers/philo_two/srcs/libft_functions.c > CMakeFiles/philo_two.dir/srcs/libft_functions.c.i

CMakeFiles/philo_two.dir/srcs/libft_functions.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/philo_two.dir/srcs/libft_functions.c.s"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/qli/CLionProjects/philosophers/philo_two/srcs/libft_functions.c -o CMakeFiles/philo_two.dir/srcs/libft_functions.c.s

CMakeFiles/philo_two.dir/srcs/print.c.o: CMakeFiles/philo_two.dir/flags.make
CMakeFiles/philo_two.dir/srcs/print.c.o: ../srcs/print.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/qli/CLionProjects/philosophers/philo_two/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/philo_two.dir/srcs/print.c.o"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/philo_two.dir/srcs/print.c.o   -c /home/qli/CLionProjects/philosophers/philo_two/srcs/print.c

CMakeFiles/philo_two.dir/srcs/print.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/philo_two.dir/srcs/print.c.i"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/qli/CLionProjects/philosophers/philo_two/srcs/print.c > CMakeFiles/philo_two.dir/srcs/print.c.i

CMakeFiles/philo_two.dir/srcs/print.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/philo_two.dir/srcs/print.c.s"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/qli/CLionProjects/philosophers/philo_two/srcs/print.c -o CMakeFiles/philo_two.dir/srcs/print.c.s

CMakeFiles/philo_two.dir/srcs/process_input.c.o: CMakeFiles/philo_two.dir/flags.make
CMakeFiles/philo_two.dir/srcs/process_input.c.o: ../srcs/process_input.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/qli/CLionProjects/philosophers/philo_two/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/philo_two.dir/srcs/process_input.c.o"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/philo_two.dir/srcs/process_input.c.o   -c /home/qli/CLionProjects/philosophers/philo_two/srcs/process_input.c

CMakeFiles/philo_two.dir/srcs/process_input.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/philo_two.dir/srcs/process_input.c.i"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/qli/CLionProjects/philosophers/philo_two/srcs/process_input.c > CMakeFiles/philo_two.dir/srcs/process_input.c.i

CMakeFiles/philo_two.dir/srcs/process_input.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/philo_two.dir/srcs/process_input.c.s"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/qli/CLionProjects/philosophers/philo_two/srcs/process_input.c -o CMakeFiles/philo_two.dir/srcs/process_input.c.s

CMakeFiles/philo_two.dir/srcs/time_calculation.c.o: CMakeFiles/philo_two.dir/flags.make
CMakeFiles/philo_two.dir/srcs/time_calculation.c.o: ../srcs/time_calculation.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/qli/CLionProjects/philosophers/philo_two/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/philo_two.dir/srcs/time_calculation.c.o"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/philo_two.dir/srcs/time_calculation.c.o   -c /home/qli/CLionProjects/philosophers/philo_two/srcs/time_calculation.c

CMakeFiles/philo_two.dir/srcs/time_calculation.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/philo_two.dir/srcs/time_calculation.c.i"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/qli/CLionProjects/philosophers/philo_two/srcs/time_calculation.c > CMakeFiles/philo_two.dir/srcs/time_calculation.c.i

CMakeFiles/philo_two.dir/srcs/time_calculation.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/philo_two.dir/srcs/time_calculation.c.s"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/qli/CLionProjects/philosophers/philo_two/srcs/time_calculation.c -o CMakeFiles/philo_two.dir/srcs/time_calculation.c.s

CMakeFiles/philo_two.dir/srcs/start_action.c.o: CMakeFiles/philo_two.dir/flags.make
CMakeFiles/philo_two.dir/srcs/start_action.c.o: ../srcs/start_action.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/qli/CLionProjects/philosophers/philo_two/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/philo_two.dir/srcs/start_action.c.o"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/philo_two.dir/srcs/start_action.c.o   -c /home/qli/CLionProjects/philosophers/philo_two/srcs/start_action.c

CMakeFiles/philo_two.dir/srcs/start_action.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/philo_two.dir/srcs/start_action.c.i"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/qli/CLionProjects/philosophers/philo_two/srcs/start_action.c > CMakeFiles/philo_two.dir/srcs/start_action.c.i

CMakeFiles/philo_two.dir/srcs/start_action.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/philo_two.dir/srcs/start_action.c.s"
	gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/qli/CLionProjects/philosophers/philo_two/srcs/start_action.c -o CMakeFiles/philo_two.dir/srcs/start_action.c.s

# Object files for target philo_two
philo_two_OBJECTS = \
"CMakeFiles/philo_two.dir/main.c.o" \
"CMakeFiles/philo_two.dir/srcs/check_status.c.o" \
"CMakeFiles/philo_two.dir/srcs/clean_up.c.o" \
"CMakeFiles/philo_two.dir/srcs/initialise_philos.c.o" \
"CMakeFiles/philo_two.dir/srcs/libft_functions.c.o" \
"CMakeFiles/philo_two.dir/srcs/print.c.o" \
"CMakeFiles/philo_two.dir/srcs/process_input.c.o" \
"CMakeFiles/philo_two.dir/srcs/time_calculation.c.o" \
"CMakeFiles/philo_two.dir/srcs/start_action.c.o"

# External object files for target philo_two
philo_two_EXTERNAL_OBJECTS =

philo_two: CMakeFiles/philo_two.dir/main.c.o
philo_two: CMakeFiles/philo_two.dir/srcs/check_status.c.o
philo_two: CMakeFiles/philo_two.dir/srcs/clean_up.c.o
philo_two: CMakeFiles/philo_two.dir/srcs/initialise_philos.c.o
philo_two: CMakeFiles/philo_two.dir/srcs/libft_functions.c.o
philo_two: CMakeFiles/philo_two.dir/srcs/print.c.o
philo_two: CMakeFiles/philo_two.dir/srcs/process_input.c.o
philo_two: CMakeFiles/philo_two.dir/srcs/time_calculation.c.o
philo_two: CMakeFiles/philo_two.dir/srcs/start_action.c.o
philo_two: CMakeFiles/philo_two.dir/build.make
philo_two: CMakeFiles/philo_two.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/qli/CLionProjects/philosophers/philo_two/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking C executable philo_two"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/philo_two.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/philo_two.dir/build: philo_two

.PHONY : CMakeFiles/philo_two.dir/build

CMakeFiles/philo_two.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/philo_two.dir/cmake_clean.cmake
.PHONY : CMakeFiles/philo_two.dir/clean

CMakeFiles/philo_two.dir/depend:
	cd /home/qli/CLionProjects/philosophers/philo_two/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/qli/CLionProjects/philosophers/philo_two /home/qli/CLionProjects/philosophers/philo_two /home/qli/CLionProjects/philosophers/philo_two/cmake-build-debug /home/qli/CLionProjects/philosophers/philo_two/cmake-build-debug /home/qli/CLionProjects/philosophers/philo_two/cmake-build-debug/CMakeFiles/philo_two.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/philo_two.dir/depend

