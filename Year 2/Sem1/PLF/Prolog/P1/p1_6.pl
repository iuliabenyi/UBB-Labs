%a. Write a predicate to test if a list is a set.
%

%exists(l1..ln, e) = false, if n ==0
%                    true, if l1 == e
%                    exists(l2..ln, e), otherwise

exists([], _):- false.
exists([E|_], E):- true.
exists([_|T], E):-
    exists(T, E).


%testSet(l1..ln) = true, if n == 0
%                  false, if nrOcc(l1..ln, l1) != 1
%                  testSet(l2..ln), otherwise
testSet([]):- true.
testSet([H|T]):-
    not(exists(T, H)),
    testSet(T).

%b. Write a predicate to remove the first three occurrences of an element in a list. If the element occurs less
%than three times, all occurrences will be removed.
%
%remove3(l1..ln, x, ct) = [], if n == 0
%                         remove3(l2..ln, x, ct+1), if l1 == x and ct <=3
%                         l1 U remove3(l2..ln, x, ct), otherwise
remove3([], _, _, []).
remove3([H|T], X, CT, R):-
    H =:= X,
    CT < 3,
    NewCT is CT + 1,
    remove3(T, X, NewCT, R).
remove3([H|T], X, CT, [H|R]):-
    remove3(T, X, CT, R).
removeMain(L, X, R):-
    remove3(L, X, 0, R).
