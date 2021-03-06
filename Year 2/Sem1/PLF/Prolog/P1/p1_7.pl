%a. Write a predicate to compute the intersection of two sets.
%
%exists(l1..ln, e) = false, if n ==0
%                    true, if l1 == e
%                    exists(l2..ln, e), otherwise

exists([], _):- false.
exists([E|_], E):- true.
exists([_|T], E):-
    exists(T, E).

%intersection(l1..ln, k1..km) = [], if n == 0
%                               [], if m == 0
%                               l1 U intersection(l2..ln, k1...km), if
%l1 in k1..km
%                               intersection(l2..ln, k1..km), otherwise
intersection([], _, []).
intersection(_, [], []).
intersection([H|T], K, [H|R]):-
    exists(K, H),
    intersection(T, K, R).
intersection([_|T], K, R):-
    intersection(T, K, R).

%b. Write a predicate to create a list (m, ..., n) of all integer numbers from the interval [m, n].
%
%interval(m, n) = [m], if m == n
%                 [], if m > n
%                 interval(m+1, n), otherwise
interval(M, M, [M]).
interval(M, N, []):-
    M > N.
interval(M, N, [M|R]):-
    NewM is M + 1,
    interval(NewM, N, R).
