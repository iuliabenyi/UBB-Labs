%Write a predicate to generate the list of all subsets with all elements of a given list.
%Eg: [2, 3, 4] N=2 => [[2,3],[2,4],[3,4]]
%comb(l1..ln, k) = [], if k == 0
%                  l1 U comb(l2..ln, K-1), if k > 0
%                  comb(l2..ln, k), if  k > 0
comb(_, 0, []).
comb([H|T], K, [H|R]):-
    K > 0,
    NewK is K - 1,
    comb(T, NewK, R).
comb([_|T], K, R):-
    K > 0,
    comb(T, K, R).
allComb(L, K, R):-
    findall(R1, comb(L, K, R1), R).

