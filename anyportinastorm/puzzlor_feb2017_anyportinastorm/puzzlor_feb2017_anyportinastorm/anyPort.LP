\ENCODING=ISO-8859-1
\Problem name: IloCplex

Minimize
 obj: x1 + 3 x2 + 2 x3 + 2 x4 + 2 x5 + x6 + 3 x7 + 2 x8 + x9
Subject To
 c1: x1 + x2 + x3  = 8
 c2: x4 + x5 + x6  = 5
 c3: x7 + x8 + x9  = 7
 c4: x1 + x4 + x7  = 4
 c5: x2 + x5 + x8  = 7
 c6: x3 + x6 + x9  = 9
Bounds
      x1 >= 0
      x2 >= 0
      x3 >= 0
      x4 >= 0
      x5 >= 0
      x6 >= 0
      x7 >= 0
      x8 >= 0
      x9 >= 0
Generals
 x1  x2  x3  x4  x5  x6  x7  x8  x9 
End
