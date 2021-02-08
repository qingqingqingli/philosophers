
### PROGRAM PARAMETERS

- `number_of_philosophers`
    - Number of philosophers and forks

-   `time_to_die` (in milliseconds)
    - if a philosopher doesn't start eating 'time_to_eat' milliseconds after starting his last meal or the beginning of the stimulation, it dies
    
- `time_to_eat` (in milliseconds)
    - the time it takes for a philosopher to eat. During that time he will need to keep the two forks

- `time_to_sleep` (in milliseconds)
    - the time the philosopher will spend sleeping

- `number_of_times_each_philosopher_must_eat` (optional)
    - If all philosophers eat at least this amount of times, the stimulation will stop
    - If not specified, the stimulation will stop only at the death of a philosopher

### SPECIFICATIONS

- Each philosopher should be given a number from 1 to `number_of_philosophers`. Philosopher number 1 is next to philosopher number ’number_of_philosophers’. Any other philosopher with number N is seated between philosopher N - 1 and philosopher N + 1

- Any change of status of a philosopher must be written as follows (with X replaced with the philosopher number and timestamp_in_ms the current timestamp in milliseconds)
    - `timestamp_in_ms X has taken a fork`
    - `timestamp_in_ms X is eating`
    - `timestamp_in_ms X is sleeping`
    - `timestamp_in_ms X is thinking`
    - `timestamp_in_ms X died`

- `No more than 10 seconds` between the death of a philosopher and when it will print its death

- Philosophers should avoid to die

### THREE SOLUTIONS

`PHILO_ONE`

- One fork between each philosopher, therefore there will be a fork at the right and at the left of each philosopher.
- To avoid philosophers duplicating forks, you should `protect the forks state` with a mutex for each of them.
- Each philosopher should be a thread.

`PHILO_TWO`

- All the forks are in the middle of the table.
- They have no states in memory but the number of available forks is represented by a semaphore.
- Each philosopher should be a thread.

`PHILO_THREE`

- All the forks are in the middle of the table.
- They have no states in memory but the number of available forks is represented by a semaphore.
- Each philosopher should be a process and the main process should not be a philosopher.

### process threading

### mutex

### semaphore
