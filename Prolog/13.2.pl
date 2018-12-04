numberGrid(A1, A2, A3, B1, B2, B3, C1, C2, C3) :- permutation([A1, A2, A3, B1, B2, B3, C1, C2, C3], [1, 2, 3, 4, 5, 6, 7, 8, 9]),
A1 + A2 + A3 =:= B1 + B2 + B3,
B1 + B2 + B3 =:= C1 + C2 + C3,
C1 + C2 + C3 =:= A1 + B1 + C1,
A1 + B1 + C1 =:= A2 + B2 + C2,
A2 + B2 + C2 =:= A3 + B3 + C3,
A3 + B3 + C3 =:= A1 + B2 + C3,
A1 + B2 + C3 =:= A3 + B2 + C1.

/*

CREDIT HELP: Cade Coughlin.

*/