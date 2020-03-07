%a. Define a predicate to remove from a list all repetitive elements.
%Eg.: l=[1,2,1,4,1,3,4] => l=[2,3])

%countOcc(l1..ln, e) = 0, if n = 0
%                      1 + countOcc(l2..ln, e), if l1 == e
%                      countOcc(l2..ln, e), otherwise
countOcc([], _, 0).
countOcc([H|T], E, R):-
    H == E,
    countOcc(T, E, NewR),
    R is NewR + 1.
countOcc([H|T], E, R):-
    H =\= E,
    countOcc(T, E, R).

% removeRepet(l1..ln) = [], if n == 0
%                       l1 U removeRepet(l2..ln), if countOcc(l1..ln,
% l1) == 1
%                       removeRepet(l2..ln), otherwise
removeRepet([], []).
removeRepet([H|T], [H|R]):-
    countOcc([H|T], H, R1),
    R1 == 1,
    removeRepet(T, R).
removeRepet([_|T], R):-
    removeRepet(T, R).

%b. Remove all occurrence of a maximum value from a list on integer numbers.
%
%findMax(l1..ln, max) = 0, if n == 0
%                       findMax(l2..ln, l1), if l1 > max
findMax([], 0).
findMax([H|T], R):-
    findMax(T, RM),
    R is max(H, RM).

%removeOcc(l1..ln, e) = [], if n == 0
%                       removeOcc(l2..ln, e), if l1 == e
%                       l1 U removeOcc(l2..ln, e), otherwise
removeOcc([], _, []).
removeOcc([H|T], E, R):-
    H == E,
    removeOcc(T,E,R).
removeOcc([H|T], E, [H|R]):-
    H =\= E,
    removeOcc(T, E, R).

removeMaximum(L, R):-
    findMax(L, Maximum),
    removeOcc(L, Maximum, R).
