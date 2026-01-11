# Dynamic Integer List in C++
    A high-performance, dynamic integer list implementation in C++ that manages memory efficiently. 
    This project demonstrates core data structure concepts, including dynamic resizing, memory-efficient element removal.
## Dynamic Resizing:
    Automatically expands capacity by 2x when full and shrinks by 50% when the load factor drops below 20% to optimize memory usage.
## Performance Optimized:
    Uses memmove for fast block-level memory shifts during element removal, avoiding slow element-by-element loops.
## Memory Managed:
    Properly implemented constructors and destructors to prevent memory leaks. 