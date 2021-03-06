%a. Write a predicate to remove all occurrences of a certain atom from a list
%removeOcc(l1..ln, e) = [] , if n = 0
%                       removeOcc(l2..ln, e), if l1 == e
%                       l1 U removeOcc(l2..ln, e), otherwise
removeOcc([], _, []).
removeOcc([H|T], E, R):-
    H == E,
    removeOcc(T, E, R).
removeOcc([H|T],E, [H|R]):-
    H =\= E,
    removeOcc(T, E, R).

%b. Define a predicate to produce a list of pairs (atom n) from an initial list of atoms. In this initial list atom has
%n occurrences.
% Eg.: numberatom([1, 2, 1, 2, 1, 3, 1], X) => X = [[1, 4], [2, 2], [3,
% 1]].
%
% countOcc(l1..ln, e) = 0, n= 0
%                       1 + countOcc(l2..ln, e), if l1 == e
%                       countOcc(l2..ln, e), otherwise
countOcc([], _, 0).
countOcc([H|T], E, R):-
    H == E,
    countOcc(T, E, NewR),
    R is NewR + 1.
countOcc([H|T], E, R):-
    H =\= E,
    countOcc(T, E, R).

%numberAtom(l1..ln) = [], n = 0
%                        , otherwise
numberAtom([], []).
numberAtom([H|T], [[H, Count]|T2]):-
    countOcc([H|T], H, Count),
    removeOcc([H|T], H, NewH),
    numberAtom(NewH, T2).
