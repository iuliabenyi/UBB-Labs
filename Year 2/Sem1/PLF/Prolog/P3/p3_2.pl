%Are given n points in a plan (represented using its coordinates). Write
% a predicate to determine all subsets of collinear points.
%colin(x1, y1, x2, y2, x3, y3) = true, x1 = x2 = x3
%                                true, y1 = y2 = y3
%                                true, different and
%                                (y2-y1)/(x2-x1) = (y3-y2)/(x3-x2)
colin(X, _, X, _, X, _):- true.
colin(_, Y, _, Y, _, Y):- true.
colin(X1, Y1, X2, Y2, X3, Y3):-
    X1 =\= X2,
    X1 =\= X3,
    X2 =\= X3,
    Y1 =\= Y2,
    Y1 =\= Y3,
    Y2 =\= Y3,
    R1 is (Y2-Y1)/(X2-X1),
    R2 is (Y3-Y2)/(X3-X2),
    R1 =:= R2.

%nu stiu cum sa scriu modelul matematic
subset([],[]).
subset([[A,B], [A1, B1], [A2,B2]|T], [[[A,B], [A1,B1], [A2,B2]]|R]):-
    colin(A, B, A1, B1, A2, B2),
    !,
    subset([[A1,B1], [A2,B2]|T], R).
subset([_|T], R):- subset(T, R).

allSubset(L, R):-
    findall(R1, subset(L, R1), R).
%nu merge
