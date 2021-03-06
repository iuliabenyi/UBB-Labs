%a. Substitute all occurrences of an element of a list with all the elements of another list.
%substitute(l1..ln, e, k) = [], if n == 0
%                           k U substitute(l2..ln, e, k), if l1 == e
%                           l1 U substitute(l2..ln, e, k), otherwise
substitute([], _, _, []).
substitute([H|T], E, K, [K|R]):-
    H =:= E,
    substitute(T, E, K, R).
substitute([H|T], E, K, [H|R]):-
    substitute(T, E, K, R).

%For a heterogeneous list, formed from integer numbers and list of numbers, replace in every sublist all
%occurrences of the first element from sublist it a new given list
%substituteHL(l1..ln, k) = [], if n == 0
%                          l1 U substituteHL(l2..ln, k), if l1 number
%                          substitute(l1.1..l1.m, l1.1, k) U
%                          substituteHL(l2..ln, k), if l1 list
substituteHL([], _, []).
substituteHL([H|T], K, [H|R]):-
    number(H),
    substituteHL(T, K, R).
substituteHL([[H1|T1]|T], K, [R1|R]):-
    substitute([H1|T1], H1, K, R1),
    substituteHL(T, K, R).
