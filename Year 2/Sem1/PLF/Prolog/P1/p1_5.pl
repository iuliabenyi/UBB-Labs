%a. Write a predicate to compute the union of two sets
%
%exists(l1..ln, e) = false, if n ==0
%                    true, if l1 == e
%                    exists(l2..ln, e), otherwise

exists([], _):- false.
exists([E|_], E):- true.
exists([_|T], E):-
    exists(T, E).

% union(l1..ln, k1..km) = k1..km, if n = 0
%                         l1..ln, if m = 0
%                         union(l2..ln, k1..km), if exists(k1..km,
% l1)
%                         l1 U union(l2..ln, k1..km), otherwise
union([], K, K).
union(L, [], L).
union([H|T], K, R):-
    exists(K, H),
    union(T, K, R).
union([H|T], K, [H|R]):-
    union(T, K, R).

%b. Write a predicate to determine the set of all the pairs of elements in a list.
%Eg.: L = [a b c d] => [[a b] [a c] [a d] [b c] [b d] [c d]].
%
pairUp(_, [], []).
pairUp(A, [B|T], Aux):-
    pairUp(A, T, R),
    append([[[A, B]], R], Aux).
pairComb([], []).
pairComb([H|T], Aux):-
    pairUp(H, T, R),
    pairComb(T, TR),
    append([R, TR], Aux).
