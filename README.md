*This project has been created as part of the 42 curriculum by sgwon.*
## Description

### push_swap
* You have 2 stacks named a and b.
	* The stack a contains a random number of unique negative and/or positive integers.
	* The stack b is empty.

* The goal is to sort the numbers in stack a in ascending order. To achieve this, you
have the following operations at your disposal:

	```
	sa (swap a): Swap the first 2 elements at the top of stack a.
		Do nothing if there is only one element or none.
	sb (swap b): Swap the first 2 elements at the top of stack b.
		Do nothing if there is only one element or none.
	ss : sa and sb at the same time.
	pa (push a): Take the first element at the top of b and put it at the top of a.
		Do nothing if b is empty.
	pb (push b): Take the first element at the top of a and put it at the top of b.
		Do nothing if a is empty.
	ra (rotate a): Shift up all elements of stack a by 1.
		The first element becomes the last one.
	rb (rotate b): Shift up all elements of stack b by 1.
		The first element becomes the last one.
	rr : ra and rb at the same time.
	rra (reverse rotate a): Shift down all elements of stack a by 1.
		The last element becomes the first one.
	rrb (reverse rotate b): Shift down all elements of stack b by 1.
		The last element becomes the first one.
	rrr : rra and rrb at the same time.
	```

*  The program must display the shortest sequence of instructions needed to sort stack
a with the smallest number at the top.
	* If no parameters are specified, the program must not display anything and should return to the prompt.
	* In case of error, it must display "Error" followed by an '\n' on the standard error. Errors include, for example: some arguments not being integers, some arguments exceeding the integer limits, and/or the presence of duplicates.

### checker


## Instructions
The commands shown below are written for the fish shell.
### Build
```
make		# creates push_swap
make bonus	# creates checker
```

### Run
```
./push_swap [stack_numbers]
```
It prints all operations that ```push_swap``` performed.

### Check the number of operations executed
```
./push_swap [stack_numbers] | wc -l
```

### Validate the result with the checker
```
set ARG "[stack_numbers]"; ./push_swap $ARG | ./checker[_Linux] $ARG 
```
It prints "OK" if ```push_swap``` sorts the numbers correctly, otherwise "KO". <br/>
In case of error, it prints "ERROR".

## Resources
[Tutorial](https://automatic-saltopus-34b.notion.site/push_swap-c15e62229b9541d78fadec4d6aae8b50)<br/>
[Algorithm reference](https://github.com/ayogun/push_swap/tree/main)