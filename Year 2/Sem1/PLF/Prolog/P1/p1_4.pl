%a. Write a predicate to determine the difference of two sets
%
%exists(l1..ln, e) = false, if n = 0
%                    true, if l1 == e
%                    exists(l2..ln, e), otherwise

exists([], _):- false.
exists([E|_], E):- true.
exists([_|T], E):-
    exists(T, E).

%difference(l1..ln, set, R) = [], if n = 0
%                             difference(T, set, R), if exists(set, l1)
%                             l1 U difference(l2..ln, set, R), otherwise

difference([], _, []).
difference([H|T], Set, R):-
    exists(Set, H),
    difference(T, Set, R).
difference([H|T], Set, [H|R]):-
    difference(T, Set, R).

%b. Write a predicate to add value 1 after every even element from a list.
%
%addValue(l1..ln, e) = [], if n == 0
%                      l1 U e U addValue(l2..ln, e), if l1 % 2 == 0
%                      l1 U addValue(l2..ln), otherwise
addValue([], _, []).
addValue([H|T], E, [H, E|R]):-
    0 is mod(H, 2),
    addValue(T, E, R).
addValue([H|T], E, [H|R]):-
    addValue(T, E, R).

add1(L, R):-
    addValue(L, 1, R).
