%Two integers, n and m are given. Write a predicate to determine
% all possible sequences of numbers from 1 to n, such that between any
% two numbers from consecutive positions, the absolute difference to be
% >= m.
%difference(a, b) = a - b, if a > b b - a, if a < b
difference(A, B, R):-
    A > B,
    R is A - B.
difference(A, B, R):-
    A < B,
    R is B - A.

%sequences(n ,i) = [], i = n + 1
%                  i U sequences(n, i+1), i <= n
%                  sequences(n, i+1), i <= n
sequences(N, I, []):-
    I =:= N + 1,
    !.
sequences(N, I, [I|R]):-
    I =< N,
    NewI is I + 1,
    sequences(N, NewI, R).
sequences(N, I, R):-
    I =< N,
    NewI is I + 1,
    sequences(N, NewI, R).

%check(l1..ln, m) = true, if diff(l1, l2) >= m and n > 2
%                   check(l2..ln, m), diff(l1, l2) >= m and n > 2
%                   false, otherwise
check([H1, H2], M):-
    difference(H1, H2, R1),
    R1 >= M,
    !.
check([H1, H2|T], M):-
    difference(H1, H2, R1),
    R1 >= M,
    check([H2|T], M).

oneSol(N, M, R):-
    sequences(N, 1, R),
    check(R, M).

allSequences(N, M, R):-
    findall(R1, oneSol(N, M, R1), R).
