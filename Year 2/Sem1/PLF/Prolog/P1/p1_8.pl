%a. Write a predicate to determine if a list has even numbers of elements without counting the elements from
%the list.
%
%1 -> odd, 0 -> even
%checkEvenEl(l1..ln, sem) = sem, n == 0
%                           checkEvenEl(l2..ln, 1), if sem == 0
%                           checkEvenEl(l2..ln, 0), if sem == 1
checkEvenEl([], Sem, Sem).
checkEvenEl([_|T], 0, R):-
    checkEvenEl(T, 1, R).
checkEvenEl([_|T], 1, R):-
    checkEvenEl(T, 0, R).

%b. Write a predicate to delete first occurrence of the minimum number from a list.
%
%findMin(l1..ln, min) = 0, if n == 0
%                       findMin(l2..ln, l1), if l1 < min
findMin([], 9999).
findMin([H|T], R):-
    findMin(T, RM),
    R is min(H, RM).

%removeMin(l1..ln, sem) = [], if n == 0
%                         removeMin(l2..ln, 0), if l1 ==
%                         findMin(l1..ln) l1 U removeMin(l2..ln),
%                       otherwise
removeMin([], _, []).
removeMin([H|T], Sem, R):-
    findMin([H|T], R1),
    H =:= R1,
    Sem =:= 1,
    removeMin(T, 0, R).
removeMin([H|T], Sem, [H|R]):-
    removeMin(T, Sem, R).


