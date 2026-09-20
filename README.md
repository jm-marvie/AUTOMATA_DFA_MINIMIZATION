# AUTOMATA_DFA_MINIMIZATION

**Comprehensive Analysis, Partition Refinement, and Implementation Structure**

📌 **Overview**

This project demonstrates the minimization of Deterministic Finite Automata (DFA). A DFA is a finite-state machine that reads an input string one symbol at a time. For every state and input symbol, there is exactly one possible next state.

The goal of DFA minimization is to reduce the number of states while preserving the same language accepted by the original DFA.

### Minimization Process
1. **0-Equivalence / Initial Partition** — Separate accepting states from non-accepting states.
2. **1-Equivalence** — Compare where each state goes for every input symbol.
3. **2-Equivalence and succeeding partitions** — Continue separating states until no further changes occur.
4. **Merge equivalent states** — States that remain equivalent are combined into a single state.

---

## DFA 1

### Original DFA
- **States:** `A` (Start), `B`, `C`, `D`, `E` (Accepting)
- **Alphabet:** Σ = `{0, 1}`
- **Accepting State:** `{E}`

### Transition Table

| State | 0 | 1 |
|-------|---|---|
| **→ A** | B | C |
| **B** | B | D |
| **C** | D | C |
| **D** | B | E |
| ***E** | B | C |

### Minimization Steps
- **0-Equivalence:** The accepting state is separated from non-accepting states: `{A, B, C, D} | {E}`
- **1-Equivalence:** After comparing transitions: `{A, B, C} | {D} | {E}`
- **2-Equivalence:** Further comparison gives: `{A, C} | {B} | {D} | {E}`
- **3-Equivalence:** Partition remains unchanged: `{A, C} | {B} | {D} | {E}`

*Result:* Final equivalent states are `{A, C}`, `{B}`, `{D}`, `{E}`. States A and C are merged.

### Minimized DFA 1
- **Minimized States:** `AC`, `B`, `D`, `E`
- **Accepting State:** `{E}`

| State | 0 | 1 |
|-------|---|---|
| **→ AC** | B | AC |
| **B** | B | D |
| **D** | B | E |
| ***E** | B | AC |

### Accepted and Rejected Inputs
The minimized DFA accepts a string when the input ends in state E. A string is accepted if, after the last 0, it contains exactly two consecutive 1s modulo 3 (i.e., trailing 1s count must be 2, 5, 8, 11, ...).

- **Accepted Examples:** `011` ✓, `0011` ✓, `1011` ✓, `00011` ✓, `01011` ✓, `10011` ✓, `11011` ✓
- **Rejected Examples:** `ε` ✗, `0` ✗, `1` ✗, `00` ✗, `01` ✗, `10` ✗, `11` ✗, `010` ✗, `0110` ✗, `111` ✗, `1111` ✗

> **Note:** For DFA 1, when A and C are merged, the transition on 1 from AC points back to AC, not a separate C, because C is already part of the merged state `{A, C}`.

### Visualization
![Example 1](Example1/Example%201.png)

---

## DFA 2

### Original DFA
- **States:** `A` (Start), `B`, `C` (Accepting), `D` (Accepting), `E` (Accepting), `F`
- **Alphabet:** Σ = `{0, 1}`
- **Accepting States:** `{C, D, E}`

### Transition Table

| State | 0 | 1 |
|-------|---|---|
| **→ A** | B | C |
| **B** | A | D |
| ***C** | E | F |
| ***D** | E | F |
| ***E** | E | F |
| **F** | F | F |

### Minimization Steps
- **0-Equivalence:** Separate accepting and non-accepting states: `{A, B, F} | {C, D, E}`
- **1-Equivalence:** After comparing transitions: `{A, B} | {F} | {C, D, E}`
- **2-Equivalence:** Partition remains unchanged: `{A, B} | {F} | {C, D, E}`

*Result:* `A ≡ B`, `C ≡ D ≡ E`, `F`

### Minimized DFA 2
- **Minimized States:** `AB`, `CDE`, `F`
- **Accepting State:** `{CDE}`

| State | 0 | 1 |
|-------|---|---|
| **→ AB** | AB | CDE |
| ***CDE** | CDE | F |
| **F** | F | F |

### Accepted and Rejected Inputs
A string is accepted if and only if it contains exactly one 1. Therefore, any number of 0s may appear before or after the single 1.

