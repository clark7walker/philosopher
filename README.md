*This project has been created as part of the 42 curriculum by cltan.*

# Philosophers

A solution to the classic **Dining Philosophers** concurrency problem,
implemented in C using POSIX threads and mutexes.

## Description

One or more philosophers sit at a round table with a large bowl of spaghetti.
Each philosopher alternates between three states: **eating**, **sleeping**,
and **thinking**. There is one fork between each pair of philosophers — and
a philosopher needs **two forks** to eat.

If a philosopher goes too long without eating, they die. The goal is to
ensure no philosopher starves.

This project explores the fundamentals of concurrent programming:
- Creating and managing threads with `pthread`
- Preventing data races with mutexes
- Avoiding deadlock through consistent lock ordering
- Precise timing and death detection

## How It Works

### Architecture
- Each philosopher runs as an independent **thread**
- A separate **monitor thread** continuously checks for death or completion
- Each fork is protected by its own **mutex**
- Shared state (`last_meal_time`, `running` flag) is protected by mutexes

### Deadlock Prevention
Forks are always acquired in **index order** (lower index first). This
breaks the circular dependency that causes deadlock — no philosopher can
ever be waiting on a fork held by someone waiting on their fork.

### Death Detection
The monitor thread checks every millisecond whether any philosopher has
exceeded `time_to_die` since their last meal. Death is reported within
10ms of occurrence.

## Instructions

### Compilation
```bash
make        # build
make clean  # remove objects
make fclean # remove objects and binary
make re     # rebuild
```

### Usage
```bash
./philo num_philosophers time_to_die time_to_eat time_to_sleep [must_eat]
```

| Argument | Description |
|----------|-------------|
| `num_philosophers` | Number of philosophers and forks |
| `time_to_die` | Milliseconds before a philosopher starves |
| `time_to_eat` | Milliseconds to eat (requires two forks) |
| `time_to_sleep` | Milliseconds to sleep |
| `must_eat` | Optional — stops when all philosophers eat this many times |

### Examples
```bash
# 5 philosophers, none should die
./philo 5 800 200 200

# simulation stops after each philosopher eats 7 times
./philo 5 800 200 200 7

# one philosopher should die
./philo 4 310 200 100

# single philosopher — dies (can never get second fork)
./philo 1 800 200 200
```

## Testing

Verified with:
- `valgrind --tool=helgrind` — no data races
- `valgrind --leak-check=full` — no memory leaks
- `norminette` — complies with 42 Norm

## Resources

- [Dining Philosophers Problem — Wikipedia](https://en.wikipedia.org/wiki/Dining_philosophers_problem)
- `man pthread_create` / `man pthread_mutex_lock` / `man gettimeofday`
- [POSIX Threads Programming — Lawrence Livermore](https://hpc-tutorials.llnl.gov/posix/)