%a. Determine the position of the maximal element of a linear list
%getMax(l1..ln, max) = false, if n == 0
%                      getMax(l2..ln, max), if l1 < max
%                      getax(l2..ln, l1), otherwise
getMax([], Max, R):- R is Max.
getMax([H|T], Max, R):-
    H < Max,
    getMax(T, Max, R).
getMax([H|T], _, R):-
    getMax(T, H, R).

%getMaxPos(l1..ln, pos) = [], if n == 0
%                         pos U getMaxPos(l2..ln, pos+1), if l1 ==
%                         getMax(l1..ln, 0)
%                         getMaxPos(l2..ln, pos+1), otherwise
getMaxPos([], _, []).
getMaxPos([H|T], Pos, [Pos|R]):-
    getMax([H|T], 0, R1),
    H =:= R1,
    NewPos is Pos + 1,
    getMaxPos(T, NewPos, R).
getMaxPos([_|T], Pos, R):-
    NewPos is Pos + 1,
    getMaxPos(T, NewPos, R).

%b. For a heterogeneous list, formed from integer numbers and list of numbers, replace every sublist with the
%position of the maximum element from that sublist.
%maxPosHL(l1..ln) = [], if n == 0
%                   maxPosHL(l2..ln), if l1 number
%                   getMaxPos(l1, 1) U maxPosHL(l2..ln),if l1 list
maxPosHL([], []).
maxPosHL([H|T], [H|R]):-
    number(H),
    maxPosHL(T, R).
maxPosHL([H|T], [R1|R]):-
    is_list(H),
    getMaxPos(H, 1, R1),
    maxPosHL(T, R).
