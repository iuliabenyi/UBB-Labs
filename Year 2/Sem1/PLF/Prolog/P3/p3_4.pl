
%The list a1... an is given. Write a predicate to determine all sublists strictly ascending of this list a
%subset(l1..ln) = [], n == 0
%                 l1 U subset(l2..ln)
%                 subset(l2..ln)
subset([], []).
subset([H|T], [H|R]):-
    subset(T, R).
subset([_|T], R):-
    subset(T, R).

%ascending(l1..ln) = true, n = 0 || n = 1
%                    false, l1 > l2
%                    ascending(l2..ln), l1 <= l2
ascending([]):- !.
ascending([_]):-!.
ascending([H1, H2|T]):-
    H1 =< H2,
    ascending([H2, T]).

%checkSubset(l1..ln) = [], if n == 0
%                      subset(l1..ln), if ascending(subset(l1..ln)) true
checkSubset([], []).
checkSubset(L, K):-
    subset(L, K),
    ascending(K).

allSubset(L, R):-
    findall(R1, checkSubset(L, R1), R).

