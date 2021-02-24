[![Logo](https://github.com/qingqingqingli/readme_images/blob/master/codam_logo_1.png)](https://github.com/qingqingqingli/philosophers)

# philosophers

***This project focuses on the basics of threading a process and how to work on the same memory space. You will learn how to make threads, and discover the mutex, semaphore and shared memory.***

## Project requirements

- A number of philosophers are sitting at a round table doing one of three things: `eating`, `thinking` or `sleeping`. 
  
- The philosophers sit at a circular table with a large bowl of spaghetti in the center. There are some forks on the table. As spaghetti is difficult to serve and philo_eat with a single fork, it is assumed that a philosopher `must philo_eat with two forks`, one for each hand.

- The philosophers must never be starving. Every philosopher needs to philo_eat. Philosophers don’t speak with each other. Philosophers don’t know when another philosopher is about to die. 

- Each time a philosopher has finished eating, he will drop his forks and start sleeping. When a philosopher is done sleeping, he will start thinking. The simulation stops when a philosopher dies.

## philo_one [link](https://github.com/qingqingqingli/philosophers/tree/main/philo_one)

- One fork between each philosopher, therefore there will be a fork at the right and at the left of each philosopher.
  
- To avoid philosophers duplicating forks, you should protect the forks state with a `mutex` for each of them.
  
- Each philosopher should be a `thread`.

## philo_two [link](https://github.com/qingqingqingli/philosophers/tree/main/philo_two)

- All the forks are in the middle of the table.
  
- They have no states in memory but the number of available forks is represented by a `semaphore`.
  
- Each philosopher should be a `thread`.

## philo_three [link](https://github.com/qingqingqingli/philosophers/tree/main/philo_three)

- All the forks are in the middle of the table.
  
- They have no states in memory but the number of available forks is represented by a `semaphore`.
  
- Each philosopher should be a `process` and the main process should not be a philosopher.