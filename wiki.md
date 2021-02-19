
### PROGRAM PARAMETERS

1. `number_of_philosophers`
    - Number of philosophers and forks

2. `time_to_die` (*in milliseconds*)
    - if a philosopher doesn't start eating 'time_to_eat' milliseconds after starting his last meal or the beginning of the stimulation, it dies
    
3. `time_to_eat` (*in milliseconds*)
    - the time it takes for a philosopher to philo_eat. During that time he will need to keep the two forks

4. `time_to_sleep` (*in milliseconds*)
    - the time the philosopher will spend sleeping

5. `number_of_times_each_philosopher_must_eat` (*optional*)
    - If all philosophers philo_eat at least this amount of times, the stimulation will stop
    - If not specified, the stimulation will stop only at the death of a philosopher

### SPECIFICATIONS

- Each philosopher should be given a number from 1 to `number_of_philosophers`. Philosopher number 1 is next to philosopher number ’number_of_philosophers’. Any other philosopher with number N is seated between philosopher N - 1 and philosopher N + 1

- Any change of status of a philosopher must be written as follows (with `X` replaced with the philosopher number and `timestamp_in_ms` the current timestamp in milliseconds)
    - `timestamp_in_ms X has taken a fork`
    - `timestamp_in_ms X is eating`
    - `timestamp_in_ms X is sleeping`
    - `timestamp_in_ms X is thinking`
    - `timestamp_in_ms X died`

- `No more than 10 seconds` between the death of a philosopher and when it will print_prompt its death

- Philosophers should avoid to die

### THREE SOLUTIONS

`PHILO_ONE` (*philosopher with threads and mutex*)

- Allowed functions: `memset`, `printf`, `malloc`, `free`, `write`, `usleep`, `gettimeofday`, `pthread_create`, `pthread_detach`, `pthread_join`, `pthread_mutex_init`, `pthread_mutex_destroy`, `pthread_mutex_lock`, `pthread_mutex_unlock`
- One fork between each philosopher, therefore there will be a fork at the right and at the left of each philosopher.
- To avoid philosophers duplicating forks, you should `protect the forks state` with a mutex for each of them.
- Each philosopher should be a thread.

`PHILO_TWO` (*philosopher with threads and semaphore*)

- Allowed functions: `memset`, `printf`, `malloc`, `free`, `write`, `usleep`, `gettimeofday`, `pthread_create`, `pthread_detach`, `pthread_join`, `sem_open`, `sem_close`, `sem_post`, `sem_wait`, `sem_unlink`
- All the forks are in the middle of the table.
- They have no states in memory but the number of available forks is represented by a semaphore.
- Each philosopher should be a thread.

`PHILO_THREE` (*philosopher with processes and semaphore*)

- Allowed functions: `memset`, `printf`, `malloc`, `free`, `write`, `fork`, `kill`, `exit`, `pthread_create`, `pthread_detach`, `pthread_join`, `usleep`, `gettimeofday`, `waitpid`, `sem_open`, `sem_close`, `sem_post`, `sem_wait`, `sem_unlink`
- All the forks are in the middle of the table.
- They have no states in memory but the number of available forks is represented by a semaphore.
- Each philosopher should be a process and the main process should not be a philosopher.

### process threading
- With `fork()`, you create a new process. You create concurrency and isolation. When one process fails, the other process is usually fine. Both processes have their only memory spaces. 

- With `threads`, you can get concurrency without isolation. Threads have different call stacks but they are in the same memory space. One thread can write into the memory space of another thread, which makes it easier to communicate between threads. It is both a blessing and curse. 

- `POSIX threads`. The `Portable Operating System Interface` (POSIX) is a family of standards specified by the IEEE Computer Society for maintaining compatibility between operating systems. A single process can contain multiple threads, all of which are executing the same program. These threads share the same global memory (data and heap segments), but each thread has its own stack (automatic variables). 

- POSIX requires that threads `share a range of attributes` (e.g., process ID, parent process ID) and have `distinct attributes` for each thread (e.g., thread ID, errno variable)

- **Pthreads function return values**: Most pthreads functions return 0 on success, and an error number on failure.

- **Thread IDs**: Each of the threads in a process has a unique thread identifier (stored in the type `pthread_t`). This identifier is returned to the caller of `pthread_create`, and a thread can obtain its own thread identifier using `pthread_self`.

- On Linux, programs that use the Pthreads API should be compiled using `cc -pthread`.

- **Race condition**. When multiple threads race to write in the same memory space. `Mutex locks` is a computing abstraction that allows one thread to exclude other threads. Only one thread can have the lock at a time. 

- Three major classes of routines in Pthreads API:
    - Thread management
    - Mutex variables
    - Condition variables

### thread

- A thread is a semi-process, that has its own stack, and executes a given piece of code. Unlike a real process, the thread normally shares its memory with other threads (where as for processes we usually have a different memory area for each one of them).

- A Thread Group is a set of threads all executing inside the same process. They all share the same memory, and thus can access the same global variables, same heap memory, same set of file descriptors, etc.

- The advantage of using a thread group over using a process group is that context switching between threads is much faster then context switching between processes (context switching means that the system switches from running one thread or process, to running another thread or process). Also, communications between two threads is usually faster and easier to implement then communications between two processes.

- On the other hand, because threads in a group all use the same memory space, if one of them corrupts the contents of its memory, other threads might suffer as well. With processes, the operating system normally protects processes from one another, and thus if one corrupts its own memory space, other processes won't suffer. Another advantage of using processes is that they can run on different machines, while all the threads have to run on the same machine (at least normally).

