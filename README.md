# Prac1_214
Factory Method pattern, Prototype pattern, Template Method pattern, Memento pattern


# Student Number
u25144465

# Explain the purpose of mutual exclusion

To prevent 2 threads from entering the critical section at the same time and causing error in the result

# Implement software locking algorithms



# Demonstrate the behaviour of concurrent threads



# Explain why certain algorithms fail

LockOne fails with concurrent threads if execution overlaps where both threads set their flags to true before checking the boolean of the other threads flag. Then both threads will check the other threads flag and see it is true and enter a permanent state of waiting causing deadlock.



# Explain how Peterson’s Lock resolves these failures