#J-K Flip-Flop
import pandas as pd
class JKFlipFlop:
    def __init__(self):
        self.Q = 0  # Initial state

    def clock_pulse(self, J, K):
        if J == 0 and K == 0:
            pass  # No change
        elif J == 0 and K == 1:
            self.Q = 0  # Reset
        elif J == 1 and K == 0:
            self.Q = 1  # Set
        elif J == 1 and K == 1:
            self.Q = 1 - self.Q  # Toggle

    def get_state(self):
        return self.Q

# Example usage
if __name__ == "__main__":
    jk_ff = JKFlipFlop()
    inputs = [(0, 0), (1, 0), (0, 1), (1, 1), (1, 1), (0, 0)]
    
    for J, K in inputs:
        jk_ff.clock_pulse(J, K)
        print(f"J: {J}, K: {K} => Q: {jk_ff.get_state()}")

    # Save the state transitions to a CSV file
    states = []
    jk_ff = JKFlipFlop()  # Reset flip-flop
    for J, K in inputs:
        jk_ff.clock_pulse(J, K)
        states.append({'J': J, 'K': K, 'Q': jk_ff.get_state()})
    df = pd.DataFrame(states)
    df.to_csv('jk_flipflop_states.csv', index=False)
