%a. Write a predicate to substitute an element from a list with another element in the list.
%
getElem([], _, _).
getElem([H | _], 0, H).
getElem([_ | T], Pos, R):-
    NewPos is Pos - 1,
    getElem(T, NewPos, R).

%setElem(l1..ln, Pos, E) = [], if n == 0
%                          E U setElem(l2..ln, Pos, E), if Pos == 0
%                          l1 U setElem(l2..ln, pos+1, E), otherwise
setElem([], _, _, []).
setElem([_ | T], 0, E, [E | T]).
setElem([H | T], Pos, E, [H | R]) :-
    NewPos is Pos - 1,
    setElem(T, NewPos, E, R).

substitute(L, Pos1, Pos2, R):-
    getElem(L, Pos1, E1),
    getElem(L, Pos2 - 1, E2),
    setElem(L, Pos1 - 1, E2, R1),
    setElem(R1, Pos2, E1, R).

%b. Write a predicate to create the sublist (lm, …, ln) from the list (l1,…, lk).
%getSublist(l1..ln, pos1, pos2) = false, n == 0
%                                 l1, if pos1 = pos2 = 0
%                                 l1 U getSublist(l2..ln, pos1, pos2-1),
%                                 if pos1 == 0
%                                 getSublist(l2..ln, pos1 - 1, pos2 -
%                                 1), if pos1 > 0
getSublist([], _, _, _):- false.
getSublist([H|_], 0, 0, H).
getSublist([H|T], Pos1, Pos2, [H|R]):-
    NewPos2 is Pos2-1,
    Pos1 =:= 0,
    getSublist(T, Pos1, NewPos2, R).
getSublist([_|T], Pos1, Pos2, R):-
    Pos1 > 0,
    NewPos1 is Pos1 - 1,
    NewPos2 is Pos2 - 1,
    getSublist(T, NewPos1, NewPos2, R).
