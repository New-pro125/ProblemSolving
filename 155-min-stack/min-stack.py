import sys

class MinStack:

    def __init__(self):
        self.min_stack = []
        self.min_value_tracker = []

    def push(self, val: int) -> None:
        # Add value to the stack
        self.min_stack.append(val)
        # If it's the first element or the new element is smaller than the current minimum
        if not self.min_value_tracker:
            self.min_value_tracker.append(val)
        else:
            # Track the minimum value at each level of the stack
            self.min_value_tracker.append(min(val, self.min_value_tracker[-1]))

    def pop(self) -> None:
        # Pop the top element from both stacks
        self.min_stack.pop()
        self.min_value_tracker.pop()

    def top(self) -> int:
        # Return the last element from the stack
        return self.min_stack[-1]

    def getMin(self) -> int:
        # Return the current minimum value
        return self.min_value_tracker[-1]