- The call to `pthread_exit()` Causes the current thread to exit and free any thread-specific resources it is taking. There is no need to use this call at the end of the thread's top function, since when it returns, the thread would exit automatically anyway. This function is useful if we want to exit a thread in the middle of its execution.


### mutex

- A Mutex is a mutually exclusive flag, which is used to protect a shared resource by ensuring mutual exclusion inside critical sections of code.
  
- It acts as a `gate keeper` to a section of code allowing one thread in and blocking access to all others. This ensures that the code being controlled will only be hit by a single thread at a time. `Just be sure to release the mutex when you are done.`

- `Mutual exclusion`. It is the requirement that one thread of execution never enters a critical section while a concurrent thread of execution is already accessing `critical section`, which refers to an interval of time during which a thread of execution accesses a shared resource, such as `shared data objects, shared resources, shared memory`.

- Deadlock will occur when the thread which acquired the lock attempts to lock the mutex again. Pay close attention to when you lock and unlock the mutexes.

- Programs having the following characteristics may be well suited for pthreads:
    - Work that can be executed, or data that can be operated on, by multiple tasks simultaneously
    - Block for potentially long I/O waits
    - Use many CPU cycles in some places but not others
    - Must respond to asynchronous events
    - Some work is more important than other work (priority interrupts)

- `pthread_mutex_t a_mutex = PTHREAD_MUTEX_INITIALIZER;` This type of initialization creates a mutex called `fast mutex`. This means that if a thread locks the mutex and then tries to lock it again, it'll get stuck - it will be in a deadlock.

- After we finished using a mutex, we should destroy it. Finished using means no thread needs it at all.

### Condition variable

- A condition variable is a mechanism that allows threads to wait (without wasting CPU cycles) for some event to occur. Several threads may wait on a condition variable, until some other thread signals this condition variable (thus sending a notification). 
  
- At this time, one of the threads waiting on this condition variable wakes up, and can act on the event. It is possible to also wake up all threads waiting on this condition variable by using a broadcast method on this variable.

- Note that a condition variable does not provide locking. Thus, a mutex is used along with the condition variable, to provide the necessary locking when accessing this condition variable.

### Synchronizing on threads exiting

- Sometimes it is desired for a thread to wait for the end of execution of another thread. This can be done using the `pthread_join()` function. It receives two parameters: a variable of type pthread_t, denoting the thread to be joined, and an address of a void* variable, into which the exit code of the thread will be placed.
  The `pthread_join()` function suspends the execution of the calling thread until the joined thread is terminated.

### Detaching a thread

- Threads that are in a 'join-able' state, must be joined by other threads, or else their memory resources will not be fully cleaned out. This is similar to what happens with processes whose parents didn't clean up after them (also called 'orphan' or 'zombie' processes).

- If we have a thread that we wish would `exit whenever it wants` without the need to join it, we should put it in the detached state. This can be done either with appropriate flags to the pthread_create() function, or by using the pthread_detach() function.

### semaphore

- Semaphores can count higher than one. It is a variable used to control access to common resource by multiple processes and avoid critical section problems in a concurrent system. 

- A semaphore can be thought as `a record of how many units of a particular resource are available`, coupled with operations to adjust that record safely.

- Semaphores which allow an arbitrary resource count are called `counting semaphores`, while semaphores which are restricted to the values 0 and 1 are called `binary semaphores` and are used to implement locks.

- A semaphore is a signalling mechanism. `A thread that is waiting on a semaphore can be signaled by another thread`. This is different than a mutex as the mutex can be signaled only by the thread that called the wait function.

- Semaphore is simply a variable which is non-negative and shared between threads. There are mainly two types of semaphores: `counting semaphores` and `binary semaphores`.
    - Binary Semaphore – This is also known as mutex lock. It can have only two values – 0 and 1. Its value is initialized to 1. It is used to implement the solution of critical section problem with multiple processes.
    - Counting Semaphore – Its value can range over an unrestricted domain. It is used to control access to a resource that has multiple instances.


### Differences between mutex and semaphore

- The correct use of a semaphore is for `signaling from one task to another`. 
  
- A mutex is meant to `be taken and released`, always in that order, by each task that uses the shared resource it protects. 
  
- By contrast, tasks that use semaphores `either signal or wait`—not both.

### relevant topics

- Uses a mutex (pthread_mutex) to synchronize the processing to avoid a race condition.
- Timing the process without using threads (Linux time command)
- Switching processing to new threads
- Running multiple threads without a mutex lock (race condition)
- Solving a race condition
- Timing the multi-threaded version
- Common problem when passing arguments to a thread
- Common problem spotting race conditions

### Resources

- [What is a mutex?](https://stackoverflow.com/questions/34524/what-is-a-mutex)
- [Mutexes and Semaphores Demystified](https://barrgroup.com/Embedded-Systems/How-To/RTOS-Mutex-Semaphore)
- [POSIX Threads wikipedia](https://en.wikipedia.org/wiki/POSIX_Threads)
- [POSIX Threads Programming](https://computing.llnl.gov/tutorials/pthreads/)
- [Introduction to Parallel Computing Tutorial](https://hpc.llnl.gov/training/tutorials/introduction-parallel-computing-tutorial)
- [Chapter 4 Programming with Synchronization Objects](https://docs.oracle.com/cd/E19683-01/806-6867/6jfpgdcnd/index.html)
- [Using Mutual Exclusion Locks](https://docs.oracle.com/cd/E19683-01/806-6867/6jfpgdcng/index.html)
- [Multi-Threaded Programming With POSIX Threads](http://www.cs.kent.edu/~ruttan/sysprog/lectures/multi-thread/multi-thread.html#definition)