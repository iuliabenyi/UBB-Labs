%Write a predicate to determine all decomposition of n (n given, positive), as sum of consecutive natural
%numbers.
%oneSol(n, e) = [], if n == 0
%               e U oneSol(n-e, e+1), otherwise
oneSol(0, _, []).
oneSol(N, E, [E|R]):-
    N >= E,
    N1 is N - E,
    N2 is E + 1,
    oneSol(N1, N2, R).

%decompose(n, e) = oneSol(n, e), e < n
%                  decompose(n, e+1), e < n
decompose(N, E, R):-
    E < N,
    oneSol(N, E, R).
decompose(N, E, R):-
    E < N,
    N1 is E + 1,
    decompose(N, N1, R).

allDecompose(N, R):-
    findall(R1, decompose(N, 1, R1), R).


