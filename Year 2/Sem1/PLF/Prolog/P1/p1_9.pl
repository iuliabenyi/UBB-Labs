%a. Insert an element on the position n in a list
%
%insert(l1..ln, e, x, pos) = [], if n == 0
%                            l1 U e U insert(l2..ln, e, x, pos+1), if
%                            pos == x
%                            l1 U insert(l2,,ln, e, x, pos+1), otherwise
insert([], _, _, _, []).
insert([H|T], E, X, Pos, [H, E|R]):-
    Pos =:= X - 1,
    NewPos is Pos + 1,
    insert(T, E, X, NewPos, R).
insert([H|T], E, X, Pos, [H|R]):-
    NewPos is Pos + 1,
    insert(T, E, X, NewPos, R).

insertMain(L, E, X, R):-
    insert(L, E, X, 1, R).

%b. Define a predicate to determine the greatest common divisor of all numbers from a list.

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

gcdList([], 0).
gcdList([H | T], TR) :-
    gcdList(T, R),
    cmmdc(H, R, TR).
