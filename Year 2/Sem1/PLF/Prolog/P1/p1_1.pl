%a. Write a predicate to determine the lowest common multiple of a list formed from integer numbers.
%cmmdc(a, b) = a, a == b
%              cmmdc(a-b, b), if a > b
%              cmmdc(a, b-a), if b <= a

cmmdc(A, B, R):-
    A == B,
    R = A.
cmmdc(A, B, R):-
    A > B,
    A1 is A - B,
    cmmdc(A1, B, R).
cmmdc(A, B, R):-
    A < B,
    B1 is B - A,
    cmmdc(A, B1, R).

%lcm(a, b) = a * b / gcd(a, b)
lcm(A, B, R):-
    cmmdc(A, B, R1),
    R is A*B/R1.

%model matematic
lcmList([], 1).
lcmList([H|T], NewR):-
    lcmList(T, R),
    P is H*R,
    cmmdc(H, R, Rcmmdc),
    NewR is P div Rcmmdc.

%b. Write a predicate to add a value v after 1-st, 2-nd, 4-th, 8-th, … element in a list.
%
% addValue(l1..ln, v, pow, pos) = [], if n = 0
%                                 l1 U v U addValue(l2..ln, v, pow*2,
% pos + 1), if pos = pow
%                                 l1 U addValue(l2..ln, v, pow, pos +
%                                 1), otherwise

addValue([], _, _, _, []).
addValue([H|T], V, Pow, Pos, [H, V|R]):-
    Pos == Pow,
    NewPos is Pos + 1,
    NewPow is Pow*2,
    addValue(T, V, NewPow, NewPos, R).
addValue([H|T], V, Pow, Pos, [H|R]):-
    Pos =\= Pow,
    NewPos is Pos + 1,
    addValue(T, V, Pow, NewPos, R).
addValueMain(L, V, R):-
    addValue(L, V, 1, 1, R).