- **Accepted Examples:** `1` ✓, `01` ✓, `10` ✓, `001` ✓, `010` ✓, `100` ✓, `0001` ✓, `00100` ✓, `10000` ✓, `000001` ✓
- **Rejected Examples (Zero 1s):** `ε` ✗, `0` ✗, `00` ✗, `000` ✗, `0000` ✗
- **Rejected Examples (Two or more 1s):** `11` ✗, `101` ✗, `110` ✗, `011` ✗, `1010` ✗, `1100` ✗, `0101` ✗, `111` ✗

### Visualization
![Example 2](Example2/Example%202.png)

---

## DFA 3

### Original DFA
- **States:** `w` (Start), `x`, `y`, `z` (Accepting)
- **Alphabet:** Σ = `{0, 1}`
- **Accepting State:** `{z}`

### Transition Table

| State | 0 | 1 |
|-------|---|---|
| **→ w** | w | x |
| **x** | y | z |
| **y** | w | x |
| ***z** | z | z |

### Minimization Steps
- **0-Equivalence:** `{w, x, y} | {z}`
- **1-Equivalence:** `{w, y} | {x} | {z}`
- **2-Equivalence:** Partition remains `{w, y} | {x} | {z}`

*Result:* `w ≡ y`, `x`, `z`. States w and y are merged.

### Minimized DFA 3
- **Minimized States:** `WY`, `X`, `Z`
- **Accepting State:** `{Z}`

| State | 0 | 1 |
|-------|---|---|
| **→ WY** | WY | X |
| **X** | WY | Z |
| ***Z** | Z | Z |

### Accepted and Rejected Inputs
A string is accepted if it contains at least two consecutive 1s (substring `11`).

- **Accepted Examples:** `11` ✓, `011` ✓, `110` ✓, `111` ✓, `0110` ✓, `1011` ✓, `1101` ✓, `0011` ✓, `1111` ✓, `00110` ✓
- **Rejected Examples:** `ε` ✗, `0` ✗, `1` ✗, `00` ✗, `01` ✗, `10` ✗, `010` ✗, `101` ✗, `10101` ✗ *(1s separated by 0s)*

### Visualization
![Example 3](Example%203/Example%203.png)

---

## DFA 4

### Original DFA
- **States:** `w` (Start/Accepting), `x`, `y` (Accepting), `z`
- **Alphabet:** Σ = `{0, 1}`
- **Accepting States:** `{w, y}`

### Transition Table

| State | 0 | 1 |
|-------|---|---|
| ***→ w** | x | w |
| **x** | w | x |
| ***y** | z | y |
| **z** | y | z |

### Minimization Steps
- **0-Equivalence:** Separate accepting and non-accepting states: `{w, y} | {x, z}`
- **1-Equivalence:** The same partition remains: `{w, y} | {x, z}`

*Result:* No further separation is necessary. Equivalent states: `w ≡ y`, `x ≡ z`.

### Minimized DFA 4
- **Minimized States:** `WY`, `XZ`
- **Accepting State:** `{WY}`

| State | 0 | 1 |
|-------|---|---|
| ***→ WY** | XZ | WY |
| **XZ** | WY | XZ |

### Accepted and Rejected Inputs
A string is accepted if the total number of 0s is even. The number of 1s does not affect acceptance.

- **Accepted Examples:** `ε` ✓, `1` ✓, `00` ✓, `11` ✓, `001` ✓, `010` ✓, `100` ✓, `111` ✓, `0000` ✓, `0011` ✓, `0101` ✓, `1010` ✓, `1111` ✓
- **Rejected Examples:** `0` ✗, `000` ✗, `01` ✗, `10` ✗, `0010` ✗, `0001` ✗, `0111` ✗, `1000` ✗, `1011` ✗, `1101` ✗

### Visualization
### Visualization
![Example 4](Example%204/Example%204.png)

---

## 📊 Summary of the Four DFAs

| DFA | Original States | Minimized States | Accepting States | Language Description |
|-----|-----------------|------------------|------------------|----------------------|
| **DFA 1** | 5 | 4 | E | Trailing 1s after last 0 are 2 mod 3 |
| **DFA 2** | 6 | 3 | CDE | Strings containing exactly one 1 |
| **DFA 3** | 4 | 3 | Z | Strings containing substring 11 |
| **DFA 4** | 4 | 2 | WY | Strings containing an even number of 0s |

---
