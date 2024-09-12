n ← "seconds"‿"minutes"‿"hours"‿"days"‿"weeks"
t ←  60      ‿ 60      ‿ 24    ‿ 7

•Out "Input amount of seconds to translate to "∾ ':'∾˜ ∾⟜", "⊸∾´ n
s ← •ParseFloat •GetLine ""
•Out¨ n∾¨ ' '∾¨ •Repr¨ (60|s)∾ t| ⌊s÷` t
