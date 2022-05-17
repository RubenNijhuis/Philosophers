# Philosophers
🧐  Philosophers is a project for Codam (42 network) which teaches multithreading and the usage of mutexes

# Quick start
```
$ make
$ make run
```
And watch as the philosophers dine and enjoy a nice meal

## Running the program
The program only accepts positive integers and a maximum of 200 philosophers (not planning making your pc explode)

```
$ ./bin/philsophers [amount_philo] [time_to_die (ms)] [time_to_eat (ms)] [time_to_sleep  (ms)] [optional amount_times_eat]
```

## Structure
```
/- Philosophers
    /- bin      # binary to be executed gets put here
    /- include  # .h files
    /- src      # project source
    Makefile # compiling magic happens here
```

Made with ❤️
